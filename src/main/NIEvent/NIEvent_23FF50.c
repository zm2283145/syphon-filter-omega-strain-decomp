/*
 * main/NIEvent: range (5 files, 0023FF50-00240230)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023FF50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DC2D0[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DC2D0; p->b24 = s->b24;

extern "C" { char D_004A71B8[] = "NIEvent.hh"; }
DEFINE_MESSAGE_CLONE(cNICameraMsg_Clone, Msg_0023FF50, 40, D_004A71B8, 105, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0023FF50 */

/* merge_units: begin func_00240050 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone_inline28.h"

extern "C" { char D_004A71C8[] = "NIEvent.hh"; }
DEFINE_MSG_CLONE_INLINE28(cNIShuttle_Clone, 0x28, D_004A71C8, 0x47, D_004DFD80, D_004DC2F0)
#pragma pop /* merge_units */
/* merge_units: end func_00240050 */

/* merge_units: begin func_00240150 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"
DEFINE_RESIZE_ELEMENT(Elem16_0150, 16)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_FloatKey_resize, Elem16_0150, Vector_Insert_240760, std_vector_imp_FloatKey_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00240150 */

/* merge_units: begin func_002401C0 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem64_01C0, 64)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_VectorKey_resize, Elem64_01C0, Vector_Insert_240DE0, std_vector_imp_VectorKey_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_002401C0 */

/* merge_units: begin func_00240230 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem8_0230, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_VisKey_resize, Elem8_0230, Vector_Insert_241590, std_vector_imp_VisKey_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00240230 */
