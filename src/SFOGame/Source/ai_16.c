/*
 * SFOGame/Source/ai: 5 files, 0016C260-0016C590
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016C260 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cAITarget::TestPointInViewCone: whether a point lies inside the owner's view cone - within
   the (darkness-scaled) view radius of the eye position and inside the half angle around the
   facing direction (eye bone or the virtual eye transform). */
/* lq/sq quadword copies: 128-bit moves have no C equivalent */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    /* VU0 macro-mode vector ops (COP2), not expressible in C */
    cVector& operator-=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& Normalize(float* len) {
        __int128 t = 0; int r; float* p;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%2); qmfc2.ni %0, $vf4" : "=r"(r), "=r"(p) : "r"(this), "0"(t), "1"(len) : "memory");
        *(int*)p = r;
        return *this;
    }
} __attribute__((aligned(16)));
static inline float Dot(const cVector& a, const cVector& b) {
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2 %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&a), "r"(&b) : "memory");
    return r;
}
struct cMatrix { cVector r[4]; cMatrix() {} const cVector& GetTranslation() const { return r[3]; } const cVector& GetForward() const { return r[1]; } };
struct cSkeleton;
struct cHuman {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual cVector GetTargetPosition(int sub) const;
    VPAD8(e) VPAD1(f) virtual cMatrix GetEyeTransform() const;
    char pad4[0x28];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x33A8 - 0x2F];
    float x33A8;
};
struct cAI { char pad[0x30]; cHuman* human; };
struct cAITarget { cVector targetPositionLastSeen; float viewConeRadius; float viewConeHalfAngle; char pad18[0x3C - 0x18]; cAI* ai;
    cHuman* GetHuman() const { return ai->human; } };
extern "C" {
extern signed char g_HeadNodeCode;
cSkeleton* cSKM_GOBJ_GetSkeleton_void(cHuman* h);
cMatrix cSkeleton_GetBoneToWorldMatrix(cSkeleton* s, int node);
float Libc_Cosf(float a);
bool cAITarget_TestPointInViewCone(const cAITarget* self, const cVector& testPoint, bool useAimDirection, int darkness);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(cHuman* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }

bool cAITarget_TestPointInViewCone(const cAITarget* self, const cVector& testPoint, bool useAimDirection, int darkness)
{
    bool res;
    cVector pos;
    float viewConeRadius = self->viewConeRadius;
    cHuman& human = *self->GetHuman();
    float distanceToTarget;
    res = false;
    if (human.x33A8 <= 0.0f) {
        if (!useAimDirection || !Ready(self->GetHuman()))
            pos = self->GetHuman()->GetTargetPosition(-1);
        else
            pos = cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(&human), g_HeadNodeCode).GetTranslation();
        {
            cVector deltaToTarget = testPoint;
            (deltaToTarget -= pos).Normalize(&distanceToTarget);
            if (darkness > 0)
                viewConeRadius *= (100.0f - darkness) / 100.0f;
            if (distanceToTarget < viewConeRadius && distanceToTarget != 0.0f) {
                if (distanceToTarget > 1.0f) {
                    cVector direction;
                    float cosAngle;
                    if (!useAimDirection || !Ready(self->GetHuman()))
                        direction = self->GetHuman()->GetEyeTransform().GetForward();
                    else
                        direction = cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(&human), g_HeadNodeCode).GetForward();
                    cosAngle = Dot(direction, deltaToTarget);
                    if (cosAngle + (1.0f - Libc_Cosf(self->viewConeHalfAngle)) > 1.0f)
                        res = true;
                } else {
                    res = true;
                }
            }
        }
    }
    return res;
}
static inline void merge_flush_func_0016C260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016C260 */

/* merge_units: begin func_0016C590 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; } Tgt_C590;
typedef struct { Tgt_C590* target; int serial; char pad8[0x34]; unsigned char seen; } Rec_C590;
typedef struct Node_C590 { int pad0; struct Node_C590* next; Rec_C590* val; } Node_C590;
typedef struct { Node_C590* n; } It_C590;
typedef struct { int a; } E_C590;
typedef struct { char pad[0x30]; char map[4]; } Own_C590;
extern void std_list_cTargetAwarenessPtr_end_void(E_C590* out, void* map);
extern void std_list_cTargetAwarenessPtr_begin(E_C590* out, void* map);
extern void cLListIterator_cTargetAwarenessPtr_ctor(It_C590* out, E_C590* in);
/* Clears the "seen" flag of every record (or only of the records targeting who). */
void cAITarget_ResendNewAwarenessMessage(Own_C590* self, Tgt_C590* who)
{
    It_C590 it;
    It_C590 b;
    It_C590 end;
    E_C590 t1;
    E_C590 t2;
    std_list_cTargetAwarenessPtr_begin(&t1, self->map);
    cLListIterator_cTargetAwarenessPtr_ctor(&b, &t1);
    it = b;
    while (std_list_cTargetAwarenessPtr_end_void(&t2, self->map), cLListIterator_cTargetAwarenessPtr_ctor(&end, &t2), it.n != end.n) {
        if (who) {
            unsigned char ok;
            int isNull;
            Tgt_C590* c;
            Rec_C590* h;
            h = it.n->val;
            c = h->target;
            isNull = !c;
            ok = 1;
            if (!isNull)
                if (c->serial != h->serial)
                    ok = 0;
            if ((ok ? c : 0) != who)
                goto next;
        }
        it.n->val->seen = 0;
    next:
        it.n = it.n->next;
    }
}
static inline void merge_flush_func_0016C590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016C590 */

/* merge_units: begin func_0016C6A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; float f24; } B7_6A0Val;
typedef struct { char pad[8]; B7_6A0Val* val; } B7_6A0Node;
typedef struct { char pad[0x30]; char map[1]; } B7_6A0Owner;
extern void cAITarget_cAwareList_Find(B7_6A0Node** out, void* map, int key);
#if 0 /* merge_units */
extern void std_list_cTargetAwarenessPtr_end_void(B7_6A0Node** out, void* map);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_end_void(a0, a1) (std_list_cTargetAwarenessPtr_end_void((E_C590 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void cLListIterator_cTargetAwarenessPtr_ctor(B7_6A0Node** out, B7_6A0Node** in);
#endif /* merge_units */
#define cLListIterator_cTargetAwarenessPtr_ctor(a0, a1) (cLListIterator_cTargetAwarenessPtr_ctor((It_C590 *)(a0), (E_C590 *)(a1))) /* merge_units */


B7_6A0Val* cAITarget_GetAwareness(B7_6A0Owner* p, int key)
{
    B7_6A0Val* r = 0;
    B7_6A0Node* it;
    B7_6A0Node* end;
    B7_6A0Node* tmp;
    B7_6A0Node* n;
    cAITarget_cAwareList_Find(&it, p->map, key);
    n = it;
    std_list_cTargetAwarenessPtr_end_void(&tmp, p->map);
    cLListIterator_cTargetAwarenessPtr_ctor(&end, &tmp);
    if (n != end) {
        B7_6A0Val* v = n->val;
        if (!(v->f24 < 0.0f)) {
            r = v;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C6A0(void) {}
#undef std_list_cTargetAwarenessPtr_end_void /* merge_units */
#undef cLListIterator_cTargetAwarenessPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016C6A0 */

/* merge_units: begin func_0016C730 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int cAITarget_GetAwareness(int, int);
#endif /* merge_units */
#define cAITarget_GetAwareness(a0, a1) ((int)cAITarget_GetAwareness((B7_6A0Owner *)(a0), (a1))) /* merge_units */




float cAITarget_GetAwarenessThreat(void) {
    int a0, a1, v0;
    float f0, f20;
    int cond;

    f20 = 0.0f;
    v0 = cAITarget_GetAwareness(a0, a1);
    cond = v0 == 0;
    if (cond) goto L0016C758;
    f20 = *(float*)((char*)v0 + 48);
L0016C758:;
    f0 = f20;
    goto ret;
ret:
    return f0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C730(void) {}
#undef cAITarget_GetAwareness /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016C730 */

/* merge_units: begin func_0016C770 */
#pragma push /* merge_units */
typedef struct { char pad[0x20]; unsigned char f20; char p21[3]; float f24; char p28[0x10]; unsigned char f38; unsigned char f39; unsigned char f3A; char p3B; unsigned char f3C; } Rec_770;
typedef struct { char pad[8]; Rec_770* val; } Node_770;
typedef struct { char pad[0x30]; char map[1]; } Owner_770;
#if 0 /* merge_units */
extern void cAITarget_cAwareList_Find(Node_770** out, void* map, int key);
#endif /* merge_units */
#define cAITarget_cAwareList_Find(a0, a1, a2) (cAITarget_cAwareList_Find((B7_6A0Node * *)(a0), (a1), (a2))) /* merge_units */



#if 0 /* merge_units */
extern void std_list_cTargetAwarenessPtr_end_void(Node_770** out, void* map);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_end_void(a0, a1) (std_list_cTargetAwarenessPtr_end_void((E_C590 *)(a0), (a1))) /* merge_units */



#if 0 /* merge_units */
extern void cLListIterator_cTargetAwarenessPtr_ctor(Node_770** out, Node_770** in);
#endif /* merge_units */
#define cLListIterator_cTargetAwarenessPtr_ctor(a0, a1) (cLListIterator_cTargetAwarenessPtr_ctor((It_C590 *)(a0), (E_C590 *)(a1))) /* merge_units */



extern void cAITarget_AddAwareness(Owner_770* p, int key, int kind, float amt);
void cAITarget_SetAwarenessVisible(Owner_770* p, int key, unsigned char a, unsigned char b)
{
    int both = (a & b) != 0;
    Node_770* it;
    Node_770* end;
    Node_770* tmp;
    cAITarget_cAwareList_Find(&it, p->map, key);
    std_list_cTargetAwarenessPtr_end_void(&tmp, p->map);
    cLListIterator_cTargetAwarenessPtr_ctor(&end, &tmp);
    if (it != end) {
        if (both && !it->val->f3C) {
            cAITarget_AddAwareness(p, key, 6, 0.0f);
        } else {
            it->val->f38 = b;
            it->val->f39 = a;
            if (a) {
                if (b) {
                    it->val->f24 = 0.0f;
                    it->val->f3A = 1;
                    it->val->f20 = 6;
                } else if (it->val->f24 < 10.0f) {
                    it->val->f24 = 0.0f;
                }
            }
        }
    } else if (both) {
        cAITarget_AddAwareness(p, key, 6, 0.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C770(void) {}
#undef cAITarget_cAwareList_Find /* merge_units */
#undef std_list_cTargetAwarenessPtr_end_void /* merge_units */
#undef cLListIterator_cTargetAwarenessPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016C770 */
