#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void Event_PackHeader();
extern "C" void Message_GetScriptTypeKey();
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_00133900();
extern "C" void func_001383D0();
extern "C" void func_001385B0();
extern "C" void func_00169270();
extern "C" void func_00169960();
extern "C" void func_002CBAC0();
extern "C" void func_003CB1E0();
extern "C" void func_003CB1F0();
extern void * const D_004DE180[];
void func_002CB160(void* self);
void func_002CC520(void* m, int flags);
void Receiver_Destruct(void* self, int flags);
void operator_delete(void* p);
}
struct ObjC480 { void* vtable; char pad[0x24]; unsigned char active; char pad2[0x2FC - 0x29]; char member[4]; };
extern "C" ObjC480* func_002CC480(ObjC480* self, short deleteFlag)
{
    if (self) {
        void* m;
        self->vtable = ((char*)D_004DE180);
        if (self->active)
            func_002CB160(self);
        m = self->member;
        if (m)
            func_002CC520(m, 0);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE180[32] = { (void*)0x0, (void*)0x0, (void*)func_002CC480, (void*)func_002CBAC0, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_003CB1E0, (void*)func_003CB1F0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)func_00133900, (void*)func_001385B0, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)func_00169270, (void*)func_00169960, (void*)Event_PackHeader, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
