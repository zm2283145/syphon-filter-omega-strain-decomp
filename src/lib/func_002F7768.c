extern unsigned char D_004908A0;
extern char D_00525600[];
extern char D_00525640[];
extern int func_0034C690(char *, char *, int, int, char *, int);
extern int func_0034AB38(char *, char *, char *, int, char *);
int func_002F7768(int a, char *out)
{
    char buf[0x4C];
    unsigned char st = D_004908A0;
    if (st != 1) return 5;
    if (a < 0) return 2;
    if (out == 0) return 2;
    if (func_0034C690(D_00525600, D_00525640, a, 1, buf, 0x4C) != st) return 1;
    return func_0034AB38(D_00525600, D_00525640, out, 0x10, buf + 0x24) != 0;
}
