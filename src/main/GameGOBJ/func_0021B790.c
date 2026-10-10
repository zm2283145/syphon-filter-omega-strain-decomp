#include "types.h"

typedef struct Gobj {
    char pad[0xC];
    int handle;
} Gobj;

typedef struct TriggerEventMsg {
    void* vtable;
    char pad[0x20];
    int event;      /* 0x24 */
    int param;      /* 0x28 */
    int other;      /* 0x2C */
    int source;     /* 0x30 */
} TriggerEventMsg;

extern int D_004F5440;
extern int D_004DAF10;
extern void Event_Construct(TriggerEventMsg*, void*);

/* Constructor: cGOBJTriggerEventMsg(event, param, source, other). */
TriggerEventMsg* cGOBJTriggerEventMsg_ctor(TriggerEventMsg* m, int event, int param, Gobj* source, Gobj* other) {
    Event_Construct(m, &D_004F5440);
    m->vtable = &D_004DAF10;
    m->event = event;
    m->param = param;
    m->source = source != 0 ? source->handle : 0;
    m->other = other != 0 ? other->handle : 0;
    return m;
}
