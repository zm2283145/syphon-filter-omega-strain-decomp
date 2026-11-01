/*
 * SFOGame/Source/human: 3 files, 00185A30-00185D40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00185A30 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#pragma push
class V58_5A { public: VPAD16(p) VPAD2(q) virtual void v18(); virtual int v19(); };
class T_5A { public: VPAD16(p) VPAD2(q) virtual void v18(); virtual void v19(); virtual void v20();
    char pad4[0xC]; char sub10[0x40]; unsigned char b50; };
typedef struct { char pad0[8]; int id; char padC[4]; } Slot_5A;
typedef struct { Slot_5A slots[8]; char pad80[4]; unsigned char cur; } Weap_5A;
typedef struct { short ids[4]; int f; } Ids_5A;
typedef struct { char pad0[0x40]; char m40[0x40]; } Sub_5A;
typedef struct {
    char pad0[0xC]; int iC; int i10; char pad14[0x18];
    unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x11];
    float f40; char pad44[0xC]; T_5A* p50; char pad54[4]; V58_5A* o58; char pad5C[4];
    Sub_5A sub60; char padE0[0x3318 - 0xE0]; char m3318[0x3524 - 0x3318]; Weap_5A* weapons;
    char pad3528[0x3590 - 0x3528]; unsigned char b3590;
} O_5A;
static const Ids_5A D_0048A2F8 = { { -1, -1, -1, -1 }, -1 };
static inline bool Ready_5A(O_5A* o) { return o->b2D && o->b2C && !o->b2E; }
extern "C" void netCreatePlayer_SendCreated(int a, int b, int c, void* d, void* e, Ids_5A* ids, int f);
extern "C" void netCreateNPC_SendCreated(int a, int b, int c, void* d, void* e, Ids_5A* ids, unsigned char r, unsigned char g, int f);
extern "C" int cHuman_SendCreated(O_5A* o, int a)
{
    if (Ready_5A(o)) {
        Ids_5A ids = D_0048A2F8;
        if (o->weapons) {
            int i;
            short* p;
            short first;
            Weap_5A* w = o->weapons;
            first = ids.ids[0] = (w->cur != 6) ? w->slots[w->cur].id : -1;
            i = 0;
            p = &ids.ids[1];
            for (; i < 6; i++) {
                int v = o->weapons->slots[(unsigned char)i].id;
                if (v != -1 && first != v) *p++ = v;
            }
        }
        bool ok = false;
        if (o->o58 && o->o58->v19()) ok = true;
        if (ok) {
            T_5A* t = o->p50;
            int b = o->i10;
            int c = o->iC;
            Sub_5A* s = &o->sub60;
            int f = (int)o->f40;
            if (t->b50) t->v20();
            netCreatePlayer_SendCreated(a, b, c, t->sub10, s->m40, &ids, f);
        } else {
            int b;
            int c;
            unsigned char r;
            T_5A* t;
            char* e;
            int v = o->b2D;
            b = o->i10;
            c = o->iC;
            t = o->p50;
            e = o->m3318;
            if (v) v = o->b2C;
            r = v;
            if (v) r = !o->b2E;
            int f = (int)o->f40;
            if (t->b50) t->v20();
            netCreateNPC_SendCreated(a, b, c, t->sub10, e, &ids, r, o->b3590, f);
        }
    }
    return 1;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185A30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185A30 */

/* merge_units: begin func_00185C70 */
#pragma push /* merge_units */
#pragma cplusplus on
class C_185C70 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct O_185C70 { char pad[0xC]; unsigned int id; char pad10[0x48]; C_185C70* ctl; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern char g_Game[];
void* cGameSystem_GetAgentData(void* list, int idx);
}
static inline unsigned char Has_185C70(O_185C70* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
extern "C" void* cHuman_GetAgentData(O_185C70* o)
{
    int idx;
    if (g_IsMultiplayer) {
        if (Has_185C70(o)) idx = ((o->id & 0x7F000000) >> 24) - 1;
        else idx = -1;
    } else {
        idx = 0;
    }
    if (Has_185C70(o)) return cGameSystem_GetAgentData(g_Game, idx);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185C70 */

/* merge_units: begin func_00185D40 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_00185D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185D40 */
