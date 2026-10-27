#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BE3B0[];
extern char D_004E0800[];
extern char D_004E0820[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
Word* cArray_cAnimatorPtr_Iterator_ctor(Word* dst, Word* src);
void std_vector_cAnimatorPtr_end_void(Word* out, PtrVec* v);
void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR(Word* out, PtrVec* self, Word* src);
int std_vector_imp_cAnimatorPtr_1_begin_void(PtrVec* v);
void std_vector_cAnimatorPtr_dtor(PtrVec* v, short deleteFlag);
}

struct Obj { virtual ~Obj(); };
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

extern "C" Holder* cKfAnimationContainer_dtor(Holder* self, short deleteFlag)
{
    if (self) {
        Obj* o;
        Word end;
        Word it;
        Obj** p;
        self->vtable = D_004E0820;
        GetBegin(&it, &self->items);
        for (p = (Obj**)it.value; GetEnd(&end, &self->items), Ne((int)p, end.value); p++) {
            o = *p;
            {
                AllocGuard guard;
                o->~Obj();
                cMemMan_Deallocate(0, o, D_004BE3B0, 0xF);
            }
        }
        if (&self->items)
            std_vector_cAnimatorPtr_dtor(&self->items, -1);
        if (self)
            self->vtable = D_004E0800;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

