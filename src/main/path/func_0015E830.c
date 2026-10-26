/* NpcRoute_AddLinkedRegions: for every node of the current region that has
 * links, add the group of each type-10 (region link) target node to the
 * candidate list unless it is already there (cost: base + squared distance
 * from the start point or from the linking node). */
#pragma cplusplus on
#include "types.h"
/* lq/sq and VU0 ops: no C equivalent (asm). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
} __attribute__((aligned(16)));
static inline void SubV(V4* pr, const V4* pa, const V4* pb) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(pa), "r"(pr), "r"(pb) : "memory"); }
static inline V4 operator-(const V4& a, const V4& b) { V4 r; SubV(&r, &a, &b); return r; }
static inline float SumSq(V4 v)
{
    V4* p = &v;
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
/* iterators are copied as one float word (retail lwc1/swc1) */
union It4 { int* p; float f; };
union It8 { int* p; float f; };
struct Link { int id; int type; };
struct PNode { char p0[0x64]; int flags; char links[0x14]; int group; };
struct NodeTab { int p0; int n; PNode** data; };
struct Region { char p0[0x10]; };
struct RegionVec { int p0; int n; Region* data; };
struct Ent { int id; int b; int c; };
struct Route { char p0[0x440]; V4 start; char p450[0x484 - 0x450]; Ent e[32]; int count; };
struct Ctx { int region; int mode; float cost; };
extern "C" {
extern NodeTab* D_004FFBE0;
extern RegionVec* D_004FFBE8;
void std_vector_int_begin(It4* out, Region* c);
void std_vector_int_end_void(It4* out, Region* c);
void cArray_int_ConstIterator_ctor(It4* out, It4* raw);
int* std_vector_imp_tNodeLink_begin_void_2(void* c);
int* std_vector_imp_tNodeLink_end_void_2(void* c);
void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(It8* out, void* c, int** raw);
V4 Node_GetTranslation(PNode* n);
void NpcRoute_AddLinkedRegions(Route* self, Ctx* ctx);
}
static inline bool Eq4(const It4& a, const It4& b) { int* x = a.p; return b.p == x; }
static inline bool Eq8(const It8& a, const It8& b) { return a.p == b.p; }

void NpcRoute_AddLinkedRegions(Route* self, Ctx* ctx)
{
    It4 it1;
    It8 it2;
    It4 t134;
    It8 t130;
    It8 end2;
    It4 end1;
    It8 t124;
    It8 t120;
    It4 raw11C;
    int* raw118;
    int* raw114;
    It4 raw110;
    NodeTab* tab = D_004FFBE0;
    Region* rg = &D_004FFBE8->data[ctx->region];
    std_vector_int_begin(&raw11C, rg);
    cArray_int_ConstIterator_ctor(&t134, &raw11C);
    it1 = t134;
    while ((std_vector_int_end_void(&raw110, rg), cArray_int_ConstIterator_ctor(&end1, &raw110), !Eq4(end1, it1))) {
        PNode* n = tab->data[*it1.p];
        if (n->flags & 0x80) {
            void* c = n->links;
            std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t124, c, (raw118 = std_vector_imp_tNodeLink_begin_void_2(c), &raw118));
            t130.p = t124.p;
            it2 = t130;
            while ((std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t120, c, (raw114 = std_vector_imp_tNodeLink_end_void_2(c), &raw114)), (end2.p = t120.p, !Eq8(it2, end2)))) {
                Link* l = (Link*)it2.p;
                if (l->type == 10) {
                    PNode* m = tab->data[l->id];
                    int grp = m->group;
                    int j;
                    int found = -1;
                    for (j = 0; j < self->count; j++) {
                        if (self->e[j].id == grp) {
                            found = j;
                            break;
                        }
                    }
                    if (found < 0) {
                        float cost = ctx->cost;
                        if (ctx->mode < 0)
                            cost += SumSq(Node_GetTranslation(m) - self->start);
                        else
                            cost += SumSq(Node_GetTranslation(m) - Node_GetTranslation(n));
                        self->e[self->count].id = grp;
                        self->e[self->count].b = -1;
                        self->e[self->count].c = 0;
                        self->count++;
                    }
                }
                it2.p += 2;
            }
        }
        it1.p += 1;
    }
}
