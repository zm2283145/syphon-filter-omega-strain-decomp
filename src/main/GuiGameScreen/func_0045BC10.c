#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Dtor(char * , int);                         
int func_0013A040(char * , int);                         
int GuiWidget_Destroy(char **, int);                           
int operator_delete(char **);                            
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_BubbleType1();
extern void GuiWidget_BubbleType0();
extern void GuiWidget_BaseSleep();
extern void GuiWidget_BaseWake();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Load();
extern void GuiGameScreen_GetClassName();
extern void GuiGameScreen_IsType();
extern void GuiGameScreen_OnEvent();
extern void GuiGameScreen_OnInput();
extern void GuiGameScreen_Draw();
extern void GuiGameScreen_Update();
extern void GuiGameScreen_Deinit();
extern void GuiGameScreen_Init();
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
        GuiWidget_Destroy(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E1620[24] = { (void*)0x0, (void*)0x0, (void*)GuiGameScreen_dtor, (void*)GuiGameScreen_Init, (void*)GuiGameScreen_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiWidget_BaseWake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiGameScreen_OnInput, (void*)GuiGameScreen_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiGameScreen_Update, (void*)GuiGameScreen_OnEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiGameScreen_GetClassName, (void*)GuiGameScreen_IsType, (void*)0x0 };
