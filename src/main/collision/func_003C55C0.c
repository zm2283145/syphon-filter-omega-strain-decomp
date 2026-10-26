#pragma cplusplus on
#include "types.h"

/* func_003C55C0: collision-tree box query root - upload the query box to VU0, then walk the root
 * node's children (func_003C5EA0 / func_003C5BD0) or test the single leaf's triangles. */

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct H { int v; H(int x) { v = x; } };
struct HO { int v; };
struct CtNode { V4 box[2]; int child[8]; };
struct CtLeaf { V4 box[2]; unsigned int count; int idx; };
struct CtTri { char pad[4]; unsigned short v[3]; };
struct CtMeshS { char pad0[2]; signed char kind; char pad3; int nNodes; int root; char padC[4]; int leaf; };
typedef CtMeshS CtMesh;
struct CtBox { V4 v[6]; };
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
void func_003C5BD0(CtMesh* m, CtOut* out, CtLeaf* l, CtBox* box);
int func_003C5BC0(int* d, int n);
void func_003C5BB0(HO* d, int* s);
int* func_00183B30(CtMesh* m, HO* h);
void func_00183730(HO* h, int f);
CtTri* func_003C0CF0(CtMesh* m, int t);
V4* func_00231EC0(CtMesh* m, unsigned short v);
unsigned char func_003C5B80(CtMesh* m, V4* a, V4* b, V4* c);
void func_003C58A0(CtOut* out, CtMesh* m, CtTri* t, int i);
void func_003C5EA0(CtMesh* m, CtOut* out, CtNode* node, CtBox* box);
CtNode* func_00182260(CtMesh* m, H* h);
CtLeaf* func_00181E80(CtMesh* m, H* h);
void func_003C55C0(CtMesh* m, CtOut* out, CtBox* box);
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


extern "C" void func_003C55C0(CtMesh* m, CtOut* out, CtBox* box)
{
    HO hr;
    HO hl;
    if (m->kind != 'F') return;
    {
        CtBox* d = (CtBox*)0x11004000;
        __int128 a;
        __int128 b;
        /* upload the query box to VU0 data memory (hand-scheduled quad copy), then wait for VU0 */
        asm volatile {
            lq a, 0(box)
            lq b, 16(box)
            sq a, 0(d)
            lq a, 32(box)
            sq b, 16(d)
            lq b, 48(box)
            sq a, 32(d)
            lq a, 64(box)
            sq b, 48(d)
            lq b, 80(box)
            sq a, 64(d)
            sq b, 80(d)
            vnop
            sync
        }
    }
    if (m->nNodes > 0) {
        CtNode* node;
        hr.v = m->root;
        node = func_00182260(m, (H*)&hr);
        if ((unsigned char)func_003C61A0(m, node)) {
            int* c;
            unsigned int j;
            c = node->child;
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
                        func_003C5EA0(m, out, func_00182120(m, *(H*)&h), box);
                        func_00182150(&h, -1);
                    } else {
                        HO h;
                        func_001821C0(&h, c);
                        func_003C5BD0(m, out, func_00181E90(m, *(H*)&h), box);
                        func_00182150(&h, -1);
                    }
                }
            }
        }
    } else {
        CtLeaf* l;
        hl.v = m->leaf;
        l = func_00181E80(m, (H*)&hl);
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
