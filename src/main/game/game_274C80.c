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
extern unsigned char D_005721C8;
extern char D_0052ACF8[];
extern char D_004DE650[];
extern char* D_004FFC2C;
extern GObjId_e1* GObj_IdentityB(int);
extern void Event_Construct(HudObjMsg_e1* msg, void* name);
extern void Transport_Send(int target, HudObjMsg_e1* msg, int a, int b);
extern void cMessage_dtor(HudObjMsg_e1* msg, int flags);
extern void ObjMarkerMgr_Remove(void*, int*, int);
int Game_RemoveHudObjective(int* args)
{
    HudObjMsg_e1 msg;
    GObjId_e1* obj = GObj_IdentityB(args[0]);
    if (D_005721C8) {
        int id = obj->id;
        Event_Construct(&msg, D_0052ACF8);
        msg.vtable = D_004DE650;
        msg.kind = 4;
        msg.id = id;
        Transport_Send(0, &msg, -1, -1);
        msg.vtable = D_004DE650;
        cMessage_dtor(&msg, 0);
    }
    ObjMarkerMgr_Remove(D_004FFC2C + 0x90, &obj->id, 1);
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
extern void Event_Construct(HudObjMsg_274D40* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_274D40* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Transport_Send(int, HudObjMsg_274D40*, int, int);
#endif /* merge_units */
#define Transport_Send(a0, a1, a2, a3) (Transport_Send((a0), (HudObjMsg_e1 *)(a1), (a2), (a3))) /* merge_units */

extern char* Loc_LookupText(char*);
extern int Loc_FindKeyThunk(char*);
extern void printf(char*);
#if 0 /* merge_units */
extern HudObjGObj_274D40* GObj_IdentityB(int);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((HudObjGObj_274D40 *)GObj_IdentityB((a0))) /* merge_units */

extern void ObjMarkerMgr_Insert(void*, int*, char*, char*);
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
    obj = GObj_IdentityB(args[0]);
    text = Loc_LookupText(a);
    if (!text || !*text) {
        printf(D_004A8F80);
    } else {
        if (D_005721C8) {
            HudObjMsg_274D40 m;
            marker = obj->marker;
            p = &m;
            Event_Construct(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? Loc_FindKeyThunk(a) : -1;
            p->key1 = b ? Loc_FindKeyThunk(b) : -1;
            m.kind = 4;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        ObjMarkerMgr_Insert(D_004FFC2C + 0x90, &obj->marker, text, b);
    }
    return 0;
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef Transport_Send /* merge_units */
#undef GObj_IdentityB /* merge_units */
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
extern void Event_Construct(HudObjMsg_274EC0* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_274EC0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((HudObjMsg_e1 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Transport_Send(int, HudObjMsg_274EC0*, int, int);
#endif /* merge_units */
#define Transport_Send(a0, a1, a2, a3) (Transport_Send((a0), (HudObjMsg_e1 *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern HudObjGObj_274EC0* GObj_IdentityB(int);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((HudObjGObj_274EC0 *)GObj_IdentityB((a0))) /* merge_units */

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
    obj = GObj_IdentityB(args[0]);
    text = Loc_LookupText(a);
    if (!text || !*text) {
        printf(D_004A8F80);
    } else {
        if (D_005721C8) {
            HudObjMsg_274EC0 m;
            marker = obj->marker;
            p = &m;
            Event_Construct(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? Loc_FindKeyThunk(a) : -1;
            p->key1 = b ? Loc_FindKeyThunk(b) : -1;
            m.kind = 4;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        ObjMarkerMgr_Insert(D_004FFC2C + 0x90, &obj->marker, text, b);
    }
    return 0;
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef Transport_Send /* merge_units */
#undef GObj_IdentityB /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274EC0 */
