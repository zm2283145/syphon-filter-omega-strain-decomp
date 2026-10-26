#include "types.h"

typedef struct E { int w[3]; } E;
typedef struct V { E* data; unsigned int count; unsigned int cap; } V;
extern char D_004A3E90[];
extern unsigned int std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(E* first, E* last);
extern unsigned int std_vector_imp_cSkaBlendSequenceItem_capacity(V* v);
extern unsigned int* std_min(unsigned int* a, unsigned int* b);
extern E* std_vector_imp_cSkaBlendSequenceItem_begin_void_2(V* v);
extern void cSkaBlendSequenceItem_opAssign(E* d, E* s);
extern E* std_vector_imp_cSkaBlendSequenceItem_end_void(V* v);
extern void* std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(V* v);
extern void cAllocator_cSkaBlendSequenceItem_destroy(void* alloc, E* p);
extern void cAllocator_cSkaBlendSequenceItem_construct(void* alloc, E* p, E* s);
extern unsigned int std_vector_imp_cSkaBlendSequenceItem_max_size(V* v);
extern void std_msl_error(const char* msg);
extern void std_vector_imp_cSkaBlendSequenceItem_clear(V* v);
extern E** std_vector_deleter_cSkaBlendSequenceItem_data_void(V* v);
extern unsigned int* std_vector_deleter_cSkaBlendSequenceItem_cap_void(V* v);
extern void cAllocator_cSkaBlendSequenceItem_deallocate(void* alloc, E* p, unsigned int n);
extern E* cAllocator_cSkaBlendSequenceItem_allocate(void* alloc, unsigned int n, int hint);

#pragma push
#pragma optimization_level 1
void Vector_Assign_209A20(V* v, E* first, E* last)
{
    unsigned int n;
    E* p;
    E* end;
    n = std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(first, last);
    if (n <= std_vector_imp_cSkaBlendSequenceItem_capacity(v)) {
        unsigned int k = *std_min(&n, &v->count);
        p = std_vector_imp_cSkaBlendSequenceItem_begin_void_2(v);
        end = p + k;
        while (p < end) {
            cSkaBlendSequenceItem_opAssign(p, first);
            p++;
            first++;
        }
        if (n < v->count) {
            end = std_vector_imp_cSkaBlendSequenceItem_end_void(v);
            while (p < end) {
                cAllocator_cSkaBlendSequenceItem_destroy(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), p);
                p++;
            }
            v->count = n;
        } else if (v->count < n) {
            while (first != last) {
                cAllocator_cSkaBlendSequenceItem_construct(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), p, first);
                first++;
                p++;
                v->count++;
            }
        }
    } else {
        if (n > std_vector_imp_cSkaBlendSequenceItem_max_size(v))
            std_msl_error(D_004A3E90);
        std_vector_imp_cSkaBlendSequenceItem_clear(v);
        if (*std_vector_deleter_cSkaBlendSequenceItem_data_void(v) != 0) {
            cAllocator_cSkaBlendSequenceItem_deallocate(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), *std_vector_deleter_cSkaBlendSequenceItem_data_void(v), *std_vector_deleter_cSkaBlendSequenceItem_cap_void(v));
            *std_vector_deleter_cSkaBlendSequenceItem_data_void(v) = 0;
            *std_vector_deleter_cSkaBlendSequenceItem_cap_void(v) = 0;
        }
        *std_vector_deleter_cSkaBlendSequenceItem_data_void(v) = cAllocator_cSkaBlendSequenceItem_allocate(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), n, 0);
        *std_vector_deleter_cSkaBlendSequenceItem_cap_void(v) = n;
        p = std_vector_imp_cSkaBlendSequenceItem_begin_void_2(v);
        while (first != last) {
            cAllocator_cSkaBlendSequenceItem_construct(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), p, first);
            first++;
            p++;
            v->count++;
        }
    }
}
#pragma pop
