#pragma cplusplus on
#include "types.h"
extern "C" {
int NetRegisterMessageStart(...);
int NetMessageField(...);
int NetRegisterApplicationMessage(...);
int Event_UnpackHeader(...);
extern int D_0055D488;
extern char D_0055D490;
void cCharActionMsg_NetCharActionReq();
}
extern "C" bool cCharActionMsg_InitNet(void) {
    struct { int a[2]; char b; char c; } sl;
    bool ok = 0;
    if (NetRegisterMessageStart() == 0) {
        bool r = 0;
        if (Event_UnpackHeader(sl.a) != 0 && NetMessageField(sl.a, &sl.b, 1, 1) == 0 && NetMessageField(sl.a, &sl.c, 1, 1) == 0) {
            r = 1;
            D_0055D488 = 0;
        }
        if (r && NetRegisterApplicationMessage(&D_0055D490, cCharActionMsg_NetCharActionReq) == 0) ok = 1;
    }
    return ok;
}
