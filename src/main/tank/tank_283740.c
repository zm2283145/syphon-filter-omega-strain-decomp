/*
 * main/tank: range (3 files, 00283740-002838B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "tank_types.h"

/* merge_units: begin func_00283740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern int D_00506278;   /* cTank class type id */
extern int D_00506280;   /* cTank script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cTank script type under its parent type. */
void ScriptType_cTank_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_00506280, *parent);
}

/* Identity casts; volatile mirrors the original stack temporary. */
int func_00283770(int obj) {
    volatile int tmp = obj;
    return tmp;
}

int func_00283790(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* func_002837B0(void* self) {
    return self;
}

void* func_002837C0(void* self) {
    return self;
}

int* func_002837D0(void) {
    return &D_00506278;
}

int* func_002837E0(void) {
    return &D_00506278;
}

int cTank_v0B(void) {
    return D_00506278;
}

int cTank_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283740 */

/* merge_units: begin func_00283820 */
#pragma push /* merge_units */
typedef struct Obj60 {
    char pad[0xC];
    int id;
    char pad2[0x50];
    void* target;
} Obj60;

/* Small notification message built on the stack. */
typedef struct NotifyMsg {
    void* vtable;
    char pad04[0x18];
    int size;           /* 0x1C */
    unsigned char kind; /* 0x20 */
    char pad21[3];
    Obj60* sender;      /* 0x24 */
    int id;             /* 0x28 */
    int pad2C;
} NotifyMsg;

extern int g_NetCreateTankMsgKey;
extern int cNetCreateTankMsg_vtable;
extern int D_004DCF10;
extern void Event_Construct(NotifyMsg*, void*);
extern void Event_Send(NotifyMsg*, void*, int);
extern void cMessage_dtor(NotifyMsg*, int);

/* Sends a notification message (kind 4) about this object to its target. */
void func_00283820(Obj60* o) {
    NotifyMsg msg;
    int* idField;
    Event_Construct(&msg, &g_NetCreateTankMsgKey);
    idField = &msg.id;
    msg.vtable = &cNetCreateTankMsg_vtable;
    *idField = -1;
    msg.sender = o;
    *idField = o->id;
    msg.kind = 4;
    msg.size = 0x40;
    Event_Send(&msg, o->target, 0);
    msg.vtable = &D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00283820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00283820 */

/* merge_units: begin func_002838B0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x2C]; } Msg;
extern char D_00506260[];
extern char D_004DCF50[];
#if 0 /* merge_units */
extern char D_004DCF10[];
#endif /* merge_units */
#define D_004DCF10 ((char*)&D_004DCF10) /* merge_units */

#if 0 /* merge_units */
extern void Event_Construct(Msg* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern void func_00283910(Msg* m, void* target);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

/* Builds a temporary message, sends it to target, then destroys it. */
void func_002838B0(void* target)
{
    Msg msg;
    Event_Construct(&msg, D_00506260);
    msg.vtable = D_004DCF50;
    func_00283910(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
#undef D_004DCF10 /* merge_units */
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002838B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002838B0 */
