#define F(p, o, T) (*(T *)((char *)(p) + (o)))
extern int func_00106C38(void *, int);
extern void func_00107748(void *);
extern int func_001064A0(void *);
extern void func_001054A8(void *, int);
extern void func_0010BD90(void *, const char *);

int func_001069F0(void *ctx)
{
    int r;
    int n;

    F(ctx, 0x828, int) = 0;
    n = F(ctx, 0x144, int) * F(ctx, 0x148, int);
    F(ctx, 0x82C, int) = 0;
    if (F(ctx, 0x18C, int) != 3)
        n = n >> 1;
    do {
        r = func_00106C38(ctx, n);
    } while (r == 1 || r == 3);
    func_00107748(ctx);
    if (!func_001064A0(ctx)) {
        if (F(ctx, 0x10A0, int))
            return 4;
        r = 2;
    }
    while ((*(volatile unsigned int *)0x1000D400 >> 8) & 1)
        ;
    if (r == 0)
        func_001054A8(ctx, F(ctx, 0x828, int) == 0);
    if (r == 1 || r == 2)
        func_0010BD90(ctx, "= Skip to the next picture =");
    return r == 0;
}

