#include "types.h"
extern char D_004C0000[];
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int func_0043BB90(void* a0, const char* s) { return strcmp(D_004C0000, s) == 0; }
