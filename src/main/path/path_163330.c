/*
 * main/path: range (4 files, 00163330-00163580)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "word_fill_range.h"

/* merge_units: begin func_00163330 */
#pragma push /* merge_units */
typedef struct { int n; int a[64]; } FA_00163330;
static const unsigned int dat_0048A000[2] = { 0x0, 0x0 };
static inline void fill_00163330(FA_00163330 *s, int n, int *v) {
    int i;
    for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
    s->n = n;
}
void NpcRoute_ClearRegionCandidates(FA_00163330 *s, unsigned int n, int *v) {
    if (n < 65U) {
        fill_00163330(s, n, v);
        return;
    }
    fill_00163330(s, 64, &(*(int*)dat_0048A000));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163330 */

/* merge_units: begin func_001633D0 */
#pragma push /* merge_units */
/* Fill an inclusive index range with a value. */
DEFINE_WORD_FILL_RANGE(nArray_InitSlots_intP_int_int_intR)
#pragma pop /* merge_units */
/* merge_units: end func_001633D0 */

/* merge_units: begin func_00163410 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { QC(this, &o); }
} __attribute__((aligned(16)));
static inline V operator-(const V& a, const V& b)
{
    V r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline float Dist(const V* a, const V* b)
{
    V r;
    V d;
    float ret;
    {
        V* pr = &r; const V* pa = a; const V* pb = b;
        asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    }
    {
    V* dd; const V* ss; int t; __int128 x; V* pv;
    ss = &r; pv = &d; asm { mtc1 $zero, ret } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
    asm {
        lqc2 vf1, 0(pv)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, ret
    }
    }
    return ret;
}
struct ROpen { char pad[0xC]; float f; int parent; int node; float g; unsigned char open; char pad1D[3]; };
struct Search { char pad[0x20]; V goal; V start; char pad40[0x18]; char openList[4]; };
struct PNode;
extern "C" {
extern int D_004EA798;
extern ROpen D_004EA7B0[];
PNode* NpcPath_GetNode(int);
void Node_GetTranslation(V* out, PNode* n);
void NpcRoute_InsertSorted(void* list, ROpen* n);
}
static inline ROpen* AllocOpen()
{
    ROpen* n;
    int c;
    n = 0;
    c = D_004EA798;
    if (c < 400) { n = &D_004EA7B0[c]; D_004EA798 = c + 1; }
    return n;
}
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" bool NpcRoute_OpenNode(Search* self, int node)
{
    bool r = false;
    V t; V d1; V d2; V r1; V r2;
    ROpen* n = AllocOpen();
    if (n) {
        float g; float h;
        Node_GetTranslation(&t, NpcPath_GetNode(node));
        {
            V* pr = &r1; const V* pa = &self->start; const V* pb = &t;
            __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
        }
        {
        V* dd; const V* ss; int tt; __int128 x; V* pv;
        ss = &r1; pv = &d1; asm { mtc1 $zero, g } dd = &d1; x = *(__int128*)ss; *(__int128*)dd = x;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(g), "=&r"(tt) : "r"(pv) : "memory");
        }
        n->node = node;
        n->g = g;
        {
            V* pr = &r2; const V* pa = &self->goal; const V* pb = &t;
            __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
        }
        {
        V* dd; const V* ss; int tt; __int128 x; V* pv;
        ss = &r2; pv = &d2; asm { mtc1 $zero, h } dd = &d2; x = *(__int128*)ss; *(__int128*)dd = x;
        asm {
            lqc2 vf1, 0(pv)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            qmfc2.ni tt, vf4
            mtc1 tt, h
        }
        }
        n->f = g + h;
        n->parent = 0;
        n->open = 1;
        NpcRoute_InsertSorted(self->openList, n);
        r = true;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163410 */

/* merge_units: begin func_00163580 */
#pragma push /* merge_units */
typedef struct CxRouteSearch { char pad[0x10]; unsigned char state; } CxRouteSearch;
extern char D_004ED9F0[];
extern unsigned char D_004ED9FD;
extern int D_004EDE68;
extern unsigned int D_004EE010;
extern int D_004EE014[];
extern void NpcRoute_HandleLosResult(void*, unsigned char*);
#if 0 /* merge_units */
extern void NpcRoute_OpenNode(CxRouteSearch*, int);
#endif /* merge_units */
#define NpcRoute_OpenNode(a0, a1) ((void)NpcRoute_OpenNode((void *)(a0), (a1))) /* merge_units */


void NpcRoute_HandleRouteLosResult(CxRouteSearch* self, unsigned char* blocked) {
    unsigned char state = self->state;
    if (state == 2) {
        D_004ED9FD = 0;
        D_004EDE68 = (unsigned char)!*blocked;
    } else if (state == 0) {
        NpcRoute_HandleLosResult(D_004ED9F0, blocked);
        if (D_004EDE68 >= 0) {
            NpcRoute_OpenNode(self, D_004EDE68);
            D_004EDE68 = -1;
        }
    } else if (state == 1) {
        NpcRoute_HandleLosResult(D_004ED9F0, blocked);
        if (D_004EDE68 >= 0) {
            if (D_004EE010 < 64) {
                D_004EE014[D_004EE010] = D_004EDE68;
                D_004EE010++;
            }
            D_004EDE68 = -1;
        }
    }
}
#undef NpcRoute_OpenNode /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163580 */
