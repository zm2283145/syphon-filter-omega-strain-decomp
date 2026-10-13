#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class S3569F0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int f54();
    char s4[0xC];
};
extern "C" {
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
int func_00418A80(void* mgr, char* a, char* b);
char* String_CStr(void* str);
void func_00354E40(int snd, int a, char* s, int b, int c, int d, int e);
void GuiStack_SwapScreens(void* mgr, void* self, int snd);
void func_003569F0(S3569F0* self, char* name, int b, int c, int d, int e);
}
void func_003569F0(S3569F0* self, char* name, int b, int c, int d, int e)
{
    int s = func_00418A80(Gui_GetScreenList(), "GuiPersonnelMenu", name);
    if (s) {
        char* str = String_CStr(self->s4);
        func_00354E40(s, self->f54(), str, b, c, d, e);
        GuiStack_SwapScreens(Gui_GetScreenStack(), self, s);
    }
}