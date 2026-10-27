/*
 * Libs/SFOLib/Source/system: 1 file, 003CAD70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CAD70 */
#pragma push /* merge_units */
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
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
ListIter std_list_deleter_voidPtr_end_void(void* l);            /* list end */
void cLListIterator_cSystemPtr_ctor(ListIter* out, const ListIter& in);
ListIter std_list_cSystemPtr_begin(void* l);            /* list begin */
void std_list_cSystemPtr_generic_iterator_ctor(ListIter* out, const ListIter& in);
void std_list_cSystemPtr_dtor(void* p, int f);         /* object list dtor */
void operator_delete(void* p);
}
struct EndIter : ListIter { EndIter(const ListIter& t) { std_list_cSystemPtr_generic_iterator_ctor(this, t); } };
struct BeginIter : ListIter { BeginIter(const ListIter& t) { cLListIterator_cSystemPtr_ctor(this, t); } };
static inline EndIter ListEnd0(void* l) { return EndIter(std_list_deleter_voidPtr_end_void(l)); }
static inline BeginIter ListBegin0(void* l) { return BeginIter(std_list_cSystemPtr_begin(l)); }
static inline BeginIter ListBegin1(void* l) { return ListBegin0(l); }
static inline BeginIter ListBegin(void* l) { return ListBegin1(l); }
static inline EndIter ListEnd(void* l) { return ListEnd0(l); }

static inline void FreeItem(ListItem* o, int line) { AllocGuard g; o->dtor(-1); cMemMan_Deallocate(0, o, D_004BD1A8, line); }
static inline void ReceiverBuf_Dtor(ReceiverBuf* s) { if (s) { void* b = s->data; if (b) { AllocGuard g; cMemMan_Deallocate(0, b, "system.hh", 0x34); } } }
static inline void Receiver_DtorInline(Receiver* self)
{
    if (self) {
        self->vtable = D_004DFDE0;
        self->magic = 0;
        self->id = RECEIVER_DEAD_ID;
        ReceiverBuf* p = self->buf;
        if (p) { AllocGuard g; ReceiverBuf_Dtor(p); cMemMan_Deallocate(0, p, D_004BD1A8, 0x54); }
    }
}

static inline ListNode* ListEndNode(void* l) { return ListEnd(l).n; }
extern "C" ListReceiver* cSystemContainer_dtor(ListReceiver* self, short f)
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
        if (self->list) std_list_cSystemPtr_dtor(self->list, 0);
        Receiver_DtorInline(&self->base);
        if (f > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003CAD70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAD70 */
