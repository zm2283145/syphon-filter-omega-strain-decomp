#include "types.h"
typedef struct { char pad[0xE4]; int fE4; } S_32AFE0;
typedef struct { char pad[0x20]; void* f20; } M_32AFE0;
char D_004B8CB8[] = "onGainFocus"; void* func_0032B260(S_32AFE0* o, int id);
void func_0041E0F0(void* a, void* b, int kind, int v, int f);
M_32AFE0* Gui_GetScreenStack(void);
int String_AssignCStr_1C43A0(char* a, char* b);

void func_0032AFE0(S_32AFE0* o)
{
    int i;
    for (i = 0; i < 4; i++) {
        void* w = 0;
        unsigned char on;
        char* str;
        switch (i) {
        case 0: w = func_0032B260(o, 0x3EA); break;
        case 1: w = func_0032B260(o, 0x408); break;
        case 2: w = func_0032B260(o, 0x39); break;
        case 3: w = func_0032B260(o, 0x3EC); break;
        }
        if (w == 0) continue;
        str = 0;
        func_0041E0F0(o, w, 4, 0, (int)&str);
        on = 0;
        switch (i) {
        case 0:
        case 1: if (o->fE4 & 1) on = 1; break;
        case 2: if (o->fE4 & 2) on = 1; break;
        case 3: if (o->fE4 & 4) on = 1; break;
        }
        if (Gui_GetScreenStack()->f20 == w) {
            if (str == 0 || String_AssignCStr_1C43A0(str, D_004B8CB8)) func_0041E0F0(o, w, 6, (int)D_004B8CB8, 0);
        } else if (on) {
            if (str == 0 || String_AssignCStr_1C43A0(str, "onPressed")) func_0041E0F0(o, w, 0xC, 0xD, 0);
        } else {
            if (str == 0 || (String_AssignCStr_1C43A0(str, "onLoseFocus") && String_AssignCStr_1C43A0(str, "onWake"))) func_0041E0F0(o, w, 6, (int)"onLoseFocus", 0);
        }
    }
}