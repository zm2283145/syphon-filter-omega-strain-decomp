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
ListReceiver* func_003CB090(ListReceiver* self, int* id) {
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
