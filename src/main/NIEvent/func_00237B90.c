#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* cNIEventLight_v42 (update): runs the light event's animation (time scaled
 * by its speed while playing, or once at 0 when it becomes ready), sends the
 * finished message when playback stopped, steps the inner/outer radius
 * tracks, and keeps a point light from the light manager in sync with the
 * owner while the event is active (released otherwise). Light class as in
 * cNIEventLight_v16 (NIEvent_237A20.c); light creation as in
 * SpawnLightEffect_Construct (SpecFxDefs_231F00.c). */
#pragma always_inline on
#pragma inline_depth(8)
typedef struct { float x, y, z, w; } V4_7B90;
class Light_7B90 {
public:
    int id;
    virtual void dtor(int flag);
    VPAD4(a) VPAD2(b) VPAD1(c)
    virtual void Move(void* m);
    virtual void Enable();
    virtual void stop();
    char p8[0x10 - 8];
    float inner;
    float outer;
    char p18[0x1D - 0x18];
    unsigned char flags;
};
class Owner_7B90 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char p4[0x40 - 4];
    char mtx[0x10];
    unsigned char dirty;
};
typedef struct { float value; char pad[0x20 - 4]; } Track_7B90;
class Ev_7B90 {
public:
    VPAD32(a) VPAD32(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual void Play(float t);
    char p4[0x2C - 4];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
    char p2F[0x50 - 0x2F];
    Owner_7B90* owner;
    char p54[0x60 - 0x54];
    int state;
    char p64[0xDC - 0x64];
    unsigned char active;
    char pDD[0x130 - 0xDD];
    unsigned char playing;
    char p131[3];
    float speed;
    char p138[0x140 - 0x138];
    Light_7B90* light;
    float pos[3];
    unsigned char b150;
    unsigned char b151;
    char p152[0x170 - 0x152];
    Track_7B90 a;
    Track_7B90 b;
};
typedef struct { void* vt; char pad[0x20]; int x24; char pad28[0x30 - 0x28]; } Msg_7B90;
extern "C" {
extern char g_LightMgr[];
extern char D_004F7C30[];
extern char D_004DBEB0[];
extern char D_004D9200[];
void Event_Construct(Msg_7B90* e, void* type);
void Event_Send(Msg_7B90* e, void* target, int a);
void cMessage_dtor(Msg_7B90* e, int f);
void Actor_BaseLogicUpdate(Ev_7B90* self, float dt);
void NiRotationTrack_Update(float t, Track_7B90* tr);
Light_7B90* LightMgr_AllocPoint(void* pool, int n);
V4_7B90* Vec4_SetFromVec3W(V4_7B90* out, float* in, float w);
void LevelLight_InitPoint(Light_7B90* l, int n, V4_7B90* pos, void* m, int k);
void LightEffect_SetInner(Light_7B90* l, float f);
void LightEffect_SetOuter(Light_7B90* l, float f);
void cNIEventLight_v42(Ev_7B90* self, float dt);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Ev_7B90* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline Owner_7B90* SyncedOwner(Ev_7B90* self) { Owner_7B90* o = self->owner; if (o->dirty) o->Sync(); return o; }

extern "C" void cNIEventLight_v42(Ev_7B90* self, float dt)
{
    unsigned char playing = self->playing;
    if (playing || (self->state == 3 && self->active && Ready(self))) {
        float t = dt * self->speed;
        self->Play(playing ? t : 0.0f);
        if (playing && !self->playing) {
            Msg_7B90 e;
            Event_Construct(&e, D_004F7C30);
            e.vt = D_004DBEB0;
            e.x24 = 0;
            Event_Send(&e, self, 0);
            e.vt = D_004DBEB0;
            cMessage_dtor(&e, 0);
        }
    }
    Actor_BaseLogicUpdate(self, dt);
    if (self->playing) {
        NiRotationTrack_Update(dt * self->speed, &self->a);
        NiRotationTrack_Update(dt * self->speed, &self->b);
    }
    if (Ready(self) && self->active) {
        if (!self->light) {
            Light_7B90* l = LightMgr_AllocPoint(g_LightMgr, 4);
            if (l) {
                Owner_7B90* o;
                float inner, outer;
                V4_7B90 v;
                inner = self->a.value;
                outer = self->b.value;
                o = SyncedOwner(self);
                LevelLight_InitPoint(l, 4, Vec4_SetFromVec3W(&v, self->pos, 0.0f), o->mtx, 3);
                *(void**)((char*)l + 4) = D_004D9200;
                LightEffect_SetInner(l, inner);
                LightEffect_SetOuter(l, outer);
            }
            self->light = l;
            if (self->light) {
                self->light->Enable();
                if (self->b151)
                    self->light->flags |= 8;
                if (self->b150)
                    self->light->flags |= 0x10;
            }
        } else {
            Owner_7B90* o = SyncedOwner(self);
            self->light->Move(o->mtx);
            self->light->inner = self->a.value;
            self->light->outer = self->b.value;
        }
    } else if (self->light) {
        self->light->stop();
        if (self->light)
            self->light->dtor(1);
        self->light = 0;
    }
}
