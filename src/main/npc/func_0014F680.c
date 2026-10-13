#pragma cplusplus on
#include "types.h"
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

extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
extern char g_ScriptAIDeadMsgKey[];
extern char D_004DCCF0[];
extern char D_004EA370[];
extern WTab_14F680 D_0049F790[];
extern void* Service_Lookup(void* a, void* b);
extern void NpcRoute_Release(void* mgr, Actor_14F680* a);
extern void Event_Construct(Msg_14F680* m, void* key);
extern void Event_Send(Msg_14F680* m, void* target, int flags);
extern void cMessage_dtor(Msg_14F680* m, int flags);
extern void Actor_RecordDeathStats(Actor_14F680* a, int killer, char how, int x);
extern int WeaponInv_IsFullAuto(int inv);
extern void WeaponInv_RandomizeDroppedAmmo(int inv);
extern void NpcPerception_Clear(Perc_14F680* p);
extern void NpcThinkList_RemoveActor(Actor_14F680* a);
extern void NpcAi_AddToDeadList(void* list, Npc_14F680** npc);

}

static inline WTab_14F680* WT_14F680(int i) { return &D_0049F790[i]; }
static inline bool Can_14F680(Wpn_14F680* w) { if (!w) return false; return WT_14F680(w->a)->ok && WT_14F680(w->b)->ok; }
extern "C" void cNPC_v1D(Npc_14F680* self, int unused, int killer, int x, char how)
{
    Actor_14F680* a = self->actor;
    if (a) {
        Msg_14F680 msg;
        bool ok;
        {
            void* mgr = Service_Lookup(D_004FFB50, g_NpcRouteMgr);
            NpcRoute_Release(mgr, self->actor);
        }
        Event_Construct(&msg, g_ScriptAIDeadMsgKey);
        msg.vtable = D_004DCCF0;
        msg.killer = killer;
        msg.how = how;
        {
            unsigned char* k = &msg.kind;
            *k = 2;
            *k = 2;
        }
        Event_Send(&msg, self->actor, 0);
        Actor_RecordDeathStats(a, killer, how, x);
        if (self->hp > 0 && self->t84 <= 0.0f) {
            Bits_14F680* b = &self->perc->bits;
            ok = b->b0 && b->b2;
            if (ok && WeaponInv_IsFullAuto(a->inv)) {
                ok = Can_14F680(a->weapon);
                if (ok) ((VNpc_14F680*)self)->s100(self->hp, -1, 0.0f);
            }
        }
        WeaponInv_RandomizeDroppedAmmo(a->inv);
        NpcPerception_Clear(self->perc);
        ok = a->f2D && a->f2C && !a->f2E && a->f3468;
        if (!ok) {
            Actor_14F680* b;
            NpcThinkList_RemoveActor(self->actor);
            b = self->actor;
            ok = b->f2D && b->f2C && !b->f2E;
            if (ok) NpcAi_AddToDeadList(D_004EA370, &self);
        }
        msg.vtable = D_004DCCF0;
        cMessage_dtor(&msg, 0);
    }
}




