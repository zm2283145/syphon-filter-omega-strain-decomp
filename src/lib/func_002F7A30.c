extern void *memset(void *, int, unsigned int);
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034BCE0(char *, char *, int *, int, char *, int);
extern int func_0034C840(char *, char *);
int func_002F7A30(char *out)
{
    char buf[16];
    int x;
    if (out == 0) return 2;
    memset(buf, 0, 0x10);
    if (func_0034BCE0(D_00525600, D_00525640, &x, 1, buf, 2) < 0) return 1;
    return func_0034C840(out, buf) != 0;
}
