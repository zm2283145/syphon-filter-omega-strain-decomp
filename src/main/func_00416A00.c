#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int operator_delete(char * );                          
extern void GuiDecorator_Load();
extern void GuiDecorator_onAdd();
extern void GuiAbstractInterface_dtor();
extern void GuiDecorator_onRemove();
extern void GuiDecorator_onWake();
extern void GuiDecorator_onSleep();
extern void GuiDecorator_onActivate();
extern void GuiDecorator_onDeactivate();
extern void GuiDecorator_onGainFocus();
extern void GuiDecorator_onLoseFocus();
extern void GuiDecorator_onInput();
extern void GuiDecorator_onRender();
extern void GuiDecorator_onAction();
extern void GuiDecorator_onMessage();
extern void GuiDecorator_onAdvanceTime();
extern void * const D_004E0960[];
extern void * const D_004E09B0[];
extern int D_00572130;

char * GuiDecorator_dtor(char * arg0, long long arg1) {
    char * temp_v0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E0960));
        temp_v0 = (char *)(F_(arg0, 0x4, int));
        if (temp_v0 != NULL) {
            F_(temp_v0, 0x44, int) = (int)(temp_v0);
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E09B0));
            D_00572130 -= 1;
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E0960[20] = { (void*)0x0, (void*)0x0, (void*)GuiDecorator_dtor, (void*)GuiDecorator_onAdd, (void*)GuiDecorator_onRemove, (void*)GuiDecorator_onActivate, (void*)GuiDecorator_onDeactivate, (void*)GuiDecorator_onWake, (void*)GuiDecorator_onSleep, (void*)GuiDecorator_onGainFocus, (void*)GuiDecorator_onLoseFocus, (void*)GuiDecorator_onInput, (void*)GuiDecorator_onRender, (void*)GuiDecorator_onAction, (void*)GuiDecorator_onAdvanceTime, (void*)GuiDecorator_onMessage, (void*)GuiDecorator_Load, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004E09B0[16] = { (void*)0x0, (void*)0x0, (void*)GuiAbstractInterface_dtor, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
