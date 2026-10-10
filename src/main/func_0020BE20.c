#include "types.h"

typedef struct { char tag; } Alloc;

extern void* func_0020BF10(void* other);
extern void* func_0020BEB0(void* other);
extern void func_0020CC80(void* self, void* first, void* last, Alloc alloc);

#pragma optimization_level 1
/* Assigns the contents of other to self unless they are the same object; returns self (unit built at -O1). */
void* func_0020BE20(void* self, void* other)
{
    if (self != other) {
        Alloc a;
        Alloc b;
        void* first = func_0020BF10(other);
        void* last = func_0020BEB0(other);
        b = a;
        func_0020CC80(self, first, last, b);
    }
    return self;
}
#pragma optimization_level reset
