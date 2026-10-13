typedef struct { int p0[2]; unsigned int f8; int p1[4]; int f1C; int f20; int p2[5]; int f38; int f3C; } Obj;
typedef struct { short p0[3]; unsigned short f6; unsigned short f8; } Peer;
extern unsigned int D_0048C450;
extern int D_005880B0[];
extern char D_0058C178[];
extern int func_002DD968(Obj **, unsigned int);
extern void func_002DE9F0(unsigned int, unsigned int);
extern void func_002DB188(Peer **, unsigned int, unsigned int);
void __attribute__((weak, section(".dtors_drop"))) func_002DD328(void *p0) { }

int func_002DEA68(unsigned int idx)
{
    Obj *obj;
    Peer *peer = 0;
    char *flag; Obj *o;
    if (idx >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    func_002DD968(&obj, idx);
    if (obj == 0) return 8;
    func_002DE9F0(obj->f8, idx);
    func_002DD968(&obj, idx);
    if (obj) {
        flag = &D_0058C178[idx];
        *flag = 1;
        if ((int)D_0048C450 < 4) {
            func_002DB188(&peer, D_0048C450, obj->f8);
            if (peer && ((int)idx < peer->f6 || (int)idx >= peer->f6 + peer->f8))
                *flag = 0;
        }
        o = obj;
        if (o->f20) { func_002DD328(&o->f20); o = obj; o->f20 = 0; }
        if (o->f1C) { func_002DD328(&o->f1C); o = obj; o->f1C = 0; }
        if (o->f38) { func_002DD328(&o->f38); o = obj; o->f38 = 0; }
        if (o->f3C) { func_002DD328(&o->f3C); obj->f3C = 0; }
        D_005880B0[idx] = 0;
        func_002DD328(&obj);
    }
    return 0;
}

/* score: 1 insn diff (beql vs beqz delay-slot choice on last free block) */
