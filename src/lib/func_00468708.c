typedef struct { char c[0x26]; } M00468708;
static const M00468708 months_init = { "JanFebMarAprMayJunJulAugSepOctNovDec" };
extern int sprintf(char *, const char *, ...);
extern char *func_00129C80(const char *, const char *);
extern int atoi(const char *);
int func_00468708(char *out)
{
    M00468708 months = months_init;
    char mon[16];
    int n;
    char *date = "Nov 25 2003";
    char *tm = "16:13:50";
    sprintf(mon, "%.3s", date);
    n = (func_00129C80(months.c, mon) - months.c) / 3 + 1;
    sprintf(out, "%.2d.%.2d.%.4s.%.2s.%.2s.%.2s", n, atoi(date + 4), date + 7, tm, tm + 3, tm + 6);
    return 0;
}