#include "types.h"

typedef struct { char b[0xC]; } String;
extern char D_004BF7B0[];
extern String* GuiTextArrayWidget_GetCell(void* a, void* b, void* c);
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_0013D680(String* dst, String* src);
extern void String_Dtor(String* s, int flag);

/* Looks up a string slot and assigns text to it (empty default string when text is NULL). */
void GuiTextArrayWidget_SetCellText(void* a, void* b, void* c, const char* text)
{
    String tmp;
    String* slot = GuiTextArrayWidget_GetCell(a, b, c);
    if (slot) {
        String* t = &tmp;
        String_CtorCStr_13B480(t, text ? text : D_004BF7B0);
        func_0013D680(slot, &tmp);
        String_Dtor(&tmp, 0);
    }
}
