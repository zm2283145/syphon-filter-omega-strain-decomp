/*
 * SFOGame/Source/GuiSubTitleDisplay: 4 files, 00459690-00459AC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00459690 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_459690)
static inline void merge_flush_func_00459690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459690 */

/* merge_units: begin func_00459780 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#define D_0049AE80 D_004C1F58
#include "object_list_erase_range.h"

DEFINE_OBJECT_LIST_ERASE_RANGE(std_list_deleter_TextAtom_erase)
static inline void merge_flush_func_00459780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459780 */

/* merge_units: begin func_004598C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#ifndef LIB_004598C0
#define LIB_004598C0

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_004C1F58[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

struct I8_004598C0Val { float a; float b __attribute__((aligned(16))); float c; float d; float e; int f; int g; int h; int i; };
struct ListI8_004598C0Node {
    ListI8_004598C0Node* prev;
    ListI8_004598C0Node* next;
    I8_004598C0Val value;
};

struct ListI8_004598C0 {
    int count;
    int alloc;
};

struct ListI8_004598C0Flag {
    char c;
    ListI8_004598C0Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_004598C0Flag() {}
};

struct ListI8_004598C0Holder;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_11(ListI8_004598C0Holder* holder);

struct ListI8_004598C0Holder {
    int* alloc;
    ListI8_004598C0Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_004598C0Holder()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_11(this);
            ListI8_004598C0Node* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_004C1F58, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_004598C0Node** result, ListI8_004598C0* list,                  \
                        ListI8_004598C0Node** pos, const I8_004598C0Val* value)                  \
    {                                                                         \
        ListI8_004598C0Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_004598C0Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_004598C0Node*)cMemMan_Allocate(0, 64, "allocator.hh", 0x5C);            \
        }                                                                     \
        ListI8_004598C0Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_004598C0Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_004598C0Node* p;                                                       \
        ListI8_004598C0Node* m = h.node;                                              \
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

#endif /* LIB_004598C0 */
DEFINE_LIST_INSERT_BEFORE8(std_list_deleter_TextAtom_insert)
static inline void merge_flush_func_004598C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004598C0 */

/* merge_units: begin func_00459AC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptr4_holder_dtor.h"

/* Destructor of a holder that frees its owned pointer. */
DEFINE_PTR4_HOLDER_DTOR(alloc_ptr_node_cAllocator_node_dtor_void_2, D_004C1F58)
static inline void merge_flush_func_00459AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459AC0 */
