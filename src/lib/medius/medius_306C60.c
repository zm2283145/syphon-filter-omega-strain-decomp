#include "types.h"
typedef struct { unsigned int sec; unsigned int ticks; unsigned int ms; unsigned int last; } TimeCounter306;
extern unsigned char D_00491308[];
extern TimeCounter306 D_00529830;
extern int func_00306C00(void);
extern unsigned int func_00306BF0(void);
static inline float TicksToMs306(float f)
{
    return f * 0.0033908419776707889f;
}
int Time_UpdateCounter(void)
{
    unsigned int now, d;
    if (!D_00491308[0] && func_00306C00()) return 1;
    now = func_00306BF0();
    d = now - D_00529830.last;
    D_00529830.last = now;
    if (d) {
        D_00529830.ticks += d;
        while (D_00529830.ticks > 294912000) {
            D_00529830.sec++;
            D_00529830.ticks -= 294912000;
        }
        { TimeCounter306* t = &D_00529830; t->ms = TicksToMs306(t->ticks); }
    }
    return 0;
}