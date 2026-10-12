#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Obj428EF0 { VPAD4(a) VPAD2(b) virtual void Reset(); char pad[0xC]; void* f10; unsigned char f14; };
typedef struct { int kind; int id; int val; } Pk428EF0;
extern "C" {
extern unsigned char D_005721D0;
Obj428EF0** NetMap_Lookup(int);
void* Object_LookupById(int*);
void func_003FB4B0(void*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_00428EF0(int a0, int a1, int a2, Pk428EF0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk428EF0* p = arg;
        Obj428EF0** e = NetMap_Lookup(p->id);
        Obj428EF0* o;
        if (!e) { int id = p->id; o = (Obj428EF0*)Object_LookupById(&id); } else o = *e;
        if (o) {
            if (p->val > -1) { o->Reset(); func_003FB4B0(o->f10, p->val); o->f14 = 0; } else o->Reset();
        }
    }
    return 0x10;
}
#pragma pop
