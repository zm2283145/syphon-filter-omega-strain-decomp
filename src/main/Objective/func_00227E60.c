#include "types.h"
typedef struct { void* vtable; } ObjMan00227E60;
extern void cObjectiveMan_v01();
extern void cObjectiveMan_v0B();
extern void cObjectiveMan_v0C();
extern void func_0012ECE0();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern void * const D_004DB790[];
extern void ObjMan_DeleteAll(ObjMan00227E60* self);
extern void Receiver_Destruct(ObjMan00227E60* self, int flags);
extern void operator_delete(void* p);
ObjMan00227E60* cObjectiveMan_dtor(ObjMan00227E60* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DB790);
        ObjMan_DeleteAll(self);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DB790[16] = { (void*)0x0, (void*)0x0, (void*)cObjectiveMan_dtor, (void*)cObjectiveMan_v01, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cObjectiveMan_v0B, (void*)cObjectiveMan_v0C, (void*)0x0 };
