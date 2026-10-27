/*
 * Libs/SFOLib/Source/character: 5 files, 003E5D70-003E5EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E5D70 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_5E40;
typedef struct { V_5E40 a; V_5E40 b; float c; float d; int e; } T_5E40;
T_5E40* cDestinationParams_ctor_cDestinationParamsR(T_5E40* d, const T_5E40* s); /* gsynth: defined below */
#pragma cplusplus on
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004E0100[];
#if 0 /* merge_units */
void cDestinationParams_ctor_cDestinationParamsR(void* dst, void* src);
#endif /* merge_units */
#define cDestinationParams_ctor_cDestinationParamsR(a0, a1) ((void)cDestinationParams_ctor_cDestinationParamsR((T_5E40 *)(a0), (const T_5E40 *)(a1))) /* merge_units */


void cCharActionMsg_ctor_cCharActionMsgR(void* self, void* other);
}
struct PM5D70 { void* vtable; char pad[8]; int wC; char pad2[0x20]; char payload[0x30]; };
extern "C" PM5D70* cCharActionMsg_DestinationParams_Clone(PM5D70* self)
{
    PM5D70* p;
    {
        AllocGuard guard;
        p = (PM5D70*)cMemMan_Allocate(0, 0x60, "character.hh", 0x40E);
    }
    if (p) {
        cCharActionMsg_ctor_cCharActionMsgR(p, self);
        cDestinationParams_ctor_cDestinationParamsR(p->payload, self->payload);
        p->vtable = D_004E0100;
    }
    p->wC = self->wC;
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E5D70(void) {}
#undef cDestinationParams_ctor_cDestinationParamsR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E5D70 */

/* merge_units: begin func_003E5E40 */
#pragma push /* merge_units */
static inline V_5E40* VAsg_(V_5E40* d, const V_5E40* s) { *d = *s; return d; }
#pragma push
#pragma peephole off
#pragma opt_dead_assignments off
#pragma opt_propagation off
#pragma opt_common_subs off
T_5E40* cDestinationParams_ctor_cDestinationParamsR(T_5E40* d, const T_5E40* s) {
    void* r;
    r = VAsg_(&d->a, &s->a); r = VAsg_(&d->b, &s->b); d->c = s->c; d->d = s->d; d->e = s->e; r = d;
    return r;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E5E40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E5E40 */

/* merge_units: begin func_003E5E80 */
#pragma push /* merge_units */
/* GCC-style VU0 asm (operand form) lets MW schedule the p->x/y/z loads in retail order. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline float Dot3(const V4* a, const V4* b)
{
    int rv0;
    float ret;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah zero, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddz.w vf4, vf0, vf3z; qmfc2.ni %0, vf4; qfsrv %0, %0, %0; mtc1 %0, %1" : "=&r"(rv0), "=f"(ret) : "r"(a), "r"(b) : "memory");
    return ret;
}
static inline void MK(V4* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
#pragma peephole off
#pragma opt_propagation off
void func_003E5E80(V4* out, const V4* n, const V4* p)
{
    V4 t;
    float d = Dot3(p, n);
    MK(&t, p->x, p->y, p->z, -d);
    *out = t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E5E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E5E80 */

/* merge_units: begin func_003E5EE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "character_types.h"

float func_003E5EE0(Character* self) {
    return self->unk0C;
}
static inline void merge_flush_func_003E5EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E5EE0 */

/* merge_units: begin func_003E5EF0 */
#pragma push /* merge_units */
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4_ func_003E5EF0(const V4_* v) {
    V4_ t;
    float zf = 0.0f;
    V4_* d = &t;
    VCopyF(d, v);
    {
        V4_* e = &t;
        e->w = zf;
        return *e;
    }
}
#pragma pop
static inline void merge_flush_func_003E5EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E5EF0 */
