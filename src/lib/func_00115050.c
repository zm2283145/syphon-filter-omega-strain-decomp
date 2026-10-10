#include "types.h"
extern int func_00114A80(int a, int b, int c, void* sp);
/* Calls func_00114A80 passing the current stack pointer. */
int func_00115050(int a, int b, int c) { int dummy; return func_00114A80(a, b, c, &dummy); }
