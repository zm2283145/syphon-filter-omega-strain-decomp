#include "types.h"
extern char D_004B8680[];
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int func_003267E0(void* a0, const char* s) { return strcmp(D_004B8680, s) == 0; }
