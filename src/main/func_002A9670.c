#include "types.h"
extern char D_004AB910[];
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int func_002A9670(void* a0, const char* s) { return strcmp(D_004AB910, s) == 0; }
