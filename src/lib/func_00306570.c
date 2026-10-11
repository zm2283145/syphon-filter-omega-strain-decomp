typedef struct { unsigned long a; unsigned char b; } ScfClk_570;
extern ScfClk_570 D_00529818, D_004AF740;
extern int func_00306558(ScfClk_570 *c);
ScfClk_570 *func_00306570(void)
{
    ScfClk_570 *c = &D_00529818;
    if (func_00306558(c) != 0) {
        c->a = D_004AF740.a;
        c->b = D_004AF740.b;
    }
    return c;
}