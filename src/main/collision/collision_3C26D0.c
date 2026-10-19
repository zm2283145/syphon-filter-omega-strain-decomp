/*
 * main/collision: range (3 files, 003C26D0-003C2DE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003C26D0 */
#pragma push /* merge_units */
/* Los_TraceImmediate */
#pragma opt_propagation off
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x60]; } __attribute__((aligned(16))) Bnd26;
typedef struct {
    V4 v[3];
    V4 n;
    char part40[0x10];
    unsigned char flag50;
    unsigned char flag51;
    unsigned char flag52;
    char pad53[0xD];
    int part60[4];
} Tri26;
typedef struct {
    unsigned char hit;
    V4 a;
    V4 b;
    char part30[0x10];
    V4 to;
    V4 from;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
    void* p64;
} Q26;
extern int D_00542CC8;
extern int D_00542D38;
extern int D_00542D48;
extern int D_00542D1C;
extern int D_004937C0[];
extern int D_004937D0[];
extern void func_0013B260(int s);
extern void Los_BuildSegmentBound(float r, Bnd26* b, V4* from, V4* to);
extern void Los_GatherCandidates(int g, int s, Bnd26* b, int a3);
extern V4* Vec4_GetZero(void);
extern void Vec4_Assign(V4* d, V4* s);
extern void Vec4_SetOrigin(V4* d);
extern void Vec4_Copy(V4* d, V4* s);
extern void func_0013B0C0(void* p);
extern void func_0013B0D0(void* p);
extern void Los_TraceWithWater(Q26* q, int s);
extern void func_003C3880(Q26* q, int s);
extern void Los_TraceTriangles(Q26* q, int s);
extern void Col_TraceFloorTriangles(Q26* q, int s);
extern void* Ptr_Identity(void* p);
extern void Col_ReconstructSourceTriangle(Tri26* t, void* p);
extern void func_00139BB0(void* d, void* s);
extern void func_00139BA0(void* d, void* s);

static inline void Tri_Init(Tri26* t) {
    V4* p;
    p = t->v;
    do {
        Ptr_Identity(p);
        p++;
    } while (p != t->v + 3);
    Ptr_Identity(&t->n);
    func_0013B0D0(t->part40);
    func_0013B0C0(t->part60);
}
static inline unsigned char HasCtx(Q26* q) { return q->b62 != 0; }
static inline void SetMpg26(int a) {
    asm {
        .set noreorder
        ctc2.ni a, vi27
        vnop
        vnop
        .set reorder
    }
}
static inline void Q_Init(Q26* q, V4* to, V4* from) {
    V4 org;
    q->hit = 0;
    Vec4_Assign(&q->a, Vec4_GetZero());
    Vec4_SetOrigin(&org);
    Vec4_Assign(&q->b, &org);
    func_0013B0C0(q->part30);
    Vec4_Assign(&q->to, to);
    Vec4_Assign(&q->from, from);
    q->b60 = 0;
    q->b61 = 0;
    q->b62 = 0;
    q->p64 = 0;
}
unsigned char Los_TraceImmediate(V4* out, Tri26* tri, V4* from, V4* to, int g, unsigned char m0, unsigned char m1, unsigned char m2, void* ctx, unsigned char under)
{
    int s;
    Bnd26 bnd;
    Q26 q;
    Q26* qp;
    Tri26 t;
    Tri26* tp;
    unsigned char res;

    {
        int k, f, r;
        asm {
            .set noreorder
            lqc2 vf1, 0(to)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        if ((unsigned char)r)
            return 0;
    }
    s = D_00542CC8;
    func_0013B260(s);
    Los_BuildSegmentBound(0.01f, &bnd, from, to);
    if (D_00542D38 != D_00542D48) {
        int i = D_00542D38;
        int e = D_004937D0[i];
        int st = D_004937C0[i];
        *(unsigned int*)0x10008020 = (unsigned int)(e - st) >> 4;
        *(int*)0x10008010 = st;
        *(int*)0x10008000 = 0x101;
        asm __volatile__("sync");
        D_00542D48 = i;
    }
    SetMpg26(D_00542D1C);
    {
        unsigned char busy;
        do {
            unsigned char tt;
            busy = 1;
            tt = busy;
            if (!(*(volatile int*)0x10008000 & 0x100) && !(*(volatile int*)0x10003800 & 3)) tt = 0;
            if (!tt && !(*(volatile int*)0x10003800 & 0x0F000000)) busy = 0;
        } while (busy);
        asm __volatile__("vnop");
        asm __volatile__("sync");
    }
    Los_GatherCandidates(g, s, &bnd, m1);
    qp = &q;
    Q_Init(qp, to, from);
    q.b60 = m0;
    q.b61 = m1;
    if (ctx) {
        q.b62 = m2;
        q.p64 = *(void* volatile*)&ctx; /* retail reloads the stack argument */
    }
    if (HasCtx(&q)) {
        if (under) Los_TraceWithWater(&q, s);
        else func_003C3880(&q, s);
    } else {
        if (under) Los_TraceTriangles(&q, s);
        else Col_TraceFloorTriangles(&q, s);
    }
    if (q.hit) {
        *out = q.b;
        tp = &t;
        Tri_Init(tp);
        Col_ReconstructSourceTriangle(tp, q.part30);
        Vec4_Copy(&tri->v[0], &t.v[0]);
        Vec4_Copy(&tri->v[1], &t.v[1]);
        Vec4_Copy(&tri->v[2], &t.v[2]);
        Vec4_Copy(&tri->n, &t.n);
        tri->flag50 = t.flag50;
        func_00139BB0(tri->part40, t.part40);
        func_00139BA0(tri->part60, t.part60);
        tri->flag51 = t.flag51;
        tri->flag52 = t.flag52;
        res = 1;
    } else {
        res = 0;
    }
    return res;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C26D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C26D0 */

/* merge_units: begin func_003C2A80 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VObj_3C2A80 { virtual void dtor(int f); };
extern "C" {
extern char D_004BD0A0[];
#if 0 /* merge_units */
extern void* D_00542CC8;
#endif /* merge_units */
#define D_00542CC8 (*(void **)&D_00542CC8) /* merge_units */

extern void* D_00542CD0;
extern void* D_00542CD8;
extern VObj_3C2A80* D_00542CE0;
extern void* D_00542D00;
void func_00139DF0(void* p, int f);
void func_001810D0(void* p, int f);
void HumanColBufB_Dtor(void* p, int f);
}
static inline void A3_3C2A80(void* p) { if (p) func_00139DF0(p, 0); }
static inline void A2_3C2A80(void* p) { if (p) A3_3C2A80(p); }
static inline void A1_3C2A80(void* p) { if (p) A2_3C2A80(p); }
static inline void B3_3C2A80(void* p) { if (p) HumanColBufB_Dtor(p, 0); }
static inline void B2_3C2A80(void* p) { if (p) B3_3C2A80(p); }
static inline void B1_3C2A80(void* p) { if (p) B2_3C2A80(p); }
static inline void C3_3C2A80(void* p) { if (p) func_001810D0(p, 0); }
static inline void C2_3C2A80(void* p) { if (p) C3_3C2A80(p); }
static inline void C1_3C2A80(void* p) { if (p) C2_3C2A80(p); }

extern "C" void func_003C2A80(void)
{
    void* p;
    if ((p = D_00542CC8) != 0) { { AllocGuard g; A1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x41); } D_00542CC8 = 0; }
    if ((p = D_00542CD0) != 0) { { AllocGuard g; A1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x47); } D_00542CD0 = 0; }
    if ((p = D_00542CD8) != 0) { { AllocGuard g; B1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x4D); } D_00542CD8 = 0; }
    { VObj_3C2A80* v; if ((v = D_00542CE0) != 0) { { AllocGuard g; v->dtor(-1); Mem_Free(0, v, D_004BD0A0, 0x53); } D_00542CE0 = 0; } }
    if ((p = D_00542D00) != 0) { { AllocGuard g; C1_3C2A80(p); Mem_Free(0, p, D_004BD0A0, 0x68E); } D_00542D00 = 0; }
}
#undef D_00542CC8 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C2A80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C2A80 */

/* merge_units: begin func_003C2DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004D9140[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_001361E0(void* p);
int func_001361D0(int* n);
void Vector_Reserve_139920_Thunk(void* p, int n);
void HumanColBufB_Init(void* p);
void HumanColBufB_Reserve(void* p, int n);
void func_003C3120(void* p, int* n, int k);
void func_003C3110(void* p);
void func_003C06B0(int a);
}
struct ScrA { int w[3]; unsigned char bC; };
struct ScrB { void* vt; int w[4]; int x[3]; };
#if 0 /* merge_units */
extern "C" ScrA* D_00542CC8;
#endif /* merge_units */
#define D_00542CC8 (*(ScrA **)&D_00542CC8) /* merge_units */

#if 0 /* merge_units */
extern "C" ScrA* D_00542CD0;
#endif /* merge_units */
#define D_00542CD0 (*(ScrA **)&D_00542CD0) /* merge_units */

#if 0 /* merge_units */
extern "C" ScrA* D_00542CD8;
#endif /* merge_units */
#define D_00542CD8 (*(ScrA **)&D_00542CD8) /* merge_units */

#if 0 /* merge_units */
extern "C" ScrB* D_00542CE0;
#endif /* merge_units */
#define D_00542CE0 (*(ScrB **)&D_00542CE0) /* merge_units */

static inline void* AllocL(int size, int line) {
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BD0A0, line);
}
extern "C" void ColScratch_Init(int a0, int a1, int a2, int a3) {
    if (!D_00542CC8) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x2E);
        if (p) {
            int n = a0;
            func_001361E0(p);
            Vector_Reserve_139920_Thunk(p, func_001361D0(&n));
            p->bC = 1;
        }
        D_00542CC8 = p;
    }
    if (!D_00542CD0) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x31);
        if (p) {
            int n = a0;
            func_001361E0(p);
            Vector_Reserve_139920_Thunk(p, func_001361D0(&n));
            p->bC = 1;
        }
        D_00542CD0 = p;
    }
    if (!D_00542CD8) {
        ScrA* p = (ScrA*)AllocL(0x10, 0x34);
        if (p) {
            int n = a1;
            HumanColBufB_Init(p);
            HumanColBufB_Reserve(p, func_001361D0(&n));
            p->bC = 1;
        }
        D_00542CD8 = p;
    }
    if (!D_00542CE0) {
        ScrB* p = (ScrB*)AllocL(0x20, 0x37);
        if (p) {
            int n = a2;
            p->vt = D_004D9140;
            func_003C3120(p->w, &n, 1);
            func_003C3110(p->x);
        }
        D_00542CE0 = p;
    }
    func_003C06B0(a3);
}
#undef D_00542CC8 /* merge_units */
#undef D_00542CD0 /* merge_units */
#undef D_00542CD8 /* merge_units */
#undef D_00542CE0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C2DE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C2DE0 */
