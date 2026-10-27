/*
 * main/system: 3 files, 003CB010-003CB230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CB010 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cSystemPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003CB010 */

/* merge_units: begin func_003CB090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Receiver subclass (vtable D_004DFDA0) with an inline scalar collection,
 * plus its type-identity helpers.
 */

#include "types.h"
#include "system_types.h"

extern char D_004DFDA0[];   /* ListReceiver vtable */
extern char D_004DFDE0[];   /* Receiver vtable */
extern int g_cSystemScriptTypeKey;      /* class type id */
extern char D_00543650[];   /* owner/type descriptor */
extern char D_00555070[];
extern int std_list_deleter_voidPtr_ctor_void(void* list);
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);

/* Constructor taking the initial unk0C value by reference. */
ListReceiver* cSystemContainer_ctor_cObjectIdR(ListReceiver* self, int* id) {
    self->base.vtable = D_004DFDE0;
    self->base.magic = RECEIVER_MAGIC;
    self->base.owner = D_00543650;
    self->base.id = *id;
    self->base.unk10 = -1;
    self->base.enabled = 1;
    self->base.buf = 0;
    self->base.vtable = D_004DFDA0;
    std_list_deleter_voidPtr_ctor_void(self->list);
    return self;
}

/* Default constructor. */
ListReceiver* cSystemContainer_ctor_void(ListReceiver* self) {
    self->base.vtable = D_004DFDE0;
    self->base.magic = RECEIVER_MAGIC;
    self->base.owner = D_00543650;
    self->base.id = -1;
    self->base.unk10 = -1;
    self->base.enabled = 1;
    self->base.buf = 0;
    self->base.vtable = D_004DFDA0;
    std_list_deleter_voidPtr_ctor_void(self->list);
    return self;
}

/* Script type factory passed when registering "cSystem" (no-op). */
void cSystem_SOBJ_init(void) {
}

/* Object -> script value (identity); volatile mirrors the original stack temporary. */
int cSystem_SOBJ_toInt(int obj) {
    volatile int tmp = obj;
    return tmp;
}

/* Script value -> object (identity). */
void* cSystem_SOBJ_convert(void* self) {
    return self;
}

/* Address of the cSystem script type key. */
int* cSystem_SOBJ_getClassId(void) {
    return &g_cSystemScriptTypeKey;
}

/* Receiver virtual: script type key (cSystem). */
int cSystem_getSOBJClassId(void) {
    return g_cSystemScriptTypeKey;
}

/* Receiver virtual: forward a script call to the shared filter. */
int cSystem_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

int cSystem_HandleMessage(void) {
    return 0;
}

/* Receiver virtual: owner/type descriptor. */
void* cSystem_GetName(Receiver* self) {
    return self->owner;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB090 */

/* merge_units: begin func_003CB230 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BD1A8[];                   /* "system.cc" */
extern char D_004D9DE0[];                   /* base timed-event vtable */
extern "C" void cDeleteCallback_Call();
extern "C" void cDeleteCallback_dtor();
extern "C" void cDeleteCallback_IsReferencing();
/* DeleteLaterEvent vtable. */
void * const D_004DFE20[8] = { (void*)0x0, (void*)0x0, (void*)cDeleteCallback_dtor, (void*)cDeleteCallback_IsReferencing, (void*)cDeleteCallback_Call, (void*)0x0, (void*)0x0, (void*)0x0 };
void* cMemMan_Allocate(int, int, char*, int);
void nCallback_SetCallback(DeleteLaterEvent*);
}
/* Queue a DeleteLaterEvent that deletes target after secs seconds. */
extern "C" void cSystem_ActualScheduleDelete(void* target, float secs) {
    DeleteLaterEvent* e;
    {
        AllocGuard g;
        e = (DeleteLaterEvent*)cMemMan_Allocate(0, sizeof(DeleteLaterEvent), D_004BD1A8, 0x6C);
    }
    if (e) {
        e->vtable = D_004D9DE0;
        e->b4 = 1;
        e->timeMs = 1000.0f * secs;
        e->b5 = 1;
        e->vtable = ((char*)D_004DFE20);
        e->target = target;
    }
    nCallback_SetCallback(e);
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB230 */
