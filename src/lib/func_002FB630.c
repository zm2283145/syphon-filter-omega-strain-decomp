typedef struct { char c[0x26]; } M2F5A58;
extern M2F5A58 D_004AF478;
extern char D_004AF4A0[], D_004AF4B0[], D_004AF4C0[], D_004AF4C8[];
extern int sprintf(char *, const char *, ...);
extern char *func_00129C80(const char *, const char *);
extern int func_00121BC8(const char *);
extern char *strncpy(char *, const char *, unsigned int);
int func_002FB630(char *out, short n)
{
    M2F5A58 months = D_004AF478;
    char mon[16];
    char buf[32];
    int m;
    char *date;
    char *tm;
    if (out == 0) return 2;
    date = D_004AF4A0;
    tm = D_004AF4B0;
    sprintf(mon, D_004AF4C0, date);
    m = (func_00129C80(months.c, mon) - months.c) / 3 + 1;
    sprintf(buf, D_004AF4C8, m, func_00121BC8(date + 4), date + 7, tm, tm + 3, tm + 6);
    strncpy(out, buf, n);
    return 0;
}
