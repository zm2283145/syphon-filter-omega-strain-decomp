#include "types.h"
typedef struct { int w[3]; } String;
typedef struct { int kind; String name; } Src;
typedef struct { char pad[0x100]; int kind; String name; } Item;
extern void* D_004FFC04;
extern char D_004ABCD0[];
extern void std_basic_string_char_char_traits_char_ctor_charP(String* dst, String* src);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
extern void String_Dtor(String* s, int flags);
extern int GuiLobbyScreen_GetLobbyString(Item* it, int id, String* name, int a, int b, int c);
extern void cGameFrontEnd_PushMessageBox(void* mgr, int a, char* fmt, int v, Item* it, int b);
/* Copies kind and name from src, then registers the item. */
void GuiNetAgencyCell_SelectAgentRemove(Item* it, Src* src)
{
    String tmp;
    void* mgr;
    it->kind = src->kind;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, &src->name);
    std_basic_string_char_char_traits_char_assign_basicstringR(&it->name, &tmp);
    String_Dtor(&tmp, 0);
    mgr = D_004FFC04;
    cGameFrontEnd_PushMessageBox(mgr, 5, D_004ABCD0, GuiLobbyScreen_GetLobbyString(it, 0x51, &src->name, 0, 0, 0), it, 0x12);
}
