#pragma cplusplus on
#include "alloc_guard.h"

extern "C" {
extern void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004ACF10[];
extern int func_004294C0(void);
extern void* func_0044FA00(void* p);
extern int func_00445E80(int a, void* fn, void* b, void* c, void* d);
extern void func_002CC260(void);
}

struct ObjCA350 {
    char pad[0x2EC];
    unsigned char inited;
    char pad2[3];
    void* a;
    void* b;
    void* c;
};

extern "C" int func_002CA350(ObjCA350* self)
{
    void* p;

    if (self->inited || !func_004294C0())
        return 0;
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x1C, D_004ACF10, 0x5E1);
    }
    if (p)
        p = func_0044FA00(p);
    self->a = p;
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x1C, D_004ACF10, 0x5E2);
    }
    if (p)
        p = func_0044FA00(p);
    self->b = p;
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x1C, D_004ACF10, 0x5E3);
    }
    if (p)
        p = func_0044FA00(p);
    self->c = p;
    self->inited = 1;
    return func_00445E80(func_004294C0(), (void*)func_002CC260, self->a, self->b, self->c);
}
