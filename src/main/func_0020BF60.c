#include "types.h"
#pragma optimization_level 1

typedef struct Rec0C {
    char b[0x14];
} Rec0C;

extern void func_0020BD30(Rec0C*, Rec0C*);

/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec0C* func_0020BF60(Rec0C* first, Rec0C* last, Rec0C* destEnd) {
    while (last > first) {
        destEnd--;
        last--;
        func_0020BD30(destEnd, last);
    }
    return destEnd;
}
