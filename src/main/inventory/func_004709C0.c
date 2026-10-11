
#include "types.h"
/* Global_PlayerRemoveItem */
typedef struct { int key; char pad[40]; } Pt2_ItemDef;
extern int D_00587FF4;
extern Pt2_ItemDef* D_00587FF8;
extern int Loc_FindKeyThunk(char*);
extern void func_004706C0(void*, int, int, int);
static inline int Pt2_FindDef(int key) {
    int i;
    for (i = 0; i < D_00587FF4; i++) {
        if (key == D_00587FF8[i].key) return i;
    }
    return -1;
}

#pragma opt_strength_reduction off
void Global_PlayerRemoveItem(void* inv, char* name, int n) {
    func_004706C0(inv, Pt2_FindDef(Loc_FindKeyThunk(name)), n, 0);
}
