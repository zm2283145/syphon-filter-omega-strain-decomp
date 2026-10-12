#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char pad[0x60]; unsigned char b60; } M3E7B;
typedef struct { M3E7B* f0; void* f4; } O3E7B;
extern "C" {
extern void func_0036DEF0(void*);
extern unsigned char* FileMan_ReadData(void*);
extern int D_0055C0B8;
extern char D_004BDEC8[];
extern void* Mem_Alloc(int, int, char*, int);
extern M3E7B* func_003EF660(void*, unsigned char**, void*, int);
extern void* func_003EEB30(M3E7B*, char*);
extern void* func_003EF010(void*);
extern float func_003EE740(void*);
extern void func_003F4510(void*, int, float, float);
}
#pragma opt_propagation off
extern "C" O3E7B* func_003E7B00(O3E7B* o, void* src) {
    unsigned char* p;
    M3E7B* m;
    void* s;
    o->f0 = 0;
    o->f4 = 0;
    func_0036DEF0(src);
    p = FileMan_ReadData(src);
    p++;
    p++;
    D_0055C0B8 = *(unsigned short*)p;
    p += 2;
    {
        AllocGuard g;
        m = (M3E7B*)Mem_Alloc(0, 0xE0, D_004BDEC8, 0x2F);
    }
    if (m) m = func_003EF660(m, &p, src, 0);
    o->f0 = m;
    o->f0->b60 = 1;
    s = func_003EEB30(o->f0, "preview");
    if (s) {
        o->f4 = func_003EF010(s);
        func_003F4510(o->f4, 1, -20.0f, 20.0f + func_003EE740(s));
    }
    return o;
}
#pragma opt_propagation reset
