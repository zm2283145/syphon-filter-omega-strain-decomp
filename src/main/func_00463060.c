#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int GuiScoresEquip_dtor(char **, int);                           
int FileMan_Release(char * , int);                         
int func_00461DC0(char * , int);                         
int operator_delete(char **);                            
extern void GuiScoresEquip_Draw();
extern void GuiScoresEquip_Init();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_BubbleType1();
extern void GuiWidget_BubbleType0();
extern void GuiWidget_BaseSleep();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void GuiWidget_Load();
extern void GuiEndGameStatistics_GetClassName();
extern void GuiEndGameStatistics_IsType();
extern void GuiEndGameStatistics_HandleInput();
extern void GuiEndGameStatistics_Update();
extern void GuiEndGameStatistics_First();
extern void GuiEndGameStatistics_HandleEvent();
extern void GuiEndGameStatistics_Wake();
extern void * const D_004E1840[];

#pragma push
#pragma opt_common_subs off
char **GuiEndGameStatistics_dtor(char **arg0, long long arg1) {
    char * temp_a0;

    if (arg0 != NULL) {
        *arg0 = &(*(char*)D_004E1840);
        if (((char *)arg0 + 0x260) != 0) {
            if (((char *)arg0 + 0x280) != NULL) {
                FileMan_Release((char *)arg0 + 0x364, -1);
                FileMan_Release((char *)arg0 + 0x2C8, -1);
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
void * const D_004E1840[24] = { (void*)0x0, (void*)0x0, (void*)GuiEndGameStatistics_dtor, (void*)GuiScoresEquip_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiEndGameStatistics_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiEndGameStatistics_HandleInput, (void*)GuiScoresEquip_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiEndGameStatistics_Update, (void*)GuiEndGameStatistics_HandleEvent, (void*)GuiWidget_Load, (void*)GuiEndGameStatistics_First, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiEndGameStatistics_GetClassName, (void*)GuiEndGameStatistics_IsType, (void*)0x0 };
