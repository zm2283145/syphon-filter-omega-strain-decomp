/*
 * SFOGame/Source/GuiEndGameStatistics: 2 files, 00463040-00463060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00463040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */

#include "types.h"

Rel* func_00463040(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00463040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00463040 */

/* merge_units: begin func_00463060 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int GuiScoresEquip_dtor(char **, int);                           
int cFileMan_dtor(char * , int);                         
int func_00461DC0(char * , int);                         
int operator_delete(char **);                            
extern void GuiScoresEquip_onRender();
extern void GuiScoresEquip_onAdd();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onSleep();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void GuiEndGameStatistics_GetClassName();
extern void GuiEndGameStatistics_IsType();
extern void GuiEndGameStatistics_HandleInput();
extern void GuiEndGameStatistics_onAdvanceTime();
extern void GuiEndGameStatistics_FindFirstFocus();
extern void GuiEndGameStatistics_onMessage();
extern void GuiEndGameStatistics_onWake();
extern void * const D_004E1840[];

#pragma push
#pragma opt_common_subs off
char **GuiEndGameStatistics_dtor(char **arg0, long long arg1) {
    char * temp_a0;

    if (arg0 != NULL) {
        *arg0 = &(*(char*)D_004E1840);
        if (((char *)arg0 + 0x260) != 0) {
            if (((char *)arg0 + 0x280) != NULL) {
                cFileMan_dtor((char *)arg0 + 0x364, -1);
                cFileMan_dtor((char *)arg0 + 0x2C8, -1);
            }
            temp_a0 = (char *)arg0 + 0x260;
            if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
                func_00461DC0(temp_a0, 0);
            }
        }
        GuiScoresEquip_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}

#pragma pop
void * const D_004E1840[24] = { (void*)0x0, (void*)0x0, (void*)GuiEndGameStatistics_dtor, (void*)GuiScoresEquip_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiEndGameStatistics_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiEndGameStatistics_HandleInput, (void*)GuiScoresEquip_onRender, (void*)GuiWidget_onAction, (void*)GuiEndGameStatistics_onAdvanceTime, (void*)GuiEndGameStatistics_onMessage, (void*)GuiWidget_Load, (void*)GuiEndGameStatistics_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiEndGameStatistics_GetClassName, (void*)GuiEndGameStatistics_IsType, (void*)0x0 };
static inline void merge_flush_func_00463060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00463060 */
