#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
typedef struct SoundRequest_5D40 {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest_5D40;
typedef struct EffectMsg_5D40 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
    int tail[1];
} EffectMsg_5D40;
class Obj_5D40 {
public:
    VPAD16(a) VPAD4(b) VPAD1(d)
    virtual void v5C(int on);
    virtual void v60(int on);
    char pad4[0x8];
    int serial;
};
struct H_5D40 { Obj_5D40* obj; int serial; bool V() const { return !obj || obj->serial == serial; } Obj_5D40* G() const { return V() ? obj : 0; } };
struct Actor_5D40 {
    char pad0[0x326A];
    unsigned char b326A;
    char pad326B[0x34E0 - 0x326B];
    Obj_5D40* fire;
    char pad34E4[0x354C - 0x34E4];
    H_5D40 h[2];
};
extern "C" {
extern char D_0049D8D0[];
extern char D_0049D8E0[];
extern char g_Game[];
extern char D_004DADF0[];
extern int D_0048A2D8[];
extern int D_0048A2E8[];
extern float D_0048A1E0;
extern float D_0048A1D8;
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
Obj_5D40* cHumanParticleGroup_ctor(void* p, Actor_5D40* self, int a, int b, float f);
Obj_5D40* cFireObj_ctor_cGOBJP_float_float(void* p, Actor_5D40* self, float r, float t);
void nGobjManager_AddGOBJ(Obj_5D40* o);
void nGobjManager_RemoveGOBJ(Obj_5D40* o);
void cSystem_ActualScheduleDelete(Obj_5D40* o, float t);
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest_5D40* req, int kind, char* name, void* a, int b);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(EffectMsg_5D40* msg, SoundRequest_5D40* req, Actor_5D40* self);
void QueueMessage_cMessageR_cSystemP_int(EffectMsg_5D40* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(EffectMsg_5D40* msg, int flags);
}
static inline bool V_5D40(H_5D40* h) { return !h->obj || h->obj->serial == h->serial; }
static inline Obj_5D40* G_5D40(H_5D40* h) { return V_5D40(h) ? h->obj : 0; }
static inline const int& IdOf_5D40(Obj_5D40* p) { if (p) return p->serial; int m = -1; return m; }
static inline void SetH_5D40(H_5D40* h, Obj_5D40* p) { h->obj = p; h->serial = IdOf_5D40(p); }
static inline void* Alloc_5D40(unsigned int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_0049D8D0, line);
}
extern "C" void cHuman_SetParticleEffect(Actor_5D40* self, int idx, int on, float f)
{
    if (on) {
        if (!self->h[(unsigned char)idx].G()) {
            Obj_5D40* p = (Obj_5D40*)Alloc_5D40(0x88, 0x43CD);
            if (p) p = cHumanParticleGroup_ctor(p, self, D_0048A2D8[(unsigned char)idx], D_0048A2E8[(unsigned char)idx], f);
            SetH_5D40(&self->h[(unsigned char)idx], p);
            if ((unsigned char)idx == 0) {
                Obj_5D40* q = (Obj_5D40*)Alloc_5D40(0xA0, 0x43D1);
                if (q) q = cFireObj_ctor_cGOBJP_float_float(q, self, D_0048A1E0, D_0048A1D8);
                self->fire = q;
            }
            nGobjManager_AddGOBJ(self->h[(unsigned char)idx].G());
            self->h[(unsigned char)idx].G()->v5C(1);
        }
    } else {
        if (self->h[(unsigned char)idx].G()) {
            self->h[(unsigned char)idx].G()->v60(1);
            nGobjManager_RemoveGOBJ(self->h[(unsigned char)idx].G());
            cSystem_ActualScheduleDelete(self->h[(unsigned char)idx].G(), 0.1f);
            SetH_5D40(&self->h[(unsigned char)idx], 0);
        }
        if ((unsigned char)idx == 0) {
            self->b326A = 0;
            SoundRequest_5D40 req;
            cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, D_0049D8E0, 0, 0);
            EffectMsg_5D40 msg;
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, self);
            msg.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
            if (self->fire) {
                nGobjManager_RemoveGOBJ(self->fire);
                cSystem_ActualScheduleDelete(self->fire, 0.1f);
                self->fire = 0;
            }
            msg.vtbl = D_004DADF0;
            cFileMan_dtor(msg.partB, -1);
            cFileMan_dtor(msg.partA, -1);
            cMessage_dtor(&msg, 0);
            cFileMan_dtor(req.partB, -1);
            cFileMan_dtor(req.partA, -1);
        }
    }
}
