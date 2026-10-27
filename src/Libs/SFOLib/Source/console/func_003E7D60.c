#include "types.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_E7D60;
typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    char pad3[5];
    int w8;
    int wC;
    char pad10[8];
    Str_E7D60 lines[0x16];
    Str_E7D60 more[0x14];
    char pad210[8];
    int w218;
    int w21C;
    int w220;
} Con_E7D60;
extern char D_004BDF30[];
extern char D_004BDF50[];
extern void __construct_array(void* arr, void (*ctor)(void*), void (*dtor)(void*), int size, int count);
extern void cString_ctor_void(void*);
extern void String_Dtor_138350(void*);
extern void std_basic_string_char_char_traits_char_reserve(Str_E7D60* s, int n);
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_E7D60* s, char* c);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(Str_E7D60* d, Str_E7D60* s);
extern void std_basic_string_char_char_traits_char_append_basicstringR(Str_E7D60* d, Str_E7D60* s);
extern void String_Dtor(Str_E7D60* s, int f);

Con_E7D60* cConsole_ctor(Con_E7D60* self, char* name, int x)
{
    int i;
    int off;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->w8 = 0;
    __construct_array(self->lines, cString_ctor_void, String_Dtor_138350, 0xC, 0x16);
    __construct_array(self->more, cString_ctor_void, String_Dtor_138350, 0xC, 0x14);
    self->w21C = 0;
    self->w220 = x;
    for (i = 0, off = 0; i < 0x16; i++, off += 0xC)
        std_basic_string_char_char_traits_char_reserve(((Con_E7D60*)((unsigned)self + off))->lines, 100);
    {
        Str_E7D60 t;
        std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BDF30);
        std_basic_string_char_char_traits_char_assign_basicstringR(&self->lines[0], &t);
        String_Dtor(&t, 0);
    }
    {
        Str_E7D60 t;
        std_basic_string_char_char_traits_char_ctor_charP(&t, name);
        std_basic_string_char_char_traits_char_append_basicstringR(&self->lines[0], &t);
        String_Dtor(&t, 0);
    }
    {
        Str_E7D60 t;
        std_basic_string_char_char_traits_char_ctor_charP(&t, D_004BDF50);
        std_basic_string_char_char_traits_char_assign_basicstringR(&self->lines[1], &t);
        String_Dtor(&t, 0);
    }
    self->wC = 2;
    self->w218 = 0;
    return self;
}


