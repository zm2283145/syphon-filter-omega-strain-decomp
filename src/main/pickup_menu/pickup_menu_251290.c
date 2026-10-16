#include "types.h"
typedef struct { char pad[0xC]; int fx0; int fx1; void* s0; void* s1; } Obj_251290;
extern void Object_DeleteLater(int fx, float t);
extern void IeElement_Release(void* s);
extern void operator_delete(void* p);
Obj_251290* PickupMenuEntry_dtor(Obj_251290* o, short flag)
{
    if (o) {
        if (o->fx0)
            Object_DeleteLater(o->fx0, 0.1f);
        if (o->fx1)
            Object_DeleteLater(o->fx1, 0.1f);
        if (o->s0)
            IeElement_Release(o->s0);
        if (o->s1)
            IeElement_Release(o->s1);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}