#include "types.h"
extern void* func_00426590(void);
extern void* func_001692D0(void*);
extern char D_004BF7B0[];
/* Looks up an entry and converts it, else returns the default object. */
void* func_004264D0(void) { void* p = func_00426590(); if (p) return func_001692D0(p); return D_004BF7B0; }
