#pragma cplusplus on

#include "types.h"
#include "vtable3_base_dtor.h"

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAgentSave_GetClassName();
extern "C" void GuiAgentSave_IsType();
extern "C" void GuiAgentSave_HandleInput();
extern "C" void GuiAgentSave_SaveDone();
extern "C" void GuiAgentSave_HandleEvent();
extern "C" void GuiAgentSave_Wake();
extern "C" void GuiAgentLoad_Update();
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
extern "C" void GuiWidget_Init();
extern "C" void GuiWidget_Load();
extern void * const D_004DD3A0[];
extern char D_004DD460[];
extern char D_004E1220[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable3Object* GuiAgentSave_dtor(Vtable3Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD3A0);
        if (self) {
            self->vtable = D_004DD460;
            if (self) {
                self->vtable = D_004E1220;
                GuiWidget_Destroy(self, 0);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD3A0[24] = { (void*)0x0, (void*)0x0, (void*)GuiAgentSave_dtor, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiAgentSave_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiAgentSave_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiAgentLoad_Update, (void*)GuiAgentSave_HandleEvent, (void*)GuiWidget_Load, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAgentSave_GetClassName, (void*)GuiAgentSave_IsType, (void*)GuiAgentSave_SaveDone };
