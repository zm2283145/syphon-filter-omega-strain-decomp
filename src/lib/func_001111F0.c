typedef struct { int x0; int x4; } P11F0;
extern P11F0 D_004E5F80;
extern volatile int D_004E5FC0;
extern int D_0048623C;
extern void func_001111B0(int);
extern void func_001112E0(void);
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_001111E0(void);
register int gp __asm__("$28");
int func_001111F0(int a, int b)
{
    P11F0 *p = &D_004E5F80;
    int s, old;
    func_001111B0(0x1B);
    if (D_0048623C == 0) func_001112E0();
    s = func_001161A0();
    old = D_004E5F80.x0;
    p->x4 = b;
    D_004E5F80.x0 = a;
    D_004E5FC0 = gp;
    if (s) func_001161F8();
    func_001111E0();
    return old;
}