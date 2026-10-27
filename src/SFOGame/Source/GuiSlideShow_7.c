/*
 * SFOGame/Source/GuiSlideShow: 2 files, 003282A0-00328310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003282A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void*);
extern "C" void String_Dtor(void*, short);
extern "C" void* GuiSlideShow_Slide_dtor(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0x10;
        if (m) String_Dtor(m, 0);
        if (self) String_Dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003282A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003282A0 */

/* merge_units: begin func_00328310 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } Str_328310;
typedef struct { int a, b, c, d; } Sub_328310;
typedef struct { Str_328310 name; Sub_328310 sub; int x; } E_328310;
typedef struct {
    char pad[0x48];
    char v48[4];
    int n4C;
    E_328310* v50;
} O_328310;
extern char D_004B8790[];
void cString_ctor_void(void* s);
void cArray_Slide_ctor(void* s);
void std_basic_string_char_char_traits_char_ctor_charP(Str_328310* s, char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_328310* d, Str_328310* s);
#if 0 /* merge_units */
void String_Dtor(void* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((a0), (short)(a1))) /* merge_units */

void std_vector_imp_Section_insert(void* v, E_328310* pos, int n, E_328310* e);
void std_vector_deleter_Slide_dtor(void* s, int f);

int GuiSlideShow_AddSection(O_328310* o, char* s)
{
    E_328310 e;
    Str_328310 t;
    int r;
    Sub_328310* m;
    cString_ctor_void(&e);
    m = &e.sub;
    cArray_Slide_ctor(m);
    { Str_328310* p = &t; std_basic_string_char_char_traits_char_ctor_charP(p, s ? s : D_004B8790); }
    std_basic_string_char_char_traits_char_assign_basicstringR(&e.name, &t);
    String_Dtor(&t, 0);
    e.x = 0;
    std_vector_imp_Section_insert(o->v48, o->v50 + o->n4C, 1, &e);
    r = o->n4C - 1;
    if (m) {
        if (m) {
            if (m) std_vector_deleter_Slide_dtor(m, 0);
        }
    }
    String_Dtor(&e, 0);
    return r;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_00328310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328310 */
