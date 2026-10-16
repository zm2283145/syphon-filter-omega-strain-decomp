#pragma cplusplus on

#include "types.h"
#include "vtable3_base_dtor.h"

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_002927E0();
extern "C" void func_002927F0();
extern "C" void func_00292820();
extern "C" void func_002928E0();
extern "C" void func_00292980();
extern "C" void func_00292A20();
extern "C" void GuiAgentLoad_Update();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern "C" void func_0041F210();
extern void * const D_004DD3A0[];
extern char D_004DD460[];
extern char D_004E1220[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" Vtable3Object* func_00292760(Vtable3Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD3A0);
        if (self) {
            self->vtable = D_004DD460;
            if (self) {
                self->vtable = D_004E1220;
                func_0041F370(self, 0);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD3A0[24] = { (void*)0x0, (void*)0x0, (void*)func_00292760, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00292A20, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00292820, (void*)func_0041E470, (void*)func_0041E230, (void*)GuiAgentLoad_Update, (void*)func_00292980, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_002927E0, (void*)func_002927F0, (void*)func_002928E0 };
