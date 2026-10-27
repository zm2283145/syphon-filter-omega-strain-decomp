#include "types.h"
typedef struct { char pad[0xE4]; int fE4; } S_32AFE0;
typedef struct { char pad[0x20]; void* f20; } M_32AFE0;
char D_004B8CB8[] = "onGainFocus"; void* GuiKeyboard_FindKey(S_32AFE0* o, int id);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
M_32AFE0* Gui_Canvas(void);
int std_basic_string_char_char_traits_char_compare_charP(char* a, char* b);

void GuiKeyboard_UpdateStateKeys(S_32AFE0* o)
{
    int i;
    for (i = 0; i < 4; i++) {
        void* w = 0;
        unsigned char on;
        char* str;
        switch (i) {
        case 0: w = GuiKeyboard_FindKey(o, 0x3EA); break;
        case 1: w = GuiKeyboard_FindKey(o, 0x408); break;
        case 2: w = GuiKeyboard_FindKey(o, 0x39); break;
        case 3: w = GuiKeyboard_FindKey(o, 0x3EC); break;
        }
        if (w == 0) continue;
        str = 0;
        GuiWidget_SendMessage(o, w, 4, 0, (int)&str);
        on = 0;
        switch (i) {
        case 0:
        case 1: if (o->fE4 & 1) on = 1; break;
        case 2: if (o->fE4 & 2) on = 1; break;
        case 3: if (o->fE4 & 4) on = 1; break;
        }
        if (Gui_Canvas()->f20 == w) {
            if (str == 0 || std_basic_string_char_char_traits_char_compare_charP(str, D_004B8CB8)) GuiWidget_SendMessage(o, w, 6, (int)D_004B8CB8, 0);
        } else if (on) {
            if (str == 0 || std_basic_string_char_char_traits_char_compare_charP(str, "onPressed")) GuiWidget_SendMessage(o, w, 0xC, 0xD, 0);
        } else {
            if (str == 0 || (std_basic_string_char_char_traits_char_compare_charP(str, "onLoseFocus") && std_basic_string_char_char_traits_char_compare_charP(str, "onWake"))) GuiWidget_SendMessage(o, w, 6, (int)"onLoseFocus", 0);
        }
    }
}