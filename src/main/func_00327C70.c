#include "types.h"

typedef struct String {
    int a, b, c;
} String;

typedef struct Obj84 {
    char pad[0x6C];
    String name;
    String desc;
    int value;
} Obj84;

extern void std_basic_string_char_char_traits_char_ctor_charP(String*, const char*);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String*, String*);
extern void String_Dtor(String*, int);

/* Sets two string fields and an int. */
void GuiSlideShow_SetInfo(Obj84* o, const char* name, const char* desc, int value) {
    String tmp2;
    String tmp1;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp1, name);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->name, &tmp1);
    String_Dtor(&tmp1, 0);
    std_basic_string_char_char_traits_char_ctor_charP(&tmp2, desc);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->desc, &tmp2);
    String_Dtor(&tmp2, 0);
    o->value = value;
}
