/*
 * main/human: range (2 files, 00190B00-00190C70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00190B00 */
#pragma push /* merge_units */
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
void Clip_AdvanceCursor(ClipCursor* c, float t) {
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
extern unsigned int Math_TruncFloatSat(float);
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
    idx = Math_TruncFloatSat(c->t);
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
