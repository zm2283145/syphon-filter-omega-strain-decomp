/*
 * lib/medius: 2 files, 00319718-00319910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00319718 */
#include "types.h"

typedef struct { float re; float im; } Cx319718;

static inline float Dist2_319718(Cx319718* a, Cx319718* b)
{
    float r;
    __asm__ volatile (
        "lwc1 $f1, 0(%1)\n"
        "lwc1 $f0, 0(%2)\n"
        "lwc1 $f2, 4(%1)\n"
        "sub.s $f0, $f1, $f0\n"
        "lwc1 $f1, 4(%2)\n"
        "mula.s $f0, $f0\n"
        "sub.s $f0, $f2, $f1\n"
        "madd.s %0, $f0, $f0\n"
        : "=f"(r) : "r"(a), "r"(b) : "$f0", "$f1", "$f2");
    return r;
}

extern void VQ2mbest(Cx319718* pos, Cx319718* tab, int n, int* out, int k);
extern float Dim2VectorLUT(int idx, Cx319718* tab, int n, Cx319718* out);
extern void RotScaleVQ2(Cx319718* a, Cx319718* tab, int idx, Cx319718* out);
extern void DeRotScaleVQ2(Cx319718* a, Cx319718* tab, int idx, Cx319718* out);
extern int SelectOutCellCB(int* a, int n, int v);
extern int Dim2VectorQuantize(Cx319718* p, Cx319718* pts, int n);

void RS2StageVQ2Enc(int* out, Cx319718* pos, int n, int nA, Cx319718* tabA, Cx319718* tabB,
                   int nC, Cx319718* ptsA, Cx319718* ptsB, int nList, int* list)
{
    int cand[4];
    Cx319718 cur;
    Cx319718 diff;
    Cx319718 rot;
    Cx319718 best;
    float bestD = 3.40281981555156e+38f;
    int i;

    VQ2mbest(pos, tabA, nA, cand, n);
    for (i = 0; i < n; i++) {
        int c = cand[i];
        Cx319718* pts;
        int j;
        float dx, dy, d;

        Dim2VectorLUT(c, tabA, nA, &cur);
        diff.re = pos->re - cur.re;
        diff.im = pos->im - cur.im;
        RotScaleVQ2(&diff, tabB, c, &rot);
        pts = SelectOutCellCB(list, nList, c) == 1 ? ptsB : ptsA;
        j = Dim2VectorQuantize(&rot, pts, nC);
        Dim2VectorLUT(j, pts, nC, &rot);
        DeRotScaleVQ2(&rot, tabB, c, &diff);
        cur.re += diff.re;
        cur.im += diff.im;
        d = Dist2_319718(pos, &cur);
        if (d < bestD) {
            out[0] = c;
            bestD = d;
            out[1] = j;
            best.re = cur.re;
            best.im = cur.im;
        }
    }
    pos->re = best.re;
    pos->im = best.im;
}
/* merge_units: end func_00319718 */

/* merge_units: begin func_00319910 */
typedef struct { float re; float im; } Cx319910;

#if 0 /* merge_units */
extern float Dim2VectorLUT(int idx, Cx319910* tab, int n, Cx319910* out);
#endif /* merge_units */
#define Dim2VectorLUT(a0, a1, a2, a3) (Dim2VectorLUT((a0), (Cx319718 *)(a1), (a2), (Cx319718 *)(a3))) /* merge_units */

#if 0 /* merge_units */
extern void DeRotScaleVQ2(Cx319910* a, Cx319910* tab, int idx, Cx319910* out);
#endif /* merge_units */
#define DeRotScaleVQ2(a0, a1, a2, a3) (DeRotScaleVQ2((Cx319718 *)(a0), (Cx319718 *)(a1), (a2), (Cx319718 *)(a3))) /* merge_units */


void RS2StageVQ2Dec(int* in, Cx319910* pos, int nA, Cx319910* tabA, Cx319910* tabB,
                   int nC, Cx319910* ptsA, Cx319910* ptsB, int nList, int* list)
{
    Cx319910 rot;
    Cx319910 diff;
    Cx319910* pts;

    Dim2VectorLUT(in[0], tabA, nA, pos);
    pts = SelectOutCellCB(list, nList, in[0]) == 1 ? ptsB : ptsA;
    Dim2VectorLUT(in[1], pts, nC, &rot);
    DeRotScaleVQ2(&rot, tabB, in[0], &diff);
    pos->re += diff.re;
    pos->im += diff.im;
}
#undef Dim2VectorLUT /* merge_units */
#undef DeRotScaleVQ2 /* merge_units */
/* merge_units: end func_00319910 */
