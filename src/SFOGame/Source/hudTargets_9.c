/*
 * SFOGame/Source/hudTargets: 2 files, 00273EE0-00273F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00273EE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

void std_list_cHudTargetInfoPtr_generic_iterator_opCast(int* dst, int* src) {
    *dst = *src;
}

Word* std_list_cHudTargetInfoPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_00273EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273EE0 */

/* merge_units: begin func_00273F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                      
int String_Dtor(...);                         
int std_list_cSafePtr_cGOBJ_dtor(...);                            
int std_list_cHudTargetInfoPtr_end_void_2(...);                          
int cLListIterator_cHudTargetInfoPtr_ctor_listR(...);                      
int std_list_cHudTargetInfoPtr_begin_void_2(...);                          
int std_list_cHudTargetsObserverPtr_dtor(...);                            
int std_list_cHudTargetInfoPtr_dtor(...);                            
int cIE_GOBJ_AnimateOff(...);                               
int operator_delete(...);                             
extern unsigned char D_0048B308;
extern char D_004A8F60;
extern unsigned char g_ProfileLockEnabled;
}
#pragma inline_depth(10)
static inline void beg0(char **o, char *l) { int r; std_list_cHudTargetInfoPtr_begin_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end0(char **o, char *l) { int r; std_list_cHudTargetInfoPtr_end_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void beg1(char **o, char *l) { beg0(o, l); }
static inline void end1(char **o, char *l) { end0(o, l); }
static inline void beg2(char **o, char *l) { beg1(o, l); }
static inline void end2(char **o, char *l) { end1(o, l); }
static inline void end3(char **o, char *l) { end2(o, l); }
extern "C" int cHudTargetManager_dtor(char *arg0, long long arg1) {
    char * sp6C;
    char * temp_s1;
    char * sp68;
    int temp_a0_4;
    char * temp_a0;
    char * var_s0;
    int temp_a0_5;
    int temp_a0_3;
    int sp5C;
    char * temp_a0_2;
    int sp60;

    if (arg0 != 0) {
        D_0048B308 = 0;
        beg0(&sp6C, arg0 + 0xC);
        var_s0 = sp6C;
        for (; end0(&sp68, arg0 + 0xC), var_s0 != sp68; ) {
                temp_s1 = (char *)(F_(var_s0, 0x8, int));
                {
                    AllocGuard g;
                if (temp_s1 != NULL) {
                    if (D_0048B308 != 0) {
                        cIE_GOBJ_AnimateOff(F_(temp_s1, 0x8, int));
                        cIE_GOBJ_AnimateOff(F_(temp_s1, 0x4, int));
                    }
                    temp_a0 = temp_s1 + 0x28;
                    if (temp_a0 != NULL) {
                        String_Dtor(temp_a0, 0);
                    }
                    temp_a0_2 = temp_s1 + 0x1C;
                    if (temp_a0_2 != NULL) {
                        String_Dtor(temp_a0_2, 0);
                    }
                }
                cMemMan_Deallocate(0, temp_s1, &D_004A8F60, 0x17E);
                }
                var_s0 = (char *)(F_(var_s0, 0x4, int));
        }
        temp_a0_3 = (int)(arg0 + 0x24);
        if (temp_a0_3 != 0) {
            std_list_cHudTargetInfoPtr_dtor(temp_a0_3, 0);
        }
        temp_a0_4 = (int)(arg0 + 0x18);
        if (temp_a0_4 != 0) {
            std_list_cSafePtr_cGOBJ_dtor(temp_a0_4, 0);
        }
        temp_a0_5 = (int)(arg0 + 0xC);
        if (temp_a0_5 != 0) {
            std_list_cHudTargetInfoPtr_dtor(temp_a0_5, 0);
        }
        if (arg0 != 0) {
            std_list_cHudTargetsObserverPtr_dtor(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (int)(arg0);
}
static inline void merge_flush_func_00273F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273F00 */
