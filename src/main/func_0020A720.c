#include "types.h"
#pragma optimization_level 1

typedef struct Rec0C {
    char b[0xC];
} Rec0C;

extern void func_00209E50(Rec0C*, Rec0C*);

/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec0C* func_0020A720(Rec0C* first, Rec0C* last, Rec0C* destEnd) {
    while (last > first) {
        destEnd--;
        last--;
        func_00209E50(destEnd, last);
    }
    return destEnd;
}
