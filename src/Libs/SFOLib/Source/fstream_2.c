/*
 * Libs/SFOLib/Source/fstream: 6 files, 003EB340-003EB8E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EB340 */
#pragma push /* merge_units */
#pragma enumsalwaysint off
enum RS_B3 { RS0, RS1, RS2, RS3, RS4, RS5, RS6, RSMAX = 0x7F };
#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct SubB3 { int n0; int n4; int n8; unsigned char bC; };
struct ReqB3 {
    int frame;
    RS_B3 state;
    char pad5[3];
    char* file;
    void (*cb)(SubB3*, int, int);
    int user;
};
struct LdrB3 { char pad[0xC]; ReqB3* cur; char pad10[4]; unsigned char b14; };
struct NodeB3 { NodeB3* prev; NodeB3* next; ReqB3* data; };
struct RawB3 { NodeB3* p; };
struct CmpB3 {};
struct PredB3 { CmpB3 cmp; ReqB3** pp; PredB3(const CmpB3& c, ReqB3** p) : cmp(c), pp(p) {} };

extern "C" {
extern char D_004BE010;
extern int D_00534CDC;
extern unsigned char D_00493990;
extern int g_FrameCounter;
void cMemMan_Deallocate(int a, void* p, char* file, int line);
void std_list_deleter_voidPtr_begin_void(RawB3*, LdrB3*);
void std_list_cFSDataPtr_generic_iterator_ctor(RawB3*, RawB3*);
void std_list_cFSDataPtr_end(RawB3*, LdrB3*);
void cLListIterator_cFSDataPtr_ctor(RawB3*, RawB3*);
void std_list_imp_voidPtr_remove_if(LdrB3*, PredB3);
void cFileStreamMan_FlushAllStreamData(LdrB3* ldr, int force);
int cFSData_StartStream(ReqB3* r);
int cFileMan_IsReadDone(char* f);
void std_list_cFSDataPtr_push_back(LdrB3* l, ReqB3** r);
}

static inline bool ReqCheckB3(ReqB3* r)
{
    unsigned char s = r->state;
    if (s == 3 || s == 6) return true;
    if (r->file) {
        int v = cFileMan_IsReadDone(r->file);
        if (v) {
            if (v == -1) r->state = RS4;
            else if (r->state != RS2) r->state = RS3;
            return true;
        }
    }
    return false;
}

static inline bool ReqReadyB3(ReqB3* r)
{
    bool b = D_00493990 == 1;
    if (b) b = ReqCheckB3(r);
    return b;
}

static inline bool LoaderIdleB3(ReqB3* r)
{
    bool b = r == 0;
    if (b) b = D_00493990 == 1;
    if (b) return true;
    return ReqReadyB3(r);
}

static inline SubB3* ReqSubB3(ReqB3* r) { return r->file ? (SubB3*)(r->file + 0x88) : 0; }
static inline int SubDataB3(SubB3* s) { return s->n8 ? s->n8 : s->n0; }

static inline void SubFreeB3(SubB3* s)
{
    void* p = (void*)s->n0;
    if (p) {
        {
            AllocGuard g;
            cMemMan_Deallocate(1, p, &D_004BE010, 0x56);
        }
        s->n0 = 0;
        s->n8 = 0;
        s->n4 = 0;
        s->bC = 0;
    }
}

static inline void BeginB3(RawB3* p, LdrB3* l) { RawB3 t; std_list_deleter_voidPtr_begin_void(&t, l); std_list_cFSDataPtr_generic_iterator_ctor(p, &t); }
static inline void EndB3(RawB3* p, LdrB3* l) { RawB3 t; std_list_cFSDataPtr_end(&t, l); cLListIterator_cFSDataPtr_ctor(p, &t); }
static inline void Begin2B3(RawB3* p, LdrB3* l) { BeginB3(p, l); }
static inline void End2B3(RawB3* p, LdrB3* l) { EndB3(p, l); }
static inline PredB3 MakePredB3(ReqB3** p) { CmpB3 c; return PredB3(c, p); }

extern "C" int cFileStreamMan_Process(LdrB3* ldr)
{
    RS_B3 st;
    RawB3 end;
    RawB3 end2;
    RawB3 it;
    RawB3 it2;
    ReqB3* r;
    NodeB3* n;
    if (!ldr->b14) ldr->b14 = 1;
    if (D_00534CDC == -1) return 0;
    cFileStreamMan_FlushAllStreamData(ldr, 0);
    if (!ldr->cur) {
        Begin2B3(&it, ldr);
        n = it.p;
        while (End2B3(&end, ldr), n != end.p) {
            r = n->data;
            if (!r->state && cFSData_StartStream(r)) {
                ldr->cur = r;
                D_00493990 = 1;
                break;
            }
            n = n->next;
        }
    } else if (LoaderIdleB3(ldr->cur)) {
        ReqB3* c = ldr->cur;
        st = c->state;
        if (st == RS2) {
            c->state = RS5;
            c->frame = g_FrameCounter;
        } else if (st == RS4) {
            c->state = RS0;
            SubFreeB3(ReqSubB3(c));
            std_list_imp_voidPtr_remove_if(ldr, MakePredB3(&ldr->cur));
            std_list_cFSDataPtr_push_back(ldr, &ldr->cur);
        } else if (st == RS1 || st == RS3) {
            SubB3* t = ReqSubB3(c);
            if (SubDataB3(t)) {
                t->bC = 1;
                c->state = RS3;
                c->cb(t, c->user, 1);
            }
        }
        ldr->cur = 0;
        D_00493990 = 0;
    }
    {
        int cnt = 0;
        Begin2B3(&it2, ldr);
        n = it2.p;
        while (End2B3(&end2, ldr), n != end2.p) {
            if (!n->data->state) cnt++;
            n = n->next;
        }
        return cnt;
    }
}
static inline void merge_flush_func_003EB340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB340 */

/* merge_units: begin func_003EB750 */
#pragma push /* merge_units */
#pragma cplusplus on

struct LNode { LNode* prev; LNode* next; void* data; };
struct LHead { LNode* prev; LNode* next; };
struct LSelf { int count; LHead header; int unkC; int unk10; };

extern "C" {
#if 0 /* merge_units */
void cMemMan_Deallocate(int, void*, char*, int);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */


void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int*, void*, LNode**, LNode**);
void cFSData_FreeStream(void*, int);
#if 0 /* merge_units */
void std_list_cFSDataPtr_begin(LNode** it, LSelf* self);
#endif /* merge_units */
void std_list_cFSDataPtr_begin(Iter* out, PtrVec* v); /* merge_units */
#define std_list_cFSDataPtr_begin(a0, a1) (std_list_cFSDataPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_advance_listR_int(LNode** it, int n);
#endif /* merge_units */
struct G7N; /* merge_units */
void std_advance_listR_int(G7N** pp, int n); /* merge_units */
#define std_advance_listR_int(a0, a1) (std_advance_listR_int((G7N * *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void** std_list_cFSDataPtr_generic_iterator_opMul(LNode** it);
#endif /* merge_units */
char* std_list_cFSDataPtr_generic_iterator_opMul(char** self); /* merge_units */
#define std_list_cFSDataPtr_generic_iterator_opMul(a0) ((void * *)std_list_cFSDataPtr_generic_iterator_opMul((char * *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char D_004BE010[];
#endif /* merge_units */
#define D_004BE010 ((char*)&D_004BE010) /* merge_units */


#if 0 /* merge_units */
extern char D_00493990;
#endif /* merge_units */
#define D_00493990 (*(char*)&D_00493990) /* merge_units */


}

static inline void* ListAt(LSelf* s, int n) {
    LNode* p = s->header.next;
    if (n >= 0) {
        while (n > 0) { p = p->next; n--; }
    } else {
        while (n < 0) { p = p->prev; n++; }
    }
    return p->data;
}
static inline void* At(LSelf* s, int i) {
    LNode* it;
    std_list_cFSDataPtr_begin(&it, s);
    std_advance_listR_int(&it, i);
    return *std_list_cFSDataPtr_generic_iterator_opMul(&it);
}

extern "C" void cFileStreamMan_Purge(LSelf* self) {
    int n = self->count;
    int i;
    for (i = 0; i < n; i++) {
        void* p;
        cFSData_FreeStream(ListAt(self, i), 0);
        p = At(self, i);
        {
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE010, 0x1B9);
        }
    }
    {
        int res;
        LNode* first;
        LNode* last;
        last = (LNode*)&self->header;
        first = self->header.next;
        std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&res, self, &first, &last);
    }
    self->unkC = 0;
    D_00493990 = 0;
    self->unk10 = 0;
}
#undef cMemMan_Deallocate /* merge_units */
#undef std_list_cFSDataPtr_begin /* merge_units */
#undef std_advance_listR_int /* merge_units */
#undef std_list_cFSDataPtr_generic_iterator_opMul /* merge_units */
#undef D_004BE010 /* merge_units */
#undef D_00493990 /* merge_units */
static inline void merge_flush_func_003EB750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB750 */

/* merge_units: begin func_003EB8E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */


/* List iterator dereference: address of the node payload at node +0x08. */
char* std_list_cFSDataPtr_generic_iterator_opMul(char** self) {
    return *self + 8;
}
static inline void merge_flush_func_003EB8E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB8E0 */

/* merge_units: begin func_003EB8F0 */
#pragma push /* merge_units */
typedef struct G7N { struct G7N* prev; struct G7N* next; } G7N;
void std_advance_listR_int(G7N** pp, int n)
{
    if (n >= 0) {
        while (n > 0) { *pp = (*pp)->next; n--; }
    } else {
        while (n < 0) { *pp = (*pp)->prev; n++; }
    }
}
static inline void merge_flush_func_003EB8F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB8F0 */

/* merge_units: begin func_003EB950 */
#pragma push /* merge_units */
/* begin() iterator of a pointer vector. */
void std_list_cFSDataPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003EB950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB950 */

/* merge_units: begin func_003EB960 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: own cleanup, then the base destructor. */
extern "C" void operator_delete(void* allocation);
#if 0 /* merge_units */
extern "C" void cFileStreamMan_Purge(void* self);
#endif /* merge_units */
#define cFileStreamMan_Purge(a0) (cFileStreamMan_Purge((LSelf *)(a0))) /* merge_units */

extern "C" void* std_list_cFSDataPtr_dtor(void* self, short deleteFlag);

extern "C" void* cFileStreamMan_dtor(void* self, short deleteFlag)
{
    if (self) {
        cFileStreamMan_Purge(self);
        if (self)
            std_list_cFSDataPtr_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef cFileStreamMan_Purge /* merge_units */
static inline void merge_flush_func_003EB960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB960 */
