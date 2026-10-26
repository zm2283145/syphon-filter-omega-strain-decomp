#include "types.h"
typedef struct { int a, b, c; } E9680;
typedef struct { int x0; unsigned int count; } V9680;
extern int std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(E9680* first, E9680* last);
extern unsigned int std_vector_imp_cSkaBlendSequenceItem_max_size(V9680* v);
extern void std_msl_error(const char* msg);
extern char D_004A3E70[];
extern void* std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(V9680* v);
extern E9680* cAllocator_cSkaBlendSequenceItem_allocate(void* alloc, int n, int hint);
extern E9680** std_vector_deleter_cSkaBlendSequenceItem_data_void(V9680* v);
extern int* std_vector_deleter_cSkaBlendSequenceItem_cap_void(V9680* v);
extern E9680* std_vector_imp_cSkaBlendSequenceItem_begin_void_2(V9680* v);
extern void cAllocator_cSkaBlendSequenceItem_construct(void* alloc, E9680* p, E9680* src);
#pragma optimization_level 1
void std_vector_imp_cSkaBlendSequenceItem_init(V9680* v, E9680* first, E9680* last)
{
    int x; int* px = &x; /* unused address-taken local: reproduces the retail 16-byte frame slot */
    int n = std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(first, last);
    if (v->count > std_vector_imp_cSkaBlendSequenceItem_max_size(v))
        std_msl_error(D_004A3E70);
    if (n != 0) {
        E9680* p;
        *std_vector_deleter_cSkaBlendSequenceItem_data_void(v) = cAllocator_cSkaBlendSequenceItem_allocate(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), n, 0);
        *std_vector_deleter_cSkaBlendSequenceItem_cap_void(v) = n;
        for (p = std_vector_imp_cSkaBlendSequenceItem_begin_void_2(v); first != last; first++) {
            cAllocator_cSkaBlendSequenceItem_construct(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), p, first);
            p++;
            v->count++;
        }
    }
}
#pragma optimization_level reset

