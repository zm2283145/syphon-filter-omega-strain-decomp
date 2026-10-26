/*
 * main/humanIk: range (2 files, 001D8890-001D8900)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tree_node_free.h"
#pragma pop

/* merge_units: begin func_001D8890 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_TREE_ROOT_DTOR(std_map_cWeaponSlotPair_cIkTarget_LeftRight_dtor, std_tree_pair_cWeaponSlotPair_value_compare_destroy)
#pragma pop /* merge_units */
/* merge_units: end func_001D8890 */

/* merge_units: begin func_001D8900 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */
                                    
#if 0 /* merge_units */
int Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */
                                  
int Mem_Alloc(int, int, char *, int);                        
int cArray_FixedCapacity_cIkTarget_LeftRight_6_ctor(int);                               
int cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotTransitionTable();                                  
int cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotIkTargetTable();                                  
int std_tree_pair_cWeaponSlotPair_value_compare_ctor(int, char *, char *);                     
extern char D_004A0170;
extern int D_004F2D80;
extern int D_004F2D88;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cDrawAndHolsterWeapon_ActionManager_InitStatics(void) {
    struct { int f20; int f24[3]; } sl;
    int temp_s0;
    int temp_s0_2;

    if (D_004F2D80 == 0) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0 = Mem_Alloc(0, 0x250, &D_004A0170, 0x271);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0 != 0) {
            cArray_FixedCapacity_cIkTarget_LeftRight_6_ctor(temp_s0);
        }
        D_004F2D80 = temp_s0;
    }
    cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotIkTargetTable();
    if (D_004F2D88 == 0) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_004A0170, 0x275);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0_2 != 0) {
            std_tree_pair_cWeaponSlotPair_value_compare_ctor(temp_s0_2, sl.f24, &sl.f20);
        }
        D_004F2D88 = temp_s0_2;
    }
    cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotTransitionTable();
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001D8900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001D8900 */
