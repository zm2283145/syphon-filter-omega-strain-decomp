#include "types.h"
extern void FunctionList_CallEach(void* a, void* b, void* c, void* d);
extern char D_004D8D10[];
extern char D_004D903C[];
extern char D_004E1B00[];
#pragma opt_common_subs off
void StaticInit_RunAll(void) { FunctionList_CallEach(D_004D8D10, D_004D903C, D_004E1B00, D_004E1B00); }