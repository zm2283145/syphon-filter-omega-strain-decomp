/*
 * Libs/SFOLib/Source/man: 2 files, 00383660-00383680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin texman_383660 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

List* std_list_deleter_int_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_texman_383660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end texman_383660 */

/* merge_units: begin func_00383680 */
#pragma push /* merge_units */
typedef struct { unsigned char pad[0x2D96]; short v; } Obj_383680;
void ActorModel_GlowDown(Obj_383680* o)
{
    o->v -= 2;
    if (o->v < 0) o->v = 0;
}
static inline void merge_flush_func_00383680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00383680 */
