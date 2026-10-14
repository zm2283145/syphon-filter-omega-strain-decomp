#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#include "types.h"
#include "alloc_guard.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "vslot_pad.h"
/* Generator_Spawn: allocate and construct one spawned NPC, register it with the generator and (online) announce it */
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
struct GsList; extern "C" void WeakHandleList_Append(GsIt* out, GsList* list, GsIt* pos, const GsHandle* h);
struct GsList { int count; char sent[8]; void push_back(const GsHandle& h) { void* s = sent; GsIt r; GsIt pos; pos.p = s; GsIt* pp = &pos; WeakHandleList_Append(&r, this, pp, &h); } };
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
extern void* D_004FFD44;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
void* Mem_Alloc(int pool, int size, char* file, int line);
int Random_Next(void);
void ActorObj_BuildNodeMatrix(GsMtx* out, GsActor* a);
GsObj* func_001B7B00(void* p, GsMtx* m, int route, int a, int b, void* c, int d, void* e, GsKey* key, int rnd);
void func_00436C00(void* ctx);
void func_00435F30(void* ctx, int* id, int slot);
void func_00436BA0(void* ctx, int v);
void NetGame_InitLocalSlot(int* slot, int v);
void ObjRegistry_AppendRecursive(void* reg, GsObj* o);
void Event_Construct(void* msg, void* name);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void Mtx_ToEuler(GsV4* out, GsMtx* m);
}

static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void* QAsg0(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; q = *(const __int128*)s; *(__int128*)d = q; return d; }
static inline void MsgInit(GsMsg* m, int id, int x10, int x68) { Event_Construct(m, D_0051F058); m->vt = D_004DE240; m->id = id; m->x54 = x10; m->x58 = x68; }
static inline void QZ(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; __asm__ volatile("lq %0, 0x0(%1)" : "+r"(q) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(d) : "memory"); }
static inline int* IdPtr(GsObj* o) { int* p = &o->id; return p; }
static inline int NetSlot(int a) { if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a); return D_00494178; } return 0; }
static inline int NetSlot5(int a) { int r = 0; if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a); return D_00494178; } return r; }
extern "C" void Generator_Spawn(GsGen* gen, GsActor* actor, int idx)
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
    int rnd = Random_Next();
    GsObj* obj;
    if (D_005721C8) {
        {
            AllocGuard g;
            obj = (GsObj*)Mem_Alloc(0, 0x35A0, D_004A4A90, 0x71A);
        }
        if (obj) {
            int* kp = &gen->key;
            int c = gen->count;
            k1.key = kp;
            k1.count = c;
            ActorObj_BuildNodeMatrix(&m1, actor);
            obj = func_001B7B00(obj, &m1, route, gen->x64, gen->x68, gen->x6C, 2, gen->xA8, &k1, rnd);
        }
        obj->SetNet(1);
        func_00436C00(ctx);
        {
            int* id = &obj->id;
            int a = D_005721A8;
            func_00435F30(ctx, id, NetSlot5(a));
        }
        func_00436BA0(ctx, -1);
    } else {
        {
            AllocGuard g;
            obj = (GsObj*)Mem_Alloc(0, 0x35A0, D_004A4A90, 0x73F);
        }
        if (obj) {
            int* kp = &gen->key;
            int c = gen->count;
            k2.key = kp;
            k2.count = c;
            ActorObj_BuildNodeMatrix(&m2, actor);
            obj = func_001B7B00(obj, &m2, route, gen->x64, gen->x68, gen->x6C, 2, gen->xA8, &k2, rnd);
        }
    }
    obj->spawned = 1;
    void* reg = D_004FFD44;
    obj->reg = reg;
    ObjRegistry_AppendRecursive(reg, obj);
    obj->Activate(1);
    gen->list90.push_back(GsHandle(obj));
    gen->list9C.push_back(GsHandle(obj));
    gen->count++;
    gen->xBC = 0;
    gen->xC8 = gen->xC4;
    if (D_005721C8) {
        GsNode* n = obj->node;
        if (n->dirty) n->Refresh();
        { GsMtx* src = &n->m; GsMtx* dst = &mc; Q4(dst, src); }
        GsMsg* m = &msg;
        MsgInit(m, *IdPtr(obj), obj->x10, gen->x68);
        Mtx_ToEuler(&e, &mc);

        QZ(&m->rot, &e);
        m->pos = mc.t;
        m->rnd = rnd;
        m->route = route;
        m->x1C = 0x40;
        msg.x20 = 4;
        Event_Send(&msg, gen, 0);
        msg.vt = D_004DE240;
        cMessage_dtor(m, 0);
    }
}
