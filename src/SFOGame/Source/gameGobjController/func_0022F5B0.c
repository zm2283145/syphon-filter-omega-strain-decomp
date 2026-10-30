#pragma cplusplus on
#include "types.h"
typedef int Q128 __attribute__((mode(TI)));
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { const V4* s = &o; V4* d = this; Q128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V4& operator=(const V4& o) { *(Q128*)this = *(const Q128*)&o; return *this; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector ops (COP2)
static inline void VSub(V4* d, const V4* a, const V4* b) {
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline V4 operator-(const V4& a, const V4& b) { V4 r; VSub(&r, &a, &b); return r; }
static inline float VLen(const V4* v) {
    float r = 0.0f; int t;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(v) : "memory");
    return r;
}
static inline void VNorm(V4* v) {
    __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory");
}
static inline float VDot(const V4* a, const V4* b) {
    int t, u; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%3); lqc2 $vf2, 0x0(%4); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %2, %1, %1; mtc1 %2, %0" : "+f"(r), "=&r"(t), "=&r"(u) : "r"(a), "r"(b) : "memory");
    return r;
}
// abs.s/max.s/min.s: MW has no C form that emits these single FPU ops here
static inline float FAbs(float x) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float FMax(float a, float b) { float r; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float FMin(float a, float b) { float r; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float Clamp01(float v) { float r = 0.0f; float lo = 0.0f, hi = 1.0f; r = FMax(v, lo); r = FMin(r, hi); return r; }

struct Obj;
struct Sub14 { char p[0x14]; unsigned char b14; };
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual bool IsPlayer(); /* 0x54 */
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v1A();
    virtual V4* Aim(); /* 0x74 */
    virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void OnShot(Obj* c, float f, int n, int part); /* 0xA0 */
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v2A(); virtual void v2B(); virtual void v2C();
    virtual void v2D();
    virtual V4 GetPos(int a); /* 0xC0 */
    virtual void v2F();
    virtual int Stance(); /* 0xC8 */
    virtual float PartMul(int part); /* 0xCC */
    virtual void v32();
    virtual int IsAiming(); /* 0xD4 */
    int pad4[2];
    int id;
    char p10[0x20 - 0x10];
    float x20;
    float x24;
    Obj* x28;
    int x2C;
    Obj* x30;
    int pad34;
    float x38;
    int x3C;
    int x40;
    int x44;
    char p48[0x4C - 0x48];
    int x4C;
    char p50[0x58 - 0x50];
    Obj* x58;
    char p5C[0x33A8 - 0x5C];
    float x33A8;
    char p33AC[0x3470 - 0x33AC];
    unsigned char b3470;
};
struct Weap {
    char p[0x34];
    int i34, i38, i3C, i40, i44;
    char p48[0x4C - 0x48];
    int i4C;
    float f50, f54;
    char p58[0x64 - 0x58];
    int i64;
    char p68[0xF0 - 0x68];
    unsigned char bF0;
};
struct Tun { float f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34; };

extern "C" {
extern Tun* D_0048ACB8;
extern float D_0048ACC0;
extern float D_0048ACC8;
extern int g_HumanActorClassKey;
extern int g_WeaponDatabase;
extern int g_TimerAccum;
extern long g_TickCounter64;
extern char g_TargetVisMgr[];
bool cTargetManager_IsLosBlocked(void* m, Obj* a, Obj* b, int c, int d);
Weap* cWeaponDB_GetEntry(int db, int id);
float cHuman_GetRecoilAimAdjust(Obj* a);
}

static inline int DivTimeT(unsigned int ticks)
{
    int bit;
    long d;
    int q;
    int i;
    long n;
    int sh;
    int c = (int)((float)ticks / 5.76f);
    n = g_TickCounter64;
    n += c;
    sh = 30;
    d = 100;
    bit = 1 << sh;
    d <<= sh;
    q = 0;
    sh++;
    for (i = 0; i < sh; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}
static inline int Div64(int sh, long q, long v) {
    int i, bit, res;
    bit = 1 << sh;
    q <<= sh;
    sh++;
    res = 0;
    for (i = 0; i < sh; i++) {
        long r = v - q;
        if (r >= 0) { v = r; res += bit; }
        q >>= 1;
        bit >>= 1;
    }
    return res;
}
static inline bool NotVis(Obj* c, Obj* t) { return !cTargetManager_IsLosBlocked(g_TargetVisMgr, c->x30, t, 0, 0); }
static inline bool IsNpc(Obj* c) { return !c->IsPlayer(); }
static inline bool HValid(Obj* c) { return !c->x28 || (c->x28->id == c->x2C) != 0; }
static inline Obj* HGet(Obj* c) { return HValid(c) ? c->x28 : 0; }
static inline int HId(Obj* o) { int d; return *(o ? &o->id : (d = -1, &d)); }

extern "C" void cGameGobjController_UpdateToHitProbability(Obj* c, Obj* t, int weapon, int part) {
    float acc = 0.0f;
    float rate = acc;
    float dt;
    float shake;
    unsigned char vis;
    int prev;
    unsigned int ticks;
    Obj* aimer;
    vis = t ? NotVis(c, t) : false;
    prev = c->x40;
    ticks = *(volatile int*)0x10000800 + g_TimerAccum;
    aimer = 0;
    c->x40 = DivTimeT(ticks);
    dt = (float)(c->x40 - prev) / 1000.0f;
    shake = 1.0f;
    if (weapon < 0) {
        c->x24 = 0.0f;
        c->x20 = 0.0f;
        c->x28 = t;
        c->x2C = HId(t);
        c->x3C = part;
        return;
    }
    {
        Weap* w = cWeaponDB_GetEntry(g_WeaponDatabase, weapon);
        Obj* me = c->x30;
        int noScale = 0;
        bool ok, ok2;
        int* pp = &g_HumanActorClassKey;
        int key = *pp;
        if (me->x4C == key) {
            if (!(me->x33A8 <= 0.0f)) vis = 0;
            if (c->IsPlayer()) shake = cHuman_GetRecoilAimAdjust(me);
            noScale = me->b3470 != 0;
        }
        ok = 1;
        ok2 = ok;
        if (!c->x30->IsAiming()) {
            if (!IsNpc(c)) ok2 = 0;
        }
        if (!ok2 && w->bF0 != 7) ok = 0;
        unsigned char ok3 = ok;
        if (t) {
            if (t == HGet(c) && vis && part == c->x3C && ok3) {
                aimer = t->x58;
                float f31 = (float)w->i38;
                float f30 = (float)w->i44 / 100.0f;
                float f29 = (float)w->i34;
                float f28 = (float)w->i40 / 100.0f;
                float f27 = w->f50;
                float f26 = (float)w->i3C;
                float f25 = (float)w->i4C / 100.0f;
                float f54 = w->f54;
                float dist;
                Obj* s;
                s = c->x30;
                {
                V4 a = s->GetPos(-1);
                V4 b = t->GetPos(-1);
                V4 dd = b - a;
                dist = VLen(&dd);
                if (dist <= f26) {
                    float m;
                    rate = c->x20;
                    if (dist < f29) {
                        acc = f28;
                    } else {
                        float d = dist - f29;
                        if (dist < f31) { float q = f31 - f29; acc = f28 + d * (f30 - f28) / q; }
                        else { float e = dist - f31; float q = f26 - f31; acc = f30 + e * (f25 - f30) / q; }
                        f27 += d * (f54 - f27) / (f26 - f29);
                    }
                    m = 1.0f + (float)t->x44 / 100.0f;
                    m *= m;
                    if (!noScale) {
                        f27 *= m;
                        acc /= m;
                    }
                    if (c->IsPlayer()) f27 *= D_0048ACC8;
                    else f27 += D_0048ACB8->f20;
                    if (f27) f27 = 1.0f / f27;
                    else f27 = 10.0f;
                    f26 = dt * f27;
                    switch ((unsigned char)s->Stance()) {
                    case 2:
                        acc = 0.0f;
                        rate = acc;
                        f26 = acc;
                        break;
                    case 4:
                        f26 *= D_0048ACB8->fC;
                        acc *= D_0048ACB8->f8;
                        break;
                    }
                    {
                        V4* av = c->Aim();
                        if (av) {
                            float r = VLen(av) / D_0048ACB8->f1C;
                            float k = 1.0f - (1.0f - D_0048ACB8->f4) * r;
                            if (k < 0.0f) k = 0.0f;
                            f26 *= k;
                            k = 1.0f - (1.0f - D_0048ACB8->f0) * r;
                            if (k < 0.0f) k = 0.0f;
                            acc *= k;
                        }
                    }
                    float g25 = c->x38;
                    if (!c->IsPlayer()) {
                        g25 *= D_0048ACC0;
                        if (dist < D_0048ACB8->f30) g25 *= D_0048ACB8->f34;
                    }
                    f26 *= g25 * t->PartMul(part);
                    float bonus = 0.0f;
                    {
                        int st = t->Stance();
                        switch ((unsigned char)st) {
                        case 2:
                            acc *= D_0048ACB8->f18;
                            if (!c->IsPlayer()) bonus += D_0048ACB8->f28;
                            break;
                        }
                        if ((unsigned char)st == 3 || (unsigned char)st == 4) acc *= D_0048ACB8->f14;
                    }
                    {
                        V4* av = aimer ? aimer->Aim() : 0;
                        if (av) {
                            V4 dir(-dd.y, dd.x, dd.z, 0.0f);
                            float k;
                            VNorm(&dir);
                            dt = FAbs(VDot(av, &dir)) / D_0048ACB8->f1C;
                            dt = (float)(int)(5.0f * dt) / 5.0f;
                            k = 1.0f - (1.0f - D_0048ACB8->f10) * dt;
                            if (k < 0.0f) k = 0.0f;
                            acc *= k;
                            if (!c->IsPlayer()) bonus += D_0048ACB8->f24 * dt;
                        }
                    }
                    acc *= shake;
                    acc *= g25;
                    acc = Clamp01(acc);
                    if (!c->IsPlayer()) {
                        if (!c->x30->IsAiming()) bonus += D_0048ACB8->f2C;
                        f26 -= bonus * f27;
                    } else {
                        float x24 = c->x24, x20 = c->x20;
                        float n = x24 * x20;
                        if (x24 < acc) rate = n / acc;
                    }
                    rate += f26;
                    rate = Clamp01(rate);
                }
                }
            }
        }
        if (t && vis && aimer) {
            int n0 = 0, n1 = 0;
            __asm__ volatile ("move $0, $0"); // zero-byte scheduling barrier: keeps the dead conversions below in this block
            n0 = (int)(10.0f * rate);
            n1 = (int)(10.0f * c->x20);
            if (aimer->IsPlayer() && ((Sub14*)aimer->x30)->b14 && part == 0)
                aimer->OnShot(c, rate, (int)(rate * (float)w->i64), part);
        }
    }
    c->x24 = acc;
    c->x20 = rate;
    c->x28 = t;
    c->x2C = HId(t);
    c->x3C = part;
}

