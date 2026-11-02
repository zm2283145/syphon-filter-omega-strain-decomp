/*
 * SFOGame/Source/Generator: 7 files, 0021D6C0-0021DF80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D6C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node21D6C0;
typedef struct { void* vt; char p4[0x20]; void* f24; signed char f28; char p29[3]; } Evt21D6C0;
typedef struct { int f0; int id; unsigned char kind; char p9[3]; int fC; unsigned short f10; } Arg21D6C0;
extern "C" {
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Evt21D6C0* e, void* type);
#endif /* merge_units */
int cMessage_ctor_cMessageNameR(void* msg, void* name); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int_int(Evt21D6C0* e, void* obj, int a, int b);
#if 0 /* merge_units */
extern void cMessage_dtor(Evt21D6C0* e, int f);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node21D6C0** out, void* map, int* key);
typedef struct { void* p; } It21D6C0;
extern It21D6C0 std_map_int_netSystemField_end(void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node21D6C0** out, const It21D6C0& in);
extern char D_004A4A70[];
extern char D_004DB660[];
extern char D_004DB640[];
extern char D_004DB620[];
extern char D_004DB600[];
extern unsigned char D_005721D0;
}
static inline int Eq21D6C0(Node21D6C0* a, Node21D6C0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
#pragma opt_lifetimes off
extern "C" int cGeneratorMessageBase_GeneratorMessageBaseCallback(int a0, int a1, int a2, Arg21D6C0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        int k[1];
        Node21D6C0* end[1];
        Node21D6C0* it[1];
        Evt21D6C0* p;
        Arg21D6C0* a = arg;
        Node21D6C0* n;

        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        cAssocArray_int_netSystemField_Iterator_ctor(end, std_map_int_netSystemField_end(D_0055C7A0));
        if (Eq21D6C0(n, end[0]) ^ 1) {
            switch (a->kind) {
            case 0: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            case 1: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                e.vt = D_004DB640;
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            case 2: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                e.vt = D_004DB620;
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            case 3: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                e.vt = D_004DB600;
                e.f28 = a->f10;
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            }
        }
    }
    return 0x14;
}
#pragma pop
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0021D6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D6C0 */

/* merge_units: begin func_0021D990 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(cDespawnedNPCMsg_dtor, D_004DB620, D_004DB660, cMessage_dtor)
static inline void merge_flush_func_0021D990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D990 */

/* merge_units: begin func_0021DA00 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(cSpawnedNPCMsg_dtor, D_004DB640, D_004DB660, cMessage_dtor)
static inline void merge_flush_func_0021DA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021DA00 */

/* merge_units: begin func_0021DA70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cGenerator_SendCreated: send a newly joined peer the generator's state - enable flag, active flag and
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
int NetGetMyClientIndex(int* slot, int v);
int cNetObj_GetOwner(int id);
int cMessage_ctor_cMessageNameR(void* msg, void* name);
#if 0 /* merge_units */
int cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((a0), (short)(a1))) /* merge_units */

unsigned char cNetObj_SendMessage_int_int_ucharP_int_etc(int a, int b, void* c, int target, int type);
int cNetObj_SendMessage_int_cMessageR_int_int(int id, void* msg, int flags, int peer);
void cEulerAngle_T_1_2_ctor_cMatrixR(GvV4* out, GvMtx* m);
#if 0 /* merge_units */
GvNodeL* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
#endif /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_tail(char* self); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) ((GvNodeL *)std_list_deleter_cSafePtr_cGOBJ_tail((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
GvIt* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(GvIt* it, GvNodeL* n);
#endif /* merge_units */
int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(int* self, int value); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((GvIt *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((int *)(a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
GvIt* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(GvIt* it, GvNodeL* n);
#endif /* merge_units */
int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(int* self, int value); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(a0, a1) ((GvIt *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP((int *)(a0), (int)(a1))) /* merge_units */

int cGenerator_SendCreated(GvGen* self, int peer);
int cEnableMsg_Pack(GvEnMsg* m, int id, int* len, int a, int b, int max, char* buf);
int cNetGeneratorCreateMsg_Pack(GvSpMsg* m, int id, int* len, int a, int b, int max, char* buf);
}
static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void QZ(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; __asm__ volatile("lq %0, 0x0(%1)" : "+r"(q) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(d) : "memory"); }
static inline void MsgInit(GvSpMsg* m, int id, int x10, int x68) { cMessage_ctor_cMessageNameR(m, D_0051F058); m->vt = D_004DE240; m->id = id; m->x54 = x10; m->x58 = x68; }
static inline int* IdPtr(GvObj* o) { int* p = &o->id; return p; }
static inline int NetSlot(int a) { int r = 0; if (g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a); return D_00494178; } return r; }
static inline bool Not(unsigned char x) { return !x; }
static inline bool ReadyG(GvGen* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline bool ReadyO(GvObj* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline bool IdEq(GvObj* p, GvHnd* h) { return p->id == h->id; }
static inline GvObj* HGet(GvHnd* h) {
    bool ok = (h->p != 0) ^ 1 || IdEq(h->p, h);
    unsigned char k = ok;
    return k ? h->p : 0;
}
static inline GvIt Begin(void* l) { GvIt t; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(&t, std_list_deleter_cSafePtr_cGOBJ_tail(l)->next); return t; }
static inline GvIt End(void* l) { GvIt t; std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&t, std_list_deleter_cSafePtr_cGOBJ_tail(l)); return t; }

int cGenerator_SendCreated(GvGen* self, int peer)
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
    if (NetSlot(D_005721A8) == cNetObj_GetOwner(id)) {
        if (ReadyG(self)) {
            GvEnMsg* pe;
            int slot = NetSlot(D_005721A8);
            pe = &em;
            int r;
            cMessage_ctor_cMessageNameR(pe, g_cEnableMsgClass);
            pe->vt = D_004E0880;
            pe->player = slot;
            pe->flags = 0x40;
            em.kind = 4;
            r = cEnableMsg_Pack(&em, self->id, &len, 0, 0, 0x400, buf);
            if (r > -1)
                cNetObj_SendMessage_int_int_ucharP_int_etc(D_0055D4C0, r, buf, peer, 0);
            em.vt = D_004E0880;
            cMessage_dtor(&em, 0);
        }
        {
            unsigned char on = self->active;
            GvSetMsg* p = &m2;
            cMessage_ctor_cMessageNameR(p, D_004A4A78);
            p->vt = D_004DB5E0;
            p->arg = on;
            p->what = 0;
            m2.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(self->id, p, 0, peer);
            m2.vt = D_004DB5E0;
            cMessage_dtor(p, 0);
        }
        {
            float rate = self->rate;
            GvSetMsg* p = &m3;
            cMessage_ctor_cMessageNameR(p, D_004A4A78);
            p->vt = D_004DB5E0;
            p->arg = (int)rate;
            p->what = 1;
            m3.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(self->id, p, 0, peer);
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
                    cEulerAngle_T_1_2_ctor_cMatrixR(&e, &mc);
                    QZ(&m->rot, &e);
                    m->pos = mc.t;
                    m->rnd = rnd;
                    m->route = route;
                    m->x1C = 0x40;
                    msg.x20 = 4;
                    r = cNetGeneratorCreateMsg_Pack(&msg, self->id, &len, 0, 0, 0x400, buf);
                    if (r > -1)
                        cNetObj_SendMessage_int_int_ucharP_int_etc(D_0051F060, r, buf, peer, 0);
                    msg.vt = D_004DE240;
                    cMessage_dtor(&msg, 0);
                }
            }
        }
    }
    return 1;
}
#undef cMessage_dtor /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP /* merge_units */
static inline void merge_flush_func_0021DA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021DA70 */

/* merge_units: begin func_0021DF80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetGeneratorCreateMsg_dtor, D_004DE240, cMessage_dtor)
static inline void merge_flush_func_0021DF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021DF80 */

/* merge_units: begin func_0021DFE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(int* self, int value) {
    *self = value;
    return self;
}

int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(int* self, int value) {
    *self = value;
    return self;
}

void* std_list_deleter_cSafePtr_cGOBJ_tail(char* self) {
    return self + 4;
}
static inline void merge_flush_func_0021DFE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021DFE0 */

/* merge_units: begin func_0021E010 */
#pragma push /* merge_units */
int cNetObj_AddSystem(int, int, void*);
#if 0 /* merge_units */
int NetGetMyClientIndex(int*, int);
#endif /* merge_units */
#define NetGetMyClientIndex(a0, a1) (NetGetMyClientIndex((a0), (a1))) /* merge_units */

extern unsigned char D_005721C0;
typedef struct { char pad[0xC]; int idC; int id10; } Gen_E010;
void cGenerator_InitNetwork(Gen_E010* self)
{
    int ok;
    self->id10 = self->idC;
    ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        int t = self->id10;
        int id;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
        cNetObj_AddSystem(t, id, self);
    }
}
#undef NetGetMyClientIndex /* merge_units */
static inline void merge_flush_func_0021E010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021E010 */
