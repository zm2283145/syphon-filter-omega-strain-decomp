/*
 * main/guiManager: 2 files, 00418580-004185A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00418580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_cString_cFontPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString_cFontPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418580 */

/* merge_units: begin func_004185A0 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_4185A0;
typedef struct { char* p; } It_4185A0;
typedef struct { Str_4185A0 first; int second; } Pair_4185A0;
typedef struct { void* it; unsigned char ok; } Res_4185A0;
typedef struct { char pad[0x10]; int def; } O_4185A0;
extern void String_CtorCStr_13B480(Str_4185A0* s, char* c);
extern void String_Dtor(Str_4185A0* s, int f);
extern void String_CopyCtor(Str_4185A0* d, Str_4185A0* s);
extern void std_basic_string_char_char_traits_char_begin(It_4185A0* out, Str_4185A0* s);
extern void std_basic_string_char_char_traits_char_end(It_4185A0* out, Str_4185A0* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_4185A0* a, It_4185A0* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_4185A0* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_4185A0* a);
extern void std_make_pair_cString_cFontP(Pair_4185A0* out, Str_4185A0* k, int v);
extern void std_tree_pair_cString_value_compare_insert_one_pairR_5(Res_4185A0* out, O_4185A0* o, Pair_4185A0* p);

unsigned char GuiFont_Register(O_4185A0* o, char* name, int w, int force)
{
    if (name == 0 || w == 0) return 0;
    if (force || o->def == 0) o->def = w;
    {
        Str_4185A0 s;
        It_4185A0 it;
        It_4185A0 end;
        Res_4185A0 r;
        Str_4185A0 k;
        Pair_4185A0 p;
        Pair_4185A0 q;
        unsigned char ok;
        String_CtorCStr_13B480(&s, name);
        std_basic_string_char_char_traits_char_begin(&it, &s);
        std_basic_string_char_char_traits_char_end(&end, &s);
        while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
            if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
            std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
        }
        String_CopyCtor(&k, &s);
        std_make_pair_cString_cFontP(&p, &k, w);
        String_CopyCtor(&q.first, &p.first);
        q.second = p.second;
        std_tree_pair_cString_value_compare_insert_one_pairR_5(&r, o, &q);
        ok = r.ok;
        String_Dtor(&q.first, 0);
        String_Dtor(&p.first, 0);
        String_Dtor(&k, 0);
        String_Dtor(&s, 0);
        return ok;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004185A0 */
