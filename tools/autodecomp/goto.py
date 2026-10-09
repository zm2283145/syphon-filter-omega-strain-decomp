"""Register-level translator (one C variable per register, gotos) for MIPS functions (see run.py)."""
import re,sys,struct
from straight import arity, writes, INT_ARGS, FLT_ARGS, SAVED, Unsupported, imm
GPR=['$v0','$fp','$v1','$a0','$a1','$a2','$a3','$t0','$t1','$t2','$t3','$t4','$t5','$t6','$t7','$s0','$s1','$s2','$s3','$s4','$s5','$s6','$s7','$t8','$t9','$fp','$at']
MEM=re.compile(r'^(%lo\((\w+)\)|-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)$')
LOADS={'lw':'int','lh':'short','lhu':'unsigned short','lb':'signed char','lbu':'unsigned char','lwc1':'float'}
STORES={'sw':'int','sh':'short','sb':'char','swc1':'float'}
BR2={'beq':'==','bne':'!='}
BR1={'beqz':'== 0','bnez':'!= 0','blez':'<= 0','bgtz':'> 0','bltz':'< 0','bgez':'>= 0'}
FCMP={'c.eq.s':'==','c.lt.s':'<','c.le.s':'<='}
def v(r):
    if r=='$zero': return '0'
    if r=='$fp': return 's8'
    if r in ('$sp','$ra','$gp','$k0','$k1'): raise Unsupported('reg '+r)
    if r.startswith('$f'): return 'f'+r[2:]
    return r[1:]
def translate(name, ins, ARITY, WR, selfret):
    lines=[]; used=set(); labels={}
    body=[(a,x) for a,x in ins]
    # labels: branch targets
    for a,x in body:
        for m in re.finditer(r'\.L([0-9A-F]{8})',x): labels[int(m.group(1),16)]=1
    out=[]; i=0; datasyms=set(); externs={}
    frame=0; locoffs=[]
    for _,x in body:
        op,_,rest=x.partition(' ')
        A=[t.strip() for t in rest.split(',')] if rest.strip() else []
        if op=='addiu' and A and A[0]=='$sp' and A[1]=='$sp': frame=min(frame,imm(A[2]))
        elif op=='addiu' and len(A)==3 and A[1]=='$sp': locoffs.append(imm(A[2]))
        elif A and len(A)>1 and A[-1].endswith('($sp)'):
            if op in ('sd','sq','ld','lq') and (A[0]=='$ra' or A[0] in SAVED): continue
            if op in ('swc1','lwc1') and A[0] in SAVED: continue
            locoffs.append(imm(A[-1].split('(')[0]))
        elif op in ('daddu','addu') and len(A)==3 and '$sp' in A[1:] and A[0]!='$sp': locoffs.append(0)
    LX=min(locoffs) if locoffs else None
    if LX is not None and LX < 0: raise Unsupported('neg local')
    def R(r):
        if r!='$zero': used.add(r)
        return v(r)
    def mem(s):
        m=MEM.match(s)
        if not m: raise Unsupported('mem '+s)
        if m.group(2):
            if hi.get(m.group(3))!=m.group(2): raise Unsupported('lo')
            datasyms.add(m.group(2)); return f'(char*){m.group(2)}'
        if m.group(3)=='$sp':
            used.add('loc'); off=imm(m.group(1))-LX
            return f'((char*)loc + {off})' if off else '(char*)loc'
        off=imm(m.group(1)); b=R(m.group(3))
        return f'((char*){b} + {off})' if off else f'(char*){b}'
    hi={}; kc={}; pend={}; argw=set()
    def emit(a,x):
        op,_,rest=x.partition(' ')
        A=[t.strip() for t in rest.split(',')] if rest.strip() else []
        if op=='nop': return
        if A and A[0].startswith('$') and op not in STORES and not op.startswith(('b','j','c.')) and op!='mtc1':
            kc.pop(A[0],None)
            if A[0] in INT_ARGS or A[0] in FLT_ARGS: argw.add(A[0])
        if op=='mtc1' and A[1] in FLT_ARGS: argw.add(A[1])
        if op=='addiu' and A[0]=='$sp' and A[1]=='$sp': return
        if op in ('sd','sq','ld','lq') and A[1].endswith('($sp)') and (A[0]=='$ra' or A[0] in SAVED): return
        if op in ('swc1','lwc1') and A[1].endswith('($sp)') and A[0] in SAVED: return
        if op in LOADS: out.append(f'    {R(A[0])} = *({LOADS[op]}*){mem(A[1])};'); return
        if op in STORES:
            t=STORES[op]; out.append(f'    *({t}*){mem(A[1])} = {R(A[0])};'); return
        if op=='lui':
            m=re.match(r'%hi\((\w+)\)',A[1])
            if m: hi[A[0]]=m.group(1); return
            m=re.match(r'\((0x[0-9A-F]+) >> 16\)',A[1])
            if not m: raise Unsupported('lui')
            k=int(m.group(1),16)&0xffff0000; out.append(f'    {R(A[0])} = {k:#x};'); hi.pop(A[0],None); kc[A[0]]=k; return
        if op=='addiu' and A[2].startswith('%lo('):
            s=re.match(r'%lo\((\w+)\)',A[2]).group(1)
            if hi.get(A[1])!=s: raise Unsupported('lo2')
            datasyms.add(s); out.append(f'    {R(A[0])} = (int){s};'); return
        if op=='ori' and A[2].startswith('('):
            m=re.match(r'\((0x[0-9A-F]+) & 0xFFFF\)',A[2]); base=kc.get(A[1]); out.append(f'    {R(A[0])} = {R(A[1])} | {int(m.group(1),16)&0xffff:#x};')
            if base is not None: kc[A[0]]=base|(int(m.group(1),16)&0xffff)
            return
        if op in ('daddu','addu','or') and A[2]=='$zero': out.append(f'    {R(A[0])} = {R(A[1])};'); return
        if op in ('daddu','addu','or') and A[1]=='$zero': out.append(f'    {R(A[0])} = {R(A[2])};'); return
        if op=='addiu' and A[1]=='$sp':
            used.add('loc'); off=imm(A[2])-LX
            out.append(f'    {R(A[0])} = (int)((char*)loc + {off});' if off else f'    {R(A[0])} = (int)loc;'); return
        if op in ('daddu','addu') and A[1]=='$sp' and A[2]=='$zero':
            used.add('loc'); off=-LX
            out.append(f'    {R(A[0])} = (int)((char*)loc + {off});' if off else f'    {R(A[0])} = (int)loc;'); return
        if op=='addiu':
            out.append(f'    {R(A[0])} = {R(A[1])} + {imm(A[2])};'); return
        if op in ('addu','subu','and','or','xor','slt'):
            s={'addu':'+','subu':'-','and':'&','or':'|','xor':'^','slt':'<'}[op]
            out.append(f'    {R(A[0])} = {R(A[1])} {s} {R(A[2])};'); return
        if op=='sltu': out.append(f'    {R(A[0])} = (unsigned int){R(A[1])} < (unsigned int){R(A[2])};'); return
        if op=='nor': out.append(f'    {R(A[0])} = ~({R(A[1])} | {R(A[2])});'); return
        if op in ('andi','ori','xori','slti'):
            s={'andi':'&','ori':'|','xori':'^','slti':'<'}[op]
            out.append(f'    {R(A[0])} = {R(A[1])} {s} {imm(A[2])};'); return
        if op=='sltiu': out.append(f'    {R(A[0])} = (unsigned int){R(A[1])} < (unsigned int){imm(A[2])};'); return
        if op=='sll': out.append(f'    {R(A[0])} = {R(A[1])} << {imm(A[2])};'); return
        if op=='sra': out.append(f'    {R(A[0])} = {R(A[1])} >> {imm(A[2])};'); return
        if op=='srl': out.append(f'    {R(A[0])} = (unsigned int){R(A[1])} >> {imm(A[2])};'); return
        if op in ('add.s','sub.s','mul.s','div.s'):
            s={'add.s':'+','sub.s':'-','mul.s':'*','div.s':'/'}[op]; out.append(f'    {R(A[0])} = {R(A[1])} {s} {R(A[2])};'); return
        if op=='neg.s': out.append(f'    {R(A[0])} = -{R(A[1])};'); return
        if op=='abs.s': raise Unsupported('abs')
        if op=='mov.s': out.append(f'    {R(A[0])} = {R(A[1])};'); return
        if op=='mtc1':
            if A[0]=='$zero': out.append(f'    {R(A[1])} = 0.0f;'); return
            if A[0] in kc:
                f=struct.unpack('<f',struct.pack('<I',kc[A[0]]))[0]
                lit=repr(f)+'f' if f!=int(f) or abs(f)>1e9 else '%d.0f'%int(f)
                if 'e' in lit or 'inf' in lit or 'nan' in lit: raise Unsupported('flit')
                out.append(f'    {R(A[1])} = {lit};'); return
            raise Unsupported('mtc1')
        if op=='daddiu':
            out.append(f'    {R(A[0])} = {R(A[1])} + {imm(A[2])};'); return
        if op=='dsll32' and imm(A[2]) in (16,24):
            pend[A[0]]=(A[1],imm(A[2])); return
        if op in ('dsra32','dsrl32') and A[1] in pend and pend[A[1]][1]==imm(A[2]):
            src,k=pend.pop(A[1]); t={(16,'dsra32'):'short',(24,'dsra32'):'signed char',(16,'dsrl32'):'unsigned short',(24,'dsrl32'):'unsigned char'}[(k,op)]
            out.append(f'    {R(A[0])} = ({t}){R(src)};'); return
        if op in ('movz','movn'):
            c='==' if op=='movz' else '!='
            out.append(f'    if ({R(A[2])} {c} 0) {R(A[0])} = {R(A[1])};'); return
        if op=='mult' and len(A)==3 and A[0]!='$zero':
            out.append(f'    {R(A[0])} = {R(A[1])} * {R(A[2])};'); return
        if op in FCMP: out.append(f'    fcc = {R(A[0])} {FCMP[op]} {R(A[1])};'); used.add('fcc'); return
        if op=='jalr':
            fr=A[-1]
            ni=max([INT_ARGS.index(r)+1 for r in argw if r in INT_ARGS]+[0]); nf=max([FLT_ARGS.index(r)+1 for r in argw if r in FLT_ARGS]+[0])
            args=[R(INT_ARGS[k]) for k in range(ni)]+[R(FLT_ARGS[k]) for k in range(nf)]
            ps=', '.join(['int']*ni+['float']*nf) or 'void'
            out.append(f'    v0 = ((int (*)({ps})){R(fr)})({", ".join(args)});'); used.add('$v0'); argw.clear(); return
        if op in ('jal',):
            tgt=A[0]
            if not tgt.startswith('func_'): raise Unsupported('tgt')
            ni,nf=ARITY.get(tgt,(None,None))
            if ni is None: raise Unsupported('callee')
            args=[R(INT_ARGS[k]) for k in range(ni)]+[R(FLT_ARGS[k]) for k in range(nf)]
            rk=WR.get(tgt,'int'); externs[tgt]=(ni,nf,rk)
            call=f'{tgt}({", ".join(args)})'
            argw.clear()
            if rk=='float': out.append(f'    f0 = {call};'); used.add('$f0')
            elif rk=='int': out.append(f'    v0 = {call};'); used.add('$v0')
            else: out.append(f'    {call};')
            return
        raise Unsupported(op)
    n=len(body)
    while i<n:
        a,x=body[i]
        if a in labels: out.append(f'L{a:08X}:;')
        op,_,rest=x.partition(' ')
        A=[t.strip() for t in rest.split(',')] if rest.strip() else []
        if op in BR2 or op in BR1 or op in ('b','bc1t','bc1f','jr','j','jal','jalr'):
            if i+1>=n: raise Unsupported('no delay')
            da,dx=body[i+1]
            if da in labels: raise Unsupported('label on delay')
            if op in ('jal','jalr'):
                emit(da,dx); emit(a,x); i+=2; continue
            if op=='j':
                emit(da,dx); emit(a,x.replace('j ','jal ',1)); out.append('    goto ret;'); i+=2; continue
            cond=None
            if op in BR2: cond=f'{R(A[0])} {BR2[op]} {R(A[1])}' if A[1]!='$zero' else f'{R(A[0])} {BR2[op]} 0'; tgt=A[2]
            elif op in BR1: cond=f'{R(A[0])} {BR1[op]}'; tgt=A[1]
            elif op=='bc1t': cond='fcc'; tgt=A[0]
            elif op=='bc1f': cond='!fcc'; tgt=A[0]
            elif op=='b': tgt=A[0]
            if op not in ('jr','j') and not tgt.startswith('.L'): raise Unsupported('branch to symbol')
            if cond:
                out.append(f'    cond = {cond};'); used.add('cond')
            emit(da,dx)
            if op=='jr':
                if A[0]!='$ra': raise Unsupported('jr')
                out.append('    goto ret;')
            elif op=='j':
                raise Unsupported('j')
            else:
                lbl=tgt.replace('.L','L')
                out.append(f'    if (cond) goto {lbl};' if cond else f'    goto {lbl};')
            i+=2; continue
        if op.endswith('l') and op[:-1] in list(BR2)+list(BR1)+['bc1t','bc1f']: raise Unsupported('likely')
        emit(a,x); i+=1
    for lab in labels:
        if not any(l.startswith(f'L{lab:08X}:') for l in out): raise Unsupported('label outside')
    # signature
    ni,nf=ARITY[name]
    params=[f'int {v(INT_ARGS[k])}' for k in range(ni)]+[f'float {v(FLT_ARGS[k])}' for k in range(nf)]
    pnames={v(INT_ARGS[k]) for k in range(ni)}|{v(FLT_ARGS[k]) for k in range(nf)}
    rt=selfret
    if rt=='int': used.add('$v0')
    if rt=='float': used.add('$f0')
    decl=[]
    ints=sorted(v(r) for r in used if r in GPR and v(r) not in pnames)
    flts=sorted(v(r) for r in used if r.startswith('$f') and r!='$fp' and v(r) not in pnames)
    if ints: decl.append('    int '+', '.join(ints)+';')
    if flts: decl.append('    float '+', '.join(flts)+';')
    if 'loc' in used:
        sz=max(4,((-frame)-LX)); decl.insert(0,f'    int loc[{(sz+3)//4}];')
    if 'fcc' in used or 'cond' in used: decl.append('    int '+', '.join(x for x in ('cond','fcc') if x in used)+';')
    retl=f'ret:\n    return {"v0" if rt=="int" else "f0"};' if rt in ('int','float') else 'ret:;'
    code=f'{rt} {name}({", ".join(params) if params else "void"}) {{\n'+'\n'.join(decl+['']+out+[retl])+'\n}\n'
    return code,externs,datasyms

