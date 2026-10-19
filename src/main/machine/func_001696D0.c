#include "types.h"
typedef struct { void* vt; char pad[0x28]; char sub[0x18]; char a44[0x108]; char a14C[0x12D]; char m279[4]; } S_96D0;
extern void GObj_GetID();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern void Object_BroadcastToChildren();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
extern void * const D_004D97B0[];
void func_0042B800(void* p, int f);
void String_Dtor_138350(void* p, int f);
void __destroy_array(void* arr, void* dtor, int size, int n);
void ListReceiver_Dtor(S_96D0* p, int f);
void operator_delete(void* p);
S_96D0* App_dtor(S_96D0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D97B0);
        func_0042B800(self->m279, -1);
        if (self->sub) {
            __destroy_array(self->a14C, String_Dtor_138350, 0xC, 0x14);
            __destroy_array(self->a44, String_Dtor_138350, 0xC, 0x16);
        }
        ListReceiver_Dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D97B0[16] = { (void*)0x0, (void*)0x0, (void*)App_dtor, (void*)Object_BroadcastToChildren, (void*)GObj_GetID, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
