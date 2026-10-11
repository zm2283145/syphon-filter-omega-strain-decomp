typedef struct { int f0; int f4; int f8; } Ent;
typedef struct { char pad[0x400]; int f400; } Ctx;
typedef struct { unsigned char a; char pad; unsigned short b; } Pk;
extern unsigned int D_0048C450;
extern int D_005983E0;
extern int func_002DD968(unsigned int *, unsigned short);
extern int func_002E51B8(unsigned int, Ctx **);
extern int func_002DE950(int, unsigned short, int);
extern unsigned char func_002E6090(int);
extern int func_002DE880(int, int, int, int, int, Pk *);
int func_002E74E8(int a, int b, int c, unsigned short *idp)
{
    Pk pk;
    unsigned int e[1];
    Ctx *ctx[1];
    unsigned short id;
    ctx[0] = 0;
    e[0] = 0;
    if (idp == 0) return -1;
    if (D_0048C450 >= 4) return -1;
    id = *idp;
    if (id >= 0x1000) return -1;
    func_002DD968(e, id);
    if (e[0] == 0) return -1;
    if (func_002E51B8(D_0048C450, ctx) || ctx[0] == 0) return -1;
    if (((Ent *)e[0])->f8 != ctx[0]->f400 || ((Ent *)e[0])->f4 != -1) return 2;
    ((Ent *)e[0])->f4 = c;
    func_002DE950(((Ent *)e[0])->f4, id, -2);
    pk.a = func_002E6090(c);
    pk.b = id;
    func_002DE880(0x50, a, -1, D_005983E0, 4, &pk);
    return 2;
}


