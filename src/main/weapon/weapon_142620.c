/*
 * main/weapon: range (4 files, 00142620-00142960)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00142620 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x18]; int size; unsigned char kind; char pad21[0xB]; unsigned char b2C; char pad2D[7]; unsigned char slot; char pad35[3]; int amount; char pad3C[4]; } Ev_2620;
typedef struct { int pad0; int id; int x8; int count; } Slot_2620;
typedef struct { int pad0; Slot_2620 slots[8]; unsigned char cur; char pad85[3]; void* own; } S_2620;
typedef struct { char pad[0x18]; int x18; } H_2620;
extern unsigned char D_005721C8;
extern char D_0052ACC8[];
extern char D_004DE610[];
void Event_Construct(Ev_2620* e, void* type);
void Event_Send(Ev_2620* e, void* target, int a);
void cMessage_dtor(Ev_2620* e, int f);
int func_00142620(S_2620* self, int slot, int amount, int remote)
{
    unsigned char dbl;
    Slot_2620* s;
    int max;
    int n;
    int dec;
    dbl = (unsigned char)slot == 0 && !(~((H_2620*)self)->x18 == 0);
    s = &self->slots[(unsigned char)slot];
    if (dbl)
        max = s->count * 2;
    else
        max = s->count;
    n = amount < max ? amount : max;
    if (dbl)
        dec = n / 2;
    else
        dec = n;
    s->count -= dec;
    if (D_005721C8 && !remote) {
        Ev_2620 e;
        Event_Construct(&e, D_0052ACC8);
        e.slot = slot;
        e.amount = n;
        e.vt = D_004DE610;
        e.b2C = 1;
        e.size = 0x40;
        e.kind = 4;
        Event_Send(&e, self->own, 0);
        e.vt = D_004DE610;
        cMessage_dtor(&e, 0);
    }
    return n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142620 */

/* merge_units: begin func_00142760 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad21[0xB];
    unsigned char op;
    char pad2D[7];
    char slot;
    char pad35[3];
    int value;
} Msg_INV;
typedef struct { int a; int b; int c; int d; } E_INV;
typedef struct { E_INV e[8]; char pad[0x88 - 0x80]; void* owner; } INV;
#if 0 /* merge_units */
extern void Event_Construct(Msg_INV* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(Msg_INV* msg, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_INV* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

int WeaponInv_SetClip(INV* self, unsigned char slot, int v, int quiet)
{
    self->e[slot].d = v;
    if (D_005721C8 && !quiet) {
        Msg_INV msg;
        Event_Construct(&msg, D_0052ACC8);
        msg.vtable = D_004DE610;
        msg.slot = slot;
        msg.value = v;
        msg.op = 3;
        msg.x1C = 0x40;
        msg.kind = 4;
        Event_Send(&msg, self->owner, 0);
        msg.vtable = D_004DE610;
        cMessage_dtor(&msg, 0);
    }
    return 1;
}
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142760 */

/* merge_units: begin func_00142830 */
#pragma push /* merge_units */
typedef struct { char pad[0xF0]; unsigned char state; char pad2[0x10C-0xF1]; int team; } S2960;
int WeaponInv_IsSameAmmo(void* unused, S2960* a, S2960* b); /* gsynth: defined below */typedef struct { int a; int id; int c; int d; } E_830;
typedef struct { int pad; E_830 e[7]; char pad2[0x84 - 0x74]; signed char held; } INV_830;
extern int D_004FFD30;
extern void* WeaponInv_GetHeldItem(INV_830* self);
extern void* WeaponDb_Get(int db, int id);
#if 0 /* merge_units */
extern int WeaponInv_IsSameAmmo(INV_830* self, void* a, void* b);
#endif /* merge_units */
#define WeaponInv_IsSameAmmo(a0, a1, a2) (WeaponInv_IsSameAmmo((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

extern int WeaponInv_AddSpare(INV_830* self, int slot, int req, int quiet);
extern void WeaponInv_DualShare(INV_830* self);
int WeaponInv_AddAmmo(INV_830* self, void* who, int req)
{
    int total = 0;
    void* held = WeaponInv_GetHeldItem(self);
    int i;
    if (held && WeaponInv_IsSameAmmo(self, held, who)) {
        total = WeaponInv_AddSpare(self, self->held, req, 0);
        req -= total;
    }
    for (i = 0; req && i < 6; i++) {
        if (i != (unsigned char)self->held && self->e[i].id != -1) {
            if (WeaponInv_IsSameAmmo(self, WeaponDb_Get(D_004FFD30, self->e[i].id), who)) {
                int n = WeaponInv_AddSpare(self, (unsigned char)i, req, 0);
                total += n;
                req -= n;
            }
        }
    }
    WeaponInv_DualShare(self);
    return total;
}
#undef WeaponInv_IsSameAmmo /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142830(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142830 */

/* merge_units: begin func_00142960 */
#pragma push /* merge_units */
int WeaponInv_IsSameAmmo(void* unused, S2960* a, S2960* b)
{
    if (a && b) {
        if (a == b)
            return 1;
        if (a->team == b->team && a->state != 1 && b->state != 1)
            return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142960 */
