/*
 * Libs/SFOLib/Source/collision: 17 files, 003C0D90-003C14F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C0D90 */
#pragma push /* merge_units */
#include "types.h"

void cCollisionModel_EdgeId_GetIndicesIntoFaceVertexList(int a0, int a1, int a2, int a3) {
    int v1;
    int cond;

    v1 = *(int*)((char*)a0 + 4);
    cond = v1 != 0;
    if (cond) goto L003C0DB8;
    *(int*)(char*)a1 = 0;
    v1 = 0 + 1;
    *(int*)(char*)a2 = v1;
    v1 = 0 + 2;
    *(int*)(char*)a3 = v1;
    goto L003C0DE8;
L003C0DB8:;
    a0 = 0 + 1;
    cond = v1 != a0;
    if (cond) goto L003C0DD8;
    *(int*)(char*)a1 = a0;
    v1 = 0 + 2;
    *(int*)(char*)a2 = v1;
    *(int*)(char*)a3 = 0;
    goto L003C0DE8;
L003C0DD8:;
    v1 = 0 + 2;
    *(int*)(char*)a1 = v1;
    *(int*)(char*)a2 = 0;
    *(int*)(char*)a3 = a0;
L003C0DE8:;
    goto ret;
ret:;
}
static inline void merge_flush_func_003C0D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0D90 */

/* merge_units: begin func_003C0DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int std_vector_cCollisionEdge_capacity(char* self) {
    return *(int*)(self + 0);
}
static inline void merge_flush_func_003C0DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0DF0 */

/* merge_units: begin func_003C0E00 */
#pragma push /* merge_units */
typedef struct { int tri; int side; void* mesh; } ColEdge_f3;
extern void* cCollisionModel_GetFace(void* mesh, int tri);
#if 0 /* merge_units */
extern int cCollisionModel_EdgeId_FaceVertexNumber0(ColEdge_f3* e);
#endif /* merge_units */
int cCollisionModel_EdgeId_FaceVertexNumber0(); /* merge_units */


#if 0 /* merge_units */
extern int cCollisionModel_EdgeId_FaceVertexNumber1(ColEdge_f3* e);
#endif /* merge_units */
unsigned int cCollisionModel_EdgeId_FaceVertexNumber1(); /* merge_units */


#if 0 /* merge_units */
extern int cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(void* tri, int i);
#endif /* merge_units */
int cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(); /* merge_units */


int cCollisionModel_EdgeLocator_IsSameEdge(ColEdge_f3* a, ColEdge_f3* b, void* mesh)
{
    void* t;
    int a0;
    int a1;
    int b0;
    int b1;
    if (a->mesh == mesh) {
        t = cCollisionModel_GetFace(a->mesh, a->tri);
        a0 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber0(a));
        a1 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber1(a));
        t = cCollisionModel_GetFace(mesh, b->tri);
        b0 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber0(b));
        b1 = cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(t, cCollisionModel_EdgeId_FaceVertexNumber1(b));
        return (a0 == b0 && a1 == b1) || (a0 == b1 && a1 == b0);
    }
    return 0;
}
static inline void merge_flush_func_003C0E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0E00 */

/* merge_units: begin func_003C0F10 */
#pragma push /* merge_units */
#include "collision_types.h"

typedef struct Cycle3 {
    int unk0;
    int index;
} Cycle3;

/* Returns the next index in a 0..2 cycle. */
unsigned int cCollisionModel_EdgeId_FaceVertexNumber1(Cycle3* c) {
    unsigned int next = c->index + 1;
    return next < 3 ? next : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0F10 */

/* merge_units: begin func_003C0F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Vertex index i of a raw triangle. */
int cCollisionModel_Face_GetIndexIntoVertexBlockOfCollisionModel(ColTri* tri, int i) {
    return tri->vert[i];
}

int cCollisionModel_EdgeId_FaceVertexNumber0(char* self) {
    return *(int*)(self + 4);
}

void* std_vector_deleter_cCollisionEdge_data(char* self) {
    return self + 8;
}

/* Address of the three edge flag bytes. */
unsigned char* cCollisionModel_Face_GetEdgeFlags(ColTri* tri) {
    return tri->edgeFlags;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C0F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C0F30 */

/* merge_units: begin func_003C0F70 */
#pragma push /* merge_units */
typedef struct { unsigned char b0, b1, b2, type; char pad[0x14]; int m18; } H0F70;
typedef struct { H0F70* h; } P20F70;
typedef struct { int m0; P20F70* q; } P10F70;
typedef struct { int idx; P10F70* p; } T0F70;
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(H0F70* h, int* x);
char* cCollisionModel_FaceLocator_Face(T0F70* t)
{
    int i = t->idx;
    H0F70* h = t->p->q->h;
    if (h->type < 4) {
        int x = h->m18;
        return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(h, &x) + i * 64;
    } else if (h->type < 5) {
        int x = h->m18;
        return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(h, &x) + i * 32;
    } else {
        int x = h->m18;
        return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(h, &x) + i * 16;
    }
}
static inline void merge_flush_func_003C0F70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C0F70 */

/* merge_units: begin func_003C1010 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cCollisionFace_FaceLocator(char* self) {
    return self + 96;
}
static inline void merge_flush_func_003C1010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C1010 */

/* merge_units: begin func_003C1020 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

struct V_3C1 {
    float x, y, z, w;
    V_3C1() {}
    // 128-bit lq/sq quadword copy idiom
    // (dead xx local reproduces retail's duplicated addiu of the destination)
    V_3C1& operator=(const V_3C1& o) { V_3C1* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Tri_3C1 { V_3C1 p0; V_3C1 p1; V_3C1 p2; V_3C1 n; char pad40[0x30]; };
struct It_3C1 {
    Tri_3C1* p;
    It_3C1() {}
    It_3C1(const It_3C1& o) : p(o.p) {}
    Tri_3C1* Get() const { return p; }
    bool operator==(const It_3C1& o) const { return Get() == o.Get(); }
    bool operator!=(const It_3C1& o) const { return !(*this == o); }
    Tri_3C1* Next() { Tri_3C1* r = p; p++; return r; }
};
struct Gath;
struct Scene_3C1;
#if 0 /* merge_units */
extern "C" Tri_3C1** std_vector_deleter_cCollisionFace_data_void_2(Scene_3C1* s);
#endif /* merge_units */
extern "C" void* std_vector_deleter_cCollisionFace_data_void_2(char* self); /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void_2(a0) ((Tri_3C1 * *)std_vector_deleter_cCollisionFace_data_void_2((char *)(a0))) /* merge_units */

struct Scene_3C1 {
    int cap;
    int count;
    Tri_3C1* data;
    It_3C1 Begin() { It_3C1 r; r.p = *std_vector_deleter_cCollisionFace_data_void_2(this); return r; }
    It_3C1 End() { It_3C1 r; r.p = *std_vector_deleter_cCollisionFace_data_void_2(this) + count; return r; }
};
// VU0 macro-mode: load triangle corners + scale into a fixed vf register group
#define LOADTRI(t, S) { int tmp; __asm__ volatile(S : "=&r"(tmp) : "r"(&t->p0), "r"(&t->p1), "r"(&t->p2), "f"(t->n.w) : "memory"); }

extern "C" void cCollisionModelList_CalculateFaceNormals(Gath* self, Scene_3C1* scene)
{
    It_3C1 it = scene->Begin();
    It_3C1 end = scene->End();
    V_3C1 n0;
    V_3C1 n1;
    V_3C1 n2;
    V_3C1 n3;
    // VU0 macro-mode: clear w of the normal accumulators
    __asm__ volatile("vmulx.w $vf25, $vf0, $vf0x; vmulx.w $vf26, $vf0, $vf0x; vmulx.w $vf27, $vf0, $vf0x; vmulx.w $vf28, $vf0, $vf0x");
    while (it != end) {
        Tri_3C1* t0 = it.Next();
        LOADTRI(t0, "lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); lqc2 $vf3, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf4");
        if (it != end) {
            Tri_3C1* t1 = it.Next();
            LOADTRI(t1, "lqc2 $vf5, 0x0(%1); lqc2 $vf6, 0x0(%2); lqc2 $vf7, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf8");
            if (it != end) {
                Tri_3C1* t2 = it.Next();
                LOADTRI(t2, "lqc2 $vf9, 0x0(%1); lqc2 $vf10, 0x0(%2); lqc2 $vf11, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf12");
                if (it != end) {
                    Tri_3C1* t3 = it.Next();
                    LOADTRI(t3, "lqc2 $vf13, 0x0(%1); lqc2 $vf14, 0x0(%2); lqc2 $vf15, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf16");
                    // VU0 macro-mode: four cross products scaled by w
                    __asm__ volatile(
                        "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vsub.xyzw $vf19, $vf6, $vf5; vsub.xyzw $vf20, $vf7, $vf5; vsub.xyzw $vf21, $vf10, $vf9; vsub.xyzw $vf22, $vf11, $vf9; vsub.xyzw $vf23, $vf14, $vf13; vsub.xyzw $vf24, $vf15, $vf13; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vopmula.xyz $ACC, $vf19, $vf20; vopmsub.xyz $vf26, $vf20, $vf19; vopmula.xyz $ACC, $vf21, $vf22; vopmsub.xyz $vf27, $vf22, $vf21; vopmula.xyz $ACC, $vf23, $vf24; vopmsub.xyz $vf28, $vf24, $vf23; vmulx.xyz $vf25, $vf25, $vf4x; vmulx.xyz $vf26, $vf26, $vf8x; vmulx.xyz $vf27, $vf27, $vf12x; vmulx.xyz $vf28, $vf28, $vf16x; sqc2 $vf25, 0x0(%0); sqc2 $vf26, 0x0(%1); sqc2 $vf27, 0x0(%2); sqc2 $vf28, 0x0(%3)"
                        : : "r"(&n0), "r"(&n1), "r"(&n2), "r"(&n3) : "memory");
                    t3->n = n3;
                } else {
                    // VU0 macro-mode: three cross products scaled by w
                    __asm__ volatile(
                        "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vsub.xyzw $vf19, $vf6, $vf5; vsub.xyzw $vf20, $vf7, $vf5; vsub.xyzw $vf21, $vf10, $vf9; vsub.xyzw $vf22, $vf11, $vf9; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vopmula.xyz $ACC, $vf19, $vf20; vopmsub.xyz $vf26, $vf20, $vf19; vopmula.xyz $ACC, $vf21, $vf22; vopmsub.xyz $vf27, $vf22, $vf21; vmulx.xyz $vf25, $vf25, $vf4x; vmulx.xyz $vf26, $vf26, $vf8x; vmulx.xyz $vf27, $vf27, $vf12x; sqc2 $vf25, 0x0(%0); sqc2 $vf26, 0x0(%1); sqc2 $vf27, 0x0(%2)"
                        : : "r"(&n0), "r"(&n1), "r"(&n2) : "memory");
                }
                t2->n = n2;
            } else {
                // VU0 macro-mode: two cross products scaled by w
                __asm__ volatile(
                    "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vsub.xyzw $vf19, $vf6, $vf5; vsub.xyzw $vf20, $vf7, $vf5; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vopmula.xyz $ACC, $vf19, $vf20; vopmsub.xyz $vf26, $vf20, $vf19; vmulx.xyz $vf25, $vf25, $vf4x; vmulx.xyz $vf26, $vf26, $vf8x; sqc2 $vf25, 0x0(%0); sqc2 $vf26, 0x0(%1)"
                    : : "r"(&n0), "r"(&n1) : "memory");
            }
            t1->n = n1;
        } else {
            // VU0 macro-mode: one cross product scaled by w
            __asm__ volatile(
                "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vmulx.xyz $vf25, $vf25, $vf4x; sqc2 $vf25, 0x0(%0)"
                : : "r"(&n0) : "memory");
        }
        t0->n = n0;
    }
}
#undef std_vector_deleter_cCollisionFace_data_void_2 /* merge_units */
static inline void merge_flush_func_003C1020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C1020 */

/* merge_units: begin func_003C13A0 */
#pragma push /* merge_units */
void* std_vector_deleter_cCollisionFace_data_void_2(char* self) {
    return self + 8;
}

void* cCollisionEdge_Vertex1(char* self) {
    return self + 16;
}
static inline void merge_flush_func_003C13A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C13A0 */

/* merge_units: begin func_003C13C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* VU0 ops as GCC-style asm; `.set noreorder` drops the assembler mfc1 hazard nop (retail has none).
   Dead `x1`/`x2` address locals give retail's dead addiu before the named-local copies. */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator+(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
extern "C" float GetDistanceSquaredPointToLine(const V* a, const V* b, const V* dir);
float GetDistanceSquaredPointToLine(const V* a, const V* b, const V* dir)
{
    V d1 = *a - *b;
    void* x1 = &d1;
    float t = d1.Dot(*dir);
    V c = *b + *dir * t;
    void* x2 = &c;
    return (*a - c).LenSq();
}
static inline void merge_flush_func_003C13C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C13C0 */

/* merge_units: begin func_003C14D0 */
#pragma push /* merge_units */
void* cCollisionEdge_UnitEdgeVector(char* self) {
    return self + 64;
}

void* cCollisionEdge_Vertex0(void* self) {
    return self;
}
static inline void merge_flush_func_003C14D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C14D0 */

/* merge_units: begin func_003C14F0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_C14;
typedef struct { char pad[0x40]; V4_C14 n; } C14_P;
static inline float Abs_C14(float x) { float r; asm { abs.s r, x } return r; }
static inline float Dot_C14(void* b, void* a) {
    void* pa = a; void* pb = b;
    int t;
    float r;
    asm {
        lqc2 vf1, 0(pa)
        lqc2 vf2, 0(pb)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
int AreNearParallel(C14_P* a, C14_P* b, float eps) {
    float d = Dot_C14(&b->n, &a->n);
    int r = 1;
    if (Abs_C14(d) < eps) r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C14F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C14F0 */

/* merge_units: begin func_003C1540 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* VU0 ops as GCC-style asm; `.set noreorder` drops the assembler mfc1 hazard nop (retail has none).
   Dead `x1`/`x2` address locals give retail's dead addiu before the named-local copies. */
static inline float DotR_(const void* a, const void* b) {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%3); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory");
        return r;
}
struct V_003C1540 {
    float x, y, z, w;
    V_003C1540() {}
    V_003C1540(const V_003C1540& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V_003C1540 operator-(const V_003C1540& b) const {
        V_003C1540 c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
    V_003C1540 operator+(const V_003C1540& b) const {
        V_003C1540 c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V_003C1540 operator*(float s) const {
        V_003C1540 c; __int128 t = 0; V_003C1540* q = &c; const V_003C1540* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot(const V_003C1540& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    float DotR(const V_003C1540& b) const { const V_003C1540* ap = this; return DotR_(ap, &b); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Flags {
    unsigned char bf;
    int K() const { return bf & ~0x80; }
};
static inline int Km(const unsigned char& c) { return c & ~0x80; }
struct Edge { V_003C1540 p0; V_003C1540 p1; char pad20[0x10]; Flags fl; char pad31[3]; float len; char pad38[8]; V_003C1540 n; };
extern "C" {
#if 0 /* merge_units */
int AreNearParallel(Edge* a, Edge* b, float eps);
#endif /* merge_units */
#define AreNearParallel(a0, a1, a2) (AreNearParallel((C14_P *)(a0), (C14_P *)(a1), (a2))) /* merge_units */



#if 0 /* merge_units */
V_003C1540* cCollisionEdge_Vertex0(Edge* e);
#endif /* merge_units */
#define cCollisionEdge_Vertex0(a0) ((V_003C1540 *)cCollisionEdge_Vertex0((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_003C1540* cCollisionEdge_UnitEdgeVector(Edge* e);
#endif /* merge_units */
#define cCollisionEdge_UnitEdgeVector(a0) ((V_003C1540 *)cCollisionEdge_UnitEdgeVector((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_003C1540* cCollisionEdge_Vertex1(Edge* e);
#endif /* merge_units */
#define cCollisionEdge_Vertex1(a0) ((V_003C1540 *)cCollisionEdge_Vertex1((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
float GetDistanceSquaredPointToLine(const V_003C1540* a, const V_003C1540* b, const V_003C1540* dir);
#endif /* merge_units */
#define GetDistanceSquaredPointToLine(a0, a1, a2) (GetDistanceSquaredPointToLine((const V *)(a0), (const V *)(a1), (const V *)(a2))) /* merge_units */

float MAX(float a, float b);
bool cCollisionEdge_CanBeConnected(Edge* a, Edge* b, float eps, float maxd, float tol);
}
bool cCollisionEdge_CanBeConnected(Edge* a_, Edge* b_, float eps, float maxd, float tol)
{
    Edge* bb = b_;
    Edge* aa = a_;
#define a aa
#define b bb
    bool r = false;
    Flags fa;
    Flags fb;
    fb.bf = b->fl.bf;
    fa.bf = a->fl.bf;
    const Flags* pa = &fa;
    if ((pa->bf & ~0x80) == (fb.bf & ~0x80)) {
        bool ok;
        if (AreNearParallel(a, b, eps))
            ok = MAX(GetDistanceSquaredPointToLine(cCollisionEdge_Vertex0(b), cCollisionEdge_Vertex0(a), cCollisionEdge_UnitEdgeVector(a)),
                      GetDistanceSquaredPointToLine(cCollisionEdge_Vertex1(b), cCollisionEdge_Vertex0(a), cCollisionEdge_UnitEdgeVector(a))) <= maxd;
        else ok = false;
        if (ok) {
            V_003C1540 d0 = b->p0 - a->p0;
                        float t0 = a->n.DotR(d0);
            V_003C1540 d1 = b->p1 - a->p0;
                        float t1 = a->n.DotR(d1);
            float len = a->len;
            if (t0 >= -tol && t0 <= len + tol) r = true;
            else if (t1 >= -tol && t1 <= len + tol) r = true;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C1540(void) {}
#undef AreNearParallel /* merge_units */
#undef cCollisionEdge_Vertex0 /* merge_units */
#undef cCollisionEdge_UnitEdgeVector /* merge_units */
#undef cCollisionEdge_Vertex1 /* merge_units */
#undef GetDistanceSquaredPointToLine /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C1540 */

/* merge_units: begin func_003C1790 */
#pragma push /* merge_units */
void cCollisionModelMaster_UnLoad(ColRef* self) {
    self->unk0 = 0;
    self->unk4 = 1;
}
static inline void merge_flush_func_003C1790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C1790 */

/* merge_units: begin func_003C17A0 */
#pragma push /* merge_units */
#include "vc_copy.h"
#include "v4_asm_copy.h"

typedef struct { float x; int pad[3]; __int128 q; } S003C1880;
#if 0 /* merge_units */
S003C1880* cSphere_opAssign(S003C1880* arg0, S003C1880* arg1); /* gsynth: defined below */
#endif /* merge_units */
S003C1880 * cSphere_opAssign(); /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 min; V4 max; } Box_18A0;
typedef struct { float r; int pad[3]; V4 c; } Sphere_18A0;
#if 0 /* merge_units */
void cBox_BoundingSphere(Sphere_18A0* out, Box_18A0* b); /* gsynth: defined below */
#endif /* merge_units */
void cBox_BoundingSphere(); /* merge_units */


typedef struct { int pad[7]; int f1C; } ColData_f3;
typedef struct { ColData_f3* data; unsigned char loaded; char pad[11]; int f10; } ColHolder_f3;
typedef struct { int w[11]; } ColTmp_f3;
extern int cFileMan_Open(void* f);
extern void cFileMan_Read_charPP_int(void* f, int* out, int z);
extern void cFileMan_Close(void* f);
extern void cCollisionModel_Data_FixUpPointers(ColData_f3* d);
extern void* cCollisionModel_Data_BoundingBox(ColData_f3* d);
#if 0 /* merge_units */
extern void cBox_BoundingSphere(ColTmp_f3* t, void* p);
#endif /* merge_units */
void cBox_BoundingSphere(); /* merge_units */




#if 0 /* merge_units */
extern void cSphere_opAssign(int* dst, ColTmp_f3* t);
#endif /* merge_units */
S003C1880 * cSphere_opAssign(); /* merge_units */




int cCollisionModelMaster_Load(ColHolder_f3* c, void* file)
{
    int buf[1];
    ColTmp_f3 tmp;
    if (c->data == 0) {
        buf[0] = 0;
        if ((unsigned char)cFileMan_Open(file)) {
            c->loaded = 1;
            return 0;
        }
        cFileMan_Read_charPP_int(file, buf, 0);
        cFileMan_Close(file);
        c->data = (ColData_f3*)buf[0];
        cCollisionModel_Data_FixUpPointers(c->data);
        cBox_BoundingSphere(&tmp, cCollisionModel_Data_BoundingBox(c->data));
        cSphere_opAssign(&c->f10, &tmp);
        {
            unsigned char b = 1;
            if (c->data != 0 && c->data->f1C != 0) b = 0;
            c->loaded = b;
        }
        return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C17A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C17A0 */

/* merge_units: begin func_003C1880 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
S003C1880 *cSphere_opAssign(S003C1880 *arg0, S003C1880 *arg1) {
    S003C1880 *s = arg1;
    arg0->x = s->x;
    {
        __int128 *src = &s->q;
        __int128 *dst = &arg0->q;
        { typedef char uf_chk_[sizeof(*dst) == 16 ? 1 : -1]; VCopyF(&(*dst), &(*src)); }
    }
    return arg0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C1880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C1880 */

/* merge_units: begin func_003C18A0 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_common_subs off
void cBox_BoundingSphere(Sphere_18A0* out, Box_18A0* b)
{
    V4 lenV;
    V4 cc;
    V4 sub;
    V4 ret;
    V4 mulV;
    V4 add;
    V4 mulT;
    float h;
    float len;
    { V4* d = &add; V4* mx = &b->max; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(mx); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    { void* xx = &mulV; }
    { __int128 tt; V4* s; V4* p; __int128 t1; V4* q; V4* d; asm { paddub tt, zero, zero } s = &add; p = &mulV; q = &mulT; d = &mulV; t1 = *(__int128*)s; *(__int128*)d = t1; h = 0.5f; asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, h; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder } ret = *q; }
    { void* xx = &cc; } { V4* d3 = &cc; V4* s3 = &ret; *d3 = *s3; }
    { V4* d = &sub; V4* mx = &b->max; asm { lqc2 vf1, 0x0(mx); lqc2 vf2, 0x0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    { V4* s4 = &sub; V4* d4 = &lenV; void* xx = &lenV; __int128 t4; len = 0.0f; t4 = *(__int128*)s4; *(__int128*)d4 = t4; { V4* v = &lenV; __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(v) : "memory"); } }
    { void* xx = &out->c; } out->r = 0.5f * len; out->c = cc;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C18A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C18A0 */
