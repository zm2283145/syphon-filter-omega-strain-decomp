#include "types.h"
typedef struct {
    void* vtable;
    char base[0x18];
    int flags;      /* 0x1C */
    int pad20;
    int target;     /* 0x24 */
    unsigned char b28;
} ObjActMsg_e8;
typedef struct { char pad[0x10]; int id; char pad14[0x11]; unsigned char active; } ObjAct_e8;
extern unsigned char D_005721C8;
extern unsigned char D_005721D0;
extern char D_00572188[];
extern char D_004E0E60[];
extern void Event_Construct(ObjActMsg_e8* msg, void* name);
extern void func_00428FD0(ObjActMsg_e8* msg, int id);
extern void cMessage_dtor(ObjActMsg_e8* msg, int flags);
void Objective_Activate(ObjAct_e8* self)
{
    self->active = 1;
    if (D_005721C8 && D_005721D0) {
        ObjActMsg_e8 msg;
        Event_Construct(&msg, D_00572188);
        msg.vtable = D_004E0E60;
        msg.b28 = 0;
        msg.target = -1;
        msg.flags = 0x40;
        func_00428FD0(&msg, self->id);
        msg.vtable = D_004E0E60;
        cMessage_dtor(&msg, 0);
    }
}