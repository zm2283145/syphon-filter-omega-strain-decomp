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
DEFINE_OBJ_LIST_DTOR(func_003CB010)
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
extern int D_00543640;      /* class type id */
extern char D_00543650[];   /* owner/type descriptor */
extern char D_00555070[];
extern int ScalarCollection_Init(void* list);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);

/* Constructor taking the initial unk0C value by reference. */
ListReceiver* Object_ConstructBase(ListReceiver* self, int* id) {
    self->base.vtable = D_004DFDE0;
    self->base.magic = RECEIVER_MAGIC;
    self->base.owner = D_00543650;
    self->base.unk0C = *id;
    self->base.unk10 = -1;
    self->base.enabled = 1;
    self->base.unk18 = 0;
    self->base.vtable = D_004DFDA0;
    ScalarCollection_Init(self->list);
    return self;
}

/* Default constructor. */
ListReceiver* func_003CB110(ListReceiver* self) {
    self->base.vtable = D_004DFDE0;
    self->base.magic = RECEIVER_MAGIC;
    self->base.owner = D_00543650;
    self->base.unk0C = -1;
    self->base.unk10 = -1;
    self->base.enabled = 1;
    self->base.unk18 = 0;
    self->base.vtable = D_004DFDA0;
    ScalarCollection_Init(self->list);
    return self;
}

void func_003CB190(void) {
}

/* Identity cast; volatile mirrors the original stack temporary. */
int func_003CB1A0(int obj) {
    volatile int tmp = obj;
    return tmp;
}

void* func_003CB1C0(void* self) {
    return self;
}

int* func_003CB1D0(void) {
    return &D_00543640;
}

int func_003CB1E0(void) {
    return D_00543640;
}

int func_003CB1F0(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

int Receiver_HandleEventBase(void) {
    return 0;
}

void* func_003CB220(Receiver* self) {
    return self->owner;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB090 */

/* merge_units: begin func_003CB230 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Pt2_TimedEv { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; void* target; };
extern "C" {
extern char D_004BD1A8[];
extern char D_004D9DE0[];
extern "C" void func_003CB4F0();
extern "C" void func_003CB530();
extern "C" void func_003CB590();
void * const D_004DFE20[8] = { (void*)0x0, (void*)0x0, (void*)func_003CB530, (void*)func_003CB590, (void*)func_003CB4F0, (void*)0x0, (void*)0x0, (void*)0x0 };
void* Mem_Alloc(int, int, char*, int);
void EventQueue_Admit(Pt2_TimedEv*);
}
extern "C" void func_003CB230(void* target, float secs) {
    Pt2_TimedEv* e;
    {
        AllocGuard g;
        e = (Pt2_TimedEv*)Mem_Alloc(0, 0x10, D_004BD1A8, 0x6C);
    }
    if (e) {
        e->vt = D_004D9DE0;
        e->b4 = 1;
        e->time = 1000.0f * secs;
        e->b5 = 1;
        e->vt = ((char*)D_004DFE20);
        e->target = target;
    }
    EventQueue_Admit(e);
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB230 */
