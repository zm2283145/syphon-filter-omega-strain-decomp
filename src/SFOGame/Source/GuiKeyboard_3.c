/*
 * SFOGame/Source/GuiKeyboard: 3 files, 0032B260-0032B4F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiKeyboard_32B260 */
#pragma push /* merge_units */
#include "types.h"
#pragma opt_strength_reduction off
typedef struct { char p0[0x68]; int* vals; char p6C[0x74 - 0x6C]; int count; int* keys; } T32B260;
int GuiKeyboard_FindKey(T32B260* t, int key)
{
    int i; int* keys;
    i = 0;
    if (i < *(volatile int*)&t->count) {
        keys = t->keys;
        do {
            if (key == keys[i]) return t->vals[i];
            i++;
        } while (i < *(volatile int*)&t->count);
    }
    return 0;
}
static inline void merge_flush_GuiKeyboard_32B260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiKeyboard_32B260 */

/* merge_units: begin func_0032B2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_0032B2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032B2D0 */

/* merge_units: begin func_0032B4F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class Stk { public: VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Push(void* o, int pri); };
struct Dlg { char p0[0x48]; void* title; void* body; int f50; int f54; int f58; char p5c[0xE0 - 0x5C]; unsigned char fE0; };
extern "C" {
void GuiTextWidget_SetText(void* w, char* s, int a);
void GuiTextEditWidget_SetCursorPos(void* w, int a);
#if 0 /* merge_units */
Stk* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Stk *)Gui_Canvas()) /* merge_units */

}
extern "C" void GuiKeyboard_Display(Dlg* d, char* title, char* body, int a, int b, int c, unsigned char e)
{
    if (d->title) GuiTextWidget_SetText(d->title, title ? title : D_004B8CF0, 0);
    if (d->body) {
        GuiTextWidget_SetText(d->body, body ? body : D_004B8CF0, 0);
        GuiTextEditWidget_SetCursorPos(d->body, -1);
    }
    d->f54 = a;
    d->f58 = c;
    d->f50 = b;
    d->fE0 = e;
    Gui_Canvas()->Push(d, 100);
}
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_0032B4F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032B4F0 */
