#include "types.h"
extern int strcmp(void* p);
extern char D_004BA660[];
/* Returns whether the test on the global object fails. */
int func_00349EA0(void) { return strcmp(D_004BA660) == 0; }
