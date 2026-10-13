/*
 * main/motionManager: 2 files, 0040F5E0-0040F650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040F5E0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int m0; void* m4; } TF5E0;
extern void World_FreePendingTree(TF5E0* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a nested tree owner: erase the root, then delete. */
TF5E0* func_0040F5E0(TF5E0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    World_FreePendingTree(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040F5E0 */

/* merge_units: begin func_0040F650 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc(int, int, char *, int);                        
int func_0040FBA0(int, char *, char *);                     
extern char D_004BEDD0;
extern unsigned char D_00533880;
extern int D_00533888;
extern int D_00571CD0;

void func_0040F650(void) {
    struct { char pad20[4]; int f24; int f28[2]; } sl;
    int temp_s0;

    if (D_00571CD0 == 0) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0 = Mem_Alloc(0, 0x10, &D_004BEDD0, 0x20);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0 != 0) {
            func_0040FBA0(temp_s0, sl.f28, &sl.f24);
        }
        D_00571CD0 = temp_s0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040F650 */
