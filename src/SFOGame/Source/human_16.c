/*
 * SFOGame/Source/human: 2 files, 0019DD80-0019E330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019DD80 */
#pragma push /* merge_units */
#pragma opt_pulloutconstants off
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
extern "C" {
typedef struct { char pad[0xDC]; unsigned char dc; } Ctl;
typedef union { int i[4]; __int128 q; } Q4;
typedef struct { char pad[0x10]; char anim[0x10]; } AnimBlk;
typedef struct {
    char pad0[0x2EC0];
    AnimBlk blk;            /* 0x2EC0 */
    char pad2EE0[0x31E0 - 0x2EE0];
    float rate;             /* 0x31E0 */
    char pad31E4[0x3204 - 0x31E4];
    int f3204;              /* 0x3204 */
    char pad3208[0x3210 - 0x3208];
    int f3210;              /* 0x3210 */
    char pad3214[0x3248 - 0x3214];
    int f3248;              /* 0x3248 */
    char pad324C[0x3310 - 0x324C];
    Ctl* ctl;               /* 0x3310 */
} Actor;
typedef struct {
    char pad0[0x3034];
    int f3034;
    char pad3038[8];
    Q4 v3040;
} ActorB;
extern float D_0049CF50;
extern float D_0049CF58;
extern float D_0049CF68;
extern float D_0049CF80;
extern float D_0049CFA0;
extern float D_0049CFB0;
extern float D_0049CFB8;
extern float D_0049CFC0;
extern float D_0049CFE0;
extern void cSkaParams_SetSliderValue_UsingSplineForInterpolation(void* a, int idx, unsigned int n, float target, float dur, float damping);
extern void cSkaParams_SetSliderValue_int_float_float_bool(void* a, int idx, unsigned int n, float target, float rate);
extern float AnimChannel_GetCurrentValue(void* a, int idx);
extern float cSkaSystem_GetSliderValue(void* a, int idx);
extern void cSkaParams_SetSwitchNextGoalState(void* a, int idx, int n);

}
typedef unsigned char u8;
static inline int HasCtl(Actor* a) { u8 r = 0; if (a->ctl && a->ctl->dc) r = 1; return r; }
static inline u8 Flag0(Actor* a) { return (((ActorB*)a)->f3034 & 1) != 0; }
static inline u8 NFlag0(Actor* a) { return !Flag0(a); }
static inline u8 C1(Actor* a) { u8 r = 0; if (HasCtl(a)) { if (NFlag0(a)) r = 1; } return r; }
static inline u8 Bit4(Actor* a) { return ((a->f3210 >> 4) & 1) != 0; }
static inline u8 Bit5(Actor* a) { return ((a->f3210 >> 5) & 1) != 0; }
static inline u8 Bit10(Actor* a) { return ((a->f3210 >> 10) & 1) != 0; }
static inline u8 Bit11(Actor* a) { return ((a->f3210 >> 11) & 1) != 0; }
static inline u8 Bit15(Actor* a) { return ((a->f3248 >> 15) & 1) != 0; }
static inline u8 C2(Actor* a) { u8 r = 1; if (!C1(a)) { if (!Bit4(a)) r = 0; } return r; }
static inline u8 C3(Actor* a) { u8 r = 1; if (!C2(a)) { if (!Bit5(a)) r = 0; } return r; }
static inline u8 C4(Actor* a) { u8 r = 1; if (!C3(a)) { if (!Bit10(a)) r = 0; } return r; }
static inline u8 C5(Actor* a) { u8 r = 1; if (!C4(a)) { if (!Bit11(a)) r = 0; } return r; }
static inline int C6(Actor* a) { u8 r = 1; if (!C5(a)) { if (!Bit15(a)) r = 0; } return r; }
/* 16-byte lq/sq copy idiom (GCC-style asm keeps retail's unfolded address setup) */
static inline void Q4_Zero(Q4* p) { Q4 z; z.i[0] = 0; z.i[1] = 0; z.i[2] = 0; z.i[3] = 0; __int128 q; __asm__ volatile("lq %0,0(%2); sq %0,0(%1)" : "=&r"(q) : "r"(p), "r"(&z) : "memory"); }

extern "C" void cHuman_ClearMotionSettings(Actor* self, int b, int c, int d, int e)
{
    unsigned char busy = C6(self);
    AnimBlk* blk = &self->blk;
    if (!busy || ((self->f3248 >> 15) & 1)) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 4, 0, 0.0f, D_0049CFB0, 3.0f);
    }
    if ((self->f3204 >> 3) & 1) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 10, 0, 1.0f, D_0049CFA0, 5.5f);
    } else {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 10, 0, 0.0f, D_0049CFA0, 5.5f);
    }
    if ((self->f3204 >> 4) & 1) {
        cSkaParams_SetSliderValue_int_float_float_bool(blk->anim, 11, 0, 1.0f, self->rate);
    } else {
        cSkaParams_SetSliderValue_int_float_float_bool(blk->anim, 11, 0, 0.0f, self->rate);
    }
    if (!busy) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 3, 0, 0.0f, D_0049CF80, 3.0f);
    } else {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 3, 0, AnimChannel_GetCurrentValue(blk, 3), -1.0f, 0.0f);
    }
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 2, 0, 0.0f, D_0049CF50, 3.0f);
    if (!busy) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 5, 0, 0.5f, D_0049CF68, 3.0f);
        if (!e) {
            cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 6, 0, 0.5f, D_0049CF58, 3.0f);
        }
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 7, 0, 0.0f, D_0049CFC0, 3.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 8, 0, 0.0f, D_0049CFC0, 3.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 9, 0, cSkaSystem_GetSliderValue(blk, 6), D_0049CF58, 3.0f);
    } else {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 5, 0, AnimChannel_GetCurrentValue(blk, 5), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 6, 0, AnimChannel_GetCurrentValue(blk, 6), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 7, 0, AnimChannel_GetCurrentValue(blk, 7), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 8, 0, AnimChannel_GetCurrentValue(blk, 8), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 9, 0, AnimChannel_GetCurrentValue(blk, 9), -1.0f, 0.0f);
    }
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 0, 0, 0.5f, D_0049CFE0, 3.0f);
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 1, 0, 0.5f, D_0049CFE0, 3.0f);
    if (!b) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 14, 0, 0.5f, D_0049CFB8, 6.5f);
    }
    if (!d) {
        cSkaParams_SetSliderValue_int_float_float_bool(blk->anim, 17, 0, 0.5f, self->rate);
    }
    {
        Q4_Zero(&((ActorB*)self)->v3040);
    }
    if (!c) {
        cSkaParams_SetSwitchNextGoalState(blk->anim, 3, 0);
    }
}
static inline void merge_flush_func_0019DD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019DD80 */

/* merge_units: begin func_0019E330 */
#pragma push /* merge_units */
/* cHuman_PreventRemotePlayerFromFallingThroughDeactivatedTerrain: in multiplayer, for a networked actor that is not
 * held/attached, if its root sits more than a margin below the ground plane
 * stored at +0x3570, snap it down onto the plane (offset by a slope-dependent
 * height) and push the plane normal to the attached body. */
#pragma cplusplus on
#pragma inline_depth(8)
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
#define VD(n) virtual void n();
#define VD10(p) VD(p##0) VD(p##1) VD(p##2) VD(p##3) VD(p##4) VD(p##5) VD(p##6) VD(p##7) VD(p##8) VD(p##9)
class Link {
public:
    VD10(a) VD(b0) VD(b1) VD(b2) VD(b3) VD(b4) VD(b5) VD(b6) VD(b7) VD(b8)
    virtual int Active();
};
struct Body { char pad[0x20]; int x20; char pad24[0x1E0 - 0x24]; V n; };
class Actor_0019E330 {
public:
    VD10(a) VD10(b) VD10(c) VD10(d) VD10(e) VD10(f)
    virtual int Probe(V* out);
    char pad4[0x14 - 4]; unsigned char held; char pad15[0x58 - 0x15]; Link* link;
    char pad5C[0x3210 - 0x5C]; int flags; char pad3214[0x3290 - 0x3214]; void* root;
    char pad3294[0x3310 - 0x3294]; Body* body; char pad3314[0x3570 - 0x3314]; V plane;
};
extern "C" {
extern unsigned char g_IsMultiplayer;
extern float D_0049CFF8;
extern float D_0049D000;
extern float D_0049D008;
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
V* cQuatVec_Rotation(void* p);
V* cQuatVec_Translation(void* p);
void cQuaternion_opAssign(V* d, V* s);
void cVector_opAssign(V* d, V* s);
V* cVector_ctor_cVectorR(V* d, const V* s);
V* cVector_SetW(V* v, float w);
void NpcAi_GroundActor(Actor_0019E330* a, int b, int c, float z);
void cHuman_PreventRemotePlayerFromFallingThroughDeactivatedTerrain(Actor_0019E330* self);
}
static inline float Dot(const V& a_, const V& b_) {
    const V* a = &a_; const V* b = &b_;
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline bool Bit(int f, int n) { return (bool)((f >> n) & 1); }
static inline bool Bit2(int f, int n) { bool r = (f >> n) & 1; return r; }
static inline bool Free(Body* b) { return !b || b->x20 == 0; }
static inline bool IsNull(void* p) { return !p; }
static inline bool IsZero(int x) { return x == 0; }
static inline bool FreeA(Body* b) { bool r = true; if (b && b->x20) r = false; return r; }
static inline bool FreeB(Body* b) { if (!b || b->x20 == 0) return true; return false; }
static inline bool NotBit(int f, int n) { return !Bit(f, n); }
static inline bool IsNZ(int x) { return x != 0; }
static inline bool Eq(int x, int y) { return x == y; }
static inline bool Free2(Actor_0019E330* s) { return !s->body || IsZero(s->body->x20); }
static inline bool Z(float v) { return v == 0.0f; }
/* horizontal part of the plane normal, written through an out pointer (keeps retail's copy register order) */
static inline void Horiz(V* out, const V& v) { V n = v; V* p = &n; p->w = 0.0f; { V* pt = out; *pt = *p; } }
static inline float GroundZ(const V& n, float x, float y) { float h = 0.0f; if (n.z != 0.0f) { V p(x, y, 0.0f, 1.0f); float z = n.z; return -Dot(n, p) / z; } return h; }
static inline void SetN(Body* b, const V& v) { b->n = v; }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Clamp(float v, float lo, float hi) { float r = 0.0f; asm { max.s r, v, lo; min.s r, r, hi } return r; }
static inline V AsDir(const V& v) { V t; V* r = cVector_SetW(cVector_ctor_cVectorR(&t, &v), 0.0f); return *r; }

void cHuman_PreventRemotePlayerFromFallingThroughDeactivatedTerrain(Actor_0019E330* self)
{
    if (g_IsMultiplayer) {
        bool linked = false;
        if (self->link && self->link->Active())
            linked = true;
        if (linked && !self->held) {
            bool b = false;
            bool a = false;
            if (Free2(self) && NotBit(self->flags, 4))
                a = true;
            if (a && NotBit(self->flags, 5))
                b = true;
            if (b) {
                void* root = self->root;
                V q;
                V pos;
                V tmp;
                cQuaternion_opAssign(&q, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root)));
                cVector_opAssign(&pos, cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(root)));
                if (Z(self->plane.x) && Z(self->plane.y) && Z(self->plane.z) && Z(self->plane.w))
                    return;
                {
                    float h = GroundZ(self->plane, pos.x, pos.y);
                    if (pos.z < h - D_0049CFF8) {
                        V m; Horiz(&m, self->plane);
                        const V* pm = &m; const float* pz = &pm->z; float s = 1.0f - Abs(*pz); float k = Clamp(s, 0.0f, 1.0f);
                        { float off = D_0049D000 + k * D_0049D008; pos.z = (h - D_0049CFF8) - off; }
                        if (!self->Probe(&tmp)) {
                            NpcAi_GroundActor(self, 1, 0, pos.z);
                            if (self->body)
                                SetN(self->body, AsDir(self->plane));
                        }
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_0019E330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019E330 */
