/*
 * main/Generator: range (2 files, 0021E620-0021EAA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "vslot_pad.h"

/* merge_units: begin func_0021E620 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
/* cGenerator_Spawn: allocate and construct one spawned NPC, register it with the generator and (online) announce it */
typedef union { __int128 q; struct { float x, y, z, w; } f; } GsV4;
struct GsMtx { GsV4 r[3]; GsV4 t; };
struct GsNode { VPAD16(a) VPAD4(b) virtual void Refresh(); int pad4[3]; GsMtx m; unsigned char dirty; };
struct GsObj {
    VPAD16(a) VPAD4(b) virtual void v58(); virtual void Activate(int on);
    VPAD32(c) VPAD4(d) VPAD2(e) VPAD1(f) virtual void SetNet(int on);
    int pad4[2];
    int id;
    int x10;
    char pad14[0x1C - 0x14];
    void* reg;
    char pad20[0x50 - 0x20];
    GsNode* node;
    char pad54[0x3598 - 0x54];
    unsigned char spawned;
};
struct GsActor { char pad0[0x78]; int route; int Route() const { return route; } };
struct GsKey { int* key; int count; };
struct GsHandle { GsObj* target; int serial; GsHandle(GsObj* o) { int none; int m = -1; serial = m; target = o; serial = *(o ? &o->id : (none = m, &none)); } };
struct GsIt { void* p; };
struct GsList; extern "C" void std_list_deleter_cSafePtr_cGOBJ_insert(GsIt* out, GsList* list, GsIt* pos, const GsHandle* h);
struct GsList { int count; char sent[8]; void push_back(const GsHandle& h) { void* s = sent; GsIt r; GsIt pos; pos.p = s; GsIt* pp = &pos; std_list_deleter_cSafePtr_cGOBJ_insert(&r, this, pp, &h); } };
struct GsGen {
    char pad0[0xC];
    int key;
    char pad10[0x64 - 0x10];
    int x64;
    int x68;
    char x6C[0x90 - 0x6C];
    GsList list90;
    GsList list9C;
    char xA8[0xBC - 0xA8];
    int xBC;
    int count;
    int xC4;
    int xC8;
};
struct GsMsg {
    void* vt;
    char pad4[0x1C - 0x4];
    int x1C;
    unsigned char x20;
    char pad21[0x30 - 0x21];
    GsV4 pos;
    GsV4 rot;
    int id;
    int x54;
    int x58;
    int rnd;
    int route;
};
extern "C" {
extern char D_004A4A90[];
extern char D_0051F058[];
extern char D_004DE240[];
extern void* g_ActorList;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
void* cMemMan_Allocate(int pool, int size, char* file, int line);
int Libc_Rand(void);
void cNode_GetNodeMatrix(GsMtx* out, GsActor* a);
GsObj* cHuman_ctor_cMatrix_int_charP_int_etc(void* p, GsMtx* m, int route, int a, int b, void* c, int d, void* e, GsKey* key, int rnd);
void cNPCInfoObject_ctor(void* ctx);
void cNPCInfoObject_Add(void* ctx, int* id, int slot);
void cNPCInfoObject_dtor(void* ctx, int v);
int NetGetMyClientIndex(int* slot, int v);
void cBaseObjList_Add(void* reg, GsObj* o);
int cMessage_ctor_cMessageNameR(void* msg, void* name);
int QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
int cMessage_dtor(void* msg, int flags);
void cEulerAngle_T_1_2_ctor_cMatrixR(GsV4* out, GsMtx* m);
}

static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void* QAsg0(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; q = *(const __int128*)s; *(__int128*)d = q; return d; }
static inline void MsgInit(GsMsg* m, int id, int x10, int x68) { cMessage_ctor_cMessageNameR(m, D_0051F058); m->vt = D_004DE240; m->id = id; m->x54 = x10; m->x58 = x68; }
static inline void QZ(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; __asm__ volatile("lq %0, 0x0(%1)" : "+r"(q) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(d) : "memory"); }
static inline int* IdPtr(GsObj* o) { int* p = &o->id; return p; }
static inline int NetSlot(int a) { if (g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a); return D_00494178; } return 0; }
static inline int NetSlot5(int a) { int r = 0; if (g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a); return D_00494178; } return r; }
extern "C" void cGenerator_Spawn(GsGen* gen, GsActor* actor, int idx)
{
    char ctx[4];
    GsKey k1;
    GsKey k2;
    GsMsg msg;
    GsMtx m1;
    GsMtx m2;
    GsMtx mc;
    GsV4 e;
    int route;
    if (idx < 0) route = -1; else route = actor->Route();
    int rnd = Libc_Rand();
    GsObj* obj;
    if (g_IsMultiplayer) {
        {
            AllocGuard g;
            obj = (GsObj*)cMemMan_Allocate(0, 0x35A0, D_004A4A90, 0x71A);
        }
        if (obj) {
            int* kp = &gen->key;
            int c = gen->count;
            k1.key = kp;
            k1.count = c;
            cNode_GetNodeMatrix(&m1, actor);
            obj = cHuman_ctor_cMatrix_int_charP_int_etc(obj, &m1, route, gen->x64, gen->x68, gen->x6C, 2, gen->xA8, &k1, rnd);
        }
        obj->SetNet(1);
        cNPCInfoObject_ctor(ctx);
        {
            int* id = &obj->id;
            int a = D_005721A8;
            cNPCInfoObject_Add(ctx, id, NetSlot5(a));
        }
        cNPCInfoObject_dtor(ctx, -1);
    } else {
        {
            AllocGuard g;
            obj = (GsObj*)cMemMan_Allocate(0, 0x35A0, D_004A4A90, 0x73F);
        }
        if (obj) {
            int* kp = &gen->key;
            int c = gen->count;
            k2.key = kp;
            k2.count = c;
            cNode_GetNodeMatrix(&m2, actor);
            obj = cHuman_ctor_cMatrix_int_charP_int_etc(obj, &m2, route, gen->x64, gen->x68, gen->x6C, 2, gen->xA8, &k2, rnd);
        }
    }
    obj->spawned = 1;
    void* reg = g_ActorList;
    obj->reg = reg;
    cBaseObjList_Add(reg, obj);
    obj->Activate(1);
    gen->list90.push_back(GsHandle(obj));
    gen->list9C.push_back(GsHandle(obj));
    gen->count++;
    gen->xBC = 0;
    gen->xC8 = gen->xC4;
    if (g_IsMultiplayer) {
        GsNode* n = obj->node;
        if (n->dirty) n->Refresh();
        { GsMtx* src = &n->m; GsMtx* dst = &mc; Q4(dst, src); }
        GsMsg* m = &msg;
        MsgInit(m, *IdPtr(obj), obj->x10, gen->x68);
        cEulerAngle_T_1_2_ctor_cMatrixR(&e, &mc);

        QZ(&m->rot, &e);
        m->pos = mc.t;
        m->rnd = rnd;
        m->route = route;
        m->x1C = 0x40;
        msg.x20 = 4;
        QueueMessage_cMessageR_cSystemP_int(&msg, gen, 0);
        msg.vt = D_004DE240;
        cMessage_dtor(m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021E620(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021E620 */

/* merge_units: begin func_0021EAA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Ctl {
    V5(a) V5(b) V5(c) V5(d)
    virtual int IsA();
    virtual int IsB();
};
struct Tgt {
    int pad0[3]; int id; int x10; unsigned char x14; char p15[0x43]; Ctl* ctl;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct Ev {
    char* vt; char p4[0x20]; signed char f24; char p25[0xB];
};
struct Gen {
    char pad[0xC]; int key; char p10[0x80]; int list90; LNode head;
};
extern "C" {
LNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(LNode* n);
LNode* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
LNode** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(LNode** it, LNode* n);
void cGenInfoObject_ctor(void* ctx);
int cGenInfoObject_HasOwner(void* ctx, void* key);
int cGenInfoObject_GetOwner(void* ctx, void* key);
void cNetObj_SetOwner(int id, int v);
#if 0 /* merge_units */
int NetGetMyClientIndex(int*, int);
#endif /* merge_units */
#define NetGetMyClientIndex(a0, a1) (NetGetMyClientIndex((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(void*, char*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
int QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

extern char D_00582730[];
extern char D_004D9300[];
}
static inline Tgt* HGet(Hnd* h) {
    unsigned char valid = 1;
    Tgt* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
extern "C" void cGenerator_CheckForOwnershipChange(Gen* self)
{
    char ctx[4];
    int* key;
    int id;
    cGenInfoObject_ctor(ctx);
    if (!cGenInfoObject_HasOwner(ctx, &self->key))
        return;
    {
        key = &self->key;
        int a = D_005721A8;
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
    }
    int cur = cGenInfoObject_GetOwner(ctx, key);
    if (cur == id) {
        Tgt* t;
        LNode* end;
        LNode* n;
        n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->head)->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        while (n != end) {
            Hnd* h = &n->h;
            t = HGet(h);
            if (t) {
                bool ok = 0;
                if (t->ctl && t->ctl->IsB())
                    ok = 1;
                if (ok) {
                    Ev ev;
                    cMessage_ctor_cMessageNameR(&ev, D_00582730);
                    ev.vt = D_004D9300;
                    ev.f24 = 1;
                    QueueMessage_cMessageR_cSystemP_int(&ev, t, 1);
                    ev.vt = D_004D9300;
                    cMessage_dtor(&ev, 0);
                    t->x14 = 1;
                    {
                        int tid = t->id;
                        cNetObj_SetOwner(tid, cGenInfoObject_GetOwner(ctx, &self->key));
                    }
                }
            }
            n = n->next;
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        }
    } else {
        Tgt* t;
        LNode* end;
        LNode* n;
        n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->head)->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        while (n != end) {
            Hnd* h = &n->h;
            t = HGet(h);
            if (t) {
                bool ok = 0;
                if (t->ctl && t->ctl->IsA())
                    ok = 1;
                if (ok) {
                    Ev ev;
                    cMessage_ctor_cMessageNameR(&ev, D_00582730);
                    ev.vt = D_004D9300;
                    ev.f24 = 2;
                    QueueMessage_cMessageR_cSystemP_int(&ev, t, 1);
                    ev.vt = D_004D9300;
                    cMessage_dtor(&ev, 0);
                    t->x14 = 0;
                    {
                        int tid = t->id;
                        cNetObj_SetOwner(tid, cGenInfoObject_GetOwner(ctx, &self->key));
                    }
                }
            }
            n = n->next;
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        }
    }
}
#undef NetGetMyClientIndex /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021EAA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021EAA0 */
