#include "types.h"
#pragma cplusplus on
class A5_FCFB0_Item {
public:
    virtual void v0();
    virtual float Get();
};
struct A5_FCFB0_It { A5_FCFB0_Item** p; };
struct A5_FCFB0_Self { char pad[0x18]; char list[1]; };
extern "C" int std_vector_imp_cAnimatorPtr_1_begin_void_2(void* c);
extern "C" void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(A5_FCFB0_It* out, void* c, int* k);
extern "C" void std_vector_cAnimatorPtr_end_void_2(A5_FCFB0_It* out, void* c);
extern "C" void cArray_cAnimatorPtr_ConstIterator_ctor(A5_FCFB0_It* out, A5_FCFB0_It* in);

inline bool A5_FCFB0_eq(A5_FCFB0_Item** a, A5_FCFB0_Item** b) { return a == b; }
inline bool A5_FCFB0_ne(A5_FCFB0_Item** a, A5_FCFB0_Item** b) { return !A5_FCFB0_eq(a, b); }
inline A5_FCFB0_Item** A5_FCFB0_end(A5_FCFB0_It* r, void* c) {
    A5_FCFB0_It e;
    std_vector_cAnimatorPtr_end_void_2(&e, c);
    cArray_cAnimatorPtr_ConstIterator_ctor(r, &e);
    return r->p;
}

extern "C" float cKfAnimationContainer_NumFrames(A5_FCFB0_Self* self) {
    A5_FCFB0_It r;
    A5_FCFB0_It it;
    int k;
    float best = 0.0f;
    A5_FCFB0_Item** p;
    k = std_vector_imp_cAnimatorPtr_1_begin_void_2(self->list);
    std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(&it, self->list, &k);
    for (p = it.p; A5_FCFB0_ne(p, A5_FCFB0_end(&r, self->list)); p++) {
        float f = (*p)->Get();
        if (!(f <= best)) best = f;
    }
    return best;
}