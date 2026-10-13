/*
 * ListReceiver destructor: deletes every object held in the list, destroys
 * the list, then runs the Receiver base destructor (inlined).
 */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "system_types.h"
#pragma inline_depth(10)

struct ListItem { virtual void dtor(int f); };
typedef struct ListNode { struct ListNode* prev; struct ListNode* next; ListItem* val; } ListNode;
struct ListIter { ListNode* n; };
extern "C" {
extern char D_004BD1A8[];                   /* "system.cc" */
extern char D_004DFDA0[];                   /* ListReceiver vtable */
extern char D_004DFDE0[];                   /* Receiver vtable */
void Mem_Free(int pool, void* p, char* file, int line);
ListIter func_0013B160(void* l);            /* list end */
void func_003CAB20(ListIter* out, const ListIter& in);
ListIter func_003CAB30(void* l);            /* list begin */
void func_003CAB40(ListIter* out, const ListIter& in);
void ReceiverList_Dtor(void* p, int f);         /* object list dtor */
void operator_delete(void* p);
}
struct EndIter : ListIter { EndIter(const ListIter& t) { func_003CAB40(this, t); } };
struct BeginIter : ListIter { BeginIter(const ListIter& t) { func_003CAB20(this, t); } };
static inline EndIter ListEnd0(void* l) { return EndIter(func_0013B160(l)); }
static inline BeginIter ListBegin0(void* l) { return BeginIter(func_003CAB30(l)); }
static inline BeginIter ListBegin1(void* l) { return ListBegin0(l); }
static inline BeginIter ListBegin(void* l) { return ListBegin1(l); }
static inline EndIter ListEnd(void* l) { return ListEnd0(l); }

static inline void FreeItem(ListItem* o, int line) { AllocGuard g; o->dtor(-1); Mem_Free(0, o, D_004BD1A8, line); }
static inline void ReceiverBuf_Dtor(ReceiverBuf* s) { if (s) { void* b = s->data; if (b) { AllocGuard g; Mem_Free(0, b, "system.hh", 0x34); } } }
static inline void Receiver_DtorInline(Receiver* self)
{
    if (self) {
        self->vtable = D_004DFDE0;
        self->magic = 0;
        self->id = RECEIVER_DEAD_ID;
        ReceiverBuf* p = self->buf;
        if (p) { AllocGuard g; ReceiverBuf_Dtor(p); Mem_Free(0, p, D_004BD1A8, 0x54); }
    }
}

static inline ListNode* ListEndNode(void* l) { return ListEnd(l).n; }
extern "C" ListReceiver* ListReceiver_Dtor(ListReceiver* self, short f)
{
    if (self) {
        self->base.vtable = D_004DFDA0;
        {
            ListItem* o;
            ListNode* e = ListEndNode(self->list);
            ListIter it = ListBegin(self->list);
            while (it.n != e) {
                o = it.n->val; FreeItem(o, 0x9E);
                it.n = it.n->next;
            }
        }
        if (self->list) ReceiverList_Dtor(self->list, 0);
        Receiver_DtorInline(&self->base);
        if (f > 0) operator_delete(self);
    }
    return self;
}