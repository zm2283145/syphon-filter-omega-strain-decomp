/*
 * main/game: 2 files, 0013BDE0-0013BE20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013BDE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int String_CopyCtor(Unk0013BDE0* self, int a1);

/* Base init through String_CopyCtor, then store the word at +0x0C. */
int std_make_pair_cString_cConsCommandP(Unk0013BDE0* self, int a1, int value) {
    int result;

    result = String_CopyCtor(self, a1);
    self->unk0C = value;
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013BDE0 */

/* merge_units: begin func_0013BE20 */
#pragma push /* merge_units */
extern signed char D_004EA0D0;
extern char D_004EA0F0[];
extern char D_004EA0D8[];
extern void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_2(void* obj, void* a, void* b);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void cKeyedRegistry_cString_cConsCommand_dtor(void);

/* Returns the lazily constructed static container. */
void* cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(void) {
    int tagB;
    int tagA;
    if (!D_004EA0D0) {
        std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_2(D_004EA0F0, &tagA, &tagB);
        __register_global_object(D_004EA0F0, cKeyedRegistry_cString_cConsCommand_dtor, D_004EA0D8);
        D_004EA0D0 = 1;
    }
    return D_004EA0F0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013BE20 */
