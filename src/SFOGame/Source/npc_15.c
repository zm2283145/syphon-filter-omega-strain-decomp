/*
 * SFOGame/Source/npc: 27 files, 0014B100-0014BD60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014B100 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(func_0014B100, D_004D9360, cMessage_dtor)
static inline void merge_flush_func_0014B100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B100 */

/* merge_units: begin func_0014B160 */
#pragma push /* merge_units */
typedef struct { float m[3][4]; } R_B160;
typedef struct { __int128 q; } V_B160;
typedef struct { float m[3][4]; V_B160 p; } M_B160;
#pragma peephole off
M_B160* cMatrix_ctor_cMatrixR_cVectorR(M_B160* self, R_B160* r, V_B160* p)
{
    self->m[0][0] = r->m[0][0];
    self->m[0][1] = r->m[0][1];
    self->m[0][2] = r->m[0][2];
    self->m[1][0] = r->m[1][0];
    self->m[1][1] = r->m[1][1];
    self->m[1][2] = r->m[1][2];
    self->m[2][0] = r->m[2][0];
    self->m[2][1] = r->m[2][1];
    self->m[2][2] = r->m[2][2];
    self->m[0][3] = r->m[0][3];
    self->m[1][3] = r->m[1][3];
    self->m[2][3] = r->m[2][3];
    self->p = *p;
    return self;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B160 */

/* merge_units: begin func_0014B1E0 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_common_subs off
#pragma opt_propagation off
Vec4 cVector_Copy_WSet1(Vec4* src)
{
    Vec4 t;
    Vec4* p;
    t = *src;
    p = &t;
    p->w = 1.0f;
    return *p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B1E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B1E0 */

/* merge_units: begin func_0014B210 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern char g_IdentityMatrix[];

void* cMatrix_GetUnit(void) {
    return g_IdentityMatrix;
}
static inline void merge_flush_func_0014B210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B210 */

/* merge_units: begin func_0014B220 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E2Npc {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual unsigned char GetState(); /* +0x108 */
    char pad[8];
    int serial;
};
struct E2Handle { E2Npc* obj; int serial; };
struct E2Node { int f0; E2Node* next; E2Handle* handle; };
extern "C" void std_list_deleter_voidPtr_begin_void(int*, void*);
extern "C" void std_list_cActiveListItemPtr_generic_iterator_ctor(E2Node**, int*);
extern "C" void std_list_cActiveListItemPtr_end_void(int*, void*);
extern "C" void cLListIterator_cActiveListItemPtr_ctor(E2Node**, int*);
extern char g_NpcThinkList[];
static inline void E2End(E2Node** e) {
    int tmp;
    std_list_cActiveListItemPtr_end_void(&tmp, g_NpcThinkList);
    cLListIterator_cActiveListItemPtr_ctor(e, &tmp);
}
static inline int E2NonNull(E2Npc* p) { return p != 0; }
static inline bool E2Idle(unsigned char s) { return s == 2 || s == 3; }
static inline E2Npc* E2Get(E2Handle* h) {
    bool ok = true;
    if ((E2NonNull(h->obj) ^ 1) == 0 && h->obj->serial != h->serial) ok = false;
    return ok ? h->obj : 0;
}
extern "C" int cNPC_GetActiveNpcCount(void)
{
    E2Node* e;
    E2Node* it;
    int b;
    int count = 0;
    std_list_deleter_voidPtr_begin_void(&b, g_NpcThinkList);
    std_list_cActiveListItemPtr_generic_iterator_ctor(&it, &b);
    for (E2Node* n = it; E2End(&e), n != e; n = n->next) {
        if (!E2Idle(E2Get(n->handle)->GetState())) count++;
    }
    return count;
}
static inline void merge_flush_func_0014B220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B220 */

/* merge_units: begin func_0014B340 */
#pragma push /* merge_units */
extern int g_MaxActiveNpcCount;          /* maximum number of active NPCs */
extern int Actor_Ignite(NpcActor* actor, int a1, int a2, int a3, int a4, float f12);

/* Sets the maximum number of active NPCs. */
void cNPC_SetMaxActiveNpcCount(int count) {
    g_MaxActiveNpcCount = count;
}

/* vtable slot 0x5D: SetOnFire. */
int cNPC_SetOnFire(cNPC* self, float f12) {
    return Actor_Ignite(self->actor, 1, 0, 0, 0, f12);
}
static inline void merge_flush_func_0014B340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B340 */

/* merge_units: begin func_0014B370 */
#pragma push /* merge_units */
#pragma cplusplus on
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct KillActor_e8 {
    V4(v00) V4(v04) V4(v08) V4(v0C) V4(v10) V4(v14) V4(v18) V4(v1C)
    V4(v20) V4(v24) V4(v28) V4(v2C) V4(v30) V4(v34) V4(v38)
    virtual void v3C(); virtual void v3D();
    virtual void Damage(KillActor_e8*, int, int, int, int, int, float); /* 0x100 */
    virtual void v3F();
    virtual unsigned char GetState(); /* 0x108 */
    char pad4[0x3C];
    float health; /* 0x40 */
    char pad44[0x33A5 - 0x44];
    unsigned char flag33A5;
};
struct KillNPC_e8 { char pad[0x30]; KillActor_e8* actor; };
extern "C" void cNPC_Kill(KillNPC_e8* self)
{
    KillActor_e8* a = self->actor;
    if (a->GetState() != 3 || a->flag33A5) {
        KillActor_e8* b = self->actor;
        b->Damage(b, 2, 10, 0, 0, 0, (float)(int)a->health);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B370 */

/* merge_units: begin func_0014B410 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } Item_B410;
typedef struct {
    char pad[0x90]; float f90;
    char pad2[0x141 - 0x94];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; unsigned char b5 : 3;
    char pad3[0x1C8 - 0x142];
    Item_B410* item; int itemId;
} NPC_B410;
void cNPC_SetGrenadeTarget(NPC_B410* self, Item_B410* item, int flag, float f)
{
    int none;
    int* p;
    self->item = item;
    if (item)
        p = &item->id;
    else {
        none = -1;
        p = &none;
    }
    self->itemId = *p;
    self->f90 = f;
    self->b4 = flag;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B410 */

/* merge_units: begin func_0014B470 */
#pragma push /* merge_units */
#pragma cplusplus on
#define B8V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct B8_NPC {
    B8V8(a) B8V8(b) B8V8(c) B8V8(d) B8V8(e) B8V8(f) B8V8(g) B8V8(h) B8V8(i) B8V8(j) B8V8(k) B8V8(l)
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6();
    virtual int GetWeapon();      /* +0x1A4 */
    virtual void m8();
    virtual void SetWeapon(int w); /* +0x1AC */
    char pad4[0x8C - 4];
    float f8C;
    char pad90[0x12C - 0x90];
    int prevWeapon;
    int fireMode;
    int fireTime;
};
extern "C" void cNPC_ForceWeaponFire(B8_NPC* npc, int mode, int weapon, float time) {
    if (weapon < 0 || weapon == npc->GetWeapon()) {
        npc->prevWeapon = -1;
    } else {
        npc->prevWeapon = npc->GetWeapon();
        npc->SetWeapon(weapon);
    }
    npc->fireMode = mode;
    if (time == 0.0f) {
        npc->fireTime = (int)npc->f8C;
    } else {
        npc->fireTime = (int)time;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B470 */

/* merge_units: begin func_0014B550 */
#pragma push /* merge_units */
typedef struct { char pad[0x118]; int prio; char pad2[0x22]; char state; } NPC;
/* Sets the state when the given priority is at least the current one. */
void cNPC_SetFireMode(NPC* n, char state, int prio) { if (prio >= n->prio) { n->state = state; n->prio = prio; } }
static inline void merge_flush_func_0014B550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B550 */

/* merge_units: begin func_0014B570 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
struct TgtNV { char pad[0xC]; int serial; };
struct HandleNV {
    char pad[0x40];
    TgtNV* obj;
    int serial;
    bool IsValid() { return IsNullNV(obj) || obj->serial == serial; }
    TgtNV* Get() { return IsValid() ? obj : 0; }
};
struct NpcNV {
    char pad[0x44];
    char anim[8];
    int timer;
    char pad2[0x1AC - 0x50];
    HandleNV* target;
};
extern "C" void cStateMachine_ChangeState(void* a, int b, int c);
extern "C" void cNPC_ResumeAIMode(NpcNV* n)
{
    if (n->timer > 20) {
        n->timer = 0;
        if (n->target->Get()) {
            cStateMachine_ChangeState(n->anim, 1, 0);
        } else {
            cStateMachine_ChangeState(n->anim, 0, 0);
        }
    }
}
static inline void merge_flush_func_0014B570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B570 */

/* merge_units: begin func_0014B600 */
#pragma push /* merge_units */
/* vtable slot 0x42: SetAggressiveness. */
void cNPC_SetAggressiveness(cNPC* self, float value) {
    self->aggressiveness = value;
}
static inline void merge_flush_func_0014B600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B600 */

/* merge_units: begin func_0014B610 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; unsigned char x2C; unsigned char x2D; unsigned char x2E; char pad2[0x3468 - 0x2F]; unsigned char x3468; } Ctl_B610;
typedef struct {
    char pad[0x30]; Ctl_B610* ctl;
    char pad2[0x141 - 0x34];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 5;
} NPC_B610;
unsigned char Npc_IsCorpseRemovable(NPC_B610* self)
{
    unsigned char r = self->b2;
    Ctl_B610* c = self->ctl;
    if (c) {
        int v = c->x2D && c->x2C && !c->x2E && c->x3468;
        if (v)
            r = 0;
    }
    return r;
}
static inline void merge_flush_func_0014B610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B610 */

/* merge_units: begin func_0014B680 */
#pragma push /* merge_units */
typedef struct { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char flag : 1; } NpcBits;
typedef struct { char pad[0x30]; void* owner; char pad2[0x10D]; NpcBits bits; } cNPC_0014B680;

extern unsigned char g_IsMultiplayer; /* networked game */
extern unsigned char D_005721C0; /* is host */
extern void cNetNPCMsgs_SendMessage(void* owner, int type, int size, unsigned char a, int b, int c, int d);

static inline int IsAuthority(void)
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}

/* cNPC virtual 0x56: sets flag bit 2 and broadcasts it in network games. */
void cNPC_DeactivateDead(cNPC_0014B680* self, int on)
{
    self->bits.flag = on;
    if (g_IsMultiplayer && IsAuthority())
        cNetNPCMsgs_SendMessage(self->owner, 0x18, 4, (unsigned char)on, 0, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B680 */

/* merge_units: begin func_0014B700 */
#pragma push /* merge_units */
typedef struct cNPC_0014B700 {
    char pad[0x70];
    float rangeMin;
    float rangeMax;
    char pad2[0xAC - 0x78];
    int rangePriority;
} cNPC_0014B700;

/* vtable slot: sets a range center +- half width when priority >= current. */
void cNPC_SetDesiredDistance(cNPC_0014B700* self, int priority, float center, float width) {
    if (priority >= self->rangePriority) {
        float half = 0.5f * width;
        self->rangeMin = center - half;
        self->rangeMax = center + half;
        self->rangePriority = priority;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B700 */

/* merge_units: begin func_0014B740 */
#pragma push /* merge_units */
void cNPC_SetWeaponPreference(int a0, int a1, int a2) {
    int v1;
    int cond;

    v1 = a2 & 255;
    cond = v1 != 0;
    if (cond) goto L0014B758;
    *(int*)((char*)a0 + 176) = a1;
    goto L0014B760;
L0014B758:;
    *(int*)((char*)a0 + 180) = a1;
L0014B760:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B740 */

/* merge_units: begin func_0014B770 */
#pragma push /* merge_units */
typedef struct { char pad[0xB0]; int w0; int w1; } NPC_B770;
int cNPC_GetWeapon(NPC_B770* self, int which) { if ((unsigned char)which == 0) return self->w0; else return self->w1; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B770 */

/* merge_units: begin func_0014B790 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int seed; char pad2[0x3524 - 0x10]; void* inv; } Ctl_NPCW;
typedef struct { char pad[0x30]; Ctl_NPCW* ctl; char pad2[0xA4 - 0x34]; int burst; int burstCount; } NPC_W;
extern int cHuman_IsHoldingGun(Ctl_NPCW* c);
extern int Libc_Rand(void);
extern int cWeapon_GetClipSize(void* inv, int slot);
static inline void ResetBurst(NPC_W* self)
{
    Ctl_NPCW* c = self->ctl;
    if (cHuman_IsHoldingGun(c)) {
        void* inv = c->inv;
        self->burst = (self->ctl->seed & 7) + 3;
        if (Libc_Rand() & 1)
            self->burst++;
        if (self->burst > cWeapon_GetClipSize(inv, 6)) {
            int h = cWeapon_GetClipSize(inv, 6) / 2;
            if (h <= 0)
                h = 1;
            self->burst = h;
        }
    } else {
        self->burst = 0;
    }
    self->burstCount = 0;
}extern int cWeapon_GetWeaponSlot(int w);
extern void cWeapon_RemoveWeapon(void* inv, int slot, int a, int b, int c);
void cNPC_RemoveWeapon(NPC_W* self, int w)
{
    void* inv = self->ctl->inv;
    cWeapon_RemoveWeapon(inv, cWeapon_GetWeaponSlot(w), 0, 0, 0);
    ResetBurst(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B790 */

/* merge_units: begin func_0014B890 */
#pragma push /* merge_units */
extern int cWeapon_Add(NpcWeaponSet* weapons, int weapon, int a2, int a3, int a4, int a5);

/* vtable slot 0x6C: AddWeapon. */
int cNPC_AddWeapon(cNPC* self, int weapon) {
    NpcActor* actor;

    actor = self->actor;
    return cWeapon_Add(actor->weapons, weapon, 1, 0, 0, 0);
}
static inline void merge_flush_func_0014B890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B890 */

/* merge_units: begin func_0014B8B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
static inline void UM(void* m) { void* p = m; int t; asm { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx;
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
extern "C" {
#if 0 /* merge_units */
int cHuman_IsHoldingGun(void*);
#endif /* merge_units */
#define cHuman_IsHoldingGun(a0) (cHuman_IsHoldingGun((Ctl_NPCW *)(a0))) /* merge_units */

int cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(void*, int, int);
int cWeapon_HasAnyWeapons(int);
int Libc_Rand(void);
#if 0 /* merge_units */
int cWeapon_GetClipSize(int, int);
#endif /* merge_units */
#define cWeapon_GetClipSize(a0, a1) (cWeapon_GetClipSize((void *)(a0), (a1))) /* merge_units */

void cWeapon_InitBackpack(int, int);

void cNPC_DropWeapon(char* self) {
    char* a = F_(self, 0x30, char*);
    int inv = F_(a, 0x3524, int);
    if (cWeapon_HasAnyWeapons(inv)) {
        Mtx m;
        UM(&m);
        cWeapon_InitBackpack(inv, cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(a, 0, 0));
    }
    a = F_(self, 0x30, char*);
    if (cHuman_IsHoldingGun(a)) {
        int w = F_(a, 0x3524, int);
        F_(self, 0xA4, int) = (F_(F_(self, 0x30, char*), 0xC, unsigned short) & 7) + 3;
        if (Libc_Rand() & 1) {
            F_(self, 0xA4, int)++;
        }
        int c = F_(self, 0xA4, int);
        if (cWeapon_GetClipSize(w, 6) < c) {
            int n = cWeapon_GetClipSize(w, 6) / 2;
            F_(self, 0xA4, int) = (n <= 0) ? 1 : n;
        }
    } else {
        F_(self, 0xA4, int) = 0;
    }
    F_(self, 0xA8, int) = 0;
}
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B8B0(void) {}
#undef cHuman_IsHoldingGun /* merge_units */
#undef cWeapon_GetClipSize /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014B8B0 */

/* merge_units: begin func_0014B9E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x84]; unsigned char cur; } Inv_B9E0;
extern void cWeapon_SelectNext(Inv_B9E0* inv, int wrap);
void cNPC_ChangeWeapon(NPC_W* self)
{
    Inv_B9E0* inv = (Inv_B9E0*)self->ctl->inv;
    cWeapon_SelectNext(inv, 1);
    if (inv->cur == 6)
        cWeapon_SelectNext(inv, 1);
    ResetBurst(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B9E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B9E0 */

/* merge_units: begin func_0014BAE0 */
#pragma push /* merge_units */
extern void cWeapon_Select(void* inv, int w);
extern void cWeapon_DrawWeapon_void(void* inv);
void cNPC_DrawWeapon(NPC_W* self, int w)
{
    Ctl_NPCW* c = self->ctl;
    if (w >= 0)
        cWeapon_Select(c->inv, w);
    else
        cWeapon_DrawWeapon_void(c->inv);
    ResetBurst(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BAE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BAE0 */

/* merge_units: begin func_0014BBD0 */
#pragma push /* merge_units */
extern void cWeapon_StoreWeapon_void(void* inv);
void cNPC_StoreWeapon(NPC_W* self)
{
    cWeapon_StoreWeapon_void(self->ctl->inv);
    ResetBurst(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BBD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BBD0 */

/* merge_units: begin func_0014BCB0 */
#pragma push /* merge_units */
typedef struct { int a0; int a4; int id; int ac; } Slot_BCB0;
typedef struct { Slot_BCB0 s[8]; char pad[4]; unsigned char cur; } Inv_BCB0;
typedef struct { char pad[0x3524]; Inv_BCB0* inv; } Ctl_BCB0;
typedef struct { char pad[0x30]; Ctl_BCB0* ctl; } NPC_BCB0;
int cNPC_GetActiveWeapon(NPC_BCB0* self) { Inv_BCB0* inv = self->ctl->inv; if (inv->cur != 6) return inv->s[inv->cur].id; return -1; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BCB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BCB0 */

/* merge_units: begin func_0014BCE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* vtable slot 0x59: SetFiringThreshold; returns the previous value. */
float cNPC_SetFiringThreshold(cNPC* self, float threshold) {
    float old;

    old = self->firingThreshold;
    self->firingThreshold = threshold;
    return old;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BCE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BCE0 */

/* merge_units: begin func_0014BCF0 */
#pragma push /* merge_units */
typedef struct Target78 {
    char pad00[0x78];
    int id; /* 0x78 */
} Target78;

typedef struct cNPC_35 {
    char pad000[0x44];
    char state44[0xFB];      /* 0x044 */
    unsigned char kind;      /* 0x13F */
    char pad140[0x70];
    void* brain;             /* 0x1B0 */
} cNPC_35;

#if 0 /* merge_units */
extern void cStateMachine_ChangeState(void* state, int kind, int value);
#endif /* merge_units */
#define cStateMachine_ChangeState(a0, a1, a2) ((void)cStateMachine_ChangeState((a0), (a1), (a2))) /* merge_units */

extern void cPathNavigator_Request_int(void* brain, int id);

/* cNPC virtual 0x35: records an event kind (< 7) and forwards the target. */
void cNPC_SetMode(cNPC_35* self, int kind, Target78* target) {
    if ((unsigned char)kind < 7) {
        cStateMachine_ChangeState(self->state44, (unsigned char)kind, 100);
        if (target) {
            self->kind = kind;
            cPathNavigator_Request_int(self->brain, target->id);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BCF0(void) {}
#undef cStateMachine_ChangeState /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014BCF0 */

/* merge_units: begin func_0014BD60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class Obj_BD60 {
public:
    VPAD32(a) VPAD32(b)
    virtual unsigned char GetState();
    char pad[0x8];
    int id;
    char pad2[0x48];
    void* x58;
};
typedef struct { char pad[0x78]; int x78; } Src_BD60;
typedef struct { char pad[0x44]; int mode; char pad2[0xF0 - 0x48]; int xF0; int xF4; } NPC_BD60;
#if 0 /* merge_units */
extern "C" void cStateMachine_ChangeState(int* mode, int m, int t);
#endif /* merge_units */
#define cStateMachine_ChangeState(a0, a1, a2) (cStateMachine_ChangeState((void *)(a0), (a1), (a2))) /* merge_units */

extern "C" int cNPC_CarryBodyToNode(NPC_BD60* self, Obj_BD60* o, Src_BD60* src)
{
    unsigned char s = o->GetState();
    unsigned char ok = 1; if ((unsigned)(s - 2) > 1) ok = 0;
    if (ok && o->x58 && self->mode != 8) {
        cStateMachine_ChangeState(&self->mode, 8, 100);
        self->xF0 = src->x78;
        self->xF4 = o->id;
    }
    return 0;
}
#undef cStateMachine_ChangeState /* merge_units */
static inline void merge_flush_func_0014BD60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014BD60 */
