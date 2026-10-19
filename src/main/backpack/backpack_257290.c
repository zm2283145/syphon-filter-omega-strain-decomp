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
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00257290)
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
int func_001361D0(int *);                           
int func_00257450(int , int);                       
int func_00257460(int );                            
extern int D_004A7B50;
extern int g_BackpackList;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void func_00257380(void) {
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
        func_00257460(temp_s0);
        func_00257450(temp_s0, func_001361D0(&sp2C));
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
