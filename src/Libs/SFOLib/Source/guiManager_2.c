/*
 * Libs/SFOLib/Source/guiManager: 4 files, 004183A0-00418580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004183A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char d[0x18]; } g2E180;
typedef struct { int pad0; int size; g2E180* data; } g2Vec180;
extern void GuiAnimationTrack_dtor(g2E180* e, int flag);
void std_vector_deleter_GuiAnimationTrack_clear(g2Vec180* v) {
    g2E180* b = v->data;
    g2E180* e = b + v->size;
    while (b < e) {
        --e;
        GuiAnimationTrack_dtor(e, -1);
    }
    v->size = 0;
}
static inline void merge_flush_func_004183A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004183A0 */

/* merge_units: begin func_00418420 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_418420;
typedef struct { char* p; } It_418420;
typedef struct { char pad[0x18]; int value; } Node_418420;
typedef struct { Node_418420* n; } MIt_418420;
typedef struct { char pad[0x10]; int def; } O_418420;
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_418420* s, char* c);
extern void String_Dtor(Str_418420* s, int f);
extern void std_basic_string_char_char_traits_char_begin(It_418420* out, Str_418420* s);
extern void std_basic_string_char_char_traits_char_end(It_418420* out, Str_418420* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_418420* a, It_418420* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_418420* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_418420* a);
extern void std_tree_pair_cString_value_compare_find_cStringR_5(MIt_418420* out, O_418420* o, Str_418420* key);
#if 0 /* merge_units */
extern void std_map_cString_cFontPtr_end(MIt_418420* out, O_418420* o);
#endif /* merge_units */
void std_map_cString_cFontPtr_end(); /* merge_units */

#if 0 /* merge_units */
extern void cAssocArray_cString_cFontPtr_Iterator_ctor(MIt_418420* out, MIt_418420* src);
#endif /* merge_units */
Word * cAssocArray_cString_cFontPtr_Iterator_ctor(); /* merge_units */


#pragma bool off
static inline int Ne_418420(Node_418420* a, Node_418420* b) { return (a == b) ^ 1; }

int GuiManager_GetFont(O_418420* o, char* name)
{
    if (name == 0 || *name == 0) return o->def;
    {
        Str_418420 s;
        MIt_418420 e;
        MIt_418420 f;
        It_418420 it;
        It_418420 end;
        MIt_418420 tmp;
        Node_418420* n;
        std_basic_string_char_char_traits_char_ctor_charP(&s, name);
        std_basic_string_char_char_traits_char_begin(&it, &s);
        std_basic_string_char_char_traits_char_end(&end, &s);
        while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
            if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
            std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
        }
        std_tree_pair_cString_value_compare_find_cStringR_5(&f, o, &s);
        n = f.n;
        std_map_cString_cFontPtr_end(&tmp, o);
        cAssocArray_cString_cFontPtr_Iterator_ctor(&e, &tmp);
        if (Ne_418420(n, e.n)) {
            int r = n->value;
            String_Dtor(&s, 0);
            return r;
        } else {
            int r = o->def;
            String_Dtor(&s, 0);
            return r;
        }
    }
}
#pragma bool reset
static inline void merge_flush_func_00418420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00418420 */

/* merge_units: begin func_00418580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cAssocArray_cString_cFontPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString_cFontPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_00418580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00418580 */

/* merge_units: begin func_004185A0 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_4185A0;
typedef struct { char* p; } It_4185A0;
typedef struct { Str_4185A0 first; int second; } Pair_4185A0;
typedef struct { void* it; unsigned char ok; } Res_4185A0;
typedef struct { char pad[0x10]; int def; } O_4185A0;
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_4185A0* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_418420 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(Str_4185A0* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_418420 *)(a0), (a1))) /* merge_units */

extern void std_basic_string_char_char_traits_char_ctor_basicstringR(Str_4185A0* d, Str_4185A0* s);
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_begin(It_4185A0* out, Str_4185A0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_begin(a0, a1) (std_basic_string_char_char_traits_char_begin((It_418420 *)(a0), (Str_418420 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_end(It_4185A0* out, Str_4185A0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_end(a0, a1) (std_basic_string_char_char_traits_char_end((It_418420 *)(a0), (Str_418420 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_4185A0* a, It_4185A0* b);
#endif /* merge_units */
#define std_opNe_wrapiteratorR_wrapiteratorR(a0, a1) (std_opNe_wrapiteratorR_wrapiteratorR((It_418420 *)(a0), (It_418420 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_4185A0* a);
#endif /* merge_units */
#define std_wrap_iterator_basic_string_char_charPtr_opMul(a0) (std_wrap_iterator_basic_string_char_charPtr_opMul((It_418420 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_4185A0* a);
#endif /* merge_units */
#define std_wrap_iterator_basic_string_char_charPtr_opInc(a0) (std_wrap_iterator_basic_string_char_charPtr_opInc((It_418420 *)(a0))) /* merge_units */

extern void std_make_pair_cString_cFontP(Pair_4185A0* out, Str_4185A0* k, int v);
extern void std_tree_pair_cString_value_compare_insert_one_pairR_5(Res_4185A0* out, O_4185A0* o, Pair_4185A0* p);

unsigned char GuiManager_AddFont(O_4185A0* o, char* name, int w, int force)
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
        std_basic_string_char_char_traits_char_ctor_charP(&s, name);
        std_basic_string_char_char_traits_char_begin(&it, &s);
        std_basic_string_char_char_traits_char_end(&end, &s);
        while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
            if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
            std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
        }
        std_basic_string_char_char_traits_char_ctor_basicstringR(&k, &s);
        std_make_pair_cString_cFontP(&p, &k, w);
        std_basic_string_char_char_traits_char_ctor_basicstringR(&q.first, &p.first);
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
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef String_Dtor /* merge_units */
#undef std_basic_string_char_char_traits_char_begin /* merge_units */
#undef std_basic_string_char_char_traits_char_end /* merge_units */
#undef std_opNe_wrapiteratorR_wrapiteratorR /* merge_units */
#undef std_wrap_iterator_basic_string_char_charPtr_opMul /* merge_units */
#undef std_wrap_iterator_basic_string_char_charPtr_opInc /* merge_units */
static inline void merge_flush_func_004185A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004185A0 */
