/*
 * SFOGame/Source/weapon: 1 file, 00144080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00144080 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
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
void cMessage_dtor(void* msg, int flags);
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
static inline void merge_flush_func_00144080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00144080 */
