#include "types.h"
typedef struct { float time; unsigned char b4; char pad5[3]; int f8; int pad; void* target; } T4EE0;
extern char D_004A7218[];
extern void func_0041BEB0(void* target, const char* text, int zero);
void func_00244EE0(T4EE0* t, char* text, float time) {
    t->time = time;
    t->f8 = 0;
    t->b4 = 0;
    if (t->target)
        func_0041BEB0(t->target, text ? text : D_004A7218, 0);
}
