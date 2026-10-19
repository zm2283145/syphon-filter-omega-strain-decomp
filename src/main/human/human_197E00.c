/*
 * main/human: range (3 files, 00197E00-001987D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_00197E00 */
#pragma push /* merge_units */
typedef struct { char c[128]; } Name_198760;
typedef struct { int a; Name_198760 name; short s84; int i88; int i8C; int i90; unsigned char b94; int i98; } S_198760;
S_198760* func_00198760(S_198760* d, S_198760* s); /* gsynth: defined below */typedef struct { int a[4]; } C5Dq;
typedef struct { char pad[0x3C]; C5Dq sel; } C5Motion;
float MotionCtrl_GetSelectorMetric(C5Motion* m, void* arg); /* gsynth: defined below */
/* Actor_UpdateAnimationEvents (0x00197E00), mw38 MATCH.
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
void Resource_Construct(void* s);
void FileMan_Release(void* s, int flag);
#if 0 /* merge_units */
void* func_00198760(void* d, const void* s);
#endif /* merge_units */
#define func_00198760(a0, a1) ((void *)func_00198760((S_198760 *)(a0), (S_198760 *)(a1))) /* merge_units */

void Vec4_Copy(void* d, const void* s);
}
struct FStr {
    int a; char d[0x98];
    FStr& operator=(const FStr& o) { func_00198760(this, &o); return *this; }
};
struct H { int v; };
struct HObj { int q[3]; int id; };
static inline int& Neg1(int& d) { d = -1; return d; }
struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { Vec4_Copy(this, &o); return *this; }
} __attribute__((aligned(16)));
struct VP { HObj* a; H b; void Set(HObj* o) { a = o; int d; b.v = *(o ? &o->id : (d = -1, &d)); } void Clear() { Set(0); } };
static inline __int128 Dup(int v) { __int128 r; __asm__ volatile("pcpyld %0, %1, %1" : "=r"(r) : "r"(v)); return r; }
static inline HObj* NullObj() { return 0; }


struct SReq;
extern "C" void SoundRequest_Ctor(SReq* r, int type, char* name, int voice, int x180);
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
        Resource_Construct(&p->s48);
        Resource_Construct(&p->sE4);
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
    SReq(int type, char* name, int voice, int x) { SoundRequest_Ctor(this, type, name, voice, x); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SReq() { FileMan_Release(&sE4, -1); FileMan_Release(&s48, -1); }
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
extern char D_0049E000[];
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
float Actor_GetGaitPhase(void* ctrl, Key* k);
#if 0 /* merge_units */
float MotionCtrl_GetSelectorMetric(void* ctrl, Key* k);
#endif /* merge_units */
#define MotionCtrl_GetSelectorMetric(a0, a1) (MotionCtrl_GetSelectorMetric((C5Motion *)(a0), (void *)(a1))) /* merge_units */

void Actor_SurfaceSoundEffects(ActorX* a, int foot, int force);
float Secondary_MotionPhase(void* sec, const Str48* name);
void WeaponInv_LaunchProjectile(int weapon, int* target, int* b, float speed);
void Actor_InfraredSwitch(ActorX* a, unsigned char on);
void* Object_LookupById(int* id);
void Melee_ApplyHit(int weapon, void* obj, int c);
void SoundEvent_CtorFromPreset(SEv* e, SReq* r, ActorX* a);
void Event_Send(SEv* e, char* tgt, int n);
void cMessage_dtor(SEv* e, int flag);
}
static inline bool HasCtl(ActorX* a) { Ctl* c = a->ctl; bool r = 0; if (c) { if (c->dd) { r = 1; asm { .set reorder } } } return r; }
static inline bool Crossed(float prev, float cur, float t) { return prev < t && !(cur < t); }
static inline void* Ctrl(ActorX* a) { return (char*)a + 0x2ED0; }
static inline void PlayEv(SReq* r, ActorX* a, int now)
{
    SEv ev;
    SoundEvent_CtorFromPreset(&ev, r, a);
    ev.flag = 1;
    Event_Send(&ev, g_Game, now);
    ev.vt = D_004DAE30;
    FileMan_Release(&ev.s114, -1);
    FileMan_Release(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
}
extern "C" void Actor_UpdateAnimationEvents(ActorX* a)
{
    Key k1(0);
    Key k2(5);
    char* root = (char*)a + 0x2EC0; SReq* snd = 0;
    SReq req;
    if (MotionCtrl_IsSelectorPlaying(root + 0x10, &k1) && HasCtl(a)) {
        float p1;
        float h;
        float ph = Actor_GetGaitPhase(root + 0x10, &k1);
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
                Actor_SurfaceSoundEffects(a, foot, 0);
        }
        a->phase1 = ph;
    } else {
        a->phase1 = 0.0f;
    }
    if (MotionCtrl_IsSelectorPlaying(root + 0x10, &k2)) {
        float p2;
        float t;
        float ph = Actor_GetGaitPhase(root + 0x10, &k2);
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
        SoundEvent_CtorFromPreset(&ev, snd, a);
        int now = 1;
        ev.flag = now;
        Event_Send(&ev, g_Game, now);
        ev.vt = D_004DAE30;
        FileMan_Release(&ev.s114, -1);
        FileMan_Release(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
    if (a->sec && a->st33E4 == 1) {
        float t = Secondary_MotionPhase(a->sec, &Str48(D_0049E000));
        if (t != -1.0f) {
            if (!(t <= D_0048A250)) {
                WeaponInv_LaunchProjectile(a->weapon, &a->target, &a->x33D0, a->speed);
                a->target = g_NoneWord;
                a->st33E4 = 2;
            }
        } else {
            t = Secondary_MotionPhase(a->sec, &Str48(D_0049DFE0));
            if (t != -1.0f && !(t <= D_0048A250)) {
                WeaponInv_LaunchProjectile(a->weapon, &a->target, &a->x33D0, D_0048A280);
                a->target = g_NoneWord;
                a->st33E4 = 2;
                {
                    SReq r(1, D_0049E060, 0, 0);
                    SEv ev;
                    SoundEvent_CtorFromPreset(&ev, &r, a);
                    ev.flag = 1;
                    Event_Send(&ev, g_Game, 0);
                    ev.vt = D_004DAE30;
                    FileMan_Release(&ev.s114, -1);
                    FileMan_Release(&ev.s78, -1);
                    cMessage_dtor(&ev, 0);
                }
            }
        }
    }
    if (a->sec && a->st33E5 == 1) {
        float t = Secondary_MotionPhase(a->sec, &Str48(D_0049E070));
        if (t != -1.0f && !(t <= D_0048A258)) {
            Actor_InfraredSwitch(a, a->ir33E6);
            a->st33E5 = 2;
        }
    }
    if (a->sec && a->st33E8 == 1) {
        float t = Secondary_MotionPhase(a->sec, &Str48(D_0049DFC8));
        if (t != -1.0f) {
            if (!(t <= D_0048A260)) {
                void* o = Object_LookupById(&a->target);
                if (o)
                    Melee_ApplyHit(a->weapon, o, 0);
                a->st33E8 = 2;
            }
        } else {
            t = Secondary_MotionPhase(a->sec, &Str48(D_0049DFB8));
            if (t != -1.0f && !(t <= D_0048A270)) {
                void* o = Object_LookupById(&a->target);
                if (o)
                    Melee_ApplyHit(a->weapon, o, 0);
                a->st33E8 = 2;
            }
        }
    }
}
#undef func_00198760 /* merge_units */
#undef MotionCtrl_GetSelectorMetric /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00197E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00197E00 */

/* merge_units: begin func_00198760 */
#pragma push /* merge_units */
S_198760* func_00198760(S_198760* d, S_198760* s)
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
extern int func_00198880(C5DqIt* a, C5DqIt* b);
extern void* func_00198BD0(C5DqIt* it);
extern void* func_00198BC0(void* p);
extern float func_00198900(void* p, void* arg);
extern void DequeIter_Next(C5DqIt* it);
float MotionCtrl_GetSelectorMetric(C5Motion* m, void* arg) {
    float sum = 0.0f;
    C5DqIt it;
    C5DqIt end;
    func_00198C40(&it, &m->sel);
    func_00198BE0(&end, &m->sel);
    while (func_00198880(&it, &end)) {
        sum += func_00198900(func_00198BC0(func_00198BD0(&it)), arg);
        DequeIter_Next(&it);
    }
    return sum;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001987D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001987D0 */
