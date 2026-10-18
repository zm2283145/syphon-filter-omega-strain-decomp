/*
 * main/NetMsgThrottle: NetMsgThrottle.cc (3 files, 00472050-00472370)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00472050 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* func_00472050(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void func_00472060(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* begin(): iterator at the leftmost node. */
void func_00472070(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
#pragma pop /* merge_units */
/* merge_units: end func_00472050 */

/* merge_units: begin func_00472080 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct ThrMsg {
    virtual ~ThrMsg();
};

struct ThrEntry {
    ThrMsg* msg;
    void* target;
    int flags;
};

struct ThrListNode {
    ThrListNode* next;
    ThrListNode* prev;
    ThrEntry* entry;
};

struct ThrList {
    char pad0[8];
    ThrListNode* head;
    char padC[4];
    float rate;
    int count;
};

struct ThrNode {
    char links[0xC];
    int key;
    ThrList list;
};

struct ThrIt { ThrNode* node; };
struct ThrLIt {
    ThrListNode* node;
    ThrLIt() {}
    ThrLIt(ThrListNode* n) : node(n) {}
};

extern "C" {
extern char D_00588020[];
extern int D_00588030;
extern char D_004C3430[];
extern char D_004C3410[];
#if 0 /* merge_units */
void func_00472070(ThrIt* r, void* map);
#endif /* merge_units */
#define func_00472070(a0, a1) (func_00472070((Iter *)(a0), (Tree *)(a1))) /* merge_units */

ThrIt func_00471EA0(void* map);
void func_00471E90(ThrIt* r, const ThrIt& s);
/* ThrLIt has constructors, so these return it through a hidden pointer:
   ThrLIt func_00472370(ThrList *) / ThrLIt func_00472060(ThrList *). */
void func_00472370(Iter* out, PtrVec* v);
#if 0 /* merge_units */
void func_00472050(ThrLIt* r, const ThrLIt& s);
#endif /* merge_units */

ThrLIt List_Erase(ThrList* l, const ThrLIt& pos);
int Net_GetClock(int);
void printf(char* fmt, ...);
void Event_Send(ThrMsg* msg, void* target, int flags);
void Tree_Successor(void* it);
void Mem_Free(int pool, void* p, char* file, int line);
}

static inline void LGet(ThrList* l, ThrLIt* b, ThrLIt* e)
{
    ThrLIt t;
    ThrLIt u;

    func_00472370((Iter*)&t, (PtrVec*)l);
    func_00472050((Word*)b, (Word*)&t);
    func_00472060((Iter*)&u, (Tree*)l);
    func_00472050((Word*)e, (Word*)&u);
}

static inline int MapNe(ThrIt* it, ThrIt* end)
{
    func_00471E90(end, func_00471EA0(D_00588020));
    return (it->node == end->node) ^ 1;
}

extern "C" void NetMsgThrottle_SendMsg(void)
{
    ThrIt it;
    ThrLIt e;
    ThrLIt b;
    ThrIt end;
    ThrIt begin;
    int now;

    func_00472070(&begin, D_00588020);
    it.node = begin.node;
    now = Net_GetClock(1);
    while (MapNe(&it, &end)) {
        ThrList* l = &it.node->list;
        float f = (float)l->count * l->rate;
        if (f >= 1.0f) {
            int n = (int)f;
            int i;
            l->count = 1;
            for (i = 0; i <= n; i++) {
                ThrEntry* ent;
                ThrMsg* msg;
                LGet(l, &b, &e);
                if (e.node == b.node) break;
                ent = l->head->entry;
                List_Erase(l, ThrLIt(l->head));
                printf(D_004C3430, now, ++D_00588030, it.node->key);
                Event_Send(ent->msg, ent->target, ent->flags);
                msg = ent->msg;
                {
                    AllocGuard guard;
                    msg->~ThrMsg();
                    Mem_Free(0, msg, D_004C3410, 0x32);
                }
                {
                    AllocGuard guard;
                    Mem_Free(0, ent, D_004C3410, 0x33);
                }
            }
        } else {
            l->count++;
        }
        Tree_Successor(&it);
    }
}
#undef func_00472070 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00472080 */

/* merge_units: begin func_00472370 */
#pragma push /* merge_units */
/* begin(): iterator at the first element. */
void func_00472370(Iter* out, PtrVec* v) {
    out->p = v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_00472370 */
