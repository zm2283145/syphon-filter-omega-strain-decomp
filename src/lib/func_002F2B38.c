extern void func_002F2C28(char *);
extern void func_002F2C68(char *, int, int);
extern void func_002F2DC8(int, char *);
void func_002F2B38(int a, int b, int c)
{
    char ctx[0x60];
    func_002F2C28(ctx);
    func_002F2C68(ctx, a, b);
    func_002F2DC8(c, ctx);
}