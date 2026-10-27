/* cGameSystem_NextFrame: per-frame world update - environment blend and fog terms, actor updates,
   the world services, and the periodic network pause-state send. */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct EnvVec3_133420 { float x, y, z; };
struct EnvData_133420 {
    char pad0[0x60];
    float zNear;
    float zFar;
    float fogNear;
    float fogFar;
    EnvVec3_133420 color;
};
/* environment blend: current settings, blend progress and the from/to values */
struct EnvBlend_133420 {
    int pad0[3];
    EnvData_133420* cur;
    unsigned char active;
    float t;
    float dur;
    float frac;
    char pad20[0x28 - 0x20];
    float zNearFrom, zNearTo;
    float fogNearFrom, fogNearTo;
    float fogFarFrom, fogFarTo;
    EnvVec3_133420 colorFrom;
    EnvVec3_133420 colorTo;
};

struct Hud_133420;
struct Ui_133420 { VPAD8(a) VPAD4(b) VPAD2(c) virtual void Update(float dt); };
struct Actor_133420 {
    VPAD16(a) virtual void Update(float dt); virtual void Think(float dt);
    char pad4[0x28];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
};
struct Msg_133420 { void* vt; char pad[0x2C]; };
struct World_133420 {
    char pad0[0x67];
    unsigned char paused;
    char pad68[0x80 - 0x68];
    void* receiver;
    EnvBlend_133420* env;
    char pad88[0x8C - 0x88];
    void* tremors;
    char pad90[0xBC - 0x90];
    Ui_133420* ui;
    char padC0[0xDC - 0xC0];
    Hud_133420* hud;
    void* vision;
    void* water;
    void* fader;
    void* decals;
    char padF0[0x1F0 - 0xF0];
    float netTimer;
};

extern "C" {
extern float D_00538340;
extern float D_00538344;
extern float D_00538348;
extern float g_LevelFarDistance;
extern int D_00538350;
extern int D_00538354;
extern int D_00538358;
extern int D_0053835C;
extern float D_00538360;
extern float D_00538364;
extern float D_00538368;
extern float D_0053836C;
extern char g_Video[];
extern char D_005436B0[];
extern char D_004D9160[];
extern char D_004F2CC0[];
extern unsigned char g_IsMultiplayer;
extern int D_00489BC0;
float cGameSystem_UpdateTimeStep(World_133420* w);
void cHud_NextFrame(Hud_133420* h, float dt);
void cEnvMan_NextFrame(EnvBlend_133420* e, float dt);
void XLib_UpdateFogParms(char* fog);
void* nGobjManager_GetGOBJList(void);
PtrVec* cObjList_cGOBJPtr_GetList(void* arr);
void cArray_cGOBJPtr_Begin(Iter* out, PtrVec* v);
void cArray_cGOBJPtr_End(Iter* out, PtrVec* v);
Iter* cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(Iter* out, Iter* in);
void cMotionManager_NextFrame(float dt);
void UpdateDarkness(void);
void nGobjManager_PurgeRemovals(void);
void cBulletManager_NextFrame(float dt);
void nDynamicSfxList_NextFrame(float dt);
void cMessage_ctor_cMessageNameR(Msg_133420* m, char* desc);
void QueueMessage_cMessageR_cSystemP_int(Msg_133420* m, void* target, int immediate);
void cMessage_dtor(Msg_133420* m, int flags);
void cVisionFxMan_NextFrame(void* v, float dt);
void cWaterFx_NextFrame(void* w, float dt);
void cScreenFader_NextFrame(void* f, float dt);
void cDecalMan_NextFrame(void* d, float dt);
void nRumbleManager_NextFrame(float dt);
void cTremorManager_NextFrame(void* t, float dt);
void cBackpack_Update(float dt);
void* cSystemContainer_GetSystem(World_133420* w, char* name);
void cGameSystem_SendAgentData(World_133420* w, int a, int b);
}

static inline float Lerp(float a, float b, float t) { return a + t * (b - a); }
static inline EnvVec3_133420* Color(EnvBlend_133420* e, EnvVec3_133420* tmp)
{
    if (e->active) {
        float ax, ay, az;
        az = e->colorFrom.z;
        ay = e->colorFrom.y;
        ax = e->colorFrom.x;
        float z = Lerp(az, e->colorTo.z, e->frac);
        float y = Lerp(ay, e->colorTo.y, e->frac);
        float x = Lerp(ax, e->colorTo.x, e->frac);
        tmp->x = x;
        tmp->y = y;
        tmp->z = z;
        return tmp;
    }
    return &e->cur->color;
}
static inline float FogFar(EnvBlend_133420* e) { return e->active ? Lerp(e->fogFarFrom, e->fogFarTo, e->frac) : e->cur->fogFar; }
static inline float FogNear(EnvBlend_133420* e) { return e->active ? Lerp(e->fogNearFrom, e->fogNearTo, e->frac) : e->cur->fogNear; }
static inline float ZNear(EnvBlend_133420* e) { return e->active ? Lerp(e->zNearFrom, e->zNearTo, e->frac) : e->cur->zNear; }
static inline float ZFar(EnvBlend_133420* e) { return e->cur->zFar; }
/* cvt.w.s+mfc1: a C (int) cast compiles to trunc.w.s */
static inline int F2I(float f) { int r; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }
static inline int Ne(Iter* a, Iter* b) { return (a->p == b->p) ^ 1; }

static inline bool Live(Actor_133420* a) { return a->b2D && a->b2C && !a->b2E; }

extern "C" int cGameSystem_NextFrame(World_133420* self)
{
    float dt = cGameSystem_UpdateTimeStep(self);
    if (self->paused) {
        self->ui->Update(dt);
        cHud_NextFrame(self->hud, dt);
        return 1;
    }
    cEnvMan_NextFrame(self->env, dt);
    {
        EnvVec3_133420 tmp;
        EnvVec3_133420* c = Color(self->env, &tmp);
        float s = 256.0f;
        float z, x, y;
        z = c->z;
        y = c->y;
        x = c->x;
        z *= s;
        D_0053836C = s;
        D_0053835C = 0x80;
        D_00538368 = z;
        D_00538358 = F2I(z);
        x *= s;
        y *= s;
        {
            int ix = F2I(x);
            D_00538360 = x;
            D_00538364 = y;
            D_00538350 = ix;
        }
        D_00538354 = F2I(y);
    }
    {
        EnvBlend_133420* e = self->env;
        float f = FogFar(e);
        float n = FogNear(e);
        D_00538340 = n;
        D_00538344 = f;
        XLib_UpdateFogParms(g_Video);
    }
    {
        EnvBlend_133420* e = self->env;
        float f = ZFar(e);
        float n = ZNear(e);
        D_00538348 = n;
        g_LevelFarDistance = f;
        XLib_UpdateFogParms(g_Video);
    }
    {
        void* arr = nGobjManager_GetGOBJList();
        Iter it, end, tb, te;
        cArray_cGOBJPtr_Begin(&tb, cObjList_cGOBJPtr_GetList(arr));
        cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&it, &tb);
        cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr));
        cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te);
        while (Ne(&it, &end)) {
            Actor_133420* a = (Actor_133420*)*it.p;
            a->Think(dt);
            if (Live(a))
                a->Update(dt);
            it.p++;
            cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr));
            cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te);
        }
    }
    cMotionManager_NextFrame(dt);
    UpdateDarkness();
    nGobjManager_PurgeRemovals();
    cBulletManager_NextFrame(dt);
    nDynamicSfxList_NextFrame(dt);
    {
        Msg_133420 m;
        cMessage_ctor_cMessageNameR(&m, D_005436B0);
        m.vt = D_004D9160;
        QueueMessage_cMessageR_cSystemP_int(&m, self->receiver, 1);
        m.vt = D_004D9160;
        cMessage_dtor(&m, 0);
    }
    cHud_NextFrame(self->hud, dt);
    cVisionFxMan_NextFrame(self->vision, dt);
    cWaterFx_NextFrame(self->water, dt);
    cScreenFader_NextFrame(self->fader, dt);
    cDecalMan_NextFrame(self->decals, dt);
    nRumbleManager_NextFrame(dt);
    if (self->tremors) cTremorManager_NextFrame(self->tremors, dt);
    cBackpack_Update(dt);
    {
        Msg_133420 m;
        cMessage_ctor_cMessageNameR(&m, D_005436B0);
        m.vt = D_004D9160;
        QueueMessage_cMessageR_cSystemP_int(&m, cSystemContainer_GetSystem(self, D_004F2CC0), 1);
        m.vt = D_004D9160;
        cMessage_dtor(&m, 0);
    }
    nGobjManager_PurgeRemovals();
    if (g_IsMultiplayer) {
        self->netTimer += dt;
        if (self->netTimer > (float)D_00489BC0) {
            self->netTimer = 0.0f;
            cGameSystem_SendAgentData(self, 1, 0);
        }
    }
    return 1;
}
