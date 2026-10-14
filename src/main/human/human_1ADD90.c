/*
 * main/human: range (2 files, 001ADD90-001ADE40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001ADD90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Res_1ADD90 { int a; int b; Res_1ADD90() {} };
class Obj_1ADD90 { public: VPAD2(p) virtual Res_1ADD90 Get(); };
typedef struct { int o; } Ref_1ADD90;
typedef struct { char name[0x30]; Ref_1ADD90 ref; int ra; int rb; } __attribute__((aligned(16))) MR_1ADD90;
typedef struct { char pad[0x34]; int reg; } Map_1ADD90;
extern "C" int NodeNameMap_Find(Map_1ADD90* m, MR_1ADD90* name);
extern "C" Ref_1ADD90* Registry_At(int* reg, int idx);
static inline void QZero_1ADD90(void* d0) { int n = 3; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
extern "C" void MotionRequest_ResolveName(MR_1ADD90* mr, Map_1ADD90* m)
{
    if (mr->name[0]) {
        volatile int t;
        t = Registry_At(&m->reg, NodeNameMap_Find(m, mr))->o;
        mr->ref.o = t;
        Res_1ADD90 r = ((Obj_1ADD90*)mr->ref.o)->Get();
        mr->ra = r.a;
        mr->rb = r.b;
        if (mr->name[0]) QZero_1ADD90(mr);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADD90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADD90 */

/* merge_units: begin func_001ADE40 */
#pragma push /* merge_units */
typedef struct { int w[12]; } __attribute__((aligned(16))) MRHead_c7;
typedef struct {
    MRHead_c7 head;
    int a30, a34, a38;
    float f3C, f40, f44, f48, f4C, f50, f54, f58;
    void* vt5C;
    int b60, b64, b68, b6C, b70, b74, b78;
    signed char c7C;
    int d80;
    signed char c84;
    int d88;
    unsigned char c8C;
    float f90;
} MotionReq_c7;
extern char D_004DFD80[];
extern char D_004DA930[];
static inline void QCopy_c7(void* d0, void* s0) { int n = 3; void* s = s0; void* d = d0;
    asm {
        .set noreorder
        nop
    lp:
        lq $a2, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a2, -0x10(d)
        .set reorder
    }
}
MotionReq_c7* MotionRequest_Copy(MotionReq_c7* d, MotionReq_c7* s) {
    QCopy_c7(&d->head, &s->head);
    d->a30 = s->a30; d->a34 = s->a34; d->a38 = s->a38;
    d->f3C = s->f3C; d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48;
    d->f4C = s->f4C; d->f50 = s->f50; d->f54 = s->f54; d->f58 = s->f58;
    d->vt5C = D_004DFD80;
    d->b60 = s->b60; d->b64 = s->b64; d->b68 = s->b68; d->b6C = s->b6C;
    d->b70 = s->b70; d->b74 = s->b74; d->b78 = s->b78;
    d->c7C = s->c7C;
    d->vt5C = D_004DA930;
    d->d80 = s->d80; d->c84 = s->c84; d->d88 = s->d88; d->c8C = s->c8C; d->f90 = s->f90;
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001ADE40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001ADE40 */
