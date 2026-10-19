/*
 * main/particle: range (6 files, 003A1450-003A1AD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A1450 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

union Key {
    __int128 q;
    unsigned long long d[2];
};

struct Entry {
    Key key;
    unsigned int num;
    float times[0x23];
    char extra[0xE0 - 0xA0];
};

struct Def {
    char pad[0x170];
    Key key;
    int count;
    char pad184[0xC];
    Entry entries[1];
};

struct Self {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Def* GetDef();
    char pad[0x60];
    float f64;
    char pad68[0x10];
    unsigned char idx[8];
    int mask;
};

extern char D_0053B540[];
extern "C" {
int ParticleDefs_FindByName(void*, void*);
Self* ParticleEmitter_SpawnChildren(float, int, Self*, int, void*);
}

/* Fires each pending timed entry whose next time has been reached, marking linked peers. */
extern "C" void ParticleEmitter_SpawnChild(Self* self, float t, int arg)
{
    int k = 0;
    int i;
    for (i = 0; i < self->GetDef()->count; k++, i++) {
        int bit = 1 << k;
        if (!(self->mask & bit) && self->GetDef()->entries[i].num != 0) {
            float tm = self->GetDef()->entries[i].times[self->idx[i]];
            if (tm >= 0.0f) {
                while (t >= tm) {
                    int r = ParticleDefs_FindByName(D_0053B540, &self->GetDef()->entries[i]);
                    Self* o = ParticleEmitter_SpawnChildren(tm + self->f64, arg, self, r, self->GetDef()->entries[i].extra);
                    if (o && self->GetDef() == o->GetDef()) {
                        int j;
                        for (j = 0; j < self->GetDef()->count; j++) {
                            if ((unsigned long long)self->GetDef()->key.q == (unsigned long long)self->GetDef()->entries[j].key.q &&
                                self->GetDef()->key.d[1] == self->GetDef()->entries[j].key.d[1])
                                o->mask |= 1 << j;
                        }
                    }
                    self->idx[i]++;
                    if (self->idx[i] >= self->GetDef()->entries[i].num) {
                        self->mask |= bit;
                        break;
                    }
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A1450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A1450 */

/* merge_units: begin func_003A1760 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline __int128 LQ(const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); return t; }
static inline void SQ(void* d, __int128 t) { __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Def_003A1760 {
    char pad[0x140];
    float s[3];
    char pad14C[0x8F0 - 0x14C];
    int w8F0;
};
struct Self_003A1760 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Def_003A1760* GetDef();
    char pad[0x4C];
    V4 col;
    char pad60[4];
    float f64;
    float f68;
    char pad6C[0x18];
    unsigned char b84;
};
struct Src { char pad[0x30]; V4 pos; };
extern "C" V4 D_00535D40;
extern "C" unsigned char D_00535D60;
extern "C" unsigned char D_00535D61;
extern "C" char g_LightMgr[];
extern "C" V4 D_00537D80;
#if 0 /* merge_units */
extern "C" void ParticleEmitter_SpawnChild(Self_003A1760* self, float t, int arg);
#endif /* merge_units */
#define ParticleEmitter_SpawnChild(a0, a1, a2) (ParticleEmitter_SpawnChild((Self *)(a0), (a1), (a2))) /* merge_units */

extern "C" void LightMgr_GatherModelLights(void* m, unsigned int mask, unsigned int flags, void* out);

static inline int Vec4_Equal_(V4* a, V4* b) {
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline bool Neq(V4* a, V4* b) { return !Vec4_Equal_(a, b); }

extern "C" void ParticleEmitterBase_Update(Self_003A1760* self, float t, int arg, Src* src)
{
    ParticleEmitter_SpawnChild(self, t - self->f64, arg);
    if (self->GetDef()->w8F0 && !(t - self->f68 <= 0.25f)) {
        V4* p = &src->pos;
        if (Neq(&D_00535D40, p)) {
            V4* d = &D_00535D40;
            QC(d, p);
            D_00535D60 = 1;
            D_00535D61 = 1;
        }
        LightMgr_GatherModelLights(g_LightMgr, 0x16, 1, 0);
        void* xx = &self->col; /* dead on purpose: retail keeps this addiu */
        SQ(&self->col, LQ(&D_00537D80)); /* split lq/sq: retail interleaves the address setup */
        self->col.x = 0.0078125f * (self->col.x * self->GetDef()->s[0]);
        self->col.y = 0.0078125f * (self->col.y * self->GetDef()->s[1]);
        self->col.z = 0.0078125f * (self->col.z * self->GetDef()->s[2]);
        self->f68 = t;
    }
    self->b84 = 1;
}
#undef ParticleEmitter_SpawnChild /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A1760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A1760 */

/* merge_units: begin func_003A1930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(func_003A1930, D_004DFB50, D_004DFAD8)
#pragma pop /* merge_units */
/* merge_units: end func_003A1930 */

/* merge_units: begin func_003A1990 */
#pragma push /* merge_units */
extern char D_004DFAD8[];
extern char D_004DFB50[];
extern struct { int n; float v[0x103]; } D_0053B6A0;

typedef struct {
    char pad0[0xC];
    int xC;
    float x10;
    char pad14[0x180 - 0x14];
    int x180;
} Info3A1990;

typedef struct {
    void* vt;
    char pad4[8];
    unsigned char xC;
    char padD[0x60 - 0xD];
    int x60;
    float x64;
    float x68;
    int x6C;
    int x70;
    int x74;
    unsigned char x78[8];
    int x80;
    unsigned char x84;
} Self3A1990;

Self3A1990* ParticleEmitterBase_Construct(Self3A1990* self, int a, Info3A1990* info, float f)
{
    int i;
    self->vt = D_004DFAD8;
    self->vt = D_004DFB50;
    self->xC = 0;
    self->x60 = 0;
    self->x64 = f;
    self->x80 = 0;
    self->x84 = 0;
    self->x74 = a;
    for (i = 0; i < info->x180; i++) {
        self->x78[i] = 0;
    }
    self->x70 = ++D_0053B6A0.n;
    self->x6C = info->xC + (int)(0.5f + info->x10 * ((float*)&D_0053B6A0)[(unsigned char)self->x70 + 4]);
    self->x68 = f - 0.25f - 1.0f;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A1990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A1990 */

/* merge_units: begin func_003A1A80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(func_003A1A80, D_004DFAD8)
#pragma pop /* merge_units */
/* merge_units: end func_003A1A80 */

/* merge_units: begin func_003A1AD0 */
#pragma push /* merge_units */
#pragma opt_rotateloops off
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; Q1(this, &o); }
    V& operator=(const V& o) { void* xx = this; Q1(this, &o); return *this; }
} __attribute__((aligned(16)));
struct M { __int128 q[4]; };
static inline void MulBy(void* d, const void* b) { __asm__ volatile("lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(b) : "memory"); }
static inline void Apply(V* p, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%1); lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%1)" : : "r"(m), "r"(p) : "memory"); }
struct Slot { char pad[0x110]; };
struct SlotX { char pad[0x2F6]; char f2F6; };
struct Rs { char pad[0xA80]; M mtx[1]; };
struct Def_003A1AD0 { char pad[0x64]; unsigned char b64; char pad65[0x74 - 0x65]; int f74; };
struct Nd;
struct NdB {
    virtual void v0();
    virtual void Draw(float, float, float, int, float);
    virtual void v2();
    virtual Def_003A1AD0* GetDef();
    virtual void v4();
    virtual M* GetM();
};
struct Nd : NdB {
    Nd* next; char pad8[4]; unsigned char bC;
    char padD[0x6C - 0xD]; int f6C; char pad70[4]; int f74;
    char pad78[0x84 - 0x78]; unsigned char b84;
    char pad85[0x170 - 0x85]; int f170;
};
struct Ids { char pad[0x16]; char b16; char pad17; unsigned int cnt; short ids[1]; };
struct Obj { char pad[8]; Nd* first; char padC[4]; Nd end; };
struct Obj2 { char pad[0x1C]; int f1C; char pad20[0x50 - 0x20]; float f50; float f54; float f58; float f5C; };
extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int D_005381C4;
extern int D_00538144;
extern int D_00538170;
extern int D_004932C0[];
extern int D_004932E0[];
extern char D_00537F80[];
extern float D_00538258[];
extern float D_00538268[];
extern int D_00538278;
extern signed char D_0053BAC0;
extern V D_0053BAD0;
extern signed char D_0053BAE0;
extern V D_0053BAF0;
extern V D_005381D0;
extern M D_005390F0;
extern float D_00538380;
extern float D_00538370;
extern Ids* g_TextureMgr;
void func_00375A30(void* a, int b, int c, int d);
void Renderer_UpdateCameraMatrices(void* r);
void Renderer_SetDrawState(void* r, M* m, int a, int f);
void func_00382910(Ids* p);
}
#define RS ((Rs*)g_Video)
#define SLOT(i) ((SlotX*)((Slot*)g_Video + (i)))
static inline void AddId(Ids* l, int id)
{
    if (l->cnt < 0x200 && (l->cnt == 0 || l->ids[l->cnt - 1] != id))
        l->ids[l->cnt++] = id;
}
static inline void Push(void)
{
    QR(&RS->mtx[D_00538C64 + 1], &RS->mtx[D_00538C64]);
    D_00538C64++;
}
static inline void Pop(void)
{
    D_00538C64--;
    D_00538C68 = 1;
}
static inline void PushMul(M* m)
{
    Push();
    MulBy(&RS->mtx[D_00538C64], m);
    D_00538C68 = 1;
}
extern "C" void ParticleInst_Draw(Obj2* o, int flags, M* mtx)
{
    Obj* self = (Obj*)o;
    if (flags == 0x80) return;
    if (!o->f1C) return;
    D_005381C4 = 0;
    int s = D_00538144;
    if (s != D_00538170) {
        func_00375A30(D_00537F80, 1, D_004932C0[s], D_004932E0[s]);
        D_00538170 = s;
    }
    D_005381C4++;
    D_00538278++;
    D_00538258[D_00538278] = 2.0f;
    D_00538268[D_00538278] = 3.0f;
    SlotX* sp = SLOT(D_00538C60); sp->f2F6 = 1;
    PushMul(mtx);
    float a = 255.0f;
    if (flags & 0x10) {
        if (!D_0053BAC0) {
            D_0053BAC0 = 1;
            D_0053BAD0.x = 0.0f; D_0053BAD0.y = 0.0f; D_0053BAD0.z = 0.0f; D_0053BAD0.w = 1.0f;
        }
        Renderer_UpdateCameraMatrices(g_Video);
        V q;
        V p = D_0053BAD0;
        M* mm = &D_005390F0;
        V* pp = &p;
        Apply(pp, mm);
        q = *pp;
        a = D_00538370 + D_00538380 / q.w;
        a = (a > 0.0f) ? a : 0.0f;
        a = (a < 255.0f) ? a : 255.0f;
    }
    Nd* n = self->first;
    Ids* l = g_TextureMgr;
    l->cnt = 0;
    l->b16 = 0;
    for (; n != &self->end; n = n->next) {
        AddId(g_TextureMgr, n->GetDef()->f74);
        if (n->bC) { int id = n->f170; if (id >= 0) AddId(g_TextureMgr, id); }
    }
    func_00382910(g_TextureMgr);
    n = self->first;
    if (!D_0053BAE0) {
        D_0053BAE0 = 1;
        D_0053BAF0.x = 0.0f; D_0053BAF0.y = 0.0f; D_0053BAF0.z = 0.0f; D_0053BAF0.w = 0.0f;
    }
    D_005381D0 = D_0053BAF0;
    int st = 0x100005;
    if (n->GetDef()->b64) st |= 0x2000;
    Renderer_SetDrawState(g_Video, mtx, 2, st);
    M* cur = 0;
    while (n != &self->end) {
        if (!n->b84 || !n->f6C) { n = n->next; continue; }
        bool chg = 0;
        bool dirty = 0;
        if (n->GetM()) {
            cur = n->GetM();
            chg = 1;
        } else if (cur && !n->f74) {
            cur = 0;
            chg = 1;
        }
        if (chg) {
            if (cur) {
                Pop();
                PushMul(cur);
            } else {
                Pop();
                PushMul(mtx);
            }
            dirty = 1;
        }
        if (n->GetDef()->b64 && !(st & 0x2000)) {
            st |= 0x2000;
            dirty = 1;
        } else if (!n->GetDef()->b64 && (st & 0x2000)) {
            dirty = 1;
            st &= ~0x2000;
        }
        if (dirty) {
            if (cur)
                Renderer_SetDrawState(g_Video, cur, 2, st);
            else
                Renderer_SetDrawState(g_Video, mtx, 2, st);
        }
        n->Draw(o->f50, a, o->f54, 2, o->f5C);
        n = n->next;
    }
    Pop();
    D_00538278--;
    SLOT(D_00538C60)->f2F6 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A1AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A1AD0 */
