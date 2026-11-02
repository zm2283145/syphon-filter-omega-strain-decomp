/*
 * SFOGame/Source/human: 7 files, 00197560-00197E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00197560 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_S7;
typedef struct { float v[4]; } __attribute__((aligned(16))) Q_S7;
typedef struct { char pad[0xEF]; unsigned char bEF; } Sub3524_S7;
typedef struct { char pad[0x415]; unsigned char b415; } Ob2_S7;
typedef struct {
    char pad0[0x14]; unsigned char b14; char pad15[0x3210 - 0x15]; int f3210; char pad3214[0x324C - 0x3214]; int f324C; char pad3250[0x3314 - 0x3250];
    Ob2_S7* s3314; char pad3318[0x33CC - 0x3318];
    int f33CC; Q_S7 q33D0; float f33E0; unsigned char b33E4; char pad33E5[0x3524 - 0x33E5];
    Sub3524_S7* f3524;
} SA_S7;

#define MSG_HDR_S7 \
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3]
typedef struct { MSG_HDR_S7; int f24; unsigned char f28; char pad29[3]; int f2C; unsigned char f30; char pad31[3]; float f34; char pad38[8]; } AEv_S7;
typedef struct { MSG_HDR_S7; int id; char pad28[8]; Q_S7 pos; float f40; } MsgT_S7;

extern "C" {
extern char D_00542B60[]; extern char D_004DA930[];
extern char D_004EEED0[]; extern char D_004DA8D0[]; extern char D_004DCF10[];
extern char D_0049E000[]; extern char D_00504068[]; extern char D_004DCDC0[]; extern unsigned char g_IsMultiplayer;
void cMessage_ctor_cMessageNameR(void* m, void* t);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
#if 0 /* merge_units */
void cMessage_dtor(void* m, int f);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

unsigned char Secondary_RequestOneShot(Ob2_S7* o, Name_S7* n, unsigned char kind, AEv_S7* p);
}

#define NAME_COPY_S7(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = ckc_s[ckc_i]; (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }

static inline void QCp_S7(Q_S7* d, const Q_S7* s) { __int128 q; asm volatile { lq q, 0(s)
 sq q, 0(d) } }

extern "C" void cHuman_ThrowGrenade(SA_S7* a, int* id, Q_S7* pos, float f)
{
    if ((a->f3210 >> 24) & 1) {
        if (a->b14) return;
        if ((a->f324C >> 9) & 1) return;
    }
    if (a->s3314) {
        MsgT_S7 m;
        Name_S7 n;
        AEv_S7 e;
        unsigned char ok;
        AEv_S7* pe = &e;
        cMessage_ctor_cMessageNameR(pe, D_00542B60);
        pe->vtable = D_004DA930;
        pe->f24 = 2;
        pe->f28 = 0;
        pe->f2C = (int)a;
        pe->f30 = 0;
        pe->f34 = 0.0f;
        NAME_COPY_S7(n.c, D_0049E000)
        ok = Secondary_RequestOneShot(a->s3314, &n, 3, &e);
        e.vtable = D_004DA930;
        cMessage_dtor(&e, 0);
        if (ok) {
            a->f33CC = *id;
            QCp_S7(&a->q33D0, pos);
            a->f33E0 = f;
            a->b33E4 = 1;
            { Sub3524_S7* sp = a->f3524; sp->bEF = 1; }
            if (g_IsMultiplayer && a->b14) {
                MsgT_S7* pm = &m;
                cMessage_ctor_cMessageNameR(pm, D_00504068);
                pm->vtable = D_004DCF10;
                pm->vtable = D_004DCDC0;
                pm->id = -1;
                pm->id = *id;
                QCp_S7(&pm->pos, pos);
                pm->f40 = f;
                m.f20 = 4;
                QueueMessage_cMessageR_cSystemP_int(&m, a, 0);
                m.vtable = D_004DCF10;
                cMessage_dtor(pm, 0);
            }
        }
    }
}

#pragma pop
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00197560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00197560 */

/* merge_units: begin func_00197780 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetGrenadeMsg_dtor, D_004DCDC0, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_00197780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00197780 */

/* merge_units: begin func_001977F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctl_1977F0 { char pad[0x810]; int flags; };
struct Inv_1977F0 { char pad[0x18]; int v18; char pad1C[0x84 - 0x1C]; unsigned char b84; };
struct A_1977F0 {
    char pad0[0x31B2];
    unsigned char autoAim;              /* 0x31B2 */
    char pad31B3[0x31C4 - 0x31B3];
    float f31C4;                        /* 0x31C4 */
    char pad31C8[0x31D0 - 0x31C8];
    float f31D0;                        /* 0x31D0 */
    char pad31D4[0x3204 - 0x31D4];
    int flags3204;                      /* 0x3204 */
    char pad3208[0x320C - 0x3208];
    int state;                          /* 0x320C */
    char pad3210[0x3248 - 0x3210];
    int flags3248;                      /* 0x3248 */
    char pad324C[0x3310 - 0x324C];
    Ctl_1977F0* ctl;                    /* 0x3310 */
    void* secondary;                    /* 0x3314 */
    char pad3318[0x33EC - 0x3318];
    unsigned char* flashlight;          /* 0x33EC */
    char pad33F0[0x3524 - 0x33F0];
    Inv_1977F0* inv;                    /* 0x3524 */
};

extern "C" {
int cWeapon_GetPoseType(Inv_1977F0* inv);
unsigned char cWeapon_GetEquipmentType(Inv_1977F0* inv);
void cHumanIkRoutine_SetAimWeaponMode(void* s, int mode);
}

static inline unsigned char CtlBit9_1977F0(A_1977F0* a)
{
    unsigned char r = 0;
    if (a->ctl && ((a->ctl->flags >> 9) & 1)) r = 1;
    return r;
}

static inline unsigned char Swim9_1977F0(A_1977F0* a)
{
    unsigned char r = 0;
    if (a->state == 8 && CtlBit9_1977F0(a)) r = 1;
    return r;
}

static inline unsigned char FlashOn_1977F0(A_1977F0* a)
{
    unsigned char r = 0;
    if (a->flashlight != 0 && *a->flashlight != 0) r = 1;
    return r;
}

static inline bool Armed_1977F0(A_1977F0* a, bool melee) { return a->inv->b84 != 6 && !melee; }
static inline unsigned char CanAim_1977F0(A_1977F0* a, bool melee) { unsigned char r = 1; if (!Armed_1977F0(a, melee) && !FlashOn_1977F0(a)) r = 0; return r; }
static inline unsigned char OkAim_1977F0(A_1977F0* a, unsigned char want, bool melee) { unsigned char r = 0; if (want && CanAim_1977F0(a, melee)) r = 1; return r; }
static inline bool AimState_1977F0(A_1977F0* a, bool swimAim, bool ladder, bool bit3)
{
    return a->state == 0 || swimAim || ladder || bit3;
}

static inline bool Loaded_1977F0(Inv_1977F0* w)
{
    return !(w->v18 == -1) && w->b84 == 0;
}

extern "C" void cHuman_AimWeapon(A_1977F0* a, unsigned char want)
{
    bool melee;
    unsigned char swimAim;
    bool bit3;
    unsigned char ok;
    bool ladder;
    int eq;
    unsigned char aim;
    bool water;
    bool hold;
    int mode;
    unsigned char k;
    eq = cWeapon_GetPoseType(a->inv);
    melee = cWeapon_GetEquipmentType(a->inv) == 1;
    water = a->state == 8 || a->state == 0x10;
    swimAim = 0;
    if (Swim9_1977F0(a) && (a->flags3204 & 1)) swimAim = 1;
    ladder = a->state == 0x10;
    bit3 = (a->flags3248 >> 3) & 1;
    aim = 0;
    ok = OkAim_1977F0(a, want, melee);
    if (ok && AimState_1977F0(a, swimAim, ladder, bit3)) aim = 1;
    hold = ((a->flags3204 >> 4) & 1) && !(a->flags3204 & 1);

    a->autoAim = aim;
    k = eq;
    switch (k) {
    case 1:
        if (aim) {
            if (water) mode = 0x17;
            else if (Loaded_1977F0(a->inv)) mode = 5;
            else mode = 2;
        } else {
            if (Loaded_1977F0(a->inv) || melee || water) mode = 1;
            else if (a->state == 0 && !((a->flags3204 >> 3) & 1) && !(a->f31D0 <= 0.75f) && !(a->f31C4 <= 0.1f)) mode = 1;
            else mode = 0xD;
        }
        break;
    case 8:
        if (aim) {
            if (water) mode = 0x17;
            else mode = 6;
        } else {
            mode = 1;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (aim) {
            if (water) {
                if (k == 3) mode = 0x17;
                else mode = 1;
            } else if (k == 3) {
                if (a->flags3204 & 1) mode = 9;
                else mode = 8;
            } else {
                if (a->flags3204 & 1) mode = 0xB;
                else mode = 0xA;
            }
        } else {
            if (water) mode = 1;
            else if (k == 4) mode = 0xF;
            else mode = 0xE;
        }
        break;
    case 6:
        if (aim) {
            if (water) mode = 1;
            else mode = 0xC;
        } else {
            if (water) mode = 1;
            else mode = 0x10;
        }
        break;
    case 0:
    case 7:
    case 9:
        if (aim && FlashOn_1977F0(a)) {
            if (water) {
                if (ladder) mode = 1;
                else mode = 0x17;
            } else {
                mode = 7;
            }
        } else if (water) {
            mode = 1;
        } else {
            switch (cWeapon_GetEquipmentType(a->inv)) {
            case 3: mode = 0x11; break;
            case 4: mode = 0x12; break;
            case 10: mode = 0x13; break;
            case 7: mode = 1; break;
            default: mode = 1; break;
            }
        }
        break;
    }
    if (a->state != 0 || hold) {
        if (a->state == 4) goto s4;
        if (a->state == 5 || a->state == 10 || a->state == 11) {
        s4:
            if ((unsigned char)mode == 0xE && !((a->flags3248 >> 10) & 1) && !((a->flags3248 >> 12) & 1)) goto done;
        }
        if (a->state == 3 && ((unsigned char)mode == 0xD || (unsigned char)mode == 0xE || (unsigned char)mode == 0xF)) goto done;
        if (a->state == 2 && (!((unsigned char)mode == 0xD || (unsigned char)mode == 6 || (unsigned char)mode == 0x10 || (unsigned char)mode == 0x11 || (unsigned char)mode == 0x12 || (unsigned char)mode == 0x13) || ((a->flags3248 >> 3) & 1))) goto done;
        if (!water) mode = 1;
    }
done:

    if (a->secondary) cHumanIkRoutine_SetAimWeaponMode(a->secondary, mode);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001977F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001977F0 */

/* merge_units: begin func_00197E00 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

typedef struct { char c[128]; } Name_198760;
typedef struct { int a; Name_198760 name; short s84; int i88; int i8C; int i90; unsigned char b94; int i98; } S_198760;
S_198760* cFileMan_opAssign(S_198760* d, S_198760* s); /* gsynth: defined below */typedef struct { int a[4]; } C5Dq;
typedef struct { char pad[0x3C]; C5Dq sel; } C5Motion;
float MotionCtrl_GetSelectorMetric(C5Motion* m, void* arg); /* gsynth: defined below */
/* cHuman_DetectForAnimationEvents (0x00197E00), mw38 MATCH.
 * Key: the SReq ctor's mask is built with a GCC-style __asm__ pcpyld (MW-style asm{} kept the
 * null-handle Set(0) folded); the handle clear is SReq::SetH(0, none) with the -1 passed in as a
 * parameter, which leaves retail's constant branch + dead 'li 0xC' arm. UNDEF __dl__FPv from the
 * dropped weak ~SReq is the usual benign one. */
#pragma cplusplus on
#pragma exceptions off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
extern "C" {
void cFileMan_ctor_void(void* s);
void cFileMan_dtor(void* s, int flag);
#if 0 /* merge_units */
void* cFileMan_opAssign(void* d, const void* s);
#endif /* merge_units */
S_198760* cFileMan_opAssign(S_198760* d, S_198760* s); /* merge_units */
#define cFileMan_opAssign(a0, a1) ((void *)cFileMan_opAssign((S_198760 *)(a0), (S_198760 *)(a1))) /* merge_units */



void cVector_opAssign(void* d, const void* s);
}
struct FStr {
    int a; char d[0x98];
    FStr& operator=(const FStr& o) { cFileMan_opAssign(this, &o); return *this; }
};
struct H { int v; };
struct HObj { int q[3]; int id; };
static inline int& Neg1(int& d) { d = -1; return d; }
struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { cVector_opAssign(this, &o); return *this; }
} __attribute__((aligned(16)));
struct VP { HObj* a; H b; void Set(HObj* o) { a = o; int d; b.v = *(o ? &o->id : (d = -1, &d)); } void Clear() { Set(0); } };
static inline __int128 Dup(int v) { __int128 r; __asm__ volatile("pcpyld %0, %1, %1" : "=r"(r) : "r"(v)); return r; }
static inline HObj* NullObj() { return 0; }


struct SReq;
extern "C" void cSndFx_ctor_int_charP_cGOBJP_int(SReq* r, int type, char* name, int voice, int x180);
struct SReq {
    int id;
    __int128 mask;
    VP f20;
    V4 v30;
    int x40;
    signed char x44;
    FStr s48;
    FStr sE4;
    int x180;
    short x184;
    unsigned char x186;
    void SetH(HObj* o, int m) { f20.a = o; int d; f20.b.v = *(o ? &o->id : (d = m, &d)); }
    SReq() {
        SReq* p = this;
        p->f20.b.v = -2;
        p->f20.a = (HObj*)0;
        cFileMan_ctor_void(&p->s48);
        cFileMan_ctor_void(&p->sE4);
        HObj* o = 0;
        int none = -1;
        p->id = none;
        p->mask = Dup(none);
        p->SetH(0, none);
        p->v30.x = 0;
        p->v30.y = 0;
        p->v30.z = 0;
        p->x184 = -1;
        p->x180 = 0;
        p->x186 = 0;
    }
    SReq(int type, char* name, int voice, int x) { cSndFx_ctor_int_charP_cGOBJP_int(this, type, name, voice, x); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SReq() { cFileMan_dtor(&sE4, -1); cFileMan_dtor(&s48, -1); }
};
struct SEv {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    FStr s78;
    FStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Str48 {
    char s[0x30];
    Str48(char* src) {
        unsigned char end = 0;
        int i = 0;
        char c;
        char* p = src;
        for (; i < 0x2F; i++) {
            if (p[i] == 0) end = 1;
            c = 0;
            if (end) asm { .set reorder } else c = p[i];
            s[i] = c;
        }
        s[i] = 0;
    }
};
struct Key { int a, b; Key(int x) { a = 0; b = x; } };
struct Ctl { char pad[0xDD]; unsigned char dd; };
struct Actor {
    char pad0[0x2EC0];
    char root[0x10];
    char ctrl[0x3260 - 0x2ED0];
    unsigned char b3260;
    char pad3261[0x31DD - 0x3261 + 0x100];
};
struct ActorX {
    char pad0[0x31DD];
    unsigned char foot;
    char pad31DE[0x3260 - 0x31DE];
    unsigned char b3260;
    char pad3261[0x3310 - 0x3261];
    Ctl* ctl;
    void* sec;
    char pad3318[0x33CC - 0x3318];
    int target;
    int x33D0;
    char pad33D4[0x33E0 - 0x33D4];
    float speed;
    unsigned char st33E4;
    unsigned char st33E5;
    unsigned char ir33E6;
    unsigned char pad33E7;
    unsigned char st33E8;
    char pad33E9[0x351C - 0x33E9];
    float phase1;
    float phase2;
    int weapon;
};
extern "C" {
extern char D_0049DFB8[];
extern char D_0049DFC8[];
extern char D_0049DFE0[];
extern char D_0049E048[];
extern char D_0049E060[];
extern char D_0049E070[];
extern float D_0048A250;
extern float D_0048A258;
extern float D_0048A260;
extern float D_0048A270;
extern float D_0048A280;
extern int g_NoneWord;
extern char D_004DAE30[];
extern char g_Game[];
int MotionCtrl_IsSelectorPlaying(void* ctrl, Key* k);
float cSkaParams_GetPlaybackWeight(void* ctrl, Key* k);
#if 0 /* merge_units */
float MotionCtrl_GetSelectorMetric(void* ctrl, Key* k);
#endif /* merge_units */
float MotionCtrl_GetSelectorMetric(C5Motion* m, void* arg); /* merge_units */
#define MotionCtrl_GetSelectorMetric(a0, a1) (MotionCtrl_GetSelectorMetric((C5Motion *)(a0), (void *)(a1))) /* merge_units */



void cHuman_HandleFootstepEvent(ActorX* a, int foot, int force);
float Secondary_MotionPhase(void* sec, const Str48* name);
void cWeapon_Throw(int weapon, int* target, int* b, float speed);
void cHuman_EquipGoggles(ActorX* a, unsigned char on);
void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void Melee_ApplyHit(int weapon, void* obj, int c);
void cPlaySoundMsg_ctor_cSndFxR(SEv* e, SReq* r, ActorX* a);
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(SEv* e, char* tgt, int n);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(SEv* e, int flag);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

}
static inline bool HasCtl(ActorX* a) { Ctl* c = a->ctl; bool r = 0; if (c) { if (c->dd) { r = 1; asm { .set reorder } } } return r; }
static inline bool Crossed(float prev, float cur, float t) { return prev < t && !(cur < t); }
static inline void* Ctrl(ActorX* a) { return (char*)a + 0x2ED0; }
static inline void PlayEv(SReq* r, ActorX* a, int now)
{
    SEv ev;
    cPlaySoundMsg_ctor_cSndFxR(&ev, r, a);
    ev.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, now);
    ev.vt = D_004DAE30;
    cFileMan_dtor(&ev.s114, -1);
    cFileMan_dtor(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
}
extern "C" void cHuman_DetectForAnimationEvents(ActorX* a)
{
    Key k1(0);
    Key k2(5);
    char* root = (char*)a + 0x2EC0; SReq* snd = 0;
    SReq req;
    if (MotionCtrl_IsSelectorPlaying(root + 0x10, &k1) && HasCtl(a)) {
        float p1;
        float h;
        float ph = cSkaParams_GetPlaybackWeight(root + 0x10, &k1);
        int foot;
        if (a->b3260 == 1) {
            float o = 0.325f; ph += o;
        } else
            ph += 0.325f;
        if (ph < 0.0f)
            ph += 1.0f;
        else if (!(ph < 1.0f))
            ph += -1.0f;
        p1 = a->phase1;
        h = 0.5f;
        if (p1 < h && !(ph < h))
            foot = 2;
        else if (!(a->phase1 <= ph))
            foot = 1;
        else
            foot = 0;
        if ((unsigned char)foot) {
            a->foot = foot;
            if (!(MotionCtrl_GetSelectorMetric(root + 0x10, &k1) <= 0.5f))
                cHuman_HandleFootstepEvent(a, foot, 0);
        }
        a->phase1 = ph;
    } else {
        a->phase1 = 0.0f;
    }
    if (MotionCtrl_IsSelectorPlaying(root + 0x10, &k2)) {
        float p2;
        float t;
        float ph = cSkaParams_GetPlaybackWeight(root + 0x10, &k2);
        p2 = a->phase2; t = 0.11f; if (p2 < t && !(ph < t)) goto hit;
        p2 = a->phase2; t = 0.3f; if (p2 < t && !(ph < t)) goto hit;
        p2 = a->phase2; t = 0.46f; if (p2 < t && !(ph < t)) goto hit;
        p2 = a->phase2; t = 0.66f; if (p2 < t && !(ph < t)) goto hit;
        p2 = a->phase2; t = 0.8f; if (p2 < t && !(ph < t)) goto hit;
        if (!(a->phase2 <= ph)) goto hit;
        goto done;
    hit:
        if (!(MotionCtrl_GetSelectorMetric(root + 0x10, &k2) <= 0.25f)) {
            req = SReq(1, D_0049E048, 0, 0);
            snd = &req;
        }
    done:
        a->phase2 = ph;
    } else {
        a->phase2 = 0.0f;
    }
    if (snd) {
        SEv ev;
        cPlaySoundMsg_ctor_cSndFxR(&ev, snd, a);
        int now = 1;
        ev.flag = now;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, now);
        ev.vt = D_004DAE30;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
    if (a->sec && a->st33E4 == 1) {
        float t = Secondary_MotionPhase(a->sec, &Str48(D_0049E000));
        if (t != -1.0f) {
            if (!(t <= D_0048A250)) {
                cWeapon_Throw(a->weapon, &a->target, &a->x33D0, a->speed);
                a->target = g_NoneWord;
                a->st33E4 = 2;
            }
        } else {
            t = Secondary_MotionPhase(a->sec, &Str48(D_0049DFE0));
            if (t != -1.0f && !(t <= D_0048A250)) {
                cWeapon_Throw(a->weapon, &a->target, &a->x33D0, D_0048A280);
                a->target = g_NoneWord;
                a->st33E4 = 2;
                {
                    SReq r(1, D_0049E060, 0, 0);
                    SEv ev;
                    cPlaySoundMsg_ctor_cSndFxR(&ev, &r, a);
                    ev.flag = 1;
                    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
                    ev.vt = D_004DAE30;
                    cFileMan_dtor(&ev.s114, -1);
                    cFileMan_dtor(&ev.s78, -1);
                    cMessage_dtor(&ev, 0);
                }
            }
        }
    }
    if (a->sec && a->st33E5 == 1) {
        float t = Secondary_MotionPhase(a->sec, &Str48(D_0049E070));
        if (t != -1.0f && !(t <= D_0048A258)) {
            cHuman_EquipGoggles(a, a->ir33E6);
            a->st33E5 = 2;
        }
    }
    if (a->sec && a->st33E8 == 1) {
        float t = Secondary_MotionPhase(a->sec, &Str48(D_0049DFC8));
        if (t != -1.0f) {
            if (!(t <= D_0048A260)) {
                void* o = nGobjManager_LookupGOBJ_cObjectIdR(&a->target);
                if (o)
                    Melee_ApplyHit(a->weapon, o, 0);
                a->st33E8 = 2;
            }
        } else {
            t = Secondary_MotionPhase(a->sec, &Str48(D_0049DFB8));
            if (t != -1.0f && !(t <= D_0048A270)) {
                void* o = nGobjManager_LookupGOBJ_cObjectIdR(&a->target);
                if (o)
                    Melee_ApplyHit(a->weapon, o, 0);
                a->st33E8 = 2;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00197E00(void) {}
#undef cFileMan_opAssign /* merge_units */
#undef MotionCtrl_GetSelectorMetric /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00197E00 */

/* merge_units: begin func_00198760 */
#pragma push /* merge_units */
S_198760* cFileMan_opAssign(S_198760* d, S_198760* s)
{
    d->a = s->a;
    d->name = s->name;
    d->s84 = s->s84;
    d->i88 = s->i88;
    d->i8C = s->i8C;
    d->i90 = s->i90;
    d->b94 = s->b94;
    d->i98 = s->i98;
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198760 */

/* merge_units: begin func_001987D0 */
#pragma push /* merge_units */
typedef struct { void* cur; void* first; void* last; void** node; int pad[4]; } C5DqIt;


extern void func_00198C40(C5DqIt* out, C5Dq* d);
extern void func_00198BE0(C5DqIt* out, C5Dq* d);
#if 0 /* merge_units */
extern int func_00198880(C5DqIt* a, C5DqIt* b);
#endif /* merge_units */
int func_00198880(); /* merge_units */


extern void* func_00198BD0(C5DqIt* it);
extern void* func_00198BC0(void* p);
extern float cSkaPlaybackList_FreezePlayback_cSkaPlaybackGroupIdR_bool(void* p, void* arg);
extern void DequeIter_Next(C5DqIt* it);
float MotionCtrl_GetSelectorMetric(C5Motion* m, void* arg) {
    float sum = 0.0f;
    C5DqIt it;
    C5DqIt end;
    func_00198C40(&it, &m->sel);
    func_00198BE0(&end, &m->sel);
    while (func_00198880(&it, &end)) {
        sum += cSkaPlaybackList_FreezePlayback_cSkaPlaybackGroupIdR_bool(func_00198BC0(func_00198BD0(&it)), arg);
        DequeIter_Next(&it);
    }
    return sum;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001987D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001987D0 */

/* merge_units: begin func_00198880 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_00198880(char* a, char* b) {
    return !(*(int*)(a + 16) == *(int*)(b + 16));
}
static inline void merge_flush_func_00198880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198880 */
