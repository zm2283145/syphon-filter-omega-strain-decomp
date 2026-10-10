#include "types.h"

typedef struct { char pad[0xA]; unsigned char mask; } MaskObj;
extern int func_0032C2D0(void* self, MaskObj* obj);

/* Tests the mask bit (4 << slot) of obj, where slot comes from func_0032C2D0. */
int func_0032C290(void* self, MaskObj* obj)
{
    int slot = func_0032C2D0(self, obj);
    return (obj->mask & (4 << slot)) != 0;
}
