#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V& operator=(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
} __attribute__((aligned(16)));
struct Mtx { V r[4]; };
struct Sub110 { char pad[0x64]; int* p64; };
struct Ctl3584 { char pad[0x33]; unsigned char b33; };
struct Obj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual Mtx GetMatrix();
    virtual int GetVec(V* out);
    VPAD4(f) VPAD1(g)
    virtual Sub110* Get110();
    char pad[0x10]; unsigned char b14; char pad15[0x3584 - 0x15]; Ctl3584* p3584;
};
struct Player { char pad[0x30]; Obj* obj; char pad34[0x50 - 0x34]; char input[0x1A0 - 0x50]; int x1A0; char pad1A4[4]; float f1A8; float f1AC; char pad1B0[0x10]; int t1C0; };


extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_00582B88;
extern int g_Hud;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004E0100[];
int Net_GetClock(int);
V* cMatrix_GetAxis(Mtx*, int);
float Math_Atan2f(float, float);
void Event_Construct(void*, void*);
void Event_Send(void*, void*, int);
void cMessage_dtor(void*, int);
void PlayerInput_Update(void*, int, Obj*, float);
void PlayerInput_DrawDebugCamera(void*, int, Obj*);
void HudRadar_SetMeter(int, int, float);
}

struct MsgBase { void* vt; char pad[0x20]; int x24; unsigned char x28;
    MsgBase(void* n) { Event_Construct(this, n); vt = D_004E0840; x24 = 0; x28 = 0xD; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgBase() { vt = D_004E0840; cMessage_dtor(this, 0); }
};
static inline float Min(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Payload { V a; V b; float ang; float s; int id;
    Payload(const V& pa, const V& pb, float g, float sc, int i) { Payload* t = this; t->a = pa; t->b = pb; t->ang = g; t->s = Min(sc, 1.0f); t->id = i; }
};
struct Msg : MsgBase { char pad2c[4]; Payload p;
    Msg(const V& pa, const V& pb, float g, float sc, int i) : MsgBase(g_ActorActionMsgClass), p(pa, pb, g, sc, i) { vt = D_004E0100; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vt = D_004E0100; }
};
static inline float Yaw(Mtx& m) {
    V r0 = *cMatrix_GetAxis(&m, 0);
    V r1 = *cMatrix_GetAxis(&m, 1);
    float a = r1.z; float b = r0.z; if (b < a) { float x = r0.x; return Math_Atan2f(r0.y, x); }
    return Math_Atan2f(-r1.x, r1.y);
}
extern "C" void Player_Update(Player* self, float dt)
{
    if (g_IsMultiplayer) {
        Obj* o = self->obj;
        if (o->b14) {
            if (o && o->p3584)
                o->p3584->b33 = D_00582B88;
            if (self->t1C0 < Net_GetClock(1)) {
                Mtx m = self->obj->GetMatrix();
                V v;
                const V& pos = m.r[3];
                int id = 0;
                if (!o->GetVec(&v)) {
                    V z; z.x = 0; z.y = 0; z.z = 0; z.w = 0;
                    v = z;
                } else {
                    Sub110* s = o->Get110();
                    if (s) id = *s->p64;
                }
                { Msg msg(pos, v, Yaw(m), 1.0f, id);
                Event_Send(&msg, self->obj, 0); }
                self->t1C0 = Net_GetClock(1) + 250;
            }
        }
    }
    { Obj* ob = self->obj; PlayerInput_Update(self->input, self->x1A0, ob, dt); }
    { Obj* ob = self->obj; PlayerInput_DrawDebugCamera(self->input, self->x1A0, ob); }
    HudRadar_SetMeter(g_Hud + 0xD0, 1, self->f1AC);
    self->f1A8 = 0;
    self->f1AC = 0;
}
