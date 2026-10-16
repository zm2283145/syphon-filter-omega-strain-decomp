/*
 * main/gameFrontEnd: 9 files, 002CD9F0-002CE340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CD9F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_002CD9F0)
#pragma pop /* merge_units */
/* merge_units: end func_002CD9F0 */

/* merge_units: begin func_002CDAE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(func_002CDAE0)
#pragma pop /* merge_units */
/* merge_units: end func_002CDAE0 */

/* merge_units: begin func_002CDC20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(func_002CDC20)
#pragma pop /* merge_units */
/* merge_units: end func_002CDC20 */

/* merge_units: begin func_002CDDE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_002CDDE0, D_0049AE80)
#pragma pop /* merge_units */
/* merge_units: end func_002CDDE0 */

/* merge_units: begin func_002CDEC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_002CDEC0(char* self) {
    return self + 4;
}

List* func_002CDED0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_002CDEC0 */

/* merge_units: begin func_002CDEF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void String_Dtor(void* p, int flags);
extern char D_004AD158[];
}
struct V_DEF0 { char p0[8]; char a[0xC]; char b[0xC]; };
struct LN_DEF0 { LN_DEF0* prev; LN_DEF0* next; V_DEF0 val; };
struct L_DEF0 { int count; };
static inline void Dt_DEF0(V_DEF0* v)
{
    if (v) {
        if (v->b) String_Dtor(v->b, 0);
        if (v->a) String_Dtor(v->a, 0);
    }
}
/* Erases [first, last) from the list, destroying each value; returns last. */
extern "C" void func_002CDEF0(LN_DEF0** result, L_DEF0* list, LN_DEF0** first, LN_DEF0** last)
{
    LN_DEF0* f = *first;
    LN_DEF0* l = *last;
    if (f == l) {
        *result = l;
        return;
    }
    LN_DEF0* lp = l->prev;
    f->prev->next = lp->next;
    lp->next->prev = f->prev;
    while (*first != *last) {
        Dt_DEF0(&(*first)->val);
        LN_DEF0* n = *first;
        *first = (*first)->next;
        if (n) {
            AllocGuard guard;
            Mem_Free(0, n, D_004AD158, 0x64);
        }
        list->count--;
    }
    *result = *last;
}
#pragma pop /* merge_units */
/* merge_units: end func_002CDEF0 */

/* merge_units: begin func_002CE070 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V2CE070 { char pad[8]; char s8[0xC]; char s14[4]; };
struct N2CE070 { N2CE070* prev; N2CE070* next; V2CE070 val; };
struct It2CE070 { N2CE070* p; };
struct L2CE070 { int size; };
extern "C" {
void String_Dtor(void* p, int f);
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void VDtor2CE070(V2CE070* v)
{
    if (v) {
        if (v->s14)
            String_Dtor(v->s14, 0);
        if (v->s8)
            String_Dtor(v->s8, 0);
    }
}
extern "C" void func_002CE070(It2CE070* ret, L2CE070* l, It2CE070* pos)
{
    N2CE070* n = pos->p;
    pos->p = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    VDtor2CE070(&n->val);
    if (n) {
        AllocGuard g;
        Mem_Free(0, n, D_004AD158, 0x64);
    }
    l->size--;
    ret->p = pos->p;
}
#pragma pop /* merge_units */
/* merge_units: end func_002CE070 */

/* merge_units: begin func_002CE1A0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004AD148[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
}

struct Str_CE1A0 { int w[3]; };
extern "C" Str_CE1A0* func_0013BCB0(Str_CE1A0* self, const Str_CE1A0* src);

struct Val_CE1A0 {
    int a;
    int b;
    Str_CE1A0 s8;
    Str_CE1A0 s14;
    int f20;
    int f24;
};

struct Node_CE1A0 {
    Node_CE1A0* prev;
    Node_CE1A0* next;
    Val_CE1A0 value;
};

struct List_CE1A0 {
    int count;
    int alloc;
};

struct Flag_CE1A0 {
    char c;
    Flag_CE1A0() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_CE1A0() {}
};

struct Holder_CE1A0;
extern "C" {
int func_002CE4D0(Holder_CE1A0* h);
Node_CE1A0* func_002CE4E0(Holder_CE1A0* h);
int func_002CE4C0(Holder_CE1A0* h);
void func_002CE420(int alloc, Node_CE1A0* n, int count);
}

struct Holder_CE1A0 {
    int* alloc;
    Node_CE1A0* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_CE1A0()
    {
        if (func_002CE4E0(this))
            func_002CE420(func_002CE4D0(this), func_002CE4E0(this), func_002CE4C0(this));
    }
};



extern "C" int func_002CE1A0(Node_CE1A0** result, List_CE1A0* list, Node_CE1A0** pos, const Val_CE1A0* value)
{
    Node_CE1A0* n;
    int* alloc = &list->alloc;
    Flag_CE1A0 flag;
    {
        AllocGuard guard;
        n = (Node_CE1A0*)Mem_Alloc(0, 0x30, D_004AD148, 0x5C);
    }
    Holder_CE1A0 h;
    h.alloc = alloc;
    h.node = n;
    Val_CE1A0* v = &h.node->value;
    if (v) {
        v->a = value->a;
        v->b = value->b;
        func_0013BCB0(&v->s8, &value->s8);
        func_0013BCB0(&v->s14, &value->s14);
        v->f20 = value->f20;
        v->f24 = value->f24;
    }
    Node_CE1A0* p;
    Node_CE1A0* m = h.node;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002CE1A0 */

/* merge_units: begin func_002CE340 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destructor of a holder that frees its owned pointer. */
DEFINE_PTR4_HOLDER_DTOR(func_002CE340, D_004AD158)
#pragma pop /* merge_units */
/* merge_units: end func_002CE340 */
