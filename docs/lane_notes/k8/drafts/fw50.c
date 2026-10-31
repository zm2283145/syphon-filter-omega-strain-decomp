#pragma cplusplus on
#include "types.h"

struct V16 { float x, y, z, w; V16() {} } __attribute__((aligned(16)));
struct VObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual int f54();
    virtual int f58();
    virtual void s21();
    virtual void s22();
    virtual void f64(void*, unsigned char, unsigned char);
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual int fC8();
    virtual void fCC(struct VObj*, unsigned char);
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual V16 fE4();
};


typedef struct WDef {
    char pad0[0x10];
    char name[0x2C];
    int x3C;
    char pad40[0x5C - 0x40];
    int x5C;
    char pad60[0x78 - 0x60];
    unsigned char x78; char pad79[3];
    char pad7C[0xA0 - 0x7C];
    int xA0;
    float xA4;
    char padA8[0xB8 - 0xA8];
    float xB8;
    unsigned char xBC;
    char padBD[3];
    char padC0[0xD4 - 0xC0];
    unsigned char xD4;
    char padD5[0xF0 - 0xD5];
    unsigned char kind;
    char padF1[0x104 - 0xF1];
    int x104;
    char pad108[0x118 - 0x108];
    unsigned char x118;
    char pad119[0x13A - 0x119];
    unsigned char x13A;
    char pad13B;
    char* x13C;
} WDef;

typedef struct Slot { int a; int id; int c; int count; } Slot;

typedef struct Act {
    char pad0[0xC];
    char xC[0x14 - 0xC];
    unsigned char x14; char pad15[3];
    char pad18[0x58 - 0x18];
    VObj* ctl;
    char pad5C[0x2DF0 - 0x5C];
    unsigned char f2DF0;
    unsigned char f2DF1;
} Act;

typedef struct Wpn {
    void* owner;
    Slot slots[6];
    char pad64[0x84 - 0x64];
    unsigned char cur;
    char pad85[0x88 - 0x85];
    Act* actor;
    char pad8C[0x90 - 0x8C];
    VObj* tgt;
    int tgtId;
    unsigned char x98;
    char pad99[3];
    int x9C;
    char padA0[0xA9 - 0xA0];
    unsigned char hand;
    char padAA[0xAC - 0xAA];
    float rate[2];
    union { int xB4[2]; float xB4f[2]; };
    float xBC;
    int xC0;
    char* xC4[2];
    float xCC[2];
    char padD4[0xF4 - 0xD4];
    float xF4;
} Wpn;

typedef struct Ev { void* vt; char pad[0x40 - 4]; } Ev;
typedef struct Ev2 { void* vt; char pad[0x30 - 4]; } Ev2;

extern "C" {
extern void* g_Game;
extern int D_004EE5C0;
extern void* g_WeaponDatabase;
extern int D_004D92A0;
extern int D_004DAE30;
extern int D_004E0840;
extern int D_004D91E0;
extern int g_ActorActionMsgClass;
extern int g_OutOfAmmoMsgClass;
extern int D_0049B1D0;
extern float D_00489C28;
extern float D_00489C30;
extern float D_00489C50;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char g_IsMultiplayer;

extern WDef* cWeaponDB_GetEntry(void*, int);
extern int cAirTaser_Shoot_cGOBJP_bool_int(void*, VObj*, unsigned char, int);
extern void* cSystemContainer_GetSystem(void*, void*);
extern void cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(Ev*, void*, float, float, int);
extern void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
extern void cMessage_dtor(void*, int);
extern int cWeapon_GetClipAmmo(Wpn*, int);
extern int cWeapon_ReadyToFire(Wpn*, unsigned char);
extern void Libc_Strcpy(char*, char*);
extern int Libc_Tolower(int);
extern void cSndFx_ctor_int_charP_cGOBJP_int(void*, int, char*, int, int);
extern void cPlaySoundMsg_ctor_cSndFxR(void*, void*, Act*);
extern void cFileMan_dtor(void*, int);
extern int* nSfxLoader_GetHandle(int);
extern void* cSfxBundle_opNew(int);
extern void cWeaponFx_ctor(void*, void*);
extern int cGobjController_ShouldHitTarget(VObj*);
extern int Libc_Rand(void);
extern float COS(float);
extern float SIN(float);
extern void Mtx44_SetRotation(void*, float, float, float);
extern void cHuman_DoWeaponRecoil(Act*, float, float);
extern int cBulletManager_AddBullet(void*);
extern void AddExtraBullets(int, void*);
extern void Alloc_Lock(int);
extern void EnableIntc(int);
extern void* cMemMan_Allocate(int, int, void*, int);
extern void* cGrenade_ctor(void*, Act*, void*, WDef*);
extern void cGrenade_SetInitialVelocity(void*, float, void*);
extern void cMan_FireShell(void*, int);
extern void cMessage_ctor_cMessageNameR(void*, void*);
extern void cWeapon_AddShotStat(Wpn*, unsigned char);

}
struct cVec { float x, y, z, w; cVec() {} } __attribute__((aligned(16)));
struct cCollisionFace {
    struct { float x, y, z, w; } __attribute__((aligned(16))) v[3];
    char pad30[0x10];
    unsigned char x40;
    char pad41;
    unsigned char x42;
    char pad43[0x60 - 0x43];
    int x60;
    int x64;
    char pad68[8];
};
struct Shot {
    float m[4][4];
    float dmg;
    Act* owner;
    VObj* tgt;
    void* hitTerrain;
    cCollisionFace face;
    cVec hitPos;
    int hitId;
    unsigned char hit;
    unsigned char quiet;
    unsigned char tracer;
    float range;
    WDef* def;
    int particleId;
    float scale;
    char padE8[8];
    Shot() { Shot* t = this; cCollisionFace* f = &t->face; { char* v = (char*)f; do { v += 0x10; } while (v != (char*)f + 0x30); } f->x40 = 0; f->x42 = 0; f->x60 = 0; f->x64 = 0; t->owner = 0; t->tgt = 0; t->hitTerrain = 0; t->def = 0; t->particleId = -1; }
};

typedef struct FxReq { char flag; char pad[3]; void* shot; int fx; } FxReq;

typedef struct Euler { float x; float y; float z; unsigned int pad; } Euler;
typedef struct Mtx16 { float m[4][4]; } __attribute__((aligned(16))) Mtx16;
extern "C" void cMatrix_Set_ColumnMajorForm(Mtx16* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
static inline void EulerToMatrix(Mtx16* m, const Euler* a)
{
    float az = a->z; float ax = a->x; float ay = a->y;
    float cz = COS(az); float sz = SIN(az);
    float cx = COS(ax); float sx = SIN(ax);
    float cy = COS(ay); float sy = SIN(ay);
    float cycz = cy * cz; float cysz = cy * sz; float sycz = sy * cz; float sysz = sy * sz;
    cMatrix_Set_ColumnMajorForm(m,
        cycz + sysz * sx, -cysz + sycz * sx, sy * cx,
        cx * sz, cx * cz, -sx,
        -sycz + cysz * sx, sysz + cycz * sx, cy * cx);
}
static inline void MulM(void* d, void* m, void* p) {
    void* pp = p; void* mm = m;
    __asm__ volatile("lqc2 vf4, 0x0(%1)\n\tlqc2 vf5, 0x10(%1)\n\tlqc2 vf6, 0x20(%1)\n\tlqc2 vf8, 0x0(%2)\n\tlqc2 vf9, 0x10(%2)\n\tlqc2 vf10, 0x20(%2)\n\tlqc2 vf11, 0x30(%2)\n\t"
        "vmulax.xyz ACC, vf4, vf8x\n\tvmadday.xyz ACC, vf5, vf8y\n\tvmaddz.xyz vf8, vf6, vf8z\n\t"
        "vmulax.xyz ACC, vf4, vf9x\n\tvmadday.xyz ACC, vf5, vf9y\n\tvmaddz.xyz vf9, vf6, vf9z\n\t"
        "vmulax.xyz ACC, vf4, vf10x\n\tvmadday.xyz ACC, vf5, vf10y\n\tvmaddz.xyz vf10, vf6, vf10z\n\t"
        "vmulax.xyz ACC, vf4, vf11x\n\tvmadday.xyz ACC, vf5, vf11y\n\tvmaddz.xyz vf11, vf6, vf11z\n\t"
        "sqc2 vf8, 0x0(%0)\n\tsqc2 vf9, 0x10(%0)\n\tsqc2 vf10, 0x20(%0)\n\tsqc2 vf11, 0x30(%0)" : : "r"(d), "r"(mm), "r"(pp) : "memory");
}

static inline void MulV(void* d, void* m, void* v) {
    __asm__ volatile("lqc2 vf8, 0x0(%2)\n\tlqc2 vf4, 0x0(%1)\n\tlqc2 vf5, 0x10(%1)\n\tlqc2 vf6, 0x20(%1)\n\tlqc2 vf7, 0x30(%1)\n\t"
        "vmulax.xyzw ACC, vf4, vf8x\n\tvmadday.xyzw ACC, vf5, vf8y\n\tvmaddaz.xyzw ACC, vf6, vf8z\n\tvmaddw.xyzw vf12, vf7, vf8w\n\t"
        "sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline bool SlotEmpty(Slot* s) { return s->id == -1; }
static inline bool SlotUsed(Slot* s) { return !SlotEmpty(s); }
static inline float RandF(void) { float m = 2147483648.0f; return (float)Libc_Rand() / (1.0f + m); }
static inline void LaunchAt(void* proj, VObj* tgt) {
    V16 pos = tgt->fE4();
    cGrenade_SetInitialVelocity(proj, D_00489C50, &pos);
}
static inline void SendReload(Wpn* self) {
    Ev2 ev;
    Ev2* p = &ev;
    cMessage_ctor_cMessageNameR(p, &g_ActorActionMsgClass);
    p->vt = &D_004E0840;
    *(int*)(p->pad + 0x20) = 0x3C;
    *(unsigned char*)(p->pad + 0x24) = 0;
    QueueMessage_cMessageR_cSystemP_int(p, self->actor, 0);
    ev.vt = &D_004E0840;
    cMessage_dtor(p, 0);
}
static inline void SendOut(Wpn* self, Slot* slot) {
    Ev2 ev;
    int v = slot->id;
    Ev2* p = &ev;
    cMessage_ctor_cMessageNameR(p, &g_OutOfAmmoMsgClass);
    p->vt = &D_004D91E0;
    *(int*)(p->pad + 0x20) = v;
    QueueMessage_cMessageR_cSystemP_int(p, self->actor->ctl, 0);
    ev.vt = &D_004D91E0;
    cMessage_dtor(p, 0);
}
static inline bool IsMul(int a, int b) { return !(a % b); }
static inline void SendNoise(Wpn* self, WDef* def) {
    Ev ev;
    void* svc = cSystemContainer_GetSystem(&g_Game, &D_004EE5C0);
    cAISoundSystemGOBJMessage_ctor_cObjectIdR_eCauseForAwareness_float_float(&ev, self->actor->xC, 1.0f, def->xB8, 4);
    QueueMessage_cMessageR_cSystemP_int(&ev, svc, 0);
    ev.vt = &D_004D92A0;
    cMessage_dtor(&ev, 0);
}
extern "C" unsigned char cWeapon_FireIfReady(Wpn* self, VObj* tgt, int id, unsigned char quiet, unsigned char alt) {
    Slot* slot;
    WDef* def;
    unsigned char fired = 0;
    int spare; int* sparep = &spare;
    unsigned char dual;
    unsigned char dual2;
    VObj* ctl;

    if (self->cur != 6) {
        slot = &self->slots[self->cur];
        def = cWeaponDB_GetEntry(g_WeaponDatabase, slot->id);
        if (def->kind == 5) {
            fired = cAirTaser_Shoot_cGOBJP_bool_int(self->owner, tgt, quiet, id);
            if (fired) SendNoise(self, def);
            return fired;
        }
    }
    if (alt && cWeapon_GetClipAmmo(self, 6) <= 0) {
        self->xC0 = 0;
        self->xBC = 0;
    }
    dual = SlotUsed(&self->slots[1]) && self->cur == 0;
    dual2 = dual && self->hand;
    if (cWeapon_ReadyToFire(self, alt)) {
        unsigned char once;
        float z = 0.0f;
        self->xB4[self->hand] = 0;
        if (dual) self->xB4f[1] = z;
        once = def->x118;
        if (!once || self->xC4[self->hand] == 0) {
            char snd[0x24];
            char req[0x190] __attribute__((aligned(16)));
            char sev[0x1C0] __attribute__((aligned(16)));
            char loud = 1;
            Libc_Strcpy(snd, def->name);
            if (Libc_Tolower(snd[0]) == 'o') {
                loud = 0;
            } else if (def->x78 == 1) {
                VObj* c = self->actor->ctl;
                unsigned char pl = 0;
                if (c && c->f54()) pl = 1;
                if (pl && self->actor->x14) snd[0] = 'P';
            }
            cSndFx_ctor_int_charP_cGOBJP_int(req, loud, snd, 0, 0);
            cPlaySoundMsg_ctor_cSndFxR(sev, req, self->actor);
            sev[0x20] = 1;
            QueueMessage_cMessageR_cSystemP_int(sev, &g_Game, 0);
            if (once) {
                self->xC4[self->hand] = def->name;
                self->xCC[self->hand] = def->kind == 8 ? 0.0f : 0.5f;
            }
            *(void**)sev = &D_004DAE30;
            cFileMan_dtor(sev + 0x114, -1);
            cFileMan_dtor(sev + 0x78, -1);
            cMessage_dtor(sev, 0);
            cFileMan_dtor(req + 0xE4, -1);
            cFileMan_dtor(req + 0x48, -1);
        }
        ctl = self->actor->ctl;
        Shot shot;
        ctl->f64(&shot, dual2, quiet);
        if (!self->xCC[self->hand]) {
            float yaw, pitch;
            shot.dmg = def->x104;
            shot.tgt = 0;
            shot.hit = 0;
            shot.quiet = quiet;
            shot.owner = self->actor;
            shot.def = def;
            shot.hitId = id;
            shot.range = def->x3C;
            shot.scale = 1.0f;
            if (def->kind != 8) {
                FxReq fx;
                void* p;
                fx.flag = 0;
                if (def->x13C) fx.flag = def->x13C[0x411] != -1;
                fx.shot = &shot;
                fx.fx = quiet ? 0 : *nSfxLoader_GetHandle(6);
                p = cSfxBundle_opNew(0x18);
                if (p) cWeaponFx_ctor(p, &fx);
            }
            if (!quiet && tgt && def->x104 >= 200) {
                shot.tgt = tgt;
                if (cGobjController_ShouldHitTarget(ctl)) {
                    shot.hit = 1;
                    if (!ctl->f54() && shot.hitId >= 0 && (unsigned char)tgt->fC8() == 2)
                        shot.hitId = -1;
                }
            }
            { int f = def->xA0; unsigned char h = 0; if (f && IsMul(slot->c, f)) h = 1; shot.tracer = h; }
            yaw = 0.0f;
            pitch = 0.0f;
            if (!quiet && def->kind == 0) {
                float spread;
                unsigned char good = !tgt || shot.hit;
                spread = good ? D_00489C30 : D_00489C28;
                yaw = 2.0f * spread * RandF() - spread;
                pitch = 2.0f * spread * RandF() - spread;
                if (!good) {
                    if (pitch < 0.0f) pitch = (pitch - spread) / 2.0f;
                    else pitch = (pitch + spread) / 2.0f;
                }
            }
            {
                Euler angOff;
                Mtx16 offsetMat;
                angOff.x = yaw; angOff.y = 0.0f; angOff.z = pitch;
                EulerToMatrix(&offsetMat, &angOff);
                MulM(&offsetMat, &shot, &offsetMat);
                shot.m[0][0] = offsetMat.m[0][0];
                shot.m[0][1] = offsetMat.m[0][1];
                shot.m[0][2] = offsetMat.m[0][2];
                shot.m[1][0] = offsetMat.m[1][0];
                shot.m[1][1] = offsetMat.m[1][1];
                shot.m[1][2] = offsetMat.m[1][2];
                shot.m[2][0] = offsetMat.m[2][0];
                shot.m[2][1] = offsetMat.m[2][1];
                shot.m[2][2] = offsetMat.m[2][2];
                shot.m[0][3] = offsetMat.m[0][3];
                shot.m[1][3] = offsetMat.m[1][3];
                shot.m[2][3] = offsetMat.m[2][3];
            }
            if (def->xD4 == 2 || def->xD4 == 1) {
                void* proj;
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                proj = cMemMan_Allocate(0, 0x130, &D_0049B1D0, 0xB12);
                if (g_ProfileLockEnabled) EnableIntc(9);
                g_ProfileLockDepth--;
                if (proj) proj = cGrenade_ctor(proj, self->actor, &shot, def);
                if (!tgt || quiet) {
                    float aim[4] __attribute__((aligned(16)));
                    float tmp[16] __attribute__((aligned(16)));
                    float r;
                    VObj* c;
                    aim[0] = 0; aim[1] = 0.0f; aim[3] = 1.0f; aim[2] = 0;
                    r = quiet ? self->xF4 : def->x3C;
                    c = self->actor->ctl;
                    c->f64(tmp, 0, quiet);
                    aim[1] = r;
                    MulV(aim, tmp, aim);
                    cGrenade_SetInitialVelocity(proj, D_00489C50, aim);
                } else {
                    LaunchAt(proj, tgt);
                }
            } else {
                if (!dual2) {
                    unsigned char k = def->x13A;
                    cHuman_DoWeaponRecoil(self->actor, (float)k / 50.0f, def->xA4);
                }
                {
                    int b = cBulletManager_AddBullet(&shot);
                    if (def->xBC == 1) AddExtraBullets(b, &shot);
                }
                if (dual) {
                    FxReq fx;
                    void* p;
                    ctl->f64(&shot, 1, quiet);
                    cBulletManager_AddBullet(&shot);
                    fx.flag = 0;
                    fx.shot = &shot;
                    fx.fx = quiet ? 0 : *nSfxLoader_GetHandle(6);
                    p = cSfxBundle_opNew(0x18);
                    if (p) cWeaponFx_ctor(p, &fx);
                }
            }
            if (def->kind != 8) {
                Act* a = self->actor;
                a->f2DF0 = 1;
                cMan_FireShell((char*)a + 0x60, 0);
                if (dual) {
                    Act* b = self->actor;
                    b->f2DF1 = 1;
                    cMan_FireShell((char*)b + 0x60, 1);
                }
            }
        }
        SendNoise(self, def);
        if (ctl->f58()) ctl->fCC(tgt, alt);
        if (def->xA4 != 0.0f) self->rate[self->hand] = 1.0f / def->xA4;
        else self->rate[self->hand] = 0.0f;
        if (alt) {
            self->xB4[self->hand + 2]--;
        } else if (def->x5C > 1) {
            int none;
            self->xB4[self->hand + 2] = def->x5C - 1;
            self->tgt = tgt;
            self->tgtId = *(tgt ? (int*)((char*)tgt + 0xC) : (none = -1, &none));
            self->x9C = id;
        }
        self->x98 = quiet;
        if (!self->xCC[self->hand]) {
            if (self->hand) slot++;
            slot->c--;
            if (dual) slot[1].c--;
            if (slot->c == 0) {
                self->xB4[self->hand + 2] = 0;
                if (slot->count) {
                    SendReload(self);
                } else {
                    unsigned char pl = 0;
                    VObj* c = self->actor->ctl;
                    if (c && c->f54()) pl = 1;
                    if (pl && !g_IsMultiplayer) {
                        SendOut(self, slot);
                    }
                }
            }
            fired = 1;
        }
    }
    if (fired) {
        cWeapon_AddShotStat(self, quiet);
        if (dual) cWeapon_AddShotStat(self, quiet);
    }
    return fired;
}

