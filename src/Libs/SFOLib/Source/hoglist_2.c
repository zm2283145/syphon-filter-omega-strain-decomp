/*
 * Libs/SFOLib/Source/hoglist: 4 files, 003F96E0-003F9B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F96E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" {
typedef struct { char pad[0x14C]; unsigned char active; char pad2[0x168 - 0x14D]; unsigned char keep; char pad3[3]; } O96E0;
typedef struct N96E0 { struct N96E0* prev; struct N96E0* next; O96E0 obj; } N96E0;
typedef struct { int m0; N96E0* list; } T96E0;
#if 0 /* merge_units */
extern N96E0* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* list);
#endif /* merge_units */
void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void*); /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(a0) ((N96E0 *)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11((a0))) /* merge_units */

extern void* std_list_deleter_cHogFile_tail(void* self);
#if 0 /* merge_units */
extern void std_list_deleter_cHogFile_generic_iterator_ctor(N96E0** out, void* v);
#endif /* merge_units */
void* std_list_deleter_cHogFile_generic_iterator_ctor(void*, void*); /* merge_units */
#define std_list_deleter_cHogFile_generic_iterator_ctor(a0, a1) ((void)std_list_deleter_cHogFile_generic_iterator_ctor((void *)(a0), (a1))) /* merge_units */

extern int String_CompareNoCase(const char* a, const char* b);
extern int cHogFile_OpenHog(O96E0* o, const char* name, unsigned char stream, int pool);
#if 0 /* merge_units */
extern void cHogFile_ctor(O96E0* o);
#endif /* merge_units */
void cHogFile_ctor(void*); /* merge_units */
#define cHogFile_ctor(a0) (cHogFile_ctor((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cHogFile_dtor(O96E0* o, int f);
#endif /* merge_units */
int cHogFile_dtor(...); /* merge_units */

#if 0 /* merge_units */
extern void std_list_deleter_cHogFile_insert(N96E0** out, T96E0* self, void* pos, O96E0* v);
#endif /* merge_units */
struct Node_3F9B30; /* merge_units */
struct List_3F9B30; /* merge_units */
struct Val_3F9B30; /* merge_units */
int std_list_deleter_cHogFile_insert(Node_3F9B30** result, List_3F9B30* list, Node_3F9B30** pos, const Val_3F9B30* value); /* merge_units */
#define std_list_deleter_cHogFile_insert(a0, a1, a2, a3) ((void)std_list_deleter_cHogFile_insert((Node_3F9B30 * *)(a0), (List_3F9B30 *)(a1), (Node_3F9B30 * *)(a2), (const Val_3F9B30 *)(a3))) /* merge_units */

}
/* the enum ternary into the unsigned char parameter gives li/movz/andi */
enum ArchiveLoadMode { ARCHIVE_RESIDENT, ARCHIVE_STREAMED };

/*
 * Find the archive called name (case-insensitive) in the list; (re)load it
 * when it is not loaded in the requested mode. Otherwise append a new entry
 * at the front of the list, load it and clear its keep flag.
 */
extern "C" O96E0* cHogList_Open(T96E0* self, const char* name, int stream, int pool)
{
    N96E0* e;
    N96E0* n;
    O96E0 tmp;
    N96E0* r;
    void* pos;
    O96E0* o;
    for (n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(&self->list)->next; std_list_deleter_cHogFile_generic_iterator_ctor(&e, std_list_deleter_cHogFile_tail(self)), n != e; n = n->next) {
        if (!String_CompareNoCase((char*)&n->obj, name)) {
            if (stream ? !(n->obj.active == 2) : !(n->obj.active != 0))
                cHogFile_OpenHog(&n->obj, name, stream ? ARCHIVE_STREAMED : ARCHIVE_RESIDENT, pool);
            return &n->obj;
        }
    }
    cHogFile_ctor(&tmp);
    pos = &self->list;
    std_list_deleter_cHogFile_insert(&r, self, &pos, &tmp);
    cHogFile_dtor(&tmp, -1);
    o = &self->list->obj;
    cHogFile_OpenHog(o, name, stream ? ARCHIVE_STREAMED : ARCHIVE_RESIDENT, pool);
    o->keep = 0;
    return o;
}
#undef details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11 /* merge_units */
#undef std_list_deleter_cHogFile_generic_iterator_ctor /* merge_units */
#undef cHogFile_ctor /* merge_units */
#undef std_list_deleter_cHogFile_insert /* merge_units */
static inline void merge_flush_func_003F96E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F96E0 */

/* merge_units: begin func_003F9850 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Elem3F98 { char name[0x14C]; unsigned char loaded; char pad14D[0x168 - 0x14D]; unsigned char busy; char pad169[0x170 - 0x169]; };
struct Node3F98 { Node3F98* prev; Node3F98* next; Elem3F98 data; };
struct List3F98 { int x0; Node3F98 sentinel; };
struct Pool3F98 { char pad[0x164]; int heap; };
struct FEnt3F98 { int d[0x27]; };
extern "C" {
extern char D_004BE1F0[];
void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void*);
#if 0 /* merge_units */
void* std_list_deleter_cHogFile_generic_iterator_ctor(Node3F98** out, void* v);
#endif /* merge_units */
#define std_list_deleter_cHogFile_generic_iterator_ctor(a0, a1) (std_list_deleter_cHogFile_generic_iterator_ctor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void* std_list_deleter_cHogFile_tail(List3F98*);
#endif /* merge_units */
#define std_list_deleter_cHogFile_tail(a0) (std_list_deleter_cHogFile_tail((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int String_CompareNoCase(void*, char*);
#endif /* merge_units */
#define String_CompareNoCase(a0, a1) (String_CompareNoCase((const char *)(a0), (const char *)(a1))) /* merge_units */

void cHogFile_ctor(void*);
#if 0 /* merge_units */
void cHogFile_dtor(void*, int);
#endif /* merge_units */

#if 0 /* merge_units */
void std_list_deleter_cHogFile_insert(Node3F98** out, List3F98* l, Node3F98** pos, Elem3F98* v);
#endif /* merge_units */
struct Node_3F9B30; /* merge_units */
struct List_3F9B30; /* merge_units */
struct Val_3F9B30; /* merge_units */
#define std_list_deleter_cHogFile_insert(a0, a1, a2, a3) ((void)std_list_deleter_cHogFile_insert((Node_3F9B30 * *)(a0), (List_3F9B30 *)(a1), (Node_3F9B30 * *)(a2), (const Val_3F9B30 *)(a3))) /* merge_units */

void* cFileMan_ctor_charP_cHogFileR_bool(void* entry, const char* name, void* handle, int extra);
int cFileMan_Open(void*);
int cFileMan_GetSize(void*);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
int cFileMan_Read_charPP_int(void*, char**, int);
void cHogFile_Open(void*, char*, char*, int);
void* cFileMan_dtor(void*, int);
}
static inline Node3F98* EndN(List3F98* l) { Node3F98* r; std_list_deleter_cHogFile_generic_iterator_ctor(&r, std_list_deleter_cHogFile_tail(l)); return r; }
static inline void Ins(List3F98* l, Elem3F98* v) { Node3F98* ins; Node3F98* pos; pos = &l->sentinel; std_list_deleter_cHogFile_insert(&ins, l, &pos, v); }
extern "C" Elem3F98* cHogList_OpenFromHog(List3F98* self, char* name, Pool3F98* pool)
{
    char* buf;
    int heap;
    FEnt3F98 e;
    Elem3F98 tmp;
    Node3F98* n;
    Elem3F98* el;
    n = ((Node3F98*)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(&self->sentinel))->next;
    while (n != EndN(self)) {
        if (String_CompareNoCase(&n->data, name) == 0 && n->data.loaded) {
            return &n->data;
        }
        n = n->next;
    }
    cHogFile_ctor(&tmp);
    Ins(self, &tmp);
    cHogFile_dtor(&tmp, -1);
    el = &self->sentinel.prev->data;
    cFileMan_ctor_charP_cHogFileR_bool(&e, name, pool, 0);
    cFileMan_Open(&e);
    heap = pool->heap;
    {
        int size = cFileMan_GetSize(&e);
        char* p;
        {
            AllocGuard g;
            p = (char*)cMemMan_Allocate(heap, size, D_004BE1F0, 0x2A);
        }
        buf = p;
    }
    cFileMan_Read_charPP_int(&e, &buf, 0);
    cHogFile_Open(el, name, buf, pool->heap);
    el->busy = 0;
    cFileMan_dtor(&e, -1);
    return el;
}
#undef std_list_deleter_cHogFile_generic_iterator_ctor /* merge_units */
#undef std_list_deleter_cHogFile_tail /* merge_units */
#undef String_CompareNoCase /* merge_units */
#undef std_list_deleter_cHogFile_insert /* merge_units */
static inline void merge_flush_func_003F9850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9850 */

/* merge_units: begin func_003F9A30 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(...);                     
int cHogFile_dtor(...);                         
extern char D_0049AE60;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void std_list_deleter_cHogFile_erase_listdeleter(void ***arg0, int *arg1, void ***arg2) {
    void **temp_s0;

    temp_s0 = *arg2;
    *arg2 = (void **)(F_(temp_s0, 0x4, int));
    F_(F_(temp_s0, 0x0, int), 0x4, int) = (int)(F_(temp_s0, 0x4, int));
    *(int *)F_(temp_s0, 0x4, int) = F_(temp_s0, 0x0, int);
    cHogFile_dtor((char *)temp_s0 + 8, -1);
    if (temp_s0 != NULL) {
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s0, &D_0049AE60, 0x64);
        }
    }
    *arg1 -= 1;
    *arg0 = *arg2;
}
static inline void merge_flush_func_003F9A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9A30 */

/* merge_units: begin func_003F9B30 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
#if 0 /* merge_units */
extern char D_0049AE60[];
#endif /* merge_units */
#define D_0049AE60 ((char*)&D_0049AE60) /* merge_units */

#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (int)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
#endif /* merge_units */

}
inline void* operator new(unsigned int, void* p) { return p; }
struct V4_3F9B30 { float x, y, z, w; V4_3F9B30(const V4_3F9B30& o) { float a = o.x, b = o.y, c = o.z, d = o.w; x = a; y = b; z = c; w = d; } };
struct V3_3F9B30 { float x, y, z; V3_3F9B30(const V3_3F9B30& o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Val_3F9B30 {
    char name[0x80]; int f80; V4_3F9B30 v84; V4_3F9B30 v94; float fA4; int fA8; int fAC;
    V3_3F9B30 vB0; int fBC; unsigned char fC0; char name2[0x80]; int f144; int f148; signed char f14C;
    int f150; int f154; int f158; int f15C; int f160; int f164; unsigned char f168;
};
struct Node_3F9B30 { Node_3F9B30* prev; Node_3F9B30* next; Val_3F9B30 value; };
struct List_3F9B30 { int count; int alloc; };
struct Flag_3F9B30 {
    char c;
    Flag_3F9B30() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_3F9B30() {}
};
struct Holder_3F9B30;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_10(Holder_3F9B30* h);
struct Holder_3F9B30 {
    int* alloc;
    Node_3F9B30* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_3F9B30()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_10(this);
            Node_3F9B30* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_0049AE60, 0x64);
            }
        }
    }
};

#pragma push
#pragma opt_propagation off
extern "C" int std_list_deleter_cHogFile_insert(Node_3F9B30** result, List_3F9B30* list, Node_3F9B30** pos, const Val_3F9B30* value)
{
    Node_3F9B30* n;
    int* alloc = &list->alloc;
    Flag_3F9B30 flag;
    {
        AllocGuard guard;
        n = (Node_3F9B30*)cMemMan_Allocate(0, 0x174, "allocator.hh", 0x5C);
    }
    {
    Holder_3F9B30 h;
    h.alloc = alloc;
    h.node = n;
    Val_3F9B30* v = &h.node->value;
    new (v) Val_3F9B30(*value);
    Node_3F9B30* p;
    Node_3F9B30* m = h.node;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    }
    return 0;
}
#pragma pop
#undef D_0049AE60 /* merge_units */
#undef cMemMan_Allocate /* merge_units */
static inline void merge_flush_func_003F9B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9B30 */
