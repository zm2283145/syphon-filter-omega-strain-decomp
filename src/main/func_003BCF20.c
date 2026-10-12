#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; } Seg;
typedef struct { char pad[0x70]; V4 v70; char pad2[0x20]; float fA0; } CQ;
extern void* Ptr_Identity(void* p);
extern V4* Array16_At(V4* base, int i);
extern V4* Vec4_Copy(V4* d, V4* s);
extern int Col_SweepEdge(CQ* q, Seg* s, void* r);
extern int Col_SweepVertex(CQ* q, V4* v, void* r);
int Col_OffFaceContact(CQ* q, V4* tri, void* r) {
    unsigned char hit;
    unsigned char hitv;
    unsigned int i;
    V4* p = &q->v70;
    int t;
    asm {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
    }
    *(int*)&q->fA0 = t;
    hit = 0;
    for (i = 0; i < 3; i++) {
        Seg s;
        Ptr_Identity(&s.a);
        Ptr_Identity(&s.b);
        Vec4_Copy(&s.a, Array16_At(tri, i));
        Vec4_Copy(&s.b, Array16_At(tri, i == 2 ? 0 : i + 1));
        hit = Col_SweepEdge(q, &s, r) || hit;
    }
    if (hit) goto yes;
    hitv = 0;
    for (i = 0; i < 3; i++) {
        hitv = Col_SweepVertex(q, Array16_At(tri, i), r) || hitv;
    }
    if (hitv) {
    yes:
        return 1;
    }
    return 0;
}
