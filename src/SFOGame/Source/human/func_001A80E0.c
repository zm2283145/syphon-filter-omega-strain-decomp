#pragma opt_pulloutconstants off
#pragma cplusplus on
#include "types.h"
typedef unsigned char u8;
struct V { float x, y, z, w; V() {} V(const V& o) { *(__int128*)this = *(const __int128*)&o; } } __attribute__((aligned(16)));
static inline void Q1D_L(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
#define CP(d, s) Q1D_L(&(d), &(s))
#define CPN(d, s) (*(__int128*)&(d) = *(const __int128*)&(s))
class Obj58 { public: virtual void F0(); virtual void F1(); virtual void F2(); virtual void F3(); virtual void F4(); virtual void F5(); virtual void F6(); virtual void F7(); virtual void F8(); virtual void F9(); virtual void F10(); virtual void F11(); virtual void F12(); virtual void F13(); virtual void F14(); virtual void F15(); virtual void F16(); virtual void F17(); virtual void F18(); virtual int IsPlayer(); };
struct Phys { char pad0[0xC]; void* f0C; };
struct Tgt { char pad0[0x140]; V quat; char pad150[0x310 - 0x150]; u8 b310; u8 b311; u8 b312; };
struct Inv { char pad0[0x84]; u8 b84; char pad85[0xA0 - 0x85]; u8 bA0; };
struct AnimBlk { char pad0[0x10]; char anim[0x1C]; float f2C; };
struct TblE { char pad0[0x4C]; u8 b4C; char pad4D[3]; };
struct Actor {
    char pad0[0x14];
    u8 b14;                 /* 0x14 */
    char pad15[0x58 - 0x15];
    Obj58* p58;             /* 0x58 */
    char pad5C[0x2EC0 - 0x5C];
    AnimBlk blk;            /* 0x2EC0 */
    char pad2EF0[0x303C - 0x2EF0];
    u8 b303C;               /* 0x303C */
    char pad303D[0x30AC - 0x303D];
    u8 b30AC;               /* 0x30AC */
    u8 b30AD;               /* 0x30AD */
    char pad30AE[2];
    V target;               /* 0x30B0 */
    float yaw;              /* 0x30C0 */
    char pad30C4[0x30E0 - 0x30C4];
    float spd;              /* 0x30E0 */
    char pad30E4[0x30F0 - 0x30E4];
    char curve[0x31B0 - 0x30F0]; /* 0x30F0 */
    u8 b31B0;               /* 0x31B0 */
    char pad31B1[0x31B7 - 0x31B1];
    u8 b31B7;               /* 0x31B7 */
    char pad31B8[8];
    V navDir;               /* 0x31C0 */
    float speed;            /* 0x31D0 */
    float turn;             /* 0x31D4 */
    char pad31D8[0x3204 - 0x31D8];
    int flags2;             /* 0x3204 */
    char pad3208[4];
    int state;              /* 0x320C */
    int flags;              /* 0x3210 */
    char pad3214[0x3290 - 0x3214];
    void* flor;             /* 0x3290 */
    char pad3294[0x3310 - 0x3294];
    Phys* phys;             /* 0x3310 */
    Tgt* p3314;             /* 0x3314 */
    char pad3318[0x3524 - 0x3318];
    Inv* inv;               /* 0x3524 */
};
extern "C" {
extern signed char D_004E1D88;
extern int D_004E1D90, D_004E1D94, D_004E1D98, D_004E1D9C;
extern TblE SecondaryStateTable[];
extern char D_004A03C8[], D_004A03D0[], D_004A03D8[];
extern float D_004A0410, D_004A0420, D_0049CFF0;
void* cSkaSystem_GetAnchor(void* p, void* key);
float cSkaAnimAnchor_GetWeight(void* r);
V* cSkaAnimAnchor_GetPosition(void* r);
V Vec4_Lerp(V* a, V* b, float t);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
V* cVector_opAdd(V* d, V* a, V* b);
V* cVector_ctor_cVectorR(V* d, const V* s);
int cHuman_TriggerGetOffLadderRequest(Actor* a, V* d);
V* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
V* cVector_InverseRotate_cQuaternionR(V* v, V* q);
void cQuaternion_opAssign(V* q, V* src);
V* cQuatVec_Rotation(V* p);
V* cQuatVec_Translation(V* p);
void cVector_opAssign(V* d, V* s);
float Libc_Cosf(float);
float Libc_Sinf(float);
float Libc_Atan2f(float, float);
float nGameUnits_Sec(float);
void cSplinedMotion_cVector_RestartTransition(void* c, float d);
void cSplinedMotion_cVector_SetTargetVal(void* c, V* t);
float MotionCtrl_GetSelectorMetric(void* anim, int* sel);
float cSkaParams_GetSliderValue(void* anim, int idx);
void cHuman_DeriveMotionParamsFromDestinationParams(Actor* a);
}
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float AbsA(float x) { float r = 0.0f; r = x; asm { abs.s r, r } return r; }
static inline float MinZ(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float MinA(float a, float b) { float r = 0.0f; r = a; asm { min.s r, r, b } return r; }
static inline float Clamp(float x, float hi, float lo) { float r = 0.0f; float l = lo, h = hi; asm { max.s r, x, l; min.s r, r, h } return r; }
static inline bool Vt54(Actor* a) { bool r = false; if (a->p58 && a->p58->IsPlayer()) r = 1; return r; }
static inline V* Zero(void) {
    if (!D_004E1D88) { D_004E1D90 = 0; D_004E1D88 = 1; D_004E1D94 = 0; D_004E1D98 = 0; D_004E1D9C = 0; }
    return (V*)&D_004E1D90;
}
static inline void SetNav2(Actor* a, const V* dir, float s, float t) {
    u8 r, o;
    { V* nd = &a->navDir; CP(*nd, *dir); }
    a->speed = s;
    a->turn = t;
    if ((r = a->b303C)) r = s == 0.0f;
    o = r;
    if (r) o = AbsZ(t) > 0.0001f;
    a->b31B7 = o;
}
static inline void SetNav(Actor* a, const V* dir, float s, float t) {
    u8 r, o;
    { V* nd = &a->navDir; CP(*nd, *dir); }
    a->speed = s;
    a->turn = t;
    if ((r = a->b303C)) r = s == 0.0f;
    o = r;
    if (r) o = AbsA(t) > 0.0001f;
    a->b31B7 = o;
}
static inline void SetNavR(Actor* a, const V* dir, float s, float t) {
    u8 r, o;
    { const V* ps = dir; V* nd = &a->navDir; const V* pt = dir; CP(*nd, *pt); }
    a->speed = s;
    a->turn = t;
    if ((r = a->b303C)) r = s == 0.0f;
    o = r;
    if (r) o = AbsA(t) > 0.0001f;
    a->b31B7 = o;
}
static inline void SetNav0(Actor* a, const V* dir, float s, float t) {
    u8 r, o;
    { V* nd = &a->navDir; CP(*nd, *dir); }
    a->speed = s;
    a->turn = t;
    if ((r = a->b303C)) r = AbsA(t) > 0.0001f;
    a->b31B7 = r;
}
static inline u8 IsZero4(V* v) {
    int k, fl; int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline u8 IsZero3(V* v) {
    int k, fl; int r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline V* Normalize(V* v) { asm { lqc2 vf1, 0x0(v); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(v) } return v; }
static inline void NormLen(V* v, float* len) { int t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%1); qmfc2.ni %0, $vf4; sw %0, 0x0(%2)" : "=&r"(t) : "r"(v), "r"(len) : "memory"); }
static inline void NormLenX(V* v, float* len) { int t; asm { lqc2 vf1, 0x0(v); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; vdiv Q, vf0w, vf4x; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(v); qmfc2.ni t, vf4; sw t, 0x0(len) } }
static inline void SubB(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(b), "r"(d), "r"(a) : "memory"); }
static inline void Sub(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void CPB(V* d, const V* s) { V* dd = d; Q1D_L(dd, s); }
static inline float LenSq(V* v) { float r = 0.0f; int t; asm { lqc2 vf1, 0x0(v); vaddw.x vf3, vf0, vf0w; vmul.xyz vf2, vf1, vf1; vmulax.x ACC, vf3, vf2x; vmadday.x ACC, vf3, vf2y; vmaddz.x vf4, vf3, vf2z; qmfc2.ni t, vf4; mtc1 t, r } return r; }
static inline float Dot3(const V* a, const V* b) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $zero, 0x6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory"); return r; }
static inline void Neg(V* v) { V* d = v; V* s = v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(s), "r"(d) : "memory"); }
static inline void Scale(V* d, const V* s, float k) { __int128 tt; asm { paddub tt, zero, zero } asm { .set noreorder; lqc2 vf1, 0x0(s); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(d); .set reorder } }
static inline void QRot(V* v, V* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void InvRot(V* out, const V* v, V* q) { V t; cVector_ctor_cVectorR(out, cVector_InverseRotate_cQuaternionR(cVector_ctor_cVectorR(&t, v), q)); }
static inline u8 Within(V* v, float r) { float r2 = r * r; u8 b = LenSq(v) < r2; return b; }
static inline float GetZ(const V* v) { return v->z; }
static inline void ZOnly(V* d, float z) { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(d) : "memory"); d->z = z; }
static inline u8 TblOk(Tgt* t) { bool r = false; if (((u8*)&SecondaryStateTable[t->b310])[0x4C] && ((u8*)&SecondaryStateTable[t->b311])[0x4C]) r = true; return (int)r; }

void cHuman_DeriveMotionParamsFromDestinationParams(Actor* a)
{
    float yaw, cy;
    float one = 1.0f;
    float three = 3.0f;
    float len;
    int sel[2];
    V d16;
    V d78;
    V r78;
    V q;
    V pos;
    V tgt;
    V fwd;
    V cp;
    V delta;
    V flat;
    V want;
    V res;
    V cvec;
    V c;
    V dir16;
    V ldir;
    V wflat;
    V wfwd;
    V rr;
    V tY;
    V s2;
    V rc;
    V n16b;
    V sub78;
    V diff;
    V n16;
    V tq;
    V scaled;
    if (a->phys && a->b30AC) {
        if (a->state == 16) {
            V* pc;
            float* tz;
            Phys* p;
            void* r1;
            void* r2;
            float w1, w2, sum, e;
            a->b30AD = 0;
            p = a->phys;
            tz = &a->target.z;
            r1 = cSkaSystem_GetAnchor(p->f0C, D_004A03D0);
            r2 = cSkaSystem_GetAnchor(p->f0C, D_004A03D8);
            w1 = cSkaAnimAnchor_GetWeight(r1);
            w2 = cSkaAnimAnchor_GetWeight(r2);
            sum = w1 + w2;
            if (!(sum <= 0.0f)) {
                float t = w2 / sum;
                V e = Vec4_Lerp(cSkaAnimAnchor_GetPosition(r1), cSkaAnimAnchor_GetPosition(r2), t);
                V off;
                cVector_ctor_float_float_float_float(&off, 0.0f, 0.0f, -D_004A0410, 0.0f);
                cVector_opAdd(&c, &e, &off);
                pc = &c;
            } else {
                cVector_ctor_cVectorR(&c, cSkaAnimAnchor_GetPosition(cSkaSystem_GetAnchor(p->f0C, D_004A03C8)));
                pc = &c;
            }
            { float zz = *tz - pc->z; V* pd = &d16; __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(pd) : "memory"); { V* pz = &d16; pz->z = zz; } }
            e = D_004A0420;
            if (!(AbsZ(d16.z) <= e)) {
                CP(n16, d16);
                CP(dir16, *Normalize(&n16));
                SetNav(a, &dir16, 1.0f, 0.0f);
            } else {
                SetNav0(a, Zero(), 0.0f, 0.0f);
                if ((a->flags >> 13) & 1) a->b30AD = 1;
            }
            if (!IsZero4(&d16) && !Vt54(a)) {
                u8 ok;
                CP(n16b, d16);
                { V* pn = &n16b; Normalize(pn); { V* pd_ = &ldir; V* pe_ = &ldir; CP(*pd_, *pn); } }
                ok = cHuman_TriggerGetOffLadderRequest(a, &ldir);
                if (!((a->flags >> 14) & 1) && ok) a->b30AD = 1;
            }
        } else if (a->state == 8 || a->state == 7) {
            V* pl; V* pv;
            a->b30AD = 0;
            pl = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->flor);
            SubB(&sub78, &a->target, pl + 1);
            pv = &d78;
            { V* ps = &sub78; { V* ps_ = &(*ps); V* pd_ = &(d78); CPN(*pd_, *ps_); } }
            d78.z = 0.0f;
            if (!Within(pv, one)) {
                InvRot(&r78, &d78, pl);
                SetNavR(a, &r78, 1.0f, 0.0f);
            } else {
                SetNav0(a, Zero(), 0.0f, 0.0f);
                a->b30AD = 1;
            }
        } else if (a->state == 0 || a->state == 2 || a->state == 21 || a->state == 28) {
            void* fl;
            float dz;
            u8 close;
            u8 lowz;
            bool b;
            V* pf;
            V* pw;
            u8 turnFlag;
            float ang;
            float turn;
            float minA;
            float halfPi;
            float spd;
            fl = a->flor;
            cQuaternion_opAssign(&q, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(fl)));
            cVector_opAssign(&pos, cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(fl)));
            minA = 0.08726646f;
            halfPi = 1.5707964f;
            CP(tgt, a->target);
            yaw = a->yaw;
            spd = a->spd;
            {
                cy = Libc_Cosf(yaw);
                fwd.x = -Libc_Sinf(yaw);
                fwd.y = cy;
                fwd.z = 0.0f;
                fwd.w = 0.0f;
            }
            { V* pd_ = &cp; CP(*pd_, pos); }
            Sub(&diff, &tgt, &cp);
            { V* ps = &diff; V* pd2 = &flat; V* ps2 = &delta; V* pz = &flat; V* pd = &delta; CPN(*pd, *ps); CPN(*pd2, *ps2);
            len = 0.0f;
            flat.z = 0.0f;
            dz = AbsZ(delta.z);
            if (!IsZero3(pz)) NormLen(&flat, &len); }
            close = len < one;
            lowz = dz < three;
            b = false;
            if (close && lowz) b = true;
            a->b30AD = b;
            pf = &flat;
            pw = &fwd;
            turnFlag = 0;
            if ((((a->flags2 >> 4) & 1) || a->state == 0x15) && !close && !(spd <= 0.0f)) {
                InvRot(&wflat, &flat, &q);
                { V* ps_; V* pd_; ps_ = &wflat; pd_ = &want; ps_ = &wflat; CP(*pd_, *ps_); }
                if (Dot3(&flat, &fwd) < 0.0f) Neg(&want);
            } else if ((a->p3314 && TblOk(a->p3314) && a->p3314->b312 != 0x10) || (a->inv->b84 != 6 && a->inv->bA0)) {
                { Tgt* tp = a->p3314; tq.x = 0.0f;
                tq.y = 1.0f;
                tq.z = 0.0f;
                tq.w = 0.0f;
                QRot(&tq, &tp->quat); }
                { V* ps_ = &tq; turnFlag = 1; CP(want, *ps_); }
            } else {
                InvRot(&wfwd, &fwd, &q);
                { V* ps_; V* pd_; ps_ = &wfwd; pd_ = &want; ps_ = &wfwd; CP(*pd_, *ps_); }
            }
            if (((a->flags2 >> 4) & 1) || a->state == 0x15) {
                InvRot(&rr, pf, &q);
                { V* prr = &rr; tY.y = prr->y > 0.0f ? 1.0f : -1.0f; }
                tY.x = 0.0f;
                tY.z = 0.0f;
                tY.w = 0.0f;
                CP(res, tY);
                if (0.0f == res.y) res.y = 1.0f;
            } else if (!close && 0.0f == (float)(u8)!spd) {
                { V* pd_ = &cvec; CP(*pd_, *pf); }
                { float dd = Dot3(pf, pw); Scale(&scaled, pw, 0.1f * dd); }
                CPB(&s2, &scaled);
                { V* pd = &cvec; V* pa = &cvec; V* pb = &s2; Sub(pd, pa, pb); }
                Normalize(&cvec);
                InvRot(&rc, &cvec, &q);
                { V* ps_ = &rc; V* pd_ = &res; V* pe_ = &rc; CP(*pd_, *pe_); }
            } else {
                CP(res, want);
            }
            ang = Libc_Atan2f(-want.x, want.y);
            if (!(ang <= 3.1415927f)) ang -= 6.2831855f;
            else if (ang < -3.1415927f) ang += 6.2831855f;
            spd = MinZ(len * (1.0f / D_0049CFF0), spd);
            if (!(AbsZ(ang) <= 1.0471976f)) spd = MinA(0.001f, spd);
            else if (!(AbsZ(ang) <= 0.43633232f)) spd = MinA(0.5f, spd);
            if (close) spd = 0.0f;
            if (a->state != 0x1C) {
                turn = ang * (turnFlag ? 3.0f : 2.0f);
                turn = Clamp(turn, 4.1887903f, -4.1887903f);
                if (0.0f == spd) {
                    float aa = AbsZ(ang);
                    if (aa < minA) turn = 0.0f;
                    else if (aa < halfPi) turn = turn * (aa * (1.0f / halfPi));
                }
            } else {
                turn = 8.0f * ang;
                turn = Clamp(turn, 4.1887903f, -4.1887903f);
            }
            SetNav2(a, &res, spd, turn);
            if (a->b31B0) {
                cSplinedMotion_cVector_RestartTransition(a->curve, nGameUnits_Sec(0.2f));
                cSplinedMotion_cVector_SetTargetVal(a->curve, &a->target);
            }
        }
    }
    if (Vt54(a)) {
        AnimBlk* s = &a->blk;
        if (!a->b14) {
            float m;
            sel[0] = 0;
            sel[1] = 0;
            { int* ps = sel; m = MotionCtrl_GetSelectorMetric(s->anim, ps); }
            m = m * m;
            m = m * m;
            {
                float m8 = m * m;
                float c = cSkaParams_GetSliderValue(s->anim, 2); s->f2C = 1.0f + c * (1.25f * m8);
            }
        }
    }
}
