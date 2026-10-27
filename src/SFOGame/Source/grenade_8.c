/*
 * SFOGame/Source/grenade: 2 files, 0025CCE0-0025CD10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025CCE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Quad* tIRGBA_opAssign_tIRGBAR(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
static inline void merge_flush_func_0025CCE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025CCE0 */

/* merge_units: begin func_0025CD10 */
#pragma push /* merge_units */
typedef struct { char pad[0x80]; int v[12]; char pad2[0xC0 - 0xB0]; } Rec_CD10;
typedef struct { char pad[0x34]; Rec_CD10* recs; } Ent_CD10;
typedef struct {
    char pad[0xFA0];
    Ent_CD10 ent[1];
    char pad1[0x1020 - 0xFA0 - 0x38];
    int cur;        /* 0x1020 */
    char pad1024[0xC];
    int n;          /* 0x1030 */
    int pad1034;
    int count;      /* 0x1038 */
    int* arr;       /* 0x103C */
    int val;        /* 0x1040 */
    int val2;       /* 0x1044 */
    int x1048;      /* 0x1048 */
} S_CD10;
void XLib_NewStrip(S_CD10* s)
{
    int v;
    int i;
    Rec_CD10* r;
    if (s->n > 0) s->arr[s->n - 1] = s->val;
    v = s->x1048 - 1;
    r = &s->ent[s->cur].recs[s->n];
    for (i = 0; i < 12; i++) r->v[i] = v;
    s->count++;
    s->n++;
    s->val = 0;
    s->val2 = 0;
}
static inline void merge_flush_func_0025CD10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025CD10 */
