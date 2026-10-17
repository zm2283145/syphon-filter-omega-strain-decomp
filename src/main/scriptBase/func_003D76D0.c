#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
extern char D_004BD3B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void PtrVector_Resize(void* v, int n, int* val);
}
typedef struct { int pad0; int count; int* data; } V76D0;
typedef struct { int pad0; int x4; V76D0 vec; char pad14[0x38 - 0x14]; int x38; } O76D0;
extern "C" {
O76D0* func_003D6030(void* p, char* name, int a, signed char f);
void func_003D7910(int list, O76D0** o);
extern int D_00554F20;
}
static inline int* At(V76D0* v, unsigned int i) { return &v->data[i]; }
static inline void* SD_Alloc(int n, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_004BD3B0, line);
}
extern "C" void func_003D76D0(char* name, int a, int x4, int n, int* src, signed char f)
{
    O76D0* o;
    int i;
    int zero;
    void* m = SD_Alloc(0x44, 0x119);
    if (m) m = func_003D6030(m, name, a, f);
    o = (O76D0*)m;
    ((O76D0*)m)->x4 = x4;
    o->x38 = 1;
    zero = 0;
    PtrVector_Resize(&o->vec, n, &zero);
    for (i = 0; i < n; i++) *At(&o->vec, i) = src[i];
    func_003D7910(D_00554F20, &o);
}



