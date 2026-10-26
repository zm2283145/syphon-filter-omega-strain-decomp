#include "types.h"
#pragma optimization_level 1

extern void cTimerDisable_ctor(int*);
extern void Mem_Free(int, int, int, int);
extern void cTimerDisable_dtor(int*, int);

/* Runs Mem_Free(b, a, d, e) inside a scoped guard object. */
void opDelete_charP_int_bool_charP_etc(int a, int b, int c, int d, int e) {
    int guard;
    cTimerDisable_ctor(&guard);
    Mem_Free(b, a, d, e);
    cTimerDisable_dtor(&guard, -1);
}
