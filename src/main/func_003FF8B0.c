#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Obj003FF8B0 { VPAD8(a) virtual void Set(int v); };
typedef struct { int kind; int id; int val; } Pk003FF8B0;
extern "C" {
extern unsigned char D_005721D0;
Obj003FF8B0** NetMap_Lookup(int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_003FF8B0(int a0, int a1, int a2, Pk003FF8B0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk003FF8B0* p = arg;
        Obj003FF8B0** obj = NetMap_Lookup(p->id);
        if (obj) (*obj)->Set(p->val);
    }
    return 0xC;
}
#pragma pop
