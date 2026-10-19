/*
 * main/GenInfoObject: 3 files, 0043ABA0-0043ACE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043ABA0 */
#pragma push /* merge_units */
#include "types.h"
#include "net_local_id.h"
typedef struct { int id; unsigned char lo : 4; unsigned char hi : 4; char pad[3]; } Ent_ABA0;
extern Ent_ABA0* D_00583888;
static inline Ent_ABA0* Find_ABA0(int k)
{
    Ent_ABA0* t = D_00583888;
    if (t) {
        int i;
        for (i = 0; i != 0x37; i++)
            if (k == t[i].id) return &t[i];
    }
    return 0;
}
#pragma inline_depth(10)
static inline int Resolve_ABA0(int i)
{
    if (i == -1) return NetLocalId();
    return i;
}
int func_0043ABA0(void* self, int* key, int idx)
{
    Ent_ABA0* e;
    if (idx > 4) return 0;
    e = Find_ABA0(*key);
    if (e) {
        idx = Resolve_ABA0(idx);
        return (e->hi & (1 << idx)) != 0;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043ABA0 */

/* merge_units: begin func_0043ACB0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int D_00583888;
#endif /* merge_units */
#define D_00583888 (*(int*)&D_00583888) /* merge_units */

extern unsigned char D_005838A0[];
/* Mark slot `index` as set while the feature flag is enabled. */
void func_0043ACB0(int unused, int index)
{
    if (D_00583888) {
        D_005838A0[index] = 1;
    }
}
#undef D_00583888 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043ACB0 */

/* merge_units: begin func_0043ACE0 */
#pragma push /* merge_units */
/* func_0043ACE0: GenInfoObject teardown (free buffer, free+erase 2 lists, free tree values, Map_Clear).
 * mw38 MATCH. Slot layout keys: b1/tb declared just before their loops (guards then interleave),
 * erase triples as a level-1 inline, begin/end calls as level-2 inlines (temps allocated breadth-first
 * after main locals), loop-2 iterator "LIt2 it2 __attribute__((aligned(8)))" (pushed to the lowest slot).
 * UNDEF __dl__FPv from the LIt dtor is the usual benign one. */
#pragma cplusplus on
#include "alloc_guard.h"

struct LNode { LNode* prev; LNode* next; void* data; };
struct LIt { LNode* p; __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~LIt() {} };
struct LIt2 { LNode* p; };
struct TNode { char pad[0xC]; void* data; };
struct TIt { TNode* node; TIt() {} };

extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void ObjectList_EraseRange(int* out, void* list, LNode** first, LNode** last);
LIt List_Begin(void* list);
LIt func_0043B180(void* list);
LIt func_00438E00(void* list);
void func_00438E10(LIt* out, const LIt& in);
void func_00438DF0(LIt* out, const LIt& in);
void func_00439380(TIt* out, void* tree);
TIt func_00439370(void* tree);
void func_00439360(TIt* out, const TIt& in);
void Tree_Successor(TIt* it);
void Map_Clear(void* tree);
extern char D_004BFD60[];
#if 0 /* merge_units */
extern void* D_00583888;
#endif /* merge_units */
#define D_00583888 (*(void **)&D_00583888) /* merge_units */

extern unsigned char D_00583880;
extern int D_00497578;
extern unsigned char D_00583890;
extern int D_00583898;
extern int D_00583910;
extern char D_005838B8[];
extern char D_005838BC[];
extern LNode* D_005838C0;
extern char D_005838D8[];
extern char D_005838DC[];
extern LNode* D_005838E0;
extern char D_00583900[];
#if 0 /* merge_units */
extern unsigned char D_005838A0;
#endif /* merge_units */
#define D_005838A0 (*(unsigned char*)&D_005838A0) /* merge_units */

extern unsigned char D_005838A1;
extern unsigned char D_005838A2;
extern unsigned char D_005838A3;
}

static inline void LB1(LIt* o, void* L) { func_00438E10(o, List_Begin(L)); }
static inline void LB2(LIt* o, void* L) { func_00438DF0(o, func_0043B180(L)); }
static inline void LE(LIt* o, void* L) { func_00438DF0(o, func_00438E00(L)); }
static inline void TE(TIt* o, void* T) { func_00439360(o, func_00439370(T)); }
static inline void LB1x(LIt* o, void* L) { LB1(o, L); }
static inline void LB2x(LIt* o, void* L) { LB2(o, L); }
static inline void LEx(LIt* o, void* L) { LE(o, L); }
static inline void TEx(TIt* o, void* T) { TE(o, T); }
static inline void Erase(void* L, void* LH, LNode* LF) { int res; LNode* first; LNode* last; last = (LNode*)LH; first = LF; ObjectList_EraseRange(&res, L, &first, &last); }
static inline unsigned char Ne(TIt* a, TIt* b) { return !(a->node == b->node); }

extern "C" void func_0043ACE0(void* self)
{
    LIt it1;
    TIt it;
    LIt end1;
    LIt2 b2, end2;
    TIt tend;

    if (D_00583888 && !D_00583880) {
        void* p = D_00583888;
        AllocGuard g;
        Mem_Free(0, p, D_004BFD60, 0x2B);
    }
    D_00583880 = 0;
    D_00583888 = 0;
    D_00497578 = -1;
    D_00583890 = 0;
    D_00583898 = 0;
    D_00583910 = 0;
    LIt b1;
    LB1x(&b1, D_005838B8);
    it1 = b1;
    while (LEx(&end1, D_005838B8), it1.p != end1.p) {
        void* e = (*(LNode* volatile*)&it1.p)->data;
        {
            AllocGuard g;
            Mem_Free(0, e, D_004BFD60, 0x38);
        }
        it1.p = it1.p->next;
    }
    Erase(D_005838B8, D_005838BC, D_005838C0);
    LB2x((LIt*)&b2, D_005838D8);
    {
        LIt2 it2 __attribute__((aligned(8))) = b2;
        while (LEx((LIt*)&end2, D_005838D8), it2.p != end2.p) {
            void* e = it2.p->data;
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFD60, 0x41);
            }
            it2.p = it2.p->next;
        }
    }
    Erase(D_005838D8, D_005838DC, D_005838E0);
    TIt tb;
    func_00439380(&tb, D_00583900);
    it = tb;
    while (TEx(&tend, D_00583900), Ne(&it, &tend)) {
        void* e = it.node->data;
        {
            AllocGuard g;
            Mem_Free(0, e, D_004BFD60, 0x4C);
        }
        Tree_Successor(&it);
    }
    Map_Clear(D_00583900);
    D_005838A0 = 0;
    D_005838A1 = 0;
    D_005838A2 = 0;
    D_005838A3 = 0;
}
#undef D_00583888 /* merge_units */
#undef D_005838A0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043ACE0 */
