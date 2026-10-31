#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rotateloops off

struct V {
    float x, y, z, w;
    V() {}
    V* P() { return this; }
    V(const V* p, int) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(p), "r"(this) : "memory"); }
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 t; V* dd = this; const V* ps = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(ps), "r"(dd) : "memory"); }
    V& operator=(const V& o) { void* xx = this; V* dd = this; const V* ps = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(ps), "r"(dd) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct R { float f[12]; };
struct Mx;
extern "C" void Mtx_MakeAxisRotation(Mx* m, float a, float b, float c, float d);
extern "C" 
struct Mx { R r; V t;
    Mx() {}
    Mx(float a, float b, float c, float d) { Mtx_MakeAxisRotation(this, a, b, c, d); }
    Mx(void* q);
    void SetRot(const Mx& rot) {
        r.f[0] = rot.r.f[0]; r.f[1] = rot.r.f[1]; r.f[2] = rot.r.f[2];
        r.f[4] = rot.r.f[4]; r.f[5] = rot.r.f[5]; r.f[6] = rot.r.f[6];
        r.f[8] = rot.r.f[8]; r.f[9] = rot.r.f[9]; r.f[10] = rot.r.f[10];
        r.f[3] = rot.r.f[3]; r.f[7] = rot.r.f[7]; r.f[11] = rot.r.f[11];
    }
} __attribute__((aligned(16)));

static inline void XformInPlace(V* v, const Mx* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}
static inline V Xform(const Mx& m, const V& v) { V t = v; const V* pt = &t; XformInPlace((V*)pt, &m); return V(pt, 0); }
static inline V AddH(const V& a, const V& b)
{
    V r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

struct Strip { char pad[0x80]; int idx[12]; char padB0[0x10]; };
struct Ent {
    char pad[0x24];
    Strip* strip;
    V* pos;
    V* c2C;
    V* c30;
    V* c34;
};
struct Rs {
    char pad[0xFB0];
    Ent ents[1];
};
struct Part {
    char pad0[0x10];
    V pos;
    char pad20[0x10];
    char q[0x10];
    V v[3];
    V uv[3];
    unsigned char dead;
    char padA1[0xF];
};
struct Desc {
    char pad0[0x38];
    int type;
    int n;
    float f40;
    float f44;
    float f48;
    char pad4C[4];
    float f50;
    float f54;
    int f58;
    char pad5C[8];
    unsigned char f64;
    char pad65[0xF];
    int f74;
    char pad78[8];
    char f80[0x30];
    long long fB0;
    long long fB8;
    long long fC0;
    long long fC8;
    long long fD0;
    long long fD8;
    char padE0[0x50];
    long long f130;
    char pad138[0x900 - 0x138];
    V f900[9];
    char pad990[0x920 - 0x990 + 0x90];
};
struct Obj {
    char pad0[0x64];
    float f64;
    char pad68[4];
    int n6C;
    int f70;
    char pad74[0x90 - 0x74];
    V f90[6];
    char padF0[0];
};
#define OF_(p, o, T) (*(T*)((char*)(p) + (o)))

extern "C" {
typedef struct G {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char D_005381F0[];
extern long long D_005381F8;
extern long long D_004BC1B0[];
extern int* D_005381C8;

static inline unsigned int Unpack(unsigned int a, unsigned int n) { return (0x6C000000 | ((n) << 16) | (a)); }
static inline void QCopy(const void* s, void* d, int n)
{
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline void QCopy1(void* d, int n, const void* s)
{
    __int128 t;
    const void* ss = s;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu d, d, 0x10
        addi n, n, -1
        addiu ss, ss, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline void Vif_Put(unsigned int v)
{
    int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = v;
}
static inline void Vif_PutV(unsigned int v)
{
    unsigned int x = v;
    int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = x;
}
static inline void Vif_PadTo(unsigned int m)
{
    while (((unsigned int)D_005381C8 & 0xF) != m) {
        Vif_Put(0);
    }
}
extern char D_00537F80[];
extern char D_00538080[];
extern char D_0053B6A0[];
extern unsigned char D_0053B540;
void func_003820E0(void* m, int idx);
void func_0025CD10(void* s);
void func_0025CA40(void* s);
void func_00371200(void* s);
void Vec4_Copy(V* d, const V* s);
void func_0025C9D0(V* d, const V* s);
float func_0025F220(void);
V* func_00132000(V* o, float x, float y, float z, float w);
int Random_Next(void);
float func_0015C2B0(void* q);
float func_0015C2A0(void* q);
float func_0015C290(void* q);
float func_0015C280(void* q);
inline Mx::Mx(void* q) { float a = func_0015C2B0(q); float b = func_0015C2A0(q); float c = func_0015C290(q); float d = func_0015C280(q); Mtx_MakeAxisRotation(this, a, b, c, d); }

float func_00121B30(float a, float b);
int* func_00375BA0(void* p, int a, int b, int c, int d);
void func_00375AC0(void* p, int a, void* q);
void* func_003797D0(void* s);
int func_00398B00(void* a, int b);
long long* func_003BB620(int a);
long long* func_00379700(int a);
void func_001AE170(void* d, void* s, int n);
V* func_00398AE0(void* t, int i);
int func_003700D0(void* t, int i);
}
#define D_00539220 (D_00539210.f20)
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_0053922C (D_00539210.f2C)
#define D_00539230 (D_00539210.f30)
#define D_00539234 (D_00539210.f34)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define D_00539248 (D_00539210.f48)
#define D_005392D0 (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)
#define RS ((Rs*)D_005381F0)

static inline unsigned char Prim(void) { if (D_005392D0 & 1) return 3; return 2; }
static inline int Mode(void) { if (D_005392D0 & 1) return 0x41; return 0x62; }
static inline void Flush(void)
{
    Ent* e;
    D_00539238 = Prim();
    D_0053923C = Mode();
    D_00539228 = 0;
    D_0053923C &= ~1;
    e = &RS->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    func_0025CD10(D_005381F0);
    D_00539224 = 0;
}
static inline V* UVT1(float u, const V& uv) { V tmp; return func_00132000(&tmp, u, uv.y + func_0025F220(), uv.z, uv.w); }
static inline V* UVT0(float u, const V& uv) { return UVT1(u, uv); }
static inline V* UVT(float u, const V& uv) { return UVT0(u, uv); }
static inline V operator+(const V& a, const V& b) { return AddH(a, b); }
static inline void Emit(const V& pos, const V& col, const V& uv)
{
    Ent* e;
    float u;
    func_0025CA40(D_005381F0);
    e = &RS->ents[D_00539210.f10];
    Vec4_Copy(&e->pos[D_00539224 - 1], &pos);
    func_0025C9D0(&e->c30[D_00539224 - 1], &col);
    u = uv.x + func_0025F220();
    Vec4_Copy(&e->c34[D_00539224 - 1], UVT(u, uv));
    D_005381F8 = 6LL << 32;
}
static inline void EndStrip(void)
{
    if (D_00539220 > 0 && D_00539230 > 0) {
        int n = D_00539220 - 1;
        if (D_00539234 < 12) {
            Ent* e = &RS->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->strip[n].idx[D_00539234] = v;
            D_00539234++;
        } else {

            if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
            { int v; int j; Strip* s; v = D_00539238 - 1; s = ((Strip**)(D_005381F0 + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->idx[j] = v; }
            D_00539230 = 0;
            D_00539234 = 0;
            D_00539228++;
            D_00539220++;
        }
    }
}
#define DRAW(m, e, col) { \
    m.SetRot(Mx(e->q)); \
    m.t = e->pos; \
    Emit(Xform(m, e->v[0]) + e->pos, col, e->uv[0]); \
    Emit(Xform(m, e->v[1]) + e->pos, col, e->uv[1]); \
    Emit(Xform(m, e->v[2]) + e->pos, col, e->uv[2]); }
static inline int RandI(int lo, int hi)
{
    float m = 2147483648.0f;
    return (int)((float)lo + (float)(hi - lo) * ((float)Random_Next() / (1.0f + m)));
}

extern "C" void cParticleShatter_Render(Obj* o, float t, float a, float b, float c)
{
    if (OF_(o, 0x170, int) >= 0) {
        int sel;
        int cnt;
        int i;
        Mx m;
        func_003820E0(D_00539248, OF_(o, 0x170, int));
        { int mn = OF_(o, 0x160, int) >= OF_(o, 0x168, int) ? OF_(o, 0x168, int) : OF_(o, 0x160, int); }
        D_005392D0 = 5;
        D_005392D8 = D_004BC1B0[OF_(o, 0x120, Desc*)->type];
        static V col(1.0f, 1.0f, 1.0f, 1.0f);
        sel = RandI(0, OF_(o, 0x15C, int) - 1);
        cnt = 0;
        Flush();
        for (i = 0; i < OF_(o, 0x15C, int); i++) {
            Part* e = OF_(o, 0x124, Part*) + i;
            if (e->dead == 0 && i != sel) {
                DRAW(m, e, col)
                cnt++;
                EndStrip();
            }
        }
        if (cnt > 0) {
            func_00371200(D_005381F0);
            Flush();
        }
        {
        Part* e = OF_(o, 0x124, Part*) + sel;
        if (e->dead == 0) {
            D_005392D8 = D_004BC1B0[1];
            DRAW(m, e, col)
            func_00371200(D_005381F0);
        }
        }
        return;
    }
    if (o->n6C > 0) {
        float s, ds;
        float y = 0.0f;
        float z = y;
        float x;
        int i;
        Desc* d = OF_(o, 0x120, Desc*);
        x = t - o->f64;
        if (d->n > 0) {
            s = 30.0f * (x + (float)d->n * d->f40);
            ds = 30.0f * d->f40;
        } else {
            ds = y;
            s = 30.0f * x;
        }
        OF_(o, 0xAC, float) = a;
        OF_(o, 0xBC, float) = b;
        if (D_0053B540 == 0 || OF_(o, 0x120, Desc*)->f58 == 0) {
            OF_(OF_(o, 0x120, Desc*), 0x98C, float) = OF_(o, 0x120, Desc*)->f50 * c;
        } else {
            OF_(OF_(o, 0x120, Desc*), 0x98C, float) = OF_(o, 0x120, Desc*)->f54 * c;
        }
        for (i = 0; i < OF_(o, 0x120, Desc*)->n + 1; i++) {
            float r = func_00121B30(s, OF_(OF_(o, 0x120, Desc*), 0x9A8, float));
            float rm = r * OF_(OF_(o, 0x120, Desc*), 0x9AC, float);
            OF_(o, 0xC0, V) = V(x, s, y, z);
            OF_(OF_(o, 0x120, Desc*), 0x920, float) = r;
            OF_(OF_(o, 0x120, Desc*), 0x930, float) = rm;
            D_005381C8 = func_00375BA0(D_00537F80, 1, 1, 0, 0);
            Vif_PutV(0x11000000);
            Vif_Put(0);
            Vif_PadTo(0xC);
            Vif_Put(Unpack(0xF, 6));
            QCopy1(D_005381C8, 6, (char*)o + 0x90);
            D_005381C8 += 0x18;
            {
                char* sp2 = (char*)OF_(o, 0x120, Desc*) + 0x900;
                Vif_PadTo(0xC);
                Vif_Put(Unpack(0x15, 9));
                QCopy(sp2, D_005381C8, 9);
            }
            D_005381C8 += 0x24;
            Vif_PadTo(0);
            func_00375AC0(D_00537F80, 1, D_005381C8);
            {
                Desc* p = OF_(o, 0x120, Desc*);
                int base = o->f70;
                int left;
                int max;
                long long* pk;
                s -= ds;
                left = o->n6C;
                y += p->f44;
                z += p->f48;
                p->fB0 = *func_003BB620(func_00398B00(func_003797D0(D_005381F0), p->f74));
                p->fC0 = *func_00379700(func_00398B00(func_003797D0(D_005381F0), p->f74));
                max = 0x21;
                if (p->f64) {
                    p->fB8 = 0x15;
                    max = 0xE;
                    p->fC8 = 7;
                    p->fD0 = 1 | (0x612F4000LL << 32);
                    p->fD8 = 1 | (0x602F4000LL << 32);
                }
                pk = (long long*)func_00375BA0(D_00537F80, 1, 1, 0, 1);
                *pk = 0;
                pk++;
                while (left > 0) {
                    int n = left < max ? left : max;
                    p->f130 = (long long)n | (0x8000 | (0x602F4000LL << 32));
                    *pk = 0;
                    pk++;
                    *pk = 0x6C0D8000LL << 32;
                    pk++;
                    func_001AE170(pk, p->f80, 12);
                    pk += 0x18;
                    *(V*)pk = *func_00398AE0(D_0053B6A0, base + left);
                    pk += 2;
                    *pk = (unsigned int)func_003700D0(D_00538080, 0x17);
                    pk++;
                    left -= n;
                    *pk = 0;
                    pk++;
                }
                func_00375AC0(D_00537F80, 1, pk);
            }
        }
    }
}














