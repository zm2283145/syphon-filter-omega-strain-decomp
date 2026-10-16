#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void GuiMissionStatistics_GetClassName();
extern "C" void func_00349ED0();
extern "C" void func_0034D2B0();
extern "C" void func_0034F380();
extern "C" void func_0034F940();
extern "C" void func_0034FA40();
extern "C" void func_0034FA80();
extern "C" void func_0034FB40();
extern "C" void func_0034FB50();
extern "C" void func_0034FBA0();
extern "C" void func_00356AD0();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_Draw();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern void * const D_004DEE70[];
extern char D_004DF0B0[];
void* func_003513B0(void* self, short deleteFlag);
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable2Object* func_0034F2D0(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DEE70);
        char* member = (char*)self + (0x70);
        if (member) {
            if (member) {
                if (member)
                    func_003513B0(member, 0);
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
void * const D_004DEE70[28] = { (void*)0x0, (void*)0x0, (void*)func_0034F2D0, (void*)func_0034FBA0, (void*)GuiWidget_Deinit, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0034FB50, (void*)func_0034FB40, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0034FA80, (void*)GuiWidget_Draw, (void*)func_0041E230, (void*)GuiWidget_Update, (void*)func_0034FA40, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiMissionStatistics_GetClassName, (void*)func_0034F380, (void*)func_0034D2B0, (void*)func_00349ED0, (void*)func_0034F940, (void*)func_00356AD0, (void*)0x0 };
