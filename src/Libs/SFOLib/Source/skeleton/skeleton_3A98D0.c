#include "types.h"
#include "vu0_ops.h"
#pragma cplusplus on
#pragma bool on
#pragma inline_depth(8)
typedef int Q128 __attribute__((mode(TI)));
static inline void MCopy(void* d, const void* s) { __int128 q0, q1; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n lq %0, 0x20(%3)\n sq %1, 0x10(%2)\n lq %1, 0x30(%3)\n sq %0, 0x20(%2)\n sq %1, 0x30(%2)" : "=&r"(q0), "=&r"(q1) : "r"(d), "r"(s) : "memory"); }
struct Mtx_9D40 { Q128 r[4]; Mtx_9D40() {} Mtx_9D40(const Mtx_9D40& o) { Mtx_9D40* d = this; MCopy(d, &o); } Mtx_9D40& operator=(const Mtx_9D40& o) { void* xx = this; MCopy(this, &o); return *this; } };
struct Node_9D40 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Refresh(); /* +0x58 */
    int pad4[3];
    Mtx_9D40 m10;           /* 0x10 */
    unsigned char b50;      /* 0x50 */
    char pad51[0xD0 - 0x51];
    Mtx_9D40 mD0;           /* 0xD0 */
    Mtx_9D40 r110;          /* 0x110 */
    char pad150[0x1D0 - 0x150];
};
struct Coll_9D40 { int pad0; int count; };
struct It_9D40;
static inline bool HEq(const It_9D40* a, const It_9D40* b);
struct It_9D40 {
    Node_9D40* p;
    It_9D40(Node_9D40* x) : p(x) {}
    It_9D40(const It_9D40& o) : p(o.p) {}
    bool operator==(const It_9D40& o) const { return HEq(this, &o); }
    bool operator!=(const It_9D40& o) const { return !(*this == o); }
    Node_9D40* operator->() const { return p; }
    Node_9D40& operator*() const { return *p; }
    It_9D40& operator++() { p++; return *this; }
};
static inline bool HEq(const It_9D40* a, const It_9D40* b) { Node_9D40* bp = b->p; return a->p == bp; }
extern "C" Node_9D40** std_vector_deleter_cBone_data_void_2(Coll_9D40*);
static inline It_9D40 HBegin(Coll_9D40* c) { It_9D40 r(*std_vector_deleter_cBone_data_void_2(c)); return r; }
static inline It_9D40 HEnd(Coll_9D40* c) { It_9D40 r(*std_vector_deleter_cBone_data_void_2(c) + c->count); return r; }
static inline void Mul_9D40(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%2)\n"
        "lqc2 $vf5, 0x10(%2)\n"
        "lqc2 $vf6, 0x20(%2)\n"
        "lqc2 $vf7, 0x30(%2)\n"
        "lqc2 $vf8, 0x0(%1)\n"
        "lqc2 $vf9, 0x10(%1)\n"
        "lqc2 $vf10, 0x20(%1)\n"
        "lqc2 $vf11, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x\n"
        "vmadday.xyzw $ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x\n"
        "vmadday.xyzw $ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x\n"
        "vmadday.xyzw $ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x\n"
        "vmadday.xyzw $ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0)\n"
        "sqc2 $vf13, 0x10(%0)\n"
        "sqc2 $vf14, 0x20(%0)\n"
        "sqc2 $vf15, 0x30(%0)\n"
        : : "r"(d), "r"(b), "r"(a) : "memory");
}
static inline void MulB_9D40(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%0)\n"
        "lqc2 $vf5, 0x10(%0)\n"
        "lqc2 $vf6, 0x20(%0)\n"
        "lqc2 $vf7, 0x30(%0)\n"
        "lqc2 $vf8, 0x0(%2)\n"
        "lqc2 $vf9, 0x10(%2)\n"
        "lqc2 $vf10, 0x20(%2)\n"
        "lqc2 $vf11, 0x30(%2)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x\n"
        "vmadday.xyzw $ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x\n"
        "vmadday.xyzw $ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x\n"
        "vmadday.xyzw $ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x\n"
        "vmadday.xyzw $ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%1)\n"
        "sqc2 $vf13, 0x10(%1)\n"
        "sqc2 $vf14, 0x20(%1)\n"
        "sqc2 $vf15, 0x30(%1)\n"
        : : "r"(a), "r"(d), "r"(b) : "memory");
}
struct Pal { Mtx_9D40 m; float x[3][4]; };
struct HitVolumes_9D40 { char pad[0x18]; Coll_9D40 coll; };
static inline Mtx_9D40 ToMtx(const Pal& p) {
    Mtx_9D40 r;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            ((float*)&r.r[i])[j] = p.x[i][j];
    return r;
}
static inline void SetX(Pal* o, Mtx_9D40* a, Mtx_9D40* b) {
    Mtx_9D40 u;
    Mul_9D40(&u, a, b);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            o->x[i][j] = ((float*)&u.r[i])[j];
}
static inline Node_9D40* World(Node_9D40* n) { if (n->b50) n->Refresh(); return n; }
#pragma opt_rotateloops off
#pragma opt_propagation off
extern "C" void cSkeleton_GetMeshToSkeletonSpaceMatrices_WithScale(HitVolumes_9D40* self, Pal* out, Pal* m)
{
    Coll_9D40* c = &self->coll;
    It_9D40 it = HBegin(c);
    It_9D40 end = HEnd(c);
    Mtx_9D40 inv; inv = ToMtx(*m);
    for (; it != end; ++it) {
        Mtx_9D40 t;
        Node_9D40* n = &*it;
        Mul_9D40(&t, &n->r110, &n->mD0);
        if (n->b50) n->Refresh();
        MulB_9D40(&t, &n->m10, &t);
        Mul_9D40(&out->m, &m->m, &t);
        Node_9D40* n2 = &*it;
        if (n2->b50) n2->Refresh();
        MulB_9D40(&t, &n2->m10, &n2->mD0);
        SetX(out, &inv, &t);
        out++;
    }
}







