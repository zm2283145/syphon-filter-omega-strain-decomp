#include "types.h"

typedef struct { char pad[0x40]; char timer[0x2380]; unsigned short ticks; } Obj390;

extern void func_00390940(Obj390* self);
extern void func_00406E00(void* timer);
extern unsigned short func_00406DC0(void* timer);
extern void Appearance_ReorderParts(Obj390* self);
extern void func_0038E030(Obj390* self);
extern void ActorModel_Setup(Obj390* self, int flag);

/* Resets the object, restarts its timer and caches the tick count. */
void func_00390FC0(Obj390* self)
{
    func_00390940(self);
    func_00406E00(self->timer);
    self->ticks = func_00406DC0(self->timer);
    Appearance_ReorderParts(self);
    func_0038E030(self);
    ActorModel_Setup(self, 1);
}
