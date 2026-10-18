#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
extern "C" {
extern "C" void GuiEndGameObjectives_IsType();
extern "C" void GuiObjectives_HandleEvent();
extern "C" void GuiObjectives_Init();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void GuiEndGameObjectives_Update();
extern "C" void GuiEndGameObjectives_GetClassName();
extern "C" void GuiEndGameObjectives_HandleInput();
extern "C" void GuiEndGameObjectives_Wake();
extern void * const D_004E17C0[];
extern char D_004DF5C0[];
void operator_delete(void* allocation);
void FileMan_Release(void* self, int flags);
void func_00461DC0(void* self, int flags);
void GuiWidget_Destroy(void* self, int flags);
}
struct O4621A0 { void* vtable; };
extern "C" O4621A0* func_004621A0(O4621A0* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E17C0);
        {
            char* q = (char*)self + 0x90;
            if (q) {
                char* p = (char*)self + 0xB0;
                if (p) {
                    FileMan_Release((char*)self + 0x194, -1);
                    FileMan_Release((char*)self + 0xF8, -1);
                }
                {
                    char* a = (char*)self + 0x90;
                    if (a) {
                        if (a) {
                            if (a)
                                func_00461DC0(a, 0);
                        }
                    }
                }
            }
        }
        if (self) {
            self->vtable = D_004DF5C0;
            GuiWidget_Destroy(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E17C0[24] = { (void*)0x0, (void*)0x0, (void*)func_004621A0, (void*)GuiObjectives_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiEndGameObjectives_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiEndGameObjectives_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiEndGameObjectives_Update, (void*)GuiObjectives_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiEndGameObjectives_GetClassName, (void*)GuiEndGameObjectives_IsType, (void*)0x0 };
