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
DEFINE_EVENT_TOGGLE_SEND(cGameParticle_Enable, g_cEnableMsgClass, D_004E0880, cEnableMsg_SendEnabled, 1)
#pragma pop /* merge_units */
/* merge_units: end func_001C5710 */

/* merge_units: begin func_001C57A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; int f60; } G1C5;
typedef struct { void* vt; char pad[0x1C]; unsigned char b20; char pad2[0x19F]; } M1C5;
typedef struct { char pad[0x190]; } R1C5;
extern void cPARTICLE_GOBJ_NextFrame(G1C5*);
extern int cPARTICLE_GOBJ_EventHappened(G1C5*);
extern int cPARTICLE_GOBJ_GetEvent(G1C5*, int*);
extern int* nSfxLoader_GetHandle(int);
extern int g_VideoFrameCounter;
extern void cSndFx_ctor_int_charP_cGOBJP_int(R1C5*, int, char*, int, int);
extern void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(M1C5*, R1C5*, int*);
extern void QueueMessage_cMessageR_cSystemP_int(M1C5*, char*, int);
extern char g_Game[];
extern char D_004DAE30[];
extern void cFileMan_dtor(void*, int);
#if 0 /* merge_units */
extern void cMessage_dtor(M1C5*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((ToggleEventMsg *)(a0), (a1))) /* merge_units */

void cGameParticle_NextFrame(G1C5* g) {
    int x[4];
    R1C5 req;
    M1C5 msg;
    cPARTICLE_GOBJ_NextFrame(g);
    if (!cPARTICLE_GOBJ_EventHappened(g)) return;
    if ((unsigned char)cPARTICLE_GOBJ_GetEvent(g, x) != 1) return;
    if (g->f60 != *nSfxLoader_GetHandle(9)) return;
    if (g_VideoFrameCounter & 7) return;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, "O_GLASS_BREAK_S", 0, 0);
    cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, x);
    msg.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    msg.vt = D_004DAE30;
    cFileMan_dtor((char*)&msg + 0x114, -1);
    cFileMan_dtor((char*)&msg + 0x78, -1);
    cMessage_dtor(&msg, 0);
    cFileMan_dtor((char*)&req + 0xE4, -1);
    cFileMan_dtor((char*)&req + 0x48, -1);
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
UnkGobj001C5950* cGameParticle_ctor_cObjectIdR_int(UnkGobj001C5950* self, int* desc, int value) {
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
