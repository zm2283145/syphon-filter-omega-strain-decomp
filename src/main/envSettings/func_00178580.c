#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
extern "C" {
extern "C" void Light_Disable();
extern "C" void Light_SetPosition();
extern "C" void Light_Enable();
extern "C" void func_001479A0();
extern "C" void Light_GetCoronaSize();
extern "C" void Light_GetCoronaFlag();
extern "C" void func_001479D0();
extern "C" void func_00147A00();
extern "C" void func_00147A10();
extern void * const D_004D9F10[];
extern char D_004D9240[];
extern char D_004D9280[];
extern char D_00535D20[];
extern unsigned char D_00535D62;
void LightMgr_RemoveFromTable(void* pool, void* p);
}
class S_8580 {
public:
    int a;
    VPAD8(x) VPAD2(y)
    virtual void Shutdown();
    int id;
};
#define VT(p) (*(void**)((char*)(p) + 4))
#pragma opt_common_subs off
extern "C" S_8580* func_00178580(S_8580* self, short flag)
{
    S_8580* s = self;
    if (s) {
        VT(s) = ((char*)D_004D9F10);
        if (s) {
            VT(s) = D_004D9240;
            s->id = -1;
            self->Shutdown();
            D_00535D62 = 1;
            if (s)
                VT(s) = D_004D9280;
        }
        if (flag > 0)
            LightMgr_RemoveFromTable(D_00535D20, s);
    }
    return s;
}
#pragma opt_common_subs reset
void * const D_004D9F10[16] = { (void*)0x0, (void*)0x0, (void*)func_00178580, (void*)func_001479D0, (void*)0x1479E0, (void*)func_00147A00, (void*)func_00147A10, (void*)func_001479A0, (void*)Light_GetCoronaSize, (void*)Light_GetCoronaFlag, (void*)Light_SetPosition, (void*)Light_Enable, (void*)Light_Disable, (void*)0x1479F0, (void*)0x0, (void*)0x0 };
