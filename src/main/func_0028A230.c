#pragma cplusplus on
#include "types.h"
struct Str_0028A230 { char d[0x10]; };
struct Obj8C_0028A230 { char pad[0x48]; Str_0028A230 name; };
struct S_0028A230 { char pad[0x8C]; Obj8C_0028A230* p8C; char pad90[0x14]; unsigned char bA4; };
extern "C" {
extern void* D_004FFC04;
extern char D_004A9798[];
extern char D_004A97A8[];
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
char* String_CStr(Str_0028A230* s);
char* func_0033CE30(S_0028A230* self, int a, int b, int c, int d, int e);
void GuiKeyboard_Open(void* kb, char* title, char* text, S_0028A230* self, int a, int b, int c);
void String_CtorCStr_13B480(Str_0028A230* s, const char* c);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_0028A230* d, int e);
void String_Dtor(Str_0028A230* s, int flags);
}
extern "C" void func_0028A230(S_0028A230* self)
{
    if (self->bA4) {
        void* kb = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9798, D_004A97A8);
        if (kb) {
            char* text = String_CStr(&self->p8C->name);
            GuiKeyboard_Open(kb, func_0033CE30(self, 0x27, 0, 0, 0, 0), text, self, 0xF, 0x21, 1);
        }
    } else {
        Str_0028A230 a;
        Str_0028A230 b;
        String_CtorCStr_13B480(&a, func_0033CE30(self, 0x29, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(self, 0x2A, 0, 0, 0, 0));
        {
            char* tb = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, self, 0x25);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
}
