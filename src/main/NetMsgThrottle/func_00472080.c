#pragma cplusplus on

#include "types.h"
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
void func_00472070(ThrIt* r, void* map);
ThrIt func_00471EA0(void* map);
void func_00471E90(ThrIt* r, const ThrIt& s);
ThrLIt func_00472370(ThrList* l);
ThrLIt func_00472060(ThrList* l);
void func_00472050(ThrLIt* r, const ThrLIt& s);
ThrLIt func_00138DA0(ThrList* l, const ThrLIt& pos);
int func_0042B1A0(int);
void printf(char* fmt, ...);
void Event_Send(ThrMsg* msg, void* target, int flags);
void Tree_Successor(void* it);
void Mem_Free(int pool, void* p, char* file, int line);
}

static inline void LGet(ThrList* l, ThrLIt* b, ThrLIt* e)
{
    func_00472050(b, func_00472370(l));
    func_00472050(e, func_00472060(l));
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
    now = func_0042B1A0(1);
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
                func_00138DA0(l, ThrLIt(l->head));
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







