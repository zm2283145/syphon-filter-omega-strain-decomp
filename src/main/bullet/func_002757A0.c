/* func_002757A0 (BulletPool bullet draw) - mw38 MATCH. First OpM site (b->dir * b->len) uses a
   per-site gcc-style helper (OpM2) whose asm operand order (pa, pr, s) fixes src/dst colouring. */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& s) { void* d = this; __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(&s) : "memory"); }
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
static inline void OpS(V4* pr, const V4* pa, const V4* pb)
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
static inline void OpM2(V4* pr, const V4* pa, float s) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pa), "r"(pr), "f"(s) : "memory"); }
static inline V4 Mul2(const V4& a, float s) { V4 r; OpM2(&r, &a, s); return r; }
static inline V4 operator-(const V4& a, const V4& b)
{
    V4 r;
    OpS(&r, &a, &b);
    return r;
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
static inline V4 operator+(const V4& a, const V4& b)
{
    V4 r;
    OpA(&r, &a, &b);
    return r;
}

typedef struct Rec_002757A0 { char pad[0x80]; int v[12]; char pad2[0xC0 - 0xB0]; } Rec_002757A0;
typedef struct Ent_002757A0 {
    char pad[0x24];
    Rec_002757A0* recs;
    V4* pos;
    V4* c2C;
    V4* c30;
    V4* c34;
} Ent_002757A0;
typedef struct EntB_002757A0 { char pad[0x34]; Rec_002757A0* recs; } EntB_002757A0;
typedef struct S_002757A0 { char pad[0xFA0]; EntB_002757A0 ent[1]; } S_002757A0;
typedef struct Rs_002757A0 {
    char pad[0xFB0];
    Ent_002757A0 ents[1];
} Rs_002757A0;
typedef struct Bullet_002757A0 {
    char pad0[0x20];
    char f20[0x10];
    V4 dir;
    char pad40[0x10];
    V4 pos;
    char pad60[0x110 - 0x60];
    int f110;
    char pad114;
    unsigned char f115;
    unsigned char f116;
    char pad117[0x11C - 0x117];
    int tex;
    V4 side0;
    V4 side1;
    int uv;
    float len;
} Bullet_002757A0;

extern "C" {
typedef struct G_002757A0 {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_002757A0;
extern G_002757A0 D_00539210;
extern char D_005381F0[];
extern long long D_005381F8;
extern V4 D_004A90A0[];
void func_003A1AD0(int h, int k, void* p);
void func_003820E0(void* m, int idx);
void func_0025CD10(void* s);
void func_0025CA40(void* s);
void Vec4_Copy(V4* d, const V4* s);
void func_0025C9D0(V4* d, const V4* s);
float func_0025F220(void);
V4* func_00132000(V4* o, float x, float y, float z, float w);
void func_00371200(void* s);
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

#define RS_002757A0 ((Rs_002757A0*)D_005381F0)

struct V4c_002757A0 {
    float x, y, z, w;
    V4c_002757A0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
static inline V4* UV_002757A0(const V4& uv)
{
    V4 tmp;
    float u = uv.x + func_0025F220();
    return func_00132000(&tmp, u, uv.y + func_0025F220(), uv.z, uv.w);
}
static inline void Emit_002757A0(const V4& pos, const V4c_002757A0& col, const V4& uv)
{
    Ent_002757A0* e;
    func_0025CA40(D_005381F0);
    e = &RS_002757A0->ents[D_00539210.f10];
    Vec4_Copy(&e->pos[D_00539224 - 1], &pos);
    func_0025C9D0(&e->c30[D_00539224 - 1], (V4*)&col);
    Vec4_Copy(&e->c34[D_00539224 - 1], UV_002757A0(uv));
    D_005381F8 = 6LL << 32;
}
static inline unsigned char Prim_002757A0(void) { if (D_005392D0 & 1) return 3; return 2; }
static inline int Mode_002757A0(void) { if (D_005392D0 & 1) return 0x41; return 0x62; }

static inline void Restart_002757A0(void)
{
    if (D_00539220 > 0) {
        if (D_00539230 > 0) {
            int k = D_00539220 - 1;
            if (D_00539234 < 12) {
                Ent_002757A0* e = &RS_002757A0->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->recs[k].v[D_00539234] = v;
                D_00539234++;
            } else {
                if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
                { int v; int j; Rec_002757A0* s; v = D_00539238 - 1; s = ((Rec_002757A0**)(D_005381F0 + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->v[j] = v; }
                D_00539230 = 0;
                D_00539234 = 0;
                D_00539228++;
                D_00539220++;
            }
        }
    }
}

extern "C" void func_002757A0(Bullet_002757A0* b)
{
    if (b->f115 && b->f110) func_003A1AD0(b->f110, 2, b->f20);
    if (b->f116 && b->f110 == 0) {
        V4* pos = &b->pos;
        V4 tail = *pos - Mul2(b->dir, b->len);
        __int128 z0 = 0;
        V4 u = b->side0 * 0.3f;
        __int128 z1 = 0;
        V4 w = b->side1 * 0.3f;
        V4 p0 = *pos + u;
        V4 p1 = *pos - u;
        V4 p2 = tail + u;
        V4 p3 = tail - u;
        V4 p4 = *pos + w;
        V4 p5 = *pos - w;
        V4 p6 = tail + w;
        V4 p7 = tail - w;
        V4c_002757A0 c1(1.0f, 1.0f, 1.0f, 1.0f);
        V4c_002757A0 c2(1.0f, 1.0f, 1.0f, 0.5f);
        Ent_002757A0* e;
        int saved = D_005392D0;
        D_005392D0 = 5;
        func_003820E0(D_00539248, b->tex);
        D_00539238 = Prim_002757A0();
        D_0053923C = Mode_002757A0();
        D_00539228 = 0;
        D_0053923C &= ~1;
        e = &RS_002757A0->ents[D_00539210.f10];
        e->pos += D_00539224;
        e->c2C += D_00539224;
        e->c30 += D_00539224;
        e->c34 += D_00539224;
        func_0025CD10(D_005381F0);
        D_00539224 = 0;
        Emit_002757A0(p0, c1, D_004A90A0[b->uv]);
        Emit_002757A0(p1, c1, D_004A90A0[b->uv + 1]);
        Emit_002757A0(p2, c2, D_004A90A0[b->uv + 2]);
        Emit_002757A0(p3, c2, D_004A90A0[b->uv + 3]);
        Restart_002757A0();
        Emit_002757A0(p4, c1, D_004A90A0[b->uv]);
        Emit_002757A0(p5, c1, D_004A90A0[b->uv + 1]);
        Emit_002757A0(p6, c2, D_004A90A0[b->uv + 2]);
        Emit_002757A0(p7, c2, D_004A90A0[b->uv + 3]);
        func_00371200(D_005381F0);
        D_005392D0 = saved;
    }
}
