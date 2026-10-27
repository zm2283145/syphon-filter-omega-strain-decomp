#include "types.h"
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
