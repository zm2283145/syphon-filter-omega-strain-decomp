/*
 * main/game: 3 files, 0013B340-0013B480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013B340 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_int_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0013B340 */

/* merge_units: begin func_0013B430 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x20]; char flag; char pad2[0xBF]; } G6E13;
typedef struct { int x; int count; G6E13* arr; } G6C13;
void std_vector_deleter_cLosRequest_cCollisionModelList_Game_clear(G6C13* c)
{
    G6E13* arr = c->arr;
    G6E13* e = arr + c->count;
    while (arr < e) {
        --e;
        if (e) e->flag = 0;
    }
    c->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B430 */

/* merge_units: begin func_0013B480 */
#pragma push /* merge_units */
/* String object: three words, zeroed before construction. */
typedef struct StrObj {
    int w0;
    int w1;
    int w2;
} StrObj;

extern int strlen(const char* s); /* strlen */
extern void std_basic_string_char_char_traits_char_reserve(StrObj* str, int capacity);
extern void std_basic_string_char_char_traits_char_do_replace(StrObj* str, int pos, int count, const char* first, const char* last, char alloc);

/* String constructor from a C string. */
StrObj* std_basic_string_char_char_traits_char_ctor_charP(StrObj* self, const char* cstr) {
    volatile char alloc[4];
    int len;
    self->w0 = 0;
    self->w1 = 0;
    self->w2 = 0;
    len = strlen(cstr);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, cstr, cstr + len, alloc[0]);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B480 */
