#include "types.h"
typedef struct { int w[0x60 / 4]; } A_1DB9A0;
typedef struct { int w[0x70 / 4]; } B_1DB9A0;
typedef struct { int w[0x78 / 4]; } C_1DB9A0;
typedef struct { int w[3]; } R_1DB9A0;
extern void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(int* it, void* map);
extern void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(int* dst, int* src);
extern void std_tree_pair_cWeaponSlotPair_value_compare_find(int* it, void* map, short* key);
extern A_1DB9A0* cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(A_1DB9A0* a, void* val);
extern void std_make_pair_cWeaponSlotPair_cIkTargetLeftRight(B_1DB9A0* b, short key, A_1DB9A0* a);
extern C_1DB9A0* std_pair_cWeaponSlotPair_cIkTarget_LeftRight_ctor_pairR(C_1DB9A0* c, B_1DB9A0* b);
extern void std_map_cWeaponSlotPair_cIkTarget_LeftRight_insert(R_1DB9A0* r, void* map, C_1DB9A0* c);
void* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotTransitionTable_Add_WithRedundancyCheck(void* map, short* key, void* val)
{
    int e[1];
    int f[1];
    int t[1];
    R_1DB9A0 r;
    C_1DB9A0 c;
    B_1DB9A0 b;
    A_1DB9A0 a;
    std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(t, map);
    cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(e, t);
    std_tree_pair_cWeaponSlotPair_value_compare_find(f, map, key);
    if (f[0] == e[0]) {
        std_make_pair_cWeaponSlotPair_cIkTargetLeftRight(&b, *key, cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(&a, val));
        std_map_cWeaponSlotPair_cIkTarget_LeftRight_insert(&r, map, std_pair_cWeaponSlotPair_cIkTarget_LeftRight_ctor_pairR(&c, &b));
    }
    return map;
}