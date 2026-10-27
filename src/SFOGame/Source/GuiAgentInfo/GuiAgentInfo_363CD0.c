/*
 * main/GuiAgentInfo: range (2 files, 00363CD0-00363D60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

/* merge_units: begin func_00363CD0 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_00363D60 */
