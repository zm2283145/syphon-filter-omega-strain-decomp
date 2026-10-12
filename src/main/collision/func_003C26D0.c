/* Los_TraceImmediate */
#include "types.h"
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










