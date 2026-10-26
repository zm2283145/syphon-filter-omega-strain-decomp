/*
 * main/ska: range (6 files, 003ABB10-003AC100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ABB10 */
#pragma push /* merge_units */
#include "types.h"
typedef struct AcPair { int token; int target; } AcPair;
typedef struct AcHost { unsigned char active; char p1[3]; AcPair pairs[6]; } AcHost;
void MotionNotify_SendSlot(AcHost* h, int idx, unsigned char clear); /* gsynth: defined below */typedef struct { char pad[0x28]; unsigned char kind; char pad29[3]; void* target; unsigned char sent; char pad31[3]; float value; } D6AnimMsg;
void MotionMsg_Send(D6AnimMsg* m, unsigned char kind, float value); /* gsynth: defined below */
/* cSkaRequestStream_SignalInterruptionOfCurrentlyPlayingItems: walks the active motion deque, resetting both message slots and the notify slot of
 * every 0xF8-byte record (MotionGraph_ClearActive without the final deque clear). Same iterator idiom
 * as src/main/ska/MotionGraph_ClearActive.c. */
#pragma cplusplus on
#include "alloc_guard.h" /* ALLOC_GUARD_DTOR: discard the out-of-line copy of the empty dtor */
struct Ring { int** cur; int** begin; int** x8; int** end; };
struct DqIt {
    Ring ring; char* elem; char* bend;
    DqIt() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~DqIt() {}
    DqIt& operator=(const DqIt& o) {
        ring.cur = o.ring.cur; ring.begin = o.ring.begin; ring.x8 = o.ring.x8; ring.end = o.ring.end;
        elem = o.elem; bend = o.bend;
        return *this;
    }
    bool Ne(char* p) const { return !(elem == p); }
    DqIt& operator++() {
        if ((elem += 0xF8) == bend) {
            if (++ring.cur == ring.end) ring.cur = ring.begin;
            elem = (char*)*ring.cur;
            bend = elem + 0x7C0;
        }
        return *this;
    }
};
struct BlockArray { int cap; int size; int start; int** data; int first; int count; };
struct MGraph { char pad[0x18]; BlockArray arr; };
extern "C" {
void std_deque_deleter_common_cSkaSystem_Request_make_iterator(DqIt* out, BlockArray* a, int n);
#if 0 /* merge_units */
void MotionMsg_Send(void* m, unsigned char kind, float value);
#endif /* merge_units */
#define MotionMsg_Send(a0, a1, a2) (MotionMsg_Send((D6AnimMsg *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void MotionNotify_SendSlot(void* h, int idx, unsigned char clear);
#endif /* merge_units */
#define MotionNotify_SendSlot(a0, a1, a2) (MotionNotify_SendSlot((AcHost *)(a0), (a1), (a2))) /* merge_units */

void MotionArray_Clear(BlockArray* a);
}
extern "C" void cSkaRequestStream_SignalInterruptionOfCurrentlyPlayingItems(MGraph* g)
{
    DqIt it;
    DqIt b;
    char* p;
    char* e;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&b, &g->arr, 0);
    it = b;
    {
        DqIt r;
        std_deque_deleter_common_cSkaSystem_Request_make_iterator(&r, &g->arr, g->arr.count);
        e = r.elem;
    }
    while (it.Ne(e)) {
        p = it.elem;
        MotionMsg_Send(p + 0x24, 5, 0.0f);
        MotionMsg_Send(p + 0x5C, 5, 0.0f);
        MotionNotify_SendSlot(p + 0x94, 6, 0);
        ++it;
    }
}
#undef MotionMsg_Send /* merge_units */
#undef MotionNotify_SendSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ABB10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ABB10 */

/* merge_units: begin func_003ABC80 */
#pragma push /* merge_units */
typedef struct AcMsg { void* vt; char p4[0x20]; int token; char p28[8]; } AcMsg;
extern char D_00542B68[];
extern char D_004DFBD0[];
extern void Event_Construct(void*, void*);
extern void Event_Send(void*, int, int);
extern void cMessage_dtor(void*, int);
static inline int AcPair_Valid(AcPair* p) { return p->target != 0 && ~p->token != 0; }
#pragma opt_common_subs off
void MotionNotify_SendSlot(AcHost* h, int idx, unsigned char clear)
{
    AcPair* p;
    if (h->active) {
        p = &((AcPair*)((char*)h + 4))[(signed char)idx];
        if (AcPair_Valid(p)) {
            AcMsg msg;
            int tok = p->token;
            Event_Construct(&msg, D_00542B68);
            msg.token = tok;
            msg.vt = D_004DFBD0;
            Event_Send(&msg, p->target, 1);
            msg.vt = D_004DFBD0;
            cMessage_dtor(&msg, 0);
            if ((signed char)idx >= 5) h->active = 0;
            if (clear) { p->token = -1; p->target = 0; }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ABC80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ABC80 */

/* merge_units: begin func_003ABD80 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void Event_Send(void* msg, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((a0), (int)(a1), (a2))) /* merge_units */


void MotionMsg_Send(D6AnimMsg* m, unsigned char kind, float value)
{
    if (m->target && !m->sent) {
        m->kind = kind;
        m->value = value;
        Event_Send(m, m->target, 1);
    }
    if (kind == 4 || kind == 5) {
        m->sent = 1;
    }
}
#undef Event_Send /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ABD80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ABD80 */

/* merge_units: begin func_003ABE00 */
#pragma push /* merge_units */
/* MotionGraph_ClearActive: walks the active motion deque, resetting both message slots and the notify slot of
 * every 0xF8-byte record, then clears the deque. Hand-matched (fam1).
 * The empty destructor keeps the iterator in memory (fields reached through s-register addresses, as in retail);
 * the field-wise operator= gives the word-by-word iterator copy. */
#pragma cplusplus on

extern "C" {
#if 0 /* merge_units */
void MotionMsg_Send(void* m, unsigned char kind, float value);
#endif /* merge_units */
#define MotionMsg_Send(a0, a1, a2) (MotionMsg_Send((D6AnimMsg *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void MotionNotify_SendSlot(void* h, int idx, unsigned char clear);
#endif /* merge_units */
#define MotionNotify_SendSlot(a0, a1, a2) (MotionNotify_SendSlot((AcHost *)(a0), (a1), (a2))) /* merge_units */

}
extern "C" void MotionGraph_ClearActive(MGraph* g)
{
    DqIt it;
    DqIt b;
    char* p;
    char* e;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&b, &g->arr, 0);
    it = b;
    {
        DqIt r;
        std_deque_deleter_common_cSkaSystem_Request_make_iterator(&r, &g->arr, g->arr.count);
        e = r.elem;
    }
    while (it.Ne(e)) {
        p = it.elem;
        MotionMsg_Send(p + 0x24, 5, 0.0f);
        MotionMsg_Send(p + 0x5C, 5, 0.0f);
        MotionNotify_SendSlot(p + 0x94, 6, 0);
        ++it;
    }
    MotionArray_Clear(&g->arr);
}
#undef MotionMsg_Send /* merge_units */
#undef MotionNotify_SendSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ABE00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ABE00 */

/* merge_units: begin func_003ABF80 */
#pragma push /* merge_units */
/* MotionGraph_ClearQueued: MotionGraph_ClearActive (src/main/ska/MotionGraph_ClearActive.c) for a graph whose active deque
 * sits at +0x30: resets both message slots and the notify slot of every 0xF8-byte record, then clears the deque. */
#pragma cplusplus on

struct MGraph_003ABF80 { char pad[0x30]; BlockArray arr; };
extern "C" {
#if 0 /* merge_units */
void MotionMsg_Send(void* m, unsigned char kind, float value);
#endif /* merge_units */
#define MotionMsg_Send(a0, a1, a2) (MotionMsg_Send((D6AnimMsg *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void MotionNotify_SendSlot(void* h, int idx, unsigned char clear);
#endif /* merge_units */
#define MotionNotify_SendSlot(a0, a1, a2) (MotionNotify_SendSlot((AcHost *)(a0), (a1), (a2))) /* merge_units */

}
extern "C" void MotionGraph_ClearQueued(MGraph_003ABF80* g)
{
    DqIt it;
    DqIt b;
    char* p;
    char* e;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&b, &g->arr, 0);
    it = b;
    {
        DqIt r;
        std_deque_deleter_common_cSkaSystem_Request_make_iterator(&r, &g->arr, g->arr.count);
        e = r.elem;
    }
    while (it.Ne(e)) {
        p = it.elem;
        MotionMsg_Send(p + 0x24, 5, 0.0f);
        MotionMsg_Send(p + 0x5C, 5, 0.0f);
        MotionNotify_SendSlot(p + 0x94, 6, 0);
        ++it;
    }
    MotionArray_Clear(&g->arr);
}
#undef MotionMsg_Send /* merge_units */
#undef MotionNotify_SendSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ABF80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ABF80 */

/* merge_units: begin func_003AC100 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x20]; int value; } UtMsg;
typedef struct { int id; int target; } UtLink;
typedef struct { unsigned char active; UtLink links[6]; } UtNotify;
typedef struct { char pad[0x28]; unsigned char kind; char pad29[3]; int target; unsigned char sent; char pad31[3]; float value; } UtAnimMsg;
typedef struct {
    unsigned char active; unsigned char done; char pad2[0x16]; float weight; char pad1C[8];
    UtAnimMsg msg; char pad5C[0x38]; UtNotify notify;
} UtSlot;
typedef struct { int cap; int size; int start; int data; int first; int count; } UtArr;
typedef struct { int a; int b; } UtRange;
typedef struct { char pad0[5]; unsigned char hold; char pad6[2]; UtRange range; char pad10[8]; UtArr arr; UtArr queue; } UtCtl;
typedef struct { char pad[8]; UtRange range; } UtReq;
#if 0 /* merge_units */
extern void* const D_004DFBD0[8];
#endif /* merge_units */
#define D_004DFBD0 ((void * const*)&D_004DFBD0) /* merge_units */

#if 0 /* merge_units */
extern void Event_Construct(UtMsg* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(void* m, int target, int immediate);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(UtMsg* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern UtSlot* std_deque_cSkaSystem_Request_opIndex(UtArr* a, int index);
extern UtSlot* Array_GetLast(UtArr* a);
extern UtReq* std_deque_deleter_common_cSkaSystem_Request_front(UtArr* a);
extern int IsReadyForNextAnim(UtSlot* s, UtRange* r);
extern void MotionGraph_Install(float w, UtCtl* c, UtReq* r, int stop);
extern void std_deque_deleter_cSkaSystem_Request_pop_front(UtArr* a);

static inline void UtMsgSend(UtAnimMsg* m, unsigned char kind, float value)
{
    if (m->target && !m->sent) {
        m->kind = kind;
        m->value = value;
        Event_Send(m, m->target, 1);
    }
    if (kind == 4 || kind == 5) {
        m->sent = 1;
    }
}
static inline int UtLinkValid(UtLink* p) { return p->target != 0 && ~p->id != 0; }
static inline void UtNotifySend(UtNotify* h, int idx, unsigned char clear)
{
    UtLink* p;
    if (h->active) {
        p = &h->links[(signed char)idx];
        if (UtLinkValid(p)) {
            UtMsg msg;
            int tok = p->id;
            Event_Construct(&msg, D_00542B68);
            msg.vtable = (void*)D_004DFBD0;
            msg.value = tok;
            Event_Send(&msg, p->target, 1);
            msg.vtable = (void*)D_004DFBD0;
            cMessage_dtor(&msg, 0);
            if ((signed char)idx >= 5) h->active = 0;
            if (clear) { p->id = -1; p->target = 0; }
        }
    }
}

void AnimCtl_UpdateTransitions(UtCtl* c, float t)
{
    UtSlot* e;
    int found;
    int j;
    int tok;
    UtSlot* ns;
    UtLink* p;
    int i;
    int n;
    UtReq* r;
    UtSlot* s;
    n = c->arr.count;
    if (n > 1) {
        found = -1;
        for (i = n - 1; i > 0; i--) {
            if (std_deque_cSkaSystem_Request_opIndex(&c->arr, i)->weight == 1.0f) {
                found = i;
                break;
            }
        }
        if (found != -1) {
            for (j = 0; j < found; j++) {
                if (j == 0 && n == 2 && std_deque_cSkaSystem_Request_opIndex(&c->arr, 1)->weight == 1.0f) {
                    s = std_deque_cSkaSystem_Request_opIndex(&c->arr, j);
                    UtMsgSend(&s->msg, 4, t);
                    ns = std_deque_cSkaSystem_Request_opIndex(&c->arr, j);
                    if (ns->notify.active) {
                        p = &ns->notify.links[5];
                        if (UtLinkValid(p)) {
                            UtMsg msg;
                            tok = p->id;
                            Event_Construct(&msg, D_00542B68);
                            msg.vtable = (void*)D_004DFBD0;
                            msg.value = tok;
                            Event_Send(&msg, p->target, 1);
                            msg.vtable = (void*)D_004DFBD0;
                            cMessage_dtor(&msg, 0);
                            ns->notify.active = 0;
                        }
                    }
                }
            }
            for (i = 0; i < found; i++) {
                std_deque_deleter_cSkaSystem_Request_pop_front(&c->arr);
            }
        }
    } else if (c->queue.count > 0) {

        e = Array_GetLast(&c->arr);
        r = std_deque_deleter_common_cSkaSystem_Request_front(&c->queue);
        if (IsReadyForNextAnim(e, &r->range)) {
            e->done = 1;
            MotionGraph_Install(0.0f, c, r, 0);
            std_deque_deleter_cSkaSystem_Request_pop_front(&c->queue);
        }
    } else if (c->hold) {
        e = Array_GetLast(&c->arr);
        if (IsReadyForNextAnim(e, &c->range)) {
            UtNotifySend(&e->notify, 2, 1);
        }
    }
}
#undef D_004DFBD0 /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC100 */
