/*
 * SFOGame/Source/weapon: 16 files, 00143BC0-00144930
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00143BC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[8]; unsigned char b8; } Sub_143BC0;
typedef struct { Sub_143BC0* sub; char p4[0x9C]; unsigned char a0; char pa1[0x1B]; int bc; int c0; char pc4[0x2B]; unsigned char ef; } S_143BC0;
#pragma cplusplus on
static inline int Busy_143(S_143BC0* s) { int b = (s->ef != 0); if (!b) b = (s->a0 != 0); if (!b) b = (s->bc != 0); if (!b) b = (s->c0 != 0); return b; }
extern "C" bool cWeapon_CanChangeWeapon(S_143BC0* s) {
    bool r = false;
    if (Busy_143(s) ^ 1) {
        bool idle = !(s->sub != 0) || !(s->sub->b8 != 0);
        if (idle) r = true;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143BC0 */

/* merge_units: begin func_00143C50 */
#pragma push /* merge_units */
typedef struct { int x0; int x4; int x8; int xC; } Slot143C50;
typedef struct { Slot143C50 s[6]; } Inv143C50;
#if 0 /* merge_units */
extern void cWeapon_DrawWeapon_eWpnSlot(Inv143C50*, int);
#endif /* merge_units */
void cWeapon_DrawWeapon_eWpnSlot(void*, int); /* merge_units */
#define cWeapon_DrawWeapon_eWpnSlot(a0, a1) (cWeapon_DrawWeapon_eWpnSlot((void *)(a0), (a1))) /* merge_units */

void cWeapon_DrawWeapon_void(Inv143C50* inv) {
    int slot = 6;
    int i;
    for (i = 0; i < 6; i++) {
        if (inv->s[i].x8 != -1) { slot = (unsigned char)i; break; }
    }
    if ((unsigned char)slot != 6) cWeapon_DrawWeapon_eWpnSlot(inv, slot);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143C50(void) {}
#undef cWeapon_DrawWeapon_eWpnSlot /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143C50 */

/* merge_units: begin func_00143CC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "weapon_types.h"

extern void cWeapon_StoreWeapon_void(Inventory* inv);

void cWeapon_ForceHolster(Inventory* inv) {
    if (inv->selected != 6) {
        cWeapon_StoreWeapon_void(inv);
    }
}
static inline void merge_flush_func_00143CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143CC0 */

/* merge_units: begin func_00143CF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x85]; unsigned char item; } Inv3CF0;
#if 0 /* merge_units */
extern void cWeapon_DrawWeapon_eWpnSlot(Inv3CF0* p, int item);
#endif /* merge_units */
#define cWeapon_DrawWeapon_eWpnSlot(a0, a1) (cWeapon_DrawWeapon_eWpnSlot((void *)(a0), (a1))) /* merge_units */


void cWeapon_DrawLastWeaponUsed(Inv3CF0* p) {
    if (p->item != 6) {
        cWeapon_DrawWeapon_eWpnSlot(p, ((signed char*)p)[0x85]);
    }
}
#undef cWeapon_DrawWeapon_eWpnSlot /* merge_units */
static inline void merge_flush_func_00143CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143CF0 */

/* merge_units: begin func_00143D20 */
#pragma push /* merge_units */
extern signed char WeaponClassToSlot[];

/* Maps a weapon id through definition byte +0x30 and the WeaponClassToSlot table. */
int cWeapon_GetWeaponSlot(int id) {
    WeaponDef* def = cWeaponDB_GetEntry(g_WeaponDatabase, id);

    return WeaponClassToSlot[def->unk30];
}
static inline void merge_flush_func_00143D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143D20 */

/* merge_units: begin func_00143D60 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { int a0; int id; int x; int y; } E3D60;
typedef struct { int pad; E3D60 e[2]; } S3D60;
void cWeapon_EqualizeDualWieldAmmo(char* self)
{
    E3D60* b = (E3D60*)(self + 0x14);
    E3D60* a = (E3D60*)(self + 0x4);
    if (*(int*)(self + 0x18) != -1 && a->id != -1) {
        int y = (b->y + a->y + 1) / 2;
        int x = (b->x + a->x + 1) / 2;
        a->x = x;
        b->x = x;
        a->y = y;
        b->y = y;
    }
}
static inline void merge_flush_func_00143D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143D60 */

/* merge_units: begin func_00143DE0 */
#pragma push /* merge_units */
extern int cHuman_AdjustMaxClips(void* a0, int key);

int cWeapon_AdjustMaxClips(Inventory* inv, int key) {
    return cHuman_AdjustMaxClips(inv->unk88, key);
}
static inline void merge_flush_func_00143DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143DE0 */

/* merge_units: begin func_00143DF0 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad21[0xB];
    unsigned char op;
    char pad2D[7];
    char slot;
    char pad35[3];
    int value;
} Msg_INV;
typedef struct { int a; int b; int c; int d; } E_INV;
typedef struct { char pad[0x60]; char equip[0x24A2 - 0x60]; char flags[1]; } Actor_INV;
typedef struct { void** held; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad85[3]; Actor_INV* owner; } INV;
typedef struct { char pad[0x30]; unsigned char type; char pad31[0x70 - 0x31]; int clip; int ammoType; char pad78[0xF0 - 0x78]; unsigned char kind; char padF1[0x13C - 0xF1]; int equip; } WDB;
extern char D_0052ACC8[];
extern char D_004DE610[];
extern unsigned char g_IsMultiplayer;
#if 0 /* merge_units */
extern int g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(int*)&g_WeaponDatabase) /* merge_units */

extern signed char WeaponHolsterAttachPoints[];
extern signed char WeaponHandAttachPoints[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_INV* msg, void* name);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void* msg, void* type); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_INV* msg, void* target, int flags);
#endif /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate); /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_INV* msg, int flags);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern WDB* cWeaponDB_GetEntry(int db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((WDB *)cWeaponDB_GetEntry((void *)(a0), (a1))) /* merge_units */

extern void cWeaponDB_LoadWeapon(int db, int id, int f);
#if 0 /* merge_units */
extern int cHuman_AdjustMaxClips(Actor_INV* a, int type);
#endif /* merge_units */
#define cHuman_AdjustMaxClips(a0, a1) (cHuman_AdjustMaxClips((void *)(a0), (a1))) /* merge_units */

extern void cMan_AddGun(void* eq, unsigned char slot, int v);
void cWeapon_Add(INV* self, int id, unsigned char ammo, int unused, unsigned char preload, unsigned char quiet)
{
    signed char slot;
    E_INV* e;
    int db;
    int idx;
    WDB* w;
    unsigned char s;
    int v;
    db = g_WeaponDatabase;
    w = cWeaponDB_GetEntry(db, id);
    slot = WeaponClassToSlot[w->type];
    idx = slot & 0xFF;
    e = &self->e[idx];
    if (preload)
        cWeaponDB_LoadWeapon(g_WeaponDatabase, id, 0);
    if (e->b != -1 && (unsigned char)slot == 0 && id == e->b && self->e[1].b == -1) {
        slot = 1;
        idx = slot & 0xFF;
        e = &self->e[idx];
    }
    e->b = id;
    if (ammo) {
        WDB* w2 = cWeaponDB_GetEntry(db, id);
        e->c = w2->clip;
        e->d = w2->clip * cHuman_AdjustMaxClips(self->owner, w2->ammoType);
    } else {
        e->c = 0;
        e->d = 0;
    }
    s = slot;
    if (s == self->cur) {
        idx = WeaponHandAttachPoints[idx];
    } else {
        asm { .set reorder } /* barrier: retail fills the bne delay slot from the fall-through lui */
        idx = WeaponHolsterAttachPoints[idx];
    }
    if (s == 1 && self->cur == 0)
        idx = 1;
    v = cWeaponDB_GetEntry(db, id)->equip;
    if (v)
        cMan_AddGun(self->owner->pad + 0x60, idx, v);
    if (s == 6 || s == 7)
        self->owner->pad[(unsigned char)idx + 0x24A2] = 0;
    if (w->kind == 5 && self->held)
        *self->held = w;
    if (g_IsMultiplayer && !quiet) {
        Msg_INV msg;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACC8);
        msg.vtable = D_004DE610;
        msg.op = 5;
        msg.value = ammo | (preload << 1);
        msg.slot = id;
        msg.x1C = 0x40;
        msg.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
        msg.vtable = D_004DE610;
        cMessage_dtor(&msg, 0);
    }
}
#undef g_WeaponDatabase /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cWeaponDB_GetEntry /* merge_units */
#undef cHuman_AdjustMaxClips /* merge_units */
static inline void merge_flush_func_00143DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143DF0 */

/* merge_units: begin func_00144080 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "alloc_guard.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) WiV4;
struct WiFx { char d[0x40]; };

class WiCtl {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsReady();
    VPAD2(d) VPAD1(e)
    virtual void GetMuzzle(WiFx* out, int hand, int z);
};

class WiActor {
public:
    VPAD32(a) VPAD32(b)
    virtual unsigned char GetState();
    char pad4[0x2C - 4];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x38 - 0x2F];
    int f38;
    char pad3C[0x58 - 0x3C];
    WiCtl* ctl;
    char pad5C[0x60 - 0x5C];
    WiV4 pos;
    bool On() { return b2D && b2C && !b2E; }
};

struct WiLightBase { signed char kind; unsigned char flag1; };
struct WiLight : WiLightBase {
    virtual void Destroy(int flags);
    VPAD4(a) VPAD2(b) VPAD1(c)
    virtual void SetPos(WiV4* p);
    virtual void Enable();
    char pad8[4];
    float intensity;
    float f10;
    float f14;
    float id;
    unsigned char enabled;
    unsigned char aux;
    unsigned char type;
    char pad1F;
    WiV4 color;
    WiV4 dir;
};

class WiFxObj {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int f);
    virtual void Deactivate(int f);
    VPAD8(d) VPAD2(e) VPAD1(f)
    virtual void Attach(void* p, int a);
    VPAD2(g)
    virtual void Update(WiV4* p);
    char pad4[0x2C - 4];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    unsigned char b2F;
    char pad30[0x60 - 0x30];
    int def;
    void* emitter;
    short f68;
    char pad6A[0x70 - 0x6A];
    float f70;
    bool On() { return b2D && b2C && !b2E; }
};

struct WiObj { char pad[0xC]; int id; };

struct WiInv {
    void* held;
    char pad4[0x88 - 4];
    WiActor* actor;
    int unk8C;
    WiObj* burstObj;
    int burstId;
    unsigned char aimView;
    char pad99[3];
    int subtarget;
    char padA0[4];
    int carried;
    char padA8[4];
    float cooldown[2];
    float unkB4[2];
    int burstLeft[2];
    int loopSoundActive[2];
    float spinUp[2];
    WiLight* light;
    WiFxObj* fx;
    float fDC;
    float fE0;
    float fE4;
    WiObj* Target() { bool ok = !burstObj || burstObj->id == burstId; return ok ? burstObj : 0; }
};

extern "C" {
extern signed char D_00489C08;
extern float D_00489C58;
extern float D_00489C60;
extern float D_00489C68;
extern float D_00489C70;
extern float D_00489C78;
extern float D_00489C80;
extern float D_00489C88;
extern float D_00489C90;
extern float D_00489C98;
extern float D_00489CA0;
extern float g_VideoFrameRate;
extern char D_0049B1D0[];
extern char D_004D9200[];
extern char D_004D9240[];
extern char D_004D9280[];
extern char D_004DF860[];
extern char D_004E1140[];
extern char g_LightMgr[];
extern unsigned char g_LevelLightsDirty;
extern char D_00583968[];
extern char g_IdentityMatrix[];
void cWeapon_FireIfReady(WiInv* self, WiObj* target, int sub, unsigned char view, int a);
unsigned char cWeapon_GetEquipmentType(WiInv* self);
void SfxParticleEffect_eEffectName_cMatrixR(int id, WiFx* fx);
void cWeapon_StopLoopingSound(WiInv* self, unsigned char slot);
int cWeapon_GetMostVisible(WiInv* self);
void cMessage_ctor_cMessageNameR(void* msg, void* type);

void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);

#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */


void cAirTaser_NextFrame(void* held, float dt);
WiLight* cLightMan_AddLight(void* pool, int kind);
int* nSfxLoader_GetHandle(int id);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nGobjManager_GetNextId(int* out, int kind);
void cGOBJ_ctor(void* p, int* id, int a, int* b);
void nGobjManager_AddGOBJ(void* p);
void nGobjManager_RemoveGOBJ(void* p);
void cSystem_ActualScheduleDelete(float t, void* p);
void cMan_GetGunBarrelEnd(WiV4* out, WiV4* src, int a);
int Libc_Rand();
void cParticle_SetScale(float r, void* e);
}

struct WiMsg {
    void* vtable; void* type; int magic; int time; int unk10; void* target; int stampKind; int flags;
    unsigned char kind; char pad21[3];
    int value;
};

static inline float WiLenSq(WiV4* a) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}

static inline float WiR01() { return (float)Libc_Rand() / 2147483648.0f; }
static inline float WiRand(float m) { return m * WiR01(); }
static inline float WiRandRR(const float& lo, const float& hi) { return lo + WiRand(hi - lo); }
static inline void* WiAlloc() { AllocGuard g; return cMemMan_Allocate(0, 0x74, D_0049B1D0, 0x533); }

static inline void WiFxCtor(WiFxObj* o, int def, int& id) {
    int z;
    nGobjManager_GetNextId(&id, 0xE7);
    z = 0;
    cGOBJ_ctor(o, &id, 4, &z);
    *(void**)o = D_004DF860;
    o->def = def;
    o->emitter = 0;
    o->f68 = 0;
    o->f70 = 1.0f;
    o->b2F = 1;
}
extern "C" void cWeapon_NextFrame(WiInv* self, float dt)
{
    int i;
    int j;
    for (i = 0; i < 2; i++) {
        if (self->burstLeft[i] > 0)
            cWeapon_FireIfReady(self, self->Target(), self->subtarget, self->aimView, 1);
    }
    for (j = 0; j < 2; j++) {
        if (!(self->cooldown[j] <= 0.0f))
            self->cooldown[j] -= dt;
        self->unkB4[j] += dt;
        if (!self->aimView && self->actor->f38 != 0x80 && !(g_VideoFrameRate <= 35.0f)
            && cWeapon_GetEquipmentType(self) != 8 && !(self->unkB4[j] <= 0.5f) && self->unkB4[j] < 1.5f) {
            WiFx fx;
            self->actor->ctl->GetMuzzle(&fx, j != 0, 0);
            SfxParticleEffect_eEffectName_cMatrixR(5, &fx);
        }
        if (!self->burstLeft[j] && !(self->unkB4[j] <= 0.5f))
            cWeapon_StopLoopingSound(self, j != 0);
        if (!(self->spinUp[j] <= 0.0f)) {
            self->spinUp[j] -= dt;
            if (self->spinUp[j] < 0.0f)
                self->spinUp[j] = 0.0f;
        }
    }
    {
        bool ready = false;
        WiCtl* c = self->actor->ctl;
        if (c && c->IsReady())
            ready = true;
        if (ready) {
            int v = cWeapon_GetMostVisible(self);
            if (v != self->carried) {
                WiMsg m;
                self->carried = v;
                cMessage_ctor_cMessageNameR(&m, D_00583968);
                m.vtable = D_004E1140;
                m.kind = 2;
                m.value = v;
                QueueMessage_cMessageR_cSystemP_int(&m, self->actor->ctl, 0);
                m.vtable = D_004E1140;
                cMessage_dtor(&m, 0);
            }
        }
    }
    if (self->held)
        cAirTaser_NextFrame(self->held, dt);
    if (cWeapon_GetEquipmentType(self) == 10 && self->actor->GetState() != 3) {
        if (!self->light) {
            WiLight* l = cLightMan_AddLight(g_LightMgr, 4);
            if (l) {
                *(void**)((char*)l + 4) = D_004D9280;
                l->kind = D_00489C08;
                l->flag1 = 0;
                *(void**)((char*)l + 4) = D_004D9240;
                l->intensity = 0.0f;
                l->enabled = 0;
                l->aux = 3;
                l->type = 4;
                l->color.x = 0.0f;
                l->color.y = 0.0f;
                l->color.z = 0.0f;
                l->color.w = 0.0f;
                l->dir.x = 0.0f;
                l->dir.y = 0.0f;
                l->dir.z = 0.0f;
                l->dir.w = 1.0f;
                g_LevelLightsDirty = 1;
                l->id = 0.0f;
                *(void**)((char*)l + 4) = D_004D9200;
            }
            self->light = l;
            if (self->light) {
                self->light->f10 = 0.0f;
                self->fDC = 1.0f;
                self->fE4 = 10000.0f;
                self->fE0 = 1.0f;
                self->light->Enable();
            }
        }
        if (!self->fx) {
            int id;
            int def = *nSfxLoader_GetHandle(7);
            WiFxObj* o;
            { AllocGuard g; o = (WiFxObj*)cMemMan_Allocate(0, 0x74, D_0049B1D0, 0x533); }
            if (o) WiFxCtor(o, def, id);

            self->fx = o;
            self->fx->Attach(g_IdentityMatrix, 0);
            nGobjManager_AddGOBJ(self->fx);
        }
        {
            WiV4 pos;
            cMan_GetGunBarrelEnd(&pos, &self->actor->pos, 0);
            if (self->light) {
                WiLight* l = self->light;
                float s = D_00489C70 + self->fE0 * (D_00489C78 - D_00489C70);
                float r = D_00489C58 * s;
                float g = D_00489C60 * s;
                float b = D_00489C68 * s;
                WiV4 c;
                l->color.x = r;
                l->color.y = g;
                l->color.z = b;
                l->color.w = 0.0f;
                c.x = r;
                c.y = g;
                c.z = b;
                c.w = 0.0f;
                l->id = 1.0f / WiLenSq(&c);
                self->light->SetPos(&pos);
                self->light->f14 = D_00489CA0;
                self->fE0 += self->fE4 * dt;
                {
                    float hi = self->fDC;
                    if ((self->fE4 > 0.0f) == (self->fE0 > hi)) {
                        self->fE0 = hi;
                        self->fDC = WiRand(1.0f);
                        self->fE4 = WiRandRR(D_00489C80, D_00489C88);
                        if (self->fDC < self->fE0)
                            self->fE4 *= -1.0f;
                    }
                }
            }
            if (self->fx) {
                if (self->actor->On() && !self->fx->On())
                    self->fx->Activate(1);
                else if (!self->actor->On() && self->fx->On())
                    self->fx->Deactivate(1);
                if (self->fx->emitter)
                    cParticle_SetScale(D_00489C90 + self->fE0 * (D_00489C98 - D_00489C90), self->fx->emitter);
                self->fx->Update(&pos);
            }
        }
    } else {
        WiLight* l = self->light;
        if (l) {
            if (l)
                l->Destroy(1);
            self->light = 0;
        }
        if (self->fx) {
            nGobjManager_RemoveGOBJ(self->fx);
            cSystem_ActualScheduleDelete(0.1f, self->fx);
            self->fx = 0;
        }
    }
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00144080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00144080 */

/* merge_units: begin func_00144930 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSubclassId_dtor)
static inline void merge_flush_func_00144930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00144930 */

/* merge_units: begin func_00144980 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; unsigned char flag; } F44980;
void cLightSrc_Deactivate(F44980* p)
{
    if (p->flag) {
        p->flag = 0;
        g_LevelLightsDirty = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144980 */

/* merge_units: begin func_001449B0 */
#pragma push /* merge_units */
extern int cSpecFx_opDelete(int);

int cSpecFx_dtor(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    cond = s0 == 0;
    if (cond) goto L001449E8;
    v1 = (int)D_004D9280;
    v0 = (short)a1;
    cond = v0 <= 0;
    *(int*)((char*)s0 + 4) = v1;
    if (cond) goto L001449E8;
    v0 = cSpecFx_opDelete(a0);
L001449E8:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001449B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001449B0 */

/* merge_units: begin func_00144A00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cWeaponVisChangeMsg_dtor, D_004E1140, cMessage_dtor)
static inline void merge_flush_func_00144A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00144A00 */

/* merge_units: begin func_00144A60 */
#pragma push /* merge_units */
#pragma cplusplus on
class E7VC {
public:
    int pad0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void Disable();
};
struct E7Light { int pad0; void* vt; int id; };
extern "C" {
#if 0 /* merge_units */
extern void* D_004D9200[];
#endif /* merge_units */
#define D_004D9200 ((void **)&D_004D9200) /* merge_units */

#if 0 /* merge_units */
extern void* D_004D9240[];
#endif /* merge_units */
#define D_004D9240 ((void **)&D_004D9240) /* merge_units */

#if 0 /* merge_units */
extern void* D_004D9280[];
#endif /* merge_units */
#define D_004D9280 ((void **)&D_004D9280) /* merge_units */



#if 0 /* merge_units */
extern int g_LightMgr;
#endif /* merge_units */
#define g_LightMgr (*(int*)&g_LightMgr) /* merge_units */

extern void cLightMan_RemoveLight(void* pool, void* p);
E7Light* cPointLight_dtor(E7Light* p, short flag) {
    if (p) {
        p->vt = D_004D9200;
        if (p) {
            p->vt = D_004D9240;
            p->id = -1;
            ((E7VC*)p)->Disable();
            g_LevelLightsDirty = 1;
            if (p) {
                p->vt = D_004D9280;
            }
        }
        if (flag > 0) {
            cLightMan_RemoveLight(&g_LightMgr, p);
        }
    }
    return p;
}
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144A60(void) {}
#undef D_004D9200 /* merge_units */
#undef D_004D9240 /* merge_units */
#undef D_004D9280 /* merge_units */
#undef g_LightMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00144A60 */

/* merge_units: begin func_00144B10 */
#pragma push /* merge_units */
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x30]; V4 v30; } C44_O;
static inline unsigned char eq4_(V4* a, V4* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
#pragma push
#pragma bool off



void cLightSrc_SetPosition(C44_O* o, V4* v) {
    if ((eq4_(&o->v30, v) != 0) ^ 1) {
        { V4* d = &o->v30; VCopyF(d, v); }
        g_LevelLightsDirty = 1;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144B10 */

/* merge_units: begin func_00144B80 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; unsigned char done; } Obj;

/* Sets the +0x1C flag (and the global flag g_LevelLightsDirty) once. */
void cLightSrc_Activate(Obj* self)
{
    if (!self->done) {
        self->done = 1;
        g_LevelLightsDirty = 1;
    }
}
static inline void merge_flush_func_00144B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00144B80 */
