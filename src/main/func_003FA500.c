#pragma opt_propagation off

typedef struct {
    char pad0[0x91];
    unsigned char flag;
    char pad92[0xE];
} Ent;

typedef struct {
    char pad0[0x20];
    int x20;
    char pad24[0x50];
    int x74;
} Sub;

typedef struct { Ent e[2]; } Pair;
typedef struct {
    Pair pairs[4];
    int x500;
    unsigned char x504;
    char pad505[3];
    Sub* x508;
    Sub* x50C;
    unsigned char x510;
    unsigned char x511;
    unsigned char x512;
    char pad513;
    float x514;
    float x518;
    float x51C;
    float x520;
    float x524;
} Obj;

extern float D_004BE210;
extern float D_004BE218;
extern int D_004BE220[];
extern void func_003D08B0(Sub* s, void* p);

Obj* func_003FA500(Obj* o, Sub* s, int v)
{
    int i;
    o->x508 = s;
    o->x50C = (Sub*)o->x508->x74;
    o->x504 = 0;
    o->x514 = 0.5f;
    o->x518 = D_004BE210;
    o->x51C = 0.5f;
    o->x520 = 1.5f;
    o->x524 = D_004BE218;
    o->x500 = 0;
    func_003D08B0(o->x50C, D_004BE220);
    o->x50C->x20 = v;
    o->x512 = 0;
    o->x511 = 0;
    o->x510 = 0;
    { Pair* p; for (i = 0, p = o->pairs; i < 4; i++, p++) { p->e[0].flag = 0; p->e[1].flag = 0; } }
    return o;
}


