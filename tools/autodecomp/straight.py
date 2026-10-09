"""Symbolic translator for branch-free MIPS functions (see run.py)."""
import re,sys,struct
INT_ARGS=['$a0','$a1','$a2','$a3','$t0','$t1','$t2','$t3']
FLT_ARGS=['$f12','$f13','$f14','$f15','$f16','$f17','$f18','$f19']
SAVED=['$s0','$s1','$s2','$s3','$s4','$s5','$s6','$s7','$fp','$f20','$f21','$f22','$f23','$f24','$f25','$f26','$f27','$f28','$f29','$f30','$f31']
CLOBBER=['$v0','$v1','$a0','$a1','$a2','$a3','$t0','$t1','$t2','$t3','$t4','$t5','$t6','$t7','$t8','$t9','$at']+['$f%d'%i for i in range(20)]
class Unsupported(Exception): pass
def imm(s):
    s=s.strip(); return int(s,16) if s.lower().startswith(('0x','-0x')) else int(s)
LOADS={'lq':('Q',16),'lw':('int',4),'lh':('short',2),'lhu':('unsigned short',2),'lb':('signed char',1),'lbu':('unsigned char',1),'lwc1':('float',4)}
STORES={'sq':'Q','sw':'int','sh':'short','sb':'char','swc1':'float'}
MEM=re.compile(r'^(%lo\((\w+)\)|-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)$')

def arity(fins):
    """registers read before written (linear approximation)"""
    written=set(); ri=-1; rf=-1
    for _,x in fins:
        op,_,rest=x.partition(' ')
        a=[t.strip() for t in rest.split(',')] if rest.strip() else []
        regs=re.findall(r'\$\w+',rest)
        if not regs: continue
        if op.startswith(('s','b')) and op not in ('sll','srl','sra','slt','sltu','slti','sltiu','sub.s','subu','sllv','srlv','srav') or op in ('jr','mtc1','ctc1'):
            reads=regs; writes=[]
            if op=='mtc1': reads=[regs[0]]; writes=[regs[1]]
        else:
            writes=regs[:1]; reads=regs[1:]
        for r in reads:
            if r not in written:
                if r in INT_ARGS: ri=max(ri,INT_ARGS.index(r))
                if r in FLT_ARGS: rf=max(rf,FLT_ARGS.index(r))
        for w in writes: written.add(w)
    return ri+1,rf+1

WR={}
def writes(fins):
    w=set()
    for _,x in fins:
        op,_,rest=x.partition(' ')
        regs=re.findall(r'\$\w+',rest)
        if regs and not (op.startswith(('s','b')) and op not in ('sll','srl','sra','slt','sltu','slti','sltiu','sub.s','subu')) and op not in ('jr','mtc1'):
            w.add(regs[0])
        if op=='mtc1' and len(regs)>1: w.add(regs[1])
    return ('float' if '$f0' in w and '$v0' not in w else 'int' if '$v0' in w else 'void')
def decompile(name, ins, ARITY):
    regs={}; used_int=set(); used_flt=set()
    stmts=[]; temps=[]; externs={}; datasyms=set()
    body=[x for _,x in ins]
    # reorder delay slots of jal/j/jr
    seq=[];i=0
    while i<len(body):
        op=body[i].split()[0]
        if op in ('jal','j','jr') and i+1<len(body):
            seq.append(body[i+1]); seq.append(body[i]); i+=2
        else: seq.append(body[i]); i+=1
    def get(r):
        if r=='$zero': return ('const',0)
        if r in regs: return regs[r]
        if r in INT_ARGS: used_int.add(r); return ('arg',r)
        if r in FLT_ARGS: used_flt.add(r); return ('farg',r)
        raise Unsupported('read undefined '+r)
    def memref(m):
        if m.group(2):
            b=get(m.group(3))
            if b[0]!='hi' or b[1]!=m.group(2): raise Unsupported('lo mismatch')
            datasyms.add(m.group(2)); return (('sym',m.group(2)),0)
        return (get(m.group(3)),imm(m.group(1)))
    frame=0; ended=False
    for x in seq:
        op,_,rest=x.partition(' ')
        a=[t.strip() for t in rest.split(',')] if rest.strip() else []
        if ended: raise Unsupported('code after return')
        if op=='nop': continue
        if op=='addiu' and a[0]=='$sp' and a[1]=='$sp':
            frame+=imm(a[2]); continue
        if op in ('sd','sq','ld','lq','swc1','lwc1') and a[1].endswith('($sp)'):
            r=a[0]
            if r=='$ra' or r in SAVED: continue
            raise Unsupported('stack access')
        if op=='jr':
            if a[0]!='$ra': raise Unsupported('jr')
            ended=True; continue
        if op in ('jal','j'):
            tgt=a[0]
            if not tgt.startswith('func_'): raise Unsupported('call target')
            ni,nf=ARITY.get(tgt,(None,None))
            if ni is None: raise Unsupported('unknown callee')
            args=[get(INT_ARGS[k]) for k in range(ni)]+[get(FLT_ARGS[k]) for k in range(nf)]
            tmp=('tmp',len(temps),'int'); temps.append(tmp)
            ftmp=('tmp',len(temps),'float'); temps.append(ftmp)
            stmts.append(('call',tgt,args,tmp,ftmp,ni,nf))
            externs[tgt]=(ni,nf)
            for r in CLOBBER: regs.pop(r,None)
            regs['$v0']=tmp; regs['$f0']=ftmp
            if op=='j': ended=True; stmts.append(('tailret',))
            continue
        if op in LOADS:
            t,_=LOADS[op]; m=MEM.match(a[1])
            if not m: raise Unsupported('mem')
            ld=('load',t,memref(m))
            tmp=('tmp',len(temps),t); temps.append(tmp); stmts.append(('decl',tmp,ld)); regs[a[0]]=tmp
        elif op in STORES:
            m=MEM.match(a[1])
            if not m: raise Unsupported('mem')
            stmts.append(('store',STORES[op],memref(m),get(a[0])))
        elif op=='lui':
            mm=re.match(r'%hi\((\w+)\)',a[1])
            if mm: regs[a[0]]=('hi',mm.group(1))
            else:
                mm=re.match(r'\((0x[0-9A-F]+) >> 16\)',a[1])
                if not mm: raise Unsupported('lui form')
                regs[a[0]]=('const',int(mm.group(1),16)&0xffff0000)
        elif op in ('daddu','addu','or') and a[2]=='$zero': regs[a[0]]=get(a[1])
        elif op in ('daddu','addu','or') and a[1]=='$zero': regs[a[0]]=get(a[2])
        elif op=='addiu' and a[2].startswith('%lo('):
            s=re.match(r'%lo\((\w+)\)',a[2]).group(1); b=get(a[1])
            if b!=('hi',s): raise Unsupported('lo')
            datasyms.add(s); regs[a[0]]=('addr',s)
        elif op=='ori' and a[2].startswith('('):
            mm=re.match(r'\((0x[0-9A-F]+) & 0xFFFF\)',a[2]); b=get(a[1])
            if not mm or b[0]!='const': raise Unsupported('ori')
            regs[a[0]]=('const',b[1]|(int(mm.group(1),16)&0xffff))
        elif op=='addiu':
            if a[1]=='$sp': raise Unsupported('stack addr')
            v=get(a[1]); k=imm(a[2])
            regs[a[0]]=('const',k) if v==('const',0) else ('bin','+',v,('const',k))
        elif op in ('addu','subu','and','or','xor','slt','sltu','nor'):
            sym={'addu':'+','subu':'-','and':'&','or':'|','xor':'^','slt':'<','sltu':'<u','nor':'nor'}[op]
            regs[a[0]]=('bin',sym,get(a[1]),get(a[2]))
        elif op in ('andi','ori','xori','slti','sltiu'):
            sym={'andi':'&','ori':'|','xori':'^','slti':'<','sltiu':'<u'}[op]
            regs[a[0]]=('bin',sym,get(a[1]),('const',imm(a[2])))
        elif op in ('sll','srl','sra'):
            sym={'sll':'<<','srl':'>>u','sra':'>>'}[op]
            regs[a[0]]=('bin',sym,get(a[1]),('const',imm(a[2])))
        elif op in ('add.s','sub.s','mul.s','div.s'):
            regs[a[0]]=('fbin',{'add.s':'+','sub.s':'-','mul.s':'*','div.s':'/'}[op],get(a[1]),get(a[2]))
        elif op=='neg.s': regs[a[0]]=('fneg',get(a[1]))
        elif op=='mov.s': regs[a[0]]=get(a[1])
        elif op=='mtc1':
            v=get(a[0])
            if v[0]!='const': raise Unsupported('mtc1')
            f=struct.unpack('<f',struct.pack('<I',v[1]&0xffffffff))[0]
            regs[a[1]]=('fconst',repr(f)+'f' if f!=int(f) else '%d.0f'%int(f))
        else: raise Unsupported(op)
    if not ended: raise Unsupported('no return')
    ret=None
    stored=[st[3] for st in stmts if st[0]=='store']
    callargs=[x for st in stmts if st[0]=='call' for x in st[2]]
    def used(v): return any(v is x for x in stored+callargs)
    lastcall=[s for s in stmts if s[0]=='call']
    lastcall=lastcall[-1] if lastcall else None
    if stmts and stmts[-1][0]=='tailret':
        ret=('tail',lastcall)
    else:
        v=regs.get('$v0'); fz=regs.get('$f0')
        if lastcall is not None and v is lastcall[3]:
            k=WR.get(lastcall[1],'int')
            if k=='int' and not used(v): ret=('int',v)
            elif k=='float' and not used(fz): ret=('float',fz)
        else:
            if v is not None and not used(v): ret=('int',v)
            elif fz is not None and fz is not (lastcall[4] if lastcall else None) and not used(fz): ret=('float',fz)
    return stmts,ret,used_int,used_flt,externs,datasyms

def linear(e):
    k=e[0]
    if k in ('arg','tmp'): return (e,1)
    if k=='bin' and e[1]=='<<' and e[3][0]=='const':
        l=linear(e[2]); return (l[0],l[1]<<e[3][1]) if l else None
    if k=='bin' and e[1] in ('+','-'):
        l=linear(e[2]); r=linear(e[3])
        if l and r and l[0]==r[0]: return (l[0], l[1]+r[1] if e[1]=='+' else l[1]-r[1])
    return None
def expr(e):
    k=e[0]
    if k=='tmp': return f'tmp{e[1]}'
    if k=='const': return str(e[1]) if e[1]<0x80000000 else hex(e[1])
    if k=='fconst': return e[1]
    if k=='arg': return e[1][1:]
    if k=='farg': return 'f'+e[1][2:]
    if k=='addr': return f'(int){e[1]}'
    if k=='hi': raise Unsupported('bare hi')
    if k=='load':
        t=e[1]; (b,off)=e[2]
        if b[0]=='sym': return f'*({t}*){b[1]}'
        return f'*({t}*)((char*){expr(b)} + {off})' if off else f'*({t}*)(char*){expr(b)}'
    if k=='bin':
        lin=linear(e)
        if e[1] in ('<<','+','-') and lin and lin[1]&(lin[1]-1)!=0: return f'({expr(lin[0])} * {lin[1]})'
        op=e[1]; l=expr(e[2]); r=expr(e[3])
        if op=='<u': return f'((unsigned int)({l}) < (unsigned int)({r}))'
        if op=='>>u': return f'((unsigned int)({l}) >> {r})'
        if op=='nor': return f'~(({l}) | ({r}))'
        return f'({l} {op} {r})'
    if k=='fbin': return f'({expr(e[2])} {e[1]} {expr(e[3])})'
    if k=='fneg': return f'-({expr(e[1])})'
    raise Unsupported(k)
def render(name,ins,ARITY):
    stmts,ret,ui,uf,externs,datasyms=decompile(name,ins,ARITY)
    params=[]
    maxi=max([INT_ARGS.index(r) for r in ui]+[-1]); maxf=max([FLT_ARGS.index(r) for r in uf]+[-1])
    for i in range(maxi+1): params.append('int '+INT_ARGS[i][1:])
    for i in range(maxf+1): params.append('float f'+FLT_ARGS[i][2:])
    # which call results used as float / int
    fl_used=set(); in_used=set()
    def scan(e):
        if isinstance(e,tuple):
            if e and e[0]=='tmp':
                (fl_used if e[2]=='float' else in_used).add(e[1])
            for x in (e[1:] if e and isinstance(e[0],str) else e):
                if isinstance(x,tuple): scan(x)
                elif isinstance(x,list):
                    for y in x: scan(y)
    for s in stmts:
        if s[0]=='store': scan(s[3]); scan(s[2][0])
        elif s[0]=='decl': scan(s[2])
        elif s[0]=='call': [scan(x) for x in s[2]]
    if ret and ret[0] in ('int','float'): scan(ret[1])
    rettype={}
    lines=[];decls=[]
    for s in stmts:
        if s[0]=='decl':
            tmp,ld=s[1],s[2]; decls.append(f'    {tmp[2]} tmp{tmp[1]};'); lines.append(f'    tmp{tmp[1]} = {expr(ld)};')
        elif s[0]=='store':
            _,t,(b,off),v=s
            if t=='Q' and not (v[0]=='tmp' and v[2]=='Q'): raise Unsupported('sq value')
            if b[0]=='sym': tgt=f'*({t}*){b[1]}'
            else: tgt=f'*({t}*)((char*){expr(b)} + {off})' if off else f'*({t}*)((char*){expr(b)})'
            lines.append(f'    {tgt} = {expr(v)};')
        elif s[0]=='call':
            _,tgt,args,tmp,ftmp,ni,nf=s
            usei=tmp[1] in in_used; usef=ftmp[1] in fl_used
            if usei and usef: raise Unsupported('both returns')
            rt='float' if usef else 'int'
            if ret and ret[0]=='tail' and ret[1] is s: rt=None
            rettype[tgt]=rt
            call=f'{tgt}({", ".join(expr(x) for x in args)})'
            if usei: decls.append(f'    int tmp{tmp[1]};'); lines.append(f'    tmp{tmp[1]} = {call};')
            elif usef: decls.append(f'    float tmp{ftmp[1]};'); lines.append(f'    tmp{ftmp[1]} = {call};')
            elif rt is None: lines.append(f'    return {call};')
            else: lines.append(f'    {call};')
    rt='void'
    if ret:
        if ret[0]=='tail':
            k=WR.get(ret[1][1],'int'); rt=k if k!='void' else 'void'; rettype[ret[1][1]]=rt if rt!='void' else 'void'
            if rt=='void': lines[-1]=lines[-1].replace('return ','')
        else:
            rt='float' if ret[0]=='float' else 'int'
            lines.append(f'    return {expr(ret[1])};')
    ext=[]
    for tgt,(ni,nf) in externs.items():
        ps=['int']*ni+['float']*nf
        ext.append((tgt,f'extern {WR.get(tgt,"int") if WR.get(tgt)!="void" else "void"} {tgt}({", ".join(ps) if ps else "void"});'))
    for d in sorted(datasyms):
        if d.startswith('func_'):
            if d in externs: continue
            ni,nf=ARITY.get(d,(0,0)); ps=['int']*ni+['float']*nf; r=WR.get(d,'int')
            ext.append((d,f'extern {r} {d}({", ".join(ps) if ps else "void"});'))
        else: ext.append((d,f'extern char {d}[];'))
    code=f'{rt} {name}({", ".join(params) if params else "void"}) {{\n'+'\n'.join(decls+([''] if decls else [])+lines)+'\n}\n'
    return code,ext

