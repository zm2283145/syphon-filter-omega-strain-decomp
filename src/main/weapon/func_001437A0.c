#include "types.h"
typedef struct E3Slot437 { int unk0; int id; int unk8; int unkC; } E3Slot437;
typedef struct E3Inv437 { int unk00; E3Slot437 slots[8]; unsigned char selected; } E3Inv437;
typedef struct E3Def437 { char pad[0xF0]; signed char unkF0; } E3Def437;
extern void* D_004FFD30;
extern E3Def437* WeaponDb_Get(void* table, int id);
static inline E3Slot437* GetSel(E3Inv437* inv) { return &inv->slots[inv->selected]; }
int func_001437A0(E3Inv437* inv) {
    if (inv->selected != 6) {
        return WeaponDb_Get(D_004FFD30, GetSel(inv)->id)->unkF0;
    }
    return 11;
}