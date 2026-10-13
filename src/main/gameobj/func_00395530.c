#pragma cplusplus on
#pragma peephole off
#pragma opt_propagation off
#include "types.h"
#include "alloc_guard.h"
static inline void K_395530(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4_395530 {
    float x, y, z, w;
    V4_395530() {}
    /* split lq / sq: retail schedules the dest addiu and the next block between them */
    V4_395530(const V4_395530& o) {
        V4_395530* d = this; const V4_395530* s = &o; __int128 t;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory");
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory");
    }
} __attribute__((aligned(16)));
extern "C" {
extern char D_004BC430[];
extern char D_004BC530[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void* func_00377C30(void* p);
void* func_0036E5D0(void* p);
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline const V4_395530& IdentR_395530(void) { V4_395530 l0; V4_395530* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
struct Coll_395530 {
    int i0;
    unsigned char b4;
    char pad5[0xB];
    float f10;
    char pad14[0xC];
    V4_395530 v20;
    Coll_395530() { i0 = 0; b4 = 1; Init(IdentR_395530()); }
    void Init(V4_395530 o) { f10 = 0.0f; void* xx = &v20; /* dead on purpose */ V4_395530* d = &v20; V4_395530* s = &o; K_395530(d, s); }
};
struct S_395530 {
    char pad0[0x60];
    int i60;
    void* i64;
    void* p68;
    char pad6c[4];
    Coll_395530* p70;
    char pad74[0x1E0 - 0x74];
    void* p1E0;
    void* p1E4;
    void* p1E8;
    void* p1EC;
};
static inline void* NewA_395530(int line)
{
    void* p;
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x9C, D_004BC430, line);
    }
    if (p) p = func_0036E5D0(p);
    return p;
}
extern "C" void func_00395530(S_395530* self_, S_395530* other_)
{
    S_395530* self = self_;
    S_395530* other = other_;
    void* p;
    self_->i60 = 0;
    self_->i64 = other;
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x30, D_004BC430, 0x99);
    }
    if (p) p = func_00377C30(p);
    self->p68 = p;
    if (self->p70 == 0) {
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0x30, D_004BC530, 0x4FD);
        }
        p = new (p) Coll_395530;
        self->p70 = (Coll_395530*)p;
    }
    self->p1E4 = NewA_395530(0x9C);
    self->p1E8 = NewA_395530(0x9D);
    self->p1EC = NewA_395530(0x9E);
    if (other == 0) {
        self->p1E0 = NewA_395530(0xA3);
    } else {
        self->p1E0 = other->p1E0;
    }
}



