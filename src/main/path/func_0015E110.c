/* NpcRoute_CollectCandidates: gather the reachable regions (start region plus
 * linked regions, depth levels), drop the ones the NPC may not enter, then
 * score every usable node of those regions and keep the best 32 in a sorted
 * list (following link chains for linked-node mode); prune entries scoring
 * 5000 or more. */
#pragma cplusplus on
#include "types.h"
/* lq/sq and VU0 ops: no C equivalent (asm). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
} __attribute__((aligned(16)));
static inline void SubV(V4* pr, const V4* pa, const V4* pb) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory"); }
static inline V4 operator-(const V4& a, const V4& b) { V4 r; SubV(&r, &a, &b); return r; }
/* iterators are copied as one float word (retail lwc1/swc1) */
union It4 { int* p; float f; };
union It8 { int* p; float f; };
struct Link { int id; int type; };
struct PNode { char p0[0x64]; int flags; char links[0x14]; int group; };
struct NodeTab { int p0; int n; PNode** data; };
struct Region { char p0[0x10]; };
struct RegionVec { int p0; int n; Region* data; };
struct Ent { int id; int b; float cost; };
struct SNode { int p0; SNode* next; SNode* prev; float key; int id; int link; int x18; int x1C; };
struct SHead { int p0; SNode* next; SNode* prev; };
struct SList { int p0[2]; SNode* first; int p0C; SHead sent; int count; };
struct Obj { char p0[0xC]; int serial; char p10[0x58 - 0x10]; class Ctl* ctl; };
class Ctl {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int RegionsRestricted();
};
struct Ref { Obj* obj; int serial; };
struct Route {
    Ref ref; char p08[8]; SList list; SNode pool[32];
};
struct RouteX {
    char p0[0x430]; char cfg[8]; unsigned char linkMode; char p439[7]; V4 start; V4 target; float maxDist; int startRegion; int nodeMask; char p46C[4];
    int skipNode; char p474[0xE]; unsigned char ignoreReserve; char p483; Ent e[32]; int count;
};
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
PNode* NpcPath_GetNode(int id);
Obj* NpcAi_NodeReservedBy(int node);
unsigned char NpcAi_IsRegionAllowed(Ctl* c, int region);
float NpcRoute_ScoreCandidate(void* c, PNode* node, int idx, V4* from, V4* to, int x, float cost);
void NpcNodeSearch_InsertSorted(SList* l, SNode* item);
void NpcRoute_AddLinkedRegions(RouteX* self, Ent* ctx);
void NpcRoute_CollectCandidates(Route* self, int depth);
}
static inline bool Eq(int a, int b) { return a == b; }
static inline Obj* Get(Ref* r)
{
    unsigned char v = !r->obj || Eq(r->obj->serial, r->serial);
    return v ? r->obj : 0;
}
static inline float Length(V4 v)
{
    V4* p = &v;
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline bool Eq4(const It4& a, const It4& b) { int* x = a.p; return b.p == x; }
static inline bool Eq8(const It8& a, const It8& b) { return a.p == b.p; }

/* unlink entries scoring 5000 or more; returns the next entry */
static inline SNode* Prune2(SList* l, SNode* p) { SNode* nx = p->next; if (!(p->key < 5000.0f)) { SNode* pv = p->prev; pv->next = nx; nx->prev = pv; l->count--; return nx; } return nx; }
static inline int Masked(RouteX* x, PNode* n) { int f = n->flags; return x->nodeMask & f; }
void NpcRoute_CollectCandidates(Route* self, int depth)
{
    RouteX* x = (RouteX*)self;
    It4 it1;
    It8 it2;
    It4 t124;
    It8 t120;
    It8 t11C;
    It8 end2;
    It4 end1;
    It8 t110;
    It8 t10C;
    It8 t108;
    It4 raw104;
    int* raw100;
    int* rawFC;
    int* rawF8;
    It4 rawF4;
    NodeTab* tab = D_004FFBE0;
    int k;
    x->count = 0;
    if (x->startRegion >= 0) {
        x->e[x->count].id = x->startRegion;
        x->e[x->count].b = -1;
        x->e[x->count].cost = 0;
        x->count++;
        for (k = 0; k < depth; k++) {
            int j;
            int n = x->count;
            for (j = 0; j < n; j++)
                NpcRoute_AddLinkedRegions(x, &x->e[j]);
        }
    }
    {
        Ctl* c = Get(&self->ref)->ctl;
        if (c && c->RegionsRestricted()) {
            int n = x->count;
            int j;
            for (j = 0; j < n; j++) {
                if (!NpcAi_IsRegionAllowed(c, x->e[j].id))
                    x->e[j].id = -1;
            }
        }
    }
    for (k = 0; k < x->count; k++) {
        if (x->e[k].id >= 0) {
            Region* rg = &D_004FFBE8->data[x->e[k].id];
            if (x->e[k].cost < x->maxDist) {
                std_vector_int_begin(&raw104, rg);
                cArray_int_ConstIterator_ctor(&t124, &raw104);
                it1 = t124;
                while ((std_vector_int_end_void(&rawF4, rg), cArray_int_ConstIterator_ctor(&end1, &rawF4), !Eq4(end1, it1))) {
                    int id = *it1.p;
                    PNode* n = tab->data[id];
                    if (id != x->skipNode && Masked(x, n)) {
                        Obj* r = NpcAi_NodeReservedBy(id);
                        if (x->ignoreReserve || !r || r == Get(&self->ref)) {
                            if (Length(x->target - Node_GetTranslation(n)) < x->maxDist) {
                                int link = -1;
                                int mask = 0;
                                float score;
                                if (!x->ignoreReserve) {
                                    score = NpcRoute_ScoreCandidate(x->cfg, n, 0, &x->start, &x->target, 0, x->e[k].cost);
                                } else {
                                    if (Abs(x->start.z - Node_GetTranslation(n).z) < 2.6f)
                                        score = 0.0f;
                                    else
                                        score = 5000.0f;
                                }
                                if (score <= 5000.0f) {
                                    void* lk = NpcPath_GetNode(id)->links;
                                    if (x->linkMode) {
                                        mask = (x->nodeMask & 0x40) ? 6 : 0x40;
                                        if (mask & n->flags)
                                            link = id;
                                        std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t110, lk, (raw100 = std_vector_imp_tNodeLink_begin_void_2(lk), &raw100));
                                        t120.p = t110.p;
                                        it2 = t120;
                                    } else {
                                        std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t10C, lk, (rawFC = std_vector_imp_tNodeLink_end_void_2(lk), &rawFC));
                                        t11C.p = t10C.p;
                                        it2 = t11C;
                                    }
                                    do {
                                        float c2 = score;
                                        if (x->linkMode && link < 0)
                                            c2 += 1000.0f;
                                        if (self->list.count < 32) {
                                            SNode* nd = (SNode*)((char*)self->pool + self->list.count * sizeof(SNode));
                                            nd->id = id;
                                            nd->link = link;
                                            nd->x18 = -1;
                                            nd->x1C = -1;
                                            nd->key = c2;
                                            NpcNodeSearch_InsertSorted(&self->list, nd);
                                        } else {
                                            SNode* last = self->list.sent.prev;
                                            if (c2 < last->key) {
                                                SNode* nx = last->next;
                                                SNode* pv = last->prev;
                                                pv->next = nx;
                                                nx->prev = pv;
                                                self->list.count--;
                                                last->id = id;
                                                last->link = link;
                                                last->x18 = -1;
                                                last->x1C = -1;
                                                last->key = c2;
                                                NpcNodeSearch_InsertSorted(&self->list, last);
                                            }
                                        }
                                        link = -1;
                                        while ((std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(&t108, lk, (rawF8 = std_vector_imp_tNodeLink_end_void_2(lk), &rawF8)), end2.p = t108.p, !Eq8(it2, end2))) {
                                            int type;
                                            Link* l = (Link*)it2.p;
                                            type = l->type;
                                            link = l->id;
                                            it2.p += 2;
                                            if (type != 7) {
                                                if (mask & NpcPath_GetNode(link)->flags)
                                                    break;
                                            } else {
                                                link = -1;
                                            }
                                        }
                                    } while (link >= 0);
                                }
                            }
                        }
                    }
                    it1.p += 1;
                }
            }
        }
    }
    {
        SNode* p = self->list.first;
        while (p != (SNode*)&self->list.sent) {
            p = Prune2(&self->list, p);
        }
    }
}
