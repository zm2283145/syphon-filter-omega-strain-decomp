#include "types.h"
typedef struct { int a, b; float ang; } S1B8;
static inline int Gt1B8(float a, float b) { return a > b; }
void func_001B8AC0(S1B8* s) {
    float a = s->ang;
    for (;;) {
        if (Gt1B8(a, 3.1415927f)) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
}