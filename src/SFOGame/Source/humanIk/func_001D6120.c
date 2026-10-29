#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V& Rotate(const V& q) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(%1); vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(%0)" : : "r"(this), "r"(&q) : "memory"); return *this; }
    void Add3(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); }
    V operator*(float k) const;
    V operator+(const V& b) const;
    V Add(const V& b) const;
    float& W() { return w; }
    V& Pt() { w = 1.0f; return *this; }
    void AddP(V o) { const void* po = &o; Add3(*(const V*)po); float* pw = &w; *pw = o.w; }
} __attribute__((aligned(16)));

static inline void ScaleTo(V* d, const V* s, float k) { int r; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }

static inline V QMul(const V* a, const V* b)
{
    V l0;
    V* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}
static inline V QW(const V* a, const V* b) { return QMul(a, b); }

static inline void Align(V* a, const V* b)
{
    int t;
    const V* xb;
    V* xa;
    xb = b;
    xa = a;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(xa)
        lqc2 vf2, 0x0(xb)
        vmul.xyzw vf3, vf1, vf2
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf5, vf1, vf0w
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni t, vi17
        andi t, t, 0x10
        beql t, zero, done
        nop
        sqc2 vf5, 0x0(xa)
        nop
    done:
        .set reorder
    }
}

static inline V NLerp(const V* a, const V* b, const float& s0)
{
    V l0;
    int r;
    V* q1 = &l0; const V* bb = a; const V* cc = b;
    float s = s0;
    float d0 = s + 1.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%1)\n lqc2 vf2, 0x0(%2)\n qmtc2.ni %0, vf3\n vaddax.xyzw ACC, vf1, vf0x\n vmaddax.xyzw ACC, vf2, vf3x\n vmsubx.xyzw vf4, vf1, vf3x\n vmul.xyzw vf5, vf4, vf4\n vmulax.w ACC, vf0, vf5x\n vmadday.w ACC, vf0, vf5y\n vmaddaz.w ACC, vf0, vf5z\n vmaddw.w vf6, vf0, vf5w\n vrsqrt Q, vf0w, vf6w\n vwaitq\n vmulq.xyzw vf7, vf4, Q\n sqc2 vf7, 0x0(%3)" : : "r"(s), "r"(bb), "r"(cc), "r"(&l0) : "memory");
#if 0
    asm {
        lqc2 vf1, 0x0(bb)
        lqc2 vf2, 0x0(cc)
        mfc1 r, s
        qmtc2.ni r, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(q1)
    }
#endif
    return l0;
}
static inline V Lerp(const V* a, const V* b, float s0)
{
    V l0;
    float s;
    s = s0;
    V* q1 = &l0; const V* bb = a; const V* cc = b;
    int r;
    asm {
        lqc2 vf1, 0x0(bb)
        lqc2 vf2, 0x0(cc)
        mfc1 r, s
        qmtc2.ni r, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}
inline V V::operator+(const V& b) const
{
    const V& a = *this;
    V l0;
    V* q1 = &l0;
    const V* pa = &a;
    const V* pb = &b;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
static inline V AddS(const V& a, const V& b)
{
    V l0;
    V* q1;
    const V* pa = &a;
    const V* pb = &b;
    q1 = &l0;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
static inline void AddTo(V* q1, const V* pa, const V* pb) { asm { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(q1) } }
inline V V::Add(const V& b) const { V l0; AddTo(&l0, this, &b); return l0; }
static inline const V& PtC(const V& v) { V* pv = (V*)&v; pv->w = 1.0f; return *pv; }
static inline V Point(const V& v) { V r = v; r.w = 1.0f; return r; }

struct Clip { int pad0; int frames; int pad8; int padC; int loop; };
struct Track {
    Clip* clip;
    void* keys;
    float rate;
    float time;
    unsigned int idx;
    float blend;
    float* k18;
    float* k1C;
    bool Active() const { return clip != 0; }
};
struct Sample {
    char pad[0x10];
    V pos;
    char pad20[0x10];
    V rot;
    char pad40[0x10];
    Sample();
    Sample(const Sample& o);
};

extern "C" {
void cSkaAnimDataSample_ctor_void(Sample* s);
unsigned char* cSkaAnimDataSample_IsEndOfData(Sample* s);
unsigned int cSkeletonData_GetBoneCount(void* keys);
void* cSkeletonData_GetBoneData(void* keys, unsigned int i);
void* cPointer_cSkaAnimData_opArrow(Track* t);
int cSkaAnimData_BoneHasTranslation(void* c, unsigned int i);
int cSkaAnimData_BoneHasRotation(void* c, unsigned int i);
int cSkaAnimData_RootHasDeltaTranslation(void* c);
int cSkaAnimData_RootHasDeltaRotation(void* c);
void cVector_ctor_float_float_float_float(V* d, float x, float y, float z, float w);
void* cSkaAnimDataSample_DeltaTranslation(Sample* s);
void* cSkaAnimDataSample_Translation(Sample* s);
void* cSkaAnimDataSample_DeltaRotation(Sample* s);
void* cSkaAnimDataSample_Rotation(Sample* s);
V LerpXYZ(const V& a, const V& b, float t);
void cVector_opAssign(void* d, const V& s);
void* cAxisAngle_ctor_eCoordinateAxis_float(void* d, unsigned char axis, float yaw);
void* cQuaternion_ctor_cAxisAngleR(void* d, void* a);
void* cQuaternion_opAssign(void* d, const void* s);
void cQuaternion_ctor_floatP(V* d, float* k);
V LerpAndNormalize(const V& a, const V& b, float t);
void cSkaAnimDataSample_ctor_cSkaAnimDataSampleR(Sample* d, const Sample* s);
void cSkaAnimDataIterator_GotoAnimFrame(Track* t, float time);
}
inline Sample::Sample() { cSkaAnimDataSample_ctor_void(this); }
inline Sample::Sample(const Sample& o) { cSkaAnimDataSample_ctor_cSkaAnimDataSampleR(this, &o); }

struct Off { char pad[8]; float x, y, z; };
struct Elem { char pad[0xC0]; Off* off; char padC4[0x1D0 - 0xC4]; };
struct It {
    Elem* p;
    It() {}
    It(const It& o) : p(o.p) {}
    bool operator==(const It& o) const { Elem* b = o.p; return p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
};
struct KList {
    int pad0;
    int count;
    It Begin();
    It End();
};
extern "C" Elem** std_vector_deleter_cBone_data_void_2(KList* l);
inline It KList::Begin() { It r; r.p = *std_vector_deleter_cBone_data_void_2(this); return r; }
inline It KList::End() { It r; r.p = *std_vector_deleter_cBone_data_void_2(this) + count; return r; }
struct Owner { char pad[0x18]; KList KList; };

struct Slot {
    char pad[0x20];
    V ref;
    char pad30[0x10];
    V a;
    V rot;
    V pos;
    unsigned char on;
    char pad71[0x4F];
    Slot* parent;
    Slot*& Parent() { return parent; }
    char padC4[0x3C];
};
extern "C" Slot UpperBodyNodeTable[];

struct Sec {
    int pad0;
    Owner* owner;
    char pad8[0xD8];
    Track ta;
    char pad100[0x10];
    Track tb;
    char pad130[0x310 - 0x130];
    unsigned char k310;
    unsigned char k311;
    signed char k312;
    signed char k313;
    char pad314[4];
    float w318;
    float w31C;
    float w320;
};

static inline void Key(void* k, unsigned int i) { cSkeletonData_GetBoneData(k, i); }
static inline Sample StepI(Track* t)
{
    Sample s;
    *cSkaAnimDataSample_IsEndOfData(&s) = 1;
    if (t->idx < cSkeletonData_GetBoneCount(t->keys)) {
        Key(t->keys, t->idx);
        if (cSkaAnimData_BoneHasTranslation(cPointer_cSkaAnimData_opArrow(t), t->idx)) {
            if (t->idx == 0 && cSkaAnimData_RootHasDeltaTranslation(cPointer_cSkaAnimData_opArrow(t))) {
                V a, b, c, d;
                cVector_ctor_float_float_float_float(&a, t->k18[0], t->k18[1], 0.0f, 0.0f);
                cVector_ctor_float_float_float_float(&b, 0.0f, 0.0f, t->k18[2], 0.0f);
                cVector_ctor_float_float_float_float(&c, t->k1C[0], t->k1C[1], 0.0f, 0.0f);
                cVector_ctor_float_float_float_float(&d, 0.0f, 0.0f, t->k1C[2], 0.0f);
                cVector_opAssign(cSkaAnimDataSample_DeltaTranslation(&s), LerpXYZ(a, c, t->blend));
                cVector_opAssign(cSkaAnimDataSample_Translation(&s), LerpXYZ(b, d, t->blend));
            } else {
                V a, b;
                cVector_ctor_float_float_float_float(&a, t->k18[0], t->k18[1], t->k18[2], 0.0f);
                cVector_ctor_float_float_float_float(&b, t->k1C[0], t->k1C[1], t->k1C[2], 0.0f);
                cVector_opAssign(cSkaAnimDataSample_Translation(&s), LerpXYZ(a, b, t->blend));
            }
            t->k18 += 4;
            t->k1C += 4;
        }
        if (cSkaAnimData_BoneHasRotation(cPointer_cSkaAnimData_opArrow(t), t->idx)) {
            if (t->idx == 0 && cSkaAnimData_RootHasDeltaRotation(cPointer_cSkaAnimData_opArrow(t))) {
                float k = t->blend;
                float yaw = (1.0f - k) * t->k18[0] + k * t->k1C[0];
                cQuaternion_opAssign(cSkaAnimDataSample_DeltaRotation(&s), cQuaternion_ctor_cAxisAngleR(&V(), cAxisAngle_ctor_eCoordinateAxis_float(&V(), 2, yaw)));
                t->k18 += 4;
                t->k1C += 4;
            }
            V a, b;
            cQuaternion_ctor_floatP(&a, t->k18);
            cQuaternion_ctor_floatP(&b, t->k1C);
            cQuaternion_opAssign(cSkaAnimDataSample_Rotation(&s), &LerpAndNormalize(a, b, t->blend));
            t->k18 += 4;
            t->k1C += 4;
        }
        t->idx++;
        *cSkaAnimDataSample_IsEndOfData(&s) = 0;
    }
    return s;
}

static inline Sample StepJ(Track* t) { return StepI(t); }
static inline Sample StepK(Track* t) { return StepJ(t); }
static inline Sample Step(Track* t) { return StepK(t); }
static inline float Remaining(Track* t)
{
    Clip* c = t->clip;
    if (c->loop)
        return 3.4028235e38f;
    return ((float)c->frames - t->time) / t->rate;
}
static inline bool Ending(Sec* self, Track* t) { return Remaining(t) < self->w320; }
static inline void Advance(Track* t, float dt) { float d = dt * t->rate;
    cSkaAnimDataIterator_GotoAnimFrame(t, t->time + d); }
static inline bool Crossed(bool now, bool was) { bool r = now && !was; return r; }

static inline V QC1(Slot* p, V* b, const V& q) { const V* a = &p->rot; *b = q; return QMul(a, b); }
extern "C" void cHumanIkRoutine_CalculateBaseIkPose(Sec* self, const V* root, float dt)
{
    Track* a = &self->ta;
    Track* b = &self->tb;
    if (a->clip || b->clip) {
        bool both = self->w318 > 0.0f && a->Active() && b->Active();
        Track* cur = a->Active() ? a : b;
        KList* l = &self->owner->KList;
        It first = l->Begin();
        It end = l->End();
        It it = first;
        Slot* slot = UpperBodyNodeTable;
        int i = 0;
        for (; it != end; slot++, i++, it.p++) {
            V q;
            V p;
            if (both) {
                Sample sa = Step(a);
                Sample sb = Step(b);
                if (slot->on) {
                    const V* ra = &sa.rot;
                    V qa = *ra;
                    V qb = sb.rot;
                    Align(&qa, &slot->ref);
                    Align(&qb, &slot->ref);
                    q = NLerp(&qa, &qb, self->w31C);
                    Off* o = it.p->off;
                    p = PtC(Lerp(&sa.pos, &sb.pos, self->w31C).Add(V(o->x, o->y, o->z, 0.0f)));
                }
            } else {
                Sample sc = Step(cur);
                if (slot->on) {
                    V* qd = &q;
                    *qd = sc.rot;
                    Elem* e = it.p;
                    Off* o = e->off;
                    p = PtC(AddS(sc.pos, V(o->x, o->y, o->z, 0.0f)));
                }
            }
            if (slot->on) {
                if (it != first) {
                    Slot* pa = slot->Parent();
                    V* sa_ = &slot->a;
                    *sa_ = q;
                    V* pr = &slot->rot;
                    *pr = QC1(pa, pr, q);
                    V* pp = &slot->pos;
                    *pp = p;
                    V* prot;
                    V* ppos = &pa->pos;
                    prot = &pa->rot;
                    pp->Rotate(*prot);
                    float wv = pp->W();
                    if (wv == 1.0f)
                        pp->Add3(*ppos);
                    else
                        pp->AddP(*ppos * wv);
                } else {
                    V* sa_ = &slot->a;
                    *sa_ = q;
                    V* pr = &slot->rot;
                    *pr = q;
                    *pr = QW(root, pr);
                    V* pp = &slot->pos;
                    *pp = p;
                    pp->Rotate(*root);
                }
            }
        }
        if (both) {
            bool was = Ending(self, a);
            Advance(a, dt);
            if (Crossed(Ending(self, a), was)) {
                if (((unsigned char)self->k310 == 0x15 && (unsigned char)self->k311 != 0x16) || ((unsigned char)self->k310 == 0x16 && (unsigned char)self->k311 != 0x15))
                    self->k312 = self->k313;
            }
            was = Ending(self, b);
            Advance(b, dt);
            if (Crossed(Ending(self, b), was)) {
                if ((unsigned char)self->k311 == 0x15 || (unsigned char)self->k311 == 0x16)
                    self->k312 = self->k313;
            }
        } else {
            bool act = a->Active();
            signed char k;
            if (act)
                k = self->k310;
            else
                k = self->k311;
            bool was = Ending(self, cur);
            Advance(cur, dt);
            if (Crossed(Ending(self, cur), was)) {
                if ((unsigned char)k == 0x15 || (unsigned char)k == 0x16)
                    self->k312 = self->k313;
            }
        }
    }
}