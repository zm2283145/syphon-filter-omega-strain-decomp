/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int D_004EA3D0;          /* cAIModeChangeMsg script type */
extern int D_004EA3F0;
extern int D_004EA3F8;          /* cNPC script type */
extern char D_00555070[];       /* cNPC script filter table */
extern void Global_PlayerAddItem(int items, int item, int count);
extern int Global_PlayerGetItemCount(int items, int item);
extern void Global_PlayerRemoveItem(int items, int item, int count);
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* func_0016AD70(void);
extern int func_00198F90(NpcActor* actor, int on, int a2);
extern int func_00199040(NpcActor* actor, int on, int a2);
extern int func_001990F0(NpcActor* actor, int on, int a2);
extern int* func_00210CB0(void);
extern int func_003D9400(int type, int iface);
extern void func_003D9440(int type, int base);
extern int* func_004080E0(void);

/* Registers the cNPC script type: base type, then the interfaces it accepts. */
int ScriptType_cNPC_Init(void) {
    int* base;
    int* iface;

    base = func_0016AD70();
    func_003D9440(D_004EA3F8, *base);
    iface = func_00210CB0();
    func_003D9400(D_004EA3F8, *iface);
    func_003D9400(D_004EA3F8, D_004EA3D0);
    iface = func_004080E0();
    return func_003D9400(D_004EA3F8, *iface);
}

int func_0014A670(int value) {
    int word[1];

    *(int*)(char*)word = value;
    return *(int*)(char*)word;
}

void* func_0014A690(void* self) {
    return self;
}

int* func_0014A6A0(void) {
    return &D_004EA3F0;
}

/* vtable slot 0x0B. */
int func_0014A6B0(void) {
    return D_004EA3F0;
}

/* vtable slot 0x0C: forwards to the cNPC script filter. */
int func_0014A6C0(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* Script: cAIModeChangeMsg.GetAiMode(). */
int Script_cAIModeChangeMsg_GetAiMode(NpcAiMsg** args) {
    return args[0]->aiMode;
}

void func_0014A6F0(void) {
}

/* Returns the cAIModeChangeMsg script type. */
int cAIModeChangeMsg_v03(void) {
    return D_004EA3D0;
}

/* vtable slot 0x86: GetItemCount. */
int cNPC_GetItemCount(cNPC* self, int item) {
    NpcActor* actor;

    actor = self->actor;
    return Global_PlayerGetItemCount(actor->items, item);
}

/* vtable slot 0x85: RemoveItem. */
void cNPC_RemoveItem(cNPC* self, int item, int count) {
    NpcActor* actor;

    actor = self->actor;
    Global_PlayerRemoveItem(actor->items, item, count);
}

/* vtable slot 0x84: AddItem. */
void cNPC_AddItem(cNPC* self, int item, int count) {
    NpcActor* actor;

    actor = self->actor;
    Global_PlayerAddItem(actor->items, item, count);
}

/* vtable slot 0x83: SetNotTargetable. */
int cNPC_SetNotTargetable(cNPC* self, int on) {
    return func_001990F0(self->actor, on, 0);
}

/* vtable slot 0x82: SetNotGasable. */
int cNPC_SetNotGasable(cNPC* self, int on) {
    return func_00199040(self->actor, on, 0);
}

/* vtable slot 0x81: SetNotTaserable. */
int cNPC_SetNotTaserable(cNPC* self, int on) {
    return func_00198F90(self->actor, on, 0);
}
