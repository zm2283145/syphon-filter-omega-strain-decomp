#include "types.h"
#pragma optimization_level 1

extern char** func_001F2DF0(void* v);

/* Returns the data pointer of the vector. */
char* func_0020BB40(void* v)
{
    return *func_001F2DF0(v);
}
