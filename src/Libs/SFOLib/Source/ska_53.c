/*
 * Libs/SFOLib/Source/ska: 2 files, 003B50A0-003B52B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B50A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_50A0;
typedef struct { char* p; } It_50A0;
typedef struct { char pad[0x148]; struct { int a; int n; }* p148; } Obj_50A0;
extern int cHogFile_GetBlock_int(Obj_50A0* o, int i);
extern char* cHogFile_GetBlockName(Obj_50A0* o, int i);
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_50A0* s, char* c);
extern void String_Dtor(Str_50A0* s, int f);
extern void std_basic_string_char_char_traits_char_begin(It_50A0* out, Str_50A0* s);
extern void std_basic_string_char_char_traits_char_end(It_50A0* out, Str_50A0* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_50A0* a, It_50A0* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_50A0* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_50A0* a);
extern int std_basic_string_char_char_traits_char_rfind_basicstringR_uint(Str_50A0* s, Str_50A0* t, int n);
#if 0 /* merge_units */
extern void cString_Substr(Str_50A0* out, Str_50A0* s, int a, int b);
#endif /* merge_units */
int cString_Substr(); /* merge_units */

extern int cString_Length(Str_50A0* s);
extern char* cString_opCast_constcharPtr(Str_50A0* s);
extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(int* out, void* self, char* name, int clip);
extern char D_004BCD78[];

void cSkaAnimationSet_AddAllAnimationsFromSkaHog(void* self, Obj_50A0* o)
{
    int r;
    It_50A0 it;
    It_50A0 end;
    Str_50A0 s;
    Str_50A0 t;
    Str_50A0 u;
    char name[0x30];
    int n = o->p148->n;
    int i;
    for (i = 0; i < n; i++) {
        int clip = cHogFile_GetBlock_int(o, i);
        if (clip) {
            int idx;
            std_basic_string_char_char_traits_char_ctor_charP(&s, cHogFile_GetBlockName(o, i));
            std_basic_string_char_char_traits_char_begin(&it, &s);
            std_basic_string_char_char_traits_char_end(&end, &s);
            while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
                if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
                std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
            }
            std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BCD78);
            idx = std_basic_string_char_char_traits_char_rfind_basicstringR_uint(&s, &t, -1);
            String_Dtor(&t, 0);
            if (idx != -1) {
                int j;
                cString_Substr(&u, &s, 0, idx);
                for (j = 0; j < 47; j++) {
                    name[j] = (j < cString_Length(&u)) ? cString_opCast_constcharPtr(&u)[j] : 0;
                }
                name[j] = 0;
                String_Dtor(&u, 0);
                cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(&r, self, name, clip);
            }
            String_Dtor(&s, 0);
        }
    }
}
static inline void merge_flush_func_003B50A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B50A0 */

/* merge_units: begin func_003B52B0 */
#pragma push /* merge_units */
extern void std_basic_string_char_char_traits_char_substr(void* tmp);
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(void* self, void* tmp);
#if 0 /* merge_units */
extern void String_Dtor(void* tmp, int flag);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_50A0 *)(a0), (a1))) /* merge_units */


/* Builds a temporary object, applies it to self, then destroys it; returns 0. */
int cString_Substr(void* self) {
    char tmp[16];
    std_basic_string_char_char_traits_char_substr(tmp);
    std_basic_string_char_char_traits_char_ctor_basicstringR(self, tmp);
    String_Dtor(tmp, -1);
    return 0;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_003B52B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B52B0 */
