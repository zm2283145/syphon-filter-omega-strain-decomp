#include "types.h"

typedef struct { char pad[0x40]; char timer[0x2380]; unsigned short ticks; } Obj390;

extern void ActorModel_SwitchBodyPacking(Obj390* self);
extern void Appearance_RemoveBlankPairs(void* timer);
extern unsigned short Appearance_GetPairCount(void* timer);
extern void Appearance_ReorderParts(Obj390* self);
extern void func_0038E030(Obj390* self);
extern void ActorModel_Setup(Obj390* self, int flag);

/* Resets the object, restarts its timer and caches the tick count. */
void ActorModel_SwitchBodies(Obj390* self)
{
    ActorModel_SwitchBodyPacking(self);
    Appearance_RemoveBlankPairs(self->timer);
    self->ticks = Appearance_GetPairCount(self->timer);
    Appearance_ReorderParts(self);
    func_0038E030(self);
    ActorModel_Setup(self, 1);
}
