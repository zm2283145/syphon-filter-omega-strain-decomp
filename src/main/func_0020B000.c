#include "types.h"
#pragma optimization_level 1
typedef struct { int w0; } Item0B000;
extern void func_0020B050(Item0B000* dst);
Item0B000* func_0020B000(Item0B000* dst, int unused, int v)
{
    func_0020B050(dst);
    dst->w0 = v;
    return dst;
}