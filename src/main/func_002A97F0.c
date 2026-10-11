#include "types.h"
typedef struct { char pad[0x8C]; void* x8C; int x90; int pad94; int pad98; int x9C; } S2A97F0;
extern int func_00421480(int a, int b);
extern char* func_00421430(int a, int b);
extern void func_0041BEB0(void* w, char* text, int f);
extern void func_002A96A0(S2A97F0* s, int f);
extern int func_0033CF90(S2A97F0* s, int a, unsigned short b, int c, int d);
int func_002A97F0(S2A97F0* s, int a, unsigned short b, int c, int d)
{
    if (s->x90 == a && b == 0x13) {
        s->x9C = func_00421480(s->x90, d);
        if (s->x8C)
            func_0041BEB0(s->x8C, func_00421430(s->x90, d), 0);
    }
    if (b == 0x1A && c == 0x1E) {
        func_002A96A0(s, 0);
        return 1;
    }
    return func_0033CF90(s, a, b, c, d);
}