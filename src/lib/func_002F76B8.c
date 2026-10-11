extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034AA50(char *, char *, int, char *, int, int, int);
extern int func_0034AB38(char *, char *, char *, int, char *);
int func_002F76B8(int a, char *out)
{
    char buf[16];
    if (D_004908A0 != 1) return 5;
    if (a == 0) return 2;
    if (out == 0) return 2;
    if (func_0034AA50(D_00525600, D_00525640, 0, buf, a, 0, 0) < 0) return 1;
    if (func_0034AB38(D_00525600, D_00525640, out, 0x10, buf) < 0) return 1;
    return 0;
}
