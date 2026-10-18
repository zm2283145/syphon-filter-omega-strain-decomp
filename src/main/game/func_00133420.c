/* World_UpdateFrame: per-frame world update - environment blend and fog terms, actor updates,
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
extern float D_0053834C;
extern int D_00538350;
extern int D_00538354;
extern int D_00538358;
extern int D_0053835C;
extern float D_00538360;
extern float D_00538364;
extern float D_00538368;
extern float D_0053836C;
extern char D_005381F0[];
extern char D_005436B0[];
extern char D_004D9160[];
extern char D_004F2CC0[];
extern unsigned char D_005721C8;
extern int D_00489BC0;
float World_GetElapsedTime(World_133420* w);
void Hud_Update(Hud_133420* h, float dt);
void func_00178440(EnvBlend_133420* e, float dt);
void Fog_ComputeTerms(char* fog);
void* World_GetActorArray(void);
PtrVec* func_001339A0(void* arr);
void PtrVec_Begin(Iter* out, PtrVec* v);
void PtrVec_End(Iter* out, PtrVec* v);
Iter* func_00133980(Iter* out, Iter* in);
void World_PhysicsTraversal(float dt);
void Actor_UpdateStealthLight(void);
void ActorWorld_FlushPending(void);
void BulletPool_Update(float dt);
void EffectService_UpdateAll(float dt);
void Event_Construct(Msg_133420* m, char* desc);
void Event_Send(Msg_133420* m, void* target, int immediate);
void cMessage_dtor(Msg_133420* m, int flags);
void VisionMgr_CommitMode(void* v, float dt);
void WaterFx_Update(void* w, float dt);
void ActorFader_Update(void* f, float dt);
void DecalMgr_Update(void* d, float dt);
void Tremor_UpdateVibration(float dt);
void TremorList_Update(void* t, float dt);
void Backpack_Tick(float dt);
void* Service_Lookup(World_133420* w, char* name);
void Game_NetSendPauseState(World_133420* w, int a, int b);
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

extern "C" int World_UpdateFrame(World_133420* self)
{
    float dt = World_GetElapsedTime(self);
    if (self->paused) {
        self->ui->Update(dt);
        Hud_Update(self->hud, dt);
        return 1;
    }
    func_00178440(self->env, dt);
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
        Fog_ComputeTerms(D_005381F0);
    }
    {
        EnvBlend_133420* e = self->env;
        float f = ZFar(e);
        float n = ZNear(e);
        D_00538348 = n;
        D_0053834C = f;
        Fog_ComputeTerms(D_005381F0);
    }
    {
        void* arr = World_GetActorArray();
        Iter it, end, tb, te;
        PtrVec_Begin(&tb, func_001339A0(arr));
        func_00133980(&it, &tb);
        PtrVec_End(&te, func_001339A0(arr));
        func_00133980(&end, &te);
        while (Ne(&it, &end)) {
            Actor_133420* a = (Actor_133420*)*it.p;
            a->Think(dt);
            if (Live(a))
                a->Update(dt);
            it.p++;
            PtrVec_End(&te, func_001339A0(arr));
            func_00133980(&end, &te);
        }
    }
    World_PhysicsTraversal(dt);
    Actor_UpdateStealthLight();
    ActorWorld_FlushPending();
    BulletPool_Update(dt);
    EffectService_UpdateAll(dt);
    {
        Msg_133420 m;
        Event_Construct(&m, D_005436B0);
        m.vt = D_004D9160;
        Event_Send(&m, self->receiver, 1);
        m.vt = D_004D9160;
        cMessage_dtor(&m, 0);
    }
    Hud_Update(self->hud, dt);
    VisionMgr_CommitMode(self->vision, dt);
    WaterFx_Update(self->water, dt);
    ActorFader_Update(self->fader, dt);
    DecalMgr_Update(self->decals, dt);
    Tremor_UpdateVibration(dt);
    if (self->tremors) TremorList_Update(self->tremors, dt);
    Backpack_Tick(dt);
    {
        Msg_133420 m;
        Event_Construct(&m, D_005436B0);
        m.vt = D_004D9160;
        Event_Send(&m, Service_Lookup(self, D_004F2CC0), 1);
        m.vt = D_004D9160;
        cMessage_dtor(&m, 0);
    }
    ActorWorld_FlushPending();
    if (D_005721C8) {
        self->netTimer += dt;
        if (self->netTimer > (float)D_00489BC0) {
            self->netTimer = 0.0f;
            Game_NetSendPauseState(self, 1, 0);
        }
    }
    return 1;
}
