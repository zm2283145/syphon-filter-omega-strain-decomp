#include "types.h"
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



