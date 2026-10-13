#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
static inline void UM(void* m) { void* p = m; int t; asm { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx;
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
extern "C" {
int Actor_IsArmed(void*);
int Backpack_Construct(void*, int, int);
int Inventory_HasAnyItem(int);
int Random_Next(void);
int WeaponInv_GetClipSize(int, int);
void WeaponInv_MoveItemsToBackpack(int, int);

void cNPC_v6B(char* self) {
    char* a = F_(self, 0x30, char*);
    int inv = F_(a, 0x3524, int);
    if (Inventory_HasAnyItem(inv)) {
        Mtx m;
        UM(&m);
        WeaponInv_MoveItemsToBackpack(inv, Backpack_Construct(a, 0, 0));
    }
    a = F_(self, 0x30, char*);
    if (Actor_IsArmed(a)) {
        int w = F_(a, 0x3524, int);
        F_(self, 0xA4, int) = (F_(F_(self, 0x30, char*), 0xC, unsigned short) & 7) + 3;
        if (Random_Next() & 1) {
            F_(self, 0xA4, int)++;
        }
        int c = F_(self, 0xA4, int);
        if (WeaponInv_GetClipSize(w, 6) < c) {
            int n = WeaponInv_GetClipSize(w, 6) / 2;
            F_(self, 0xA4, int) = (n <= 0) ? 1 : n;
        }
    } else {
        F_(self, 0xA4, int) = 0;
    }
    F_(self, 0xA8, int) = 0;
}
}





