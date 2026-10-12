#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern "C" void Objective_ConsumeEvent();
extern "C" void Objective_ScriptFilter();
extern "C" void cObjective_v04();
extern "C" void cObjective_v06();
extern "C" void cObjective_v07();
extern "C" void cObjective_v0B();
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern void * const D_004DB7D0[];
extern char D_004A5D88[];
void Mem_Free(int heap, void* p, char* file, int line);
void Receiver_Destruct(void* self, int flag);
void operator_delete(void* p);
}
static inline void Del_00229180(void* p, int line) { if (p) { AllocGuard g; Mem_Free(0, p, D_004A5D88, line); } }
struct S_00229180 { void* vt; char pad4[0x48]; void* p4C; void* p50; char pad54[4]; void* p58; char pad5c[4]; void* p60; void* p64; void* p68; void* p6C; void* p70; void* p74; void* p78; void* p7C; void* p80; void* p84; void* p88; };
extern "C" S_00229180* cObjective_dtor(S_00229180* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004DB7D0);
        Del_00229180(self->p4C, 0x7A);
        Del_00229180(self->p50, 0x7D);
        Del_00229180(self->p58, 0x80);
        Del_00229180(self->p60, 0x83);
        Del_00229180(self->p64, 0x86);
        Del_00229180(self->p68, 0x89);
        Del_00229180(self->p6C, 0x8C);
        Del_00229180(self->p70, 0x8F);
        Del_00229180(self->p74, 0x92);
        Del_00229180(self->p78, 0x95);
        Del_00229180(self->p7C, 0x98);
        Del_00229180(self->p80, 0x9B);
        Del_00229180(self->p84, 0x9E);
        Del_00229180(self->p88, 0xA1);
        Receiver_Destruct(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB7D0[16] = { (void*)0x0, (void*)0x0, (void*)cObjective_dtor, (void*)Objective_ConsumeEvent, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)cObjective_v04, (void*)func_0012ED00, (void*)cObjective_v06, (void*)cObjective_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cObjective_v0B, (void*)Objective_ScriptFilter, (void*)0x0 };
