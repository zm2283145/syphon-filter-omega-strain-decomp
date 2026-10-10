#include "types.h"

typedef struct { int unk0; unsigned char disabled; } Item;
typedef struct { void* owner; } Holder;
extern int NodeNameMap_Find(void* owner);
extern Item** Registry_At(void* table, int key);

/* Looks up the owner's item; returns it unless it is disabled (then 0). */
Item* func_00190F50(Holder* self)
{
    char* owner = self->owner;
    Item* item = *Registry_At(owner + 0x34, NodeNameMap_Find(owner));
    return item->disabled == 0 ? item : 0;
}
