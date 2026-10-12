#pragma cplusplus on
#include "alloc_guard.h"
#include "types.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
void func_003E79F0(void* p, int flag);
int* func_0026D030(PtrVec* v, int i);
void func_0026DF80(PtrVec* v, int flag);
extern char D_004A8808[];
extern char D_004DCBB0[];
extern char D_004DC930[];
}

struct Elem {
    virtual void Destroy(int flag);
};

struct Holder {
    int unk0;
    void* vtbl;
    void* p;
    int unkC;
    PtrVec list;
};

extern "C" Holder* func_0026DDC0(Holder* self, short deleteFlag) {
    if (self) {
        self->vtbl = D_004DCBB0;
        {
            void* p = self->p;
            AllocGuard guard;
            func_003E79F0(p, -1);
            Mem_Free(0, p, D_004A8808, 0x133);
        }
        {
            int i;
            for (i = self->list.count - 1; i >= 0; i--) {
                Elem* e = *(Elem**)func_0026D030(&self->list, i);
                AllocGuard guard;
                e->Destroy(-1);
                Mem_Free(0, e, D_004A8808, 0x137);
            }
        }
        self->list.count = 0;
        if (&self->list) func_0026DF80(&self->list, -1);
        if (self) self->vtbl = D_004DC930;
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
