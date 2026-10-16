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
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041EBF0();
extern void func_0041EFA0();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F210();
extern void func_0045BCC0();
extern void func_0045BCD0();
extern void GuiGameScreen_OnEvent();
extern void GuiGameScreen_OnInput();
extern void GuiGameScreen_Draw();
extern void GuiGameScreen_Update();
extern void func_0045DE80();
extern void GuiGameScreen_Init();
extern void * const D_004E1620[];

char **func_0045BC10(char **arg0, long long arg1) {
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
void * const D_004E1620[24] = { (void*)0x0, (void*)0x0, (void*)func_0045BC10, (void*)GuiGameScreen_Init, (void*)func_0045DE80, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)GuiGameScreen_OnInput, (void*)GuiGameScreen_Draw, (void*)func_0041E230, (void*)GuiGameScreen_Update, (void*)GuiGameScreen_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_0045BCC0, (void*)func_0045BCD0, (void*)0x0 };
