/*
 * main/ska: range (2 files, 003AC6E0-003ACD30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_003AC6E0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" void func_003ACD30(void* list, int flag); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on

struct Slot;
typedef struct { void* vtable; char pad[0x20]; int value; char pad2[8]; } NMsg;
typedef struct { int id; int target; } NLink;
typedef struct { unsigned char active; char pad[3]; NLink links[6]; } NNotify;
typedef struct { char pad[0x28]; unsigned char kind; char pad29[3]; int target; unsigned char sent; char pad31[3]; float value; } AMsg;
struct Slot {
    unsigned char active; unsigned char done; char pad2[0x1A]; unsigned char IsActive() const { return active; } unsigned char IsDone() const { return done; } int x1C[2];
    AMsg msg; AMsg msg2; NNotify notify; char padC8[0x18]; float cur; float end; int grp;
    char padEC[0xC];
};
struct DqIt {
    Slot** cur; Slot** begin; Slot** x8; Slot** end; Slot* elem; Slot* bend;
    DqIt() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~DqIt() {}
    DqIt& operator=(const DqIt& o) {
        cur = o.cur; begin = o.begin; x8 = o.x8; end = o.end; elem = o.elem; bend = o.bend;
        return *this;
    }
    Slot& operator*() const { return *elem; }
    DqIt& operator--() {
        if (bend - elem == 8) {
            if (cur == begin) cur = end;
            --cur;
            elem = bend = *cur + 8;
        }
        --elem;
        return *this;
    }
};

struct Dq {
    DqIt fin;
    Slot& back() { DqIt tmp; tmp = fin; --tmp; return *tmp; }
    void pop_back() { --fin; }
};

extern "C" {
extern char D_00542B68[];
extern char D_004DFBD0[];
void cMessage_ctor_cMessageNameR(NMsg* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, int target, int immediate);
void cMessage_dtor(NMsg* m, int flags);
int cDequeue_cSkaSystem_Request_ReverseIterator_opEq(void* a, void* b);
void cSkaSystem_Request_Process(float w, Slot* s, unsigned char* a, float* nw, unsigned char* b, void* p, unsigned char* f, float t);
int cSkaAnimCheckpoints_HasScheduledEvents(NNotify* n);
int cSkaPlaybackGroupId_IsValid(int* p);
int func_003AD1E0(int* g, int* p);
void cSkaAnimCheckpoints_TriggerScheduledEvents(NNotify* n, int x);
int cSkaSystem_Request_PlaybackGroupId(Slot* s);
bool AnimGroup_IsComplete(int* g, int x);
#if 0 /* merge_units */
void func_003ACD30(int* g, unsigned char f);
#endif /* merge_units */
#define func_003ACD30(a0, a1) (func_003ACD30((void *)(a0), (int)(a1))) /* merge_units */

}

static inline void MsgSend(AMsg* m, unsigned char kind, float value)
{
    if (m->target && !m->sent) {
        m->kind = kind;
        m->value = value;
        QueueMessage_cMessageR_cSystemP_int(m, m->target, 1);
    }
    if (kind == 4 || kind == 5) {
        m->sent = 1;
    }
}
static inline bool LinkValid(NLink* p) { return p->target != 0 && ~p->id != 0; }
static inline void NotifySend(NNotify* h, int idx, unsigned char clear)
{
    NLink* p;
    if (h->active) {
        p = &h->links[(signed char)idx];
        if (LinkValid(p)) {
            NMsg msg;
            int tok = p->id;
            cMessage_ctor_cMessageNameR(&msg, D_00542B68);
            msg.value = tok;
            msg.vtable = D_004DFBD0;
            QueueMessage_cMessageR_cSystemP_int(&msg, p->target, 1);
            msg.vtable = D_004DFBD0;
            cMessage_dtor(&msg, 0);
            if ((signed char)idx >= 5) h->active = 0;
            if (clear) { p->id = -1; p->target = 0; }
        }
    }
}
static inline bool Differs(void* q, void* r) { return !cDequeue_cSkaSystem_Request_ReverseIterator_opEq(q, r); }
static inline bool Slot_Done(Slot* s)
{
    if (s->cur != -1.0f) return s->cur == s->end;
    return AnimGroup_IsComplete(&s->grp, cSkaSystem_Request_PlaybackGroupId(s));
}

extern "C" void cSkaRequestStream_ProcessCurrentlyPlayingItems(void* a0, void* a1, Dq* q, void* req, unsigned char flag, float w, float t)
{
    if (!(w <= 0.0f) && Differs(q, req)) {
        Slot* s;
        unsigned char started;
        unsigned char wasDone;
        unsigned char nflag;
        float nw;
        unsigned char ended;
        s = &q->back();
        q->pop_back();
        started = s->IsActive();
        wasDone = s->IsDone();
        cSkaSystem_Request_Process(w, s, &nflag, &nw, &ended, a1, &flag, t);
        s->active = 0;
        s->done = 0;
        cSkaRequestStream_ProcessCurrentlyPlayingItems(a0, a1, q, req, nflag, nw, t);
        if (cSkaAnimCheckpoints_HasScheduledEvents(&s->notify) && cSkaPlaybackGroupId_IsValid(s->x1C)) {
            cSkaAnimCheckpoints_TriggerScheduledEvents(&s->notify, func_003AD1E0(&s->grp, s->x1C));
        }
        if (started) {
            MsgSend(&s->msg, 1, t);
            MsgSend(&s->msg2, 1, t);
            NotifySend(&s->notify, 0, 0);
        }
        if (ended) {
            MsgSend(&s->msg, 2, t);
            MsgSend(&s->msg2, 4, t);
            NotifySend(&s->notify, 1, 0);
        }
        if (wasDone) {
            MsgSend(&s->msg, 3, t);
            NotifySend(&s->notify, 3, 0);
        }
        if (Slot_Done(s)) {
            MsgSend(&s->msg, 4, t);
            NotifySend(&s->notify, 4, 1);
        }
        func_003ACD30(&s->grp, flag);
    }
}
#undef func_003ACD30 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC6E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC6E0 */

/* merge_units: begin func_003ACD30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Set the flag byte of every node's target in a list. */
typedef struct { unsigned char pad[0x33]; unsigned char flag; } Tgt_3ACD30;
typedef struct Node_3ACD30 { int pad0; struct Node_3ACD30* next; Tgt_3ACD30* target; } Node_3ACD30;
typedef struct { Node_3ACD30* p; } It_3ACD30;
typedef struct { int w[1]; } Raw_3ACD30;

extern "C" {
void func_003ACDC0(Raw_3ACD30* out, void* list);
void cLListIterator_cSkaPlaybackGroupPtr_ctor(It_3ACD30* out, Raw_3ACD30* raw);
void std_list_cSkaPlaybackGroupPtr_end(Raw_3ACD30* out, void* list);
}

extern "C" void func_003ACD30(void* list, int flag)
{
    It_3ACD30 first;
    It_3ACD30 last;
    Raw_3ACD30 rawFirst;
    Raw_3ACD30 rawLast;
    Node_3ACD30* n;
    Node_3ACD30* end;
    func_003ACDC0(&rawFirst, list);
    cLListIterator_cSkaPlaybackGroupPtr_ctor(&first, &rawFirst);
    n = first.p;
    std_list_cSkaPlaybackGroupPtr_end(&rawLast, list);
    cLListIterator_cSkaPlaybackGroupPtr_ctor(&last, &rawLast);
    end = last.p;
    unsigned char f = flag;
    for (; n != end; n = n->next)
        n->target->flag = f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ACD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ACD30 */
