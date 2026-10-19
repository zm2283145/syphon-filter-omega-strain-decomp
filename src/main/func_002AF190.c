#include "types.h"
typedef struct { int w[3]; } String;
typedef struct { int kind; String name; } Src;
typedef struct { char pad[0x100]; int kind; String name; } Item;
extern void* D_004FFC04;
extern char D_004ABCD0[];
extern void String_CtorCStr_13B480(String* dst, String* src);
extern void String_AssignString(String* dst, String* src);
extern void String_Dtor(String* s, int flags);
extern int GuiScreen_GetLobbyString(Item* it, int id, String* name, int a, int b, int c);
extern void FrontEnd_OpenPopup(void* mgr, int a, char* fmt, int v, Item* it, int b);
/* Copies kind and name from src, then registers the item. */
void func_002AF190(Item* it, Src* src)
{
    String tmp;
    void* mgr;
    it->kind = src->kind;
    String_CtorCStr_13B480(&tmp, &src->name);
    String_AssignString(&it->name, &tmp);
    String_Dtor(&tmp, 0);
    mgr = D_004FFC04;
    FrontEnd_OpenPopup(mgr, 5, D_004ABCD0, GuiScreen_GetLobbyString(it, 0x51, &src->name, 0, 0, 0), it, 0x12);
}
