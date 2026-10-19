/*
 * main/ska: range (2 files, 003AFCB0-003AFF10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AFCB0 */
#pragma push /* merge_units */
typedef struct {
    int target; int f4; unsigned char b8; unsigned char b9; char padA[2];
    int fC; int f10; int f14; unsigned char b18; char pad19[3];
    int f1C; int f20; int f24;
} AnimTrans_f3;
typedef struct { char pad[0x6C]; int list; } AnimSel_f3;
AnimTrans_f3* AnimSelector_BeginTransition(AnimSel_f3* sel, int a, int b, int target); /* gsynth: defined below */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies and VU0 ops as GCC-style volatile asm; unused xx locals reproduce retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    bool NotIdent() const { bool b = !IsIdent(); return b; }
    V operator*(const V& b) const {
        V c; const V* r = &b; const V* l = this; V* d = &c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

struct Ctx;
struct EvNode {
    virtual void v0();
    virtual void Eval(float t, const V* q, Ctx* c);
};
struct Child { char pad0[0x1C]; float k; EvNode* a; EvNode* b; };
struct Sel { char pad0[0x10]; V rot; int idx; char vec[4]; };

static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

/* Combined rotation (q * self->rot); retail keeps the product in the caller's frame after the inline returns. */
static inline const V* Pick(Sel* self, const V* q) {
    const V* r;
    if (self->rot.NotIdent()) {
        if (q->NotIdentR()) {
            V a = *q * self->rot;
            V b = a;
            r = &b;
        } else {
            r = &self->rot;
        }
        return r;
    }
    return q;
}
extern "C" {
extern float D_004BCD68;
Child* func_003B01C0(Ctx* c, Sel* s);
int func_003B01A0(Ctx* c, int i);
void* func_003B0180(void* v, int i);
EvNode* func_003B0170(void* e);
void* func_003B0150(Sel* s, Ctx* c);
int func_003B0140(void* p);
int func_003B0130(void* p);
int func_003B0050(Sel* s, Ctx* c);
#if 0 /* merge_units */
void* AnimSelector_BeginTransition(Ctx* c, int a, int b, Sel* s);
#endif /* merge_units */
#define AnimSelector_BeginTransition(a0, a1, a2, a3) ((void *)AnimSelector_BeginTransition((AnimSel_f3 *)(a0), (a1), (a2), (int)(a3))) /* merge_units */

void AnimSelector_Evaluate(Sel* self, float t, const V* q, Ctx* ctx);
}

void AnimSelector_Evaluate(Sel* self, float t, const V* q, Ctx* ctx)
{
    if (t < D_004BCD68) return;
    const V* r = Pick(self, q);
    Child* ch = func_003B01C0(ctx, self);
    if (ch) {
        float u = t * ch->k;
        ch->a->Eval(MaxF(0.0f, t - u), r, ctx);
        ch->b->Eval(u, r, ctx);
    } else {
        func_003B0170(func_003B0180(&self->vec, func_003B01A0(ctx, self->idx)))->Eval(t, r, ctx);
    }
    void* p = func_003B0150(self, ctx);
    int from = func_003B0140(p);
    int to = func_003B0130(p);
    if (from != to && !func_003B0050(self, ctx))
        AnimSelector_BeginTransition(ctx, from, to, self);
}
#undef AnimSelector_BeginTransition /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AFCB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AFCB0 */

/* merge_units: begin func_003AFF10 */
#pragma push /* merge_units */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern void Alloc_Lock(int);
extern void Alloc_Unlock(int);
extern void* Mem_Alloc(int, int, char*, int);
extern void func_003B0020(int* list, AnimTrans_f3** item);
static inline void* AllocL_f3(int size, char* file, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = Mem_Alloc(0, size, file, line);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    return p;
}
AnimTrans_f3* AnimSelector_BeginTransition(AnimSel_f3* sel, int a, int b, int target)
{
    AnimTrans_f3* t[1];
    AnimTrans_f3* p;
    p = AllocL_f3(0x28, "ska.icc", 0x47F);
    if (p) {
        p->target = target;
        p->f4 = 0;
        p->b8 = 0;
        p->b9 = 0;
        p->fC = b;
        p->f10 = a;
        p->f14 = 0;
        p->b18 = 0;
        p->f1C = 0;
        p->f20 = 0;
        p->f24 = 0;
    }
    t[0] = p;
    func_003B0020(&sel->list, t);
    return t[0];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AFF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AFF10 */
