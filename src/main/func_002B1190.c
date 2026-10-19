#include "types.h"
extern char D_004ABEB8[];
extern char D_004ABEC8[];
extern char D_004ABED0[];
extern char D_00587C90[];
extern char* g_Hud;
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(char* key);
extern char* Loc_GetTextById(int id);
extern char* Loc_GetStoredKey(int id);
extern void String_Copy(char* d, const char* s);
extern void Notify_Insert(void* list, char* text, void* a, int b, int c);
#pragma opt_propagation off
void func_002B1190(int a, int b, int id)
{
    char name[0x20];
    char key[0x20];
    char out[0x200];
    char* fmt;
    char* txt;
    char* p;
    char* np = name;
    np[0] = 0;
    key[0] = 0;
    sprintf(key, D_004ABEB8, 0x1E, a, b);
    fmt = Loc_LookupText(key);
    txt = 0;
    if (id > 0)
        txt = Loc_GetTextById(id);
    p = Loc_GetStoredKey(id);
    if (p)
        String_Copy(np, p);
    sprintf(out, D_004ABEC8, fmt, txt ? txt : D_004ABED0);
    Notify_Insert(g_Hud + 0x100, out, D_00587C90, 1, 0);
}


#pragma opt_propagation reset

