typedef struct { char c[0x26]; } M00468708;
extern M00468708 D_004C2C28;
extern char D_004C2C50[], D_004C2C60[], D_004C2C70[], D_004C2C78[];
extern int sprintf(char *, const char *, ...);
extern char *func_00129C80(const char *, const char *);
extern int func_00121BC8(const char *);
int func_00468708(char *out)
{
    M00468708 months = D_004C2C28;
    char mon[16];
    int n;
    char *date = D_004C2C50;
    char *tm = D_004C2C60;
    sprintf(mon, D_004C2C70, date);
    n = (func_00129C80(months.c, mon) - months.c) / 3 + 1;
    sprintf(out, D_004C2C78, n, func_00121BC8(date + 4), date + 7, tm, tm + 3, tm + 6);
    return 0;
}