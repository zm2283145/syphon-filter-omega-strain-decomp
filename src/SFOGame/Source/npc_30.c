/*
 * SFOGame/Source/npc: 5 files, 0014F610-0014FA00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014F610 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void cAIWeaponFiredMsg_Clone();
extern "C" void cAIWeaponFiredMsg_getSOBJClassId();
extern "C" void cAIGOBJMsg_Pack();
extern void * const D_004DCBF0[];
extern char D_004DCD70[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cAIWeaponFiredMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DCBF0);
        if (self) {
            self->vtable = D_004DCD70;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DCBF0[8] = { (void*)0x0, (void*)0x0, (void*)cAIWeaponFiredMsg_dtor, (void*)cAIWeaponFiredMsg_Clone, (void*)cAIGOBJMsg_Pack, (void*)cAIWeaponFiredMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014F610 */

/* merge_units: begin func_0014F680 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VNpc_14F680 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100(int, int, float);
};
extern "C" {

typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad21[3];
    int killer;
    char how;
} Msg_14F680;

typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
} Bits_14F680;

typedef struct { char pad[0x20]; Bits_14F680 bits; } Perc_14F680;
typedef struct { char pad[0x4C]; unsigned char ok; char pad4D[3]; } WTab_14F680;
typedef struct { char pad[0x310]; unsigned char a; unsigned char b; } Wpn_14F680;

typedef struct {
    char pad0[0x2C];
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    char pad2F[0x3314 - 0x2F];
    Wpn_14F680* weapon;
    char pad3318[0x3468 - 0x3318];
    unsigned char f3468;
    char pad3469[0x3524 - 0x3469];
    int inv;
} Actor_14F680;

typedef struct Npc_14F680 {
    void** vtable;
    char pad4[0x2C];
    Actor_14F680* actor;
    char pad34[0x50];
    float t84;
    char pad88[0x20];
    int hp;
    char padAC[0x100];
    Perc_14F680* perc;
} Npc_14F680;

extern char g_Game[];
extern char g_NpcRouteMgr[];
extern char g_ScriptAIDeadMsgKey[];
extern char D_004DCCF0[];
extern char g_NpcDeadList[];
extern WTab_14F680 SecondaryStateTable[];
extern void* cSystemContainer_GetSystem(void* a, void* b);
extern void cPathSystem_ClearRequests(void* mgr, Actor_14F680* a);
extern void cMessage_ctor_cMessageNameR(Msg_14F680* m, void* key);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_14F680* m, void* target, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg_14F680* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


extern void cHuman_UpdateStats(Actor_14F680* a, int killer, char how, int x);
extern int cWeapon_IsFullyAutomatic(int inv);
extern void cWeapon_SetAmmoNpcDeath(int inv);
extern void cAITarget_dtor(Perc_14F680* p);
extern void cNPC_RemoveFromActiveList(Actor_14F680* a);
extern void std_list_cNPCPtr_push_back(void* list, Npc_14F680** npc);

}

static inline WTab_14F680* WT_14F680(int i) { return &SecondaryStateTable[i]; }
static inline bool Can_14F680(Wpn_14F680* w) { if (!w) return false; return WT_14F680(w->a)->ok && WT_14F680(w->b)->ok; }
extern "C" void cNPC_NoticeDeath(Npc_14F680* self, int unused, int killer, int x, char how)
{
    Actor_14F680* a = self->actor;
    if (a) {
        Msg_14F680 msg;
        bool ok;
        {
            void* mgr = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
            cPathSystem_ClearRequests(mgr, self->actor);
        }
        cMessage_ctor_cMessageNameR(&msg, g_ScriptAIDeadMsgKey);
        msg.vtable = D_004DCCF0;
        msg.killer = killer;
        msg.how = how;
        {
            unsigned char* k = &msg.kind;
            *k = 2;
            *k = 2;
        }
        QueueMessage_cMessageR_cSystemP_int(&msg, self->actor, 0);
        cHuman_UpdateStats(a, killer, how, x);
        if (self->hp > 0 && self->t84 <= 0.0f) {
            Bits_14F680* b = &self->perc->bits;
            ok = b->b0 && b->b2;
            if (ok && cWeapon_IsFullyAutomatic(a->inv)) {
                ok = Can_14F680(a->weapon);
                if (ok) ((VNpc_14F680*)self)->s100(self->hp, -1, 0.0f);
            }
        }
        cWeapon_SetAmmoNpcDeath(a->inv);
        cAITarget_dtor(self->perc);
        ok = a->f2D && a->f2C && !a->f2E && a->f3468;
        if (!ok) {
            Actor_14F680* b;
            cNPC_RemoveFromActiveList(self->actor);
            b = self->actor;
            ok = b->f2D && b->f2C && !b->f2E;
            if (ok) std_list_cNPCPtr_push_back(g_NpcDeadList, &self);
        }
        msg.vtable = D_004DCCF0;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F680(void) {}
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F680 */

/* merge_units: begin func_0014F910 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cAIDeadMsg_dtor, D_004DCCF0, cMessage_dtor)
static inline void merge_flush_func_0014F910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F910 */

/* merge_units: begin func_0014F970 */
#pragma push /* merge_units */
/* NPC message object (vtable, base data, parameters). */
typedef struct NpcMsg {
    void* vtable;
    char base[0x20];
    unsigned char mode;
    char pad[3];
    int target;
    char pad2[4];
} NpcMsg;

typedef struct cNPC {
    char pad[0x1AC];
    int ai;
} cNPC;

extern void cAITarget_AddAwareness(int ai, int arg, int mode, float value);
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(NpcMsg* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Msg_14F680 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(NpcMsg* msg, cNPC* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((Msg_14F680 *)(a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(NpcMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern char D_004EE550[];
extern char D_004D9340[]; /* AI mode message vtable */

/* cNPC vtable slot 0x1C: switches the AI to mode 8 and notifies itself. */
void cNPC_NoticeDamage(cNPC* self, int arg) {
    NpcMsg msg;
    cAITarget_AddAwareness(self->ai, arg, 8, 0.0f);
    cMessage_ctor_cMessageNameR(&msg, D_004EE550);
    msg.vtable = D_004D9340;
    msg.mode = 8;
    msg.target = -1;
    QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
    msg.vtable = D_004D9340;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0014F970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F970 */

/* merge_units: begin func_0014FA00 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#include "vslot_pad.h"

struct HObj4FA {
    char pad[0xC];
    int id;
};

struct Handle4FA {
    HObj4FA* obj;
    int id;
};

struct Node4FA {
    int unk0;
    Node4FA* next;
    Handle4FA* h;
};

class Ctl4FA {
public:
    VPAD32(p) VPAD32(q)
    virtual unsigned char GetMode();
};

struct Inner4FA {
    char pad[0x58];
    int owner;
};

class Npc4FA {
public:
    VPAD32(p)
    virtual unsigned char GetState();
    char pad[0x2C];
    Ctl4FA* ctl;
    char pad34[0xE0 - 0x34];
    int resA;
    int resB;
    char padE8[0x1B0 - 0xE8];
    Inner4FA* inner;
};

struct Obj4FA {
    char pad[0x58];
    Npc4FA* npc;
};

extern "C" {
extern Tree g_NpcThinkList;
extern void std_list_cActiveListItemPtr_begin_void(Iter* out, Tree* t);
extern Word* cLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src);
extern void std_list_cActiveListItemPtr_end_void(Iter* out, Tree* t);
}

static inline void FCopy4FA(float* d, float* s) { float* ss = s; float* dd = d; *dd = *ss; }

extern "C" Ctl4FA* cNPC_IsNodeOccupied(int node)
{
    Node4FA* it;
    int tmp;
    Word w;
    Word w2;
    Iter b;
    Iter end;
    Ctl4FA* result = 0;

    std_list_cActiveListItemPtr_begin_void(&b, &g_NpcThinkList);
    cLListIterator_cActiveListItemPtr_ctor(&w, (Word*)&b);
    { int v = w.value; tmp = v; }
    FCopy4FA((float*)&it, (float*)&tmp);
    std_list_cActiveListItemPtr_end_void(&end, &g_NpcThinkList);
    cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&end);
    while (*(int*)&it != w2.value) {
        unsigned char valid;
        Handle4FA* h;
        HObj4FA* o;
        int isnull;
        h = it->h;
        o = h->obj;
        isnull = (o != 0) ^ 1;
        valid = 1;
        if (!isnull && o->id != h->id) {
            valid = 0;
        }
        if (valid ? o : 0) {
            if (o && o->id != h->id) {
                o = 0;
            }
            if (((Obj4FA*)o)->npc->GetState() == 1) {
                Npc4FA* npc;
                unsigned char v3;
                Handle4FA* h3;
                HObj4FA* o3;
                int n3;
                h3 = it->h;
                o3 = h3->obj;
                n3 = (o3 != 0) ^ 1;
                v3 = 1;
                if (!n3 && o3->id != h3->id) {
                    v3 = 0;
                }
                npc = ((Obj4FA*)(v3 ? o3 : 0))->npc;
                if (npc->ctl->GetMode() != 3) {
                    if (node == npc->resB || node == npc->resA || node == npc->inner->owner) {
                        result = npc->ctl;
                        break;
                    }
                }
            }
        }
        it = it->next;
        std_list_cActiveListItemPtr_end_void(&end, &g_NpcThinkList);
        cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&end);
    }
    return result;
}
static inline void merge_flush_func_0014FA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014FA00 */
