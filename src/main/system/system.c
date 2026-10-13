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
DEFINE_OBJ_LIST_DTOR(ReceiverList_Dtor)
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
extern int ScalarCollection_Init(void* list);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);

/* Constructor taking the initial unk0C value by reference. */
ListReceiver* Object_ConstructBase(ListReceiver* self, int* id) {
    self->base.vtable = D_004DFDE0;
    self->base.magic = RECEIVER_MAGIC;
    self->base.owner = D_00543650;
    self->base.id = *id;
    self->base.unk10 = -1;
    self->base.enabled = 1;
    self->base.buf = 0;
    self->base.vtable = D_004DFDA0;
    ScalarCollection_Init(self->list);
    return self;
}

/* Default constructor. */
ListReceiver* ListReceiver_Ctor(ListReceiver* self) {
    self->base.vtable = D_004DFDE0;
    self->base.magic = RECEIVER_MAGIC;
    self->base.owner = D_00543650;
    self->base.id = -1;
    self->base.unk10 = -1;
    self->base.enabled = 1;
    self->base.buf = 0;
    self->base.vtable = D_004DFDA0;
    ScalarCollection_Init(self->list);
    return self;
}

/* Script type factory passed when registering "cSystem" (no-op). */
void cSystem_ScriptFactory(void) {
}

/* Object -> script value (identity); volatile mirrors the original stack temporary. */
int Script_ObjToValue(int obj) {
    volatile int tmp = obj;
    return tmp;
}

/* Script value -> object (identity). */
void* Script_ValueToObj(void* self) {
    return self;
}

/* Address of the cSystem script type key. */
int* cSystem_GetScriptTypeKeyPtr(void) {
    return &g_cSystemScriptTypeKey;
}

/* Receiver virtual: script type key (cSystem). */
int Receiver_GetScriptTypeKey(void) {
    return g_cSystemScriptTypeKey;
}

/* Receiver virtual: forward a script call to the shared filter. */
int Receiver_ScriptDispatch(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

int Receiver_HandleEventBase(void) {
    return 0;
}

/* Receiver virtual: owner/type descriptor. */
void* Receiver_GetOwner(Receiver* self) {
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
extern "C" void func_003CB4F0();
extern "C" void func_003CB530();
extern "C" void func_003CB590();
/* DeleteLaterEvent vtable. */
void * const D_004DFE20[8] = { (void*)0x0, (void*)0x0, (void*)func_003CB530, (void*)func_003CB590, (void*)func_003CB4F0, (void*)0x0, (void*)0x0, (void*)0x0 };
void* Mem_Alloc(int, int, char*, int);
void EventQueue_Admit(DeleteLaterEvent*);
}
/* Queue a DeleteLaterEvent that deletes target after secs seconds. */
extern "C" void Object_DeleteLater(void* target, float secs) {
    DeleteLaterEvent* e;
    {
        AllocGuard g;
        e = (DeleteLaterEvent*)Mem_Alloc(0, sizeof(DeleteLaterEvent), D_004BD1A8, 0x6C);
    }
    if (e) {
        e->vtable = D_004D9DE0;
        e->b4 = 1;
        e->timeMs = 1000.0f * secs;
        e->b5 = 1;
        e->vtable = ((char*)D_004DFE20);
        e->target = target;
    }
    EventQueue_Admit(e);
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB230 */
