extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C3D8(char *, char *, int, unsigned short *, char *);
extern int func_0034C840(char *, char *);
int func_002F74C0(int a, unsigned char *out, char *name, unsigned short *port)
{
    char buf[16];
    unsigned short p;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (D_004908A0 != 1) return 5;
    if (a < 0) return 2;
    if (name == 0) return 2;
    r = func_0034C3D8(D_00525600, D_00525640, a, &p, buf);
    if (r < 0) {
        if (r != -500) return 1;
        r = 0;
    }
    if (r > 0) {
        *out = 1;
        *port = p;
        if (func_0034C840(name, buf)) return 1;
    }
    return 0;
}
