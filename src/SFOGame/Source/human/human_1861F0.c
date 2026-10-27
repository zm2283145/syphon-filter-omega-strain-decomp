/*
 * main/human: range (2 files, 001861F0-00186360)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_001861F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_61F0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_61F0 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_61F0* ctl; };
extern "C" {
void* cGameSystem_GetAgentData(void*, int);
int cAgentData_HasSpecialBonus(void*, int);
extern char g_Game[];
extern float D_0048A2D0;
extern unsigned char g_IsMultiplayer;
}
static inline unsigned char IsPlayer_61F0(Hum_61F0* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int IsPlayerB_61F0(Hum_61F0* h) { int b = h->ctl != 0; if (b) b = h->ctl->IsPlayer(); return b; }
static inline int LocalId_61F0(Hum_61F0* h) { int id; if (g_IsMultiplayer) { if (IsPlayer_61F0(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline void* Agent_61F0(Hum_61F0* h) { return IsPlayerB_61F0(h) ? cGameSystem_GetAgentData(g_Game, LocalId_61F0(h)) : 0; }
/* clips granted to an actor: the player's count is scaled when the agent has perk 5 */
#pragma push
#pragma opt_propagation off
extern "C" int cHuman_AdjustMaxClips(Hum_61F0* h, int n)
{
    int r = n;
    if (IsPlayer_61F0(h)) {
        int id = LocalId_61F0(h); void* ag = IsPlayerB_61F0(h) ? cGameSystem_GetAgentData(g_Game, id) : 0;
        if (cAgentData_HasSpecialBonus(ag, 5)) {
            r = (int)(n * D_0048A2D0);
            if (r == n) r++;
        }
    }
    return r;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001861F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001861F0 */

/* merge_units: begin func_00186360 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char d[0x9C]; } Str_00186360;
struct Req_00186360 { char pad0[0x48]; Str_00186360 s48; Str_00186360 sE4; char pad180[0x10]; };
struct Snd_00186360 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00186360 s78;
    Str_00186360 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Snd2_00186360 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00186360 s78;
    Str_00186360 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16)));
struct Msg_00186360 { void* vt; char pad4[0x18]; int f1C; unsigned char b20; char pad21[3]; int kind; unsigned char b28; char pad29[3]; int id; int on; };
struct Obj_00186360 { char pad[0xC]; int id; };
struct Npc_00186360 {
    char pad0[0x31F4]; float f31F4; char pad31F8[0x326A - 0x31F8]; unsigned char b326A;
    char pad326B[0x33A4 - 0x326B]; unsigned char b33A4; char pad33A5[0x33B8 - 0x33A5]; unsigned char b33B8;
    char pad33B9[0x3480 - 0x33B9]; Obj_00186360* p3480; int id3484; unsigned char b3488;
};
extern "C" {
extern char D_0049D8E0[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern char g_ActorActionMsgClass[];
extern "C" void cMessage_getSOBJClassId();
extern "C" void func_00186670();
extern "C" void cCharActionMsg_ObjectId_Int_Pack();
extern "C" void cCharActionMsg_ObjectId_Int_Clone();
void * const D_004E0180[8] = { (void*)0x0, (void*)0x0, (void*)func_00186670, (void*)cCharActionMsg_ObjectId_Int_Clone, (void*)cCharActionMsg_ObjectId_Int_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern char D_004E0840[];
void cHuman_SetParticleEffect(Npc_00186360* self, int a, int b, float f);
void cSndFx_ctor_int_charP_cGOBJP_int(Req_00186360* r, int a, char* name, int b, int c);
void cPlaySoundMsg_ctor_cSndFxR(Snd_00186360* e, Req_00186360* r, void* owner);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Snd2_00186360* e, Req_00186360* r, void* owner);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cFileMan_dtor(Str_00186360* s, int flag);
}
static inline int GetId_00186360(Obj_00186360* o, int& t)
{
    int* p;
    if (o) {
        p = &o->id;
    } else {
        t = -1;
        p = &t;
    }
    return *p;
}
extern "C" void Actor_Ignite(Npc_00186360* self, unsigned char on, Obj_00186360* obj, unsigned char a3, int quiet, float f)
{
    int t2;
    int t1;
    unsigned char old = self->b326A;
    if (self->b33B8 || self->b33A4)
        self->b326A = 0;
    else
        self->b326A = on;
    if (!old && self->b326A) {
        cHuman_SetParticleEffect(self, 0, 1, 0.4f);
        cHuman_SetParticleEffect(self, 1, 1, 0.4f);
        self->f31F4 = f;
        self->p3480 = obj;
        self->id3484 = GetId_00186360(obj, t1);
        self->b3488 = a3;
        {
            Req_00186360 req;
            Snd_00186360 ev;
            cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, D_0049D8E0, 0, 0);
            cPlaySoundMsg_ctor_cSndFxR(&ev, &req, self);
            ev.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
            ev.vt = D_004DAE30;
            cFileMan_dtor(&ev.s114, -1);
            cFileMan_dtor(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
            cFileMan_dtor(&req.sE4, -1);
            cFileMan_dtor(&req.s48, -1);
        }
    } else if (!self->b326A) {
        cHuman_SetParticleEffect(self, 0, 0, 1.0f);
        cHuman_SetParticleEffect(self, 1, 0, 1.0f);
        {
            Req_00186360 req;
            Snd2_00186360 ev;
            cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, D_0049D8E0, 0, 0);
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev, &req, self);
            ev.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
            ev.vt = D_004DADF0;
            cFileMan_dtor(&ev.s114, -1);
            cFileMan_dtor(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
            cFileMan_dtor(&req.sE4, -1);
            cFileMan_dtor(&req.s48, -1);
        }
    }
    if (g_IsMultiplayer && !quiet) {
        int id = GetId_00186360(obj, t2);
        int st = self->b326A;
        Msg_00186360 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.kind = 0x44;
        m.b28 = 6;
        m.id = id;
        m.on = st;
        m.vt = ((char*)D_004E0180);
        m.b20 = 4;
        m.f1C = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vt = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00186360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00186360 */
