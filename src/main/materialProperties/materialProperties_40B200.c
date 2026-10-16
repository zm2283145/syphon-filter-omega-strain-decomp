/*
 * main/materialProperties: 2 files, 0040B200-0040B2A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B200 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "short_string_replace.h"
extern "C" void String_Reserve(ShortStr* self, unsigned int n);
struct SB40B200 { ShortStr s; unsigned char c; };
extern "C" SB40B200* func_0040B200(SB40B200* self, const SB40B200* src)
{
    if (!ShortStr_IsLong(&src->s)) {
        self->s = src->s;
    } else {
        self->s.u.l.word = 0;
        self->s.u.l.length = 0;
        self->s.u.l.data = 0;
        String_Reserve(&self->s, src->s.u.l.length);
        ShortStrIterTag tag;
        String_Replace(&self->s, 0, 0, src->s.u.l.data, src->s.u.l.data + src->s.u.l.length, tag);
    }
    self->c = src->c;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040B200 */

/* merge_units: begin func_0040B2A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_insert_obj.h"

extern "C" { char D_004BEC48[] = "allocator.hh"; }
DEFINE_TREE_INSERT_OBJ(func_0040B2A0, 0x1C, 0x10, D_004BEBD0, D_004BEC48, 0x5C, func_00139BC0, func_0040B410, func_0013CD40)
#pragma pop /* merge_units */
/* merge_units: end func_0040B2A0 */
