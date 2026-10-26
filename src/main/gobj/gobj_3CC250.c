/*
 * main/gobj: range (10 files, 003CC250-003CC500)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_003CC250 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */


void SubScript_v0E(void) {
}

void SubScript_v0F(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC250 */

/* merge_units: begin func_003CC270 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003CC270 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_003CC270;

/* Virtual-call view of cGOBJ: only the slots used here are named (vtable offset in comments). */
struct cGOBJ_003CC270 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int who); /* +0x68 */
};

/* Script native: cGOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_SubScript_Disable(ScriptArg_003CC270* args)
{
    cGOBJ_003CC270* obj = (cGOBJ_003CC270*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC270 */

/* merge_units: begin func_003CC2A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003CC2A0 { int i; float f; void* p; unsigned char b; } ScriptArg_003CC2A0;

struct cGOBJ_003CC2A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int value); /* +0x64 */
};

/* Script native: cGOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_SubScript_Enable(ScriptArg_003CC2A0* args)
{
    cGOBJ_003CC2A0* obj = (cGOBJ_003CC2A0*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC2A0 */

/* merge_units: begin func_003CC2D0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad4[0x18]; int flags; char pad20[4]; int target; char pad28[8]; } Msg003CC2D0;
typedef struct { char pad[0x64]; unsigned char busy; } Obj003CC2D0;
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
extern void Event_Construct(Msg003CC2D0* ev, void* desc);
extern void Event_Send(Msg003CC2D0* ev, void* target, int flags);
extern void cMessage_dtor(Msg003CC2D0* ev, int flags);
/* Clear the busy flag and send a message to the object. */
void SubScript_v18(Obj003CC2D0* obj)
{
    Msg003CC2D0 ev;
    obj->busy = 0;
    Event_Construct(&ev, g_cDisableMsgClass);
    ev.vtable = D_004E0860;
    ev.target = -1;
    ev.flags = 0x40;
    Event_Send(&ev, obj, 0);
    ev.vtable = D_004E0860;
    cMessage_dtor(&ev, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC2D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC2D0 */

/* merge_units: begin func_003CC350 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x18]; int size; char pad[4]; int index; char pad2[8]; } Visitor;
typedef struct { char pad[0x64]; unsigned char flag; } SubScript;

extern char g_cEnableMsgClass[];
extern char D_004E0880[];
#if 0 /* merge_units */
extern void Event_Construct(Visitor* v, void* arg);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(Visitor* v, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Visitor* v, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* SubScript virtual 0x17: sets the flag and applies a temporary visitor to self. */
void SubScript_v17(SubScript* self)
{
    Visitor v;
    self->flag = 1;
    Event_Construct(&v, g_cEnableMsgClass);
    v.vtable = D_004E0880;
    v.index = -1;
    v.size = 0x40;
    Event_Send(&v, self, 0);
    v.vtable = D_004E0880;
    cMessage_dtor(&v, 0);
}
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC350 */

/* merge_units: begin func_003CC3D0 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * SubScript script type registration and script-type accessors.
 */


extern int D_005436B8;   /* cGOBJ script-type key */
extern int D_00543720;   /* SubScript script-type value */
extern int D_00543728;   /* SubScript script-type key */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern void ScriptType_SetParent(int type, int base);

/* Registers the SubScript script type under cGOBJ. */
void ScriptType_SubScript_Init(void) {
    ScriptType_SetParent(D_00543728, D_005436B8);
}

int SubScript_v0B(void) {
    return D_00543720;
}

int SubScript_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC3D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC3D0 */

/* merge_units: begin func_003CC420 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003CC420 { int i; float f; void* p; unsigned char b; } ScriptArg_003CC420;

struct cGOBJ_003CC420 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20();
    virtual void ScaleBBox(float value); /* +0x8C */
};

/* Script native: cGOBJ::ScaleBBox(args[1]) on args[0]; returns 0. */
extern "C" int Script_cGOBJ_ScaleBBox(ScriptArg_003CC420* args)
{
    int part[1];
    cGOBJ_003CC420* obj;
    part[0] = args[1].i;
    obj = (cGOBJ_003CC420*)args[0].p;
    obj->ScaleBBox(*(float*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC420 */

/* merge_units: begin func_003CC460 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ darkness script natives.
 */


/* GetDarkness(gobj); the volatile mirrors the original stack temporary. */
int Script_cGOBJ_GetDarkness(ScriptArg* args) {
    volatile int darkness = ((cGOBJ*)args[0].p)->darkness;
    return darkness;
}

/* SetDarkness(gobj, value). */
int Script_cGOBJ_SetDarkness(ScriptArg* args) {
    volatile int darkness = args[1].i;
    ((cGOBJ*)args[0].p)->darkness = darkness;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC460 */

/* merge_units: begin func_003CC4B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003CC4B0 { int i; float f; void* p; unsigned char b; } ScriptArg_003CC4B0;

struct Component {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18();
    virtual unsigned char IsEnemy(int other); /* +0x6C */
};

typedef struct cGOBJ_003CC4B0 { char pad[0x58]; Component* component; /* +0x58 */ } cGOBJ_003CC4B0;

/* Script native: asks the object component (+0x58, virtual +0x6C) about args[1]; true when there is no component. */
extern "C" int Script_cGOBJ_Enemy_2(ScriptArg_003CC4B0* args)
{
    int result;
    int part[1];
    cGOBJ_003CC4B0* obj;
    int other;
    Component* component;
    obj = (cGOBJ_003CC4B0*)args[0].p;
    part[0] = args[1].i;
    component = obj->component;
    other = *(int*)part;
    result = -1;
    if (component)
        result = component->IsEnemy(other);
    return result != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC4B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC4B0 */

/* merge_units: begin func_003CC500 */
#pragma push /* merge_units */
int cGobjController_Enemy_int(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC500 */
