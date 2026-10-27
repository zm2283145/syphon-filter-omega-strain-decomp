/*
 * SFOGame/Source/gameSound: 5 files, 001C78E0-001C7D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C78E0 */
#pragma push /* merge_units */
/* cGameSound_CalcVolPan: volume (0..1024, by distance between the slot's
 * near/far range from the local player) and pan angle (degrees, relative to
 * the camera heading) of a voice positioned at its object or fixed point. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Q16 { __int128 q; };
class XNode {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char p4[0x40 - 4]; V pos; unsigned char dirty;
};
struct Obj { char p0[0xC]; int serial; char p10[0x2C - 0x10]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char p2F[0x50 - 0x2F]; XNode* node; char p54[0x64 - 0x54]; float heading; };
struct Holder { char p0[0x30]; Obj* obj; };
struct Ref { Obj* obj; int serial; };
struct Inst {
    int kind; char p4[0xC]; Q16 v10; Ref ref; char p28[8]; V pos; int busy; unsigned char used; char p45[0xE4 - 0x45];
    char stream[0x178 - 0xE4]; unsigned char b178; char p179[7]; int x180; short x184; unsigned char b186; char p187[0x190 - 0x187];
};
struct Req {
    int kind; char p4[0xC]; Q16 v10; Ref ref; char p28[8]; V pos; char p40[0x180 - 0x40]; int x180; char p184[2]; unsigned char b186;
};
struct Slot { int f0; int f4; char p8[0xC]; unsigned char b14; char p15[0xB]; Inst in; };
struct SoundMgr { char p0[0x30]; Slot slots[50]; };
extern "C" {
extern Holder* g_LocalPlayer;
extern char g_CameraObject[];
Obj** cLList_cCAMERA_GOBJPtr_Front(void* l);
float Libc_Atan2f(float y, float x);
void cGameSound_CalcVolPan(SoundMgr* self, Inst* in, int* vol, int* pan);
}
static inline bool Eq(int a, int b) { return a == b; }
/* weak reference: object if its serial still matches, else 0 */
static inline Obj* Get(Ref* r)
{
    unsigned char v = !r->obj || Eq(r->obj->serial, r->serial);
    return v ? r->obj : 0;
}
static inline bool Not(unsigned char b) { return !b; }
static inline const V& WorldPos(Obj* o) { XNode* n = o->node; if (n->dirty) n->Update(); return n->pos; }
/* VU0 vector ops (COP2) */
static inline V operator-(const V& a, const V& b) { V r; V* pr = &r; const V* pa = &a; const V* pb = &b; asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) } return r; }
static inline V operator-(const V& a) { V r; V* pr = &r; const V* pa = &a; asm { lqc2 vf1, 0(pa); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0(pr) } return r; }
static inline float Deg(float r) { return 57.295776f * r; }
static inline float Atan2(float x, float y) { return Libc_Atan2f(x, y); }
static inline float Length(const V& v)
{
    float r = 0.0f;
    int t;
    const V* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}

void cGameSound_CalcVolPan(SoundMgr* self, Inst* in, int* vol, int* pan)
{
    Obj* o = Get(&in->ref);
    V pos = in->pos;
    if (!o) {
        if (pos.x == 0.0f && pos.y == 0.0f && pos.z == 0.0f) {
            *vol = 1024;
            *pan = -1;
            return;
        }
    } else {
        bool audible = false;
        bool on = false;
        if (o->b2D && o->b2C)
            on = true;
        if (on && Not(o->b2E))
            audible = true;
        if (!audible) {
            *vol = 0;
            *pan = 0;
            return;
        }
    }
    {
        Obj* pl = g_LocalPlayer ? g_LocalPlayer->obj : 0;
        if (o)
            pos = WorldPos(o);
        V rel = pl ? WorldPos(pl) - pos : -pos;
        if (pl) {
            int d = (int)Length(rel);
            int fr = 200;
            int nr = 5;
            int a = self->slots[in->x184].f0;
            int b = self->slots[in->x184].f4;
            if (a)
                nr = a;
            if (b)
                fr = b;
            if (d <= nr) {
                *vol = 1024;
            } else {
                int v = ((fr - d) << 10) / fr;
                *vol = 0 > v ? 0 : v;
            }
        } else {
            *vol = 1024;
        }
        if (*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject)) {
            V cp = WorldPos(*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject));
            rel = pos - cp;
        }
        {
            float a = Atan2(rel.x, rel.y);
            a -= *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) ? (*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject))->heading : 0.0f;
            *pan = (int)(a < 0.0f ? 360.0f + Deg(a) : Deg(a));
        }
    }
}
static inline void merge_flush_func_001C78E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C78E0 */

/* merge_units: begin func_001C7D80 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

typedef struct { int type; char pad[0x3C]; void* ptr; unsigned char flag; } G3S_001C7D80;
typedef struct { char pad[0x50]; G3S_001C7D80 s; char pad2[0x1B0 - 0x50 - sizeof(G3S_001C7D80)]; } G3E_001C7D80;
extern void snd_StopSound(void* p);
extern void snd_FlushSoundCommands(void);
void SoundMgr_StopMusic(G3E_001C7D80* arg) {
    int i;
    G3S_001C7D80* s;
    G3E_001C7D80* e = arg;
    for (i = 0; i < 50; i++, e++) {
        s = &e->s;
        if (s->type == 5) {
            if (s->ptr) {
                snd_StopSound(s->ptr);
                s->ptr = 0;
            }
            s->flag = 0;
        }
    }
    snd_FlushSoundCommands();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7D80 */

/* merge_units: begin func_001C7E00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct SndEv_7E00 { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; unsigned char on; };
struct Slot_7E00 {
    int type; char pad4[0x3C]; int handle; unsigned char state; char pad45[0x1B0 - 0x45 - 0x50];
    bool NotFree() { return (state == 0) ^ 1; }
    bool NotStopping() { return !(state == 1 || state == 3); }
    unsigned char IsActive() {
        unsigned char r = 0;
        if (NotFree())
            if (NotStopping())
                r = 1;
        return r;
    }
};
struct Ent_7E00 { char pad0[0x50]; Slot_7E00 sub; };
struct Self_7E00 { char pad0[0x20]; unsigned char on; };
extern "C" {
extern char D_0049F4A0[];
extern char D_004D9DE0[];
extern void * const D_004DAC30[];
void* cMemMan_Allocate(int, int, char*, int);
void nCallback_SetCallback(SndEv_7E00*);
void snd_AutoVol(int, int, int, int);
void snd_ContinueAllSoundsInGroup(int);
void snd_PauseAllSoundsInGroup(int);
}

extern "C" void cGameSound_PauseMusic(Self_7E00* self, int on)
{
    Slot_7E00* found = 0;
    int i;
    for (i = 0; i < 50; i++) {
        Slot_7E00* s = &((Ent_7E00*)self)[i].sub;
        if (((Ent_7E00*)self)[i].sub.type == 5) {
            if (s->IsActive()) {
                found = s;
                break;
            }
        }
    }
    if (on && !self->on) {
        if (found) {
            SndEv_7E00* e;
            snd_AutoVol(found->handle, 0, 0x1F4, 2);
            {
                AllocGuard g;
                e = (SndEv_7E00*)cMemMan_Allocate(0, 0x10, D_0049F4A0, 0x591);
            }
            if (e) {
                e->vt = D_004D9DE0;
                e->b4 = 0;
                e->time = 0xFA0;
                e->b5 = 0;
                e->vt = (void*)D_004DAC30;
                e->on = 1;
            }
            nCallback_SetCallback(e);
        } else {
            snd_PauseAllSoundsInGroup(2);
        }
        self->on = 1;
    }
    if (!on && self->on) {
        if (found) {
            SndEv_7E00* e;
            snd_AutoVol(found->handle, 0x400, 0x1F4, 2);
            {
                AllocGuard g;
                e = (SndEv_7E00*)cMemMan_Allocate(0, 0x10, D_0049F4A0, 0x5A2);
            }
            if (e) {
                e->vt = D_004D9DE0;
                e->b4 = 0;
                e->time = 0xFA0;
                e->b5 = 0;
                e->vt = (void*)D_004DAC30;
                e->on = 0;
            }
            nCallback_SetCallback(e);
        } else {
            snd_ContinueAllSoundsInGroup(2);
        }
        self->on = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7E00 */

/* merge_units: begin func_001C80B0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char on; } S1C80B0;
extern void snd_PauseAllSoundsInGroup(int);
extern void snd_ContinueAllSoundsInGroup(int);
void cPauseMusicCB_Call(S1C80B0* s) { if (s->on) snd_PauseAllSoundsInGroup(2); else snd_ContinueAllSoundsInGroup(2); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C80B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C80B0 */

/* merge_units: begin func_001C80F0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct WeakT_80F0 { char pad0[0xC]; int serial; };
struct Slot_80F0 {
    int type; char pad4[0xC]; char name[0x10]; WeakT_80F0* obj; int serial; char pad28[0x18]; int handle; unsigned char state; char pad45[0x1B0 - 0x45 - 0x50];
    WeakT_80F0* Get() {
        bool isNull;
        bool ok;
        WeakT_80F0* t;
        t = obj;
        isNull = !t;
        ok = true;
        if (!isNull)
            if (t->serial != serial)
                ok = false;
        return ok ? t : 0;
    }
    bool Used() { return state != 0; }
    bool Stopping() { return state == 1 || state == 3; }
};
struct Ent_80F0 { char pad0[0x50]; Slot_80F0 sub; };
struct Self_80F0;
extern "C" {
extern char D_0049F4B0[];
extern char D_0049F4F0[];
int String_CompareNoCase(char*, char*);
void cGameSound_StopVAG(Self_80F0*, signed char, int, int);
}

extern "C" void cGameSound_StopSound(Self_80F0* self, Slot_80F0* d)
{
    int matched;
    int mode;
    int done;
    int found;
    Slot_80F0* s;
    int i;
    if (d->type == 5) {
        cGameSound_StopVAG(self, d->type, 0, 0);
        return;
    }
    if (d->type == 4) {
        cGameSound_StopVAG(self, d->type, 0, 1);
        return;
    }
    matched = 0;
    mode = 0;
    done = 0;
    found = 0;
    if (d->Get())
        mode = 1;
    while (!done) {
        for (i = 0; i < 50; i++) {
            s = &((Ent_80F0*)self)[i].sub;
            if (s->Used() || s->Stopping()) {
                if (d->type == s->type && String_CompareNoCase(d->name, s->name) == 0) {
                    WeakT_80F0* a = s->Get();
                    WeakT_80F0* b = d->Get();
                    found = 1;
                    if (mode && a && a == b) {
                        matched = 1;
                        break;
                    }
                    if (!mode && !a) {
                        matched = 1;
                        break;
                    }
                    if (mode == -1) {
                        matched = 1;
                        break;
                    }
                }
            }
        }
        if (!found)
            done = 1;
        else if (matched) {
            s->state = 0;
            done = 1;
        } else if (mode == -1)
            sprintf(D_0049F4B0, D_0049F4F0, d->name);
        else if (mode == 0)
            mode = -1;
        else if (mode == 1)
            mode = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C80F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C80F0 */
