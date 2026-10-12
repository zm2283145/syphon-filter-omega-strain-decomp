#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int kind; int id; int floor; unsigned char lock; } Pk2115E0;
extern "C" {
extern unsigned char D_005721D0;
void** NetMap_Lookup(int);
void cElevatorGOBJ_LockFloor(void*, int, int);
void cElevatorGOBJ_UnlockFloor(void*, int, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_002115E0(int a0, int a1, int a2, Pk2115E0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk2115E0* p = arg;
        void** obj = NetMap_Lookup(p->id);
        if (obj) {
            if (p->lock) cElevatorGOBJ_LockFloor(*obj, p->floor, 1);
            else cElevatorGOBJ_UnlockFloor(*obj, p->floor, 1);
        }
    }
    return 0x10;
}
#pragma pop
