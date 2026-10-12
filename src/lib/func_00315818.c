typedef struct { int a; int b; int c; int d; int e; int f; int g; } Arg5818;
typedef struct { int h; char pad[2]; unsigned char b6; } Ent5818;
typedef struct {
    int id;
    char pad0[8];
    int xC;
    char pad1[0xA9 - 0x10];
    unsigned char mode;
    char pad2[2];
    int xAC;
    int xB0;
    int xB4;
    int xB8;
    int xBC;
} Obj5818;
extern int D_00598428;
extern int func_00314FE0(Obj5818 *o);
extern int func_002DE880(int op, int id, int h, int k, int len, Arg5818 *a);
int func_00315818(Obj5818 *o, Ent5818 *e)
{
    Arg5818 a;
    int m, r;
    if (func_00314FE0(o) != 1) return 0x17;
    if (e == 0) return 0x17;
    m = o->mode;
    if (m != 1) return 0x17;
    a.a = o->id;
    a.b = o->xC;
    a.c = o->xB0;
    a.d = o->xB8;
    a.e = o->xAC;
    a.f = o->xB4;
    a.g = o->xBC;
    r = func_002DE880(0x50, o->id, e->h, D_00598428, 0x1C, &a);
    if (r == 0) e->b6 = m;
    return r;
}
