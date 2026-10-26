/*
 * main/MoviePlayer: 2 files, 003F9520-003F9530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F9520 */

/* merge_units: begin func_003F9530 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int String_CompareNoCase(int, int);
int Hog_Unload(int);
#if 0 /* merge_units */
int details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(int);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(a0) ((int)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11((void *)(a0))) /* merge_units */

int std_list_deleter_cHogFile_generic_iterator_ctor(int *, int);
int std_list_deleter_cHogFile_tail(int);

void ArchiveList_CloseNamed(int arg0, int arg1) {
    int sp4C;
    int var_s0;

    var_s0 = F_(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(arg0 + 4), 0x4, int);
    std_list_deleter_cHogFile_generic_iterator_ctor(&sp4C, std_list_deleter_cHogFile_tail(arg0));
    if (var_s0 != sp4C) {
        do {
            if (String_CompareNoCase(var_s0 + 8, arg1) == 0) {
                Hog_Unload(var_s0 + 8);
            }
            var_s0 = F_(var_s0, 0x4, int);
            std_list_deleter_cHogFile_generic_iterator_ctor(&sp4C, std_list_deleter_cHogFile_tail(arg0));
        } while (var_s0 != sp4C);
    }
}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9530 */
