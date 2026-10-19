#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_00219730(...);                         
int GuiWidget_Destroy(...);                         
int func_004583B0(...);                         
int func_004593A0(...);                            
int operator_delete(...);                          
extern char D_004C1EB0;
extern "C" void GuiSubTitleDisplay_IsType();
extern "C" void func_00293950();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern "C" void GuiSubTitleDisplay_GetClassName();
extern "C" void GuiSubTitleDisplay_Draw();
extern "C" void GuiSubTitleDisplay_Update();
extern "C" void GuiSubTitleDisplay_OnSleep();
extern "C" void GuiSubTitleDisplay_OnWake();
extern void * const D_004E1560[];
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * func_00458280(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E1560));
        temp_s2 = F_(arg0, 0x50, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2, &D_004C1EB0, 0x14A);
            }
        }
        func_004593A0(arg0);
        temp_a0 = arg0 + 0x68;
        if (temp_a0 != NULL) {
            func_00219730(temp_a0, -1);
        }
        temp_a0_2 = arg0 + 0x58;
        if (temp_a0_2 != NULL) {
            func_004583B0(temp_a0_2, -1);
        }
        GuiWidget_Destroy(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E1560[24] = { (void*)0x0, (void*)0x0, (void*)func_00458280, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiSubTitleDisplay_OnWake, (void*)GuiSubTitleDisplay_OnSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)func_00293950, (void*)GuiSubTitleDisplay_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiSubTitleDisplay_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiSubTitleDisplay_GetClassName, (void*)GuiSubTitleDisplay_IsType, (void*)0x0 };
