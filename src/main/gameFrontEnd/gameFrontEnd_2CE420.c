/*
 * main/gameFrontEnd: 5 files, 002CE420-002CE690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CE420 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004AD158[]; void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" void func_002CE420(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004AD158, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002CE420 */

/* merge_units: begin func_002CE4C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

int func_002CE4C0(void) {
    return 1;
}

int func_002CE4D0(WordFields* self) {
    return self->unk00;
}

int func_002CE4E0(WordFields* self) {
    return self->unk04;
}

List* std_list_deleter_MessageBoxEntry_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_002CE4C0 */

/* merge_units: begin func_002CE510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_002CE510, std_vector_deleter_tAchievementInfo_clear, D_004AA5B8)
#pragma pop /* merge_units */
/* merge_units: end func_002CE510 */

/* merge_units: begin func_002CE600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_copy_ctor.h"

/* Copy-construct a string. */
DEFINE_SHORT_STRING_COPY_CTOR(func_002CE600)
#pragma pop /* merge_units */
/* merge_units: end func_002CE600 */

/* merge_units: begin func_002CE690 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_002CE690)
#pragma pop /* merge_units */
/* merge_units: end func_002CE690 */
