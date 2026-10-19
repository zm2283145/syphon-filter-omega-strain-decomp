/*
 * main/Loader: 4 files, 001C5710-001C5950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C5710 */
#pragma push /* merge_units */
#include "types.h"
#include "event_toggle_send.h"

/* Post the "on" event and set the state flag. */
DEFINE_EVENT_TOGGLE_SEND(ParticleGob_Enable, g_cEnableMsgClass, D_004E0880, func_003FF930, 1)
#pragma pop /* merge_units */
/* merge_units: end func_001C5710 */

/* merge_units: begin func_001C57A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; int f60; } G1C5;
typedef struct { void* vt; char pad[0x1C]; unsigned char b20; char pad2[0x19F]; } M1C5;
typedef struct { char pad[0x190]; } R1C5;
extern void cPARTICLE_GOBJ_v10(G1C5*);
extern int func_00394170(G1C5*);
extern int func_00394140(G1C5*, int*);
extern int* SpecFx_GetEffectDef(int);
extern int g_VideoFrameCounter;
extern void SoundRequest_Ctor(R1C5*, int, char*, int, int);
extern void SoundPosRequest_Ctor(M1C5*, R1C5*, int*);
extern void Event_Send(M1C5*, char*, int);
extern char g_Game[];
extern char D_004DAE30[];
extern void FileMan_Release(void*, int);
#if 0 /* merge_units */
extern void cMessage_dtor(M1C5*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((ToggleEventMsg *)(a0), (a1))) /* merge_units */

void ParticleGob_Update(G1C5* g) {
    int x[4];
    R1C5 req;
    M1C5 msg;
    cPARTICLE_GOBJ_v10(g);
    if (!func_00394170(g)) return;
    if ((unsigned char)func_00394140(g, x) != 1) return;
    if (g->f60 != *SpecFx_GetEffectDef(9)) return;
    if (g_VideoFrameCounter & 7) return;
    SoundRequest_Ctor(&req, 0, "O_GLASS_BREAK_S", 0, 0);
    SoundPosRequest_Ctor(&msg, &req, x);
    msg.b20 = 1;
    Event_Send(&msg, g_Game, 0);
    msg.vt = D_004DAE30;
    FileMan_Release((char*)&msg + 0x114, -1);
    FileMan_Release((char*)&msg + 0x78, -1);
    cMessage_dtor(&msg, 0);
    FileMan_Release((char*)&req + 0xE4, -1);
    FileMan_Release((char*)&req + 0x48, -1);
}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C57A0 */

/* merge_units: begin func_001C58A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "gobj_flag_dtor.h"
DEFINE_GOBJ_FLAG_DTOR(cPARTICLE_GOBJ_dtor, D_004DF860)
#pragma pop /* merge_units */
/* merge_units: end func_001C58A0 */

/* merge_units: begin func_001C5950 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern char D_004DAA10[]; /* vtable of the derived object */
extern char D_004DF860[]; /* vtable of its intermediate base */
extern cGOBJ* cGOBJ_ctor(cGOBJ* self, int* desc, int a2, int* a3);

/* Constructor of a cGOBJ-derived object (two inlined constructor levels). */
UnkGobj001C5950* ParticleGob_Create(UnkGobj001C5950* self, int* desc, int value) {
    int zero[1];

    zero[0] = 0;
    cGOBJ_ctor(&self->base, desc, 4, zero);
    self->base.vtable = D_004DF860;
    self->unk60 = value;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unk70 = 1.0f;
    self->base.unk2F = 1;
    self->base.vtable = D_004DAA10;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C5950 */
