/*
 * main/backpack: range (3 files, 00256FD0-002570C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00256FD0 */
#pragma push /* merge_units */
typedef struct { int id; int a[4]; int b[4]; int pad; } G3En_00256FD0;
typedef struct { G3En_00256FD0 e[5]; int pad2; int cc; unsigned char d0; } G3El_00256FD0;
typedef struct { int pad; G3El_00256FD0 el[3]; int x280[4]; } G3S_00256FD0;
void cBackpack_InitCrate(G3S_00256FD0* s) {
    int j, i, k;
    for (i = 0; i < 4; i++) s->x280[i] = 0;
    for (j = 0; j < 3; j++) {
        s->el[j].cc = 0;
        s->el[j].d0 = 0;
        for (i = 0; i < 5; i++) {
            for (k = 0; k < 4; k++) {
                s->el[j].e[i].a[k] = 0;
                s->el[j].e[i].b[k] = 0;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00256FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00256FD0 */

/* merge_units: begin func_00257040 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { char pad[0x2F3]; unsigned char b2F3; char pad2[0x308 - 0x2F4]; int x308; } G3E_00257040;
typedef struct { int pad; int count; G3E_00257040** items; } G3L_00257040;
extern unsigned char g_IsMultiplayer;
extern G3L_00257040* g_BackpackList;
void func_00257040(int x) {
    if (g_IsMultiplayer) {
        G3L_00257040* l = g_BackpackList;
        int i;
        for (i = 0; i < l->count; i++) {
            G3E_00257040* e = l->items[i];
            if (!e->b2F3) {
                int* p = &e->x308;
                if (x == *p) *p = 0;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00257040 */

/* merge_units: begin func_002570C0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
typedef struct BackpackEntry{char pad[0x60];unsigned char active;}BackpackEntry;
typedef struct BackpackRegistry{int capacity,count;BackpackEntry**items;}BackpackRegistry;
#if 0 /* merge_units */
extern BackpackRegistry*g_BackpackList;
#endif /* merge_units */
#define g_BackpackList (*(BackpackRegistry **)&g_BackpackList) /* merge_units */

void cBackpack_Remove(BackpackEntry*);void cBackpack_ResetCrates(void);void ResetInteractBoxes(void);
static inline int Identity(int n){return n;}
void cBackpack_RemoveAll(void){BackpackRegistry*list=g_BackpackList;int i;for(i=0;i<list->count;i++){int offset=i<<2;int base=(int)list->items;BackpackEntry*p=*(BackpackEntry**)(base+offset);if(!p->active){i--;cBackpack_Remove(p);}}cBackpack_ResetCrates();ResetInteractBoxes();}
#undef g_BackpackList /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002570C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002570C0 */
