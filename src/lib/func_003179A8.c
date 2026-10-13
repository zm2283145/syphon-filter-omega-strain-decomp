typedef struct {
    int f0; char a4[4]; int f8; char pc[4]; char a10[4]; char a14[4]; char a18[4];
    int f1C; int f20; int f24; int f28; int f2C; int f30; float f34; int f38; float f3C;
    int f40; int f44; void *buf; int f4C; char p50[8];
} Obj;
extern void *(*D_004E1D34)(int n, int size);
extern float D_004E1C74;
extern int func_0031A018(int, Obj *);
extern int func_0031C838(float, void *);
extern int func_00318A70(void *);
extern int func_00317680(void *);
extern int func_00318658(void *);
int func_003179A8(Obj **pp, int arg)
{
    Obj *o;
    if (pp == 0) return 1;
    *pp = 0;
    o = D_004E1D34(1, sizeof(Obj));
    if (o == 0) return 1;
    *pp = o;
    o->f40 = arg;
    o->f44 = 1;
    o->buf = D_004E1D34(1, 0x40);
    if (o->buf == 0) return 1;
    if (func_0031A018(0x173, o)) return 1;
    if (func_0031C838(D_004E1C74, o->a4)) return 1;
    o->f8 = 0;
    if (func_00318A70(o->a10)) return 1;
    if (func_00317680(o->a14)) return 1;
    if (func_00318658(o->a18)) return 1;
    o->f20 = 1;
    o->f1C = 0;
    o->f28 = 1;
    o->f30 = 0;
    o->f34 = 100.0f;
    o->f38 = 0;
    o->f3C = 100.0f;
    o->f4C = 0;
    return 0;
}


