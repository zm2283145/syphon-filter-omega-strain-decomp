#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int operator_delete(char * );                          
extern void GuiDecorator_Load();
extern void GuiDecorator_onAdd();
extern void GuiAbstractInterface_dtor();
extern void func_00416850();
extern void func_00416870();
extern void func_00416890();
extern void func_004168B0();
extern void func_004168D0();
extern void func_004168F0();
extern void func_00416910();
extern void func_00416930();
extern void func_00416950();
extern void func_00416970();
extern void func_00416990();
extern void func_004169B0();
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
void * const D_004E0960[20] = { (void*)0x0, (void*)0x0, (void*)GuiDecorator_dtor, (void*)GuiDecorator_onAdd, (void*)func_00416850, (void*)func_004168B0, (void*)func_004168D0, (void*)func_00416870, (void*)func_00416890, (void*)func_004168F0, (void*)func_00416910, (void*)func_00416930, (void*)func_00416950, (void*)func_00416970, (void*)func_004169B0, (void*)func_00416990, (void*)GuiDecorator_Load, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004E09B0[16] = { (void*)0x0, (void*)0x0, (void*)GuiAbstractInterface_dtor, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
