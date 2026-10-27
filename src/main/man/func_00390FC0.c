#include "types.h"

typedef struct { char pad[0x40]; char timer[0x2380]; unsigned short ticks; } Obj390;

extern void cMan_MergeSKLs(Obj390* self);
extern void SKL_RemoveBlanks(void* timer);
extern unsigned short SKL_CountAttribs(void* timer);
extern void cMan_SortParts(Obj390* self);
extern void cMan_GetTextureIDs(Obj390* self);
extern void cMan_BuildMan(Obj390* self, int flag);

/* Resets the object, restarts its timer and caches the tick count. */
void cMan_AddCostume(Obj390* self)
{
    cMan_MergeSKLs(self);
    SKL_RemoveBlanks(self->timer);
    self->ticks = SKL_CountAttribs(self->timer);
    cMan_SortParts(self);
    cMan_GetTextureIDs(self);
    cMan_BuildMan(self, 1);
}
