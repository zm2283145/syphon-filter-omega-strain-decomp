/*
 * SFOGame/Source/human: 3 files, 00190A00-00190B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00190A00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct S {
    signed char a;
    V v10;
    V v20;
    V v30;
    V v40;
};
extern "C" { extern signed char D_004E1D88; extern V D_004E1D90; }
static inline const V& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0.0f; D_004E1D88 = 1; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f; } return D_004E1D90; }
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" S* cSkaAnimDataSample_ctor_void(S* p)
{
    p->a = 0;
    p->v10 = Zero();
    p->v20 = Zero();
    { V u = Unit(); p->v30 = u; }
    p->v40 = Unit();
    return p;
}
static inline void merge_flush_func_00190A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00190A00 */

/* merge_units: begin func_00190B00 */
#pragma push /* merge_units */
#include "types.h"

typedef struct {
    unsigned int type;
    unsigned int frames;
    int stride;
    int pad0C;
    int loop;
} ClipData;
typedef struct {
    ClipData* d;
    int pad04;
    int pad08;
    float t;
    int i10;
    float frac;
    float* a;
    float* b;
    unsigned char done;
} ClipCursor;
void cSkaAnimDataIterator_GotoAnimFrame(ClipCursor* c, float t) {
    float len;
    unsigned int frames;
    int stride;
    ClipData* d;
    unsigned int type;
    unsigned int idx;
    int i0;
    float* base;
    int i1;
    c->t = t;
    c->done = 0;
    len = (int)c->d->frames;
    if (c->d->loop) {
        while (c->t >= len) {
            c->t -= len;
        }
    } else if (c->t >= len) {
        c->t = len;
        c->done = 1;
    }
    frames = c->d->frames;
    stride = c->d->stride;
    c->i10 = 0;
    d = c->d;
    type = d->type;
    if (type >= 3) {
        base = (float*)((char*)d + 0x70);
    } else if (type == 2) {
        base = (float*)((char*)d + 0x40);
    } else {
        base = (float*)((char*)d + 0x30);
    }
    idx = (int)c->t;
    i0 = idx * d->stride;
    if (d->loop) {
        i1 = (idx < frames - 1) ? i0 + stride : 0;
    } else {
        i1 = (idx < frames) ? i0 + stride : i0;
    }
    c->frac = c->t - idx;
    c->a = base + i0;
    c->b = base + i1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190B00 */

/* merge_units: begin func_00190C70 */
#pragma push /* merge_units */
typedef struct {
    void* d;
    int pad04;
    int pad08;
    float t;
    int i10;
    float frac;
    float* a;
    float* b;
    unsigned char done;
} ClipCursor_00190C70;
extern unsigned int nSFO_Macros_FTOI(float);
extern float* cSkaAnimData_DataStart(void*);
extern int cSkaAnimData_GetFrameSize(void*);
extern int cSkaAnimData_IsLooping(void*);
extern int cSkaAnimData_GetFrameCount(void*);
extern void* cPointer_cSkaAnimData_opArrow(ClipCursor_00190C70*);
void cSkaAnimDataIterator_GotoStartAnimFrame(ClipCursor_00190C70* c) {
    float len;
    unsigned int frames;
    int stride;
    unsigned int idx;
    int i0;
    float* base;
    int i1;
    c->t = 0.0f;
    c->done = 0;
    len = cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(c));
    if (cSkaAnimData_IsLooping(cPointer_cSkaAnimData_opArrow(c))) {
        while (c->t >= len) {
            c->t -= len;
        }
    } else if (c->t >= len) {
        c->t = len;
        c->done = 1;
    }
    frames = cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(c));
    stride = cSkaAnimData_GetFrameSize(cPointer_cSkaAnimData_opArrow(c));
    c->i10 = 0;
    base = cSkaAnimData_DataStart(cPointer_cSkaAnimData_opArrow(c));
    idx = nSFO_Macros_FTOI(c->t);
    i0 = idx * cSkaAnimData_GetFrameSize(cPointer_cSkaAnimData_opArrow(c));
    if (cSkaAnimData_IsLooping(cPointer_cSkaAnimData_opArrow(c))) {
        i1 = (idx < frames - 1) ? i0 + stride : 0;
    } else {
        i1 = (idx < frames) ? i0 + stride : i0;
    }
    c->frac = c->t - idx;
    c->a = base + i0;
    c->b = base + i1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190C70 */
