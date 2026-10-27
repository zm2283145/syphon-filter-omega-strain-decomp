/*
 * SFOGame/Source/flashlight: 1 file, 0045BC10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045BC10 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Dtor(char * , int);                         
int func_0013A040(char * , int);                         
int GuiWidget_dtor(char **, int);                           
int operator_delete(char **);                            
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onSleep();
extern void GuiWidget_onWake();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_Load();
extern void GuiGameScreen_GetClassName();
extern void GuiGameScreen_IsClass();
extern void GuiGameScreen_onMessage();
extern void GuiGameScreen_onInput();
extern void GuiGameScreen_onRender();
extern void GuiGameScreen_onAdvanceTime();
extern void GuiGameScreen_onRemove();
extern void GuiGameScreen_onAdd();
extern void * const D_004E1620[];

char **GuiGameScreen_dtor(char **arg0, long long arg1) {
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (char *)arg0 + 0x80;
        *arg0 = &(*(char*)D_004E1620);
        if (temp_a0 != NULL) {
            func_0013A040(temp_a0, -1);
        }
        temp_a0_2 = (char *)arg0 + 0x70;
        if (temp_a0_2 != NULL) {
            func_0013A040(temp_a0_2, -1);
        }
        temp_a0_3 = (char *)arg0 + 0x58;
        if (temp_a0_3 != NULL) {
            String_Dtor(temp_a0_3, 0);
        }
        GuiWidget_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E1620[24] = { (void*)0x0, (void*)0x0, (void*)GuiGameScreen_dtor, (void*)GuiGameScreen_onAdd, (void*)GuiGameScreen_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiWidget_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiGameScreen_onInput, (void*)GuiGameScreen_onRender, (void*)GuiWidget_onAction, (void*)GuiGameScreen_onAdvanceTime, (void*)GuiGameScreen_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiGameScreen_GetClassName, (void*)GuiGameScreen_IsClass, (void*)0x0 };
static inline void merge_flush_func_0045BC10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045BC10 */
