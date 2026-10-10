#include "types.h"
typedef struct { char pad[0xC]; int marker; } E2GObj;
typedef struct { void* vtbl; char pad04[0x1C]; unsigned char kind; char pad21[3]; int marker; } E2HudMsg;
typedef union { int i; void* p; } E2Arg;
extern E2GObj* GObj_IdentityB(int);
extern unsigned char D_005721C8;
extern char D_0052ACF8[];
extern char D_004DE650[];
extern char* D_004FFC2C;
extern void Event_Construct(E2HudMsg*, void*);
extern void Transport_Send(int, E2HudMsg*, int, int);
extern void cMessage_dtor(E2HudMsg*, int);
extern void ObjMarkerMgr_Remove(void*, int*, int);
int Game_RemoveHudObjectiveInt(E2Arg* args) {
    E2GObj* obj;
    int quiet = args[1].i != 0;
    obj = GObj_IdentityB(args[0].i);
    if (!quiet && D_005721C8) {
        int marker = obj->marker;
        E2HudMsg msg;
        Event_Construct(&msg, D_0052ACF8);
        msg.vtbl = D_004DE650;
        msg.kind = 4;
        msg.marker = marker;
        Transport_Send(0, &msg, -1, -1);
        msg.vtbl = D_004DE650;
        cMessage_dtor(&msg, 0);
    }
    ObjMarkerMgr_Remove(D_004FFC2C + 0x90, &obj->marker, 1);
    return 0;
}