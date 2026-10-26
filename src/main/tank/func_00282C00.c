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

extern int g_NetCreateTankMsgKey;
extern void Message_GetScriptTypeKey();
extern void cNetCreateTankMsg_dtor();
extern void cNetCreateTankMsg_v01();
extern void cNetCreateTankMsg_v04();
extern void cNetCreateTankMsg_v05();
extern void cNetMsg_Pack();
void * const cNetCreateTankMsg_vtable[8] = { (void*)0x0, (void*)0x0, (void*)cNetCreateTankMsg_dtor, (void*)cNetCreateTankMsg_v01, (void*)cNetMsg_Pack, (void*)Message_GetScriptTypeKey, (void*)cNetCreateTankMsg_v04, (void*)cNetCreateTankMsg_v05 };
extern int D_004DCF10;
extern void Event_Construct(NotifyMsg*, void*);
extern void Event_Send(NotifyMsg*, void*, int);
extern void cMessage_dtor(NotifyMsg*, int);

/* Sends a notification message (kind 4) about this object to its target. */
int Script_cTank_NetCreate(Obj60** args) {
    Obj60* o = *args;
    NotifyMsg msg;
    int* idField;
    Event_Construct(&msg, &g_NetCreateTankMsgKey);
    idField = &msg.id;
    msg.vtable = &(*(int*)cNetCreateTankMsg_vtable);
    *idField = -1;
    msg.sender = o;
    *idField = o->id;
    msg.kind = 4;
    msg.size = 0x40;
    Event_Send(&msg, o->target, 0);
    msg.vtable = &D_004DCF10;
    cMessage_dtor(&msg, 0);
    return 0;
}
