#include "types.h"

typedef struct Widget {
    char pad[0x14];
    unsigned short flags;
} Widget;

typedef struct ObjF0 {
    char pad[0xE0];
    Widget* widget;
    char padE4[4];
    int handle;     /* 0xE8 */
    void* target;   /* 0xEC */
    void* owner;    /* 0xF0 */
} ObjF0;

/* Notification message built on the stack. */
typedef struct NotifyMsg {
    void* vtable;
    char pad04[0x20];
    void* owner;    /* 0x24 */
    int code;       /* 0x28 */
    char pad2C[4];
} NotifyMsg;

extern int D_004F7E48;
extern int D_004DC330;
extern void func_00421070(int);
extern void Event_Construct(NotifyMsg*, void*);
extern void Event_Send(NotifyMsg*, void*, int);
extern void cMessage_dtor(NotifyMsg*, int);
extern void func_0045DE40(ObjF0*);

/* Closes the attached widget, notifies the owner (code -255) and detaches. */
void func_0045BF80(ObjF0* o) {
    void* owner;
    NotifyMsg msg;
    if (o->widget == 0) return;
    o->widget->flags &= ~2;
    func_00421070(o->handle);
    owner = o->owner;
    if (owner != 0) {
        Event_Construct(&msg, &D_004F7E48);
        msg.owner = owner;
        msg.vtable = &D_004DC330;
        msg.code = -0xFF;
        Event_Send(&msg, o->target, 0);
        msg.vtable = &D_004DC330;
        cMessage_dtor(&msg, 0);
    }
    o->target = 0;
    o->owner = 0;
    func_0045DE40(o);
}
