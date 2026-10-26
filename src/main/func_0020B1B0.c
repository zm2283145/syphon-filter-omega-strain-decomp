#include "types.h"
#pragma optimization_level 1

typedef struct Rec0C {
    char b[0x24];
} Rec0C;

extern void cSkaTransBLEND_opAssign(Rec0C*, Rec0C*);

/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec0C* std_copy_backward_cSkaTransBLEND_copy_backward(Rec0C* first, Rec0C* last, Rec0C* destEnd) {
    while (last > first) {
        destEnd--;
        last--;
        cSkaTransBLEND_opAssign(destEnd, last);
    }
    return destEnd;
}
