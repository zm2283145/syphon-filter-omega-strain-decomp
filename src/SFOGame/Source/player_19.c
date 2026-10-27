/*
 * SFOGame/Source/player: 5 files, 00177A90-00177C00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00177A90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define std_list_deleter_voidPtr_erase_listdeleter_listdeleter std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter
#include "obj_list_dtor_mid.h"

DEFINE_OBJ_LIST_DTOR_MID(std_list_imp_cSafePtr_cGOBJ_dtor)
static inline void merge_flush_func_00177A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177A90 */

/* merge_units: begin func_00177B10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "player_types.h"

extern void cGameGobjController_ctor(void* self);
extern char D_004D9CF0[];  /* player component class table */
extern void cPlayerControls_ctor(PlayerInputState* input);

PlayerComponent* cPlayer_ctor(PlayerComponent* self) {
    cGameGobjController_ctor(self);
    self->vtable = D_004D9CF0;
    cPlayerControls_ctor(&self->input);
    self->unk1A0 = 0;
    self->unk1C0 = 0;
    self->unk1B4 = 0;
    self->unk1B0 = 0;
    self->unk1A8 = 0.0f;
    self->unk1AC = 0.0f;
    self->unk1BC = 0;
    self->unk1B8 = -1;
    self->unk1A4 = 0;
    return self;
}
static inline void merge_flush_func_00177B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177B10 */

/* merge_units: begin func_00177B80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "obj_list_dtor.h"

DEFINE_OBJ_LIST_DTOR(std_list_cSafePtr_cGOBJ_dtor)
static inline void merge_flush_func_00177B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177B80 */

/* merge_units: begin func_00177C00 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

#pragma cplusplus on
DEFINE_VT8_CHAIN_DTOR(cPlayerRespawnCB_dtor, D_004D9DC0, D_004D9DE0)
static inline void merge_flush_func_00177C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177C00 */

/* merge_units: begin func_00177C60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_7C60 { void* vt; char pad[0x18]; int size; char pad20[4]; int target; char pad28[8]; };
struct Q_7C60 { int type; unsigned char a; unsigned char b; char pad6[2]; void* vt; void* obj; };
struct O_7C60 { char pad[0x30]; void* recv; };
struct S_7C60 { char pad[0xC]; O_7C60* obj; };
struct G_7C60 { int pad0; float t; };
extern "C" {
extern G_7C60* g_Fader;
extern char D_004F7940[];
extern char D_004DB890[];
extern char D_004D9DE0[];
extern char D_004D9DC0[];
void cMessage_ctor_cMessageNameR(Ev_7C60* e, void* type);
void QueueMessage_cMessageR_cSystemP_int(Ev_7C60* e, void* target, int a);
void cMessage_dtor(Ev_7C60* e, int f);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nCallback_SetCallback(Q_7C60* q);
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
}
static inline void Init_7C60(Q_7C60* q, O_7C60* obj)
{
    q->vt = D_004D9DE0;
    q->a = 1;
    q->type = 0xF;
    q->b = 0;
    q->vt = D_004D9DC0;
    q->obj = obj;
}
extern "C" void cPlayerRespawnCB_Call(S_7C60* self)
{
    Q_7C60* q;
    if (g_Fader->t == 0.0f) {
        Ev_7C60 e;
        cMessage_ctor_cMessageNameR(&e, D_004F7940);
        e.target = 0;
        e.vt = D_004DB890;
        e.size = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&e, self->obj->recv, 0);
        e.vt = D_004DB890;
        cMessage_dtor(&e, 0);
        return;
    }
    if (g_ProfileLockEnabled)
        Alloc_Lock(9);
    g_ProfileLockDepth++;
    q = (Q_7C60*)cMemMan_Allocate(0, 0x10, "player.cc", 0x1AA);
    if (g_ProfileLockEnabled)
        EnableIntc(9);
    g_ProfileLockDepth--;
    if (q)
        Init_7C60(q, self->obj);
    nCallback_SetCallback(q);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00177C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00177C60 */
