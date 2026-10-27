/*
 * Libs/SFOLib/Source/materialProperties: 3 files, 004088D0-004089B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004088D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(std_pair_cString_char_dtor, String_Dtor)
static inline void merge_flush_func_004088D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004088D0 */

/* merge_units: begin func_00408930 */
#pragma push /* merge_units */
extern void operator_delete(void* p);
extern void __destroy_array(void* arr, void* dtor, int size, int n);
extern void* cMaterialProperties_MatPropInfo_dtor(void* self, short del);
extern void* String_Dtor(void* self, short del);
/* Deleting destructor: destroys 5 members at +0xC, then the base. */
void* cMaterialProperties_dtor(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array((char*)self + 0xC, (void*)cMaterialProperties_MatPropInfo_dtor, 0x38, 5);
        if (self)
            String_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00408930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408930 */

/* merge_units: begin func_004089B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int std_basic_string_char_char_traits_char_ctor_basicstringR(L4FlagVec*, int);

int std_make_pair_cString_uchar(L4FlagVec* v, int a1, int flag) {
    int ret = std_basic_string_char_char_traits_char_ctor_basicstringR(v, a1);

    v->unk0C = flag;
    return ret;
}
static inline void merge_flush_func_004089B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004089B0 */
