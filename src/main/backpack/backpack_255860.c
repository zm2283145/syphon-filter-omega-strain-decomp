/*
 * main/backpack: range (3 files, 00255860-002559D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00255860 */
#pragma push /* merge_units */
typedef struct { char pad[0x2E4]; int pending; int a; int b; } Q255;
int Backpack_TakeArmor(Q255* s, int* a, int* b) {
    if (s->pending) {
        s->pending--;
        *a = s->a;
        *b = s->b;
        return 1;
    }
    *a = 0;
    *b = 0;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255860 */

/* merge_units: begin func_002558A0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_558A0;
typedef struct { V4_558A0 a; V4_558A0 b; int id; int ref; } Ent_558A0;
typedef struct { unsigned char type; char pad[3]; Ent_558A0 ents[5]; int count; unsigned char flag; char pad2[3]; } Slot_558A0;
typedef struct { char pad[0x64]; Slot_558A0 slots[3]; } Pack_558A0;
extern int WeaponInv_SlotOfItem(int key);
static inline void Cp_558A0(Ent_558A0* d, Ent_558A0* s) { d->a = s->a; d->b = s->b; d->id = s->id; d->ref = s->ref; }
#pragma opt_rotateloops off
int Backpack_TakeItem(Pack_558A0* s, int id, int keep)
{
    Slot_558A0* p; int i;
    int t;
    t = WeaponInv_SlotOfItem(id); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->type == (unsigned char)t) {
            Ent_558A0* e = p->ents;
            int j = 0;
            if (j < p->count) {
                do {
                    if ((void*)e->id == (void*)id) {
                        if (!keep) {
                            if (--e->ref == 0) {
                                int n = --p->count;
                                Cp_558A0(e, (Ent_558A0*)((char*)p + n * 40 + 4));
                            }
                        }
                        return 1;
                    }
                    j++;
                    e++;
                } while (j < p->count);
            }
        }
    }
    return 0;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002558A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002558A0 */

/* merge_units: begin func_002559D0 */
#pragma push /* merge_units */
typedef struct { unsigned char type; char pad[0xCF]; unsigned char flag; char pad2[3]; } Slot2559;
typedef struct { char pad[0x64]; Slot2559 slots[3]; } Pack2559;
#pragma opt_rotateloops off
unsigned char Backpack_GetItemSlotFlag(Pack2559* s, int key) {
    Slot2559* p; int i;
    int t;
    t = WeaponInv_SlotOfItem(key); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->type == (unsigned char)t) return p->flag;
    }
    return 0;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002559D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002559D0 */
