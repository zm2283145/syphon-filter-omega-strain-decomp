/*
 * main/globalization: range (2 files, 003FDB80-003FDBB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003FDB80 */
#pragma push /* merge_units */
extern int* D_0055CA78;
int Loc_GetTextById(int id)
{
    return id >= 0 ? D_0055CA78[id] : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FDB80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FDB80 */

/* merge_units: begin func_003FDBB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int PtrVector_Resize(char *, int, int *);                
int func_003FEEE0(int, int);                            
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int D_0055CA50;
extern char D_0055CA70;
extern int D_0055CA80;
extern int D_0055D460;
extern int D_0055D468;

void func_003FDBB0(void) {
    int sp2C;
    int temp_s0;

    temp_s0 = D_0055CA50;
    if (temp_s0 != 0) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        if ((temp_s0 != 0) && (temp_s0 != 0) && (temp_s0 != 0)) {
            func_003FEEE0(temp_s0, 0);
        }
        Mem_Free(0, temp_s0, "globalization.cc", 0x9B);
        if (g_ProfileLockEnabled != 0) {
            Alloc_Unlock(9);
        }
        D_0055CA50 = 0;
        g_ProfileLockDepth -= 1;
    }
    sp2C = 0;
    PtrVector_Resize(&D_0055CA70, D_0055CA80, &sp2C);
    D_0055D460 = D_0055D468;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FDBB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FDBB0 */
