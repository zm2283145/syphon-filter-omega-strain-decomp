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
DEFINE_TREE_ROOT_DTOR(func_001D8890, func_001DF1F0)
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
int func_001D8A60(int);                               
int func_001D8B10();                                  
int func_001DBB20();                                  
int func_001DF780(int, char *, char *);                     
extern char D_004A0170;
extern int D_004F2D80;
extern int D_004F2D88;
extern unsigned char D_00533880;
extern int D_00533888;

void func_001D8900(void) {
    struct { int f20; int f24[3]; } sl;
    int temp_s0;
    int temp_s0_2;

    if (D_004F2D80 == 0) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0 = Mem_Alloc(0, 0x250, &D_004A0170, 0x271);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0 != 0) {
            func_001D8A60(temp_s0);
        }
        D_004F2D80 = temp_s0;
    }
    func_001DBB20();
    if (D_004F2D88 == 0) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_004A0170, 0x275);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s0_2 != 0) {
            func_001DF780(temp_s0_2, sl.f24, &sl.f20);
        }
        D_004F2D88 = temp_s0_2;
    }
    func_001D8B10();
}
#undef Alloc_Lock /* merge_units */
#undef Alloc_Unlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001D8900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001D8900 */
