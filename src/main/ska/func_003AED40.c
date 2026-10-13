#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies as GCC-style volatile asm; unused xx locals reproduce retail's dead addius (they survive only after an earlier GCC asm) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Plc;
extern "C" void VecPair_Copy(Plc* d, const Plc* s);
struct Plc { V rot; V pos; Plc() {} Plc(const Plc& o) { VecPair_Copy(this, &o); void* xx = this; } };
extern "C" {
extern signed char D_004E1D80;
extern Plc D_00497F00;
void Quat_SetIdentity(V* q);
void Vec4_SetOrigin(V* v);
void Placement_GetIdentity(Plc* p, V* q, V* v);
void func_003AF2B0(void* self);
}
static inline Plc Ident()
{
    if (!D_004E1D80) {
        V q; V v;
        Quat_SetIdentity(&q);
        Vec4_SetOrigin(&v);
        Placement_GetIdentity(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
struct Wd { int value; };
extern "C" {
Wd* func_003AF280(Wd* dst, Wd* src);
void* func_003AF290(void* self);
int func_003AF2A0(void* a0, int a1);
int func_001361D0(int* n);
void AnimRoot_Construct(void* p);
struct Elem;
void RootCollection_Append(void* self, void* pos, int n, const Elem& v);
void* func_00396340(void* self, short flags);
}
/* RootCollection_Construct: Elem dtor uses the weak .dtors_drop idiom (include/alloc_guard.h); "Elem* t = this" keeps the element address in s0; iterators default-constructed then assigned give retail's temp+copy stack slots */
struct It {
    Wd* p;
    It() {}
    It(Wd* q) : p(q) {}
    bool operator==(const It& o) const { Wd* b = o.p; Wd* a = p; return a == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
    void operator++() { p++; }
};
struct WVec {
    int x0; int size; Wd* data;
    It begin() { return It(*(Wd**)func_003AF290(this)); }
    It end() { return It(*(Wd**)func_003AF290(this) + size); }
};
#pragma define_section ELEM_DTOR ".dtors_drop" far_absolute RX
struct Elem { Wd w; char pad[0xC]; char root[0x170]; Elem(Wd& x) { Elem* t = this; func_003AF280(&t->w, &x); AnimRoot_Construct(t->root); } __declspec(weak) __declspec(ELEM_DTOR) ~Elem() { func_00396340(root, -1); } } __attribute__((aligned(16)));
struct S { int x0; int size; char* data; unsigned char bC; Plc p10; Plc p30; };
extern "C" S* RootCollection_Construct(S* s, WVec* src);
S* RootCollection_Construct(S* s, WVec* src)
{
    It it; It e;
    int n = src->size;
    func_003AF2B0(s);
    func_003AF2A0(s, func_001361D0(&n));
    s->bC = 1;
    s->p10 = Ident();
    s->p30 = Ident();
    it = src->begin();
    e = src->end();
    while (it != e) {
        RootCollection_Append(s, s->data + s->size * 0x180, 1, Elem(*it.p));
        ++it;
    }
    return s;
}