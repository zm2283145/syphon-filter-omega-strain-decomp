/*
 * main/humanCollision: 3 files, 001EB340-001EB5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanCollision_types.h"

/* Copy-assign of a preset configuration. */
HumanColPresetCfg* HumanColPreset_Copy(HumanColPresetCfg* dst, HumanColPresetCfg* src) {
    dst->range0Min = src->range0Min;
    dst->range0Max = src->range0Max;
    dst->range1Min = src->range1Min;
    dst->range1Max = src->range1Max;
    dst->range2Min = src->range2Min;
    dst->range2Max = src->range2Max;
    dst->enabled = src->enabled;
    return dst;
}

Word* func_001EB380(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_001EB390(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_001EB340 */

/* merge_units: begin func_001EB3A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
int __destroy_array(int, char *, int, int);                  
int func_001EF8D0(int, int);                            
int func_001EFA40(int, int);                            
extern int D_004F5358;
extern int D_004F5360;
extern int D_004F5368;
extern unsigned char D_00533880;
extern char HumanColPreset_Dtor;
}
extern "C" void HumanCol_Shutdown(void) {
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;

    temp_s0 = D_004F5358;
    if (temp_s0 != 0) {
        {
            AllocGuard g;
        if ((temp_s0 != 0) && (temp_s0 != 0)) {
            __destroy_array(temp_s0 + 0x10, &HumanColPreset_Dtor, 0xF0, 9);
        }
        Mem_Free(0, temp_s0, "humanCollision.cc", 0x3F6);
        }
        D_004F5358 = 0;
    }
    temp_s0_2 = D_004F5360;
    if (temp_s0_2 != 0) {
        {
            AllocGuard g;
        if ((temp_s0_2 != 0) && (temp_s0_2 != 0) && (temp_s0_2 != 0)) {
            func_001EFA40(temp_s0_2, 0);
        }
        Mem_Free(0, temp_s0_2, "humanCollision.cc", 0x3FE);
        }
        D_004F5360 = 0;
    }
    temp_s0_3 = D_004F5368;
    if (temp_s0_3 != 0) {
        {
            AllocGuard g;
        if ((temp_s0_3 != 0) && (temp_s0_3 != 0) && (temp_s0_3 != 0) && (temp_s0_3 != 0)) {
            func_001EF8D0(temp_s0_3, 0);
        }
        Mem_Free(0, temp_s0_3, "humanCollision.cc", 0x406);
        }
        D_004F5368 = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_001EB3A0 */

/* merge_units: begin func_001EB5C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


extern "C" {
int HumanCol_InstallPresets(...);                        
int *Mem_Alloc(...);                       
int __construct_array(...);            
int func_001361D0(...);                           
int func_001EB800(...);                   
int func_001EB870(...);                        
int func_001EB880(...);                             
extern char D_004A04A0;
#if 0 /* merge_units */
extern int *D_004F5358;
#endif /* merge_units */
#define D_004F5358 (*(int **)&D_004F5358) /* merge_units */

#if 0 /* merge_units */
extern int *D_004F5360;
#endif /* merge_units */
#define D_004F5360 (*(int **)&D_004F5360) /* merge_units */

#if 0 /* merge_units */
extern int *D_004F5368;
#endif /* merge_units */
#define D_004F5368 (*(int **)&D_004F5368) /* merge_units */

extern char HumanColPreset_Ctor;
}
extern "C" void HumanCol_Init(void) {
    int sp3C;
    int sp38;
    int *temp_s0;
    int *temp_s0_2;
    int *temp_s0_3;

    if (D_004F5358 == NULL) {
        {
            AllocGuard g;
        temp_s0 = Mem_Alloc(0, 0x880, &D_004A04A0, 0x3DC);
        }
        if (temp_s0 != NULL) {
            *temp_s0 = 0;
            __construct_array((char *)temp_s0 + 0x10, &HumanColPreset_Ctor, &HumanColPreset_Dtor, 0xF0, 9);
        }
        D_004F5358 = temp_s0;
        HumanCol_InstallPresets();
    }
    if (D_004F5360 == NULL) {
        {
            AllocGuard g;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_004A04A0, 0x3E4);
        }
        if (temp_s0_2 != NULL) {
            sp3C = 0x96;
            func_001EB880(temp_s0_2);
            func_001EB870(temp_s0_2, func_001361D0(&sp3C));
            F_(temp_s0_2, 0xC, signed char) = 1;
        }
        D_004F5360 = temp_s0_2;
    }
    if (D_004F5368 == NULL) {
        {
            AllocGuard g;
        temp_s0_3 = Mem_Alloc(0, 0x10, &D_004A04A0, 0x3EB);
        }
        if (temp_s0_3 != NULL) {
            sp38 = 0x96;
            func_001EB800(temp_s0_3, &sp38, 1);
        }
        D_004F5368 = temp_s0_3;
    }
}
#undef D_004F5358 /* merge_units */
#undef D_004F5360 /* merge_units */
#undef D_004F5368 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB5C0 */
