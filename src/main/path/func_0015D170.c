#include "types.h"
extern void GObj_GetID();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern void NpcRouteMgr_HandleMessage();
extern void Receiver_GetScriptTypeKey();
extern void Receiver_ScriptDispatch();
extern void * const D_004D96C0[];
extern void func_0015D200(void* p, int flag);
extern void Receiver_Destruct(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_D170;
S_D170* NpcRouteMgr_Destruct(S_D170* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)D_004D96C0);
        m = (char*)self + 0x2C;
        if (m)
            func_0015D200(m, 0);
        m = (char*)self + 0x20;
        if (m)
            func_0015D200(m, 0);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D96C0[16] = { (void*)0x0, (void*)0x0, (void*)NpcRouteMgr_Destruct, (void*)NpcRouteMgr_HandleMessage, (void*)GObj_GetID, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
