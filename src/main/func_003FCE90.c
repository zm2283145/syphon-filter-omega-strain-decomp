#pragma cplusplus on
#include "types.h"

extern "C" {
Word* func_003FCF60(Word* dst, Word* src);
void func_003FCF70(Word* out, PtrVec* v);
void func_003FCF90(Word* out, PtrVec* self, Word* src);
int func_003FCFA0(PtrVec* v);
void IeElement_EvaluateAt(void* item, float t);
}

#pragma bool off
static inline int Ne(int a, int b) { return !(a == b); }
#pragma bool reset
static inline void GetEnd(Word* out, PtrVec* v) { Word e; func_003FCF70(&e, v); func_003FCF60(out, &e); }
static inline void GetBegin(Word* out, PtrVec* v) { Word b; b.value = func_003FCFA0(v); func_003FCF90(out, v, &b); }
struct Holder {
    char* vtable;
    char pad[0x14];
    PtrVec items;
};

extern "C" void func_003FCE90(Holder* self, float t)
{
    Word end;
    Word it;
    void** p;
    GetBegin(&it, &self->items);
    for (p = (void**)it.value; GetEnd(&end, &self->items), Ne((int)p, end.value); p++) {
        IeElement_EvaluateAt(*p, t);
    }
}
