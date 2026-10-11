
#include "types.h"
/* ItemInv_Any */
typedef struct { int id; int count; } Pt2_Item;
typedef struct { int pad0; int n; Pt2_Item* items; } Pt2_ItemInv;

#pragma opt_strength_reduction off
int func_004704F0(Pt2_ItemInv* inv) {
    int i;
    for (i = 0; i < *(volatile int*)&inv->n; i++) {
        if (inv->items[i].count) return 1;
    }
    return 0;
}
