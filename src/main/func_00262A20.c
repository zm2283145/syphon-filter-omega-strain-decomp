#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

typedef struct V4_2A20 { float x, y, z, w; } V4_2A20;
typedef struct Mtx_2A20 { __int128 q[4]; } Mtx_2A20;
typedef struct Ent_2A20 {
    char pad[0x28];
    V4_2A20* pos;
    V4_2A20* c2C;
    V4_2A20* c30;
    V4_2A20* c34;
} Ent_2A20;
typedef struct Slot_2A20 {
    char pad[0x1F0];
    float r[4];
    char pad200[0x2E0 - 0x200];
    int f2E0;
    int pad2E4;
    float f2E8;
    char pad2EC[0x2F4 - 0x2EC];
    char f2F4;
    char f2F5;
    char f2F6;
} Slot_2A20;
typedef struct Rs_2A20 {
    char pad[0xA80];
    Mtx_2A20 mtx[1];
    char padAC0[0xFB0 - 0xAC0];
    Ent_2A20 ents[1];
} Rs_2A20;
typedef struct Arg_2A20 { int tex; float dx; float dy; float alpha; } Arg_2A20;

extern "C" {
typedef struct G_2A20 {
    int f10; int pad14[4]; int f24; int f28; int pad2C[3]; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_2A20;
extern G_2A20 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_2A20 D_00539170;
extern long long D_004BC1B0;
void Renderer_BindTexture(void* m, int idx);
void func_0025CD10(void* s);
void func_0025CA40(void* s);
void Vec4_Copy(V4_2A20* d, V4_2A20* s);
void GuiBatch_AddVertexColor(V4_2A20* d, V4_2A20* s);
float GuiBatch_AddVertexUV(void);
V4_2A20* Vec4_Set(V4_2A20* o, float x, float y, float z, float w);
void Renderer_FlushPrimitives(void* s);
}
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)
#define D_005392D8 (D_00539210.fD8)

#define RS_2A20 ((Rs_2A20*)g_Video)
#define SLOT_2A20(i) ((Slot_2A20*)(g_Video + (i) * 0x110))

static inline void UM_2A20(void* mm) { void* m = mm; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_2A20(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }


struct Part_2A20 { void* inst; char pad4[0xC]; Mtx_2A20 m; };
struct Node_2A20 { struct Node_2A20* prev; struct Node_2A20* next; char pad8[8]; Part_2A20 part; };
struct Head_2A20 { Node_2A20* prev; Node_2A20* next; };
struct Iter_2A20 { Node_2A20* n; Iter_2A20() {} Iter_2A20(const Iter_2A20& o) { n = o.n; } bool operator!=(const Iter_2A20& o) const { return n != o.n; } bool operator==(const Iter_2A20& o) const { return n == o.n; } };
struct Pt_2A20 { V4_2A20 pos; char pad10[0x20]; V4_2A20 col; };
struct Held_2A20 {
    char pad0[8];
    unsigned char state;
    char pad9[0x14 - 9];
    int count;
    Pt_2A20* pts;
    char pad1C[4];
    int list;
    Head_2A20 head;
    char pad2C[0xC0 - 0x2C];
    void* inst;
};
extern "C" {
Head_2A20* func_00262D80(Head_2A20* h);
Node_2A20* func_00262D70(int* l);
void func_00262D60(Iter_2A20* it, Node_2A20* n);
void ParticleInst_Draw(void* inst, int key, Mtx_2A20* m);
void func_003701B0(void* s);
void func_00262A20(Held_2A20* self);
}
static inline unsigned char Prim_2A20(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_2A20(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Emit_2A20(V4_2A20* pos, V4_2A20* col)
{
    Ent_2A20* e;
    func_0025CA40(g_Video);
    e = &RS_2A20->ents[D_00539210.f10];
    Vec4_Copy(&e->pos[D_00539224 - 1], pos);
    GuiBatch_AddVertexColor(&e->c30[D_00539224 - 1], col);
    D_005381F8 = 2LL << 32;
}
static inline Iter_2A20 Begin0_2A20(Head_2A20* h) { Iter_2A20 t; t.n = func_00262D80(h)->next; return t; }
static inline Iter_2A20 Begin_2A20(Head_2A20* h) { return Begin0_2A20(h); }
static inline Iter_2A20 End_2A20(int* l) { Iter_2A20 e; func_00262D60(&e, func_00262D70(l)); return e; }

/* func_00262A20: draws the taser wire: a line strip through the held item's
 * points, then the spark particles (on each list entry's matrix while
 * attached, or once at the last point while flying). Render state as in
 * VisionFx_DrawScanBand (VisionFx_DrawScanBand.c); item layout as in
 * HeldItem_Release (taser/HeldItem_Release.c). */
extern "C" void func_00262A20(Held_2A20* self)
{
    int n;
    int saved;
    int i;
    if (!self->state)
        return;
    n = self->count;
    if (n <= 1)
        return;
    saved = g_DrawMode;
    g_DrawMode = 0x200;
    D_005392D8 = D_004BC1B0;
    D_00539238 = Prim_2A20();
    D_0053923C = Mode_2A20();
    D_00539228 = 0;
    D_0053923C &= ~1;
    {
        Ent_2A20* e = &RS_2A20->ents[D_00539210.f10];
        e->pos += D_00539224;
        e->c2C += D_00539224;
        e->c30 += D_00539224;
        e->c34 += D_00539224;
    }
    func_0025CD10(g_Video);
    D_00539224 = 0;
    for (i = 0; i < n; i++) {
        Pt_2A20* p = &self->pts[i];
        V4_2A20* col = &p->col;
        Emit_2A20(&p->pos, col);
    }
    func_003701B0(g_Video);
    g_DrawMode = saved;
    if (self->state == 2) {
        Iter_2A20 it = Begin_2A20(&self->head);
        while (it != End_2A20(&self->list)) {
            Part_2A20* pp = &it.n->part;
            ParticleInst_Draw(pp->inst, 2, &pp->m);
            it.n = it.n->next;
        }
    } else if (self->state == 1) {
        Mtx_2A20 m;
        UM_2A20(&m);
        { __int128* d = &m.q[3]; Pt_2A20** pp = &self->pts; *d = *(__int128*)&(*pp)[n - 1].pos; }
        ParticleInst_Draw(self->inst, 2, &m);
    }
}
