#include "types.h"

typedef struct Obj60 {
    char pad[0xC];
    int id;
    char pad2[0x50];
    void* target;
} Obj60;

/* Small notification message built on the stack. */
typedef struct NotifyMsg {
    void* vtable;
    char pad04[0x18];
    int size;           /* 0x1C */
    unsigned char kind; /* 0x20 */
    char pad21[3];
    Obj60* sender;      /* 0x24 */
    int id;             /* 0x28 */
    int pad2C;
} NotifyMsg;

extern int D_00506248;
extern int D_004DCF70;
extern int D_004DCF10;
extern void Event_Construct(NotifyMsg*, void*);
extern void Event_Send(NotifyMsg*, void*, int);
extern void cMessage_dtor(NotifyMsg*, int);

/* Sends a notification message (kind 4) about this object to its target. */
void func_00283820(Obj60* o) {
    NotifyMsg msg;
    int* idField;
    Event_Construct(&msg, &D_00506248);
    idField = &msg.id;
    msg.vtable = &D_004DCF70;
    *idField = -1;
    msg.sender = o;
    *idField = o->id;
    msg.kind = 4;
    msg.size = 0x40;
    Event_Send(&msg, o->target, 0);
    msg.vtable = &D_004DCF10;
    cMessage_dtor(&msg, 0);
}
