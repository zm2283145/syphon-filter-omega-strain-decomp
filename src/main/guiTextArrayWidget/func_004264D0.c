#include "types.h"
extern void* func_00426590(void);
extern void* String_CStr(void*);
const unsigned int D_004BF7B0[4] = { 0x0, 0x0, 0x0, 0x0 };
/* Looks up an entry and converts it, else returns the default object. */
void* func_004264D0(void) { void* p = func_00426590(); if (p) return String_CStr(p); return ((char*)D_004BF7B0); }
