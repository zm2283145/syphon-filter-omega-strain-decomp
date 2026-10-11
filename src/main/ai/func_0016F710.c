#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_0049C810[];
extern char D_004D9850[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void cMessage_ctor2(void* self, void* other);
void func_0016F7E0(void* dst, void* src);
void Vec4_Assign(void* dst, void* src);
}
struct Msg_0016F710 {
    void* vtable;
    char base[0x30];
    char a[0xC];
    char v[0x10];
};
extern "C" Msg_0016F710* func_0016F710(Msg_0016F710* self)
{
    Msg_0016F710* p;
    {
        AllocGuard guard;
        p = (Msg_0016F710*)Mem_Alloc(0, 0x50, D_0049C810, 0x164);
    }
    if (p) {
        cMessage_ctor2(p, self);
        p->vtable = D_004D9850;
        func_0016F7E0(p->a, self->a);
        Vec4_Assign(p->v, self->v);
    }
    return p;
}