#include "types.h"
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

extern char D_00542B68[];
extern void* const D_004DFBD0[8];
extern void Event_Construct(UtMsg* m, void* type);
extern void Event_Send(void* m, int target, int immediate);
extern void cMessage_dtor(UtMsg* m, int flags);
extern UtSlot* func_003AC4A0(UtArr* a, int index);
extern UtSlot* Array_GetLast(UtArr* a);
extern UtReq* func_003AC450(UtArr* a);
extern int func_003AC530(UtSlot* s, UtRange* r);
extern void func_003AB970(float w, UtCtl* c, UtReq* r, int stop);
extern void func_003B87A0(UtArr* a);

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
            if (func_003AC4A0(&c->arr, i)->weight == 1.0f) {
                found = i;
                break;
            }
        }
        if (found != -1) {
            for (j = 0; j < found; j++) {
                if (j == 0 && n == 2 && func_003AC4A0(&c->arr, 1)->weight == 1.0f) {
                    s = func_003AC4A0(&c->arr, j);
                    UtMsgSend(&s->msg, 4, t);
                    ns = func_003AC4A0(&c->arr, j);
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
                func_003B87A0(&c->arr);
            }
        }
    } else if (c->queue.count > 0) {

        e = Array_GetLast(&c->arr);
        r = func_003AC450(&c->queue);
        if (func_003AC530(e, &r->range)) {
            e->done = 1;
            func_003AB970(0.0f, c, r, 0);
            func_003B87A0(&c->queue);
        }
    } else if (c->hold) {
        e = Array_GetLast(&c->arr);
        if (func_003AC530(e, &c->range)) {
            UtNotifySend(&e->notify, 2, 1);
        }
    }
}
