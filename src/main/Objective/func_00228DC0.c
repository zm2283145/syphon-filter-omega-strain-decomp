#include "types.h"
typedef struct { char pad[0x24]; unsigned char state; char pad2[0x5B]; int notify; } Objective_228DC0;
extern void* ObjMan_GetService(void);
extern void ObjMan_Notify(void* man, int id);
#pragma opt_common_subs off
void Objective_SetFailed(Objective_228DC0* o) {
    o->state = 2;
    if (o->notify != 0) {
        ObjMan_Notify(ObjMan_GetService(), o->notify);
    }
}
#pragma opt_common_subs reset