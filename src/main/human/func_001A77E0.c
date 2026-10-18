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
ClipData** func_00190F20(Cursor* c, ClipData* d);
ClipData* func_00190F10(Cursor* c);
int func_00190F00(ClipData* d);
float func_00190EC0(ClipData* d);
void func_00190C70(Cursor* c);
}
struct Cursor {
    Cursor(ClipData* dd, int* o) {
        Cursor* c = this;
        func_00190F20(c, dd);
        c->out = o;
        c->speed = 0.0f;
        c->t = 0;
        c->i = 0;
        c->frac = 0;
        c->a = 0;
        c->b = 0;
        c->done = 0;
        c->speed = func_00190F00(func_00190F10(c)) / func_00190EC0(func_00190F10(c));
        func_00190C70(c);
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
Sample* func_00190A00(Sample* s);
signed char* func_001909F0(Sample* s);
unsigned int func_001909E0(int* out);
char* func_001909D0(int* out, int i);
int func_001909B0(ClipData* d, int i);
int RootClip_TranslationEnabled(ClipData* d);
int func_00190920(ClipData* d, int i);
int RootClip_IsEnabled(ClipData* d);
V* func_00132000(V* v, float x, float y, float z, float w);
V* func_00190990(Sample* s);
V* func_00190940(Sample* s);
V* func_00190900(Sample* s);
V* func_001907B0(Sample* s);
V Vec3_LerpKeepW_190950(V* a, V* b, float s);
V Anim_ApproachTarget(V* a, V* b, float s);
void Vec4_Copy(V* d, const V& s);
V* func_00190880(V* v, unsigned char axis, float w);
V* Quat_FromYaw(V* q, V* axisAngle);
V* Quat_Assign(V* d, const V& s);
V* func_001907C0(V* d, float* s);
static inline void SetApproach(V* dst, V* a, V* b, Cursor& c)
{
    Quat_Assign(dst, Anim_ApproachTarget(a, b, c.frac));
}

static inline void SetYaw(V* dst, float ang)
{
    V q;
    V axis;
    Quat_Assign(dst, *Quat_FromYaw(&q, func_00190880(&axis, 2, ang)));
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
    func_00190A00(&s);
    *func_001909F0(&s) = 1;
    if (cur.i < func_001909E0(cur.out)) {
        func_001909D0(cur.out, cur.i);
        if (func_001909B0(func_00190F10(&cur), cur.i)) {
            if (cur.i == 0 && RootClip_TranslationEnabled(func_00190F10(&cur))) {
                V a0, a1, b0, b1;
                func_00132000(&a0, cur.a[0], cur.a[1], 0.0f, 0.0f);
                func_00132000(&a1, 0.0f, 0.0f, cur.a[2], 0.0f);
                func_00132000(&b0, cur.b[0], cur.b[1], 0.0f, 0.0f);
                func_00132000(&b1, 0.0f, 0.0f, cur.b[2], 0.0f);
                Vec4_Copy(func_00190990(&s), Vec3_LerpKeepW_190950(&a0, &b0, cur.frac));
                Vec4_Copy(func_00190940(&s), Vec3_LerpKeepW_190950(&a1, &b1, cur.frac));
            } else {
                V a, b;
                func_00132000(&a, cur.a[0], cur.a[1], cur.a[2], 0.0f);
                func_00132000(&b, cur.b[0], cur.b[1], cur.b[2], 0.0f);
                Vec4_Copy(func_00190940(&s), Vec3_LerpKeepW_190950(&a, &b, cur.frac));
            }
            cur.a += 4;
            cur.b += 4;
        }
        if (func_00190920(func_00190F10(&cur), cur.i)) {
            if (cur.i == 0 && RootClip_IsEnabled(func_00190F10(&cur))) {
                float f = cur.frac;
                SetYaw(func_00190900(&s), (1.0f - f) * cur.a[0] + f * cur.b[0]);
                cur.a += 4;
                cur.b += 4;
            }
            {
                V qa, qb;
                func_001907C0(&qa, cur.a);
                func_001907C0(&qb, cur.b);
                SetApproach(func_001907B0(&s), &qa, &qb, cur);
                cur.a += 4;
                cur.b += 4;
            }
        }
        cur.i++;
        *func_001909F0(&s) = 0;
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
    Clip_AdvanceCursor(&cur, t * func_00190F00(func_00190F10(&cur)));
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
