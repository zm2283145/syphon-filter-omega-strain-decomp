#include "types.h"
extern char D_004BB7F8[];
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int func_0035AE90(void* a0, const char* s) { return strcmp(D_004BB7F8, s) == 0; }
