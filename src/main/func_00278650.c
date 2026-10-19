#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V(const V* p, int) { V* dd = this; const V* ss = p; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q), "+r"(dd) : "r"(ss) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VX : V { VX(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; } };
typedef struct Mtx { __int128 q[4]; } Mtx;
typedef struct Strip { char pad[0x80]; int idx[12]; char padB0[0x10]; } Strip;
typedef struct Ent {
    char pad[0x24];
    Strip* c24;
    V* pos;
    V* c2C;
    V* c30;
    V* c34;
} Ent;
typedef struct Rs {
    char pad[0xA80];
    Mtx mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent ents[1];
} Rs;
struct Mdl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void Update();
    char pad4[0xC]; Mtx m; unsigned char f50;
};
typedef struct Obj { char pad[0x50]; Mdl* mdl; } Obj;
typedef struct Item { int flags; char pad4[0xC]; Mtx m; float r; int tex; Obj* obj; float fade; } Item;
typedef struct Arg { Item** items; char pad4[0xC]; int count; } Arg;

extern "C" {
typedef struct G {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C64;
extern char D_00538C68;
extern long long D_004BC1B0[];
void Renderer_BindTexture(void* m, int idx);
void func_0025CD10(void* s);
void func_0025CA40(void* s);
void Renderer_FlushBatch(void* s);
void Vec4_Copy(V* d, const V* s);
void GuiBatch_AddVertexColor(V* d, const V* s);
float GuiBatch_AddVertexUV(void);
V* Vec4_Set(V* o, float x, float y, float z, float w);
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

#define RS ((Rs*)g_Video)

static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void MulM(void* d, const void* m) { __asm__ volatile("lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(m) : "memory"); }
static inline void Xform(V* d, const Mtx* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m) : "memory"); }
static inline V operator*(const Mtx& m, const V& v) { V t = v; const V* pt = &t; Xform((V*)pt, &m); return V(pt, 0); }
static inline void MulV(V* d, const Mtx& m, const V& v) { V t = v; const V* pt = &t; Xform((V*)pt, &m); { V* dd = d; const V* ss = pt; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q), "+r"(dd) : "r"(ss) : "memory"); } }

static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Begin(void)
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
    func_0025CD10(g_Video);
    D_00539224 = 0;
}
static inline void Emit(const V& pos, const V& col, const V& uv)
{
    V tmp;
    Ent* e;
    float u;
    func_0025CA40(g_Video);
    e = &RS->ents[D_00539210.f10];
    Vec4_Copy(&e->pos[D_00539224 - 1], &pos);
    GuiBatch_AddVertexColor(&e->c30[D_00539224 - 1], &col);
    u = uv.x + GuiBatch_AddVertexUV();
    Vec4_Copy(&e->c34[D_00539224 - 1], Vec4_Set(&tmp, u, uv.y + GuiBatch_AddVertexUV(), uv.z, uv.w));
    D_005381F8 = 6LL << 32;
}
static inline bool EndStrip(void)
{
    if (D_00539220 > 0 && D_00539230 > 0) {
        int n = D_00539220 - 1;
        if (D_00539234 < 12) {
            Ent* e = &RS->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->c24[n].idx[D_00539234] = v;
            D_00539234++;
        } else {

            if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
            { int v; int j; Strip** pc; Strip* s; v = D_00539238 - 1; s = ((Strip**)(g_Video + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->idx[j] = v; }
            D_00539230 = 0;
            D_00539234 = 0;
            D_00539228++;
            D_00539220++;
        }
    }
    return true;
}

extern "C" void DecalMgr_Draw(Arg* a)
{
    int saved;
    int tex;
    int blend;
    Obj* obj;
    int i;
    bool first;
    V col;
    saved = g_DrawMode;
    g_DrawMode = 0x400005;
    Begin();
    tex = -1;
    first = true;
    obj = 0;
    blend = tex;
    col.x = 1.0f;
    i = 0;
    col.y = 1.0f;
    col.z = 1.0f;
    col.w = 1.0f;
    for (; i < a->count; i++) {
        Item* it = a->items[i];
        float alpha;
        int b;
        if (it->fade == -2.0f) continue;
        alpha = 1.0f;
        if (!(it->fade < 0.0f)) {
            alpha = 1.0f - it->fade / 2.0f;
            if (alpha <= 0.0f) it->fade = -2.0f;
        }
        col.w = alpha;
        if (alpha <= 0.0f) continue;
        if (it->flags & 8) b = 3;
        else if (it->flags & 4) b = 0;
        else if (it->flags & 0x10) b = 2;
        else b = 3;
        {
            bool c3 = true;
            bool c2 = true;
            bool c1 = true;
            if (!first && tex == it->tex) c1 = 0;
            if (!c1 && b == blend) c2 = 0;
            if (!c2 && it->obj == obj) c3 = 0;
            if (c3 != false) {
                Renderer_FlushBatch(g_Video);
                Begin();
                if (tex != it->tex) {
                    tex = it->tex;
                    Renderer_BindTexture(g_TextureMgr, tex);
                }
                if (b != blend) {
                    blend = b;
                    D_005392D8 = D_004BC1B0[b];
                }
                if (it->obj != obj) {
                    if (obj) {
                        D_00538C64--;
                        D_00538C68 = 1;
                    }
                    obj = it->obj;
                    if (obj) {
                        Mdl* m;
                        QR(&RS->mtx[D_00538C64 + 1], &RS->mtx[D_00538C64]);
                        D_00538C64++;
                        m = obj->mdl;
                        if (m->f50) m->Update();
                        MulM(&RS->mtx[D_00538C64], &m->m);
                        D_00538C68 = 1;
                    }
                }
            }
        }
        {
            float r = it->r;
            const Mtx* m = &it->m;
            V c0; MulV(&c0, *m, V(-r, 0.0f, -r, 1.0f));
            V c1; MulV(&c1, *m, V(-r, 0.0f, r, 1.0f));
            V c2; MulV(&c2, *m, V(r, 0.0f, -r, 1.0f));
            V c3; MulV(&c3, *m, V(r, 0.0f, r, 1.0f));
            Emit(c0, col, VX(0.0f, 1.0f, 1.0f, 0.0f));
            Emit(c1, col, V(0.0f, 0.0f, 1.0f, 0.0f));
            Emit(c2, col, V(1.0f, 1.0f, 1.0f, 0.0f));
            Emit(c3, col, V(1.0f, 0.0f, 1.0f, 0.0f));
        }
        first = !EndStrip();
    }
    Renderer_FlushBatch(g_Video);
    if (obj) {
        D_00538C64--;
        D_00538C68 = 1;
    }
    g_DrawMode = saved;
    D_005392D8 = D_004BC1B0[0];
}
