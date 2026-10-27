/*
 * main/game: 3 files, 00274C80-00274EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00274C80 */
#pragma push /* merge_units */
#include "types.h"
typedef struct HudObjMsg_e1 {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int id;
    char pad2[8];
} HudObjMsg_e1;
typedef struct { char pad[0xC]; int id; } GObjId_e1;
extern unsigned char g_IsMultiplayer;
extern char D_0052ACF8[];
extern char D_004DE650[];
extern char* g_Hud;
extern GObjId_e1* cGOBJ_SOBJ_convert(int);
extern void cMessage_ctor_cMessageNameR(HudObjMsg_e1* msg, void* name);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int target, HudObjMsg_e1* msg, int a, int b);
extern void cMessage_dtor(HudObjMsg_e1* msg, int flags);
extern void cHudTargetManager_Remove(void*, int*, int);
int Game_RemoveHudObjective(int* args)
{
    HudObjMsg_e1 msg;
    GObjId_e1* obj = cGOBJ_SOBJ_convert(args[0]);
    if (g_IsMultiplayer) {
        int id = obj->id;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACF8);
        msg.vtable = D_004DE650;
        msg.kind = 4;
        msg.id = id;
        cNetObj_SendMessage_int_cMessageR_int_int(0, &msg, -1, -1);
        msg.vtable = D_004DE650;
        cMessage_dtor(&msg, 0);
    }
    cHudTargetManager_Remove(g_Hud + 0x90, &obj->id, 1);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00274C80 */

/* merge_units: begin func_00274D40 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_274D40;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_274D40;
union HudObjArg_274D40 { int i; char* p; };
extern "C" {
extern char D_0051F098[];
extern char D_004DE280[];
extern char D_004A8F80[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HudObjMsg_274D40* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_274D40* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, HudObjMsg_274D40*, int, int);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) (cNetObj_SendMessage_int_cMessageR_int_int((a0), (HudObjMsg_e1 *)(a1), (a2), (a3))) /* merge_units */

extern char* nGlobalization_GetString_charP(char*);
extern int nGlobalization_GetStringIndex(char*);
extern void printf(char*);
#if 0 /* merge_units */
extern HudObjGObj_274D40* cGOBJ_SOBJ_convert(int);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((HudObjGObj_274D40 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

extern void cHudTargetManager_AddObjective_cObjectIdR_charP_charP(void*, int*, char*, char*);
}
/* the script args are read through unions; with propagation off they stay in stack slots and are reloaded once into saved registers */
extern "C" int Game_AddHudObjective3(int* args)
{
    HudObjArg_274D40 ub; ub.i = args[2];
    HudObjArg_274D40 ua; ua.i = args[1];
    int marker;
    HudObjGObj_274D40* obj;
    char* text;
    HudObjMsg_274D40* p;
    char* b;
    char* a;
    a = ua.p;
    b = ub.p;
    obj = cGOBJ_SOBJ_convert(args[0]);
    text = nGlobalization_GetString_charP(a);
    if (!text || !*text) {
        printf(D_004A8F80);
    } else {
        if (g_IsMultiplayer) {
            HudObjMsg_274D40 m;
            marker = obj->marker;
            p = &m;
            cMessage_ctor_cMessageNameR(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? nGlobalization_GetStringIndex(a) : -1;
            p->key1 = b ? nGlobalization_GetStringIndex(b) : -1;
            m.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        cHudTargetManager_AddObjective_cObjectIdR_charP_charP(g_Hud + 0x90, &obj->marker, text, b);
    }
    return 0;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274D40 */

/* merge_units: begin func_00274EC0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_274EC0;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_274EC0;
union HudObjArg_274EC0 { int i; char* p; };
extern "C" {
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HudObjMsg_274EC0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_274EC0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, HudObjMsg_274EC0*, int, int);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) (cNetObj_SendMessage_int_cMessageR_int_int((a0), (HudObjMsg_e1 *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern HudObjGObj_274EC0* cGOBJ_SOBJ_convert(int);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((HudObjGObj_274EC0 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

}
/* the script args are read through unions; with propagation off they stay in stack slots and are reloaded once into saved registers */
extern "C" int Game_AddHudObjective2(int* args)
{
    HudObjArg_274EC0 ua; ua.i = args[1];
    HudObjGObj_274EC0* obj;
    char* text;
    HudObjMsg_274EC0* p;
    int marker;
    char* const b = 0;
    char* a;
    a = ua.p;
    obj = cGOBJ_SOBJ_convert(args[0]);
    text = nGlobalization_GetString_charP(a);
    if (!text || !*text) {
        printf(D_004A8F80);
    } else {
        if (g_IsMultiplayer) {
            HudObjMsg_274EC0 m;
            marker = obj->marker;
            p = &m;
            cMessage_ctor_cMessageNameR(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? nGlobalization_GetStringIndex(a) : -1;
            p->key1 = b ? nGlobalization_GetStringIndex(b) : -1;
            m.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        cHudTargetManager_AddObjective_cObjectIdR_charP_charP(g_Hud + 0x90, &obj->marker, text, b);
    }
    return 0;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274EC0 */
