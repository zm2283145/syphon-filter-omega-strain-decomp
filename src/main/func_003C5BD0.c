#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad0[3]; unsigned char kind; char pad4[0x14]; int tris; char pad1C[4]; int verts; } Mesh5BD0;
typedef struct { int vec; int x4; unsigned char mask; } Out5BD0;
typedef struct { V4 box[2]; unsigned int count; int idx; } Node5BD0;
typedef struct { char pad[4]; unsigned short v[3]; char flags[2]; } Tri5BD0;
typedef struct { char pad[0x74]; } Rec5BD0;
extern int D_00542D20;
extern int D_00542D1C;
extern int* func_00183B30(Mesh5BD0* m, int* p);
extern char* func_00183B20(Mesh5BD0* m, int* p);
extern char* func_00183B10(Mesh5BD0* m, int* p);
extern int Triangle_GetSurface(Tri5BD0* t);
extern int Surface_Lookup(Mesh5BD0* m, int s);
extern int ColTri_FilterStub(void* f, unsigned char mask);
extern int Surface_TestMask(int s, unsigned char mask);
extern int func_001839E0(int v);
extern int func_001839D0(int v);
extern void Vector_Reserve_139920_Thunk_1839C0(int v, int n);
extern void func_001839B0(int v, int n, Rec5BD0* r);
extern int func_00183990(int v);
extern void func_0013AAE0(Rec5BD0* r);
extern void func_00131B70(Rec5BD0* r, int f);
extern void GatherRecords_Append(int p, Tri5BD0* t, int i, int s, int x);

static inline unsigned char BoxTest5BD0(void* unused, V4* a) {
    V4* b = a + 1;
    int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vcallmsr vi27
        cfc2.i r, vi1
        .set reorder
    }
    return r;
}
static inline unsigned char TriTest5BD0(void* unused, V4* a, V4* b, V4* c) {
    int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        lqc2 vf3, 0(c)
        vcallmsr vi27
        cfc2.i r, vi1
        .set reorder
    }
    return r;
}
static inline void SetMpg5BD0(int a) {
    asm {
        .set noreorder
        ctc2.ni a, vi27
        vnop
        vnop
        .set reorder
    }
}
static inline int* GetIdx5BD0(Mesh5BD0* m, int o) { return func_00183B30(m, &o); }
static inline char* GetTris5BD0(Mesh5BD0* m) { int o = m->tris; return func_00183B20(m, &o); }
static inline V4* GetVert5BD0(Mesh5BD0* m, int i) { int o = m->verts; return (V4*)func_00183B10(m, &o) + i; }

void func_003C5BD0(Mesh5BD0* m, Out5BD0* out, Node5BD0* node)
{
    int* ip;
    unsigned int i;
    unsigned int n;
    int idx;
    Tri5BD0* t;
    V4* a;
    V4* b;
    V4* c;
    int surf;
    int sz;
    Rec5BD0 rec;

    if (BoxTest5BD0(0, node->box)) {
        SetMpg5BD0(D_00542D20);
        n = node->count;
        ip = GetIdx5BD0(m, node->idx);
        for (i = 0; i < n; i++, ip++) {
            idx = *ip;
            if (m->kind < 4) {
                t = (Tri5BD0*)(GetTris5BD0(m) + (idx << 6));
            } else if (m->kind < 5) {
                t = (Tri5BD0*)(GetTris5BD0(m) + (idx << 5));
            } else {
                t = (Tri5BD0*)(GetTris5BD0(m) + (idx << 4));
            }
            a = GetVert5BD0(m, t->v[0]);
            b = GetVert5BD0(m, t->v[1]);
            c = GetVert5BD0(m, t->v[2]);
            if (TriTest5BD0(0, a, b, c)) {
                surf = Surface_Lookup(m, Triangle_GetSurface(t));
                if (!(ColTri_FilterStub(t->flags, out->mask) & 0xFF) && !(Surface_TestMask(surf, out->mask) & 0xFF)) {
                    sz = func_001839E0(out->vec);
                    if (sz >= func_001839D0(out->vec)) {
                        Vector_Reserve_139920_Thunk_1839C0(out->vec, func_001839D0(out->vec) * 3 / 2);
                    }
                    func_0013AAE0(&rec);
                    func_001839B0(out->vec, func_001839E0(out->vec) + 1, &rec);
                    func_00131B70(&rec, -1);
                    GatherRecords_Append(func_00183990(out->vec), t, idx, surf, out->x4);
                }
            }
        }
        SetMpg5BD0(D_00542D1C);
    }
}
