typedef struct { char c[0x26]; } M2F5A58;
static const M2F5A58 months_init = { "JanFebMarAprMayJunJulAugSepOctNovDec" };
extern int sprintf(char *, const char *, ...);
extern char *strstr(const char *, const char *);
extern int atoi(const char *);
extern char *strncpy(char *, const char *, unsigned int);
int func_002FB630(char *out, short n)
{
    M2F5A58 months = months_init;
    char mon[16];
    char buf[32];
    int m;
    char *date;
    char *tm;
    if (out == 0) return 2;
    date = "Mar  8 2004";
    tm = "12:07:55";
    sprintf(mon, "%.3s", date);
    m = (strstr(months.c, mon) - months.c) / 3 + 1;
    sprintf(buf, "%.2d.%.2d.%.4s.%.2s.%.2s.%.2s", m, atoi(date + 4), date + 7, tm, tm + 3, tm + 6);
    strncpy(out, buf, n);
    return 0;
}
