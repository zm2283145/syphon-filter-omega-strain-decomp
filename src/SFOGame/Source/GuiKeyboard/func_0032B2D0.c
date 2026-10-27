#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
typedef struct { char pad[0x4C]; char* x4C; char pad50[4]; void* x54; int x58; } KB_2B2D0;
extern char D_004B8CF0[];
extern char D_004B8CF8[];
extern void* ValidateWidget_GuiWidgetP_2(void*);
extern int Gui_Canvas(void);
extern void GuiCanvas_Transition(int, KB_2B2D0*, void*);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
extern unsigned int strlen(const char*);
extern char* cMemMan_Allocate(int, int, char*, int);
extern void cMemMan_Deallocate(int, void*, char*, int);
extern void Libc_Strcpy(char*, char*);
extern void GuiWidget_SendMessage(KB_2B2D0*, void*, int, int, char*);
void GuiKeyboard_Close(KB_2B2D0* k, int accept);
}
void GuiKeyboard_Close(KB_2B2D0* k, int accept)
{
    k->x54 = ValidateWidget_GuiWidgetP_2(k->x54);
    GuiCanvas_Transition(Gui_Canvas(), k, 0);
    if (accept) {
        char* src;
        int n;
        char* buf;
        char* p;
        int i;
        if (k->x4C) { char* t = std_basic_string_char_char_traits_char_c_str(k->x4C + 0x48); src = t; }
        else src = D_004B8CF0;
        n = strlen(src) + 1;
        { AllocGuard g; buf = cMemMan_Allocate(0, n, D_004B8CF8, 0x453); }
        Libc_Strcpy(buf, src);
        p = buf;
        while (*p && (unsigned char)*p <= 0x20) p++;
        i = strlen(p) - 1;
        while (i >= 0 && (unsigned char)p[i] <= 0x20) {
            p[i] = 0;
            i--;
        }
        GuiWidget_SendMessage(k, k->x54, 0x1A, k->x58, p);
        { AllocGuard g; cMemMan_Deallocate(0, buf, D_004B8CF8, 0x45A); }
    } else {
        GuiWidget_SendMessage(k, k->x54, 0x1B, k->x58, 0);
    }
}
