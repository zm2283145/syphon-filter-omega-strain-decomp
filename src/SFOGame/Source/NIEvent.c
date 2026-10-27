/*
 * SFOGame/Source/NIEvent: 7 files, 002373A0-00237550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002373A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define CMSG_KIND_T char
#define CMSG_NO_PROTOS /* cMessage_dtor is declared by DEFINE_VTABLE_BASE_DTOR below */
#include "cmessage.h"

#define cMessage_vtable  D_004DFD80
#define cNINotice_vtable D_004DBEB0

extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char cMessage_vtable[];
extern char cNINotice_vtable[];
}

/* cNINotice (NIEvent.hh): a cMessage carrying one word whose low byte is the
 * notice action (read by the script Action() accessor). 0x28 bytes. */
struct cNINotice {
    CMSG_HEADER;
    int action; /* +0x24 */
};

/* Clone (vtable slot 1): heap copy of the message, built the way the inlined
 * copy constructors do it (base part first, then the derived vtable). */
extern "C" cNINotice* cCrateInteractMsg_Clone(cNINotice* self)
{
    cNINotice* copy;
    {
        AllocGuard guard;
        copy = (cNINotice*)cMemMan_Allocate(0, sizeof(cNINotice), "NIEvent.hh", 0x28);
    }
    if (copy) {
        copy->vtable = cMessage_vtable;
        copy->type = self->type;
        copy->magic = self->magic;
        copy->time = self->time;
        copy->unk10 = self->unk10;
        copy->target = self->target;
        copy->stampKind = self->stampKind;
        copy->flags = self->flags;
        copy->kind = self->kind;
        copy->vtable = cNINotice_vtable;
        copy->action = self->action;
    }
    return copy;
}
static inline void merge_flush_func_002373A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002373A0 */

/* merge_units: begin func_002374A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNINotice_dtor, cNINotice_vtable, cMessage_dtor)
static inline void merge_flush_func_002374A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002374A0 */

/* merge_units: begin func_00237500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F7D20; /* cNINotice script type key */
extern int D_004F7D28; /* cNINotice script type id */
extern int* cMessage_SOBJ_getClassId(void); /* address of the cMessage type key */
extern void cScriptBase_declareParent(int type, int parentType);

/* Action(notice): returns the notice's action byte (low byte of cNINotice.action, +0x24). */
int Script_cNINotice_Action(unsigned char** args) {
    return args[0][0x24];
}

/* cNINotice derives from cMessage. */
void cNINotice_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7D28, *parent);
}

int cNINotice_getSOBJClassId(void) {
    return D_004F7D20;
}
static inline void merge_flush_func_00237500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237500 */

/* merge_units: begin func_00237550 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cNIEventLight {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44();
    virtual void Reset(); /* +0x11C */
};

/* Script native: cNIEventLight::Reset() on args[0]; returns 0. */
extern "C" int Script_cNIEventLight_Reset(ScriptArg* args)
{
    cNIEventLight* obj = (cNIEventLight*)args[0].p;
    obj->Reset();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237550 */

/* merge_units: begin func_00237580 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00237580 { int i; float f; void* p; } ScriptArg_00237580;

/* Virtual-call view of cNIEventLight: only the slots used here are named (vtable offset in comments). */
struct cNIEventLight_00237580 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43();
    virtual void Stop(int now); /* +0x118 */
};

/* Script native: cNIEventLight::Stop(1) on args[0]; returns 0. */
extern "C" int Script_cNIEventLight_Stop(ScriptArg_00237580* args)
{
    cNIEventLight_00237580* obj = (cNIEventLight_00237580*)args[0].p;
    obj->Stop(1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237580 */

/* merge_units: begin func_002375B0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_002375B0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_002375B0;

/* Virtual-call view of cNIEventLight: only the slots used here are named (vtable offset in comments). */
struct cNIEventLight_002375B0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42();
    virtual void Play(); /* +0x114 */
};

/* Script native: cNIEventLight::Play() on args[0]; returns 0. */
extern "C" int Script_cNIEventLight_Play(ScriptArg_002375B0* args)
{
    cNIEventLight_002375B0* obj = (cNIEventLight_002375B0*)args[0].p;
    obj->Play();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002375B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002375B0 */

/* merge_units: begin func_002375E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F7CF8; /* cNIEventLight script type key */
extern int D_004F7D00; /* cNIEventLight script type id */
extern char D_00555070[]; /* global script filter */
extern int cScriptInterpreter_CallEvent(void* filter, int a1, int a2);
extern int* cGOBJ_SOBJ_getClassId(void); /* address of the cGObj type key */
extern int cScriptBase_declareMsgUse(int type, int acceptedType);

/* cNIEventLight derives from cGObj and accepts cNINotice messages. */
int cNIEventLight_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7D00, *parent);
    return cScriptBase_declareMsgUse(D_004F7D00, D_004F7D20);
}

int cNIEventLight_getSOBJClassId(void) {
    return D_004F7CF8;
}

int cNIEventLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002375E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002375E0 */
