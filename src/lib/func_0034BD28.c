extern int sprintf(char *buf, const char *fmt, ...);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern char *func_00129C80(const char *searchee, const char *lookfor);
extern int atoi(const char *s);

int func_0034BD28(char *out, int n)
{
    char months[] = "JanFebMarAprMayJunJulAugSepOctNovDec\0";
    char mon[16];
    char buf[32];
    const char *date;
    const char *time;
    int m;

    if (out == 0)
        return -0x200;
    date = "Mar  8 2004";
    time = "12:06:56";
    sprintf(mon, "%.3s", date);
    m = (func_00129C80(months, mon) - months) / 3 + 1;
    sprintf(buf, "%.2d.%.2d.%.4s.%.2s.%.2s.%.2s", m, atoi(date + 4), date + 7,
            time, time + 3, time + 6);
    strncpy(out, buf, n);
    return 0;
}
