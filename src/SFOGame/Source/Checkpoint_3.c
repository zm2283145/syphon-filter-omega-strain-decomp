/*
 * SFOGame/Source/Checkpoint: 3 files, 0022DBB0-0022DCF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022DBB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_5(char* self) {
    return self + 4;
}

List* std_list_deleter_LosReqElem_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_0022DBB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022DBB0 */

/* merge_units: begin func_0022DBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004DB890[];

struct Msg_0022DBE0 : ClonedMessageBase {
    int a24;
};

extern "C" Msg_0022DBE0* cRespawnMsg_Clone(Msg_0022DBE0* self)
{
    Msg_0022DBE0* p;
    {
        AllocGuard guard;
        p = (Msg_0022DBE0*)cMemMan_Allocate(0, 40, "Checkpoint.hh", 107);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w04 = self->w04;
        p->w08 = self->w08;
        p->w0C = self->w0C;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004DB890;
        p->a24 = self->a24;
    }
    p->w0C = self->w0C;
    return p;
}
static inline void merge_flush_func_0022DBE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022DBE0 */

/* merge_units: begin func_0022DCF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script type registration for cCheckpoint and the checkpoint messages,
 * plus the SetPlayersCheckpoint script native.
 */

#include "Checkpoint_types.h"

/* Script type keys: each class has a key cell and a type id cell. */
extern int D_004F79A0; /* cAddCheckpointMsg key */
extern int D_004F79A8; /* cAddCheckpointMsg type id */
extern int D_004F79B0; /* cNotifyCheckpointMsg key */
extern int D_004F79B8; /* cNotifyCheckpointMsg type id */
extern int D_004F79C0; /* cRespawnMsg key */
extern int D_004F79C8; /* cRespawnMsg type id */
extern int D_004F79D0; /* cCheckpoint key */
extern int D_004F79D8; /* cCheckpoint type id */
extern int Global_SetPlayersCheckpoint(int player, int checkpoint);
extern int* cCheckpoint_SOBJ_getClassId(void);
extern int* cRespawnMsg_SOBJ_getClassId(void);
extern int* cNotifyCheckpointMsg_SOBJ_getClassId(void);
extern int* cAddCheckpointMsg_SOBJ_getClassId(void);

/* cCheckpoint derives from cGObj. */
void cCheckpoint_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79D8, *parent);
}

int* cCheckpoint_SOBJ_getClassId(void) {
    return &D_004F79D0;
}

int cCheckpoint_getSOBJClassId(void) {
    return *cCheckpoint_SOBJ_getClassId();
}

int cCheckpoint_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

/* cRespawnMsg derives from the message base type. */
void cRespawnMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79C8, *parent);
}

int* cRespawnMsg_SOBJ_getClassId(void) {
    return &D_004F79C0;
}

int cRespawnMsg_getSOBJClassId(void) {
    return *cRespawnMsg_SOBJ_getClassId();
}

void cNotifyCheckpointMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79B8, *parent);
}

int* cNotifyCheckpointMsg_SOBJ_getClassId(void) {
    return &D_004F79B0;
}

int cNotifyCheckpointMsg_getSOBJClassId(void) {
    return *cNotifyCheckpointMsg_SOBJ_getClassId();
}

void cAddCheckpointMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79A8, *parent);
}

int* cAddCheckpointMsg_SOBJ_getClassId(void) {
    return &D_004F79A0;
}

int cAddCheckpointMsg_getSOBJClassId(void) {
    return *cAddCheckpointMsg_SOBJ_getClassId();
}

/* SetPlayersCheckpoint(player, checkpoint) */
int Script_SetPlayersCheckpoint(CheckpointScriptArg* args) {
    volatile int checkpoint = args[1].i; /* original stack temporary */
    int player = cGOBJ_SOBJ_convert(args[0].i);
    Global_SetPlayersCheckpoint(player, checkpoint);
    return 0;
}
static inline void merge_flush_func_0022DCF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022DCF0 */
