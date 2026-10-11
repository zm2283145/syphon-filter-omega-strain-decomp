extern void func_002F2C28(char *);
extern void func_002F2C68(char *, char *, char *);
extern void func_002F2DC8(char *, char *);
void func_002F2B98(char *a, char *b, char *c, char *d, char *e)
{
    char ctx[0x60];
    func_002F2C28(ctx);
    if (a && b) func_002F2C68(ctx, a, b);
    func_002F2C68(ctx, c, d);
    func_002F2DC8(e, ctx);
}
