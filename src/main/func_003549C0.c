#include "types.h"
typedef struct { char pad[0x6C]; char s6C[0xC]; char s78[0xC]; signed char a84; char pad85[3]; int a88; } S3549C0;
extern int func_003534A0(int id);
extern char* String_CStr(void* str);
extern void* Gui_GetScreenList(void);
extern void* Gui_GetScreenStack(void);
extern int func_00418A80(void* mgr, char* a, char* b);
extern void func_0041E0F0(void* self, int a, int b, int c, int d);
extern void GuiStack_SwapScreens(void* mgr, void* self, int snd);
void func_003549C0(S3549C0* o)
{
    int s = func_003534A0(o->a84);
    if (!s) {
        char* b = String_CStr(o->s78);
        char* a = String_CStr(o->s6C);
        s = func_00418A80(Gui_GetScreenList(), a, b);
    }
    if (s) {
        func_0041E0F0(o, s, 0x3000, o->a88, 0);
        GuiStack_SwapScreens(Gui_GetScreenStack(), o, s);
    }
}
