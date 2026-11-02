/*
 * SFOGame/Source/Generator: 5 files, 0021E620-0021EDE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021E620 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "vslot_pad.h"

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
#if 0 /* merge_units */
LNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(LNode* n);
#endif /* merge_units */
void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(void* self); /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(a0) ((LNode *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
LNode* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
#endif /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_tail(void*); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) ((LNode *)std_list_deleter_cSafePtr_cGOBJ_tail((a0))) /* merge_units */

#if 0 /* merge_units */
LNode** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(LNode** it, LNode* n);
#endif /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(void*, void*); /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((LNode * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((void *)(a0), (void *)(a1))) /* merge_units */

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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021EAA0(void) {}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4 /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef NetGetMyClientIndex /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021EAA0 */

/* merge_units: begin func_0021EDE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(void* self) {
    return self;
}
static inline void merge_flush_func_0021EDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021EDE0 */

/* merge_units: begin func_0021EDF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define V25(a) V5(a##a) V5(a##b) V5(a##c) V5(a##d) V5(a##e)
struct Tgt_0021EDF0 {
    V25(x) V25(y) V5(za) V5(zb) virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual unsigned char State();
    int pad4[2]; int id;
};
struct Hnd_0021EDF0 { Tgt_0021EDF0* p; int id; };
struct LNode_0021EDF0 { LNode_0021EDF0* prev; LNode_0021EDF0* next; Hnd_0021EDF0 h; };
struct Gen_0021EDF0;
extern "C" {
#if 0 /* merge_units */
LNode_0021EDF0* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(LNode_0021EDF0* n);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(a0) ((LNode_0021EDF0 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4((void *)(a0))) /* merge_units */



#if 0 /* merge_units */
LNode_0021EDF0* std_list_deleter_cSafePtr_cGOBJ_tail(void* l);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) ((LNode_0021EDF0 *)std_list_deleter_cSafePtr_cGOBJ_tail((a0))) /* merge_units */

#if 0 /* merge_units */
LNode_0021EDF0** std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(LNode_0021EDF0** it, LNode_0021EDF0* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((LNode_0021EDF0 * *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((void *)(a0), (void *)(a1))) /* merge_units */

int cGenInfoObject_IsOwner(void* ctx, void* key);
int cDME_GetTime(int);
int cNPC_GetActiveNpcCount(void);
unsigned char cGenerator_CheckSpawnNode(Gen_0021EDF0* g, Gen_0021EDF0* s);
#if 0 /* merge_units */
void cGenerator_Spawn(Gen_0021EDF0* g, Gen_0021EDF0* s, int i);
#endif /* merge_units */
#define cGenerator_Spawn(a0, a1, a2) (cGenerator_Spawn((GsGen *)(a0), (GsActor *)(a1), (a2))) /* merge_units */

extern int g_MaxActiveNpcCount;
extern int D_004F56B8;
void cGenerator_NextFrame(Gen_0021EDF0* self, float dt);
}
struct Gen_0021EDF0 {
    V5(a) V5(b) V5(c) V5(d) V5(e)
    virtual int CanSpawn();
    char pad4[8]; char key[0x78 - 0xC]; int n78; Gen_0021EDF0** arr; int pad80; float f84; int n88; int n8C;
    int list90; LNode_0021EDF0 head; char padA4[0x18]; float fBC; int nC0; int nC4; int nC8; char padCC[4]; unsigned char bD0; unsigned char bD1;
};
static inline bool Valid(Hnd_0021EDF0* h) {
    return !h->p || h->p->id == h->id;
}
static inline Tgt_0021EDF0* HGet_0021EDF0(Hnd_0021EDF0* h) {
    return Valid(h) ? h->p : 0;
}
void cGenerator_NextFrame(Gen_0021EDF0* self, float dt)
{
    char ctx[4];
    LNode_0021EDF0* end;
    int cnt = 0;
    LNode_0021EDF0* n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->head)->next;
    self->fBC += dt;
    std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
    while (n != end) {
        Hnd_0021EDF0* h = &n->h;
        Tgt_0021EDF0* t = HGet_0021EDF0(h);
        if (t && t->State() != 3) cnt++;
        n = n->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
    }
    cGenInfoObject_ctor(ctx);
    if (self->bD1) return;
    if (g_IsMultiplayer) {
        if (!cGenInfoObject_IsOwner(ctx, self->key)) return;
        if (!(D_004F56B8 < cDME_GetTime(1))) return;
    }
    if (!(g_MaxActiveNpcCount > cNPC_GetActiveNpcCount())) return;
    if (!self->CanSpawn()) return;
    if (!(self->nC0 < self->n8C)) return;
    if (self->fBC <= self->f84) return;
    if (!(cnt < self->n88)) return;
    Gen_0021EDF0* s;
    int nn = self->n78;
    if (nn == 0) {
        s = self;
    } else {
        if (!self->bD0) {
            int c = self->nC4 + 1;
            self->nC4 = c;
            self->nC4 = c % nn;
        }
        s = self->arr[self->nC4];
    }
    unsigned char r = cGenerator_CheckSpawnNode(self, s);
    if (r == 1) {
        cGenerator_Spawn(self, s, self->n78 ? self->nC4 : -1);
        D_004F56B8 = cDME_GetTime(1) + 250;
    } else if (r == 0) {
        if (self->nC8 == self->nC4) self->fBC = self->f84 - 1.0f;
    }
}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4 /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef cGenerator_Spawn /* merge_units */
static inline void merge_flush_func_0021EDF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021EDF0 */

/* merge_units: begin func_0021F0A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_0021F0A0 {
    V5(a) V5(b) V5(c)
    virtual int IsA();      /* +0x44 */
    virtual void d3(); virtual void d4(); virtual void e0(); virtual void e1();
    virtual int IsPlayer(); /* +0x58 */
};
struct Tgt_0021F0A0 {
    V5(a) virtual void b0();
    virtual void Activate();   /* +0x20 */
    virtual void Deactivate(); /* +0x24 */
    V5(c) V5(d) virtual void e0(); virtual void e1(); virtual void e2();
    virtual void ActivateNet(int f); /* +0x5C */
    virtual void Kill(int f);        /* +0x60 */
    V5(f) V5(g) V5(h) V5(i) V5(j) V5(k) V5(l) V5(m) virtual void n0();
    virtual unsigned char State(); /* +0x108 */
    int magic;
    int pad8;
    int id;
    int x10;
    char pad14[0x18];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
    char pad2F[0x29];
    Ctl_0021F0A0* ctl;
    char pad5C[0x3584 - 0x5C];
    int x3584;
};
struct Hnd_0021F0A0 { Tgt_0021F0A0* p; int id; };
struct LNode_0021F0A0 { LNode_0021F0A0* prev; LNode_0021F0A0* next; Hnd_0021F0A0 h; };
struct It { void* n; };
struct LHead { LNode_0021F0A0* prev; LNode_0021F0A0* next; };
struct NIt { LNode_0021F0A0* p; };
struct FIt { void* p; };
struct GList { int size; LHead head; };
struct Gen_0021F0A0 {
    void* vt;
    char pad4[8];
    int key;
    char pad10[0x1C];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
    char pad2F[0x61];
    GList list90;
    GList list9C;
    char padA8[0x18];
    int nC0;
    char padC4[8];
    int maskCC;
    char padD0[2];
    unsigned char bD2;
    unsigned char bD3;
};
struct EvA { void* vt; char pad4[0x1C]; unsigned char kind; char p21[3]; Tgt_0021F0A0* obj; };
struct EvB { void* vt; char pad4[0x18]; int x1C; unsigned char kind; char p21[0xB]; int id; int x10; };
extern "C" {
extern char D_004A4A80[];
extern char D_004DB640[];
extern char D_004DB660[];
extern char D_004DE260[];
extern char D_0051F068[];
extern char D_00555070[];
#if 0 /* merge_units */
extern int g_ActorList;
#endif /* merge_units */
#define g_ActorList (*(int*)&g_ActorList) /* merge_units */

extern unsigned char D_005721C0;
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

int cNetObj_GetNetSystem(int);
int cNetObj_GetPlayer(int);
void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(It* ret, GList* l, It* a, It* b);
int cNetObj_GetOwner(int);
void cHuman_SetupNetworkFields(Tgt_0021F0A0*, int);
#if 0 /* merge_units */
LNode_0021F0A0* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(LHead* n);
#endif /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(a0) ((LNode_0021F0A0 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
void* std_list_deleter_cSafePtr_cGOBJ_tail(GList* l);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_tail(a0) (std_list_deleter_cSafePtr_cGOBJ_tail((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
It* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(It* it, void* n);
#endif /* merge_units */
#define std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(a0, a1) ((It *)std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void cGenerator_CheckForOwnershipChange(Gen_0021F0A0* g);
#endif /* merge_units */
#define cGenerator_CheckForOwnershipChange(a0) (cGenerator_CheckForOwnershipChange((Gen *)(a0))) /* merge_units */

void* cLListIterator_cSafePtr_cGOBJ_ctor_void(It* it);
void cLList_cSafePtr_cGOBJ_Begin(It* out, GList* l);
It* cLListIterator_cSafePtr_cGOBJ_opAssign(It* dst, It* src);
void cLList_cSafePtr_cGOBJ_End(It* out, GList* l);
int opNe_cLListIteratorR_cLListIteratorR_3(It* a, It* b);
Hnd_0021F0A0* cLListIterator_cSafePtr_cGOBJ_opMul(It* it);
int cSafePtr_cGOBJ_opEq(Hnd_0021F0A0* a, Hnd_0021F0A0* b);
It* cLListIterator_cSafePtr_cGOBJ_opInc(It* it);
It* cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(It* dst, It* src);
void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(It* ret, GList* l, It* pos);
#if 0 /* merge_units */
int NetGetMyClientIndex(int*, int);
#endif /* merge_units */
#define NetGetMyClientIndex(a0, a1) (NetGetMyClientIndex((a0), (a1))) /* merge_units */

void cSystem_ActualScheduleDelete(Tgt_0021F0A0*, float);
void cScriptInterpreter_RemoveFromAllGroups(void*, Tgt_0021F0A0*);
#if 0 /* merge_units */
void cNetObj_SetOwner(int, int);
#endif /* merge_units */
#define cNetObj_SetOwner(a0, a1) (cNetObj_SetOwner((a0), (a1))) /* merge_units */

void cBaseObjList_Remove(int, Tgt_0021F0A0*);
int cNPCInfoObject_IsActiveOnRemote(void*, int*);
void cNPCInfoObject_SetActive(void*, int*);
int cNPCInfoObject_GetOwner_cObjectIdR(void*, int*);
#if 0 /* merge_units */
void cNPCInfoObject_dtor(void*, int);
#endif /* merge_units */
#define cNPCInfoObject_dtor(a0, a1) (cNPCInfoObject_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cNPCInfoObject_ctor(void*);
#endif /* merge_units */
#define cNPCInfoObject_ctor(a0) (cNPCInfoObject_ctor((a0))) /* merge_units */

#if 0 /* merge_units */
int cGenInfoObject_GetOwner(void*, int*);
#endif /* merge_units */
#define cGenInfoObject_GetOwner(a0, a1) (cGenInfoObject_GetOwner((a0), (void *)(a1))) /* merge_units */

void cGenInfoObject_SetOwner(void*, int*, int);
#if 0 /* merge_units */
int cGenInfoObject_HasOwner(void*, int*);
#endif /* merge_units */
#define cGenInfoObject_HasOwner(a0, a1) (cGenInfoObject_HasOwner((a0), (void *)(a1))) /* merge_units */

int cGenInfoObject_IsActive(void*, int*, int);
#if 0 /* merge_units */
void cGenInfoObject_ctor(void*);
#endif /* merge_units */
#define cGenInfoObject_ctor(a0) (cGenInfoObject_ctor((a0))) /* merge_units */


void cGenerator_v11(Gen_0021F0A0* self);
}
static inline Tgt_0021F0A0* HGet_0021F0A0(Hnd_0021F0A0* h) {
    unsigned char valid = 1;
    Tgt_0021F0A0* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
static inline Tgt_0021F0A0* HGetN(LNode_0021F0A0* n) { Hnd_0021F0A0* h = &n->h; return HGet_0021F0A0(h); }
static inline void MkEv(EvB* e, int x10, int id) { cMessage_ctor_cMessageNameR(e, D_0051F068); e->vt = D_004DE260; e->id = id; e->x10 = x10; e->x1C = 0x40; e->kind = 4; }
static inline bool GActive(Gen_0021F0A0* g) { return g->b2D && g->b2C && !g->b2E; }
static inline bool TActive(Tgt_0021F0A0* t) { return t->b2D && t->b2C && !t->b2E; }
static inline bool IsPl(Tgt_0021F0A0* t) { bool r = 0; if (t->ctl && t->ctl->IsPlayer()) r = 1; return r; }
static inline bool IsDying(Tgt_0021F0A0* o) { unsigned char s = o->State(); return s == 2 || s == 3; }
static inline int IsAuth(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline int LocalId(void) {
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}

void cGenerator_v11(Gen_0021F0A0* self)
{
    char ctx[4];
    char ctx2[4];
    It found1;
    It found2;
    It found3;
    It ret1;
    It arg1;
    It ret2;
    It arg2;
    It ret3;
    It arg3;
    It ret4;
    It arg4;
    It ret5;
    It arg5;
    It ret6;
    It arg6;
    It ret7;
    It arg7;
    It ret8;
    It arg8;
    It end1;
    It endc2;
    It end2;
    It end3;
    It endc4;
    It end4;
    It ret9;
    It arg9a;
    It arg9b;
    int none1;
    int none2;
    int none3;
    It it1;
    It beg1;
    It ie1;
    It it2;
    It beg2;
    It ie2;
    It it3;
    It beg3;
    It ie3;
    Hnd_0021F0A0 h1;
    Hnd_0021F0A0 h2;
    Hnd_0021F0A0 h3;
    EvA ev1;
    EvB ev2;
    EvB ev3;
    EvA ev4;

    if (g_IsMultiplayer) {
        int me;
        NIt n;
        cGenInfoObject_ctor(ctx);
        cNPCInfoObject_ctor(ctx2);
        me = cGenInfoObject_GetOwner(ctx, &self->key);
        n.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end1, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        while (n.p != end1.n) {
            Hnd_0021F0A0* h = &n.p->h;
            Tgt_0021F0A0* t = (Tgt_0021F0A0*)HGet_0021F0A0(h);
            LNode_0021F0A0* cur = n.p;
            n.p = n.p->next;
            if (t) {
                bool atEnd;
                bool kill;
                FIt f;
                f.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list9C.head);
                if (self->list9C.size > 0) {
                    int* pid = &h1.id;
                    *pid = -1;
                    h1.p = t;
                    *pid = *(t ? &t->id : (none1 = -1, &none1));
                    cLListIterator_cSafePtr_cGOBJ_ctor_void(&it1);
                    cLList_cSafePtr_cGOBJ_Begin(&beg1, &self->list9C);
                    cLListIterator_cSafePtr_cGOBJ_opAssign(&it1, &beg1);
                    for (; cLList_cSafePtr_cGOBJ_End(&ie1, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it1, &ie1); cLListIterator_cSafePtr_cGOBJ_opInc(&it1)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it1), &h1)) break; //
                    cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found1, &it1);
                    f.p = found1.n;
                }
                atEnd = f.p == (void*)((char*)self + 0xA0);
                kill = 0;
                if (me >= 0 && !atEnd) {
                    if (me == cNPCInfoObject_GetOwner_cObjectIdR(ctx2, &t->id)) {
                        cMessage_ctor_cMessageNameR(&ev1, D_004A4A80);
                        ev1.obj = t;
                        ev1.vt = D_004DB640;
                        ev1.kind = 1;
                        QueueMessage_cMessageR_cSystemP_int(&ev1, self, 0);
                        arg1.n = f.p;
                        std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret1, &self->list9C, &arg1);
                        if (TActive(t))
                            cNPCInfoObject_SetActive(ctx2, &t->id);
                        ev1.vt = D_004DB660;
                        cMessage_dtor(&ev1, 0);
                    } else if (t->ctl && !t->ctl->IsA()) {
                        arg2.n = f.p;
                        std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret2, &self->list9C, &arg2);
                    }
                }
                if (me < 0) {
                    if (atEnd) {
                        if (TActive(t)) {
                            if (IsPl(t))
                                t->Kill(0);
                            else
                                t->Deactivate();
                        }
                        if (IsPl(t) && !cNPCInfoObject_IsActiveOnRemote(ctx2, &t->id))
                            kill = 1;
                    }
                } else if (!GActive(self)) {
                    if (TActive(t)) {
                        if (IsPl(t))
                            t->Kill(0);
                        else
                            t->Deactivate();
                    } else if (atEnd) {
                        if (t->ctl && !t->ctl->IsA())
                            kill = 1;
                    }
                } else if (!TActive(t)) {
                    if (t->ctl && t->ctl->IsA()) {
                        if (IsPl(t)) {
                            t->ActivateNet(0);
                        } else {
                            t->Activate();
                            if (t->x3584 == 0) {
                                int m = cNetObj_GetNetSystem(t->x10);
                                if (m)
                                    cHuman_SetupNetworkFields(t, m);
                            }
                        }
                    } else if (atEnd) {
                        kill = 1;
                    }
                }
                if (kill && me == LocalId()) {
                    int x10 = t->x10;
                    int id = t->id;
                    cMessage_ctor_cMessageNameR(&ev2, D_0051F068);
                    ev2.vt = D_004DE260;
                    ev2.id = id;
                    ev2.x10 = x10;
                    ev2.x1C = 0x40;
                    ev2.kind = 4;
                    QueueMessage_cMessageR_cSystemP_int(&ev2, self, 0);
                    if (!IsDying(t) && !self->bD2)
                        self->nC0--;
                    arg3.n = cur;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret3, &self->list90, &arg3);
                    cBaseObjList_Remove(g_ActorList, t);
                    cScriptInterpreter_RemoveFromAllGroups(D_00555070, t);
                    if (t->magic == (int)0xBEBAAFDE)
                        cSystem_ActualScheduleDelete(t, 1.0f);
                    ev2.vt = D_004DE260;
                    cMessage_dtor(&ev2, 0);
                }
            } else {
                arg4.n = cur;
                std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret4, &self->list90, &arg4);
            }
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end1, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        }
        cGenerator_CheckForOwnershipChange(self);
        if (me == LocalId()) {
            bool purge = 0;
            if (GActive(self)) {
                self->bD3 = 1;
            } else if (self->bD3) {
                int sel = -1;
                int i;
                for (i = 0; i < 4; i++) {
                    if ((self->maskCC & (1 << i)) && cGenInfoObject_IsActive(ctx, &self->key, i) && cNetObj_GetPlayer(i)) {
                        sel = i;
                        break;
                    }
                }
                if (sel >= 0) {
                    cGenInfoObject_SetOwner(ctx, &self->key, sel);
                } else {
                    cGenInfoObject_SetOwner(ctx, &self->key, -1);
                    purge = 1;
                }
            } else if (IsAuth() && (!cGenInfoObject_IsActive(ctx, &self->key, -1) || !(self->maskCC & 1))) {
                int sel = -1;
                int i;
                for (i = 1; i < 4; i++) {
                    if ((self->maskCC & (1 << i)) && cGenInfoObject_IsActive(ctx, &self->key, i) && cNetObj_GetPlayer(i)) {
                        sel = i;
                        break;
                    }
                }
                if (sel >= 0) {
                    cGenInfoObject_SetOwner(ctx, &self->key, sel);
                } else {
                    cGenInfoObject_SetOwner(ctx, &self->key, -1);
                    purge = 1;
                }
            }
            if (purge) {
                NIt n2;
                n2.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
                while (n2.p != end2.n) {
                    Hnd_0021F0A0* h = &n2.p->h;
                    Tgt_0021F0A0* t = HGet_0021F0A0(h);
                    NIt cur; cur.p = n2.p;
                    n2.p = n2.p->next;
                    if (t) {
                        if (self->list9C.size > 0) {
                            FIt f2;
                            int* pid = &h2.id;
                            *pid = -1;
                            h2.p = t;
                            *pid = *(t ? &t->id : (none2 = -1, &none2));
                            cLListIterator_cSafePtr_cGOBJ_ctor_void(&it2);
                            cLList_cSafePtr_cGOBJ_Begin(&beg2, &self->list9C);
                            cLListIterator_cSafePtr_cGOBJ_opAssign(&it2, &beg2);
                            for (; cLList_cSafePtr_cGOBJ_End(&ie2, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it2, &ie2); cLListIterator_cSafePtr_cGOBJ_opInc(&it2)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it2), &h2)) break; //
                            cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found2, &it2);
                            f2.p = found2.n;
                            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list9C));
                            if (f2.p != endc2.n) {
                                arg5.n = f2.p;
                                std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret5, &self->list9C, &arg5);
                            }
                        }
                        {
                            int x10 = t->x10;
                            MkEv(&ev3, x10, t->id);
                            QueueMessage_cMessageR_cSystemP_int(&ev3, self, 0);
                            if (!IsDying(t) && !self->bD2)
                                self->nC0--;
                            arg6.n = cur.p;
                            std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret6, &self->list90, &arg6);
                            cBaseObjList_Remove(g_ActorList, t);
                            cScriptInterpreter_RemoveFromAllGroups(D_00555070, t);
                            if (t->magic == (int)0xBEBAAFDE)
                                cSystem_ActualScheduleDelete(t, 1.0f);
                            ev3.vt = D_004DE260;
                            cMessage_dtor(&ev3, 0);
                        }
                    }
                    std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end2, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
                }
            }
        } else {
            self->bD3 = 0;
        }
        if (IsAuth() && cGenInfoObject_HasOwner(ctx, &self->key)) {
            NIt n3;
            n3.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end3, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
            int* k; int tid;
            while (n3.p != end3.n) {
                k = &self->key;
                if (cNetObj_GetOwner(HGetN(n3.p)->id) != cGenInfoObject_GetOwner(ctx, k)) {
                    k = &self->key;
                    tid = HGetN(n3.p)->id;
                    cNetObj_SetOwner(tid, cGenInfoObject_GetOwner(ctx, k));
                }
                n3.p = n3.p->next;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end3, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
            }
        }
        if (self->bD2 && !cGenInfoObject_HasOwner(ctx, &self->key) && self->list90.size == 0)
            self->nC0 = 0;
        {
            int i;
            for (i = 0; i < 4; i++) {
                if (!cNetObj_GetPlayer(i)) {
                    if (self->maskCC & (1 << i))
                        self->maskCC ^= (1 << i);
                }
            }
        }
        cNPCInfoObject_dtor(ctx2, -1);
    } else {
        NIt n4;
        n4.p = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4(&self->list90.head)->next;
        std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end4, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        while (n4.p != end4.n) {
            Hnd_0021F0A0* h = &n4.p->h;
            Tgt_0021F0A0* t = HGet_0021F0A0(h);
            NIt cur; cur.p = n4.p;
            n4.p = n4.p->next;
            if (t) {
                FIt f3;
                {
                    int* pid = &h3.id;
                    *pid = -1;
                    h3.p = t;
                    *pid = *(t ? &t->id : (none3 = -1, &none3));
                }
                cLListIterator_cSafePtr_cGOBJ_ctor_void(&it3);
                cLList_cSafePtr_cGOBJ_Begin(&beg3, &self->list9C);
                cLListIterator_cSafePtr_cGOBJ_opAssign(&it3, &beg3);
                for (; cLList_cSafePtr_cGOBJ_End(&ie3, &self->list9C), opNe_cLListIteratorR_cLListIteratorR_3(&it3, &ie3); cLListIterator_cSafePtr_cGOBJ_opInc(&it3)) if (cSafePtr_cGOBJ_opEq(cLListIterator_cSafePtr_cGOBJ_opMul(&it3), &h3)) break; //
                cLListIterator_cSafePtr_cGOBJ_ctor_cLListIteratorR(&found3, &it3);
                f3.p = found3.n;
                std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&endc4, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list9C));
                if (f3.p != endc4.n) {
                    cMessage_ctor_cMessageNameR(&ev4, D_004A4A80);
                    ev4.obj = t;
                    ev4.vt = D_004DB640;
                    ev4.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&ev4, self, 0);
                    arg7.n = f3.p;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret7, &self->list9C, &arg7);
                    ev4.vt = D_004DB660;
                    cMessage_dtor(&ev4, 0);
                }
                if (!GActive(self)) {
                    if (TActive(t))
                        t->Kill(1);
                } else if (!TActive(t)) {
                    if (t->ctl && t->ctl->IsA())
                        t->ActivateNet(1);
                }
                if (!TActive(t)) {
                    if (!IsDying(t) && !self->bD2)
                        self->nC0--;
                    arg8.n = cur.p;
                    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter(&ret8, &self->list90, &arg8);
                    cBaseObjList_Remove(g_ActorList, t);
                    cScriptInterpreter_RemoveFromAllGroups(D_00555070, t);
                    if (t->magic == (int)0xBEBAAFDE)
                        cSystem_ActualScheduleDelete(t, 1.0f);
                }
            }
            std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(&end4, std_list_deleter_cSafePtr_cGOBJ_tail(&self->list90));
        }
        if (self->bD2) {
            if (!GActive(self) && self->list90.size == 0)
                self->nC0 = 0;
        }
    }
    if (self->list90.size == 0 && self->list9C.size > 0) {
        arg9b.n = &self->list9C.head;
        arg9a.n = self->list9C.head.next;
        std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&ret9, &self->list9C, &arg9a, &arg9b);
    }
}
#undef g_ActorList /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_4 /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_tail /* merge_units */
#undef std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP /* merge_units */
#undef cGenerator_CheckForOwnershipChange /* merge_units */
#undef NetGetMyClientIndex /* merge_units */
#undef cNetObj_SetOwner /* merge_units */
#undef cNPCInfoObject_dtor /* merge_units */
#undef cNPCInfoObject_ctor /* merge_units */
#undef cGenInfoObject_GetOwner /* merge_units */
#undef cGenInfoObject_HasOwner /* merge_units */
#undef cGenInfoObject_ctor /* merge_units */
static inline void merge_flush_func_0021F0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021F0A0 */
