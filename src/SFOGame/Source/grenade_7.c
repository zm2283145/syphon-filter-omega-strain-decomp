/*
 * SFOGame/Source/grenade: 4 files, 0025C9D0-0025CCE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025C9D0 */
#pragma push /* merge_units */
#include "types.h"

/* Converts four floats to ints scaled by 128. */
int* tIRGBA_opAssign_tRGBAR(int* out, float* in) {
    out[0] = (int)(128.0f * in[0]);
    out[1] = (int)(128.0f * in[1]);
    out[2] = (int)(128.0f * in[2]);
    out[3] = (int)(128.0f * in[3]);
    return out;
}
static inline void merge_flush_func_0025C9D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025C9D0 */

/* merge_units: begin func_0025CA40 */
#pragma push /* merge_units */
typedef struct V4_0025CA40 { float x, y, z, w; } V4_0025CA40;
typedef struct Blk_0025CA40 { char pad[0x80]; int idx[12]; char padB0[0x10]; } Blk_0025CA40;
typedef struct Ent_0025CA40 {
    char pad[0x24];
    Blk_0025CA40* blocks;
    V4_0025CA40* pos;
    V4_0025CA40* c2C;
    V4_0025CA40* c30;
    V4_0025CA40* c34;
    char pad38[0x38 - 0x38];
} Ent_0025CA40;
typedef struct Strip_0025CA40 {
    char pad0[8];
    long long flags;
    char pad10[0xFB0 - 0x10];
    Ent_0025CA40 ents[1];
    char padFE8[0x1020 - 0xFE8];
    int cur;
    int pad1024;
    int pad1028;
    int n102C;
    int nBlocks;
    int nVerts;
    int n1038;
    int* list;
    int run;
    int n1044;
    int n1048;
    int maxRun;
} Strip_0025CA40;
extern void cVector_opAssign(V4_0025CA40* dst, V4_0025CA40* src);
#if 0 /* merge_units */
extern void tIRGBA_opAssign_tIRGBAR(V4_0025CA40* dst, V4_0025CA40* src);
#endif /* merge_units */
Quad * tIRGBA_opAssign_tIRGBAR(); /* merge_units */

void XLib_NextBatchVert(Strip_0025CA40* s)
{
    if (s->run == s->maxRun) {
        int v;
        int i;
        Blk_0025CA40* p;
        Ent_0025CA40* e;
        if (s->nBlocks > 0)
            s->list[s->nBlocks - 1] = s->run;
        v = s->n1048 - 1;
        p = &s->ents[s->cur].blocks[s->nBlocks];
        for (i = 0; i < 12; i++)
            p->idx[i] = v;
        s->n1038++;
        s->nBlocks++;
        s->run = 0;
        s->n1044 = 0;
        e = &s->ents[s->cur];
        cVector_opAssign(&e->pos[s->nVerts], &e->pos[s->nVerts - 2]);
        cVector_opAssign(&e->pos[s->nVerts + 1], &e->pos[s->nVerts - 1]);
        if (s->flags & 0x200000000LL) {
            tIRGBA_opAssign_tIRGBAR(&e->c30[s->nVerts], &e->c30[s->nVerts - 2]);
            tIRGBA_opAssign_tIRGBAR(&e->c30[s->nVerts + 1], &e->c30[s->nVerts - 1]);
        }
        if (s->flags & 0x400000000LL) {
            cVector_opAssign(&e->c34[s->nVerts], &e->c34[s->nVerts - 2]);
            cVector_opAssign(&e->c34[s->nVerts + 1], &e->c34[s->nVerts - 1]);
        }
        if (s->flags & 0x100000000LL) {
            cVector_opAssign(&e->c2C[s->nVerts], &e->c2C[s->nVerts - 2]);
            cVector_opAssign(&e->c2C[s->nVerts + 1], &e->c2C[s->nVerts - 1]);
        }
        s->run += 2;
        s->nVerts += 2;
        s->n102C += 2;
    }
    s->run++;
    s->nVerts++;
    s->n102C++;
}
static inline void merge_flush_func_0025CA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025CA40 */

/* merge_units: begin func_0025CCE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


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
