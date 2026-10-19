#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void func_00349ED0();
extern "C" void GuiRatings_GetClassName();
extern "C" void GuiRatings_IsType();
extern "C" void func_0034D2B0();
extern "C" void func_0034D2C0();
extern "C" void GuiRatings_HandleInput();
extern "C" void GuiRatings_HandleEvent();
extern "C" void GuiRatings_Draw();
extern "C" void GuiRatings_Sleep();
extern "C" void GuiRatings_First();
extern "C" void GuiRatings_Wake();
extern "C" void GuiRatings_Init();
extern "C" void GuiPersonnelScreen_Back();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Load();
extern void * const D_004DECC0[];
extern char D_004DF0B0[];
void* func_00299360(void* self, short deleteFlag);
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable2Object* GuiRatings_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DECC0);
        char* member = (char*)self + (0xCC);
        if (member) {
            if (member) {
                if (member)
                    func_00299360(member, 0);
            }
        }
        if (self) {
            self->vtable = D_004DF0B0;
            GuiWidget_Destroy(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DECC0[28] = { (void*)0x0, (void*)0x0, (void*)GuiRatings_dtor, (void*)GuiRatings_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiRatings_Wake, (void*)GuiRatings_Sleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiRatings_HandleInput, (void*)GuiRatings_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiRatings_HandleEvent, (void*)GuiWidget_Load, (void*)GuiRatings_First, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiRatings_GetClassName, (void*)GuiRatings_IsType, (void*)func_0034D2B0, (void*)func_00349ED0, (void*)func_0034D2C0, (void*)GuiPersonnelScreen_Back, (void*)0x0 };
