#include "types.h"
typedef struct { char c; } Tag0020C110;
extern void* func_0020B3C0(void* other);
extern void func_0020AF80(void* self, void* v);
extern void* func_0020BF10(void* other);
extern void* func_0020BEB0(void* other);
extern void func_0020CAE0(void* self, void* first, void* last, Tag0020C110 tag);
#pragma optimization_level 1
void* func_0020C110(void* self, void* other)
{
    void* first;
    void* last;
    Tag0020C110 arg;
    Tag0020C110 tag;
    func_0020AF80(self, func_0020B3C0(other));
    first = func_0020BF10(other);
    last = func_0020BEB0(other);
    arg = tag;
    func_0020CAE0(self, first, last, arg);
    return self;
}
#pragma optimization_level reset