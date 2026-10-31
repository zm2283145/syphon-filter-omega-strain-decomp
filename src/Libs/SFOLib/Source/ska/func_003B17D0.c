#pragma cplusplus on
#include "types.h"

typedef struct V4 { __int128 q; } V4;
typedef struct It16 { char *p; } It16;

typedef struct ClipS {
    unsigned int type;
    unsigned int n;
    int stride;
    char pC[0x10];
    int tmask;
    int rmask;
    char key[0xC];
    char d30[0x10];
    char d40[0x30];
    char d70[0x10];
} ClipS;

typedef struct StateS {
    char p0[0x24];
    ClipS *clip;
    unsigned char reverse;
    unsigned char mirror;
    char p2A[2];
    float start;
    float end;
    float offset;
    char p38[0xC];
    signed char motionFlag;
    unsigned char loop;
    unsigned char align;
} StateS;

typedef struct ParamS {
    char p0[0x24];
    float time;
    char p28[4];
    float speed;
} ParamS;

typedef struct BoneS {
    char p0[0xC0];
    unsigned char *info;
    char pC4[0x1D0 - 0xC4];
} BoneS;

typedef struct BoneVec {
    int unk0;
    int count;
    BoneS *data;
} BoneVec;

typedef struct SkelInner {
    char p0[0x18];
    BoneVec bones;
} SkelInner;

typedef struct SkelS {
    char p0[0x20];
    SkelInner *inner;
    char p24[0xA0 - 0x24];
    char roots[0x10];
} SkelS;

typedef struct RootS {
    char p0[0xD0];
    float accum;
} RootS;

typedef void Hdr;
typedef struct W2 { float w[2]; W2() {} W2(float x) { w[0] = x; w[1] = 1.0f - w[0]; } } __attribute__((aligned(16))) W2;
struct BIt { BoneS *p; BIt(BoneS *q) : p(q) {} bool operator!=(const BIt &o) const { return !(p == o.p); } };

extern "C" {
void cSkaAnimAnchor_AccumulateDeltaRot(RootS *r, float a, float w);
void cSkaAnimAnchor_AccumulateDeltaPos(RootS *r, V4 *v, signed char f, float w);
void cSkaAnimAnchor_AccumulatePos(RootS *r, V4 *v, float w);
void cSkaAnimAnchor_AccumulateRot(RootS *r, V4 *q, unsigned char f, float w);
void cBone_AnimationAccumulateRotation(BoneS *b, V4 *q, float w);
void cBone_AnimationAccumulateOffset(BoneS *b, V4 *v, float w);
int cSkaAnimData_RootHasDeltaTranslationX(Hdr *h);
int cSkaAnimData_RootHasDeltaTranslationY(Hdr *h);
int cSkaAnimData_RootHasDeltaTranslationZ(Hdr *h);
float Deg2Rad(float d);
void cVector_ctor_void(V4 *v);
void cSkaAnim_Lerp(StateS *s, V4 *out, V4 *a, V4 *b, float *w);
void cQuaternion_Rotate(V4 *q, V4 *r);
void cQuaternion_GetIdentity(V4 *o);
int cSkaAnimData_RootHasDeltaRotation(Hdr *h);
unsigned char cSkaAnimData_RootHasDeltaTranslation(Hdr *h);
RootS *RootCollection_FindByKey(void *coll, void *key);
void cSkaAnimData_RootOffsetFromFirstFrameTranslation(V4 *o, Hdr *h);
It16 *cSkaAnimDataFrame_ConstIterator_opInc(It16 *it);
void cBoneData_PositionOffset(V4 *o, void *b);
void cSkaAnim_LerpXYZ(StateS *s, V4 *out, V4 *a, V4 *b, float *w);
void cVector_opAddAssign(V4 *a, V4 *b);
void cVector_opAssign(V4 *a, V4 *b);
V4 *cVector_GetZero(void);
void cVector_opMul(V4 *o, V4 *v, float s);
void cQuaternion_ctor_void(V4 *q);
void cVector_Rotate_cQuaternionR(V4 *v, V4 *q);
float *cQuaternion_Z_void(V4 *q);
float *cQuaternion_Y_void(V4 *q);
float *cQuaternion_W_void(V4 *q);
BoneS **std_vector_deleter_cBone_data_void(BoneVec *v);
void cQuaternion_opSub(V4 *o, V4 *q);
float func_001E50E0(V4 *a, V4 *b);
int cQuaternion_IsUnitQuatIdentity(V4 *q);
void cQuaternion_Negate(V4 *q);
V4 *cQuaternion_opAdd_void(V4 *q);
V4 *cSkaAnimDataFrame_ConstIterator_Quaternion(It16 *it);
float *cSkaAnimDataFrame_ConstIterator_Scalar(It16 *it);
void *cBone_Properties(BoneS *b);
float *cVector_Z_void_2(V4 *v);
float *cVector_Y_void_2(V4 *v);
float *cVector_X_void_2(V4 *v);
V4 *cSkaAnimDataFrame_ConstIterator_Vector(It16 *it);
void cVector_SetZero(V4 *v);
Hdr *cPointer_cSkaAnimData_opCast_constcSkaAnimDataPtr(ClipS **c);
void cSkaAnim_ProcessAnimData(float w, StateS *st, ParamS *pr, V4 *q, SkelS *sk);
}

static inline float FMin(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline char *ClipData(ClipS *c)
{
    if (c->type >= 3)
        return c->d70;
    if (c->type == 2)
        return c->d40;
    return c->d30;
}

void cSkaAnim_ProcessAnimData(float w, StateS *st, ParamS *pr, V4 *q, SkelS *sk)
{
    V4 *k0;
    V4 *k1;
    It16 it0;
    It16 it1;

    if (w == 0.0f)
        return;
    {
        ClipS *c = st->clip;
        int f1;
        float pos;
        unsigned int n = c->n;
        unsigned char loop = st->loop;
        float sp = *(volatile float *)&pr->speed;
        float rate = (float)n * sp;
        float t = pr->time;
        RootS *root;
        int tmask;
        BoneVec *bv;
        int rmask;
        int i;

        if (st->reverse) {
            if (t != 0.0f || !loop)
                t = 1.0f - t;
            rate = -rate;
        }
        if (st->offset != 0.0f) {
            t += st->offset;
            if (!(t < 1.0f))
                t -= 1.0f;
        } else {
            bool full = false;
            if (st->start == 0.0f && st->end == 1.0f)
                full = true;
            if (!full) {
                float e = st->end;
                float len = e - st->start;
                t = st->start + t * len;
                if (loop) {
                    if (!(t < e))
                        t -= len;
                } else {
                    t = FMin(1.0f, t);
                }
                rate *= len;
            }
        }
        pos = t * (float)n;
        f1 = (int)pos + 1;
        if (loop) {
            if (!(f1 < n))
                f1 = 0;
        } else {
            if (n < f1)
                f1 = n;
        }
        W2 wt(pos - (float)(int)pos);
        it0.p = ClipData(c) + (int)pos * c->stride * 4;
        it1.p = ClipData(c) + f1 * c->stride * 4;
        root = RootCollection_FindByKey(sk->roots, c->key);
        tmask = c->tmask;
        bv = &sk->inner->bones;
        rmask = c->rmask;
        BIt it(*std_vector_deleter_cBone_data_void(bv));
        BIt end(*std_vector_deleter_cBone_data_void(bv) + bv->count);
        i = 0;
        root->accum += w;
        if (it != end) {
            V4 tr;
            V4 rot;
            V4 motion;
            unsigned char te;


            cVector_ctor_void(&tr);
            cQuaternion_ctor_void(&rot);
            cVector_ctor_void(&motion);
            c = (ClipS *)cPointer_cSkaAnimData_opCast_constcSkaAnimDataPtr(&st->clip);
            te = cSkaAnimData_RootHasDeltaTranslation(c);
            cVector_SetZero(&motion);

            if (tmask & 1) {
                V4 bm;
                cSkaAnim_LerpXYZ(st, &tr, cSkaAnimDataFrame_ConstIterator_Vector(&it0), cSkaAnimDataFrame_ConstIterator_Vector(&it1), wt.w);
                cSkaAnimDataFrame_ConstIterator_opInc(&it0);
                cSkaAnimDataFrame_ConstIterator_opInc(&it1);
                if (st->mirror)
                    *cVector_X_void_2(&tr) = -*cVector_X_void_2(&tr);
                if (te) {
                    V4 s;
                    cVector_opMul(&s, &tr, rate);
                    cVector_opAssign(&motion, &s);
                    if (cSkaAnimData_RootHasDeltaTranslationX(c))
                        *cVector_X_void_2(&tr) = 0.0f;
                    else
                        *cVector_X_void_2(&motion) = 0.0f;
                    if (cSkaAnimData_RootHasDeltaTranslationY(c))
                        *cVector_Y_void_2(&tr) = 0.0f;
                    else
                        *cVector_Y_void_2(&motion) = 0.0f;
                    if (cSkaAnimData_RootHasDeltaTranslationZ(c))
                        *cVector_Z_void_2(&tr) = 0.0f;
                    else
                        *cVector_Z_void_2(&motion) = 0.0f;
                }
                if (st->mirror) {
                    cSkaAnimData_RootOffsetFromFirstFrameTranslation(&bm, c);
                    *cVector_X_void_2(&bm) = -*cVector_X_void_2(&bm);
                    cVector_opAddAssign(&tr, &bm);
                } else {
                    V4 b;
                    cSkaAnimData_RootOffsetFromFirstFrameTranslation(&b, c);
                    cVector_opAddAssign(&tr, &b);
                }
                {
                    V4 o;
                    cBoneData_PositionOffset(&o, cBone_Properties(it.p));
                    cVector_opAddAssign(&tr, &o);
                }
            }
            if (rmask & 1) {
                if (cSkaAnimData_RootHasDeltaRotation(c)) {
                    float a0 = *cSkaAnimDataFrame_ConstIterator_Scalar(&it0);
                    float d = *cSkaAnimDataFrame_ConstIterator_Scalar(&it1) - a0;
                    float a;
                    if (d < Deg2Rad(-180.0f))
                        d += Deg2Rad(360.0f);
                    else if (d > Deg2Rad(180.0f))
                        d += Deg2Rad(-360.0f);
                    a = a0 + d * wt.w[0];
                    cSkaAnimDataFrame_ConstIterator_opInc(&it0);
                    cSkaAnimDataFrame_ConstIterator_opInc(&it1);
                    if (st->mirror)
                        a = -a;
                    a *= rate;
                    cSkaAnimAnchor_AccumulateDeltaRot(root, a, w);
                }
                k0 = cSkaAnimDataFrame_ConstIterator_Quaternion(&it0);
                k1 = cSkaAnimDataFrame_ConstIterator_Quaternion(&it1);
                if (func_001E50E0(k0, k1) >= 0.0f) {
                    cSkaAnim_Lerp(st, &rot, k0, cQuaternion_opAdd_void(k1), wt.w);
                } else {
                    V4 nq;
                    cQuaternion_opSub(&nq, k1);
                    cSkaAnim_Lerp(st, &rot, k0, &nq, wt.w);
                    if (*cQuaternion_W_void(&rot) < 0.0f)
                        cQuaternion_Negate(&rot);
                }
                cSkaAnimDataFrame_ConstIterator_opInc(&it0);
                cSkaAnimDataFrame_ConstIterator_opInc(&it1);
                if (st->mirror) {
                    *cQuaternion_Y_void(&rot) = -*cQuaternion_Y_void(&rot);
                    *cQuaternion_Z_void(&rot) = -*cQuaternion_Z_void(&rot);
                }
                if (!cQuaternion_IsUnitQuatIdentity(q)) {
                    cQuaternion_Rotate(&rot, q);
                    cVector_Rotate_cQuaternionR(&tr, q);
                    if (te)
                        cVector_Rotate_cQuaternionR(&motion, q);
                }
                cSkaAnimAnchor_AccumulateRot(root, &rot, st->align, w);
                {
                    V4 id;
                    cQuaternion_GetIdentity(&id);
                    cBone_AnimationAccumulateRotation(it.p, &id, w);
                }
            }
            if (tmask & 1) {
                cSkaAnimAnchor_AccumulatePos(root, &tr, w);
                if (te)
                    cSkaAnimAnchor_AccumulateDeltaPos(root, &motion, st->motionFlag, w);
                cBone_AnimationAccumulateOffset(it.p, cVector_GetZero(), w);
            }
            i++;
            it.p++;
        }
        while (it != end) {
            int bit;
            bool hasT;
            bool hasR;
            V4 tr;
            V4 rot;
            V4 motion;

            BoneS *b = st->mirror ? &bv->data[it.p->info[1]] : it.p;
            bit = 1 << i;
            hasT = (tmask & bit) != 0;
            hasR = (rmask & bit) != 0;
            cVector_ctor_void(&tr);
            cQuaternion_ctor_void(&rot);
            cVector_ctor_void(&motion);
            if (hasT) {
                cSkaAnim_LerpXYZ(st, &tr, cSkaAnimDataFrame_ConstIterator_Vector(&it0), cSkaAnimDataFrame_ConstIterator_Vector(&it1), wt.w);
                cSkaAnimDataFrame_ConstIterator_opInc(&it0);
                cSkaAnimDataFrame_ConstIterator_opInc(&it1);
                if (st->mirror)
                    *cVector_X_void_2(&tr) = -*cVector_X_void_2(&tr);
                {
                    V4 o;
                    cBoneData_PositionOffset(&o, cBone_Properties(b));
                    cVector_opAddAssign(&tr, &o);
                }
            }
            if (hasR) {
                V4 *k0 = cSkaAnimDataFrame_ConstIterator_Quaternion(&it0);
                V4 *k1 = cSkaAnimDataFrame_ConstIterator_Quaternion(&it1);
                if (func_001E50E0(k0, k1) >= 0.0f) {
                    cSkaAnim_Lerp(st, &rot, k0, cQuaternion_opAdd_void(k1), wt.w);
                } else {
                    V4 nq;
                    cQuaternion_opSub(&nq, k1);
                    cSkaAnim_Lerp(st, &rot, k0, &nq, wt.w);
                    if (*cQuaternion_W_void(&rot) < 0.0f)
                        cQuaternion_Negate(&rot);
                }
                cSkaAnimDataFrame_ConstIterator_opInc(&it0);
                cSkaAnimDataFrame_ConstIterator_opInc(&it1);
                if (st->mirror) {
                    *cQuaternion_Y_void(&rot) = -*cQuaternion_Y_void(&rot);
                    *cQuaternion_Z_void(&rot) = -*cQuaternion_Z_void(&rot);
                }
                cBone_AnimationAccumulateRotation(b, &rot, w);
            }
            if (hasT)
                cBone_AnimationAccumulateOffset(b, &tr, w);
            i++;
            it.p++;
        }
    }
}
