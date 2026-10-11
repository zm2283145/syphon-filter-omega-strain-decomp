extern void func_00313A20(char *);
extern void func_00313AE8(char *, char *, char *);
extern void func_00313C80(char *, char *, char *);
void func_002F8020(char *a, char *b, char *c, char *d, char *e, char *f)
{
    char ctx[0x60];
    func_00313A20(ctx);
    if (a && b) func_00313AE8(ctx, a, b);
    func_00313AE8(ctx, c, d);
    func_00313C80(ctx, e, f);
}
