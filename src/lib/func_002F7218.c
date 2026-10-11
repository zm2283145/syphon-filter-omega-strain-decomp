extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C7A8(char *, int);
extern int func_0034C628(char *, char *, int, unsigned short, char *);
int func_002F7218(int a, unsigned char *out, int name, unsigned short port)
{
    char buf[16];
    unsigned char st;
    int r;
    if (out == 0) return 2;
    *out = 0;
    st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    if (func_0034C7A8(buf, name) < 0) return 1;
    r = func_0034C628(D_00525600, D_00525640, a, port, buf);
    if (r < 0) return 1;
    if (r > 0) *out = st;
    return 0;
}
