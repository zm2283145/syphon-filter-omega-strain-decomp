/*
 * SFOGame/Source/Loader: 4 files, 001BFCA0-001BFD60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BFCA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* clear(): count = 0. */
void std_vector_deleter_cSkaSwitchValue_clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_001BFCA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFCA0 */

/* merge_units: begin func_001BFCB0 */
#pragma push /* merge_units */
extern void cSkaSliderValue_dtor(void*, int);
typedef struct { char d[0x3C]; } G6E1B;
typedef struct { int x; int count; G6E1B* arr; } G6C1B;
void std_vector_deleter_cSkaSliderValue_clear(G6C1B* c)
{
    G6E1B* arr = c->arr;
    G6E1B* e = arr + c->count;
    while (arr < e) {
        --e;
        cSkaSliderValue_dtor(e, -1);
    }
    c->count = 0;
}
static inline void merge_flush_func_001BFCB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFCB0 */

/* merge_units: begin func_001BFD30 */
#pragma push /* merge_units */
#include "loose00_types.h"

#if 0 /* merge_units */
extern int Global_LoadAnimation(int anim);
#endif /* merge_units */
void Global_LoadAnimation(); /* merge_units */


/* Script native: LoadAnimation(id). */
int Script_LoadAnimation(ScriptArg* args) {
    volatile int anim = args[0].i; /* stored to the stack and reloaded */

    Global_LoadAnimation(anim);
    return 0;
}
static inline void merge_flush_func_001BFD30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BFD30 */

/* merge_units: begin human_1BFD60 */
#pragma push /* merge_units */
typedef struct { unsigned int word; unsigned int length; char* data; } Str_1BFD60;
typedef struct { char* p; } It_1BFD60;
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_1BFD60* s, char* c);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(Str_1BFD60* d, Str_1BFD60* s);
extern void String_Dtor(Str_1BFD60* s, int f);
extern void std_basic_string_char_char_traits_char_begin(It_1BFD60* out, Str_1BFD60* s);
extern void std_basic_string_char_char_traits_char_end(It_1BFD60* out, Str_1BFD60* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_1BFD60* a, It_1BFD60* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_1BFD60* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_1BFD60* a);
extern char* std_basic_string_char_char_traits_char_c_str(Str_1BFD60* s);
extern void cLoader_LoadSingleAnimation_FromHogWithLevelSpecificAnimations(void* mgr, char* name);
extern void* D_004FFBD8;
static inline void Ctor_1BFD60(Str_1BFD60* s) { s->word = 0; s->length = 0; s->data = 0; }

#pragma opt_propagation off
void Global_LoadAnimation(char* name)
{
    It_1BFD60 it;
    It_1BFD60 end;
    Str_1BFD60 s;
    { Str_1BFD60* ps = &s; ps->word = 0; ps->length = 0; ps->data = 0; }
    if (name[0]) {
        Str_1BFD60 t;
        std_basic_string_char_char_traits_char_ctor_charP(&t, name);
        std_basic_string_char_char_traits_char_assign_basicstringR(&s, &t);
        String_Dtor(&t, 0);
        std_basic_string_char_char_traits_char_begin(&it, &s);
        std_basic_string_char_char_traits_char_end(&end, &s);
        while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
            if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
            std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
        }
    } else {
        Str_1BFD60 t2;
        std_basic_string_char_char_traits_char_ctor_charP(&t2, name);
        std_basic_string_char_char_traits_char_assign_basicstringR(&s, &t2);
        String_Dtor(&t2, 0);
    }
    cLoader_LoadSingleAnimation_FromHogWithLevelSpecificAnimations(D_004FFBD8, std_basic_string_char_char_traits_char_c_str(&s));
    String_Dtor(&s, 0);
}
static inline void merge_flush_human_1BFD60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end human_1BFD60 */
