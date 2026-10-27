/*
 * Libs/SFOLib/Source/interface_model: 2 files, 003EF000-003EF010
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EF000 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* std_list_cInterfaceElementPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003EF000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EF000 */

/* merge_units: begin func_003EF010 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cMemMan_Allocate();                        
int cInterfaceElement_ctor(int, int );                     
int cInterfaceModel_Activate(int, int, int);                              
int std_list_cInterfaceElementPtr_push_back(int , int *);                     
extern int D_004BE030;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

int cInterfaceModel_CreateInstance(int arg0) {
    int sp3C;
    int var_s1;

    cInterfaceModel_Activate(arg0, 1, 1);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s1 = cMemMan_Allocate(0, 0x80, &D_004BE030, 0x207);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (var_s1 != 0) {
        var_s1 = cInterfaceElement_ctor(var_s1, arg0);
    }
    sp3C = var_s1;
    std_list_cInterfaceElementPtr_push_back(arg0 + 0x8C, &sp3C);
    return F_(F_(arg0, 0x90, int), 0x8, int);
}
static inline void merge_flush_func_003EF010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EF010 */
