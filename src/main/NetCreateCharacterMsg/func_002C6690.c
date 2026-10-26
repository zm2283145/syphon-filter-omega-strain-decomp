/* netCreateNPC_HandleNetNPCCreate: network actor-update message handler (NetCreateCharacterMsg.cc): reposition an
 * existing actor, rebuild its components and replay its state events. */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "v4_asm_copy.h"
static inline void StRR(void* d, __int128 t) { asm { .set reorder
 sq t, 0(d) } }
static inline void StR(void* d, __int128 t) { asm { sq t, 0(d) } }
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
struct V4u { __int128 q; };
struct M4u {
    __int128 r0, r1, r2, r3;
    M4u() {}
    M4u(const M4u& s)
    {
        const M4u* ps = &s;
        M4u* pd = this;
        __int128 a, b;
        __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(ps), "r"(pd) : "memory");
    }
};
struct Ang { float x, y, z, w; Ang(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Fv { float x, y, z, w; Fv& Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; return *this; } };
struct NetId { int v; };
struct Msg {
    char pad0[4];
    NetId id;
    float rx, ry, rz;
    float px, py, pz;
    char pad20[0x4C - 0x20];
    unsigned char b4C;
    unsigned char b4D;
    short health;
};
struct Q4 { __int128 q; };
struct Ev30 { char* vt; char pad04[0x20]; int f24; unsigned char f28; char pad29[3]; int f2C; };
struct Ev50 { char* vt; char pad04[0x20]; int f24; unsigned char f28; char pad29[7]; Q4 q30; float f40; float f44; unsigned char f48; char pad49[7]; };
struct Ev70 { char* vt; char pad04[0x20]; unsigned char f24; char pad25[0xB]; M4u m; };
struct Comp;
struct Actor {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void Activate();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual M4u GetXf();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char Kind();
    char pad4[0x10];
    unsigned char b14;
    char pad15[0x3398 - 0x15];
    int health;
};
extern "C" {
extern char D_004AC940[];
extern char g_ActorActionMsgClass[];
extern char g_TeleportMsgClass[];
extern char D_004E0840[];
extern char D_004E01E0[];
extern char D_004E0120[];
extern char D_004D9360[];
float Math_CosThunk(float);
float Math_SinThunk(float);
void* Mtx44_SetRotation(M4u* m, float a, float b, float c, float d, float e, float f,
                        float g, float h, float i);
void* Mem_Alloc(int pool, int size, char* file, int line);
Actor* Object_LookupById(NetId* id);
Comp* cNetNPC_ctor(void* p, int a, Actor* o);
void Actor_InitComponents(Actor* a, int n, int b, Comp* c);
void Actor_SetHealth(Actor* a, int h, int f);
void Event_Construct(void* e, char* t);
void Event_Send(void* e, Actor* a, int f);
void cMessage_dtor(void* e, int f);
int NetMap_BindReceiver(int id, int b, Actor* a);
void cHuman_SetNetworkID(Actor* a, int id);
void cHuman_SetupNetworkFields(Actor* a, int r);
}

static inline void* NewMem(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004AC940, line);
}

static inline void SetRow(__int128* d0, const Fv& v)
{
    __int128 tp;
    __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(tp) : "r"(d0), "r"(&v) : "memory");
}

static inline void SetEulerPos(M4u* m, const Fv& p, const Ang& r)
{
    float y = r.y;
    float x = r.x;
    float z = r.z;
    float cy = Math_CosThunk(y);
    float sy = Math_SinThunk(y);
    float cx = Math_CosThunk(x);
    float sx = Math_SinThunk(x);
    float cz = Math_CosThunk(z);
    float sz = Math_SinThunk(z);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    Mtx44_SetRotation(m,
                      czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                      szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                      -cx * sy, sx, cx * cy);

}

static inline void EvInit(Ev30* e, int id, unsigned char b)
{
    Event_Construct(e, g_ActorActionMsgClass);
    e->vt = D_004E0840;
    e->f24 = id;
    e->f28 = b;
}

static inline void Ev50Init(Ev50* e, const __int128& v, float a, float b, unsigned char k)
{
    Event_Construct(e, g_ActorActionMsgClass);
    e->vt = D_004E0840;
    e->f24 = 0;
    e->f28 = 0xC;
    {
        void* d = &e->q30; __int128 tp; const void* src = &v;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(tp) : "r"(d), "r"(src) : "memory");
    }
    e->f40 = a;
    e->f44 = b;
    e->f48 = k;
    e->vt = D_004E0120;
}

static inline void MCopy(M4u* d0, const M4u* s0)
{
    void* d = d0; __int128 qa; __int128 qb; const void* s = s0;
    __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory");
}

extern "C" void netCreateNPC_HandleNetNPCCreate(Msg* msg, int arg1)
{
    NetId id;
    Ang r(msg->rx, msg->ry, msg->rz);
    Fv pos;
    M4u m;
    Actor* a;
    Comp* c;

    SetEulerPos(&m, pos.Set(msg->px, msg->py, msg->pz, 1.0f), r);
    SetRow(&m.r3, pos);
    id = msg->id;
    a = Object_LookupById(&id);
    if (a) {
        {
            void* p = NewMem(0x220, 0x21B);
            if (p) p = cNetNPC_ctor(p, 0, a);
            c = (Comp*)p;
        }
        Actor_InitComponents(a, 4, 0, c);
        {
            int h = msg->health;
            a->health = h;
            Actor_SetHealth(a, h, 0);
        }
        if (a->Kind() == 3) {
            {
                Ev30 e;
                Ev30* p = &e;
                EvInit(p, 0x3A, 0);
                Event_Send(p, a, 0);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
            {
                Ev30 e;
                Ev30* p = &e;
                EvInit(p, 0x3F, 0);
                Event_Send(p, a, 0);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
            {
                int v = msg->b4D;
                Ev30 e;
                Ev30* p = &e;
                EvInit(p, 0x42, 2);
                p->vt = D_004E01E0;
                p->f2C = v;
                Event_Send(p, a, 0);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
            {
                const M4u& t = a->GetXf();
                Ev50 e;
                Ev50* p = &e;
                const __int128& r = t.r1;
                Ev50Init(p, r, 0.0f, 0.0f, 2);
                Event_Send(&e, a, 1);
                e.vt = D_004E0840;
                cMessage_dtor(p, 0);
            }
        }
        if (msg->b4C) a->Activate();
        {
            Ev70 e;
            Ev70* p = &e;
            Event_Construct(p, g_TeleportMsgClass);
            p->vt = D_004D9360;
            p->f24 = 2;
            MCopy(&p->m, &m);
            Event_Send(&e, a, 1);
            e.vt = D_004D9360;
            cMessage_dtor(p, 0);
        }
        a->b14 = 0;
        cHuman_SetNetworkID(a, msg->id.v);
        cHuman_SetupNetworkFields(a, NetMap_BindReceiver(msg->id.v, arg1, a));
    } else {
        NetMap_BindReceiver(msg->id.v, arg1, a);
    }
}
