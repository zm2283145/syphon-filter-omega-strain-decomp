#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { Alloc alloc; int value; } TaggedInt;
extern void func_003D5D10(void* self, TaggedInt arg);
/* Forwards value, paired with an empty allocator tag, to func_003D5D10. */
void func_003D35D0(void* self, int value)
{
    Alloc alloc;
    TaggedInt arg;
    arg.alloc = alloc;
    arg.value = value;
    func_003D5D10(self, arg);
}
