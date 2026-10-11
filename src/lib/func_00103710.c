typedef struct { short x0; short x2; int x4; int x8; } GsInfo3710;
extern GsInfo3710 *func_00102A18(void);
extern void func_0010D5F0(void);
extern long func_0010D680(void);

int func_00103710(void)
{
    GsInfo3710 *g = func_00102A18();
    long v;
    if (g->x8 == 0) {
        func_0010D5F0();
        if (g->x0 != 1) return 1;
        return (int)((*(volatile unsigned long *)0x12001000 >> 13) & 1);
    }
    v = (func_0010D680() >> 13) & 1;
    if (g->x0 != 1) return 1;
    return (int)v;
}