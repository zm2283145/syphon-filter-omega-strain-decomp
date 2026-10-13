extern int sprintf(char* buf, const char* fmt, ...);
extern char* func_00129C80(const char* s, const char* sub);
extern int func_00121BC8(const char* s);

int func_002E9350(char* out)
{
    char months[] = "JanFebMarAprMayJunJulAugSepOctNovDec\0";
    char buf[16];
    const char* date;
    const char* time;
    int m;

    if (out == 0)
        return 0x17;
    date = "Mar  8 2004";
    time = "12:08:45";
    sprintf(buf, "%.3s", date);
    m = (func_00129C80(months, buf) - months) / 3 + 1;
    sprintf(out, "Time of build: %.2d.%.2d.%.4s.%.2s.%.2s.%.2s", m, func_00121BC8(date + 4), date + 7, time, time + 3, time + 6);
    return 0;
}
