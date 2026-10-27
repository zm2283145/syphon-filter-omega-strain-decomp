/*
 * SFOGame/Source/human: 8 files, 001B92E0-001B9310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B92E0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float t; float v; } Endpoint;
typedef struct { Endpoint ep[2]; float scale; } AnimChannel;
/* Sets an endpoint's time and scaled value. */
void cHermiteSplineWithScaledDuration_float_ResetPoint(AnimChannel* c, int i, float* t, float* v)
{
    float value = *v * c->scale;
    Endpoint* ep = &c->ep[i];
    ep->t = *t;
    ep->v = value;
}
static inline void merge_flush_func_001B92E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B92E0 */

/* merge_units: begin func_001B9310 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_9310 { float v; float s; Key_9310() {} };
struct Crv_9310 { Key_9310 k[2]; float dur; float inv; };
/* rebuild a two-key segment in place, keeping its duration */
#pragma push
#pragma opt_unroll_loops off
static inline Crv_9310* Init_9310(Crv_9310* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_9310* e = c->k; do { new (e) Key_9310; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
extern "C" void cHermiteSplineWithScaledDuration_float_Reset(Crv_9310* c, float* v0, float* s0, float* v1, float* s1)
{
    if (c) Init_9310(c, v0, s0, v1, s1, c->dur);
}
#pragma pop
static inline void merge_flush_func_001B9310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9310 */

/* merge_units: begin func_001B93B0 */
#pragma push /* merge_units */
typedef struct { int a[4]; float f10; } Seg1B9;
typedef struct { int a[10]; float f28; int b; Seg1B9* seg; float f34; } Ch1B9;
int cSplinedMotion_float_HasTransitionJustBeenStarted(Ch1B9* c) {
    int r = c->f34 == c->seg->f10;
    if (r) r = c->f28 > 0.0f;
    return r;
}
static inline void merge_flush_func_001B93B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B93B0 */

/* merge_units: begin func_001B9400 */
#pragma push /* merge_units */
static inline float clamp_B940(float a, float lo, float hi) { asm { max.s lo, a, lo
 min.s lo, lo, hi } return lo; }
typedef struct { char pad[8]; float f8; char pad2[0x38 - 0xC]; unsigned char b38; } Ch_B940;
extern float Libc_Fmodf(float a, float b);void cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation(Ch_B940* c) {
    float x = c->f8;
    float v;
    if (!c->b38) {
        v = clamp_B940(x, 0.0f, 1.0f);
    } else {
        v = Libc_Fmodf(x, 1.0f);
        if (v < 0.0f) v += 1.0f;
    }
    c->f8 = v;
}
static inline void merge_flush_func_001B9400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9400 */

/* merge_units: begin func_001B9480 */
#pragma push /* merge_units */
extern float Libc_Fmodf(float, float);
static inline float fmax_(float a, float b) { float r; asm { max.s r, a, b } return r; }
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    char pad18[0x20];
    unsigned char b38;
} B7_AnimCh;
static inline float B7_Wrap(B7_AnimCh* p, float d)
{
    float r;
    if (!p->b38) {
        return d;
    }
    r = Libc_Fmodf(d, 1.0f);
    if (r < 0.5f) {
        r += 1.0f;
    } else if (r > 0.5f) {
        r -= 1.0f;
    }
    return r;
}
void cSplinedMotion_Scalar0To1_UpdateVelocity(B7_AnimCh* p, float dt, float speed)
{
    float d = B7_Wrap(p, p->f8 - p->f4);
    p->fC = speed * d;
    p->fC *= fmax_(0.0f, 1.0f - p->f14 * dt);
}
static inline void merge_flush_func_001B9480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9480 */

/* merge_units: begin func_001B9560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vt8_chain_dtor.h"
DEFINE_VT8_CHAIN_DTOR(cHumanTimeBasedCallback_dtor, D_004DA870, D_004D9DE0)
static inline void merge_flush_func_001B9560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9560 */

/* merge_units: begin func_001B95C0 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } F2Str;
typedef struct {
    char pad0[0x48];
    F2Str s48;
    F2Str sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) F2Req;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    F2Str s78;
    F2Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) F2Ev;
typedef struct { char pad[0xC]; int preset; unsigned char kind; } F2Arg;
extern char D_0049D910[];
extern char g_Game[];
extern char D_004DAE30[];
extern void cSndFx_ctor_int_charP_cGOBJP_int(F2Req* r, int a, char* b, int c, int d);
extern void cPlaySoundMsg_ctor_cSndFxR(F2Ev* e, F2Req* r, int preset);
extern void QueueMessage_cMessageR_cSystemP_int(F2Ev* e, char* tgt, int n);
extern void cFileMan_dtor(F2Str* s, int flag);
extern void cMessage_dtor(F2Ev* e, int flag);
extern void cHuman_HandleFootstepEvent(int preset, int a, int b);
static inline void Play_F2(int preset)
{
    F2Req req;
    F2Ev ev;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, D_0049D910, 0, 0);
    cPlaySoundMsg_ctor_cSndFxR(&ev, &req, preset);
    ev.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
    ev.vt = D_004DAE30;
    cFileMan_dtor(&ev.s114, -1);
    cFileMan_dtor(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
    cFileMan_dtor(&req.sE4, -1);
    cFileMan_dtor(&req.s48, -1);
}
void cHumanTimeBasedCallback_Call(F2Arg* a)
{
    switch (a->kind) {
    case 0:
        cHuman_HandleFootstepEvent(a->preset, 1, 1);
        break;
    case 1:
        Play_F2(a->preset);
        break;
    }
}
static inline void merge_flush_func_001B95C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B95C0 */

/* merge_units: begin func_001B96B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004DA890[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DA890;

DEFINE_MESSAGE_CLONE(cTurnOnWeaponPickupMsg_Clone, Msg_0020E560, 0x24, D_0049D8D0, 0xEF, CLONE_BODY)
static inline void merge_flush_func_001B96B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B96B0 */
