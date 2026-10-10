#include "types.h"

typedef struct Rec3C {
    char b[0x3C];
} Rec3C;

extern void func_001BECC0(Rec3C*, Rec3C*);

/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec3C* func_00366EB0(Rec3C* first, Rec3C* last, Rec3C* destEnd) {
    while (last > first) {
        Rec3C* src = --last;
        Rec3C* dst = --destEnd;
        func_001BECC0(dst, src);
    }
    return destEnd;
}
