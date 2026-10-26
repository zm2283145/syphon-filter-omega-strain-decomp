#pragma cplusplus on
#include "types.h"
/* Pickup_PerformAction: hand the backpack's weapons (with their clips/spares, possibly as a dual
   pair), its ammo and its held item to the player, with a pickup sound and HUD notices. */
struct V4_254DA0 {
    float x, y, z, w;
    V4_254DA0() {}
    V4_254DA0(const V4_254DA0& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
} __attribute__((aligned(16)));
struct Str_254DA0 { char d[0x9C]; };
struct Str2_254DA0 { char d[0xAC]; };
extern "C" void FileMan_Release(void* s, int flags);
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
    __declspec(weak) __declspec(DTOR_DROP_254DA0) ~SndMsg_254DA0() { vtbl = D_004DAE30; if (&req) { /* the request part's teardown tests its address */ FileMan_Release(&req.b, -1); FileMan_Release(&req.a, -1); } }
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
extern int g_WeaponDatabase;
extern int g_Hud;
extern char g_Game[];
extern int g_HotboxTracker;
extern char D_004A7B18[];
extern char D_004A7B20[];
extern char D_004A7B30[];
extern char D_004F1AF0[];
extern char D_004F17B0[];
extern char D_004F1C90[];
extern char D_004DAE30[];
int Backpack_ListItems(Bp_254DA0* p, int* ids, Inv_254DA0* inv, int max);
unsigned char Backpack_TakeItem(Bp_254DA0* p, int id, int remove);
int WeaponInv_SlotOfItem(int id);
void* Agent_GetSelected(char* game, int i);
int AgentData_HasUnlock(void* agent, int what);
void Backpack_QueryAmmo(Bp_254DA0* p, int id, int* a, int* b, int* c);
char* WeaponDb_Get(int db, int id);
char* Loc_LookupText(char* key);
void WeaponInv_Add(Inv_254DA0* inv, int id, int a, int b, int c, int d);
void WeaponInv_SetClip(Inv_254DA0* inv, int slot, int n, int z);
void WeaponInv_AddSpare(Inv_254DA0* inv, int slot, int n, int z);
int sprintf(char* buf, const char* fmt, ...);
void Hud_PostNotification(int hud, char* text);
void WeaponInv_DualShare(Inv_254DA0* inv);
void SoundPosRequest_Ctor(void* m, char* req, V4_254DA0* pos);
void Event_Send(void* msg, void* target, int immediate);
void FileMan_Release(void* s, int flags);
void cMessage_dtor(void* msg, int flags);
unsigned char Backpack_PickupAmmo(Bp_254DA0* p, Inv_254DA0* inv);
void Object_Register(Bp_254DA0* p);
Hot_254DA0* Hotbox_CreateRuntime(int mgr, Bp_254DA0* p, int a, int b);
void Backpack_Finish(Bp_254DA0* p);
void Pickup_PerformAction(Bp_254DA0* self, Player_254DA0* pl);
}


static inline bool IsPrimary_254DA0(unsigned char s) { return s == 0; }
static inline int ItemAt_254DA0(Inv_254DA0* inv, unsigned char s) { return inv->slots[s].id; }
static inline bool HasDual_254DA0(Inv_254DA0* inv) { return inv->dual >= 0; }
void Pickup_PerformAction(Bp_254DA0* self, Player_254DA0* pl)
{
    if (self->open) {
        int spare;
        int clip;
        int extra;
        int ids[10];
        char buf[0x80];
        Inv_254DA0* inv = pl->inv;
        int n = Backpack_ListItems(self, ids, inv, 10);
        int db = g_WeaponDatabase;
        bool played = false;
        V4_254DA0 pos = pl->GetPos(-1);
        int i;
        for (i = 0; i < n; i++) {
            if (Backpack_TakeItem(self, ids[i], 1)) {
                int slot = WeaponInv_SlotOfItem(ids[i]);
                bool dualOk;
                bool same;
                int have;
                bool first;
                have = ItemAt_254DA0(inv, slot);
                first = IsPrimary_254DA0(slot);
                same = have == ids[i];
                dualOk = HasDual_254DA0(inv);
                unsigned char hasDual = first && dualOk;
                bool dual = first && !hasDual && same && AgentData_HasUnlock(Agent_GetSelected(g_Game, -1), 1);
                char* name;
                Backpack_QueryAmmo(self, ids[i], &spare, &clip, &extra);
                name = Loc_LookupText(WeaponDb_Get(db, ids[i]) + 0x80);
                if (dual)
                    slot = 1;
                if (have < 0 || dual) {
                    WeaponInv_Add(inv, ids[i], 0, 0, 0, 0);
                    WeaponInv_SetClip(inv, slot, clip, 0);
                    WeaponInv_AddSpare(inv, slot, spare, 0);
                    Backpack_TakeItem(self, ids[i], 0);
                    sprintf(buf, D_004A7B18, name, Loc_LookupText(D_004A7B20));
                    Hud_PostNotification(g_Hud, buf);
                    WeaponInv_DualShare(inv);
                    if (!played) {
                        SndMsg_254DA0 m1;
                        SoundPosRequest_Ctor(&m1, D_004F1AF0, &pos);
                        m1.flag = 1;
                        Event_Send(&m1, g_Game, 0);
                        played = true;
                    }
                }
            }
        }
        if (Backpack_PickupAmmo(self, inv)) {
            WeaponInv_DualShare(inv);
            if (!played) {
                SndMsgP_254DA0 m2;
                SoundPosRequest_Ctor(&m2, D_004F17B0, &pos);
                m2.flag = 1;
                Event_Send(&m2, g_Game, 0);
                m2.vtbl = D_004DAE30;
                played = true;
                FileMan_Release(&m2.req[0xE4], -1);
                FileMan_Release(&m2.req[0x48], -1);
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
                        Object_Register(self);
                        if (!self->hot) {
                            self->hot = Hotbox_CreateRuntime(g_HotboxTracker, self, 0, 1);
                            self->hot->id = self->id;
                        }
                    }
                }
                if (!played) {
                    SndMsgP_254DA0 m3;
                    SoundPosRequest_Ctor(&m3, D_004F1C90, &pos);
                    m3.flag = 1;
                    Event_Send(&m3, g_Game, 0);
                    m3.vtbl = D_004DAE30;
                    FileMan_Release(&m3.req[0xE4], -1);
                    FileMan_Release(&m3.req[0x48], -1);
                    cMessage_dtor(&m3, 0);
                }
                { int hud = g_Hud; Hud_PostNotification(hud, Loc_LookupText(D_004A7B30)); }
            }
        }
    }
    if (!self->keep)
        Backpack_Finish(self);
}
