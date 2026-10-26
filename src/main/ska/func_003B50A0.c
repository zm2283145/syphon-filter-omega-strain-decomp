#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_50A0;
typedef struct { char* p; } It_50A0;
typedef struct { char pad[0x148]; struct { int a; int n; }* p148; } Obj_50A0;
extern int Hog_GetMemberInPlace(Obj_50A0* o, int i);
extern char* Archive_GetMemberName(Obj_50A0* o, int i);
extern void String_CtorCStr_13B480(Str_50A0* s, char* c);
extern void String_Dtor(Str_50A0* s, int f);
extern void std_basic_string_char_char_traits_char_begin(It_50A0* out, Str_50A0* s);
extern void std_basic_string_char_char_traits_char_end(It_50A0* out, Str_50A0* s);
extern int std_opNe_wrapiteratorR_wrapiteratorR(It_50A0* a, It_50A0* b);
extern char* std_wrap_iterator_basic_string_char_charPtr_opMul(It_50A0* a);
extern void std_wrap_iterator_basic_string_char_charPtr_opInc(It_50A0* a);
extern int std_basic_string_char_char_traits_char_rfind_basicstringR_uint(Str_50A0* s, Str_50A0* t, int n);
extern void cString_Substr(Str_50A0* out, Str_50A0* s, int a, int b);
extern int String_Length(Str_50A0* s);
extern char* String_CStr_Thunk(Str_50A0* s);
extern void Skas_RegisterClip(int* out, void* self, char* name, int clip);
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
        int clip = Hog_GetMemberInPlace(o, i);
        if (clip) {
            int idx;
            String_CtorCStr_13B480(&s, Archive_GetMemberName(o, i));
            std_basic_string_char_char_traits_char_begin(&it, &s);
            std_basic_string_char_char_traits_char_end(&end, &s);
            while (std_opNe_wrapiteratorR_wrapiteratorR(&it, &end)) {
                if (*std_wrap_iterator_basic_string_char_charPtr_opMul(&it) >= 'A' && *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) <= 'Z') *std_wrap_iterator_basic_string_char_charPtr_opMul(&it) += 0x20;
                std_wrap_iterator_basic_string_char_charPtr_opInc(&it);
            }
            String_CtorCStr_13B480(&t, D_004BCD78);
            idx = std_basic_string_char_char_traits_char_rfind_basicstringR_uint(&s, &t, -1);
            String_Dtor(&t, 0);
            if (idx != -1) {
                int j;
                cString_Substr(&u, &s, 0, idx);
                for (j = 0; j < 47; j++) {
                    name[j] = (j < String_Length(&u)) ? String_CStr_Thunk(&u)[j] : 0;
                }
                name[j] = 0;
                String_Dtor(&u, 0);
                Skas_RegisterClip(&r, self, name, clip);
            }
            String_Dtor(&s, 0);
        }
    }
}
