#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

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
void Event_Construct(NMsg* m, void* type);
void Event_Send(void* m, int target, int immediate);
void cMessage_dtor(NMsg* m, int flags);
int TransitionReq_SameKey(void* a, void* b);
void AnimBlend_Evaluate(float w, Slot* s, unsigned char* a, float* nw, unsigned char* b, void* p, unsigned char* f, float t);
int func_003AD2F0(NNotify* n);
int func_003AD2C0(int* p);
int func_003AD1E0(int* g, int* p);
void func_003ACEA0(NNotify* n, int x);
int func_003AC6D0(Slot* s);
bool AnimGroup_IsComplete(int* g, int x);
void func_003ACD30(int* g, unsigned char f);
}

static inline void MsgSend(AMsg* m, unsigned char kind, float value)
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
static inline bool LinkValid(NLink* p) { return p->target != 0 && ~p->id != 0; }
static inline void NotifySend(NNotify* h, int idx, unsigned char clear)
{
    NLink* p;
    if (h->active) {
        p = &h->links[(signed char)idx];
        if (LinkValid(p)) {
            NMsg msg;
            int tok = p->id;
            Event_Construct(&msg, D_00542B68);
            msg.value = tok;
            msg.vtable = D_004DFBD0;
            Event_Send(&msg, p->target, 1);
            msg.vtable = D_004DFBD0;
            cMessage_dtor(&msg, 0);
            if ((signed char)idx >= 5) h->active = 0;
            if (clear) { p->id = -1; p->target = 0; }
        }
    }
}
static inline bool Differs(void* q, void* r) { return !TransitionReq_SameKey(q, r); }
static inline bool Slot_Done(Slot* s)
{
    if (s->cur != -1.0f) return s->cur == s->end;
    return AnimGroup_IsComplete(&s->grp, func_003AC6D0(s));
}

extern "C" void AnimCtl_Evaluate(void* a0, void* a1, Dq* q, void* req, unsigned char flag, float w, float t)
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
        AnimBlend_Evaluate(w, s, &nflag, &nw, &ended, a1, &flag, t);
        s->active = 0;
        s->done = 0;
        AnimCtl_Evaluate(a0, a1, q, req, nflag, nw, t);
        if (func_003AD2F0(&s->notify) && func_003AD2C0(s->x1C)) {
            func_003ACEA0(&s->notify, func_003AD1E0(&s->grp, s->x1C));
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












