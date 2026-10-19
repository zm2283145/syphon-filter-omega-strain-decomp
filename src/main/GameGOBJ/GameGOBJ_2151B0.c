/*
 * main/GameGOBJ: range (2 files, 002151B0-002151C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_002151B0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */


int* func_002151B0(PtrVec* v, int i) {
    return v->data + i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002151B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002151B0 */

/* merge_units: begin func_002151C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Door: only the slots used here are named (vtable offset in comments). */
struct Door {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Method60(int flag); /* +0x60 */
};

typedef struct cElevatorGOBJ_002151C0 {
    char pad[0x64];
    Door* door; /* +0x64 */
    char pad68[0x2E0 - 0x68];
    int floors; /* +0x2E0 */
} cElevatorGOBJ_002151C0;

/* Elevator notification message built on the stack (0x1D0 bytes); its destructor is inlined. */
typedef struct ElevatorMsg {
    void* vtable;           /* +0x000 */
    char pad004[0x78 - 4];
    char memberA[0x114 - 0x78]; /* +0x078 */
    char memberB[0x1D0 - 0x114]; /* +0x114 */
} ElevatorMsg;

extern char g_Game[];
extern char D_004DADF0[];
extern char g_TargetVisMgr[];
extern "C" void SoundStopMsg_Ctor(ElevatorMsg* msg, int* floors, cElevatorGOBJ_002151C0* self);
extern "C" void Event_Send(ElevatorMsg* msg, void* queue, int flag);
extern "C" void FileMan_Release(void* member, int flag);
extern "C" void cMessage_dtor(ElevatorMsg* msg, int flag);
extern "C" void TargetVis_Unregister(void* list, cElevatorGOBJ_002151C0* obj);
extern "C" void func_003CE7D0(cElevatorGOBJ_002151C0* self);

/* Lift virtual 0x07: posts an elevator message, notifies the door (virtual +0x60), runs the base handler and unregisters. */
extern "C" void cElevatorGOBJ_v07(cElevatorGOBJ_002151C0* self)
{
    ElevatorMsg msg;
    SoundStopMsg_Ctor(&msg, &self->floors, self);
    Event_Send(&msg, g_Game, 1);
    /* ~ElevatorMsg() */
    msg.vtable = D_004DADF0;
    FileMan_Release(msg.memberB, -1);
    FileMan_Release(msg.memberA, -1);
    cMessage_dtor(&msg, 0);
    if (self->door)
        self->door->Method60(1);
    func_003CE7D0(self);
    TargetVis_Unregister(g_TargetVisMgr, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002151C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002151C0 */
