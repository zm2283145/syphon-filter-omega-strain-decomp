#include "types.h"
typedef struct { char pad[0xC]; int marker; } E2GObj;
typedef struct { void* vtbl; char pad04[0x1C]; unsigned char kind; char pad21[3]; int marker; } E2HudMsg;
typedef union { int i; void* p; } E2Arg;
extern E2GObj* cGOBJ_SOBJ_convert(int);
extern unsigned char g_IsMultiplayer;
extern char D_0052ACF8[];
extern void cMessage_getSOBJClassId();
extern void cNetRemoveHudObjectiveMsg_dtor();
extern void cNetRemoveHudObjectiveMsg_Clone();
extern void cNetRemoveHudObjectiveMsg_Pack();
void * const D_004DE650[8] = { (void*)0x0, (void*)0x0, (void*)cNetRemoveHudObjectiveMsg_dtor, (void*)cNetRemoveHudObjectiveMsg_Clone, (void*)cNetRemoveHudObjectiveMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern char* g_Hud;
extern void cMessage_ctor_cMessageNameR(E2HudMsg*, void*);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, E2HudMsg*, int, int);
extern void cMessage_dtor(E2HudMsg*, int);
extern void cHudTargetManager_Remove(void*, int*, int);
int Game_RemoveHudObjectiveInt(E2Arg* args) {
    E2GObj* obj;
    int quiet = args[1].i != 0;
    obj = cGOBJ_SOBJ_convert(args[0].i);
    if (!quiet && g_IsMultiplayer) {
        int marker = obj->marker;
        E2HudMsg msg;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACF8);
        msg.vtbl = ((char*)D_004DE650);
        msg.kind = 4;
        msg.marker = marker;
        cNetObj_SendMessage_int_cMessageR_int_int(0, &msg, -1, -1);
        msg.vtbl = ((char*)D_004DE650);
        cMessage_dtor(&msg, 0);
    }
    cHudTargetManager_Remove(g_Hud + 0x90, &obj->marker, 1);
    return 0;
}