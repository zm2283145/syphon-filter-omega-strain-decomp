typedef struct { unsigned int ms; unsigned int sec; unsigned int min; unsigned int hour; unsigned int day; unsigned int month; unsigned int year; unsigned int base; } ScfClock;
typedef struct { unsigned int ms; int pad[3]; } ScfNow;
/* retail defines func_00306740 earlier in the same unit; declaring it pure reproduces that delay-slot fill */
extern int func_00306740(void) __attribute__((pure));
extern int func_00306030(void *out);
extern unsigned char D_00491309;
extern ScfClock D_00529840;
int func_003069E0(ScfClock *out)
{
    ScfClock c;
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


