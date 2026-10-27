#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

/* cTurret_Fire: start the reload timer, request one shell from the bullet pool (every n-th one a
 * tracer), kick the gun's recoil animation and tell the network peers about the shot. */
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
struct BulletReq;
void cBulletManager_AddBullet(BulletReq* r);
struct Gun;
void cNIEventBase_SetSpeed(float f, Gun* g);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, int target, int immediate);
void cMessage_dtor(void* m, int flags);
struct Turret;
void cTurret_Fire(Turret* t);
}
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct M4 {
    __int128 q[4];
    // 128-bit lq/sq quadword copy idiom, one row at a time
    M4& operator=(const M4& o) {
        const M4* s = &o; M4* d = this; __int128 t, u;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s));
        __asm__ volatile("lq %0, 0x10(%1)" : "=r"(u) : "r"(s));
        d->q[0] = t;
        __asm__ volatile("lq %0, 0x20(%1)" : "=r"(t) : "r"(s));
        d->q[1] = u;
        __asm__ volatile("lq %0, 0x30(%1)" : "=r"(u) : "r"(s));
        d->q[2] = t;
        d->q[3] = u;
        return *this;
    }
};
struct LosHit {
    VP arr[3];
    VP normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    void* x64;
    char pad68[0x8];
    void Init() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct Aux { char p[0x3C]; int f3C; char p40[0xA0 - 0x40]; int burst; float rate; };
struct BulletReq {
    M4 m;
    float speed;
    int owner;
    int f48;
    int f4C;
    LosHit hit;
    char padC0[0xD4 - 0xC0];
    unsigned char bD4;
    unsigned char bD5;
    unsigned char tracer;
    char pD7;
    float fD8;
    Aux* aux;
    int fE0;
    BulletReq() { BulletReq* p = this; p->hit.Init(); p->owner = 0; p->f48 = 0; p->f4C = 0; p->aux = 0; p->fE0 = -1; }
};
struct TNode { VPAD16(a) VPAD4(b) virtual void Update(); char p4[0xC]; M4 mtx; unsigned char dirty; };
struct Model { char p[0x50]; TNode* node; };
struct Gun { VPAD32(a) VPAD32(b) VPAD2(c) VPAD1(d) virtual void Start(); virtual void v68(); virtual void Fire(); };
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
/* message destructors are inlined; the out-of-line weak copies go to .dtors_drop (dropped at link) */
struct MsgB {
    void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3];
    MsgB() { MsgB* m = this; cMessage_ctor_cMessageNameR(m, D_00506260); m->vtable = D_004DCF10; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct Msg : MsgB {
    unsigned char b24; char p25[3]; int f28; float f2C;
    Msg(unsigned char type) { Msg* m = this; m->vtable = D_004DCF50; m->b24 = type; m->f2C = 0.0f; m->f28 = 0; m->b20 = 4; m->f1C = 0x40; }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg() { vtable = D_004DCF10; }
};
struct Turret {
    char pad0[0x8];
    Gun* gun;
    Model* model;
    float cooldown;
    int shots;
    char pad18[0x58 - 0x18];
    int owner;
    char pad5C[0x68 - 0x5C];
    Aux* aux;
};
static inline unsigned char IsAuth(void) { unsigned char r; if (g_IsMultiplayer) r = D_005721C0; else r = true; return r; }
extern "C" void cTurret_Fire(Turret* t)
{
    t->cooldown = 1.0f / t->aux->rate;
    t->shots++;
    int n = t->aux->burst;
    BulletReq req;
    req.aux = t->aux;
    req.owner = t->owner;
    bool tracer = 0;
    if (n) { if (((t->shots % n) != 0) ^ 1) tracer = 1; }
    req.tracer = tracer;
    req.fD8 = (float)t->aux->f3C; req.speed = 500.0f; req.bD4 = 0;
    TNode* o = t->model->node;
    if (o->dirty) o->Update();
    req.m = o->mtx;
    req.f48 = 0;
    cBulletManager_AddBullet(&req);
    cNIEventBase_SetSpeed(3.0f, t->gun);
    t->gun->Fire();
    t->gun->Start();
    if (g_IsMultiplayer && IsAuth() && t->aux->rate <= 1.0f) {
        Msg m(3);
        QueueMessage_cMessageR_cSystemP_int(&m, t->owner, 0);
    }
}
