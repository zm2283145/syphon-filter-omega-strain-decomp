/*
 * SFOGame/Source/GuiSubTitleDisplay: 3 files, 004587D0-00458900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004587D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cLList_TextAtomPtr_1_dtor)
static inline void merge_flush_func_004587D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004587D0 */

/* merge_units: begin func_004588C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_004588C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_cLList_TextAtomPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_004588C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004588C0 */

/* merge_units: begin func_00458900 */
#pragma push /* merge_units */
extern int *std_list_deleter_TextAtom_generic_iterator_ctor(int *self, int value);
extern int std_list_deleter_TextAtom_tail(char *self);
extern char *details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(char *self);
extern void std_vector_float_push_back(void *v, float *value);

static inline char *At(char *self, int i) { return (*(char ***)(self + 0x60))[i]; }
#pragma opt_strength_reduction off
void GuiSubTitleDisplay_CalcLineTimes(char *self)
{
    float sum;
    int end;
    int i;
    char *list;
    char *n;

    *(int *)(self + 0x6C) = 0;
    sum = 0.0f;
    for (i = 0; i < *(int *)(self + 0x5C); i++) {
        list = At(self, i);
        for (n = *(char **)(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(list + 4) + 4); std_list_deleter_TextAtom_generic_iterator_ctor(&end, std_list_deleter_TextAtom_tail(list)), n != (char *)end; n = *(char **)(n + 4)) {
            sum += *(float *)(n + 0x10);
            sum += *(int *)(n + 0x3C) / 20.0f;
        }
        std_vector_float_push_back(self + 0x68, &sum);
    }
}
#pragma opt_strength_reduction reset
static inline void merge_flush_func_00458900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00458900 */
