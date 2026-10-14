/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { char pad[0x400]; unsigned int f400; char p404[0x40]; int f444; } Obj2E4550;
typedef struct { char pad[0x29]; unsigned char f29; } Ent2E4550;
typedef struct { int f0; unsigned int f4; unsigned int f8; char pC[0x24]; unsigned int f30; unsigned int f34; } Peer2E4550;
extern unsigned int D_0048C450;
extern int D_0048C464;
extern signed char D_0058C178[];
extern unsigned int D_0058806C;
extern int func_002E51B8(int a, Obj2E4550 **out);
extern int func_002E52D8(int a, int i, Ent2E4550 **out);
int __attribute__((weak, section(".dtors_drop"))) func_002DD968(Peer2E4550 **out, int i) { return 0; }
extern void func_002DB188(int *out, int a, int i);
extern void func_002E3340(int a, int b);
extern void func_002E31D0(int a, int b, int c);
void func_002E4550(void)
{
    Obj2E4550 *obj;
    Peer2E4550 *p;
    int x;
    Ent2E4550 *ent;
    unsigned int self;
    int i;
    int j;
    p = 0;
    obj = 0;
    ent = 0;
    if (D_0048C450 >= 4) return;
    if (func_002E51B8(D_0048C450, &obj) != 0) return;
    if (obj == 0) return;
    self = obj->f400;
    if (self >= 0x100) return;
    for (i = 0; i < D_0048C464; i++) {
        if (D_0058C178[i] != 2) continue;
        if (func_002DD968(&p, i) != 0) continue;
        if (p == 0) continue;
        if (self != p->f4 && (p->f4 != -1 || self != p->f8)) continue;
        if (p->f34 == 0 || (p->f30 != 0 && p->f34 + p->f30 < D_0058806C)) {
            func_002E3340(-1, i);
            continue;
        }
        for (j = 0; j < obj->f444; j++) {
            x = 0;
            func_002DB188(&x, D_0048C450, j);
            if (x == 0) continue;
            func_002E52D8(D_0048C450, j, &ent);
            if (ent == 0) continue;
            if (j == self) continue;
            if (ent->f29 != 1) continue;
            func_002E3340(j, i);
        }
        func_002E31D0(i, 0, 0);
    }
    for (j = 0; j < obj->f444; j++) {
        func_002E52D8(D_0048C450, j, &ent);
        if (ent && j != self && ent->f29 == 1)
            ent->f29 = 0;
    }
}

