#pragma opt_addtogetherconstantpartsoftreeexpressions off
#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    static void VU0Subtract(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator-(const V& vector) const { V result; VU0Subtract(result, *this, vector); return result; }
} __attribute__((aligned(16)));
static inline V Sub(const V& a, const V& b)
{
    V r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline float Len(V v) { return v.Length(); }
static inline void SubTo(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct Stream { char pad[0xC]; char* cur; };
static inline void ReadF(Stream* s, float* out) { *out = *(float*)s->cur; s->cur += 4; }
struct VVec { int pad; int count; V* data; unsigned char flag; char pad_d[3]; V*& Data() { return data; } V& At(int i) { return Data()[i]; } V& operator[](int i) { return data[i]; } };
struct FVec { int pad; int count; float* data; unsigned char flag; char pad_d[3]; };
struct Link { int f0; int f4; int f8; unsigned char fC; char pad[0x13]; };
struct PathObj {
    void* vt;
    char pad4[0x2C];
    int f30;
    char pad34[0x60];
    VVec pts;
    VVec v2;
    FVec lens;
    float fC4;
    float fC8;
    int fCC;
    Link* link;
    float fD4;
    int type;
    unsigned char fDC;
    char padDD[3];
    float fE0;
    int fE4;
};
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
__declspec(weak) __declspec(DROPDTOR) int k6_ctx(double a, double b) { return a >= b; }
extern "C" {
extern char D_004DB280[];
extern float D_0048A9B8[];
extern char D_004A4550[];
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char g_IsMultiplayer;
void cGameGOBJ_ctor(PathObj* self, void* a1, Stream* s, int kind);
void std_vector_cVector_ctor(VVec* v);
void std_vector_cQuaternion_ctor(VVec* v);
void std_vector_float_ctor(FVec* v);
void cGOBJ_CreateMovementInfo_void(PathObj* self);
void std_vector_imp_cVector_resize(VVec* v, int n, V* fill);
void std_vector_imp_cQuaternion_resize(VVec* v, int n, V* fill);
void std_vector_pod_int_resize(FVec* v, int n, float* fill);
void cPathedGOBJ_CreatePathedGobjInfo(PathObj* self);
int Alloc_Lock(int);
int EnableIntc(int);
void* cMemMan_Allocate(int, int, char*, int);
PathObj* cPathedGOBJ_ctor(PathObj* self, void* a1, Stream* s);
}
PathObj* cPathedGOBJ_ctor(PathObj* self, void* a1, Stream* s)
{
    V e;
    int n;
    V now, then;
    V f1, f2;
    { V* pe = &e; }
    cGameGOBJ_ctor(self, a1, s, 2);
    self->vt = D_004DB280;
    { VVec* v = &self->pts; std_vector_cVector_ctor(v); v->flag = 1; }
    { VVec* v = &self->v2; std_vector_cQuaternion_ctor(v); v->flag = 1; }
    { FVec* v = &self->lens; std_vector_float_ctor(v); v->flag = 1; }
    cGOBJ_CreateMovementInfo_void(self);
    self->f30 = 0;
    self->type = *(int*)s->cur;
    s->cur += 4;
    self->fD4 = *(float*)s->cur;
    s->cur += 4;
    self->fD4 *= 2.0f;
    self->fC4 = *(float*)s->cur;
    s->cur += 4;
    n = *(int*)s->cur;
    s->cur += 4;
    {
        std_vector_imp_cVector_resize(&self->pts, n, &f1);
    }
    for (int i = 0; i < n; i++) {
        ReadF(s, &self->pts.data[i].x);
        ReadF(s, &self->pts.data[i].y);
        ReadF(s, &self->pts.data[i].z);
        self->pts.data[i].w = 1.0f;
    }
    std_vector_pod_int_resize(&self->lens, n, D_0048A9B8);
    for (int i = 0; i < n - 1; i++) {
        now = self->pts.At(i);
        then = self->pts.At(i + 1);
        float dist = (now - then).Length();
        dist = (dist <= 0.01) ? 1.0f : dist;
        self->lens.data[i] = dist;
    }
    std_vector_imp_cQuaternion_resize(&self->v2, n, &f2);
    for (int i = 0; i < n; i++) {
        ReadF(s, &self->v2.data[i].x);
        ReadF(s, &self->v2.data[i].y);
        ReadF(s, &self->v2.data[i].z);
        ReadF(s, &self->v2.data[i].w);
    }
    if (g_IsMultiplayer) {
        self->link = 0;
        cPathedGOBJ_CreatePathedGobjInfo(self);
    } else {
        Link* p;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = (Link*)cMemMan_Allocate(0, 0x20, D_004A4550, 0x247);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (p) {
            p->f0 = 0;
            p->f4 = 0;
            p->fC = 0;
        }
        self->link = p;
    }
    self->link->f4 = 1;
    self->link->f0 = 0;
    if (self->type == 1 || self->type == 3 || self->type == 4) {
        self->fDC = 1;
        self->fC8 = 0.0f;
        self->fE0 = 1.0f;
    } else {
        self->fDC = 0;
        self->fE0 = 0.0f;
        self->fC8 = 1e-5f;
    }
    self->fE4 = 0;
    self->link->f8 = -1;
    self->fCC = -1;
    return self;
}



