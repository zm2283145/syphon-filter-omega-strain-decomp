#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BE3B0[];
extern char D_004E0800[];
extern char D_004E0820[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
Word* func_003FCF60(Word* dst, Word* src);
void func_003FCF70(Word* out, PtrVec* v);
void func_003FCF90(Word* out, PtrVec* self, Word* src);
int func_003FCFA0(PtrVec* v);
void func_003F1B00(PtrVec* v, short deleteFlag);
}

struct Obj { virtual ~Obj(); };
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

extern "C" Holder* func_003FD0F0(Holder* self, short deleteFlag)
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
                Mem_Free(0, o, D_004BE3B0, 0xF);
            }
        }
        if (&self->items)
            func_003F1B00(&self->items, -1);
        if (self)
            self->vtable = D_004E0800;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

