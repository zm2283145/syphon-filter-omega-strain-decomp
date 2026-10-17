#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern void* D_004FFC0C;
extern char D_004A6E38[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_00177060(void* w, void* o);
void* func_002348E0(void* p, signed char type, float a, void* src, float b, float c);
void* func_00235DF0(void* p, signed char type, float a, float b, float c, float d);
}
static inline void* GAlloc(int sz, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, sz, D_004A6E38, line);
}
extern "C" void func_00232C00(signed char type, void* src, float a, float b, float c, float d)
{
    void* w = D_004FFC0C;
    func_00177060(w, 0);
    if (type == 0x16 || type == 0x17 || type == 0x18) {
        void* p = GAlloc(0xD0, 0x4CD);
        if (p) p = func_002348E0(p, type, b, src, c, d);
        func_00177060(w, p);
    } else {
        void* p = GAlloc(0xC0, 0x4D2);
        if (p) p = func_00235DF0(p, type, a, b, c, d);
        func_00177060(w, p);
    }
}

