/*
 * SFOGame/Source/hudTargets: 3 files, 00274A60-00274B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00274A60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct O274A60 { char p[0xC]; int id; char pad[0x6C - 0x10]; int f6C; };
struct H274A60 { int type; O274A60* p; int id; };
struct W274A60 { char pad[0x10]; H274A60 h; char str[4]; };
extern "C" int std_basic_string_char_char_traits_char_c_str(void*);
static inline O274A60* Get274A60(H274A60* h) {
    bool isNull;
    bool ok;
    O274A60* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
static inline O274A60* Deref274A60(H274A60* h) {
    bool isNull;
    O274A60* t;
    t = h->p;
    isNull = !t;
    return (isNull || t->id == h->id) ? t : 0;
}
extern "C" int cHudTargetInfo_GetObjectiveString(W274A60* w)
{
    if (w->h.type == 1) {
        if (Get274A60(&w->h)) return Deref274A60(&w->h)->f6C;
    } else if (w->h.type == 2) {
        return std_basic_string_char_char_traits_char_c_str(w->str);
    }
    return 0;
}
static inline void merge_flush_func_00274A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274A60 */

/* merge_units: begin func_00274B20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "hudTargets_types.h"

/* Clears a fresh marker record. */
ObjMarkerRecord* cHudTargetInfo_ctor(ObjMarkerRecord* self) {
    self->id = 0;
    self->icon0 = 0;
    self->icon1 = 0;
    self->unk0C = 0;
    self->unk18 = -2;
    self->unk14 = 0;
    self->text = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->text2 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    return self;
}
static inline void merge_flush_func_00274B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274B20 */

/* merge_units: begin game_274B60 */
#pragma push /* merge_units */
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
static inline void merge_flush_game_274B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_274B60 */
