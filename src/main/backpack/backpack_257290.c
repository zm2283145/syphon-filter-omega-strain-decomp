/*
 * main/backpack: range (2 files, 00257290-00257380)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_00257290 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cBackpackPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00257290 */

/* merge_units: begin func_00257380 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */
                                    
#if 0 /* merge_units */
int Alloc_Unlock(int);
#endif /* merge_units */
#define Alloc_Unlock(a0) (Alloc_Unlock((a0))) /* merge_units */
                                  
int Mem_Alloc(int, int, int *, int);                      
int cArrayCapacity_Int(int *);                           
int PtrVec_Reserve_Thunk_257450(int , int);                       
int std_vector_cBackpackPtr_ctor(int );                            
extern int D_004A7B50;
extern int g_BackpackList;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cBackpack_InitLevel(void) {
    int sp2C;
    int temp_s0;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0 = Mem_Alloc(0, 0x10, &D_004A7B50, 0x17D);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    if (temp_s0 != NULL) {
        sp2C = 0x14;
        std_vector_cBackpackPtr_ctor(temp_s0);
        PtrVec_Reserve_Thunk_257450(temp_s0, cArrayCapacity_Int(&sp2C));
        F_(temp_s0, 0xC, signed char) = 1;
    }
    g_BackpackList = temp_s0;
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00257380 */
