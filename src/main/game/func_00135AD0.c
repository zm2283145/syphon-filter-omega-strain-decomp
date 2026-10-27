#pragma cplusplus on
struct O_00135AD0 { void* vt; char pad[0x1C]; char m20[0x10]; char m30[0xC]; char m3C[4]; };
extern "C" {
extern "C" void cLosManager_cCollisionModelList_Game_HandleMessage();
extern "C" void cSystem_ScriptGetObjectId();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void cSystem_getSOBJClassId();
extern "C" void cSystem_ScriptHandleMessage();
extern void * const D_004D90A0[];
void std_basic_string_char_char_traits_char_dtor(void* m, short f);
void func_0013A130(void* m, short f);
void cSystem_dtor(void* p, short f);
void operator_delete(void* p);
}
extern "C" O_00135AD0* cLosManager_cCollisionModelList_Game_dtor(O_00135AD0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D90A0);
        if (self->m3C) std_basic_string_char_char_traits_char_dtor(self->m3C, 0);
        if (self->m30) std_basic_string_char_char_traits_char_dtor(self->m30, 0);
        if (self->m20) { if (self->m20) { if (self->m20) func_0013A130(self->m20, 0); } }
        cSystem_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004D90A0[16] = { (void*)0x0, (void*)0x0, (void*)cLosManager_cCollisionModelList_Game_dtor, (void*)cLosManager_cCollisionModelList_Game_HandleMessage, (void*)cSystem_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)0x0 };
