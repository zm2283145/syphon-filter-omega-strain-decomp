/*
 * Libs/SFOLib/Source/interface_model: 2 files, 003ECAF0-003ECB50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ECAF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int details_compressed_pair_imp_cAllocator_voidPtr_int_1_first(List*);

/* Constructs an empty list (sentinel at +4). */
List* std_list_cSfxSchedulerPtr_ctor(List* l) {
    l->count = 0;
    details_compressed_pair_imp_cAllocator_voidPtr_int_1_first(l);
    l->last = &l->first;
    l->first = &l->first;
    return l;
}

/* Initializes an empty vector header. */
L4OwnedVec* cSfxScheduler_tItem_ctor(L4OwnedVec* self) {
    self->vec.unk0 = 0;
    self->vec.count = 0;
    self->vec.data = 0;
    self->owned = 0;
    return self;
}
static inline void merge_flush_func_003ECAF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ECAF0 */

/* merge_units: begin func_003ECB50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r0, r1, r2, t; };
static inline void MulV(V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V operator*(const V& v, M& m) { V t = v; MulV(&t, &m); return t; }
struct V3 { float x, y, z; };
struct Rect { float x, z, w, h; };
struct Obj {
    char pad0[0x20];
    M m;
    char pad60[0x64 - 0x60];
    unsigned short nverts;
    char pad66[0x6C - 0x66];
    unsigned short nsub;
    char pad6E[0x70 - 0x6E];
    V3* verts;
    char pad74[0x80 - 0x74];
    int* subs;
};
extern "C" void cAnimator_SetFrame(int s, float f);
extern "C" void cInterfaceModel_GetBounds(Rect* out, Obj* obj, float f)
{
    float b[4];
    int i;
    int j;
    b[2] = 10000.0f;
    b[3] = 10000.0f;
    b[0] = -10000.0f;
    b[1] = -10000.0f;
    if (!(f < 0.0f)) {
        for (i = 0; i < obj->nsub; i++)
            cAnimator_SetFrame(obj->subs[i], f);
    }
    for (j = 0; j < obj->nverts; j++) {
        V p(obj->verts[j].x, obj->verts[j].y, obj->verts[j].z, 1.0f);
        p = p * obj->m;
        if (p.x < b[2]) b[2] = p.x;
        if (!(p.x <= b[0])) b[0] = p.x;
        if (p.z < b[3]) b[3] = p.z;
        if (!(p.z <= b[1])) b[1] = p.z;
    }
    float x0 = b[2];
    float x1 = b[0];
    float z0;
    float z1;
    if (!(x0 <= x1) || !((z0 = b[3]) <= (z1 = b[1]))) {
        out->x = 0.0f;
        out->z = 0.0f;
        out->w = 0.0f;
        out->h = 0.0f;
    } else {
        x1 -= x0;
        z1 -= z0;
        out->x = x0;
        out->z = z0;
        out->w = x1;
        out->h = z1;
    }
}
static inline void merge_flush_func_003ECB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ECB50 */
