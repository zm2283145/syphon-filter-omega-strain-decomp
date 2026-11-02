/*
 * SFOGame/Source/gameFrontEnd: 12 files, 002CD1B0-002CD9F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CD1B0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "string_replace_range_xd.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "short_string_assign.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "string_reserve.h"
#pragma pop

#pragma cplusplus on

extern "C" {
char D_004AD0C0[] = "basic_string: out_of_range";
}
extern "C" {
char D_004AD0E0[] = "basic_string: length_error";
}
DEFINE_STRING_REPLACE_RANGE_XD(String_Replace_2CD1B0, D_004AD0C0, D_004AD0E0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048C370, D_0048C378, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP, String_Dtor)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CD1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CD1B0 */

/* merge_units: begin func_002CD620 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_002CD620)
static inline void merge_flush_func_002CD620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CD620 */

/* merge_units: begin func_002CD6B0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004AD100[] = "basic_string::reserve length_error";
}
DEFINE_STRING_RESERVE(String_Reserve_2CD6B0, D_004AD100, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CD6B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CD6B0 */

/* merge_units: begin func_002CD9F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_002CD9F0)
static inline void merge_flush_func_002CD9F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CD9F0 */

/* merge_units: begin func_002CDAE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_range.h"

/* Erase a range of nodes from a linked list. */
DEFINE_OBJECT_LIST_ERASE_RANGE(func_002CDAE0)
static inline void merge_flush_func_002CDAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CDAE0 */

/* merge_units: begin func_002CDC20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "list_insert_before.h"

/* Insert an int value before a list position. */
DEFINE_LIST_INSERT_BEFORE(func_002CDC20)
static inline void merge_flush_func_002CDC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CDC20 */

/* merge_units: begin func_002CDDE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Free the owned allocation, optionally delete. */
DEFINE_PTR4_HOLDER_DTOR(func_002CDDE0, D_0049AE80)
static inline void merge_flush_func_002CDDE0(void) {} /* merge_units */
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
static inline void merge_flush_func_002CDEC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CDEC0 */

/* merge_units: begin func_002CDEF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(void* p, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((TStr *)(a0), (a1))) /* merge_units */

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
extern "C" void std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(LN_DEF0** result, L_DEF0* list, LN_DEF0** first, LN_DEF0** last)
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
            cMemMan_Deallocate(0, n, D_004AD158, 0x64);
        }
        list->count--;
    }
    *result = *last;
}
#undef cMemMan_Deallocate /* merge_units */
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_002CDEF0(void) {} /* merge_units */
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
#if 0 /* merge_units */
void String_Dtor(void* p, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((TStr *)(a0), (a1))) /* merge_units */

void cMemMan_Deallocate(int pool, void* p, char* file, int line);
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
extern "C" void std_list_deleter_MessageBoxEntry_erase_listdeleter(It2CE070* ret, L2CE070* l, It2CE070* pos)
{
    N2CE070* n = pos->p;
    pos->p = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    VDtor2CE070(&n->val);
    if (n) {
        AllocGuard g;
        cMemMan_Deallocate(0, n, D_004AD158, 0x64);
    }
    l->size--;
    ret->p = pos->p;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_002CE070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CE070 */

/* merge_units: begin func_002CE1A0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004AD148[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
}

struct Str_CE1A0 { int w[3]; };
extern "C" Str_CE1A0* std_basic_string_char_char_traits_char_ctor_basicstringR(Str_CE1A0* self, const Str_CE1A0* src);

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



extern "C" int std_list_deleter_MessageBoxEntry_insert(Node_CE1A0** result, List_CE1A0* list, Node_CE1A0** pos, const Val_CE1A0* value)
{
    Node_CE1A0* n;
    int* alloc = &list->alloc;
    Flag_CE1A0 flag;
    {
        AllocGuard guard;
        n = (Node_CE1A0*)cMemMan_Allocate(0, 0x30, D_004AD148, 0x5C);
    }
    Holder_CE1A0 h;
    h.alloc = alloc;
    h.node = n;
    Val_CE1A0* v = &h.node->value;
    if (v) {
        v->a = value->a;
        v->b = value->b;
        std_basic_string_char_char_traits_char_ctor_basicstringR(&v->s8, &value->s8);
        std_basic_string_char_char_traits_char_ctor_basicstringR(&v->s14, &value->s14);
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
static inline void merge_flush_func_002CE1A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CE1A0 */

/* merge_units: begin func_002CE340 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destructor of a holder that frees its owned pointer. */
DEFINE_PTR4_HOLDER_DTOR(alloc_ptr_node_cAllocator_node_dtor_void, D_004AD158)
static inline void merge_flush_func_002CE340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CE340 */
