#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { Alloc alloc; int value; } TaggedInt;
extern void std_list_imp_voidPtr_remove_if(void* self, TaggedInt arg);
/* Forwards value, paired with an empty allocator tag, to std_list_imp_voidPtr_remove_if. */
void cLList_cSkaTransPlaybackPtr_Remove(void* self, int value)
{
    Alloc alloc;
    TaggedInt arg;
    arg.alloc = alloc;
    arg.value = value;
    std_list_imp_voidPtr_remove_if(self, arg);
}
