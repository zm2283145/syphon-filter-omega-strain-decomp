/*
 * Libs/SFOLib/Source/skeleton: 7 files, 003A96A0-003A9D40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A96A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cBone_Size(char* self) {
    return *(int*)(self + 4);
}

void* cSkeleton_GetBoneList(char* self) {
    return self + 24;
}
static inline void merge_flush_func_003A96A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A96A0 */

/* merge_units: begin skeleton_3A96C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 q;  __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
    float& operator[](int i) { return (&x)[i]; }
} __attribute__((aligned(16)));
extern "C" V* cMatrix_GetAxis(void* m, int i);
struct R4 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
struct M4 {
    R4 r[4];
    V* Row(int k) { return cMatrix_GetAxis(this, k); }
    void SetRow(int k, const V& v) { r[k].Set(v.x, v.y, v.z, v.w); }
};
template <class T> struct Vec { T* data; T& At(int i) { Vec* p = this; return p->data[i]; } T& At2(int i) { return At(i); } T& operator[](int i) { return At(i); } };
struct V3 { float x, y, z; float& operator[](int i) { return (&x)[i]; } };
struct SNode {
    char pad[0x110];
    M4 m;
    char pad2[0x1D0 - 0x150];
};
struct VT : V { VT(const V& o) { void* xx = this; const V* s = &o; __int128 q; V* d = this;  __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); } };
static inline V WithComp(VT t, int k, float f) { V* p = &t; (&p->x)[k] = f; return *p; }
static inline void CPa(V* d0, const V* s0) { const V* s = s0;__int128 q;V* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct VT3 : V { VT3(const V& o) { void* xx = this; CPa(this, &o); } };
static inline V W3(VT3 t, int k, float f) { V* p = &t; (&p->x)[k] = f; return *p; }
struct S { char pad[0xC]; Vec<V3> scales; char pad10[4]; unsigned char x14; char pad15[7]; int count; Vec<SNode> nodes; };
#define BLK3(K, C) { float f = s->scales[i].C;SNode* nd = &s->nodes[i]; V r = W3(*nd->m.Row(K), K, f); nd->m.SetRow(K, r); }
#define BLK(K, C) { float f = s->scales[i].C;SNode* nd = &s->nodes[i]; V r = WithComp(*nd->m.Row(K), K, f); nd->m.SetRow(K, r); }
extern "C" void cSkeleton_SetupBoneScaleMatrices(S* s);
void cSkeleton_SetupBoneScaleMatrices(S* s)
{
    if (s->x14) {
        int n = s->count;
        for (int i = 0; i < n; i++) {
            BLK(0, x)
            BLK(1, y)
            BLK3(2, z)
        }
    }
}
static inline void merge_flush_skeleton_3A96C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end skeleton_3A96C0 */

/* merge_units: begin skeleton_3A98D0 */
#pragma push /* merge_units */
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
static inline void merge_flush_skeleton_3A98D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end skeleton_3A98D0 */

/* merge_units: begin func_003A9D40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool on
#pragma inline_depth(8)

struct Mtx_9D40_003A9D40 { Q128 r[4]; };
struct Node_9D40_003A9D40 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Refresh(); /* +0x58 */
    int pad4[3];
    Mtx_9D40_003A9D40 m10;           /* 0x10 */
    unsigned char b50;      /* 0x50 */
    char pad51[0xD0 - 0x51];
    Mtx_9D40_003A9D40 mD0;           /* 0xD0 */
    char pad110[0x1D0 - 0x110];
};
struct It_9D40_003A9D40;
static inline bool HEq_003A9D40(const It_9D40_003A9D40* a, const It_9D40_003A9D40* b);
struct It_9D40_003A9D40 {
    Node_9D40_003A9D40* p;
    It_9D40_003A9D40(Node_9D40_003A9D40* x) : p(x) {}
    It_9D40_003A9D40(const It_9D40_003A9D40& o) : p(o.p) {}
    bool operator==(const It_9D40_003A9D40& o) const { return HEq_003A9D40(this, &o); }
    bool operator!=(const It_9D40_003A9D40& o) const { return !(*this == o); }
    Node_9D40_003A9D40* operator->() const { return p; }
    Node_9D40_003A9D40& operator*() const { return *p; }
    It_9D40_003A9D40& operator++() { p++; return *this; }
};
static inline bool HEq_003A9D40(const It_9D40_003A9D40* a, const It_9D40_003A9D40* b) { Node_9D40_003A9D40* bp = b->p; return a->p == bp; }
#if 0 /* merge_units */
extern "C" Node_9D40_003A9D40** std_vector_deleter_cBone_data_void_2(Coll_9D40*);
#endif /* merge_units */
#define std_vector_deleter_cBone_data_void_2(a0) ((Node_9D40_003A9D40 * *)std_vector_deleter_cBone_data_void_2((a0))) /* merge_units */

static inline It_9D40_003A9D40 HBegin_003A9D40(Coll_9D40* c) { It_9D40_003A9D40 r(*std_vector_deleter_cBone_data_void_2(c)); return r; }
static inline It_9D40_003A9D40 HEnd_003A9D40(Coll_9D40* c) { It_9D40_003A9D40 r(*std_vector_deleter_cBone_data_void_2(c) + c->count); return r; }
static inline void Mul_9D40_003A9D40(void* d, void* a, void* b) {
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
#pragma opt_rotateloops off
#pragma opt_propagation off
extern "C" void cSkeleton_GetMeshToSkeletonSpaceMatrices(HitVolumes_9D40* self, Mtx_9D40_003A9D40* out, Mtx_9D40_003A9D40* m)
{
    Coll_9D40* c = &self->coll;
    It_9D40_003A9D40 it = HBegin_003A9D40(c);
    It_9D40_003A9D40 end = HEnd_003A9D40(c);
    for (; it != end; ++it) {
        Node_9D40_003A9D40* n = &*it;
        if (n->b50)
            n->Refresh();
        Mul_9D40_003A9D40(out, &n->m10, &n->mD0);
        Mul_9D40_003A9D40(out, m, out);
        out++;
    }
}
#undef std_vector_deleter_cBone_data_void_2 /* merge_units */
static inline void merge_flush_func_003A9D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A9D40 */

/* merge_units: begin func_003A9F00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (just before skeleton.cc);
 * functions are named by address until real names are known.
 */

#include "loose03_types.h"

extern int cSkeleton_CreateBones(SkelNodes*);
extern void cSkeleton_DestroyBones(SkelNodes*);

void cSkeleton_Deactivate(SkelNodes* self) {
    self->unk14 = 0;
    cSkeleton_DestroyBones(self);
}

/* Sets unk14 then constructs the node set. */
int cSkeleton_Activate(SkelNodes* self) {
    self->unk14 = 1;
    return cSkeleton_CreateBones(self);
}
static inline void merge_flush_func_003A9F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A9F00 */

/* merge_units: begin func_003A9F20 */
#pragma push /* merge_units */
typedef struct ModelSrc {
    int** model;  /* 0x00 */
    int unk04;    /* 0x04 */
} ModelSrc;

typedef struct ModelCtx {
    int** model;          /* 0x00 */
    char scales[0x10];    /* 0x04 */
    unsigned char hasSkel;/* 0x14 */
    char pad15[0x13];
    int unk28;            /* 0x28 */
} ModelCtx;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern void std_vector_imp_cBoneScale_resize(void* scales, int* bones, Vec3f* scale);
#if 0 /* merge_units */
extern void cSkeleton_CreateBones(ModelCtx* ctx);
#endif /* merge_units */
#define cSkeleton_CreateBones(a0) ((void)cSkeleton_CreateBones((SkelNodes *)(a0))) /* merge_units */




/* Initializes a model context from src with unit bone scale. */
void cSkeleton_Reset(ModelCtx* ctx, ModelSrc* src) {
    Vec3f scale;
    ctx->model = src->model;
    ctx->unk28 = src->unk04;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    std_vector_imp_cBoneScale_resize(ctx->scales, *ctx->model, &scale);
    if (ctx->hasSkel) {
        cSkeleton_CreateBones(ctx);
    }
}
#undef cSkeleton_CreateBones /* merge_units */
static inline void merge_flush_func_003A9F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A9F20 */

/* merge_units: begin func_003A9F90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { char* name; int count; int a, b; } N3A9;
extern "C" {
extern void cFileMan_Open(void*);
extern void cFileMan_Read_charPP_int(void*, int*, int);
extern void cFileMan_Close(void*);
extern void* cMemMan_Allocate(int, int, char*, int);
extern char D_004BCCF8[];
extern unsigned int strlen(const char*);
extern void Libc_Strcpy(char*, char*);
extern void std_list_cSkeletonDataBankEntryPtr_push_back(void*, N3A9**);
}
extern "C" void cSkeletonDataBank_AddSkeletonData_charP_cFileManR(int* out, void* list, char* name, void* file) {
    int n[1];
    N3A9* tmp[1];
    int cnt;
    N3A9* node;
    n[0] = 0;
    cFileMan_Open(file);
    cFileMan_Read_charPP_int(file, n, 0);
    cFileMan_Close(file);
    cnt = n[0];
    {
        AllocGuard g;
        node = (N3A9*)cMemMan_Allocate(0, 0x10, D_004BCCF8, 0x60);
    }
    if (node) {
        int len = strlen(name) + 1;
        char* s;
        {
            AllocGuard g;
            s = (char*)cMemMan_Allocate(0, len, "skeleton.hh", 0x61);
        }
        node->name = s;
        node->count = cnt;
        Libc_Strcpy(node->name, name);
    }
    tmp[0] = node;
    std_list_cSkeletonDataBankEntryPtr_push_back(list, tmp);
    *out = cnt;
}
static inline void merge_flush_func_003A9F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A9F90 */
