#include "types.h"
extern char D_004C2860[];
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int func_00463130(void* a0, const char* s) { return strcmp(D_004C2860, s) == 0; }
