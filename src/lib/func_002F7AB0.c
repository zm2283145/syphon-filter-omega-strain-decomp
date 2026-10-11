extern void *memset(void *, int, unsigned int);
extern int D_004908D4;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034B2C0(char *, char *, int, int, char *, int);
extern int func_0034C840(char *, char *);
int func_002F7AB0(char *out)
{
    char buf[16];
    if (out == 0) return 2;
    if (D_004908D4 < 0) return 1;
    memset(buf, 0, 0x10);
    if (func_0034B2C0(D_00525600, D_00525640, D_004908D4, 0xB, buf, 0x10)) return 1;
    return func_0034C840(out, buf) != 0;
}
