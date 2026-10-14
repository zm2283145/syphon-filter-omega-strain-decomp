/*
 * main/inventory: range (2 files, 004702A0-004703B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_004702A0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x28]; void* model; } Pt2_ItemDef;
extern "C" {
extern int D_00587FF4;
extern Pt2_ItemDef* D_00587FF8;
extern char D_00587FF0[];
void func_0038CC70(void*);
void func_004719A0(void*);
}


static inline void Pt2_Free(void* p) {
    AllocGuard g;
    Mem_Free(0, p, "inventory.cc", 0xD8);
}
#pragma opt_strength_reduction off
extern "C" void func_004702A0(void) {
    int i;
    for (i = 0; i < D_00587FF4; i++) {
        func_0038CC70(D_00587FF8[i].model);
        Pt2_Free(D_00587FF8[i].model);
    }
    func_004719A0(D_00587FF0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004702A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004702A0 */

/* merge_units: begin func_004703B0 */
#pragma push /* merge_units */
typedef struct { char p[8]; char m8[0x20]; char m28[4]; } E4703B0;
extern void* D_004FFD30;
#if 0 /* merge_units */
extern E4703B0* D_00587FF8;
#endif /* merge_units */
#define D_00587FF8 (*(E4703B0 **)&D_00587FF8) /* merge_units */

extern void WeaponDb_LoadModel(void* m, void* a, void* b, int c, int d, int e, int f);
#pragma push
#pragma opt_strength_reduction off
void func_004703B0(void)
{
    void* m = D_004FFD30;
    int i;
    for (i = 0; i < D_00587FF4; i++) WeaponDb_LoadModel(m, D_00587FF8[i].m8, D_00587FF8[i].m28, -1, 0, 0, 0);
}
#pragma pop
#undef D_00587FF8 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004703B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004703B0 */
