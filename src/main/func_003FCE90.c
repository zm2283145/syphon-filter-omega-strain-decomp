#pragma cplusplus on
#include "types.h"

extern "C" {
Word* cArray_cAnimatorPtr_Iterator_ctor(Word* dst, Word* src);
void std_vector_cAnimatorPtr_end_void(Word* out, PtrVec* v);
void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Word* out, PtrVec* self, Word* src);
int std_vector_imp_cAnimatorPtr_1_begin_void(PtrVec* v);
void IeElement_EvaluateAt(void* item, float t);
}

#pragma bool off
static inline int Ne(int a, int b) { return !(a == b); }
#pragma bool reset
static inline void GetEnd(Word* out, PtrVec* v) { Word e; std_vector_cAnimatorPtr_end_void(&e, v); cArray_cAnimatorPtr_Iterator_ctor(out, &e); }
static inline void GetBegin(Word* out, PtrVec* v) { Word b; b.value = std_vector_imp_cAnimatorPtr_1_begin_void(v); std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(out, v, &b); }
struct Holder {
    char* vtable;
    char pad[0x14];
    PtrVec items;
};

extern "C" void IeTrack_EvaluateGroup(Holder* self, float t)
{
    Word end;
    Word it;
    void** p;
    GetBegin(&it, &self->items);
    for (p = (void**)it.value; GetEnd(&end, &self->items), Ne((int)p, end.value); p++) {
        IeElement_EvaluateAt(*p, t);
    }
}
