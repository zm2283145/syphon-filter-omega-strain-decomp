#pragma cplusplus on
#include "types.h"
struct Q7 { __int128 Q7; };
static inline void QM(void* d, const void* s) { __int128 t; asm { .set noat
 lq t, 0(s)
 sq t, 0(d) } }

struct Id_7800 { int v; };
struct Obj_7800 { char pad[0xC]; int id; };
static inline Id_7800* ObjId(Obj_7800* o) { return (Id_7800*)&o->id; }
static inline Id_7800* MakeId(Id_7800* t, int v) { t->v = v; return t; }
struct Handle_7800 {
    Obj_7800* obj;
    int id;
    Handle_7800(Obj_7800* o) : obj(o), id(-1) { Id_7800 t; id = (o ? ObjId(o) : MakeId(&t, -1))->v; }
};
struct Veh_7800 { char pad[0x3D2]; unsigned char b3D2; unsigned char b3D3; unsigned char b3D4; };
struct Player_7800 {
    char pad[0x3204];
    int f3204;
    char pad3208[8];
    int f3210;
    char pad3214[0x34];
    int f3248;
    char pad324C[0xC4];
    Veh_7800* veh;
    int f3314;
    char pad3318[0x20C];
    int f3524;
};
struct Cam_7800 {
    char pad0[8];
    Obj_7800* obj;
    char padC[4];
    float f10, f14, f18, f1C;
    char pad20[4];
    unsigned char b24;
    char pad25[0x13];
    int f38;
    int f3C;
    char pad40[0x10];
    int f50;
    char pad54[0x6C];
    Handle_7800 h;
    char padC8[0x1C];
    int fE4;
};
struct Flags_7800 { int w[1]; };
struct Out_7800 {
    char pad0[0xCF8];
    Flags_7800 flags;
    Obj_7800* obj;
    int id;
    Obj_7800* tgt;
    int tgtId;
    int fD0C;
    float fD10;
    float fD14, fD18, fD1C, fD20;
    char padD24[0xC];
    Q7 vD30;
    Q7 vD40;
    Q7 vD50;
    Q7 vD60;
    char padD70[0x20];
    Q7 vD90;
};
extern "C" {
extern float D_004A9330;
unsigned char WeaponInv_GetHeldClass(int);
Id_7800* func_0015AC90(Id_7800*, int);
Id_7800* func_00247D50(Obj_7800*);
void Quat_DampTowardIdentity(Q7*, int);
void Camera_ApplyInput(Cam_7800* cam, Out_7800* out, Player_7800* pl, Q7* a3, Q7* t0, Q7* t1, Q7* t2);
}
struct HS_7800 { Obj_7800* obj; int id; };
static inline void SetH(HS_7800* h, Obj_7800* o) { Id_7800 t; h->obj = o; h->id = (o ? func_00247D50(o) : func_0015AC90(&t, -1))->v; }
static inline void SetF(Out_7800* o, float a, float b, float c, float d) { o->fD14 = a; o->fD18 = b; o->fD1C = c; o->fD20 = d; }
static inline bool Eq(int a, int b) { return a == b; }
static inline bool HandleValid(Handle_7800* h) { return !h->obj || Eq(h->obj->id, h->id); }
static inline bool Bit(int v, int b) { return (v >> b) & 1; }
static inline bool CamBit8(Cam_7800* c) { return Bit(c->f3C, 8); }
static inline bool InVeh(Player_7800* p) { return Bit(p->f3204, 4) && p->veh; }
static inline bool VehB3D2(Player_7800* p) { bool r = false; if (InVeh(p) && p->veh->b3D2) r = true; return r; }
static inline bool VehB3D4(Player_7800* p) { return p->veh && p->veh->b3D4; }
void Camera_ApplyInput(Cam_7800* cam, Out_7800* out, Player_7800* pl, Q7* a3, Q7* t0, Q7* t1, Q7* t2)
{
    Obj_7800* tgt;
    int tid;
    Q7 v;
    {
        Handle_7800* h;
        if (CamBit8(cam) != 0) {
            Handle_7800 n(0);
            h = &n;
        } else {
            h = &cam->h;
        }
        tgt = HandleValid(h) ? h->obj : 0;
    }
    tid = CamBit8(cam) ? -1 : cam->fE4;
    SetH((HS_7800*)&out->obj, cam->obj);
    if (tgt) {
        SetH((HS_7800*)&out->tgt, tgt);
        out->fD10 = D_004A9330;
    }
    out->fD0C = tid;
    SetF(out, cam->f14, cam->f10, cam->f18, cam->f1C);
    Q7* p0 = &out->vD30; Q7* p1 = &out->vD40; Q7* p2 = &out->vD50; Q7* p3 = &out->vD60;
    int i = 0;
    QM(p0, t2);
    QM(p1, a3);
    QM(p2, t0);
    QM(p3, t1);
    for (; i <= 0; i++)
        out->flags.w[i] = 0;
    if (cam->f50 == 1)
        out->flags.w[0] |= 1;
    if (cam->f38 == 4) {
        if (!VehB3D2(pl) && cam->b24)
            out->flags.w[0] |= 0x400;
    }
    if (cam->f38 == 4) {
        if (VehB3D2(pl))
            out->flags.w[0] |= 0x800;
    }
    if ((cam->f3C >> 8) & 1) {
        out->flags.w[0] |= 4;
        if (WeaponInv_GetHeldClass(pl->f3524) != 1)
            out->flags.w[0] |= 8;
    }
    if ((cam->f3C >> 5) & 1)
        out->flags.w[0] |= 2;
    if ((cam->f3C >> 7) & 1) {
        out->flags.w[0] |= 0x40;
        if ((pl->f3248 >> 8) & 1)
            out->flags.w[0] |= 0x80;
        if ((pl->f3248 >> 9) & 1)
            out->flags.w[0] |= 0x100;
    }
    if ((cam->f3C >> 6) & 1)
        out->flags.w[0] |= 0x200;
    if ((cam->f3C >> 10) & 1)
        out->flags.w[0] |= 0x10;
    if (((cam->f3C >> 10) & 1) || ((pl->f3248 >> 4) & 1)) {
        int f = pl->f3248;
        if (!((f >> 6) & 1) && !((f >> 7) & 1) && !((pl->f3210 >> 7) & 1)) {
            if (pl->veh)
                pl->veh->b3D3 = 1;
            if (VehB3D4(pl))
                out->flags.w[0] |= 0x20;
        }
    }
    if (pl->f3314) {
        Quat_DampTowardIdentity(&v, pl->f3314);
    } else {
        ((int*)&v)[0] = 0; ((int*)&v)[1] = 0; ((int*)&v)[2] = 0; ((int*)&v)[3] = 0;
    }
    {
        Q7* s = &v;
        Q7* d;
        __int128 x;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(x) : "r"(s));
        d = &out->vD90;
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(x), "r"(d) : "memory");
    }
}

