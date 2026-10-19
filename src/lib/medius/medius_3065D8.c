/*
 * lib/medius: 5 files, 003065D8-003069E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003065D8 */
typedef struct { int f0; int f4; int f8; } ScfCnt_5D8;
extern ScfCnt_5D8 D_00529830;
extern int Time_UpdateCounter(void);
int func_003065D8(int *out)
{
    int ret = 2;
    if (out == 0) return ret;
    if (Time_UpdateCounter() != 0) return 1;
    out[0] = D_00529830.f0;
    out[1] = D_00529830.f8;
    return 0;
}
/* merge_units: end func_003065D8 */

/* merge_units: begin func_00306630 */
extern int func_0010CEE0(unsigned short t, void (*cb)(), int arg);
extern int GetThreadId(void);
extern void SleepThread(void);
extern void func_00306D70();
extern double SoftFloat_FloatToDouble(float);
extern int SoftFloat_UnpackAndCompare(double, double);
int func_00306630(unsigned int ms)
{
    float t = ms * 0.015734f;
    unsigned short n;
    while (SoftFloat_UnpackAndCompare(SoftFloat_FloatToDouble(t), 0.0) > 0) {
        if (t > 65535.0f) {
            n = 0xFFFF;
            t -= 65535.0f;
        } else {
            n = (unsigned int)t;
            t = 0.0f;
        }
        func_0010CEE0(n, func_00306D70, GetThreadId());
        SleepThread();
    }
    return 0;
}
/* merge_units: end func_00306630 */

/* merge_units: begin func_00306740 */
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
/* merge_units: end func_00306740 */

/* merge_units: begin func_00306870 */
typedef struct { unsigned int ms; unsigned int sec; unsigned int min; unsigned int hour; unsigned int day; unsigned int month; unsigned int year; unsigned int base; } ScfClock_00306870;
typedef struct { unsigned int ms; int pad[3]; } ScfNow;
/* retail defines func_00306740 earlier in the same unit; declaring it pure reproduces that delay-slot fill */
extern int func_00306740(void) __attribute__((pure));
extern int sprintf(char *s, const char *fmt, ...);
extern unsigned char D_00491309;
#if 0 /* merge_units */
extern ScfClock_00306870 D_00529840;
#endif /* merge_units */
#define D_00529840 (*(ScfClock_00306870*)&D_00529840) /* merge_units */

extern char D_004AF750[];
int func_00306870(char *out)
{
    ScfClock_00306870 c;
    ScfNow now;
    if (out == 0) return 2;
    if (D_00491309 == 0) {
        if (func_00306740() != 0) return 1;
        D_00491309 = 1;
    }
    c = D_00529840;
    if (func_00306030(&now) != 0) return 1;
    c.ms += now.ms - D_00529840.base;
    c.sec += c.ms / 1000;
    c.ms %= 1000;
    c.min += c.sec / 60;
    c.sec %= 60;
    c.hour += c.min / 60;
    c.min %= 60;
    c.hour %= 24;
    sprintf(out, D_004AF750, c.hour, c.min, c.sec);
    return 0;
}
#undef D_00529840 /* merge_units */
/* merge_units: end func_00306870 */

/* merge_units: begin func_003069E0 */
typedef struct { unsigned int ms; unsigned int sec; unsigned int min; unsigned int hour; unsigned int day; unsigned int month; unsigned int year; unsigned int base; } ScfClock_003069E0;
#if 0 /* merge_units */
extern ScfClock_003069E0 D_00529840;
#endif /* merge_units */
#define D_00529840 (*(ScfClock_003069E0*)&D_00529840) /* merge_units */

int func_003069E0(ScfClock_003069E0 *out)
{
    ScfClock_003069E0 c;
    ScfNow now;
    if (out == 0) return 2;
    if (D_00491309 == 0) {
        if (func_00306740() != 0) return 1;
        D_00491309 = 1;
    }
    c = D_00529840;
    if (func_00306030(&now) != 0) return 1;
    c.ms += now.ms - D_00529840.base;
    c.sec += c.ms / 1000;
    c.ms %= 1000;
    c.min += c.sec / 60;
    c.sec %= 60;
    c.hour += c.min / 60;
    c.min %= 60;
    if (c.hour >= 24) {
        if (func_00306740() != 0) return 1;
        c = D_00529840;
    }
    out->year = c.year;
    out->month = c.month;
    out->day = c.day;
    out->hour = c.hour;
    out->min = c.min;
    out->sec = c.sec;
    out->ms = c.ms;
    out->base = c.base;
    return 0;
}
#undef D_00529840 /* merge_units */
/* merge_units: end func_003069E0 */
