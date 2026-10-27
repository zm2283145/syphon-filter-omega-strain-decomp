/*
 * Libs/SFOLib/Source/console: 2 files, 003E7CF0-003E7D60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E7CF0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int words[3]; } String;
typedef struct { char unk0; unsigned char unk1; unsigned char unk2; char pad; int unk4; int pad8; int index; char pad10[8]; String names[1]; } Obj;
static const unsigned int dat_004BDF28[2] = { 0x0, 0x0 };
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
extern void String_Dtor(String* s, int flags);

/* Sets defaults and resets the current name slot to ((char*)dat_004BDF28). */
void cConsole_Activate(Obj* self)
{
    String tmp;
    self->unk1 = 1;
    self->unk2 = 1;
    self->unk4 = 8;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, ((char*)dat_004BDF28));
    std_basic_string_char_char_traits_char_assign_basicstringR(&self->names[self->index], &tmp);
    String_Dtor(&tmp, 0);
}
static inline void merge_flush_func_003E7CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E7CF0 */

/* merge_units: begin func_003E7D60 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_E7D60* s, char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((String *)(a0), (const char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_assign_basicstringR(Str_E7D60* d, Str_E7D60* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_assign_basicstringR(a0, a1) (std_basic_string_char_char_traits_char_assign_basicstringR((String *)(a0), (String *)(a1))) /* merge_units */

extern void std_basic_string_char_char_traits_char_append_basicstringR(Str_E7D60* d, Str_E7D60* s);
#if 0 /* merge_units */
extern void String_Dtor(Str_E7D60* s, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((String *)(a0), (a1))) /* merge_units */


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
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_assign_basicstringR /* merge_units */
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_003E7D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E7D60 */
