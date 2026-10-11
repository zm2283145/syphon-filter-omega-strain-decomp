#include "types.h"
typedef struct { int cap; int count; void** data; } Vec_1C3B00;
typedef struct { char pad[0x10]; Vec_1C3B00* vec; } Obj_1C3B00;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049EE88[];
extern void Alloc_Lock(int n);
extern void Alloc_Unlock(int n);
extern void Mem_Free(int pool, void* p, char* file, int line);
extern void** PtrVec_Back_1C3C30(Vec_1C3B00* v);
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int f);
extern void func_001454E0(Vec_1C3B00* v, int f);
void func_001C3B00(Obj_1C3B00* o)
{
    Vec_1C3B00* v = o->vec;
    if (v) {
        int g[2];
        while (v->count) {
            void* p = *PtrVec_Back_1C3C30(v);
            if (D_00533880)
                Alloc_Lock(9);
            D_00533888++;
            Mem_Free(0, p, D_0049EE88, 0x10D);
            if (D_00533880)
                Alloc_Unlock(9);
            D_00533888--;
            o->vec->count--;
            v = o->vec;
        }
        func_00136DA0(g);
        func_001454E0(v, -1);
        Mem_Free(0, v, D_0049EE88, 0x111);
        func_0012F530(g, -1);
        o->vec = 0;
    }
}