#pragma cplusplus on
#include "types.h"
struct Obj_E980 { virtual void Set(int on, signed char st); };
struct S_E980 { unsigned char mode; bool active; unsigned char state; unsigned char prev; int pad4; Obj_E980* obj; };
/* switch the attached object on (state 6) or restore its previous state */
extern "C" void cDrawAndHolsterWeapon_ActionManager_TriggerCallback(S_E980* s)
{
    if (s->obj) {
        if (s->state != 6) {
            s->obj->Set(1, 6);
            s->state = 6;
            { unsigned char m = (s->prev != 6) ? 2 : 0; s->mode = m; s->active = m != 0; }
        } else {
            s->obj->Set(0, (signed char)s->prev);
            s->prev = 6;
            s->mode = 0;
            s->active = 0;
        }
    }
}
