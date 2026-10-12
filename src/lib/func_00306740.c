typedef struct { unsigned char stat, second, minute, hour, pad, day, month, year; } CdClock;
typedef struct { int f0; int sec; int min; int hour; int day; int month; int year; int t[2]; } ScfClock;
extern int sceCdReadClock(CdClock *c);
extern void func_00326728(void *t);
extern int func_00306030(void *out);
extern ScfClock D_00529840;
#define BCD(x) (((x) >> 4) * 10 + ((x) & 0xF))
int func_00306740(void)
{
    CdClock c;
    sceCdReadClock(&c);
    func_00326728(&c);
    D_00529840.sec = BCD(c.second);
    D_00529840.min = BCD(c.minute);
    D_00529840.hour = BCD(c.hour);
    D_00529840.day = BCD(c.day);
    D_00529840.month = BCD(c.month);
    D_00529840.year = BCD(c.year);
    D_00529840.f0 = 0;
    return func_00306030(D_00529840.t) != 0;
}
