#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Ctl5B80 {
public:
    VPAD8(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual int isActive();          /* slot 15 */
    VPAD16(t)
    virtual unsigned char kind();    /* slot 32 */
};
struct Obj5B80 { char pad[0x58]; Ctl5B80* ctl; };
struct Src5B80 { int a; int b; int id; };
struct Msg5B80 { void* vtable; char pad[0x2C]; char payload[0x2E0]; };
extern "C" {
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_004DE110[];
void cNetCopyMsg_ctor(Msg5B80* m, Src5B80* src);
Obj5B80* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void cNetNPC_ConvertToNpc(Ctl5B80* c, void* payload);
void func_0042CE10(int* id);
void cMessage_dtor(void* self, int flags);
}
extern "C" int cNetCopyMsg_CopyMsgCallback(int a, int b, int c, Src5B80* src)
{
    if (!D_005723C8)
        D_005723C8 = 1;
    if (D_005721D0) {
        Msg5B80 m;
        int id[2];
        Obj5B80* o;
        id[0] = src->id;
        cNetCopyMsg_ctor(&m, src);
        o = nGobjManager_LookupGOBJ_cObjectIdR(id);
        if (o && o->ctl && o->ctl->isActive() && o->ctl->kind() == 2)
            cNetNPC_ConvertToNpc(o->ctl, m.payload);
        func_0042CE10(id);
        m.vtable = D_004DE110;
        cMessage_dtor(&m, 0);
    }
    D_005723C8 = 0;
    return 0x2F0;
}