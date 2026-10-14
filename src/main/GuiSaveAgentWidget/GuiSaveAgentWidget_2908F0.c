/*
 * main/GuiSaveAgentWidget: 5 files, 002908F0-00290AA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002908F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_002908F0)
#pragma pop /* merge_units */
/* merge_units: end func_002908F0 */

/* merge_units: begin func_00290940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int PtrVec_Insert(PtrVec*, int*, int, int*);

int* func_00290940(PtrVec* v) {
    return v->data + v->count;
}

void func_00290960(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_00290970(PtrVec* v) {
    return v->data;
}

int** func_00290980(PtrVec* v) {
    return &v->data;
}

void* func_00290990(char* self) {
    return self + 11856;
}

/* push_back */
int func_002909A0(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_00290940 */

/* merge_units: begin func_002909C0 */
#pragma push /* merge_units */
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
Obj2909C0* func_002909C0(Obj2909C0* o, int a, Vec4* v, float f) {
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
#pragma pop /* merge_units */
/* merge_units: end func_002909C0 */

/* merge_units: begin func_00290A50 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Obj00290A50;
extern void func_00290B90(Obj00290A50* obj, int* src, unsigned char flag);
extern void func_001396D0(Obj00290A50* obj, int value);
/* Construct from src and flag; returns obj. */
Obj00290A50* func_00290A50(Obj00290A50* obj, int* src, unsigned char flag)
{
    func_00290B90(obj, src, flag);
    func_001396D0(obj, *src);
    obj->flag = flag;
    return obj;
}
#pragma pop /* merge_units */
/* merge_units: end func_00290A50 */

/* merge_units: begin func_00290AA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00290AA0)
#pragma pop /* merge_units */
/* merge_units: end func_00290AA0 */
