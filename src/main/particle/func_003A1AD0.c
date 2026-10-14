#pragma opt_rotateloops off
#pragma cplusplus on
#include "types.h"
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
struct Def { char pad[0x64]; unsigned char b64; char pad65[0x74 - 0x65]; int f74; };
struct Nd;
struct NdB {
    virtual void v0();
    virtual void Draw(float, float, float, int, float);
    virtual void v2();
    virtual Def* GetDef();
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
extern char D_005381F0[];
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
extern Ids* D_00539248;
void func_00375A30(void* a, int b, int c, int d);
void Renderer_UpdateCameraMatrices(void* r);
void Renderer_SetDrawState(void* r, M* m, int a, int f);
void func_00382910(Ids* p);
}
#define RS ((Rs*)D_005381F0)
#define SLOT(i) ((SlotX*)((Slot*)D_005381F0 + (i)))
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
extern "C" void func_003A1AD0(Obj2* o, int flags, M* mtx)
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
        Renderer_UpdateCameraMatrices(D_005381F0);
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
    Ids* l = D_00539248;
    l->cnt = 0;
    l->b16 = 0;
    for (; n != &self->end; n = n->next) {
        AddId(D_00539248, n->GetDef()->f74);
        if (n->bC) { int id = n->f170; if (id >= 0) AddId(D_00539248, id); }
    }
    func_00382910(D_00539248);
    n = self->first;
    if (!D_0053BAE0) {
        D_0053BAE0 = 1;
        D_0053BAF0.x = 0.0f; D_0053BAF0.y = 0.0f; D_0053BAF0.z = 0.0f; D_0053BAF0.w = 0.0f;
    }
    D_005381D0 = D_0053BAF0;
    int st = 0x100005;
    if (n->GetDef()->b64) st |= 0x2000;
    Renderer_SetDrawState(D_005381F0, mtx, 2, st);
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
                Renderer_SetDrawState(D_005381F0, cur, 2, st);
            else
                Renderer_SetDrawState(D_005381F0, mtx, 2, st);
        }
        n->Draw(o->f50, a, o->f54, 2, o->f5C);
        n = n->next;
    }
    Pop();
    D_00538278--;
    SLOT(D_00538C60)->f2F6 = 1;
}
