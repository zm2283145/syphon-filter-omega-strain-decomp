/*
 * Libs/SFOLib/Source/message: 4 files, 003CA0E0-003CA2B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_3CA0E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#ifndef LIB_003CA0E0
#define LIB_003CA0E0

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_004BD198[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

struct I8_003CA0E0Val { int w0; int w1; int w2; };
struct ListI8_003CA0E0Node {
    ListI8_003CA0E0Node* prev;
    ListI8_003CA0E0Node* next;
    I8_003CA0E0Val value;
};

struct ListI8_003CA0E0 {
    int count;
    int alloc;
};

struct ListI8_003CA0E0Flag {
    char c;
    ListI8_003CA0E0Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_003CA0E0Flag() {}
};

struct ListI8_003CA0E0Holder;
#if 0 /* merge_units */
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(ListI8_003CA0E0Holder* holder);
#endif /* merge_units */
extern "C" void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(char* self); /* merge_units */
#define details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(a0) ((void)details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9((char *)(a0))) /* merge_units */


struct ListI8_003CA0E0Holder {
    int* alloc;
    ListI8_003CA0E0Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_003CA0E0Holder()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(this);
            ListI8_003CA0E0Node* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_004BD198, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_003CA0E0Node** result, ListI8_003CA0E0* list,                  \
                        ListI8_003CA0E0Node** pos, const I8_003CA0E0Val* value)                  \
    {                                                                         \
        ListI8_003CA0E0Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_003CA0E0Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_003CA0E0Node*)cMemMan_Allocate(0, 20, "allocator.hh", 0x5C);            \
        }                                                                     \
        ListI8_003CA0E0Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_003CA0E0Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_003CA0E0Node* p;                                                       \
        ListI8_003CA0E0Node* m = h.node;                                              \
        h.node = 0;                                                           \
        p = *pos;                                                             \
        p->prev->next = m;                                                    \
        m->prev = p->prev;                                                    \
        p->prev = m;                                                          \
        m->next = p;                                                          \
        list->count++;                                                        \
        *result = m;                                                          \
        return 0;                                                             \
    }

#endif /* LIB_003CA0E0 */
DEFINE_LIST_INSERT_BEFORE8(std_list_deleter_tQueuedMessage_insert)
#undef details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9 /* merge_units */
static inline void merge_flush_message_3CA0E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_3CA0E0 */

/* merge_units: begin func_003CA2B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(char* self) {
    return self + 4;
}

Map* std_tree_pair_int_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

List* std_list_deleter_tQueuedMessage_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_003CA2B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA2B0 */

/* merge_units: begin func_003CA300 */
#pragma push /* merge_units */
extern void std_list_deleter_tQueuedMessage_dtor(void* self, short del);
extern void operator_delete(void* p);
void* std_list_tQueuedMessage_dtor(void* self, short del)
{
    if (self) {
        if (self)
            std_list_deleter_tQueuedMessage_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003CA300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA300 */

/* merge_units: begin func_003CA360 */
#pragma push /* merge_units */
extern void std_list_deleter_tQueuedMessage_begin(int* out, void* self);
extern void std_list_deleter_tQueuedMessage_end(int* out, void* self);
extern void std_list_deleter_tQueuedMessage_erase(int* out, void* self, int* first, int* last);
void* std_list_imp_tQueuedMessage_dtor(void* self, short del)
{
    if (self) {
        if (self) {
            int r;
            int first;
            int last;
            std_list_deleter_tQueuedMessage_begin(&first, self);
            std_list_deleter_tQueuedMessage_end(&last, self);
            std_list_deleter_tQueuedMessage_erase(&r, self, &first, &last);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003CA360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA360 */
