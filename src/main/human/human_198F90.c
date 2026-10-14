/*
 * main/human: range (2 files, 00198F90-00199040)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00198F90 */
#pragma push /* merge_units */
/* Message object (vtable, base data, parameters). */
typedef struct HumanMsg_00198F90 {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char value;
    unsigned char extra;
    char pad2[0xA];
} HumanMsg_00198F90;

typedef struct Human_00198F90 {
    char pad[0x346A];
    unsigned char value;
} Human_00198F90;

extern unsigned char D_005721C8;
extern char D_004EEE98[];
extern char D_004DA9D0[]; /* message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void Event_Construct(HumanMsg_00198F90* msg, void* name);
extern void Event_Send(HumanMsg_00198F90* msg, void* target, int flags);
extern void cMessage_dtor(HumanMsg_00198F90* msg, int flags);

/* Stores the byte at +0x346C and, when D_005721C8 is set and not silent, broadcasts it. */
void Actor_SetStunImmune(Human_00198F90* self, unsigned char value, int silent) {
    HumanMsg_00198F90 msg;
    self->value = value;
    if (D_005721C8 && !silent) {
        Event_Construct(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.extra = 2;
        msg.kind = 4;
        msg.size = 0x40;
        msg.value = value;
        Event_Send(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198F90 */

/* merge_units: begin func_00199040 */
#pragma push /* merge_units */
/* Message object (vtable, base data, parameters). */
typedef struct HumanMsg_00199040 {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char value;
    unsigned char extra;
    char pad2[0xA];
} HumanMsg_00199040;

typedef struct Human_00199040 {
    char pad[0x346B];
    unsigned char value;
} Human_00199040;
#if 0 /* merge_units */
extern void Event_Construct(HumanMsg_00199040* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(HumanMsg_00199040* msg, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HumanMsg_00199040* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* Stores the byte at +0x346C and, when D_005721C8 is set and not silent, broadcasts it. */
void Actor_SetNotGasable(Human_00199040* self, unsigned char value, int silent) {
    HumanMsg_00199040 msg;
    self->value = value;
    if (D_005721C8 && !silent) {
        Event_Construct(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.extra = 1;
        msg.kind = 4;
        msg.size = 0x40;
        msg.value = value;
        Event_Send(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00199040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00199040 */
