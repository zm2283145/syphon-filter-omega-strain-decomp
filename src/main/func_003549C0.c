#include "types.h"
typedef struct { char pad[0x6C]; char s6C[0xC]; char s78[0xC]; signed char a84; char pad85[3]; int a88; } S3549C0;
extern int GuiAchievementScreen_Construct(int id);
extern char* std_basic_string_char_char_traits_char_c_str(void* str);
extern void* Gui_Manager(void);
extern void* Gui_Canvas(void);
extern int GuiManager_OpenGui(void* mgr, char* a, char* b);
extern void GuiWidget_SendMessage(void* self, int a, int b, int c, int d);
extern void GuiCanvas_Transition(void* mgr, void* self, int snd);
void GuiPersonnelMenu_PreviousScreen(S3549C0* o)
{
    int s = GuiAchievementScreen_Construct(o->a84);
    if (!s) {
        char* b = std_basic_string_char_char_traits_char_c_str(o->s78);
        char* a = std_basic_string_char_char_traits_char_c_str(o->s6C);
        s = GuiManager_OpenGui(Gui_Manager(), a, b);
    }
    if (s) {
        GuiWidget_SendMessage(o, s, 0x3000, o->a88, 0);
        GuiCanvas_Transition(Gui_Canvas(), o, s);
    }
}
