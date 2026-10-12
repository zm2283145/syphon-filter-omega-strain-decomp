typedef struct { int x0; int x4; int x8; int xC[3]; } Out71A8;
typedef struct { char pad[0x38]; float f38; float f3C; } St71A8;
typedef struct { float f0; float f4; float f8; float fC; float f10; int x14[3]; } Prm71A8;
extern int func_003170A8(float a, float b, float c);
extern void func_00317138(float x, int v, float *a, float *b);
extern int func_0031D1D8(float x);
extern float func_0031D260(int v);
extern float func_0031D290(float a, float b, float c, float d);
extern int func_00317020(float x);
extern void func_003191F8(int *a, int *b, int n, float x);
void func_003171A8(Out71A8 *o, St71A8 *st, Prm71A8 *p)
{
    float *q = &p->f8;
    o->x4 = func_003170A8(st->f38, p->f4, q[1]);
    func_00317138(st->f38, o->x4, &p->f4, &p->fC);
    o->x8 = func_0031D1D8(q[0]);
    q[0] = func_0031D260(o->x8);
    p->f0 = func_0031D290(st->f3C, q[0], st->f38, q[1]);
    o->x0 = func_00317020(p->f10);
    func_003191F8(p->x14, o->xC, 0xC, q[1]);
    st->f38 = q[1];
    st->f3C = q[0];
}
