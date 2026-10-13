#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_Dtor();                         
int func_00412CF0();                          
int func_00416A00();                         
int func_00418240();                         
int operator_delete();                          
extern void GuiWidget_OnActivate();
extern void GuiWidget_OnDeactivate();
extern void GuiWidget_OnGainFocus();
extern void GuiWidget_OnLoseFocus();
extern void GuiWidget_OnSleep();
extern void GuiWidget_OnWake();
extern void func_00416F70();
extern void func_00417340();
extern void func_004173B0();
extern void func_00417790();
extern void func_00417870();
extern void func_004178E0();
extern void * const D_004E09F0[];
extern char D_00571DC0;

char * func_00417AE0(char * arg0, long long arg1) {
    int temp_a1;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E09F0));
        temp_a1 = F_(arg0, 0x20, int);
        if (temp_a1 != -1) {
            func_00412CF0(&D_00571DC0, temp_a1);
        }
        temp_a0 = arg0 + 0x70;
        if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
            func_00418240(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x14;
        if (temp_a0_2 != NULL) {
            String_Dtor(temp_a0_2, 0);
        }
        temp_a0_3 = arg0 + 8;
        if (temp_a0_3 != NULL) {
            String_Dtor(temp_a0_3, 0);
        }
        func_00416A00(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E09F0[20] = { (void*)0x0, (void*)0x0, (void*)func_00417AE0, (void*)func_004178E0, (void*)func_00417870, (void*)GuiWidget_OnActivate, (void*)GuiWidget_OnDeactivate, (void*)GuiWidget_OnWake, (void*)GuiWidget_OnSleep, (void*)GuiWidget_OnGainFocus, (void*)GuiWidget_OnLoseFocus, (void*)0x416930, (void*)func_00417340, (void*)0x416970, (void*)func_00417790, (void*)func_004173B0, (void*)func_00416F70, (void*)0x0, (void*)0x0, (void*)0x0 };
