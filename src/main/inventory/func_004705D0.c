
#include "types.h"
/* Global_PlayerGetItemCount */
typedef struct { int key; char pad[40]; } Pt2_ItemDef;
typedef struct { int id; int count; } Pt2_Item;
typedef struct { int pad0; int n; Pt2_Item* items; } Pt2_ItemInv;
extern int D_00587FF4;
extern Pt2_ItemDef* D_00587FF8;
extern int Loc_FindKeyThunk(char*);
static inline int Pt2_FindDef(int key) {
    int i;
    for (i = 0; i < D_00587FF4; i++) {
        if (key == D_00587FF8[i].key) return i;
    }
    return -1;
}

#pragma opt_strength_reduction off
int Global_PlayerGetItemCount(Pt2_ItemInv* inv, char* name) {
    int idx = Pt2_FindDef(Loc_FindKeyThunk(name));
    if (idx > -1) {
        int i;
        for (i = 0; i < *(volatile int*)&inv->n; i++) {
            if (idx == inv->items[i].id) return inv->items[i].count;
        }
    }
    return 0;
}