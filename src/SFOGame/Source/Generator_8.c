/*
 * SFOGame/Source/Generator: 2 files, 0021D350-0021D370
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_int_netSystemField_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_int_netSystemField_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_0021D350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D350 */

/* merge_units: begin func_0021D370 */
#pragma push /* merge_units */
#include "message_pack.h"

#define BASE_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;
DEFINE_MESSAGE_PACK_INLINE(GeneratorMessageBase_Pack, 0x14, D_004F56C8, BASE_BODY)

#define PACK_TAIL(e, b) MP_H(b, 0x10) = MP_U(e, 0x28); MP_S(b, 8) = 3;
DEFINE_MESSAGE_PACK_DERIVED(cGeneratorMessage_Pack, 0x14, GeneratorMessageBase_Pack, PACK_TAIL)
static inline void merge_flush_func_0021D370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D370 */
