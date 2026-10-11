#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { Alloc alloc; int value; } TaggedInt;
extern void ActiveList_EraseMatching(void* self, TaggedInt arg);
/* Forwards value, paired with an empty allocator tag, to ActiveList_EraseMatching. */
void func_003AB880(void* self, int value)
{
    Alloc alloc;
    TaggedInt arg;
    arg.alloc = alloc;
    arg.value = value;
    ActiveList_EraseMatching(self, arg);
}
