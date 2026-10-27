/*
 * main/guiManager: 2 files, 004183A0-00418420
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
extern void std_map_cString_cFontPtr_end(MIt_418420* out, O_418420* o);
extern void cAssocArray_cString_cFontPtr_Iterator_ctor(MIt_418420* out, MIt_418420* src);

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
#pragma pop /* merge_units */
/* merge_units: end func_00418420 */
