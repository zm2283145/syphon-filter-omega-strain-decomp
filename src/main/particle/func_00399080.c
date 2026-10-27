#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)

#include "types.h"
#include "vslot_pad.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    void Norm();
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4& operator=(const V4& o) { const V4* s = &o; void* xx = this; __int128 t; V4* d = this; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void OpM(V4* pr, const V4* pa, float s)
{
    const V4* a_ = pa;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a_)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
}
static inline V4 operator*(const V4& a, float s)
{
    V4 r;
    OpM(&r, &a, s);
    return r;
}
static inline void OpMZ(V4* pr, const V4* pa, float s)
{
    __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(pr), "r"(pa), "f"(s) : "memory");
}
static inline void OpS(V4* pr, const V4* pa, const V4* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline void OpSx(V4* pr, const V4* pa, const V4* pb)
{
    const V4* a_ = pa;
    const V4* b_ = pb;
    asm {
        lqc2 vf1, 0x0(a_)
        lqc2 vf2, 0x0(b_)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
}
static inline V4 Sub(const V4& a, const V4& b)
{
    V4 r;
    OpS(&r, &a, &b);
    return r;
}
static inline V4 operator-(const V4& a, const V4& b)
{
    return Sub(a, b);
}
static inline void OpA(V4* pr, const V4* pa, const V4* pb)
{
    const V4* a_ = pa;
    const V4* b_ = pb;
    asm {
        lqc2 vf1, 0x0(a_)
        lqc2 vf2, 0x0(b_)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
}
static inline V4 Add(const V4& a, const V4& b)
{
    V4 r;
    OpA(&r, &a, &b);
    return r;
}
static inline V4 operator+(const V4& a, const V4& b)
{
    return Add(a, b);
}
static inline void Cross(V4* r, const V4* a, const V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vopmula.xyz $ACC, $vf1, $vf2; vopmsub.xyz $vf3, $vf2, $vf1; vsubw.w $vf3, $vf0, $vf0w; sqc2 $vf3, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline V4 CrossRn(const V4& a, const V4& b)
{
    V4 r;
    Cross(&r, &a, &b);
    return r;
}
static inline V4 CrossW0(const V4& a, const V4& b)
{
    return CrossRn(a, b);
}
static inline V4 CrossW1(const V4& a, const V4& b)
{
    return CrossW0(a, b);
}
static inline V4 CrossR(const V4& a, const V4& b)
{
    return CrossW1(a, b);
}
static inline void Normalize(V4* a)
{
    V4* r = a;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(r)
    }
}

inline void V4::Norm() { void* xx = this; Normalize(this); }
struct M4 { V4 r0, r1, r2, r3; const V4& Up() const { return r1; } };
class CamObj {
public:
    VPAD32(a) VPAD16(b) VPAD8(c)
    virtual M4 GetMtx();
};

typedef struct Elem { float x, y, z; float vx, vy, vz; float life; int pad; } Elem;
typedef struct EHandle { Elem* data; void* owner; } EHandle;
typedef struct InfoSub { char d[0xE0]; } InfoSub;
typedef struct Info {
    char p0[0x14];
    float f14;
    char p18[0x38 - 0x18];
    int f38;
    char p3C[0x74 - 0x3C];
    int f74;
    char p78[0x140 - 0x78];
    float f140, f144, f148;
    char p14C[0x180 - 0x14C];
    int f180;
    char p184[0x190 - 0x184];
    InfoSub sub[1];
} Info;
typedef struct Found { char p0[0xC]; int fC; char p10[4]; float f14; char p18[0x74 - 0x18]; int f74; } Found;
typedef struct Self {
    char p0[0x6C];
    int f6C;
    char p70[0x100 - 0x70];
    Info* info;
    CamObj* cam;
    EHandle* h;
    char p10C[0x130 - 0x10C];
    unsigned char f130;
} Self;

typedef struct Rec_00399080 { char pad[0x80]; int v[12]; char pad2[0xC0 - 0xB0]; } Rec_00399080;
typedef struct Ent_00399080 {
    char pad[0x24];
    Rec_00399080* recs;
    V4* pos;
    V4* c2C;
    V4* c30;
    V4* c34;
} Ent_00399080;
typedef struct Rs_00399080 {
    char pad[0xFB0];
    Ent_00399080 ents[1];
} Rs_00399080;

extern "C" {
typedef struct G_00399080 {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_00399080;
extern G_00399080 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern long long D_004BC1B0[];
extern char D_0053B540[];
extern char D_0053B544[];
extern V4 D_004BC550;
extern signed char D_0053BB40;
extern signed char D_0053BB48;
extern signed char D_0053BB50;
extern V4 D_004BC5A0;
extern V4 D_004BC5B0;
extern V4 D_004BC5C0;
void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void XLib_DrawSprites(void* s);
void XLib_DrawStrip(void* s);
void cVector_opAssign(V4* d, const V4* s);
void tIRGBA_opAssign_tRGBAR(V4* d, const V4* s);
float tVifFloatToInt_short_4_Bias(void);
V4* cVector_ctor_float_float_float_float(V4* o, float x, float y, float z, float w);
int GetEffectID__15cParticleSystemCFRC1(void* mgr, void* key);
void* cLList_cParticleDefinitionPtr_opIndex(void* self, int n);
}
#define D_00539220 (D_00539210.f20)
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_0053922C (D_00539210.f2C)
#define D_00539230 (D_00539210.f30)
#define D_00539234 (D_00539210.f34)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)

#define RS ((Rs_00399080*)g_Video)

static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }

static inline void Begin(void)
{
    Ent_00399080* e;
    D_00539238 = Prim();
    D_0053923C = Mode();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
}
static inline void Flush(int& n)
{
    XLib_DrawSprites(g_Video);
    Begin();
    n = 0;
}
static inline void EmitC(const V4& pos, const V4& col)
{
    Ent_00399080* e;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], &col);
    D_005381F8 = 2LL << 32;
}
static inline V4* UV(const V4& uv)
{
    V4 tmp;
    float u = uv.x + tVifFloatToInt_short_4_Bias();
    return cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w);
}
static inline V4* UVW0(const V4& uv) { return UV(uv); }
static inline V4* UVW1(const V4& uv) { return UVW0(uv); }
static inline void Emit(V4 pos, const V4& col, const V4& uv)
{
    Ent_00399080* e;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], &col);
    cVector_opAssign(&e->c34[D_00539224 - 1], UVW1(uv));
    D_005381F8 = 6LL << 32;
}
static inline void Restart(void)
{
    if (D_00539220 > 0) {
        if (D_00539230 > 0) {
            int k = D_00539220 - 1;
            if (D_00539234 < 12) {
                Ent_00399080* e = &RS->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->recs[k].v[D_00539234] = v;
                D_00539234++;
            } else {
                if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
                { int v; int j; Rec_00399080* s; v = D_00539238 - 1; s = ((Rec_00399080**)(g_Video + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->v[j] = v; }
                D_00539230 = 0;
                D_00539234 = 0;
                D_00539228++;
                D_00539220++;
            }
        }
    }
}
static inline Elem* At(Self* s, int i)
{
    EHandle* h = s->h;
    Elem* e = 0;
    if (h && h->owner == s) e = &h->data[i];
    return e;
}

extern "C" void cParticleBox_Render(Self* self)
{
    V4 col;
    V4 c2;
    V4 c3;
    V4 pos;
    V4 vel;
    int n;
    int i;
    int start;
    Found* found;
    if (At(self, 0) == 0) return;
    col.Set(self->info->f140, self->info->f144, self->info->f148, 1.0f);
    D_005392D8 = D_004BC1B0[self->info->f38];
    g_DrawMode = 5;
    n = 0;
    Begin();
    start = 0;
    if (self->info->f180 > 0) {
        int k;
        found = 0;
        for (k = 0; k < self->info->f180; k++) {
            found = *(Found**)cLList_cParticleDefinitionPtr_opIndex(D_0053B544, GetEffectID__15cParticleSystemCFRC1(D_0053B540, &self->info->sub[k]));
            if (found->fC == 0) break;
            found = 0;
        }
    if (found) {
        int j;
        c2.Set(0.0f, 0.0f, 0.0f, self->info->f14);
        cTexMan_SetActive(g_TextureMgr, found->f74);
        start = self->f6C / 12;
        for (j = 0; j < start; j++) {
            Elem* e = At(self, j);
            if (e) {
                col.w = e->life;
                c2.w = found->f14;
                if (!(col.w <= 0.001f)) {
                    c2.x = e->x;
                    c2.y = e->y;
                    c2.z = e->z;
                    EmitC(c2, col);
                    if (++n >= 33) Flush(n);
                }
            }
        }
        if (n > 0) Flush(n);
    }
    }
    cTexMan_SetActive(g_TextureMgr, self->info->f74);
    if (self->f130 == 1) {
        c3.Set(0.0f, 0.0f, 0.0f, self->info->f14);
        for (i = start; i < self->f6C; i++) {
            Elem* e = At(self, i);
            if (e) {
                col.w = e->life;
                if (!(col.w <= 0.001f)) {
                    c3.x = e->x;
                    c3.y = e->y;
                    c3.z = e->z;
                    EmitC(c3, col);
                    if (++n >= 33) Flush(n);
                }
            }
        }
        if (n > 0) XLib_DrawSprites(g_Video);
    } else {
        if (!D_0053BB40) {
            D_0053BB40 = 1;
            D_004BC5A0.Set(0.0f, 0.0f, 1.0f, 0.0f);
        }
        if (!D_0053BB48) {
            D_004BC5B0.Set(0.5f, 1.0f, 1.0f, 0.0f);
            D_0053BB48 = 1;
        }
        if (!D_0053BB50) {
            D_004BC5C0.Set(1.0f, 0.0f, 1.0f, 0.0f);
            D_0053BB50 = 1;
        }
        pos.Set(0.0f, 0.0f, 0.0f, 1.0f);
        vel.Set(0.0f, 0.0f, 0.0f, 1.0f);
        V4 side = CrossR(self->cam->GetMtx().Up(), D_004BC550);
        side.Norm();
        OpMZ(&side, &side, 0.07f);
        for (i = start; i < self->f6C; i++) {
            Elem* e = At(self, i);
            if (e) {
                col.w = e->life;
                if (!(col.w <= 0.001f)) {
                    pos.x = e->x;
                    pos.y = e->y;
                    pos.z = e->z;
                    pos.w = self->info->f14;
                    vel.x = e->vx;
                    vel.y = e->vy;
                    vel.z = e->vz;
                    Emit(pos - side, col, D_004BC5A0);
                    Emit(pos - vel * self->info->f14, col, D_004BC5B0);
                    Emit(pos + side, col, D_004BC5C0);
                    n++;
                    Restart();
                }
            }
        }
        if (n > 0) XLib_DrawStrip(g_Video);
    }
}




