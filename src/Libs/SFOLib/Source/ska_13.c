/*
 * Libs/SFOLib/Source/ska: 10 files, 003ACF60-003AD3F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ACF60 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vtable; char pad[0x20]; int value; char pad2[8]; } Msg;
typedef struct { int value; void* target; } S;
extern char D_00542B68[];
extern char D_004DFBD0[];
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends an immediate message carrying s->value to s->target. */
void cSkaAnimEvent_Trigger(S* s)
{
    Msg msg;
    int value = s->value;
    cMessage_ctor_cMessageNameR(&msg, D_00542B68);
    msg.value = value;
    msg.vtable = D_004DFBD0;
    QueueMessage_cMessageR_cSystemP_int(&msg, s->target, 1);
    msg.vtable = D_004DFBD0;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_003ACF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ACF60 */

/* merge_units: begin func_003ACFE0 */
#pragma push /* merge_units */
typedef struct Phase {
    float lo;
    float hi;
} Phase;

int cSkaAnimCheckpoints_cTimedEvent_IsTimeToTriggerEvent(const Phase* a, const Phase* b) {
    float alo = a->lo;
    float ahi = a->hi;
    if (!(ahi < alo) && !(b->hi < b->lo)) {
        return alo <= b->hi && ahi > b->lo;
    }
    if (ahi < alo && !(b->hi < b->lo)) {
        float bhi = b->hi;
        float blo = b->lo;
        return (alo - 1.0f <= bhi && ahi > blo) || (alo <= bhi && 1.0f + ahi > blo);
    }
    if (!(ahi < alo) && b->hi < b->lo) {
        float bhi = b->hi;
        float blo = b->lo;
        return (alo <= bhi && ahi > blo - 1.0f) || (alo <= 1.0f + bhi && ahi > blo);
    }
    return alo <= 1.0f + b->hi && 1.0f + ahi > b->lo;
}
static inline void merge_flush_func_003ACFE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ACFE0 */

/* merge_units: begin func_003AD1D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


void* cSkaPlaybackGroup_PlaybackPosWithHistory(char* self) {
    return self + 8;
}
static inline void merge_flush_func_003AD1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AD1D0 */

/* merge_units: begin func_003AD1E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Look up the entry matching key and return its info block (or a blank one). */
typedef struct { int w[1]; } It_3AD1E0;
typedef struct { int a; int b; unsigned char c; } Info_3AD1E0;
typedef struct { unsigned char pad[0x20]; Info_3AD1E0 info; } Ent_3AD1E0;

extern "C" {
void cArray_cString_REnd(It_3AD1E0* out, void* map);
void func_00198B60(It_3AD1E0* out, void* map);
bool opNe_cConstLListIteratorR_cConstLListIteratorR(It_3AD1E0* a, It_3AD1E0* b);
Ent_3AD1E0** cConstLListIterator_cSkaPlaybackGroupPtr_opMul(It_3AD1E0* it);
void cConstLListIterator_cSkaPlaybackGroupPtr_opInc(It_3AD1E0* it);
int cSkaPlaybackGroup_CheckId(Ent_3AD1E0* e, void* key);
}

extern "C" Info_3AD1E0* func_003AD1E0(void* map, void* key)
{
    Ent_3AD1E0* found = 0;
    It_3AD1E0 it;
    It_3AD1E0 end;
    Info_3AD1E0 blank;
    cArray_cString_REnd(&it, map);
    func_00198B60(&end, map);
    for (; opNe_cConstLListIteratorR_cConstLListIteratorR(&it, &end); cConstLListIterator_cSkaPlaybackGroupPtr_opInc(&it)) {
        if (cSkaPlaybackGroup_CheckId(*cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it), key)) {
            found = *cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it);
            break;
        }
    }
    if (found)
        return &found->info;
    blank.a = 0;
    blank.b = 0;
    blank.c = 0;
    return &blank;
}
static inline void merge_flush_func_003AD1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AD1E0 */

/* merge_units: begin func_003AD2C0 */
#pragma push /* merge_units */
#include "ska_types.h"

typedef struct HandlePair {
    int first;
    int second;
} HandlePair;

/* True when first is non-zero or second is not -1. */
int cSkaPlaybackGroupId_IsValid(HandlePair* p) {
    return p->first != 0 || ~p->second != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD2C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD2C0 */

/* merge_units: begin func_003AD2F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; int v; } Obj40;
/* Returns whether the field at +0x40 is set. */
int cSkaAnimCheckpoints_HasScheduledEvents(Obj40* o) { return !(o->v == 0); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD2F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD2F0 */

/* merge_units: begin func_003AD310 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern SkaTransitionReq* std_list_deleter_voidPtr_ctor_void(SkaTransitionReq* self);

/* True when both requests carry the same key. */
int cDequeue_cSkaSystem_Request_ReverseIterator_opEq(SkaTransitionReq* a, SkaTransitionReq* b) {
    return a->key == b->key;
}

SkaTransitionReq* TransitionReq_Construct(SkaTransitionReq* self, float time) {
    std_list_deleter_voidPtr_ctor_void(self);
    self->unk0C = time;
    return self;
}

/* Reset: zero words, both limits to FLT_MAX. */
SkaTransitionReq* cSkaSystem_Transition_ctor_void(SkaTransitionReq* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk08 = 3.4028235e38f;
    self->unk0C = 3.4028235e38f;
    self->key = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD310 */

/* merge_units: begin func_003AD3A0 */
#pragma push /* merge_units */
typedef struct { char data[0xF8]; } DequeItem;
typedef struct { unsigned int mapSize; int unk4; unsigned int start; DequeItem** map; unsigned int first; unsigned int count; } Deque;

/* Returns a pointer to the last element of a block-based deque (8 items per block). */
DequeItem* std_deque_deleter_common_cSkaSystem_Request_back_void_2(Deque* self)
{
    unsigned int index = self->first + self->count - 1;
    return &self->map[(self->start + (index >> 3)) % self->mapSize][index & 7];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD3A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD3A0 */

/* merge_units: begin func_003AD3F0 */
#pragma push /* merge_units */
typedef struct {
    unsigned char b0;
    unsigned char b1;
    char pad2[2];
    int i4;
    char req[0x14];
    char x1C[8];
    char ev1[0x38];
    char ev2[0x38];
    char x94[0x4C];
    float fE0;
    int iE4;
    char trans[0x10];
} F6Sel;
typedef struct { char pad[0x18]; char a18[0x14]; int n2C; char a30[0x14]; int n44; } F6Ctl;
#if 0 /* merge_units */
extern F6Sel* std_deque_deleter_common_cSkaSystem_Request_back_void_2(void* arr);
#endif /* merge_units */
#define std_deque_deleter_common_cSkaSystem_Request_back_void_2(a0) ((F6Sel *)std_deque_deleter_common_cSkaSystem_Request_back_void_2((Deque *)(a0))) /* merge_units */

extern signed char D_00542B70;
extern char D_00542B78[];
extern F6Sel D_00542B90;
#if 0 /* merge_units */
extern void cSkaSystem_Transition_ctor_void(void*);
#endif /* merge_units */
#define cSkaSystem_Transition_ctor_void(a0) ((void)cSkaSystem_Transition_ctor_void((SkaTransitionReq *)(a0))) /* merge_units */

extern void cSkaPlaybackGroupId_ctor_int(void*, int);
extern void cSkaAnimEndedMessage_ctor_void(void*);
extern void cSkaAnimCheckpoints_ctor_void(void*);
#if 0 /* merge_units */
extern void TransitionReq_Construct(void*, float);
#endif /* merge_units */
#define TransitionReq_Construct(a0, a1) ((void)TransitionReq_Construct((SkaTransitionReq *)(a0), (a1))) /* merge_units */

extern void __register_global_object(void*, void*, void*);
extern void func_00397400(void);
#pragma opt_propagation off
F6Sel* cSkaRequestStream_GetLatestRequest(F6Ctl* c)
{
    if (c->n44) {
        return std_deque_deleter_common_cSkaSystem_Request_back_void_2(c->a30);
    }
    if (c->n2C) {
        return std_deque_deleter_common_cSkaSystem_Request_back_void_2(c->a18);
    }
    if (!D_00542B70) {
        F6Sel* s = &D_00542B90;
        D_00542B90.b0 = 0;
        D_00542B90.b1 = 0;
        D_00542B90.i4 = 0;
        cSkaSystem_Transition_ctor_void(D_00542B90.req);
        cSkaPlaybackGroupId_ctor_int(D_00542B90.x1C, -1);
        cSkaAnimEndedMessage_ctor_void(D_00542B90.ev1);
        cSkaAnimEndedMessage_ctor_void(D_00542B90.ev2);
        cSkaAnimCheckpoints_ctor_void(s->x94);
        s->fE0 = -1.0f;
        s->iE4 = 0;
        TransitionReq_Construct(s->trans, 0.0f);
        __register_global_object(s, func_00397400, D_00542B78);
        D_00542B70 = 1;
    }
    return &D_00542B90;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD3F0(void) {}
#undef std_deque_deleter_common_cSkaSystem_Request_back_void_2 /* merge_units */
#undef cSkaSystem_Transition_ctor_void /* merge_units */
#undef TransitionReq_Construct /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AD3F0 */

/* merge_units: begin func_003AD500 */
#pragma push /* merge_units */
typedef struct { float v[5]; } D5F5;
typedef struct { float v[4]; } D5F4;
typedef struct {
    unsigned char b0;
    unsigned char b1;
    char pad2[2];
    int i4;
    D5F5 req;
    char x1C[8];
    char ev1[0x38];
    char ev2[0x38];
    char x94[0x4C];
    float fE0;
    int iE4;
    char trans[0x10];
} D5Sel;
extern D5F5* cSkaSystem_Transition_ctor_cSkaSystemTransitionR(D5F5* dst, D5F5* src);
extern void cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(void* dst, void* src);
extern void cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(void* dst, void* src);
extern void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* dst, void* src);
#if 0 /* merge_units */
extern void TransitionReq_Construct(void* self, float t);
#endif /* merge_units */
#define TransitionReq_Construct(a0, a1) ((void)TransitionReq_Construct((SkaTransitionReq *)(a0), (a1))) /* merge_units */


extern void AnimCtl_Install(void* c, D5Sel* r, unsigned char mode);
extern void func_00396910(void* p, int f);
extern void cSkaAnimCheckpoints_dtor(void* p, int f);
extern void cSkaAnimEndedMessage_dtor(void* p, int f);
#pragma opt_propagation off
void cSkaRequestStream_AddRequest(void* ctl, int id, unsigned char mode, D5F4* range, void* pair, void* m1, void* m2, void* x, float f0, float f1)
{
    D5Sel s;
    D5F5 t;
    D5Sel* p = &s;
    t.v[0] = range->v[0];
    t.v[1] = range->v[1];
    t.v[2] = range->v[2];
    t.v[3] = range->v[3];
    t.v[4] = 0;
    s.b0 = 0;
    s.b1 = 0;
    s.i4 = id;
    cSkaSystem_Transition_ctor_cSkaSystemTransitionR(&s.req, &t);
    cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(s.x1C, pair);
    cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(s.ev1, m1);
    cSkaAnimEndedMessage_ctor_cSkaAnimEndedMessageR(s.ev2, m2);
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(p->x94, x);
    p->fE0 = f0;
    p->iE4 = 0;
    TransitionReq_Construct(p->trans, f1);
    AnimCtl_Install(ctl, &s, mode);
    func_00396910(s.trans, -1);
    cSkaAnimCheckpoints_dtor(s.x94, -1);
    cSkaAnimEndedMessage_dtor(s.ev2, -1);
    cSkaAnimEndedMessage_dtor(s.ev1, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD500(void) {}
#undef TransitionReq_Construct /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AD500 */
