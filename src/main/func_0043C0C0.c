#include "types.h"
extern int strcmp(void* p);
extern char D_004C00E0[];
/* Returns whether the test on the global object fails. */
int func_0043C0C0(void) { return strcmp(D_004C00E0) == 0; }
