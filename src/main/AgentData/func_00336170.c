#include "types.h"
extern void* D_004FFC04;
extern void* func_002C90F0(void*);
/* Returns the global lookup result if set, else the object's embedded member at +0x8AC. */
void* func_00336170(char* p) { void* r = func_002C90F0(D_004FFC04); if (r) return r; return p + 0x8AC; }
