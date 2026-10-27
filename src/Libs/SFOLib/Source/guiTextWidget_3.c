/*
 * main/guiTextWidget: range (2 files, 0041C6A0-0041C7D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_0041C6A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int String_Dtor(...);                         
int GuiWidget_dtor(...);                         
int operator_delete(...);                          
extern char D_004BF2D0;
extern "C" void GuiTextWidget_IsClass();
extern "C" void GuiWidget_onInput();
extern "C" void GuiTextWidget_GetClassName();
extern "C" void GuiTextWidget_UpdateText();
extern "C" void GuiTextWidget_onRender();
extern "C" void GuiTextWidget_onSleep();
extern "C" void GuiTextWidget_onWake();
extern "C" void GuiTextWidget_Load();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern void * const D_004E0AC0[];
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * GuiTextWidget_dtor(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E0AC0));
        temp_s2 = F_(arg0, 0x78, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            if (temp_s2 != 0) {
                temp_a0 = (char *)(temp_s2 + 0x14);
                if (temp_a0 != NULL) {
                    String_Dtor(temp_a0, 0);
                }
            }
            cMemMan_Deallocate(0, temp_s2, &D_004BF2D0, 0x23);
            }
        }
        temp_a0_2 = arg0 + 0x48;
        if (temp_a0_2 != NULL) {
            String_Dtor(temp_a0_2, 0);
        }
        GuiWidget_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E0AC0[24] = { (void*)0x0, (void*)0x0, (void*)GuiTextWidget_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiTextWidget_onWake, (void*)GuiTextWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiWidget_onInput, (void*)GuiTextWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiTextWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiTextWidget_GetClassName, (void*)GuiTextWidget_IsClass, (void*)GuiTextWidget_UpdateText };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C6A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C6A0 */

/* merge_units: begin func_0041C7D0 */
#pragma push /* merge_units */
typedef struct { char p[0x11]; unsigned char b11, b12; } S41C7D0;
typedef struct { void* vt; char p4[0x44]; int f48; int f4C; int f50; int f54; char p58[8]; float f60, f64, f68; char p6C[4]; int f70; unsigned char b74, b75, b76; char p77; S41C7D0* f78; } W41C7D0;
extern void GuiWidget_ctor(W41C7D0* w);
#if 0 /* merge_units */
extern char D_004E0AC0[];
#endif /* merge_units */
#define D_004E0AC0 ((char*)&D_004E0AC0) /* merge_units */

W41C7D0* GuiTextWidget_ctor(W41C7D0* w)
{
    GuiWidget_ctor(w);
    w->vt = D_004E0AC0;
    w->f48 = 0;
    w->f4C = 0;
    w->f50 = 0;
    w->f68 = 1.0f;
    w->f64 = 1.0f;
    w->f60 = 1.0f;
    w->f54 = 0;
    w->f70 = 0;
    w->f78 = 0;
    w->b75 = 0;
    w->b76 = 0;
    w->b74 = 0;
    if (w->f78) {
        w->f78->b12 = w->b74 == 0;
        w->f78->b11 = w->b74 == 2;
    }
    return w;
}
#undef D_004E0AC0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0041C7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0041C7D0 */
