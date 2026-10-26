#pragma cplusplus on
#include "types.h"
struct A_E070 { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct It_E070 { A_E070** p; };
struct Vec_E070;
extern "C" {
void* World_GetActorArray(void);
Vec_E070* cObjList_cGOBJPtr_GetList(void* arr);
void PtrVec_Begin(It_E070* out, Vec_E070* v);
void PtrVec_End(It_E070* out, Vec_E070* v);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It_E070* out, It_E070* in);
void* ActivationMgr_Get(void);
void ZoneMgr_DeactivateObject(void* mgr, A_E070* a, int f);
}
static inline int Ne_E070(It_E070* a, It_E070* b) { return (a->p == b->p) ^ 1; }
extern "C" void cScene_DeactivateAll(void)
{
    It_E070 it;
    It_E070 end;
    It_E070 tb;
    It_E070 te;
    void* arr = World_GetActorArray();
    PtrVec_Begin(&tb, cObjList_cGOBJPtr_GetList(arr));
    cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&it, &tb);
    for (PtrVec_End(&te, cObjList_cGOBJPtr_GetList(arr)), cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te); Ne_E070(&it, &end); PtrVec_End(&te, cObjList_cGOBJPtr_GetList(arr)), cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te)) {
        A_E070* a = *it.p;
        if (a) {
            unsigned char ok = a->b2D != 0 && a->b2C != 0 && !(a->b2E != 0);
            if (ok)
                ZoneMgr_DeactivateObject(ActivationMgr_Get(), a, 1);
        }
        it.p++;
    }
}