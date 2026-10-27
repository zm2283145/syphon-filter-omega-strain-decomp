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
