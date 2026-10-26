#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"
/* Bullet_InitFromRequest: fills a pooled bullet from a fire request (frame,
 * owner/target handles, hit triangle copy, type), creates its tracer when the
 * type has one, and builds the two streak side vectors from the bullet's
 * forward axis. Request layout as in BulletPool_Request (BulletPool_Request.c). */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx { VP r[4]; Mtx& operator=(const Mtx& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; } };
struct Sub40 { char b[0x10]; };
struct Sub60 { char b[0x10]; };
struct Tracked { char pad[0xC]; int serial; };
struct TrCopy {
    VP v[4];
    Sub40 s40;
    unsigned char b50, b51, b52; char p53[0xD];
    Sub60 s60;
};
struct Type { char pad[0xF8]; int fxF8; char padFC[0x134 - 0xFC]; int tracer; };
struct Req {
    Mtx m;
    float f40;
    Tracked* f44;
    Tracked* f48;
    Tracked* f4C;
    TrCopy tr;
    VP hit;
    int fD0;
    unsigned char fD4, fD5, fD6;
    float fD8;
    Type* fDC;
    int fE0;
    float fE4;
};
struct H { Tracked* p; int serial; };
struct Bullet {
    float age;
    float speed;
    float range;
    int id;
    int fx;
    char pad14[0xC];
    Mtx m;
    H h60;
    H h68;
    H h70;
    char pad78[4];
    int count;
    char pad80[0x10];
    TrCopy tr;
    V hit;
    void* emitter;
    unsigned char b114, b115, active, b117, b118, b119;
    char pad11A[2];
    int tex;
    V side0;
    V side1;
    int uv;
    float len;
    Type* type;
};
extern "C" {
extern char D_004A91A0[];
extern int D_00504038;
void* Mem_Alloc(int pool, int size, char* file, int line);
void* Tracer_Create(void* p, int id, Mtx* m, float scale);
int* SpecFx_GetEffectDef(int id);
void Vec4_Copy(void* d, const void* s);
void func_00139BB0(void* d, const void* s);
void func_00139BA0(void* d, const void* s);
void Bullet_InitFromRequest(Bullet* b, Req* r);
}
static inline const int& IdOf(Tracked* p) { if (p) return p->serial; int m = -1; return m; }
static inline void SetH(H* h, Tracked* p) { h->p = p; h->serial = IdOf(p); }
static inline void Crs(V* d, const V* l, const V* r) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory"); }
static inline V Cross(const V& a, const V& b) { V r; Crs(&r, &a, &b); return r; }
static inline void* NewTracer(int line)
{
    void* p;
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x70, D_004A91A0, line);
    }
    return p;
}

void Bullet_InitFromRequest(Bullet* b, Req* r)
{
    b->m = r->m;
    b->speed = r->f40;
    SetH(&b->h60, r->f48);
    SetH(&b->h68, r->f44);
    b->b114 = r->fD4;
    b->b118 = r->fD5;
    b->id = r->fD0;
    b->active = 1;
    b->b115 = 1;
    SetH(&b->h70, r->f4C);
    Vec4_Copy(&b->tr.v[0], &r->tr.v[0]);
    Vec4_Copy(&b->tr.v[1], &r->tr.v[1]);
    Vec4_Copy(&b->tr.v[2], &r->tr.v[2]);
    Vec4_Copy(&b->tr.v[3], &r->tr.v[3]);
    b->tr.b50 = r->tr.b50;
    func_00139BB0(&b->tr.s40, &r->tr.s40);
    func_00139BA0(&b->tr.s60, &r->tr.s60);
    b->tr.b51 = r->tr.b51;
    b->tr.b52 = r->tr.b52;
    b->hit = *(V*)&r->hit;
    b->b117 = r->fD6;
    b->type = r->fDC;
    b->range = r->fD8;
    b->age = 0.0f;
    b->fx = b->type->fxF8;
    b->b119 = 1;
    b->count = 0;
    if (b->type->tracer > -1) {
        void* p = NewTracer(0xE0);
        if (p) p = Tracer_Create(p, b->type->tracer, &b->m, r->fE4);
        b->emitter = p;
    } else {
        b->emitter = 0;
    }
    b->tex = *SpecFx_GetEffectDef(26);
    {
        V fwd = *(V*)&b->m.r[1];
        b->side0 = Cross(fwd, V(0.0f, 0.0f, 1.0f, 0.0f));
        b->side1 = Cross(fwd, b->side0);
    }
    b->uv = D_00504038;
    b->len = 8.0f;
    D_00504038 += 4;
    if (D_00504038 == 16)
        D_00504038 = 0;
}
