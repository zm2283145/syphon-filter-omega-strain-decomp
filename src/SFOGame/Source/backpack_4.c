/*
 * SFOGame/Source/backpack: 3 files, 00254990-00254DA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00254990 */
#pragma push /* merge_units */
#include "types.h"

#pragma cplusplus on

struct Entry {
    int amount[4];
    int extra[4];
    int item;
    int n;
};

struct Slot {
    unsigned char kind;
    Entry e[5];
    int count;
    unsigned char flag;
};

struct Owner_00254990 { char pad0[0xC]; int id; };

struct BP {
    char pad00[0x60];
    unsigned char b60;
    char pad61[3];
    Slot slots[3];
    char pad2E0[4];
    int x2E4;
    char pad2E8[0x2F1 - 0x2E8];
    unsigned char b2F1;
    char pad2F2[0x2FC - 0x2F2];
    void* fx;
    Owner_00254990* holder;
    int holderId;
    bool Free() { return !x2E4; }
    bool NoHolder() { return !Holder(); }
    Owner_00254990* Holder() { bool n = !holder; return (n || holder->id == holderId) ? holder : 0; }
};

extern "C" {
extern int g_WeaponDatabase;
extern int g_HotboxTracker;
int cWeapon_GetWeaponSlot(int id);
void* cWeaponDB_GetEntry(int db, int item);
int cHuman_CanPackBeDeleted(Owner_00254990* o);
void cHotboxMan_RemoveHotbox(int, void*);
int nGobjManager_RemoveGOBJ(void*);
int cSystem_ActualScheduleDelete(void*, float);
void cBackpack_Remove(BP* bp);
}

static inline bool HolderReady(BP* bp) {
    bool r = true;
    if (!bp->NoHolder() && !cHuman_CanPackBeDeleted(bp->Holder())) r = false;
    return r;
}

extern "C" void cBackpack_CheckForRemoval(BP* bp) {
    Slot* s;
    int i;
    bool ok;
    bool all;
    for (i = 0, s = bp->slots; i < 3; i++, s++) {
        Entry* e = s->e;
        int j;
        for (j = 0; j < s->count; j++, e++) {
            if ((unsigned char)cWeapon_GetWeaponSlot(e->item) == 4 && (e->n == 0 || e->amount[e->n - 1] == 0)) {
                j--;
                *e-- = s->e[--s->count];
            }
        }
    }
    ok = false;
    if (bp->Free()) {
        if (HolderReady(bp)) ok = true;
    }
    all = ok;
    if (ok) {
        int i2;
        Entry* e;
        Slot* s2;
        for (s2 = bp->slots, i2 = 0; all && i2 < 3; i2++, s2++) {
            if (s2->flag && !bp->b2F1) {
                all = false;
            } else if (s2->count) {
                int j;
                e = s2->e;
                cWeaponDB_GetEntry(g_WeaponDatabase, s2->e[0].item);
                for (j = 0; all && j < s2->count; j++, e++) {
                    if (e->n) all = false;
                }
            }
        }
    }
    if (all) {
        if (bp->b60 == 1) {
            if (bp->fx) {
                cHotboxMan_RemoveHotbox(g_HotboxTracker, bp->fx);
                nGobjManager_RemoveGOBJ(bp->fx);
                cSystem_ActualScheduleDelete(bp->fx, 0.1f);
                bp->fx = 0;
            }
        } else {
            cBackpack_Remove(bp);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00254990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00254990 */

/* merge_units: begin func_00254CA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int id; } Ent_4CA0;
typedef struct { union { unsigned char type; Ent_4CA0 ents[5]; } u; int pad; int count; unsigned char flag; char pad2[3]; } Slot_4CA0;
typedef struct { char pad[0x64]; Slot_4CA0 slots[3]; } Pack_4CA0;
#if 0 /* merge_units */
extern int cWeapon_GetWeaponSlot(int key);
#endif /* merge_units */
#define cWeapon_GetWeaponSlot(a0) (cWeapon_GetWeaponSlot((a0))) /* merge_units */


#pragma opt_rotateloops off

int cBackpack_GetNextWeapon(Pack_4CA0* s, int id, int back)
{
    Slot_4CA0* p; int i;
    int t;
     t = cWeapon_GetWeaponSlot(id); p = s->slots;
    i = 0;
    for (; i < 3; i++, p++) {
        if (p->u.type == (unsigned char)t) {
            int j = 0;
            if (j < p->count) {
                do {
                    if ((void*)p->u.ents[j].id == (void*)id) {
                        j += back ? -1 : 1;
                        if (j < 0) j = p->count - 1;
                        else if (j >= p->count) j = 0;
                        return p->u.ents[j].id;
                    }
                    j++;
                } while (j < p->count);
            }
        }
    }
    return id;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00254CA0(void) {}
#undef cWeapon_GetWeaponSlot /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00254CA0 */

/* merge_units: begin func_00254DA0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cBackpack_AutoPickup: hand the backpack's weapons (with their clips/spares, possibly as a dual
   pair), its ammo and its held item to the player, with a pickup sound and HUD notices. */
struct V4_254DA0 {
    float x, y, z, w;
    V4_254DA0() {}
    V4_254DA0(const V4_254DA0& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
} __attribute__((aligned(16)));
struct Str_254DA0 { char d[0x9C]; };
struct Str2_254DA0 { char d[0xAC]; };
extern "C" void cFileMan_dtor(void* s, int flags);
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" char D_004DAE30[];
#pragma define_section DTOR_DROP_254DA0 ".dtors_drop" far_absolute RX
struct Req_254DA0 {
    char pad0[0x48]; Str_254DA0 a; Str2_254DA0 b;
};
struct MsgBase_254DA0 {
    void* vtbl; char pad4[0x1C]; unsigned char flag; char pad21[0xF];
    __declspec(weak) __declspec(DTOR_DROP_254DA0) ~MsgBase_254DA0() { cMessage_dtor(this, 0); }
};
struct SndMsgP_254DA0 { void* vtbl; char pad4[0x1C]; unsigned char flag; char pad21[0xF]; char req[0x190]; };
struct SndMsg_254DA0 : MsgBase_254DA0 {
    Req_254DA0 req;
    __declspec(weak) __declspec(DTOR_DROP_254DA0) ~SndMsg_254DA0() { vtbl = D_004DAE30; if (&req) { /* the request part's teardown tests its address */ cFileMan_dtor(&req.b, -1); cFileMan_dtor(&req.a, -1); } }
};
struct Slot_254DA0 { int a; int b; int id; int c; };
struct Inv_254DA0 { Slot_254DA0 slots[1]; char pad10[0x18 - 0x10]; int dual; };
struct Player_254DA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual V4_254DA0 GetPos(int node);
    char pad4[0x339C - 0x4];
    int heldType;   /* 0x339C */
    int heldCount;  /* 0x33A0 */
    char pad33A4[0x3524 - 0x33A4];
    Inv_254DA0* inv; /* 0x3524 */
};
struct Hot_254DA0 { char pad[0x94]; int id; };
struct Bp_254DA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void SetActive(int on);
    char pad4[0xC - 0x4];
    int id;            /* 0xC */
    char pad10[0x2E4 - 0x10];
    int stack;         /* 0x2E4 */
    int stackCount;    /* 0x2E8 */
    int stackType;     /* 0x2EC */
    unsigned char open;   /* 0x2F0 */
    unsigned char keep;   /* 0x2F1 */
    char pad2F2[0x2FC - 0x2F2];
    Hot_254DA0* hot;   /* 0x2FC */
};
extern "C" {
extern int g_Hud;
extern char g_Game[];
extern char D_004A7B18[];
extern char D_004A7B20[];
extern char D_004A7B30[];
extern char D_004F1AF0[];
extern char D_004F17B0[];
extern char D_004F1C90[];
#if 0 /* merge_units */
extern char D_004DAE30[];
#endif /* merge_units */
#define D_004DAE30 ((char*)&D_004DAE30) /* merge_units */

int cBackpack_GetWeaponDbs(Bp_254DA0* p, int* ids, Inv_254DA0* inv, int max);
unsigned char cBackpack_TakeWeapon(Bp_254DA0* p, int id, int remove);
void* cGameSystem_GetAgentData(char* game, int i);
int cAgentData_HasSpecialBonus(void* agent, int what);
void cBackpack_GetAmmoCounts(Bp_254DA0* p, int id, int* a, int* b, int* c);
#if 0 /* merge_units */
char* cWeaponDB_GetEntry(int db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((char *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

char* nGlobalization_GetString_charP(char* key);
void cWeapon_Add(Inv_254DA0* inv, int id, int a, int b, int c, int d);
void cWeapon_PickupClip(Inv_254DA0* inv, int slot, int n, int z);
void cWeapon_PickupAmmo_eWpnSlot_int_bool(Inv_254DA0* inv, int slot, int n, int z);
int sprintf(char* buf, const char* fmt, ...);
void cHud_Message(int hud, char* text);
void cWeapon_EqualizeDualWieldAmmo(Inv_254DA0* inv);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(void* m, char* req, V4_254DA0* pos);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
#if 0 /* merge_units */
void cFileMan_dtor(void* s, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (a1))) /* merge_units */

unsigned char cBackpack_AutoTakeAmmo(Bp_254DA0* p, Inv_254DA0* inv);
void nGobjManager_AddGOBJ(Bp_254DA0* p);
Hot_254DA0* cHotboxMan_CreateInteractBox(int mgr, Bp_254DA0* p, int a, int b);
void cBackpack_Unlock(Bp_254DA0* p);
void cBackpack_AutoPickup(Bp_254DA0* self, Player_254DA0* pl);
}


static inline bool IsPrimary_254DA0(unsigned char s) { return s == 0; }
static inline int ItemAt_254DA0(Inv_254DA0* inv, unsigned char s) { return inv->slots[s].id; }
static inline bool HasDual_254DA0(Inv_254DA0* inv) { return inv->dual >= 0; }
void cBackpack_AutoPickup(Bp_254DA0* self, Player_254DA0* pl)
{
    if (self->open) {
        int spare;
        int clip;
        int extra;
        int ids[10];
        char buf[0x80];
        Inv_254DA0* inv = pl->inv;
        int n = cBackpack_GetWeaponDbs(self, ids, inv, 10);
        int db = g_WeaponDatabase;
        bool played = false;
        V4_254DA0 pos = pl->GetPos(-1);
        int i;
        for (i = 0; i < n; i++) {
            if (cBackpack_TakeWeapon(self, ids[i], 1)) {
                int slot = cWeapon_GetWeaponSlot(ids[i]);
                bool dualOk;
                bool same;
                int have;
                bool first;
                have = ItemAt_254DA0(inv, slot);
                first = IsPrimary_254DA0(slot);
                same = have == ids[i];
                dualOk = HasDual_254DA0(inv);
                unsigned char hasDual = first && dualOk;
                bool dual = first && !hasDual && same && cAgentData_HasSpecialBonus(cGameSystem_GetAgentData(g_Game, -1), 1);
                char* name;
                cBackpack_GetAmmoCounts(self, ids[i], &spare, &clip, &extra);
                name = nGlobalization_GetString_charP(cWeaponDB_GetEntry(db, ids[i]) + 0x80);
                if (dual)
                    slot = 1;
                if (have < 0 || dual) {
                    cWeapon_Add(inv, ids[i], 0, 0, 0, 0);
                    cWeapon_PickupClip(inv, slot, clip, 0);
                    cWeapon_PickupAmmo_eWpnSlot_int_bool(inv, slot, spare, 0);
                    cBackpack_TakeWeapon(self, ids[i], 0);
                    sprintf(buf, D_004A7B18, name, nGlobalization_GetString_charP(D_004A7B20));
                    cHud_Message(g_Hud, buf);
                    cWeapon_EqualizeDualWieldAmmo(inv);
                    if (!played) {
                        SndMsg_254DA0 m1;
                        cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&m1, D_004F1AF0, &pos);
                        m1.flag = 1;
                        QueueMessage_cMessageR_cSystemP_int(&m1, g_Game, 0);
                        played = true;
                    }
                }
            }
        }
        if (cBackpack_AutoTakeAmmo(self, inv)) {
            cWeapon_EqualizeDualWieldAmmo(inv);
            if (!played) {
                SndMsgP_254DA0 m2;
                cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&m2, D_004F17B0, &pos);
                m2.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&m2, g_Game, 0);
                m2.vtbl = D_004DAE30;
                played = true;
                cFileMan_dtor(&m2.req[0xE4], -1);
                cFileMan_dtor(&m2.req[0x48], -1);
                cMessage_dtor(&m2, 0);
            }
        }
        {
            int cnt = self->stack ? self->stackCount : 0;
            if (pl->heldCount < cnt) {
                int oldCount = pl->heldCount;
                int oldType = pl->heldType;
                int c, t;
                if (self->stack) {
                    self->stack--;
                    c = self->stackCount;
                    t = self->stackType;
                } else {
                    c = 0;
                    t = 0;
                }
                /* retail stores the type into the count slot before the count itself */
                pl->heldType = t;
                pl->heldCount = t;
                pl->heldCount = c;
                if (oldCount) {
                    if (self->stack++ == 0) {
                        self->stackCount = oldCount;
                        self->stackType = oldType;
                    }
                    if (!self->hot) {
                        self->SetActive(1);
                        nGobjManager_AddGOBJ(self);
                        if (!self->hot) {
                            self->hot = cHotboxMan_CreateInteractBox(g_HotboxTracker, self, 0, 1);
                            self->hot->id = self->id;
                        }
                    }
                }
                if (!played) {
                    SndMsgP_254DA0 m3;
                    cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&m3, D_004F1C90, &pos);
                    m3.flag = 1;
                    QueueMessage_cMessageR_cSystemP_int(&m3, g_Game, 0);
                    m3.vtbl = D_004DAE30;
                    cFileMan_dtor(&m3.req[0xE4], -1);
                    cFileMan_dtor(&m3.req[0x48], -1);
                    cMessage_dtor(&m3, 0);
                }
                { int hud = g_Hud; cHud_Message(hud, nGlobalization_GetString_charP(D_004A7B30)); }
            }
        }
    }
    if (!self->keep)
        cBackpack_Unlock(self);
}
#undef D_004DAE30 /* merge_units */
#undef cWeaponDB_GetEntry /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00254DA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00254DA0 */
