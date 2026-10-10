#include "types.h"
typedef struct { char pad[8]; unsigned char b8; } Sub_143BC0;
typedef struct { Sub_143BC0* sub; char p4[0x9C]; unsigned char a0; char pa1[0x1B]; int bc; int c0; char pc4[0x2B]; unsigned char ef; } S_143BC0;
#pragma cplusplus on
static inline int Busy_143(S_143BC0* s) { int b = (s->ef != 0); if (!b) b = (s->a0 != 0); if (!b) b = (s->bc != 0); if (!b) b = (s->c0 != 0); return b; }
extern "C" bool func_00143BC0(S_143BC0* s) {
    bool r = false;
    if (Busy_143(s) ^ 1) {
        bool idle = !(s->sub != 0) || !(s->sub->b8 != 0);
        if (idle) r = true;
    }
    return r;
}