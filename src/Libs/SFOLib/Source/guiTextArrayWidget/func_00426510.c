#include "types.h"

typedef struct { char b[0xC]; } String;
extern char D_004BF7B0[];
extern String* GuiTextArrayWidget_GetTextElement(void* a, void* b, void* c);
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
extern void String_Dtor(String* s, int flag);

/* Looks up a string slot and assigns text to it (empty default string when text is NULL). */
void GuiTextArrayWidget_SetText(void* a, void* b, void* c, const char* text)
{
    String tmp;
    String* slot = GuiTextArrayWidget_GetTextElement(a, b, c);
    if (slot) {
        String* t = &tmp;
        std_basic_string_char_char_traits_char_ctor_charP(t, text ? text : D_004BF7B0);
        std_basic_string_char_char_traits_char_assign_basicstringR(slot, &tmp);
        String_Dtor(&tmp, 0);
    }
}
