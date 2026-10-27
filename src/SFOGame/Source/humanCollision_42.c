/*
 * SFOGame/Source/humanCollision: 5 files, 001EF450-001EF6C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EF450 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_opAssign(int, int);

int std_vector_imp_cCollisionEdgePtr_1_opAssign(int a0, int a1) {
    std_vector_pod_int_opAssign(a0, a1);
    return a0;
}
static inline void merge_flush_func_001EF450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF450 */

/* merge_units: begin func_001EF480 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "range_copy_backward_assign.h"
DEFINE_COPY_BACKWARD_ELEMENT(E1EF480, 16)
DEFINE_RANGE_COPY_BACKWARD_ASSIGN(std_copy_backward_cEdgeGroup_copy_backward, E1EF480, cArray_cCollisionEdgePtr_opAssign)
static inline void merge_flush_func_001EF480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF480 */

/* merge_units: begin func_001EF4F0 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int std_vector_pod_int_ctor(ObjVec*, ObjVec*);

/* Array copy constructor: copy contents, then the owns-storage flag. */
ObjVec* cEdgeGroup_ctor_cEdgeGroupR(ObjVec* dst, ObjVec* src) {
    std_vector_pod_int_ctor(dst, src);
    dst->owned = src->owned;
    return dst;
}
static inline void merge_flush_func_001EF4F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF4F0 */

/* merge_units: begin func_001EF530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct E1EF530 { int w[4]; };
struct V1EF530 { unsigned int cap; unsigned int count; E1EF530* data; };
extern "C" {
extern char D_004A0558[];
void* opNew_uint_voidP(unsigned int size, void* p);
#if 0 /* merge_units */
void cEdgeGroup_ctor_cEdgeGroupR(void* dst, const E1EF530* src);
#endif /* merge_units */
#define cEdgeGroup_ctor_cEdgeGroupR(a0, a1) ((void)cEdgeGroup_ctor_cEdgeGroupR((ObjVec *)(a0), (ObjVec *)(a1))) /* merge_units */

void std_swap_vectordeleterR_vectordeleterR_12(V1EF530* a, V1EF530* b);
void std_vector_deleter_cEdgeGroup_dtor(V1EF530* a, int f);
}
extern "C" void std_vector_imp_cEdgeGroup_reserve(V1EF530* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x600000) {
            Libc_Fprintf(D_00489738->stream, "vector::reserve length error\n");
            Libc_Abort();
        }
        V1EF530 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E1EF530*)TStr_Alloc(n * sizeof(E1EF530), D_004A0558, 0x5C);
        tmp.cap = n;
        E1EF530* d = tmp.data;
        E1EF530* s = v->data;
        E1EF530* e = s + v->count;
        for (; s < e; s++, d++) {
            void* o = opNew_uint_voidP(sizeof(E1EF530), d);
            if (o) cEdgeGroup_ctor_cEdgeGroupR(o, s);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_12(&tmp, v);
        std_vector_deleter_cEdgeGroup_dtor(&tmp, -1);
    }
}
#undef cEdgeGroup_ctor_cEdgeGroupR /* merge_units */
static inline void merge_flush_func_001EF530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF530 */

/* merge_units: begin func_001EF6C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_propagation off

struct V4q {
    float x, y, z, w;
    V4q(const V4q& o) { const V4q* s = &o; V4q* d = this; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
} __attribute__((aligned(16)));
struct V4r {
    float x, y, z, w;
    V4r(const V4r& o) { V4r* d = this; const V4r* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
} __attribute__((aligned(16)));
struct F2 { float x, y; };
struct E1EF6C0 {
    V4q a;
    V4q b;
    V4q c;
    unsigned char d;
    float e;
    V4r f;
    F2 g;
    int h;
};
struct V1EF6C0 { unsigned int cap; unsigned int count; E1EF6C0* data; };
extern "C" {
extern char D_004A04E0[];
extern char D_004A0548[];
void std_swap_vectordeleterR_vectordeleterR_13(V1EF6C0* a, V1EF6C0* b);
void std_vector_deleter_cCollisionEdge_dtor(V1EF6C0* a, int f);
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline void Construct1EF6C0(E1EF6C0* p, const E1EF6C0* s)
{
    new (p) E1EF6C0(*s);
}
extern "C" void std_vector_imp_cCollisionEdge_reserve(V1EF6C0* v, unsigned int n)
{
    if (v->cap < n) {
        unsigned int mx = 0x100000;
        if (n > mx) {
            Libc_Fprintf(D_00489738->stream, D_004A04E0);
            Libc_Abort();
        }
        V1EF6C0 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E1EF6C0*)TStr_Alloc(n * sizeof(E1EF6C0), D_004A0548, 0x5C);
        { unsigned int* pc = &tmp.cap; *pc = n; }
        E1EF6C0* d = tmp.data;
        E1EF6C0* s = v->data;
        E1EF6C0* e = s + v->count;
        for (; s < e; s++, d++) {
            Construct1EF6C0(d, s);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_13(&tmp, v);
        std_vector_deleter_cCollisionEdge_dtor(&tmp, -1);
    }
}
static inline void merge_flush_func_001EF6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF6C0 */
