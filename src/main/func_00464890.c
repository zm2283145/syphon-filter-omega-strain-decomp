#include "types.h"
extern int strcmp(void* p);
extern char D_004C28E8[];
/* Returns whether the test on the global object fails. */
int func_00464890(void) { return strcmp(D_004C28E8) == 0; }
