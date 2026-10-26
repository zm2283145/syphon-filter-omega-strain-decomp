#pragma cplusplus on
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct H { int v; H(int x) { v = x; } };
struct HO { int v; };
struct CtNode { V4 box[2]; int child[8]; };
struct CtLeaf { V4 box[2]; unsigned int count; int idx; };
struct CtTri { char pad[4]; unsigned short v[3]; };
struct CtMesh;
struct CtOut;

extern "C" {
extern int D_00542D10;
int ColTree_IsLeaf(CtMesh* m, const H& h);
CtNode* func_00182120(CtMesh* m, const H& h);
unsigned char func_003C61A0(CtMesh* m, void* box);
int func_001821D0(int* p, int z);
void func_001821C0(HO* d, int* s);
void func_00182150(HO* h, int f);
CtLeaf* func_00181E90(CtMesh* m, const H& h);
void func_003C5BD0(CtMesh* m, CtOut* out, CtLeaf* l, int x);
int func_003C5BC0(int* d, int n);
void func_003C5BB0(HO* d, int* s);
int* func_00183B30(CtMesh* m, HO* h);
void func_00183730(HO* h, int f);
CtTri* func_003C0CF0(CtMesh* m, int t);
V4* func_00231EC0(CtMesh* m, unsigned short v);
unsigned char func_003C5B80(CtMesh* m, V4* a, V4* b, V4* c);
void func_003C58A0(CtOut* out, CtMesh* m, CtTri* t, int i);
void func_003C5EA0(CtMesh* m, CtOut* out, CtNode* node, int x);
}

static inline unsigned char BoxTest(void* unused, V4* a) {
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
static inline void SetMpg(int a) {
    asm {
        .set noreorder
        ctc2 a, vi27
        vnop
        vnop
        .set reorder
    }
}


extern "C" void func_003C5EA0(CtMesh* m, CtOut* out, CtNode* node, int x)
{
    if (BoxTest(0, node->box)) {
        int* ref;
        unsigned int i;
        ref = node->child;
        for (i = 0; i < 8; i++, ref++) {
            if (*ref) {
                HO h1;
                HO h2;
                HO h6;
                HO* p1 = &h1;
                p1->v = *ref;
                if (!(unsigned char)ColTree_IsLeaf(m, *(H*)p1)) {
                    CtNode* sub;
                    HO* p2 = &h2;
                    p2->v = *ref;
                    sub = func_00182120(m, *(H*)p2);
                    if ((unsigned char)func_003C61A0(m, sub)) {
                        int* c;
                        unsigned int j;
                        c = sub->child;
                        for (j = 0; j < 8; j++, c++) {
                            if (func_001821D0(c, 0)) {
                                unsigned char leaf;
                                {
                                    HO h;
                                    func_001821C0(&h, c);
                                    leaf = ColTree_IsLeaf(m, *(H*)&h);
                                    func_00182150(&h, -1);
                                }
                                if (!leaf) {
                                    HO h;
                                    func_001821C0(&h, c);
                                    func_003C5EA0(m, out, func_00182120(m, *(H*)&h), x);
                                    func_00182150(&h, -1);
                                } else {
                                    HO h;
                                    func_001821C0(&h, c);
                                    func_003C5BD0(m, out, func_00181E90(m, *(H*)&h), x);
                                    func_00182150(&h, -1);
                                }
                            }
                        }
                    }
                    sub = 0; /* dead store: keeps the failed sub-box test branching to this arm's own exit block (retail does not thread it to the loop increment) */
                } else {
                    CtLeaf* l;
                    HO* p6 = &h6;
                    p6->v = *ref;
                    l = func_00181E90(m, *(H*)p6);
                    if (func_003C61A0(m, l)) {
                        unsigned int n;
                        int* ip;
                        unsigned int k;
                        SetMpg(func_003C5BC0(&D_00542D10, 4));
                        n = l->count;
                        {
                            HO h;
                            func_003C5BB0(&h, &l->idx);
                            ip = func_00183B30(m, &h);
                            func_00183730(&h, -1);
                        }
                        for (k = 0; k < n; k++, ip++) {
                            int t = *ip;
                            CtTri* tr = func_003C0CF0(m, t);
                            V4* a = func_00231EC0(m, tr->v[0]);
                            V4* b = func_00231EC0(m, tr->v[1]);
                            V4* c = func_00231EC0(m, tr->v[2]);
                            if (func_003C5B80(m, a, b, c)) func_003C58A0(out, m, tr, t);
                        }
                        SetMpg(func_003C5BC0(&D_00542D10, 3));
                    }
                }
            }
        }
    }
}
