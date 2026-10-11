typedef struct { char c[0x26]; } M00468708;
extern M00468708 D_004AD3D8;
extern char D_004AD400[], D_004AD410[], D_004AD420[], D_004AD428[];
extern int sprintf(char *, const char *, ...);
extern char *func_00129C80(const char *, const char *);
extern int func_00121BC8(const char *);
int func_002D0728(char *out)
{
    M00468708 months = D_004AD3D8;
    char mon[16];
    int n;
    char *date = D_004AD400;
    char *tm = D_004AD410;
    sprintf(mon, D_004AD420, date);
    n = (func_00129C80(months.c, mon) - months.c) / 3 + 1;
    sprintf(out, D_004AD428, n, func_00121BC8(date + 4), date + 7, tm, tm + 3, tm + 6);
    return 0;
}