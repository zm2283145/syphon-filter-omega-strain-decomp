#include "types.h"
typedef struct { char pad[0xC]; int fx0; int fx1; void* s0; void* s1; } Obj_251290;
extern void func_003CB230(int fx, float t);
extern void func_003E8EB0(void* s);
extern void operator_delete(void* p);
Obj_251290* func_00251290(Obj_251290* o, short flag)
{
    if (o) {
        if (o->fx0)
            func_003CB230(o->fx0, 0.1f);
        if (o->fx1)
            func_003CB230(o->fx1, 0.1f);
        if (o->s0)
            func_003E8EB0(o->s0);
        if (o->s1)
            func_003E8EB0(o->s1);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}