#include "types.h"
typedef struct { char c; } Tag002099C0;
extern int func_002099F0(void* a, void* b, Tag002099C0 tag);
#pragma optimization_level 1
int func_002099C0(void* a, void* b)
{
    Tag002099C0 tag;
    return func_002099F0(a, b, tag);
}
#pragma optimization_level reset