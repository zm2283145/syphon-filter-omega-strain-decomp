// cNode::cNode(cPopulation&, int) (prototype locals numLinks/levelID/itemID/... ). The link count is read as the last argument of an inline
// whose earlier parameter is the default tNodeLink() temp: args are evaluated right to left but the temp's reference parameter is numbered first,
// which gives it s1 and the count s0 as in retail.
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
struct VN {
    float x, y, z, w;
    VN() {}
    VN(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    VN(const VN& o) { VN* d = this; const VN* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    VN& operator=(const VN& o) { VN* d = this; const VN* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct MtxN {
    VP r[4];
    MtxN() {}
    MtxN(const MtxN& o) { const MtxN* s = &o; MtxN* d = this; __int128 qa, qb; asm volatile { lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
};
struct ReaderN { int version; int a, b; char* cur; };
struct Elem8 { int a, b; };
static inline void CopyVP(VP* d, const VP* s) { __int128 q; asm volatile { lq q, 0x0(s); sq q, 0x0(d) } }
struct Vec8 { int capacity; unsigned int count; Elem8* data; inline void resize(int n, const Elem8& e = Elem8()); };
struct RelN { Vec8 v; unsigned char d; };
struct NodeN {
    void* vt;
    char pad4[8];
    int idC;
    char pad10[0x1D];
    unsigned char x2D;
    char pad2E[0x32];
    void* x60;
    int x64;
    RelN x68;
    int x78;
    int x7C;
    VP pos;
};
extern "C" {
extern void* const cNode_vtable[];
extern char D_004EA770[];
extern MtxN g_IdentityMatrix;
void cGOBJ_ctor(NodeN* self, int* id, int n, char* name);
void std_vector_tNodeLink_ctor(RelN* r);
void std_vector_imp_tNodeLink_resize(Vec8* v, unsigned int n, const Elem8* value);
void* nGobjManager_LookupGOBJ_int_int(int region, int id);
void cMatrix_SetAxes(MtxN* m, VP* a, VP* b, VP* c);
void cMatrix_SetTranslation(MtxN* m, VP* t);
float Math_Acos(float x);
double SoftFloat_FloatToDouble(float f);
int _dpfge(double a, double b);
NodeN* cNode_ctor_cPopulationR_int(NodeN* self, ReaderN* r, int arg);
}
static inline int ReadI(ReaderN* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt(ReaderN* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline float ReadF(ReaderN* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void ReadP(ReaderN* r, VP* v)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->w = 1.0f;
    v->x = x;
    v->y = y;
    v->z = z;
}
static inline void ReadV(ReaderN* r, VP* v, float w)
{
    float x = ReadF(r);
    float y = ReadF(r);
    float z = ReadF(r);
    v->x = x;
    v->w = w;
    v->y = y;
    v->z = z;
}
static inline void MulM(VN* v, MtxN* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline VN Xform(const VN& p, MtxN& m) { VN t = p; VN* tp = &t; MulM(tp, &m); return *tp; }
static inline VN& Unit(VN& v) { VN* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return v; }
static inline float Dot(const VN& a, const VN& b)
{
    float r;
    int t;
    const VN* ap = &a;
    const VN* bp = &b;
    asm { mtc1 zero, r }
    asm {
        lqc2 vf1, 0(ap)
        lqc2 vf2, 0(bp)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
inline void Vec8::resize(int n, const Elem8& e) { std_vector_imp_tNodeLink_resize(this, n, &e); }

static inline void ReadRels(ReaderN* r, Vec8* v, int n)
{
    int i;
    v->resize(n);
    for (i = 0; i < n; i++) {
        Elem8* e = &v->data[i];
        ReadInt(r, &e->a);
        ReadInt(r, &e->b);
    }
}
static inline void ReadRels2(ReaderN* r, Vec8* v, const Elem8& e, int n)
{
    int i;
    std_vector_imp_tNodeLink_resize(v, n, &e);
    for (i = 0; i < n; i++) {
        Elem8* l = &v->data[i];
        ReadInt(r, &l->a);
        ReadInt(r, &l->b);
    }
}NodeN* cNode_ctor_cPopulationR_int(NodeN* self, ReaderN* r, int arg)
{
    int numLinks;
    union { int i; } id;
    int gid = -1;
    cGOBJ_ctor(self, &gid, 10, D_004EA770);
    self->vt = (void*)cNode_vtable;
    { RelN* rl = &self->x68; std_vector_tNodeLink_ctor(rl); rl->d = 1; }
    {
        VP r0, r1, r2, t;
        MtxN m = g_IdentityMatrix;
        float a;
        int hi = ReadI(r);
        int lo = ReadI(r);
        id.i = lo | (hi << 16);
        self->idC = id.i;
        self->x60 = 0;
        if (r->version >= 0x40) {
            int c = ReadI(r);
            if (c >= 0)
                self->x60 = nGobjManager_LookupGOBJ_int_int(hi, c);
        }
        ReadInt(r, &self->x64);
        ReadP(r, &t);
        ReadV(r, &r0, 0.0f);
        ReadV(r, &r1, 0.0f);
        ReadV(r, &r2, 0.0f);
        cMatrix_SetAxes(&m, &r0, &r1, &r2);
        cMatrix_SetTranslation(&m, &t);
        {
            VN dir = Xform(VN(0.0f, 1.0f, 0.0f, 0.0f), m);
            dir.z = 0.0f;
            Unit(dir);
            a = Math_Acos(Dot(dir, VN(0.0f, 1.0f, 0.0f, 0.0f)));
            if (a != 0.0f && a != 3.1415927f) {
                if (!(dir.x < 0.0f))
                    a = 3.1415927f + (3.1415927f - a);
            }
        }
        if (_dpfge(SoftFloat_FloatToDouble(a), 6.2))
            a = 0.0f;
        CopyVP(&self->pos, &t);
        *(float*)&self->pos.w = a;
    }
    self->x78 = arg;
    ReadInt(r, &self->x7C);
    ReadRels2(r, &self->x68.v, Elem8(), ReadI(r));
    self->x2D = 0;
    return self;
}
