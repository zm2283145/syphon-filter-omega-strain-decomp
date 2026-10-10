#include "types.h"
extern int strcmp(void* p);
extern char D_004ABAA0[];
/* Returns whether the test on the global object fails. */
int func_002AAD10(void) { return strcmp(D_004ABAA0) == 0; }
