/* Clip_ResolveMotionPlacement: placement (rotation, position) at the end of a clip - the clip's stored
   end placement for a full clip, otherwise the root sample at the clip's end time. */
#pragma cplusplus on

/* 16-byte vector; copies are lq/sq quad moves (no C equivalent) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    void Set(const V& o) { const V* ps = &o; V* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { const V* ps = &o; V* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));

struct Placement {
    V q;
    V p;
    Placement(const V& a, const V& b) : q(a), p(b) {}
};

struct ClipData {
    char pad[0x50];
    Placement end;
};

struct Clip {
    char pad[0x24];
    ClipData* d;
    unsigned char reverse;
    float from;
    float to;
    float pos;
};

struct Sample;
extern "C" Sample* Anim_CopySample(Sample* d, Sample* s);
struct Sample {
    Sample() {}
    Sample(const Sample& o) { Anim_CopySample(this, (Sample*)&o); }
    signed char active;
    V v10;
    V v20;
    V v30;
    V v40;
};

struct Cursor;
extern "C" {
ClipData** cPointer_cSkaAnimData_ctor(Cursor* c, ClipData* d);
ClipData* cPointer_cSkaAnimData_opArrow(Cursor* c);
int cSkaAnimData_GetFrameCount(ClipData* d);
float cSkaAnimData_GetDuration(ClipData* d);
void cSkaAnimDataIterator_GotoStartAnimFrame(Cursor* c);
}
struct Cursor {
    Cursor(ClipData* dd, int* o) {
        Cursor* c = this;
        cPointer_cSkaAnimData_ctor(c, dd);
        c->out = o;
        c->speed = 0.0f;
        c->t = 0;
        c->i = 0;
        c->frac = 0;
        c->a = 0;
        c->b = 0;
        c->done = 0;
        c->speed = cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(c)) / cSkaAnimData_GetDuration(cPointer_cSkaAnimData_opArrow(c));
        cSkaAnimDataIterator_GotoStartAnimFrame(c);
    }
    ClipData* d;
    int* out;
    float speed;
    float t;
    unsigned int i;
    float frac;
    float* a;
    float* b;
    unsigned char done;
};

extern "C" {
void Clip_AdvanceCursor(Cursor* c, float t);
Sample* cSkaAnimDataSample_ctor_void(Sample* s);
signed char* cSkaAnimDataSample_IsEndOfData(Sample* s);
unsigned int cSkeletonData_GetBoneCount(int* out);
char* cSkeletonData_GetBoneData(int* out, int i);
int cSkaAnimData_BoneHasTranslation(ClipData* d, int i);
int RootClip_TranslationEnabled(ClipData* d);
int cSkaAnimData_BoneHasRotation(ClipData* d, int i);
int RootClip_IsEnabled(ClipData* d);
V* Vec4_Set(V* v, float x, float y, float z, float w);
V* cSkaAnimDataSample_DeltaTranslation(Sample* s);
V* cSkaAnimDataSample_Translation(Sample* s);
V* cSkaAnimDataSample_DeltaRotation(Sample* s);
V* cSkaAnimDataSample_Rotation(Sample* s);
V Vec3_LerpKeepW_190950(V* a, V* b, float s);
V Anim_ApproachTarget(V* a, V* b, float s);
void Vec4_Copy(V* d, const V& s);
V* cAxisAngle_ctor_eCoordinateAxis_float(V* v, unsigned char axis, float w);
V* Quat_FromYaw(V* q, V* axisAngle);
V* Quat_Assign(V* d, const V& s);
V* cQuaternion_ctor_floatP(V* d, float* s);
static inline void SetApproach(V* dst, V* a, V* b, Cursor& c)
{
    Quat_Assign(dst, Anim_ApproachTarget(a, b, c.frac));
}

static inline void SetYaw(V* dst, float ang)
{
    V q;
    V axis;
    Quat_Assign(dst, *Quat_FromYaw(&q, cAxisAngle_ctor_eCoordinateAxis_float(&axis, 2, ang)));
}

/* sample position as a point (w = 1) */
static inline V& SamplePoint(const Sample& r, V& p)
{
    V* pp;
    const Sample* rr = &r; /* unused: reproduces retail's dead load of the sample address */
    p.Set(r.v10);
    pp = &p;
    pp->w = 1.0f;
    return *pp;
}

static inline Sample SampleNext(Cursor& cur)
{
    Sample s;
    cSkaAnimDataSample_ctor_void(&s);
    *cSkaAnimDataSample_IsEndOfData(&s) = 1;
    if (cur.i < cSkeletonData_GetBoneCount(cur.out)) {
        cSkeletonData_GetBoneData(cur.out, cur.i);
        if (cSkaAnimData_BoneHasTranslation(cPointer_cSkaAnimData_opArrow(&cur), cur.i)) {
            if (cur.i == 0 && RootClip_TranslationEnabled(cPointer_cSkaAnimData_opArrow(&cur))) {
                V a0, a1, b0, b1;
                Vec4_Set(&a0, cur.a[0], cur.a[1], 0.0f, 0.0f);
                Vec4_Set(&a1, 0.0f, 0.0f, cur.a[2], 0.0f);
                Vec4_Set(&b0, cur.b[0], cur.b[1], 0.0f, 0.0f);
                Vec4_Set(&b1, 0.0f, 0.0f, cur.b[2], 0.0f);
                Vec4_Copy(cSkaAnimDataSample_DeltaTranslation(&s), Vec3_LerpKeepW_190950(&a0, &b0, cur.frac));
                Vec4_Copy(cSkaAnimDataSample_Translation(&s), Vec3_LerpKeepW_190950(&a1, &b1, cur.frac));
            } else {
                V a, b;
                Vec4_Set(&a, cur.a[0], cur.a[1], cur.a[2], 0.0f);
                Vec4_Set(&b, cur.b[0], cur.b[1], cur.b[2], 0.0f);
                Vec4_Copy(cSkaAnimDataSample_Translation(&s), Vec3_LerpKeepW_190950(&a, &b, cur.frac));
            }
            cur.a += 4;
            cur.b += 4;
        }
        if (cSkaAnimData_BoneHasRotation(cPointer_cSkaAnimData_opArrow(&cur), cur.i)) {
            if (cur.i == 0 && RootClip_IsEnabled(cPointer_cSkaAnimData_opArrow(&cur))) {
                float f = cur.frac;
                SetYaw(cSkaAnimDataSample_DeltaRotation(&s), (1.0f - f) * cur.a[0] + f * cur.b[0]);
                cur.a += 4;
                cur.b += 4;
            }
            {
                V qa, qb;
                cQuaternion_ctor_floatP(&qa, cur.a);
                cQuaternion_ctor_floatP(&qb, cur.b);
                SetApproach(cSkaAnimDataSample_Rotation(&s), &qa, &qb, cur);
                cur.a += 4;
                cur.b += 4;
            }
        }
        cur.i++;
        *cSkaAnimDataSample_IsEndOfData(&s) = 0;
    }
    return s;
}

int Clip_ResolveMotionPlacement(Placement* res_out, Clip* clip, int* out)
{
    int r; /* the early path returns without setting v0, as retail does */
    if (clip->pos == 0.0f) {
        bool full = false;
        if (clip->from == 0.0f && clip->to == 1.0f) {
            full = true;
        }
        if (full) {
            *res_out = clip->d->end;
            return r;
        }
    }
    Cursor cur(clip->d, out);
    float t = clip->pos;
    t = t != 0.0f ? t : (clip->reverse ? clip->from : clip->to);
    Clip_AdvanceCursor(&cur, t * cSkaAnimData_GetFrameCount(cPointer_cSkaAnimData_opArrow(&cur)));
    Sample res = SampleNext(cur);
    V ret;
    V p;
    {
        const V* pq = &res.v30;
        V* pb = &res_out->p;
        const V* pr = &ret;
        ret = SamplePoint(res, p);
        res_out->q = *pq;
        *pb = *pr;
    }
    r = 0;
    return r;
}
}
