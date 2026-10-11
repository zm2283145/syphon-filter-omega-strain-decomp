extern void func_00313A20(char *);
extern void func_00313AE8(char *, int, int);
extern void func_00313C80(char *, int, int);
void func_002F7FB0(int a, int b, int c, int d)
{
    char ctx[0x60];
    func_00313A20(ctx);
    func_00313AE8(ctx, a, b);
    func_00313C80(ctx, c, d);
}