/*
 * main/materialProperties: range (2 files, 00408EA0-00408FB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00408EA0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T8FB0;
T8FB0* func_00408FB0(T8FB0* t, short del); /* gsynth: defined below */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int func_0012F530(char *, int);                            
int func_00136DA0(char *);                               
#if 0 /* merge_units */
int func_00408FB0(int, int);
#endif /* merge_units */
#define func_00408FB0(a0, a1) ((int)func_00408FB0((void *)(a0), (short)(a1))) /* merge_units */
                            
int func_0040A210(int, int);                            
extern unsigned char D_00533880;
extern int D_00533888;

typedef struct { int f0; int f4; unsigned char f8; } PS0_00408EA0;
void func_00408EA0(PS0_00408EA0 *arg0) {
    int sp38[2];
    int temp_s1;
    int temp_s1_2;

    if (arg0->f8 != 0) {
        temp_s1 = arg0->f0;
        func_00136DA0(sp38);
        func_00408FB0(temp_s1, -1);
        Mem_Free(0, temp_s1, "materialProperties.cc", 0x75);
        func_0012F530(sp38, -1);
        arg0->f0 = 0;
        temp_s1_2 = arg0->f4;
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        if ((temp_s1_2 != 0) && (temp_s1_2 != 0) && (temp_s1_2 != 0)) {
            func_0040A210(temp_s1_2, 0);
        }
        Mem_Free(0, temp_s1_2, "materialProperties.cc", 0x78);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        arg0->f4 = 0;
        arg0->f8 = 0U;
    }
}
#undef func_00408FB0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00408EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00408EA0 */

/* merge_units: begin func_00408FB0 */
#pragma push /* merge_units */
extern void func_0040A380(T8FB0* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a nested tree owner: erase the root, then delete. */
T8FB0* func_00408FB0(T8FB0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_0040A380(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00408FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00408FB0 */
