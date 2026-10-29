#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "alloc_guard.h"

struct cTremorObj;
struct TNode;
struct DIt { TNode* p; };
struct LIt : DIt {};
union UBlk { TNode* p; int i; };
struct cLListIterator : LIt { cLListIterator() {} cLListIterator(const LIt& g) { p = g.p; } void Set(const cLListIterator& o) { cLListIterator t; cLListIterator* pt = &t; *(UBlk*)this = *(UBlk*)&o; } cLListIterator& operator=(const cLListIterator& o) { Set(o); return *this; } };
struct TNode { TNode* prev; TNode* next; cTremorObj* data; };
struct cLList { int a, b, c; };
struct cTremorManager { cLList mTremors; };

extern "C" {
extern char D_004A8EF0[];
void std_list_deleter_voidPtr_begin_void(DIt* out, cLList* l);
LIt* std_list_cTremorObjPtr_generic_iterator_ctor(LIt* d, DIt* s);
void std_list_cTremorObjPtr_end(LIt* out, cLList* l);
cLListIterator* cLListIterator_cTremorObjPtr_ctor(cLListIterator* d, LIt* s);
DIt* std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(LIt* d, cLListIterator* s);
void std_list_cTremorObjPtr_generic_iterator_opCast(DIt* out, LIt* s);
void std_list_deleter_voidPtr_erase_listdeleter(DIt* out, cLList* l, DIt* pos);
void cMemMan_Deallocate(int, void*, char*, int);
void func_00135C10(void*, int);
void operator_delete(void*);
}

static inline void Free(void* p) { AllocGuard g; cMemMan_Deallocate(0, p, D_004A8EF0, 0x31); }
/* delete of a cTremorObj: class operator delete wrapping the allocator lock */
static inline void Free1(void* p) { Free(p); }

static inline void Begin3(cLList* l, LIt* b) { DIt a; std_list_deleter_voidPtr_begin_void(&a, l); std_list_cTremorObjPtr_generic_iterator_ctor(b, &a); }
static inline void Begin2(cLList* l, LIt* b) { Begin3(l, b); }
static inline void Begin1(cLList* l, cLListIterator* out) { LIt b; Begin2(l, &b); out->p = b.p; }
static inline void Begin0(cLList* l, cLListIterator* out) { Begin1(l, out); }
static inline void End4(cLList* l, cLListIterator* f);
static inline void End3(cLList* l, cLListIterator* f) { End4(l, f); }
static inline void End4(cLList* l, cLListIterator* f) { LIt e; std_list_cTremorObjPtr_end(&e, l); cLListIterator_cTremorObjPtr_ctor(f, &e); }
static inline void End2(cLList* l, cLListIterator* f) { End3(l, f); }
static inline void Erase3(cLList* l, LIt* c, LIt* g) { DIt r; DIt d; LIt* pc = c; std_list_cTremorObjPtr_generic_iterator_opCast(&d, pc); std_list_deleter_voidPtr_erase_listdeleter(&r, l, &d); std_list_cTremorObjPtr_generic_iterator_ctor(g, &r); }
static inline cLListIterator Erase0(cLList* l, cLListIterator* cur);
static inline cLListIterator Erase1(cLList* l, cLListIterator* cur) { return Erase0(l, cur); }
static inline cLListIterator Erase0(cLList* l, cLListIterator* cur) { LIt g; LIt c; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&c, cur); Erase3(l, &c, &g); return cLListIterator(g); }
static inline bool NotEnd(cLList* l, cLListIterator& c) { cLListIterator f; End2(l, &f); return c.p != f.p; }

extern "C" cTremorManager* cTremorManager_dtor(cTremorManager* self, short flag)
{
    if (self) {
        cLListIterator curr;
        cTremorObj* obj;
        for (Begin0(&self->mTremors, &curr); NotEnd(&self->mTremors, curr); ) {
            obj = curr.p->data;
            curr = Erase1(&self->mTremors, &curr);
            Free1(obj);
        }
        if (self) func_00135C10(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}


