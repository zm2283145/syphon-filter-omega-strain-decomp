#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
typedef struct { char pad[0x4C]; char* x4C; char pad50[4]; void* x54; int x58; } KB_2B2D0;
extern char D_004B8CF0[];
extern char D_004B8CF8[];
extern void* GuiMessageBox_ValidateTarget_32D750(void*);
extern int Gui_GetScreenStack(void);
extern void GuiStack_SwapScreens(int, KB_2B2D0*, void*);
extern char* String_CStr(void*);
extern unsigned int strlen(const char*);
extern char* Mem_Alloc(int, int, char*, int);
extern void Mem_Free(int, void*, char*, int);
extern void String_Copy(char*, char*);
extern void GuiWidget_SendEvent(KB_2B2D0*, void*, int, int, char*);
void GuiKeyboard_Close(KB_2B2D0* k, int accept);
}
void GuiKeyboard_Close(KB_2B2D0* k, int accept)
{
    k->x54 = GuiMessageBox_ValidateTarget_32D750(k->x54);
    GuiStack_SwapScreens(Gui_GetScreenStack(), k, 0);
    if (accept) {
        char* src;
        int n;
        char* buf;
        char* p;
        int i;
        if (k->x4C) { char* t = String_CStr(k->x4C + 0x48); src = t; }
        else src = D_004B8CF0;
        n = strlen(src) + 1;
        { AllocGuard g; buf = Mem_Alloc(0, n, D_004B8CF8, 0x453); }
        String_Copy(buf, src);
        p = buf;
        while (*p && (unsigned char)*p <= 0x20) p++;
        i = strlen(p) - 1;
        while (i >= 0 && (unsigned char)p[i] <= 0x20) {
            p[i] = 0;
            i--;
        }
        GuiWidget_SendEvent(k, k->x54, 0x1A, k->x58, p);
        { AllocGuard g; Mem_Free(0, buf, D_004B8CF8, 0x45A); }
    } else {
        GuiWidget_SendEvent(k, k->x54, 0x1B, k->x58, 0);
    }
}
