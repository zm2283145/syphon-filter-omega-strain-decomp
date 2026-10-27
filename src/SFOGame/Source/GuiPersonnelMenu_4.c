/*
 * SFOGame/Source/GuiPersonnelMenu: 5 files, 003550B0-00355200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003550B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "member_dtor_chain.h"

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_003550B0, func_00299360)
static inline void merge_flush_func_003550B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003550B0 */

/* merge_units: begin func_00355120 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00355120, func_00299360)
static inline void merge_flush_func_00355120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355120 */

/* merge_units: begin func_00355180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_00355180(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00355180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355180 */

/* merge_units: begin func_003551A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_003551A0, func_00299360)
static inline void merge_flush_func_003551A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003551A0 */

/* merge_units: begin func_00355200 */
#pragma push /* merge_units */
/* Event message built on the stack (C++ object with inlined destructor). */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x1C];
    unsigned char immediate;    /* 0x20 */
    char pad21[0x57];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;

typedef struct ObjF4 {
    char pad[0xB0];
    char target[0x44];
    unsigned char pending;      /* 0xF4 */
} ObjF4;

extern int g_Game;
extern int D_004DADF0;
extern void cStopSoundMsg_ctor_cSndFxR_bool(EventMsg*, void*, int);
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg*, void*, int);
extern void cFileMan_dtor(void*, int);
extern void cMessage_dtor(EventMsg*, int);

/* Clears the pending flag and sends an immediate event message for the target. */
void GuiPersonnelMenu_StopPlayback(ObjF4* o) {
    EventMsg msg;
    o->pending = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&msg, o->target, 0);
    msg.immediate = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, &g_Game, 1);
    msg.vtable = &D_004DADF0;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_00355200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00355200 */
