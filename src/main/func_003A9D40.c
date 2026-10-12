#include "types.h"
#include "vu0_ops.h"
#pragma cplusplus on
#pragma bool on
#pragma inline_depth(8)
typedef int Q128 __attribute__((mode(TI)));
struct Mtx_9D40 { Q128 r[4]; };
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
    char pad110[0x1D0 - 0x110];
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
extern "C" Node_9D40** func_001D5E80(Coll_9D40*);
static inline It_9D40 HBegin(Coll_9D40* c) { It_9D40 r(*func_001D5E80(c)); return r; }
static inline It_9D40 HEnd(Coll_9D40* c) { It_9D40 r(*func_001D5E80(c) + c->count); return r; }
static inline void Mul_9D40(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1)\n"
        "lqc2 $vf5, 0x10(%1)\n"
        "lqc2 $vf6, 0x20(%1)\n"
        "lqc2 $vf7, 0x30(%1)\n"
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
        "sqc2 $vf12, 0x0(%0)\n"
        "sqc2 $vf13, 0x10(%0)\n"
        "sqc2 $vf14, 0x20(%0)\n"
        "sqc2 $vf15, 0x30(%0)\n"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct HitVolumes_9D40 { char pad[0x18]; Coll_9D40 coll; };
#pragma opt_rotateloops off
#pragma opt_propagation off
extern "C" void HitVolumes_NodeMatrices(HitVolumes_9D40* self, Mtx_9D40* out, Mtx_9D40* m)
{
    Coll_9D40* c = &self->coll;
    It_9D40 it = HBegin(c);
    It_9D40 end = HEnd(c);
    for (; it != end; ++it) {
        Node_9D40* n = &*it;
        if (n->b50)
            n->Refresh();
        Mul_9D40(out, &n->m10, &n->mD0);
        Mul_9D40(out, m, out);
        out++;
    }
}



