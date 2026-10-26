/*
 * main/texman: 2 files, 00382EA0-00382ED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00382EA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator helpers.
 */

#include "types.h"
#include "texman_types.h"

Word* cLListIterator_int_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_deleter_int_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

TexListIter* std_list_deleter_int_generic_iterator_ctor_nodeP(TexListIter* it, TexListNode* node) {
    it->node = node;
    return it;
}
#pragma pop /* merge_units */
/* merge_units: end func_00382EA0 */

/* merge_units: begin func_00382ED0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TexMan {
    int used;
    char pad[0x48C - 4];
    int last;
};

static inline int BlockW(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 8 : (bpp == 16) ? 16 : (bpp == 8) ? 16 : 32;
}

static inline int BlockH(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 8 : (bpp == 16) ? 8 : 16;
}

static inline int BlockShift(int bpp)
{
    return (bpp == 32 || bpp == 24) ? 6 : (bpp == 16) ? 7 : (bpp == 8) ? 8 : 9;
}
extern "C" int cTexMan_AllocStaticVram(TexMan* self, int w, int h, int bpp)
{
    int last = self->last;
    if (last == self->used) {
        unsigned int bw, bh;
        int aw, ah;
        int sh;
        w = (w < h) ? h : w;
        bw = BlockW(bpp);
        bh = BlockH(bpp);
        aw = bw * ((int)(w + bw - 1) / (int)bw);
        ah = bh * ((int)(h + bh - 1) / (int)bh);
        sh = BlockShift(bpp);
        self->used += (aw * ah) >> sh;
        self->last = self->used;
    }
    return last;
}
#pragma pop /* merge_units */
/* merge_units: end func_00382ED0 */
