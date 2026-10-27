/*
 * SFOGame/Source/GuiAgentInfo: 11 files, 00363CD0-00364150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00363CD0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma opt_propagation off
#pragma peephole off
#pragma opt_common_subs off
typedef struct {
    unsigned char on;
    unsigned char zero;
    char pad02[2];
    float f;
    char pad08[8];
    Vec4 v;
} Obj290860;
static inline Vec4 CopyAsPoint_(Vec4* src) {
    Vec4 t;
    Vec4* p;
    t = *src;
    p = &t;
    p->w = 1.0f;
    return *p;
}
Obj290860* func_00363CD0(Obj290860* o, Vec4* v, float f) {
    int k, fl; unsigned char r;
    o->on = 1;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    o->zero = r;
    o->f = f;
    { Vec4 tmp; Vec4* ps; Vec4* dst; tmp = CopyAsPoint_(v); dst = &o->v; ps = &tmp; *dst = *ps; }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00363CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00363CD0 */

/* merge_units: begin func_00363D60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00363D60)
static inline void merge_flush_func_00363D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363D60 */

/* merge_units: begin func_00363DB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int* func_00363DB0(PtrVec* v) {
    return v->data + v->count;
}

void func_00363DD0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_00363DE0(char* self) {
    return *(int*)(self + 8);
}

void* func_00363DF0(char* self) {
    return self + 8;
}

void* func_00363E00(char* self) {
    return self + 11856;
}
static inline void merge_flush_func_00363DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363DB0 */

/* merge_units: begin func_00363E10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00363E10)
static inline void merge_flush_func_00363E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363E10 */

/* merge_units: begin func_00363E60 */
#pragma push /* merge_units */
#include "GuiAgentInfo_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_00363E60(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00363E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363E60 */

/* merge_units: begin func_00363E80 */
#pragma push /* merge_units */
#include "loose01_types.h"

#pragma opt_propagation off
#pragma peephole off
#pragma opt_common_subs off
typedef struct {
    int a;
    unsigned char zero;
    char pad05[3];
    float f;
    char pad0c[4];
    Vec4 v;
} Obj2909C0;
Obj2909C0* func_00363E80(Obj2909C0* o, int a, Vec4* v, float f) {
    int k, fl; unsigned char r;
    o->a = a;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    o->zero = r;
    o->f = f;
    {
        /* inlined copy-as-point (w = 1) into tmp, then tmp -> o->v */
        Vec4 tmp; Vec4* ps; Vec4* dst; Vec4 t; Vec4* p;
        p = &t; t = *v; p->w = 1.0f;
        { Vec4* pt = &tmp; *pt = *p; }
        dst = &o->v; ps = &tmp; *dst = *ps;
    }
    return o;
}
static inline void merge_flush_func_00363E80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363E80 */

/* merge_units: begin func_00363F10 */
#pragma push /* merge_units */
typedef struct ObjC0 {
    char pad[0xC];
    signed char flag;
} ObjC0;

extern void std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(ObjC0*);
extern void std_vector_pod_int_reserve(ObjC0*, int);

/* Constructor: base init, then std_vector_pod_int_reserve(self, *src) and flag byte at +0xC. */
ObjC0* func_00363F10(ObjC0* o, int* src, int flag) {
    std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(o);
    std_vector_pod_int_reserve(o, *src);
    o->flag = flag;
    return o;
}
static inline void merge_flush_func_00363F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363F10 */

/* merge_units: begin func_00363F60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00363F60)
static inline void merge_flush_func_00363F60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00363F60 */

/* merge_units: begin func_00364050 */
#pragma push /* merge_units */
Rel* func_00364050(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00364050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364050 */

/* merge_units: begin func_00364070 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "owned_buffer8_dtor.h"

/* Free the owned buffer, optionally delete. */
DEFINE_OWNED_BUFFER8_DTOR(func_00364070, D_0049AF00)
static inline void merge_flush_func_00364070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364070 */

/* merge_units: begin func_00364150 */
#pragma push /* merge_units */
/* Copies a 3x4 block into the matrix at +0x10 (xyz of each row, then w). */
void Mtx44_SetRows123FromMtx34_364150(MtxHolder* self, Mtx34* src) {
    self->m[0][0] = src->m[0][0];
    self->m[0][1] = src->m[0][1];
    self->m[0][2] = src->m[0][2];
    self->m[1][0] = src->m[1][0];
    self->m[1][1] = src->m[1][1];
    self->m[1][2] = src->m[1][2];
    self->m[2][0] = src->m[2][0];
    self->m[2][1] = src->m[2][1];
    self->m[2][2] = src->m[2][2];
    self->m[0][3] = src->m[0][3];
    self->m[1][3] = src->m[1][3];
    self->m[2][3] = src->m[2][3];
}
static inline void merge_flush_func_00364150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364150 */
