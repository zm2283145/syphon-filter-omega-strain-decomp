/*
 * SFOGame/Source/GameGOBJ: 11 files, 00211000-00211540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00211000 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cElevatorGOBJ (lift) script natives and script type registration.
 * "volatile" locals mirror the original stack temporaries.
 */

#include "gobj_types.h"

extern int D_004F54F0;   /* cPathedGOBJ script-type value */
extern int D_004F5540;   /* cElevatorGOBJ script-type value */
extern int D_004F5548;   /* cElevatorGOBJ script-type key */
extern int D_004F5610;   /* cElevatorNotice script-type value */
extern char D_00555070[];
extern unsigned char cElevatorGOBJ_CloseDoors(cElevatorGOBJ* lift);
extern unsigned char cElevatorGOBJ_OpenDoors(cElevatorGOBJ* lift);
extern int cElevatorGOBJ_SeekFloor(cElevatorGOBJ* lift, int floor, int a2, int a3);
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int cElevatorGOBJ_ChooseFloor(cElevatorGOBJ* lift);
extern unsigned char cElevatorGOBJ_GetState(cElevatorGOBJ* lift);
extern int cScriptBase_declareMsgUse(int type, int iface);
extern void cScriptBase_declareParent(int type, int base);

int Script_cElevatorGOBJ_ChooseFloor(ScriptArg* args) {
    cElevatorGOBJ_ChooseFloor(args[0].p);
    return 0;
}

int Script_cElevatorGOBJ_GetCurrentFloor(ScriptArg* args) {
    volatile int floor = ((cElevatorGOBJ*)args[0].p)->state->index;
    return floor;
}

int Script_cElevatorGOBJ_GetDestFloor(ScriptArg* args) {
    volatile int floor = ((cElevatorGOBJ*)args[0].p)->state->dest;
    return floor;
}

/* Passengers(lift): true when the passenger count is positive. */
int Script_cElevatorGOBJ_Passengers(ScriptArg* args) {
    volatile int any = ((cElevatorGOBJ*)args[0].p)->passengers > 0;
    return any;
}

int Script_cElevatorGOBJ_GetState(ScriptArg* args) {
    return cElevatorGOBJ_GetState(args[0].p);
}

int Script_cElevatorGOBJ_CloseDoors(ScriptArg* args) {
    return cElevatorGOBJ_CloseDoors(args[0].p);
}

int Script_cElevatorGOBJ_OpenDoors(ScriptArg* args) {
    return cElevatorGOBJ_OpenDoors(args[0].p);
}

/* SeekFloor(lift, floor, flag). */
int Script_cElevatorGOBJ_SeekFloor(ScriptArg* args) {
    int loc[1];   /* stack copy of the floor argument (kept for matching) */
    cElevatorGOBJ* lift;
    int flag;
    int floor;

    flag = args[2].i;
    floor = args[1].i;
    *(int*)(char*)loc = floor;
    lift = args[0].p;
    floor = *(int*)(char*)loc;
    cElevatorGOBJ_SeekFloor(lift, floor, (unsigned int)flag != 0, 0);
    return 0;
}

/* Registers the cElevatorGOBJ script type under cPathedGOBJ; accepts cElevatorNotice. */
int cElevatorGOBJ_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F5548, D_004F54F0);
    return cScriptBase_declareMsgUse(D_004F5548, D_004F5610);
}

int cElevatorGOBJ_getSOBJClassId(void) {
    return D_004F5540;
}

int cElevatorGOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

int Script_Mover_SetSpeed(Args* a) {
    union { int i; float f; } u;
    u.i = a->arg1;
    a->obj->speed = u.f;
    return 0;
}
static inline void merge_flush_func_00211000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211000 */

/* merge_units: begin func_002111C0 */
#pragma push /* merge_units */
#include "script_arg.h"

typedef struct { char pad[0xDC]; unsigned char busy; } MoverGS;
typedef enum { MOVER_GS_IDLE0, MOVER_GS_IDLE1 } MoverGSState;

/* The enum-typed inline result keeps MW's movz select (a plain int/bool folds to sltu/xori). */
static inline MoverGSState MoverGS_State(MoverGS* m) { return m->busy ? MOVER_GS_IDLE0 : MOVER_GS_IDLE1; }

unsigned char Script_Mover_GetState(ScriptArg* args)
{
    return MoverGS_State((MoverGS*)args[0].p);
}
static inline void merge_flush_func_002111C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002111C0 */

/* merge_units: begin func_002111E0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int start; int len; int cur; } SmSeg;
typedef struct { char pad0[0xCC]; int target; SmSeg* seg; char pad1[8]; unsigned char stopped; } SmMover;
int Script_Mover_Stop(SmMover** args)
{
    SmMover* m = *args;
    if (!m->stopped) {
        m->seg->cur = m->seg->start + m->seg->len;
        m->target = m->seg->start + m->seg->len;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002111E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002111E0 */

/* merge_units: begin func_00211220 */
#pragma push /* merge_units */
#define STACK_COPY(arr) (*(int*)(arr))
typedef struct { void* vtable; char base[0x20]; int kind; int index; } PathMsg_f3;
typedef struct { int cur; int dir; int target; } PathState_f3;
typedef struct {
    char pad0[0x98]; int count;
    char pad9C[0xCC - 0x9C]; int posCC; PathState_f3* path;
    char padD4[0xDC - 0xD4]; unsigned char bDC; char padDD[3]; int fE0;
} PathObj_f3;
typedef struct { PathObj_f3* obj; int target; } PathArgs_f3;
extern char D_004F5450[];
extern char D_004DAE90[];
extern void cMessage_ctor_cMessageNameR(PathMsg_f3* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(PathMsg_f3* m, void* target, int immediate);
extern void cMessage_dtor(PathMsg_f3* m, int flags);
static inline void PathObj_SetPos_f3(int idx, PathObj_f3* o)
{
    PathMsg_f3 msg;
    if (idx >= 0 && idx <= o->count - 1 && o->path->cur != idx) {
        o->fE0 = 0;
        if (o->path->cur < idx) {
            o->path->dir = 1;
        } else {
            o->path->dir = -1;
        }
        o->path->target = idx;
        o->posCC = idx;
        o->bDC = 0;
        cMessage_ctor_cMessageNameR(&msg, D_004F5450);
        msg.vtable = D_004DAE90;
        msg.kind = 1;
        msg.index = idx;
        QueueMessage_cMessageR_cSystemP_int(&msg, o, 0);
        msg.vtable = D_004DAE90;
        cMessage_dtor(&msg, 0);
    }
}
int PathObj_ScriptSetPos(PathArgs_f3* a)
{
    int idx[1];
    idx[0] = a->target;
    PathObj_SetPos_f3(STACK_COPY(idx), a->obj);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211220 */

/* merge_units: begin func_00211310 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * Pathed object (mover) script natives.
 */


extern int cPathedGOBJ_ResetAndTrigger(Mover* obj);

/* GetPos(mover): current path index (first word of the path state at +0xD0). */
int Script_Mover_GetPos(Args* a) {
    volatile int pos = a->obj->path[0];
    return pos;
}

int PathObj_ScriptResetAndTrigger(Args* a) {
    cPathedGOBJ_ResetAndTrigger(a->obj);
    return 0;
}
static inline void merge_flush_func_00211310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211310 */

/* merge_units: begin func_00211350 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj211350 { char pad0[0xC]; int id; char p10[0xD0]; int fE0; };
struct Msg211350 { void* vtable; char base[0x20]; int f24; int f28; int from; int to; char pad34[4]; };
extern "C" {
extern char g_TriggerMsgKey[];
extern char D_004DAF10[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(void* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((PathMsg_f3 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((PathMsg_f3 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((PathMsg_f3 *)(a0), (a1))) /* merge_units */

}
static inline int ObjId211350(Obj211350* o) { return o ? o->id : 0; }
#pragma push
#pragma opt_propagation off
extern "C" int PathObj_ScriptTrigger(Obj211350** args) {
    Msg211350 m;
    Msg211350* p = &m;
    Obj211350* self = args[0];
    self->fE0 = 0;
    cMessage_ctor_cMessageNameR(&m, g_TriggerMsgKey);
    m.f24 = 0;
    m.f28 = 0;
    m.vtable = D_004DAF10;
    p->to = ObjId211350(0);
    p->from = ObjId211350(0);
    QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
    m.vtable = D_004DAF10;
    cMessage_dtor(&m, 0);
    return 0;
}
#pragma pop
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00211350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211350 */

/* merge_units: begin func_00211400 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cPathedGOBJ script type registration and accessors.
 */


extern int D_004F54D0;   /* cGameGOBJ script-type value */
extern int D_004F54F8;   /* cPathedGOBJ script-type key */
extern int D_004F5638;   /* cPathedNotice script-type value */

/* Registers the cPathedGOBJ script type under cGameGOBJ; accepts cPathedNotice. */
int cPathedGOBJ_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F54F8, D_004F54D0);
    return cScriptBase_declareMsgUse(D_004F54F8, D_004F5638);
}

int cPathedGOBJ_getSOBJClassId(void) {
    return D_004F54F0;
}

int cPathedGOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211400 */

/* merge_units: begin func_00211470 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cGameGOBJ: only the slots used here are named (vtable offset in comments). */
struct cGameGOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int mode); /* +0x68 */
};

/* Script native: cGameGOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cGameGOBJ_Disable(ScriptArg* args)
{
    cGameGOBJ* obj = (cGameGOBJ*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211470 */

/* merge_units: begin func_002114A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_002114A0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_002114A0;

/* Virtual-call view of cGameGOBJ: only the slots used here are named (vtable offset in comments). */
struct cGameGOBJ_002114A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cGameGOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cGameGOBJ_Enable(ScriptArg_002114A0* args)
{
    cGameGOBJ_002114A0* obj = (cGameGOBJ_002114A0*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002114A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002114A0 */

/* merge_units: begin func_002114D0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cGameGOBJ script type registration and accessors.
 */


extern int D_004F54D8;   /* cGameGOBJ script-type key */
extern int D_004F55D8;   /* cGOBJTriggerEventMsg script-type value */
extern int* cGOBJ_SOBJ_getClassId(void);

/* Registers the cGameGOBJ script type under cGOBJ; accepts cGOBJTriggerEventMsg. */
int cGameGOBJ_SOBJ_init(void) {
    int* base;

    base = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F54D8, *base);
    return cScriptBase_declareMsgUse(D_004F54D8, D_004F55D8);
}

int cGameGOBJ_getSOBJClassId(void) {
    return D_004F54D0;
}

int cGameGOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002114D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002114D0 */

/* merge_units: begin func_00211540 */
#pragma push /* merge_units */
typedef struct { int a; int b; } Desc00211540;
typedef struct { int a; char b; } Proto00211540;
extern int NetRegisterMessageStart(void* reg);
extern int cMessage_RegisterFields(Desc00211540* d);
extern int NetMessageField(Desc00211540* d, void* field, int size, int count);
extern int NetRegisterMessage(void* type, int version, void* factory);
extern char D_004F54C0[];
extern void cNetLockElevatorMsg_NetLockElevatorMsgCallback(void);
unsigned char cNetLockElevatorMsg_InitNet(void* reg)
{
    Proto00211540 p;
    Desc00211540 d;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cMessage_RegisterFields(&d) != 0 &&
        NetMessageField(&d, &p.a, 4, 1) == 0 &&
        NetMessageField(&d, &p.b, 1, 1) == 0 &&
        NetRegisterMessage(D_004F54C0, 2, cNetLockElevatorMsg_NetLockElevatorMsgCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_00211540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211540 */
