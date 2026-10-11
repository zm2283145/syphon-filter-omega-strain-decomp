#pragma cplusplus on
#include "types.h"
struct A_E070 { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct It_E070 { A_E070** p; };
struct Vec_E070;
extern "C" {
void* World_GetActorArray(void);
Vec_E070* func_001339A0(void* arr);
void PtrVec_Begin(It_E070* out, Vec_E070* v);
void PtrVec_End(It_E070* out, Vec_E070* v);
void func_00133980(It_E070* out, It_E070* in);
void* func_00224530(void);
void func_00224180(void* mgr, A_E070* a, int f);
}
static inline int Ne_E070(It_E070* a, It_E070* b) { return (a->p == b->p) ^ 1; }
extern "C" void func_0013E070(void)
{
    It_E070 it;
    It_E070 end;
    It_E070 tb;
    It_E070 te;
    void* arr = World_GetActorArray();
    PtrVec_Begin(&tb, func_001339A0(arr));
    func_00133980(&it, &tb);
    for (PtrVec_End(&te, func_001339A0(arr)), func_00133980(&end, &te); Ne_E070(&it, &end); PtrVec_End(&te, func_001339A0(arr)), func_00133980(&end, &te)) {
        A_E070* a = *it.p;
        if (a) {
            unsigned char ok = a->b2D != 0 && a->b2C != 0 && !(a->b2E != 0);
            if (ok)
                func_00224180(func_00224530(), a, 1);
        }
        it.p++;
    }
}