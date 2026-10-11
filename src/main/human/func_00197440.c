#include "types.h"
typedef struct { void* vtable; char base[0x20]; int id; char pad28[8]; Q pos; } Msg_197440;
extern char D_004EEED0[];
extern char D_004DA8D0[];
extern char D_004DCF10[];
extern void Event_Construct(Msg_197440* msg, void* name);
extern void cMessage_dtor(Msg_197440* msg, int flags);
extern void Script_ReadU32(int* out);
extern void func_00197500(Q* out);
extern void* func_00185080(void);
extern int func_00185060(void* self, void* key);
extern void func_00197140(void* self, int* id, Q* pos);
void func_00197440(void* self)
{
    Msg_197440 msg;
    int* ip;
    Q* qp;
    Event_Construct(&msg, D_004EEED0);
    msg.vtable = D_004DA8D0;
    ip = &msg.id;
    *ip = -1;
    Script_ReadU32(ip);
    qp = &msg.pos;
    func_00197500(qp);
    if (self && func_00185060(self, func_00185080())) func_00197140(self, ip, qp);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}