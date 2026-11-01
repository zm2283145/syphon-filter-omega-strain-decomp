#pragma cplusplus on
#include "types.h"

struct cVector_251920 { float x, y, z, w; cVector_251920() {} cVector_251920(const cVector_251920& o) { x = o.x; y = o.y; z = o.z; w = o.w; } } __attribute__((aligned(16)));
struct H_251920 { int v; };
struct Act_251920 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_251920 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct EMsg_251920 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Msg_251920 {
    void* vtbl;
    char pad04[0x18];
    int w1C;
    unsigned char flag;
    unsigned char b21;
    char pad22[2];
    int w24;
    int w28;
    int w2C;
};
struct Human_251920;
struct Slot_251920 { int unk0; int unk4; int weapon; int unkC; };
struct Weapon_251920 {
    Slot_251920 slots[8];
    char pad80[4];
    signed char cur;
    char pad85[0xA4 - 0x85];
    int wA4;
};
struct Obj58_251920 {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void u53();
    virtual void u54();
    virtual void u55();
    virtual void u56();
    virtual void u57();
    virtual void u58();
    virtual void u59();
    virtual void u60();
    virtual void u61();
    virtual void u62();
    virtual void u63();
    virtual void u64();
    virtual void u65();
    virtual void u66();
    virtual void u67();
    virtual void u68();
    virtual void u69();
    virtual void u70();
    virtual void u71();
    virtual void u72();
    virtual void u73();
    virtual void u74();
    virtual void u75();
    virtual void u76();
    virtual void u77();
    virtual void u78();
    virtual void u79();
    virtual void u80();
    virtual void u81();
    virtual void u82();
    virtual void u83();
    virtual void u84();
    virtual void u85();
    virtual void u86();
    virtual void u87();
    virtual void u88();
    virtual void u89();
    virtual void u90();
    virtual void u91();
    virtual void u92();
    virtual void u93();
    virtual void u94();
    virtual void u95();
    virtual void u96();
    virtual void u97();
    virtual void u98();
    virtual void u99();
    virtual void u100();
    virtual void u101();
    virtual void u102();
    virtual void u103();
    virtual void u104();
    virtual void u105();
    virtual void u106();
    virtual void u107();
    virtual void u108();
    virtual void u109();
    virtual void u110();
    virtual void u111();
    virtual void u112();
    virtual void u113();
    virtual void u114();
    virtual void u115();
    virtual void Notify(int a, int b);
};
struct Target_251920 {
    char pad0[0xC];
    int serial;
    char pad10[0x58 - 0x10];
    Obj58_251920* obj58;
    char pad5C[0x3528 - 0x5C];
    void* items;
};
struct Human_251920 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual cVector_251920 GetPosition(int bone = -1);
    char pad04[0x339C - 0x4];
    int armor;
    int initialArmor;
    char pad33A4[0x3524 - 0x33A4];
    Weapon_251920* inv;
    void* items;
};
struct Owner_251920 {
    char pad0[0x60];
    unsigned char net;
    char pad61[0x300 - 0x61];
    Target_251920* target;
    int serial;
};
struct WeaponDef_251920 {
    char pad0[0x30];
    unsigned char kind;
    char pad31[0x80 - 0x31];
    char name[0xF0 - 0x80];
    unsigned char type;
};
struct Item_251920 {
    unsigned char kind;
    char pad1[3];
    int id;
    int ammo;
    void* icon;
    void* icon2;
    void* label;
    void* label2;
};
struct Self_251920 {
    Owner_251920* owner;
    Item_251920 items[5];
    int count;
    int sel;
    int x;
};

extern "C" {
extern int g_WeaponDatabase;
extern char g_Game[];
extern void* g_Hud;
extern unsigned char g_IsMultiplayer;
extern char g_ActorActionMsgClass[];
extern char D_004A79B8[];
extern char D_004DAE30[];
extern char D_004F17B0[];
extern char D_004F1AF0[];
extern char D_004F7EA0[];
extern char D_004DC480[];
extern char D_004DCF10[];
extern char D_004A79D0[];
extern char D_004A79C8[];
extern char D_004E01A0[];
extern char D_004E0840[];
extern char D_004FF2B8[];
extern char D_004DCC50[];
extern char D_004DCD70[];
extern char D_004F7EE0[];
extern char D_004DC460[];
extern int D_005721A8;
extern int D_00494178;
extern char D_005061B0[];
extern char D_004DCEF0[];
void cFileMan_ctor_void(void* m);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void cMessage_ctor_cMessageNameR(void* msg, void* name);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
void cSndFx_SetSndFx(void* action, int kind, char* name, int a, int b);
void EffectMsg_WrapRequest(EMsg_251920* msg, void* action);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(EMsg_251920* msg, void* snd, cVector_251920* pos);
int cWeapon_GetWeaponSlot(int id);
bool cBackpack_TakeWeapon(Owner_251920* o, int id, int which);
bool cBackpack_SlotIsReplaceable(Owner_251920* o, int id);
int cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_HasSpecialBonus(int agent, int what);
void cBackpack_GetAmmoCounts(Owner_251920* o, int id, int* a, int* b, int* c);
int cWeapon_PickupAmmo_eWpnSlot_int_bool(Weapon_251920* w, int slot, int ammo, int b);
void cBackpack_TakeAmmo(Owner_251920* o, int id, int ammo);
int cWeapon_GetAmmo(Weapon_251920* w, int slot);
int cWeapon_GetClipAmmo(Weapon_251920* w, int slot);
void cWeapon_RemoveWeapon(Weapon_251920* w, int slot, int a, int b, int c);
WeaponDef_251920* cWeaponDB_GetEntry(int db, int id);
void cWeapon_Add(Weapon_251920* w, int id, int a, int b, int c, int d);
void cWeapon_PickupClip(Weapon_251920* w, int slot, int clip, int b);
int cBackpack_GetNextWeapon(Owner_251920* o, int id, int which);
char* nGlobalization_GetString_charP(char* key);
int sprintf(char* buf, const char* fmt, ...);
void cHud_Message(void* hud, char* msg);
void cWeapon_DrawWeapon_eWpnSlot(Weapon_251920* w, int slot);
void cBackpack_SetHasTakenPlayerItems(Owner_251920* o);
void cBackpack_AddWeapon(Owner_251920* o, int id, int ammo, int clip, int b);
void cHuman_EquipGoggles(Human_251920* h, int on);
void cBackpack_TakeFlakJacket(Owner_251920* o, int* armor, int* initial);
void cBackpack_AddFlakJacket(Owner_251920* o, int armor, int initial);
int cInventory_Remove_int_int_bool(void* items, int id, int n, int b);
void cInventory_Add_int_int_bool(void* items, int id, int n, int b);
char* cInventory_GetShortName(int id);
void cBackpack_AutoTakeAmmo(Owner_251920* o, Weapon_251920* w);
void cWeapon_EqualizeDualWieldAmmo(Weapon_251920* w);
void NetGetMyClientIndex(int* p, int x);
}

static inline Target_251920* Handle_Get(Owner_251920* h) {
    bool isNull;
    bool ok;
    Target_251920* t;
    t = h->target;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->serial != h->serial) ok = false;
    return ok ? t : 0;
}

static inline int DB() { int t = g_WeaponDatabase; return t; }
static inline void SafeNull(H_251920* dst)
{
    H_251920 h;
    H_251920* hp;
    hp = (H_251920*)((char*)&h + 0);
    hp = (H_251920*)((int)hp);
    h.v = -1;
    *dst = *hp;
}
static inline void InvMsgCtor(Msg_251920* m, int id, int n, Human_251920* h)
{
    cMessage_ctor_cMessageNameR(m, D_004F7EE0);
    m->vtbl = D_004DC460;
    m->w24 = id;
    m->w28 = n;
    m->flag = 2;
    m->w1C = 64;
    m->w2C = (int)h;
}
static inline void NetMsgCtor(Msg_251920* m, Owner_251920* pk, int idx)
{
    cMessage_ctor_cMessageNameR(m, D_005061B0);
    m->vtbl = D_004DCEF0;
    m->w28 = (int)pk;
    m->flag = 4;
    m->w2C = idx;
    *(unsigned char*)&m->w24 = 0;
}
static inline int MyIdx(int net)
{
    if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, net);
    return D_00494178;
}
static inline int GetIdx(int net)
{
    return g_IsMultiplayer ? MyIdx(net) : 0;
}
static inline void PlaySnd(Act_251920* snd)
{
    EMsg_251920 m;
    EffectMsg_WrapRequest(&m, snd);
    m.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
    m.vtbl = D_004DAE30;
    cFileMan_dtor(m.partB, -1);
    cFileMan_dtor(m.partA, -1);
    cMessage_dtor(&m, 0);
}

#pragma push
extern "C" bool cPickupMenu_AcceptChoices(Self_251920* self, Human_251920* human)
{
    bool finished;
    int db;
    bool hasLeftWpn;
    bool packHasWeapon;
    Item_251920* entry;
    int slot;
    Weapon_251920* inv;

    db = DB();
    inv = human->inv;
    finished = false;
    cVector_251920 humanPos = human->GetPosition();
    Act_251920 sound;
    bool isHolsterWpn;
    char* pb;
    bool sameWpn;
    char* pa;
    int packAmmo;
    int packClipAmmo;
    int packTotalAmmo;
    {
        Act_251920* p;
        p = (Act_251920*)((char*)&sound + 0);
        sound.h24.v = -2;
        pa = sound.memberA;
        sound.w20 = 0;
        cFileMan_ctor_void(pa);
        pb = sound.memberB;
        cFileMan_ctor_void(pb);
        p->id = -1;
        p->mask = -1;
        p->w20 = 0;
        SafeNull(&p->h24);
        p->w30 = 0;
        p->w34 = 0;
        p->w38 = 0;
        p->h184 = -1;
        p->w180 = 0;
        p->b186 = 0;
        cSndFx_SetSndFx(p, 3, D_004A79B8, 0, 0);
        PlaySnd(&sound);
    }
    entry = &self->items[self->sel];
    if (0 == entry->kind) {
        unsigned char uslot;
        bool dual;
        bool unlocked;
        slot = cWeapon_GetWeaponSlot(entry->id);
        if (self->x) {
            slot = inv->cur;
            if ((unsigned char)slot >= 6) {
                cFileMan_dtor(pb, -1);
                cFileMan_dtor(pa, -1);
                return true;
            }
        }
        uslot = slot;
        int curWpn = inv->slots[uslot].weapon;
        isHolsterWpn = uslot == 0;
        hasLeftWpn = 0 <= inv->slots[1].weapon;
        dual = isHolsterWpn && hasLeftWpn;
        packHasWeapon = cBackpack_TakeWeapon(self->owner, entry->id, 1);
        sameWpn = packHasWeapon && curWpn == entry->id;
        if (sameWpn && cBackpack_SlotIsReplaceable(self->owner, entry->id)) {
            packHasWeapon = sameWpn = false;
        }
        unlocked = isHolsterWpn && !dual && sameWpn && cAgentData_HasSpecialBonus(cGameSystem_GetAgentData(g_Game, -1), 1);
        cBackpack_GetAmmoCounts(self->owner, entry->id, &packAmmo, &packClipAmmo, &packTotalAmmo);
        if (sameWpn && !unlocked && packHasWeapon) {
            int taken = cWeapon_PickupAmmo_eWpnSlot_int_bool(inv, slot, packTotalAmmo, 0);
            cBackpack_TakeAmmo(self->owner, entry->id, taken);
            if (taken) {
                EMsg_251920 msg;
                cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, D_004F17B0, &humanPos);
                msg.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                if (self->owner->net == 1) {
                    Msg_251920 msg2;
                    cMessage_ctor_cMessageNameR(&msg2, D_004F7EA0);
                    msg2.vtbl = D_004DC480;
                    msg2.w2C = (int)human;
                    msg2.w24 = -1;
                    msg2.w28 = -1;
                    msg.flag = 2;
                    QueueMessage_cMessageR_cSystemP_int(&msg2, self->owner, 0);
                    msg2.vtbl = D_004DCF10;
                    cMessage_dtor(&msg2, 0);
                }
                msg.vtbl = D_004DAE30;
                cFileMan_dtor(msg.partB, -1);
                cFileMan_dtor(msg.partA, -1);
                cMessage_dtor(&msg, 0);
            }
        } else if (entry->id > -1) {
            int oldAmmo;
            bool dualDrop;
            int oldClipAmmo;
            int taken;
            bool wasActive;
            int given;
            oldClipAmmo = 0;
            oldAmmo = 0;
            bool dropped = !sameWpn && curWpn > -1;
            dualDrop = isHolsterWpn && hasLeftWpn;
            taken = -1;
            wasActive = uslot == (unsigned char)inv->cur;
            given = -1;
            if (dropped) {
                oldAmmo = cWeapon_GetAmmo(inv, slot);
                oldClipAmmo = cWeapon_GetClipAmmo(inv, slot);
                if (dualDrop) {
                    cWeapon_RemoveWeapon(inv, 1, 0, 0, 0);
                    oldAmmo /= 2;
                    oldClipAmmo /= 2;
                }
                cWeapon_RemoveWeapon(inv, slot, 0, 0, 0);
            }
            if (packHasWeapon) {
                EMsg_251920 msg;
                WeaponDef_251920* dbEntry;
                int ammoTaken;
                int otherWpn;
                char* wpnName;
                char strbuff[128];
                cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, D_004F1AF0, &humanPos);
                msg.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                dbEntry = cWeaponDB_GetEntry(db, entry->id);
                if (unlocked) slot = 1;
                cWeapon_Add(inv, entry->id, 0, 0, 0, 0);
                cWeapon_PickupClip(inv, slot, packClipAmmo, 0);
                ammoTaken = cWeapon_PickupAmmo_eWpnSlot_int_bool(inv, slot, packAmmo, 0);
                otherWpn = cBackpack_GetNextWeapon(self->owner, entry->id, 0);
                if (dbEntry->type == 1) {
                    cBackpack_TakeAmmo(self->owner, entry->id, ammoTaken);
                } else {
                    cBackpack_TakeWeapon(self->owner, entry->id, 0);
                }
                taken = entry->id;
                wpnName = nGlobalization_GetString_charP(dbEntry->name);
                sprintf(strbuff, D_004A79C8, wpnName, nGlobalization_GetString_charP(D_004A79D0));
                cHud_Message(g_Hud, strbuff);
                if (wasActive && dropped) cWeapon_DrawWeapon_eWpnSlot(inv, slot);
                if (!cBackpack_TakeWeapon(self->owner, entry->id, 1)) entry->id = otherWpn;
                msg.vtbl = D_004DAE30;
                cFileMan_dtor(msg.partB, -1);
                cFileMan_dtor(msg.partA, -1);
                cMessage_dtor(&msg, 0);
            }
            if (dropped) {
                cBackpack_SetHasTakenPlayerItems(self->owner);
                cBackpack_AddWeapon(self->owner, curWpn, oldAmmo, oldClipAmmo, 0);
                entry->id = curWpn;
                given = curWpn;
                if (cWeaponDB_GetEntry(db, curWpn)->kind == 6) cHuman_EquipGoggles(human, 0);
                if (dualDrop) cBackpack_AddWeapon(self->owner, curWpn, oldAmmo, oldClipAmmo, 0);
            }
            if (taken >= 0 || given >= 0) {
                if (self->owner->net == 1) {
                    Msg_251920 msg;
                    cMessage_ctor_cMessageNameR(&msg, D_004F7EA0);
                    msg.w24 = taken;
                    msg.w2C = (int)human;
                    msg.vtbl = D_004DC480;
                    msg.flag = 2;
                    msg.w28 = given;
                    QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
                    msg.vtbl = D_004DCF10;
                    cMessage_dtor(&msg, 0);
                }
                if (given) human->inv->wA4 = -1;
                if (self->x > 0) finished = true;
            }
        }
    } else if (entry->kind == 2) {
        int newArmor;
        int newInitialArmor;
        int initialArmor = human->initialArmor;
        int armor = human->armor;
        if (self->owner->net == 1) {
            Msg_251920 msg;
            cMessage_ctor_cMessageNameR(&msg, D_004F7EA0);
            msg.vtbl = D_004DC480;
            msg.w2C = (int)human;
            msg.w24 = -1;
            msg.w28 = -1;
            msg.flag = 2;
            QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
            msg.vtbl = D_004DCF10;
            cMessage_dtor(&msg, 0);
        }
        cBackpack_TakeFlakJacket(self->owner, &newArmor, &newInitialArmor);
        { int ni = newInitialArmor; human->armor = ni; human->initialArmor = ni; }
        human->initialArmor = newArmor;
        cBackpack_AddFlakJacket(self->owner, initialArmor, armor);
        if (initialArmor) cBackpack_SetHasTakenPlayerItems(self->owner);
    } else if (entry->kind == 3) {
        Target_251920* o = Handle_Get(self->owner);
        if (o) {
            Msg_251920 message;
            cMessage_ctor_cMessageNameR(&message, g_ActorActionMsgClass);
            message.w24 = 43;
            *(unsigned char*)&message.w28 = 5;
            message.vtbl = D_004E01A0;
            message.w2C = o->serial;
            message.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&message, human, 0);
            message.vtbl = D_004E0840;
            cMessage_dtor(&message, 0);
        }
        finished = true;
    } else if (entry->kind == 4) {
        Target_251920* o = Handle_Get(self->owner);
        if (o) {
            Obj58_251920* x = o->obj58;
            Msg_251920 msg;
            if (x) x->Notify(0, 1);
            cMessage_ctor_cMessageNameR(&msg, D_004FF2B8);
            msg.w24 = (int)human;
            msg.flag = 2;
            msg.vtbl = D_004DCC50;
            msg.flag = 2;
            msg.w1C = 64;
            QueueMessage_cMessageR_cSystemP_int(&msg, o, 0);
            msg.vtbl = D_004DCD70;
            cMessage_dtor(&msg, 0);
        }
        finished = true;
    } else if (entry->kind == 5) {
        if (entry->ammo == 0) {
            char* itemName;
            char strbuff[128];
            entry->ammo = cInventory_Remove_int_int_bool(Handle_Get(self->owner)->items, entry->id, 10000, 0);
            cInventory_Add_int_int_bool(human->items, entry->id, entry->ammo, 0);
            itemName = cInventory_GetShortName(entry->id);
            sprintf(strbuff, D_004A79C8, itemName, nGlobalization_GetString_charP(D_004A79D0));
            cHud_Message(g_Hud, strbuff);
            {
                Msg_251920 msg;
                InvMsgCtor(&msg, entry->id, entry->ammo, human);
                QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
                msg.vtbl = D_004DCF10;
                cMessage_dtor(&msg, 0);
            }
        }
    }
    cBackpack_AutoTakeAmmo(self->owner, inv);
    cWeapon_EqualizeDualWieldAmmo(inv);
    if (g_IsMultiplayer && self->x) {
        Msg_251920 msg;
        NetMsgCtor(&msg, self->owner, GetIdx(D_005721A8));
        QueueMessage_cMessageR_cSystemP_int(&msg, human, 0);
        msg.vtbl = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
    cFileMan_dtor(pb, -1);
    cFileMan_dtor(pa, -1);
    return finished;
}
#pragma pop
