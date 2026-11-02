/*
 * SFOGame/Source/npc: 34 files, 0014B100-0014D270
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
#if 0 /* merge_units */
extern "C" void cStateMachine_ChangeState(void* a, int b, int c);
#endif /* merge_units */
extern "C" int cStateMachine_ChangeState(void* obj, int a1, int a2); /* merge_units */
#define cStateMachine_ChangeState(a0, a1, a2) ((void)cStateMachine_ChangeState((a0), (a1), (a2))) /* merge_units */

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
#undef cStateMachine_ChangeState /* merge_units */
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
#if 0 /* merge_units */
extern int cHuman_IsHoldingGun(Ctl_NPCW* c);
#endif /* merge_units */
int cHuman_IsHoldingGun(void*); /* merge_units */
#define cHuman_IsHoldingGun(a0) (cHuman_IsHoldingGun((void *)(a0))) /* merge_units */

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
#undef cHuman_IsHoldingGun /* merge_units */
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
int cHuman_IsHoldingGun(void*);

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
#define cStateMachine_ChangeState(a0, a1, a2) ((void)cStateMachine_ChangeState((void *)(a0), (a1), (a2))) /* merge_units */


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

/* merge_units: begin func_0014BE10 */
#pragma push /* merge_units */
extern int cStateMachine_ChangeState(void* obj, int a1, int a2);

typedef struct NpcMoveGobj {
    char pad00[0xC];
    int id;                         /* 0x0C */
} NpcMoveGobj;

typedef struct NpcMoveNode {
    char pad00[0x78];
    int id;                         /* 0x78 */
} NpcMoveNode;

/* vtable slot 0x3F: MoveToGobj. */
int cNPC_MoveToGobj(cNPC* self, NpcMoveGobj* gobj) {
    self->moveTargetGobj = gobj->id;
    self->moveTargetNode = -1;
    cStateMachine_ChangeState(self->unk044, 7, 100);
    return 1;
}

/* vtable slot 0x3E: MoveToNode. */
int cNPC_MoveToNode(cNPC* self, NpcMoveNode* node) {
    cStateMachine_ChangeState(self->unk044, 7, 100);
    self->moveTargetNode = node->id;
    self->moveTargetGobj = -1;
    return 1;
}
static inline void merge_flush_func_0014BE10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014BE10 */

/* merge_units: begin func_0014BEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class NPC_BEA0 {
public:
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD16(d) VPAD8(e) VPAD4(f)
    virtual void OnClear();
    char pad[0xB8];
    int bits[9];
};
extern "C" void cNPC_RestrictMovementToNodeGroup(NPC_BEA0* self, int notify)
{
    int i;
    for (i = 0; i < 9; i++)
        self->bits[i] = 0;
    if (notify)
        self->OnClear();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BEA0 */

/* merge_units: begin func_0014BF00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Bits_0014BF00 {
    int w[8];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
    void set(int n) { w[n / 32] |= 1 << (n & 31); }
    void reset(int n) { w[n / 32] &= ~(1 << (n & 31)); }
};
typedef struct { char pad[0x7C]; int id; } Obj_0014BF00;
typedef struct { char pad[0xBC]; Bits_0014BF00 bits; } NPC_0014BF00;
extern "C" void cNPC_RemoveGroupFromPathRegion(NPC_0014BF00* self, Obj_0014BF00* o)
{
    int id = o->id;
    if (self->bits.test(id)) self->bits.reset(id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BF00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BF00 */

/* merge_units: begin func_0014BF60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Bits_0014BF60 {
    int w[8];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
    void set(int n) { w[n / 32] |= 1 << (n & 31); }
    void reset(int n) { w[n / 32] &= ~(1 << (n & 31)); }
};
typedef struct { char pad[0x7C]; int id; } Obj_0014BF60;
typedef struct { char pad[0xBC]; Bits_0014BF60 bits; } NPC_0014BF60;
extern "C" void cNPC_AddGroupToPathRegion(NPC_0014BF60* self, Obj_0014BF60* o)
{
    int id = o->id;
    if (!self->bits.test(id)) self->bits.set(id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BF60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BF60 */

/* merge_units: begin func_0014BFB0 */
#pragma push /* merge_units */
typedef struct { char pad[0xBC]; int bits[8]; } S_BFB0;
unsigned char cNPC_GroupInPathRegion(S_BFB0* self, int i)
{
    unsigned char r = 1;
    if (i >= 0)
        r = ((self->bits[i / 32] >> (i & 31)) & 1) != 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BFB0 */

/* merge_units: begin func_0014BFF0 */
#pragma push /* merge_units */
/* 0014BFF0 cNPC::UpdateMovement() (npc.cc). Rebuilt from the prototype DWARF/.line data (lines 5611-5980); retail
 * rewrote the transport/terrain block near the start and added the weapon-type facing branch (taken from the retail asm).
 * Message temporaries/locals are C++ classes with weak inline destructors (.dtors_drop). VU0 operations, lq/sq quad
 * copies and abs.s/min.s are inline asm because MW has no C spelling for them. */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma enumsalwaysint off

struct cVector;
/* 128-bit copy: lq/sq have no C spelling in MW (a struct copy is split into words). */
static inline void CopyV(cVector* d, const cVector* s)
{
    cVector* dp = d; const cVector* sp = s;
    __int128 t;
    __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(sp));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(dp) : "memory");
}
/* VU0 vsub: no C equivalent */
static inline void SubC(cVector* r, const cVector* a, const cVector* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { CopyV(this, &o); }
    cVector& operator=(const cVector& o) { CopyV(this, &o); return *this; }
    cVector operator-(const cVector& b) const { cVector r; SubC(&r, this, &b); return r; }
    void Zero() { cVector* p = this; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(p) : "memory"); }
    /* VU0 normalise (vrsqrt): no C equivalent */
    void Normalize() { NormP(this); }
    static void NormP(cVector* p0)
    {
        cVector* p = p0;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory");
    }
    /* VU0 length squared: no C equivalent */
    float LengthSq() { return LsqP(this); }
    static float LsqP(const cVector* p0)
    {
        float r = 0.0f;
        int t;
        const cVector* p = p0;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2 %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(p) : "memory");
        return r;
    }
    /* VU0 zero test (vaddx + clip flags): no C equivalent */
    unsigned char IsZero()
    {
        int k, fl;
        int r = 0;
        const cVector* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni fl, vi17
            bne k, fl, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
} __attribute__((aligned(16)));
extern "C" float Libc_Atan2f(float, float);
struct cNetHuman;
struct cMatrix { cVector r0, r1, r2, t; const cVector& T() const { return t; } float Z() const { return t.z; } const cVector& R1() const { return r1; } float HeadingZ() const { return Libc_Atan2f(-r1.x, r1.y); } void ToNet(cNetHuman& n) const; };
/* abs.s / min.s have no C spelling in MW */
static inline float Fabs(float x) { float r = 0.0f; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float MinF(float a, float b) { float r = 0.0f; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

enum eMoveMode { MM_0 = 0, MM_1 = 1, MM_MAX = 0x7F };
struct cObjectId { int mId; bool operator==(const cObjectId& o) const { return mId == o.mId; } };
struct cGOBJ;
struct cSafePtr {
    cGOBJ* ptr;
    cObjectId id;
    bool IsValid() const;
    cGOBJ* Get() const { return IsValid() ? ptr : 0; }
};
struct cNetHuman { char pad[0x3C]; float speed; float rotZ; float x, y, z; };
inline void cMatrix::ToNet(cNetHuman& n) const { n.x = t.x; n.y = t.y; n.z = t.z; }
struct tSecondaryState { char pad[0x4C]; unsigned char aims; char pad4D[0x50 - 0x4D]; };
struct cHumanIkRoutine { char pad[0x310]; unsigned char mode0; unsigned char mode1; };
struct cGOBJ {
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
    virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
    virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19(); virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23();
    virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29(); virtual void g30(); virtual void g31();
    virtual void g32(); virtual void g33(); virtual void g34(); virtual void g35(); virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39();
    virtual void g40(); virtual void g41(); virtual void g42(); virtual void g43(); virtual void g44(); virtual void g45();
    virtual cVector GetBonePos(int bone);          /* 0xC0 */
    virtual void g47(); virtual void g48(); virtual void g49(); virtual void g50(); virtual void g51(); virtual void g52(); virtual void g53(); virtual void g54(); virtual void g55();
    virtual cMatrix GetNetMatrix();                /* 0xE8 */
    virtual void g57(); virtual void g58();
    virtual cMatrix GetMatrix();                   /* 0xF4 */
    virtual unsigned char IsInActiveSector(const void* plane); /* 0xF8 */
    virtual void g61(); virtual void g62(); virtual void g63();
    virtual unsigned char GetState();              /* 0x108 */
    char pad04[0xC - 4];
    cObjectId mObjectId;
    char pad10[0x14 - 0x10];
    unsigned char mbIsLocal;
    char pad15[0x2C - 0x15];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    cObjectId* ObjId() { return &mObjectId; }
    bool IsActiveAndNotStreaming() { return mActiveFlag && mEnabled && !mStreamingFlag; }
};
inline bool cSafePtr::IsValid() const { return !ptr || ptr->mObjectId == id; }
static inline bool IsTerrainActive(cGOBJ* g) { return g && g->IsActiveAndNotStreaming(); }
struct cHuman : cGOBJ {
    char pad30[0x30AC - 0x30];
    unsigned char destReached;      /* 0x30AC */
    unsigned char destReachedValue; /* 0x30AD */
    char pad30AE[0x3204 - 0x30AE];
    int flags3204;                  /* 0x3204 */
    char pad3208[0x3210 - 0x3208];
    int flags3210;                  /* 0x3210 */
    char pad3214[0x3260 - 0x3214];
    unsigned char sex;              /* 0x3260 */
    char pad3261[0x3310 - 0x3261];
    struct Carry { char pad[0xDC]; unsigned char active; }* carry; /* 0x3310 */
    cHumanIkRoutine* ikRoutine;     /* 0x3314 */
    char pad3318[0x3478 - 0x3318];
    cSafePtr transport;             /* 0x3478 */
    char pad3480[0x3524 - 0x3480];
    void* mWeapon;                  /* 0x3524 */
    char pad3528[0x3584 - 0x3528];
    cNetHuman* m_NetHuman;          /* 0x3584 */
    bool Rolling() { return ((flags3204 >> 5) & 1) != 0; }
    bool Bit7() { return ((flags3204 >> 7) & 1) != 0; }
    unsigned char IsLocal() { return mbIsLocal; }
    bool IsCarrying() { return carry && carry->active; }
};
struct cNode { char pad[0x60]; cGOBJ* terrainGobj; char pad64[0x7C - 0x64]; int groupIndex; bool InGroup(int g) { return groupIndex == g; } };
struct cPathNavigator {
    cVector nextDestination;
    cVector pathDelta;
    char pad20[0x50 - 0x20];
    int nextNodeIndex;
    char pad54[0x5C - 0x54];
    int nodeGroupIndex;
    int NextNode() { return nextNodeIndex; }
    float PathHeading() { return Libc_Atan2f(-pathDelta.x, pathDelta.y); }
    unsigned char onPatrolPath : 1;
    unsigned char onPath : 1;
    unsigned char forceOnNodes : 1;
    unsigned char destinationReachedFlag : 1;
    unsigned char IsDestinationReached() { return destinationReachedFlag; }
};
struct cCurrentLookAt { cSafePtr gobj; float duration; int priority; unsigned char use; char pad[3]; };
struct cNPCInfoObject { char pad[4]; };

struct cNPC_0014BFF0;
extern "C" {
extern int g_NpcRegionTable[];
extern int D_005721A8;
extern int D_00494178;
extern tSecondaryState SecondaryStateTable[];
extern char D_004EA3C0[], D_004EA3B0[];
extern signed char D_004EA3A8;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0100[], D_004DAE30[], D_004F1610[], g_Game[];
cNode* cAIPathData_GetNode(int);
cNode* cPathNavigator_GetLastNodeReached(cPathNavigator*);
float cPathNavigator_PathFloorZ(cPathNavigator*, unsigned char, unsigned char);
cHuman* cNetObj_GetPlayer(int);
void cPathNavigator_UpdateGobjBeingTransported(cPathNavigator*, int);
void* func_0014D460(void*);
void* func_0014D450(void*);
cGOBJ* func_0014D410(void*);
void cPlane_dtor(void*, int);
void __register_global_object(void*, void*, void*);
void NpcAi_GroundActor(cGOBJ*, unsigned char, int, float);
void NpcPath_SetHeight(cPathNavigator*, float);
void cNPCInfoObject_ctor(cNPCInfoObject*);
void cNPCInfoObject_dtor(cNPCInfoObject*, int);
void NetGetMyClientIndex(int*, int);
unsigned char cNPCInfoObject_IsInActiveTerrain(cNPCInfoObject*, cObjectId*, int);
void func_00433F20(cNPCInfoObject*, cObjectId*, unsigned char);
void cPathNavigator_SetDestinationReached(cPathNavigator*, unsigned char);
void cPathNavigator_Update(cPathNavigator*);
cGOBJ* cSafePtr_cGOBJ_GetPtr_void(cSafePtr*);
cVector cNode_GetLoc(cNode*);
unsigned char cWeapon_GetEquipmentType(void*);
float Libc_Atan2f(float, float);
void cNPC_DoAction(cNPC_0014BFF0*, int, int, float);
void cNPC_SetMoveMode(cNPC_0014BFF0*, int, int);
void cMessage_ctor_cMessageNameR(void*, void*);
#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

void QueueMessage_cMessageR_cSystemP_int(const void*, void*, int);
void cPlaySoundMsg_ctor_cSndFxR(void*, void*, cGOBJ*);
void cFileMan_dtor(void*, int);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct cMessage {
    void* vt;
    char pad04[0x20 - 4];
    unsigned char mDestinationType;
    cMessage() {}
    cMessage(void* n) { cMessage_ctor_cMessageNameR(this, n); }
    __declspec(weak) __declspec(MSG_DTOR) ~cMessage() { cMessage_dtor(this, 0); }
};
struct cCharActionMsg : cMessage {
    int mAction; unsigned char mParamType;
    cCharActionMsg(int a, unsigned char t) : cMessage(g_ActorActionMsgClass) { vt = D_004E0840; mAction = a; mParamType = t; }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg() { vt = D_004E0840; }
};
struct tDestParams {
    cVector dest;
    float o0, o1, o2, o3;
    float rotZ;
    float speed;
    int flags;
    tDestParams(const cVector& d, float rz, float sp)
    {
        tDestParams* p = this;
        p->dest = d;
        p->o0 = 0.0f; p->o1 = 0.0f; p->o2 = 0.0f; p->o3 = 0.0f;
        p->rotZ = rz;
        p->speed = MinF(1.0f, sp);
        p->flags = 0;
    }
};
struct cCharActionMsg_DestinationParams : cCharActionMsg {
    char pad2C[4];
    tDestParams params;
    cCharActionMsg_DestinationParams(const cVector& d, float rz, float sp) : cCharActionMsg(0, 13), params(d, rz, sp)
    {
        vt = D_004E0100;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg_DestinationParams() { vt = D_004E0840; }
};
struct cSndMember { char pad[0x9C]; __declspec(weak) __declspec(MSG_DTOR) ~cSndMember() { cFileMan_dtor(this, -1); } };
struct cPlaySoundMsg : cMessage {
    char pad24[0x78 - 0x24];
    cSndMember s0;
    cSndMember s1;
    char pad1B0[0x10];
    cPlaySoundMsg() {}
    __declspec(weak) __declspec(MSG_DTOR) ~cPlaySoundMsg() { vt = D_004DAE30; }
};
static inline void SendAction(const cCharActionMsg& m, cGOBJ* g) /* mDestinationType = 1 at the call site */
{
    ((cCharActionMsg&)m).mDestinationType = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g, 1);
}

static inline bool NotB(unsigned char b) { return !b; }
static inline int GetMyIndex(int conn)
{
    if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, conn);
    return D_00494178;
}
static inline int GetClientIndex(int conn)
{
    int idx = 0;
    if (g_IsMultiplayer) idx = GetMyIndex(conn);
    else idx = 0;
    return idx;
}
static inline float WrapAngle(float a)
{
    if (a > 3.1415927f) a -= 6.2831855f;
    else if (a < -3.1415927f) a += 6.2831855f;
    return a;
}

struct cNPC_0014BFF0 {
    virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3(); virtual void n4(); virtual void n5(); virtual void n6(); virtual void n7();
    virtual void n8(); virtual void n9(); virtual void n10(); virtual void n11(); virtual void n12(); virtual void n13(); virtual void n14(); virtual void n15();
    virtual void n16(); virtual void n17(); virtual void n18(); virtual void n19(); virtual void n20(); virtual void n21(); virtual void n22(); virtual void n23();
    virtual void n24(); virtual void n25(); virtual void n26(); virtual void n27(); virtual void n28(); virtual void n29(); virtual void n30(); virtual void n31();
    virtual void n32(); virtual void n33(); virtual void n34(); virtual void n35(); virtual void n36(); virtual void n37(); virtual void n38();
    virtual eMoveMode GetMoveMode();                /* 0xA4 */
    virtual unsigned char UseCurrentLookAt(int w);  /* 0xA8 */
    virtual unsigned char TargetPositionValid();    /* 0xAC */
    virtual const cVector* GetTargetPos();          /* 0xB0 */
    virtual unsigned char IsTargetVisible();        /* 0xB4 */
    virtual void n44(); virtual void n45(); virtual void n46(); virtual void n47(); virtual void n48(); virtual void n49(); virtual void n50(); virtual void n51();
    virtual float GetRawTravelSpeed();              /* 0xD8 */
    char pad04[0x30 - 4];
    cHuman* mGobj;
    char pad34[0x114 - 0x34];
    int pathLinkType;               /* 0x114 */
    char pad118[0x124 - 0x118];
    int actionFlags;                /* 0x124 */
    char pad128[0x13C - 0x128];
    unsigned char m13C;             /* 0x13C */
    char pad13D[0x158 - 0x13D];
    unsigned char inActiveSector;   /* 0x158 */
    char pad159[0x16C - 0x159];
    cCurrentLookAt currentLookAt[3];/* 0x16C */
    char pad1A8[0x1B0 - 0x1A8];
    cPathNavigator* pathNavigator;  /* 0x1B0 */
    char pad1B4[0x1D0 - 0x1B4];
    cNode* searchLookNode;          /* 0x1D0 */
    char pad1D4[0x1D6 - 0x1D4];
    unsigned char deathFallScreamWhenFalling; /* 0x1D6 */
    cHuman* GetGobj() { return mGobj; }
    bool IsDying() { return IsDS(mGobj->GetState()); }
    static bool IsDS(unsigned short st) { return st == 3 || st == 2; }
    void NotifyTerrain(int forced, float z)
    {
        unsigned char f = forced;
        if (f ? (mGobj->IsCarrying() || !inActiveSector) : !inActiveSector)
            NpcAi_GroundActor(mGobj, f, 1, z);
    }
    cCurrentLookAt* GetLookAt(int w) { cCurrentLookAt* r = 0; if (currentLookAt[w].use) r = &currentLookAt[w]; return r; }
    bool IsAiming()
    {
        return mGobj->ikRoutine ? IsAimingMode(mGobj->ikRoutine) : false;
    }
    static bool IsAimingMode(cHumanIkRoutine* ik)
    {
        return SS(ik->mode0).aims && SS(ik->mode1).aims;
    }
    static const tSecondaryState& SS(int m) { return SecondaryStateTable[m]; }
};

extern "C" void cNPC_UpdateMovement(cNPC_0014BFF0* self)
{
    cVector pos = self->GetGobj()->GetMatrix().T();
    unsigned char prevInActiveSector;
    float floorZ;
    prevInActiveSector = self->inActiveSector;
    self->inActiveSector = 1;
    {
        unsigned char resetZ = 1;
        if (self->pathLinkType != 7) {
            resetZ = ((self->mGobj->flags3204 >> 7) & 1) != 0;
            if (self->pathNavigator->NextNode() >= 0) {
                if (!IsTerrainActive(cAIPathData_GetNode(self->pathNavigator->NextNode())->terrainGobj))
                    resetZ = 0;
            }
            {
                cNode* n = cPathNavigator_GetLastNodeReached(self->pathNavigator);
                if (n) {
                    if (!IsTerrainActive(n->terrainGobj))
                        resetZ = 0;
                }
            }
        }
        floorZ = cPathNavigator_PathFloorZ(self->pathNavigator, prevInActiveSector, resetZ);
    }
    if ((self->mGobj->flags3210 >> 22) & 1) {
        int groupIndex = -1;
        if (g_IsMultiplayer) {
            int i;
            for (i = 0; i != 4; i++) {
                cHuman* gobj = cNetObj_GetPlayer(i);
                if (gobj) {
                    if (gobj->transport.Get() == self->mGobj) {
                        groupIndex = g_NpcRegionTable[i];
                        break;
                    }
                }
            }
        }
        cPathNavigator_UpdateGobjBeingTransported(self->pathNavigator, groupIndex);
        {
            cGOBJ* t = func_0014D410(func_0014D450(func_0014D460(self->mGobj)));
            if (!t || !t->IsActiveAndNotStreaming())
                self->inActiveSector = 0;
        }
    } else if (!prevInActiveSector || self->mGobj->GetMatrix().Z() <= floorZ) {
        bool s3;
        if (D_004EA3A8 == 0) {
            __register_global_object(D_004EA3C0, (void*)cPlane_dtor, D_004EA3B0);
            D_004EA3A8 = 1;
        }
        self->inActiveSector = self->mGobj->IsInActiveSector(D_004EA3C0);
        s3 = 0;
        if (self->m13C == 1) {
            unsigned char s2 = 0;
            if (NotB(self->pathNavigator->IsDestinationReached()) && NotB(self->IsDying()))
                s2 = 1;
            if (s2) s3 = 1;
        }
        self->NotifyTerrain(s3, floorZ);
    } else if (self->mGobj->GetState() == 3) {
        NpcPath_SetHeight(self->pathNavigator, 3.0f + self->mGobj->GetMatrix().Z());
    }
    if (prevInActiveSector != self->inActiveSector)
        self->pathNavigator->forceOnNodes = !self->inActiveSector;
    if (g_IsMultiplayer) {
        cNPCInfoObject npcInfo;
        cNPCInfoObject_ctor(&npcInfo);
        if (self->inActiveSector != cNPCInfoObject_IsInActiveTerrain(&npcInfo, self->mGobj->ObjId(), GetClientIndex(D_005721A8)))
            func_00433F20(&npcInfo, &self->mGobj->mObjectId, self->inActiveSector);
        if (self->mGobj->mbIsLocal) {
            cNetHuman* netHuman = self->mGobj->m_NetHuman;
            if (netHuman) {
                self->mGobj->GetNetMatrix().ToNet(*netHuman);
            }
        }
        cNPCInfoObject_dtor(&npcInfo, -1);
    }
    if (!self->IsDying() || self->pathLinkType == 7) {
        float speed;
        eMoveMode moveMode;
        unsigned char rolling;
        cVector faceDelta;
        if (self->mGobj->destReached)
            cPathNavigator_SetDestinationReached(self->pathNavigator, self->mGobj->destReachedValue);
        cPathNavigator_Update(self->pathNavigator);
        speed = self->GetRawTravelSpeed();
        moveMode = self->GetMoveMode();
        rolling = self->mGobj->Rolling();
        if (0.0f == speed)
            moveMode = MM_0;
        if (moveMode != 1)
            speed = 0.0f;
        if (g_IsMultiplayer) {
            if (self->mGobj->mbIsLocal) {
                cNetHuman* netHuman = self->mGobj->m_NetHuman;
                if (netHuman) netHuman->speed = speed;
            }
        }
        if (self->UseCurrentLookAt(2)) {
            cCurrentLookAt* lookAt = self->GetLookAt(2);
            if (lookAt->gobj.Get())
                faceDelta = cSafePtr_cGOBJ_GetPtr_void(&lookAt->gobj)->GetBonePos(-1) - pos;
        } else if (rolling || self->pathLinkType == 7) {
            faceDelta = self->pathNavigator->pathDelta;
        } else if ((self->IsAiming() && self->IsTargetVisible()) || (cWeapon_GetEquipmentType(self->mGobj->mWeapon) == 1 && self->TargetPositionValid())) {
            faceDelta = *self->GetTargetPos() - pos;
            if (faceDelta.LengthSq() < 16.0f)
                faceDelta.Zero();
        } else {
            faceDelta.Zero();
        }
        if (moveMode == 1) {
            float rotZ;
            if (faceDelta.IsZero())
                faceDelta = self->pathNavigator->pathDelta;
            else
                faceDelta.Normalize();
            if (self->pathLinkType == 9 && !(self->actionFlags & 2) && !rolling) {
                float pathDeltaZ = self->pathNavigator->PathHeading();
                float deltaAngle = WrapAngle(pathDeltaZ - self->mGobj->GetMatrix().HeadingZ());
                if (Fabs(deltaAngle) <= 0.43633232f) {
                    cNPC_DoAction(self, 2, 0, 0.0f);
                    self->actionFlags &= ~2;
                    self->pathLinkType = 0;
                }
            }
            rotZ = Libc_Atan2f(-faceDelta.x, faceDelta.y);
            { cCharActionMsg_DestinationParams msg(self->pathNavigator->nextDestination, rotZ, speed); msg.mDestinationType = 1; QueueMessage_cMessageR_cSystemP_int(&msg, self->mGobj, 1); }
        } else if (moveMode == 0) {
            float rotZ;
            if (!g_IsMultiplayer || self->mGobj->IsLocal()) {
                if (faceDelta.IsZero()) {
                    faceDelta = self->mGobj->GetMatrix().R1();
                    if (self->searchLookNode && self->searchLookNode->InGroup(self->pathNavigator->nodeGroupIndex)) {
                        faceDelta = cNode_GetLoc(self->searchLookNode) - pos;
                        faceDelta.Normalize();
                    }
                } else {
                    faceDelta.Normalize();
                }
                rotZ = Libc_Atan2f(-faceDelta.x, faceDelta.y);
            } else if (g_IsMultiplayer) {
                rotZ = self->mGobj->m_NetHuman ? self->mGobj->m_NetHuman->rotZ : 0.0f;
            }
            { cCharActionMsg_DestinationParams msg(faceDelta, rotZ, speed); msg.mDestinationType = 1; QueueMessage_cMessageR_cSystemP_int(&msg, self->mGobj, 1); }
        } else {
            float angleTarget;
            float pathDeltaZ = self->pathNavigator->PathHeading();
            float deltaAngle = WrapAngle(pathDeltaZ - self->mGobj->GetMatrix().HeadingZ());
            if (self->pathLinkType == 4 || self->pathLinkType == 11 || self->pathLinkType == 3 || self->pathLinkType == 9)
                angleTarget = 25.0f;
            else
                angleTarget = 360.0f;
            if (Fabs(deltaAngle) <= 0.017453292f * angleTarget) {
                cNPC_SetMoveMode(self, 1, 20);
                if (self->pathLinkType == 4) {
                    SendAction(cCharActionMsg(15, 0), self->mGobj);
                } else if (self->pathLinkType == 11) {
                    SendAction(cCharActionMsg(16, 0), self->mGobj);
                } else if (self->pathLinkType == 3) {
                    QueueMessage_cMessageR_cSystemP_int(&cCharActionMsg(26, 0), self->mGobj, 0);
                }
            }
            { cCharActionMsg_DestinationParams msg(self->pathNavigator->nextDestination, self->pathNavigator->PathHeading(), speed); msg.mDestinationType = 1; QueueMessage_cMessageR_cSystemP_int(&msg, self->mGobj, 1); }
        }
    }
    if (self->deathFallScreamWhenFalling && ((self->mGobj->flags3204 >> 7) & 1)) {
        self->deathFallScreamWhenFalling = 0;
        cPlaySoundMsg msg;
        cPlaySoundMsg_ctor_cSndFxR(&msg, self->mGobj->sex == 1 ? D_004F1610 : D_004F1610, self->mGobj);
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    }
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0014BFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014BFF0 */

/* merge_units: begin func_0014D270 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cGeneratorMessage_dtor, D_004E0100, D_004E0840, cMessage_dtor)
static inline void merge_flush_func_0014D270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D270 */
