/*
 * main/globalization: range (2 files, 003FDEE0-003FDF40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_003FDEE0 */
#pragma push /* merge_units */
extern void func_003FEEE0(void* self, short del);
extern void operator_delete(void* p);
void* func_003FDEE0(void* self, short del)
{
    if (self) {
        func_003FEEE0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FDEE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FDEE0 */

/* merge_units: begin func_003FDF40 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int Alloc_Unlock();                                  
int Loc_ReadPoolFile();                       
int Mem_Alloc();                        
signed char func_0043FBB0();                         
extern char D_00493A40;
extern char D_004BE440;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0055CA40;
extern int D_0055CA74;
extern int D_0055CA80;
extern char D_0055CA90;
extern signed char D_0055D450;
extern int D_0055D458;
extern int D_0055D460;
extern int D_0055D468;
extern unsigned char D_0055D470;

void Loc_LoadCommonPool(int arg0) {
    int sp130[68];
    int sp30[64];
    int temp_s1;

    sprintf(sp130, "%s\\COMMON\\STRINGS%s.DAT", arg0, F_(&D_00493A40, (D_0055D470 * 4), int));
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s1 = Mem_Alloc(0, 0x1E000, &D_004BE440, 0x110);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_0055D458 = temp_s1;
    D_0055D460 = temp_s1;
    D_0055D468 = temp_s1;
    D_00533888 -= 1;
    Loc_ReadPoolFile(&D_0055CA40, sp130);
    D_0055CA80 = D_0055CA74;
    D_0055D468 = D_0055D460;
    sprintf(sp30, "%s\\COMMON\\sfo_char.map", arg0);
    D_0055D450 = func_0043FBB0(&D_0055CA90, sp30);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FDF40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FDF40 */
