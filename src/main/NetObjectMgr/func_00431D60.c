#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int kind; int id; short f8; short fA; } Pk431D60;
extern "C" {
extern unsigned char D_005721D0;
void* Object_LookupById(int*);
void func_0042D790(void*);
void func_0042D910(void*);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_00431D60(int a0, int a1, int a2, Pk431D60* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk431D60* p = arg;
        int id = p->id;
        void* o = Object_LookupById(&id);
        if (o) {
            if (p->fA == 0) func_0042D790(o);
            else func_0042D910(o);
        }
    }
    return 0xC;
}
#pragma pop
