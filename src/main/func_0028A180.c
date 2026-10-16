#pragma cplusplus on
#include "types.h"
struct Str_0028A180 { char d[0x10]; };
struct Obj94_0028A180 { char pad[0x48]; Str_0028A180 name; };
struct S_0028A180 { char pad[0x94]; Obj94_0028A180* p94; };
extern "C" {
extern char D_004A9798[];
extern char D_004A97A8[];
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
char* String_CStr(Str_0028A180* s);
char* func_0033CE30(S_0028A180* self, int a, int b, int c, int d, int e);
void GuiKeyboard_Open(void* kb, char* title, char* text, S_0028A180* self, int a, int b, int c);
}
extern "C" void func_0028A180(S_0028A180* self)
{
    void* kb = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9798, D_004A97A8);
    if (kb) {
        char* text = String_CStr(&self->p94->name);
        GuiKeyboard_Open(kb, func_0033CE30(self, 0x28, 0, 0, 0, 0), text, self, 0xF, 0x22, 1);
    }
}
