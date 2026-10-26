#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* cGenerator_v05: send a newly joined peer the generator's state - enable flag, active flag and
   rate - and a spawn record for every live spawned actor still in the generator's list. */
typedef union { __int128 q; struct { float x, y, z, w; } f; } GvV4;
struct GvMtx { GvV4 r[3]; GvV4 t; };
struct GvNode { VPAD16(a) VPAD4(b) virtual void Refresh(); int pad4[3]; GvMtx m; unsigned char dirty; };
struct GvObj {
    VPAD32(a) VPAD32(b) virtual unsigned char State();
    int pad4[2];
    int id;
    int x10;
    char pad14[0x2C - 0x14];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x50 - 0x2F];
    GvNode* node;
    char pad54[0x31F0 - 0x54];
    int rnd;
    char pad31F4[0x3548 - 0x31F4];
    int route;
};
struct GvHnd { GvObj* p; int id; };
struct GvNodeL { GvNodeL* prev; GvNodeL* next; GvHnd h; };
struct GvIt {
    GvNodeL* n;
    GvIt() {}
    bool operator!=(const GvIt& o) const { return n != o.n; }
};
struct GvGen {
    char pad0[0x10];
    int id;
    char pad14[0x2C - 0x14];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x68 - 0x2F];
    int x68;
    char pad6C[0x90 - 0x6C];
    char list90[0xC];
    char pad9C[0xB8 - 0x9C];
    float rate;
    char padBC[0xD1 - 0xBC];
    unsigned char active;
};
struct GvEnMsg {
    void* vt; char pad4[0x1C - 0x4]; int flags; unsigned char kind; char pad21[3];
    int player;
};
struct GvSetMsg { void* vt; char pad4[0x1C - 0x4]; int flags; unsigned char kind; char pad21[3]; int arg; unsigned char what; };
struct GvSpMsg {
    void* vt;
    char pad4[0x1C - 0x4];
    int x1C;
    unsigned char x20;
    char pad21[0x30 - 0x21];
    GvV4 pos;
    GvV4 rot;
    int id;
    int x54;
    int x58;
    int rnd;
    int route;
};
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern char g_cEnableMsgClass[];
extern int D_0055D4C0;
extern int D_0051F060;
extern char D_004A4A78[];
extern char D_0051F058[];
extern char D_004E0880[];
extern char D_004DB5E0[];
extern char D_004DE240[];
int NetGame_InitLocalSlot(int* slot, int v);
int Player_GetIndex(int id);
int Event_Construct(void* msg, void* name);
int cMessage_dtor(void* msg, int flags);
unsigned char NetObj_SendMessage(int a, int b, void* c, int target, int type);
int Transport_Send(int id, void* msg, int flags, int peer);
void Mtx_ToEuler(GvV4* out, GvMtx* m);
GvNodeL* func_0021E000(void* l);
GvIt* func_0021DFE0(GvIt* it, GvNodeL* n);
GvIt* func_0021DFF0(GvIt* it, GvNodeL* n);
int cGenerator_v05(GvGen* self, int peer);
int cEnableMsg_v02(GvEnMsg* m, int id, int* len, int a, int b, int max, char* buf);
int func_002D1100(GvSpMsg* m, int id, int* len, int a, int b, int max, char* buf);
}
static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void QZ(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; __asm__ volatile("lq %0, 0x0(%1)" : "+r"(q) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(d) : "memory"); }
static inline void MsgInit(GvSpMsg* m, int id, int x10, int x68) { Event_Construct(m, D_0051F058); m->vt = D_004DE240; m->id = id; m->x54 = x10; m->x58 = x68; }
static inline int* IdPtr(GvObj* o) { int* p = &o->id; return p; }
static inline int NetSlot(int a) { int r = 0; if (g_IsMultiplayer) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a); return D_00494178; } return r; }
static inline bool Not(unsigned char x) { return !x; }
static inline bool ReadyG(GvGen* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline bool ReadyO(GvObj* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline bool IdEq(GvObj* p, GvHnd* h) { return p->id == h->id; }
static inline GvObj* HGet(GvHnd* h) {
    bool ok = (h->p != 0) ^ 1 || IdEq(h->p, h);
    unsigned char k = ok;
    return k ? h->p : 0;
}
static inline GvIt Begin(void* l) { GvIt t; func_0021DFF0(&t, func_0021E000(l)->next); return t; }
static inline GvIt End(void* l) { GvIt t; func_0021DFE0(&t, func_0021E000(l)); return t; }

int cGenerator_v05(GvGen* self, int peer)
{
    int len;
    char buf[0x400];
    GvEnMsg em;
    GvSetMsg m2;
    GvSetMsg m3;
    GvSpMsg msg;
    GvMtx mc;
    GvV4 e;
    int id = self->id;
    if (NetSlot(D_005721A8) == Player_GetIndex(id)) {
        if (ReadyG(self)) {
            GvEnMsg* pe;
            int slot = NetSlot(D_005721A8);
            pe = &em;
            int r;
            Event_Construct(pe, g_cEnableMsgClass);
            pe->vt = D_004E0880;
            pe->player = slot;
            pe->flags = 0x40;
            em.kind = 4;
            r = cEnableMsg_v02(&em, self->id, &len, 0, 0, 0x400, buf);
            if (r > -1)
                NetObj_SendMessage(D_0055D4C0, r, buf, peer, 0);
            em.vt = D_004E0880;
            cMessage_dtor(&em, 0);
        }
        {
            unsigned char on = self->active;
            GvSetMsg* p = &m2;
            Event_Construct(p, D_004A4A78);
            p->vt = D_004DB5E0;
            p->arg = on;
            p->what = 0;
            m2.kind = 4;
            Transport_Send(self->id, p, 0, peer);
            m2.vt = D_004DB5E0;
            cMessage_dtor(p, 0);
        }
        {
            float rate = self->rate;
            GvSetMsg* p = &m3;
            Event_Construct(p, D_004A4A78);
            p->vt = D_004DB5E0;
            p->arg = (int)rate;
            p->what = 1;
            m3.kind = 4;
            Transport_Send(self->id, p, 0, peer);
            m3.vt = D_004DB5E0;
            cMessage_dtor(p, 0);
        }
        {
            GvIt it;
            for (it = Begin(self->list90); it != End(self->list90); it.n = it.n->next) {
                GvObj* t = HGet(&it.n->h);
                if (ReadyO(t) && t->State() != 3) {
                    int r;
                    GvNode* n;
                    GvSpMsg* m;
                    int oid;
                    int onet;
                    int grp;
                    int rnd;
                    int route;
                    route = t->route;
                    rnd = t->rnd;
                    n = t->node;
                    if (n->dirty) n->Refresh();
                    { GvMtx* src = &n->m; GvMtx* dst = &mc; Q4(dst, src); }
                    m = &msg;
                    oid = *IdPtr(t);
                    grp = self->x68;
                    onet = t->x10;
                    MsgInit(m, oid, onet, grp);
                    Mtx_ToEuler(&e, &mc);
                    QZ(&m->rot, &e);
                    m->pos = mc.t;
                    m->rnd = rnd;
                    m->route = route;
                    m->x1C = 0x40;
                    msg.x20 = 4;
                    r = func_002D1100(&msg, self->id, &len, 0, 0, 0x400, buf);
                    if (r > -1)
                        NetObj_SendMessage(D_0051F060, r, buf, peer, 0);
                    msg.vt = D_004DE240;
                    cMessage_dtor(&msg, 0);
                }
            }
        }
    }
    return 1;
}
