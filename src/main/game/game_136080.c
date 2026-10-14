/*
 * main/game: range (2 files, 00136080-001360D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00136080 */
#pragma push /* merge_units */
extern char D_004E1D88[];
extern char D_004E1D90[];
extern char D_004E1D94[];
extern char D_004E1D98[];
extern char D_004E1D9C[];

int Vec4_GetZero(void) {
    int v0;
    int cond;

    v0 = *(signed char*)(char*)D_004E1D88;
    cond = v0 != 0;
    if (cond) goto L001360B8;
    v0 = 0 + 1;
    *(int*)(char*)D_004E1D90 = 0;
    *(char*)(char*)D_004E1D88 = v0;
    *(int*)(char*)D_004E1D94 = 0;
    *(int*)(char*)D_004E1D98 = 0;
    *(int*)(char*)D_004E1D9C = 0;
L001360B8:;
    v0 = (int)D_004E1D90;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136080 */

/* merge_units: begin func_001360D0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc(int, int, int *, int);                      
int func_001361C0(int , int);                       
int func_001361D0(int *);                           
int func_001361E0(int );                            
int func_00139920(int , int);                       
extern int D_004EA0C0;
extern unsigned char D_00533880;
extern int D_00533888;

void func_001360D0(int arg0) {
    int sp3C;
    int temp_s1;

    if (D_004EA0C0 == NULL) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s1 = Mem_Alloc(0, 0x10, ((int*)"collision.hh"), 0xAE6);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s1 != NULL) {
            sp3C = arg0;
            func_001361E0(temp_s1);
            func_001361C0(temp_s1, func_001361D0(&sp3C));
            F_(temp_s1, 0xC, signed char) = 1;
        }
        D_004EA0C0 = temp_s1;
        return;
    }
    func_00139920(D_004EA0C0, arg0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001360D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001360D0 */
