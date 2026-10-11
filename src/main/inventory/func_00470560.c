
#include "types.h"
/* ItemInv_Count */
typedef struct { int id; int count; } Pt2_Item;
typedef struct { int pad0; int n; Pt2_Item* items; } Pt2_ItemInv;

static inline Pt2_Item* Find(Pt2_ItemInv* inv, int id) {
    int i;
    for (i = 0; i < *(volatile int*)&inv->n; i++) {
        if (id == inv->items[i].id) return &inv->items[i];
    }
    return 0;
}
#pragma opt_strength_reduction off
int func_00470560(Pt2_ItemInv* inv, int id) {
    Pt2_Item* e = Find(inv, id);
    return e ? e->count : 0;
}
