#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    V& operator-=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; const V& Pos() const { return r[3]; } };
static inline void SubEq(V* d, const V* a, const V* b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void Copy(V* d, const V* s) { __int128 t = *(__int128*)s; *(__int128*)d = t; }
static inline float Len(V* p) {
    float len;
    len = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2 %0, vf4" : "=r"(len) : "r"(p) : "memory");
    return len;
}
class Actor;
class Ctrl {
public:
    VPAD16(a) VPAD4(b)
    virtual int IsNpc();
    virtual int IsOther();
    VPAD16(c) VPAD8(d) VPAD4(e)
    virtual void Hear(char kind, Actor* who, float dist);
};
class Actor {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    virtual M GetMtx();
    VPAD4(f) VPAD2(h) VPAD1(i)
    virtual unsigned char State();
    char pad04[0x8];
    int id;
    char pad10[0x1C];
    unsigned char enabled;
    unsigned char active;
    unsigned char streaming;
    char pad2F[0x29];
    Ctrl* ctrl;
};
struct Hnd { Actor* p; int id; };
static inline bool IdEq(Actor* p, Hnd* h) { return p->id == h->id; }
static inline Actor* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct Grenade { char pad[0x124]; Hnd mThrower; };
struct Human { char pad[0x33AC]; float deafTimer; };
struct Awareness { char pad[0x38]; unsigned char inViewcone; unsigned char los; };
struct Npc : Ctrl { };
struct NpcF { char pad[0x1AC]; void* target; };
struct Msg {
    void* vt;
    char pad04[0x20];
    unsigned char type;
    unsigned char kind;
    char pad26[6];
    float radius;
    int objectId;
    int toObjectId;
    char pad38[8];
    V position;
};
struct MName { int id; };
struct LNode { LNode* prev; LNode* next; Hnd* value; };
union It { LNode* p; };
struct Sys;
extern "C" {
extern MName D_004EE5C8;
extern char g_NpcThinkList[];
MName* cMessage_Name(Msg* m);
Actor* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
unsigned char cSystem_HandleMessage(Sys* s, Msg* m);
Human* cNPC_Human(Npc* n);
Awareness* cAITarget_GetAwareness(void* t, Actor* a);
void std_list_cActiveListItemPtr_begin_void_2(It* r, void* l);
void std_list_cActiveListItemPtr_end_void_2(It* r, void* l);
void cConstLListIterator_cActiveListItemPtr_ctor(It* d, It* s);
}
static inline bool Downed(Actor* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
static inline bool IsNpc(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->IsNpc()) r = true; return r; }
static inline bool IsOther(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->IsOther()) r = true; return r; }
static inline bool Alive(Actor* a) { bool r = 0; if (a->active && a->enabled) r = 1; return r; }
static inline bool Live(Actor* a) { return !a->streaming; }
static inline bool Targetable(Actor* a) { bool r = 0; if (Alive(a) && Live(a)) r = 1; return r; }
static inline bool NotEnd(It& it, void* l, It& t2, It& t3) { std_list_cActiveListItemPtr_end_void_2(&t2, l); cConstLListIterator_cActiveListItemPtr_ctor(&t3, &t2); return it.p != t3.p; }
static inline It Begin(void* l) { It t; std_list_cActiveListItemPtr_begin_void_2(&t, l); It r; cConstLListIterator_cActiveListItemPtr_ctor(&r, &t); return r; }
static inline It End(void* l) { It t; std_list_cActiveListItemPtr_end_void_2(&t, l); It r; cConstLListIterator_cActiveListItemPtr_ctor(&r, &t); return r; }

extern "C" unsigned char cAISoundSystem_HandleMessage(Sys* self, Msg* message)
{
    unsigned char res = 1;
    unsigned char soundHeard = 0;
    MName* nm = cMessage_Name(message);
    if (nm->id == D_004EE5C8.id) {
        Msg& msg = *message;
        Actor* who = nGobjManager_LookupGOBJ_cObjectIdR(&msg.objectId);
        if (who) {
            if (msg.type == 2) {
                Actor* gobj = nGobjManager_LookupGOBJ_cObjectIdR(&msg.toObjectId);
                if (msg.kind == 7) {
                    if (IsNpc(gobj) || IsOther(gobj))
                        gobj->ctrl->Hear(msg.kind, who, 0.0f);
                }
            } else {
                void* activeList = g_NpcThinkList;
                It it; It t1; It t3; It t0; It t2;
                std_list_cActiveListItemPtr_begin_void_2(&t0, activeList);
                cConstLListIterator_cActiveListItemPtr_ctor(&t1, &t0);
                it = t1;
                for (; NotEnd(it, activeList, t2, t3); it.p = it.p->next) {
                    Actor* gobj = HGet(it.p->value);
                    if (!gobj) continue;
                    if (gobj->id == msg.objectId) continue;
                    if (Downed(gobj)) continue;
                    if (!IsNpc(gobj)) continue;
                    Npc* npc = (Npc*)gobj->ctrl;
                    if (cNPC_Human(npc)->deafTimer <= 0.0f) {
                        V delta(gobj->GetMtx().Pos());
                        if (msg.type == 0) {
                            delta -= who->GetMtx().Pos();
                        } else {
                            delta -= msg.position;
                        }
                        float distance = Len(&delta);
                        if (distance < msg.radius)
                            npc->Hear(msg.kind, who, distance);
                    }
                    if (!soundHeard && msg.kind == 5) {
                        Grenade* grenade = (Grenade*)who;
                        Actor* thrower = HGet(&grenade->mThrower);
                        if (thrower && Targetable(thrower) && HGet(&grenade->mThrower) != gobj) {
                            Awareness* awareness = cAITarget_GetAwareness(((NpcF*)npc)->target, thrower);
                            if (awareness && awareness->los && awareness->inViewcone)
                                npc->Hear(msg.kind, who, 0.0f);
                        }
                    }
                }
            }
        }
    } else {
        res = cSystem_HandleMessage(self, message);
    }
    return res;
}
