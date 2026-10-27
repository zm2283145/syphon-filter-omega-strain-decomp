#include "types.h"

typedef struct E { int w[9]; } E;
typedef struct V { E* data; unsigned int count; unsigned int cap; } V;
extern char D_004A3E90[];
extern unsigned int std_distance_cSkaTransBLENDP_cSkaTransBLENDP(E* first, E* last);
extern unsigned int std_vector_imp_cSkaTransBLEND_capacity(V* v);
extern unsigned int* std_min(unsigned int* a, unsigned int* b);
extern E* std_vector_imp_cSkaTransBLEND_begin_void(V* v);
extern void cSkaTransBLEND_opAssign(E* d, E* s);
extern E* std_vector_imp_cSkaTransBLEND_end_void(V* v);
extern void* std_vector_deleter_cSkaTransBLEND_alloc_void(V* v);
extern void cAllocator_cSkaTransBLEND_destroy(void* alloc, E* p);
extern void cAllocator_cSkaTransBLEND_construct(void* alloc, E* p, E* s);
extern unsigned int std_vector_imp_cSkaTransBLEND_max_size(V* v);
extern void std_msl_error(const char* msg);
extern void std_vector_imp_cSkaTransBLEND_clear(V* v);
extern E** std_vector_deleter_cSkaTransBLEND_data_void(V* v);
extern unsigned int* std_vector_deleter_cSkaTransBLEND_cap_void(V* v);
extern void cAllocator_cSkaTransBLEND_deallocate(void* alloc, E* p, unsigned int n);
extern E* cAllocator_cSkaTransBLEND_allocate(void* alloc, unsigned int n, int hint);

#pragma push
#pragma optimization_level 1
void std_vector_imp_cSkaTransBLEND_do_assign(V* v, E* first, E* last)
{
    unsigned int n;
    E* p;
    E* end;
    n = std_distance_cSkaTransBLENDP_cSkaTransBLENDP(first, last);
    if (n <= std_vector_imp_cSkaTransBLEND_capacity(v)) {
        unsigned int k = *std_min(&n, &v->count);
        p = std_vector_imp_cSkaTransBLEND_begin_void(v);
        end = p + k;
        while (p < end) {
            cSkaTransBLEND_opAssign(p, first);
            p++;
            first++;
        }
        if (n < v->count) {
            end = std_vector_imp_cSkaTransBLEND_end_void(v);
            while (p < end) {
                cAllocator_cSkaTransBLEND_destroy(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p);
                p++;
            }
            v->count = n;
        } else if (v->count < n) {
            while (first != last) {
                cAllocator_cSkaTransBLEND_construct(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p, first);
                first++;
                p++;
                v->count++;
            }
        }
    } else {
        if (n > std_vector_imp_cSkaTransBLEND_max_size(v))
            std_msl_error(D_004A3E90);
        std_vector_imp_cSkaTransBLEND_clear(v);
        if (*std_vector_deleter_cSkaTransBLEND_data_void(v) != 0) {
            cAllocator_cSkaTransBLEND_deallocate(std_vector_deleter_cSkaTransBLEND_alloc_void(v), *std_vector_deleter_cSkaTransBLEND_data_void(v), *std_vector_deleter_cSkaTransBLEND_cap_void(v));
            *std_vector_deleter_cSkaTransBLEND_data_void(v) = 0;
            *std_vector_deleter_cSkaTransBLEND_cap_void(v) = 0;
        }
        *std_vector_deleter_cSkaTransBLEND_data_void(v) = cAllocator_cSkaTransBLEND_allocate(std_vector_deleter_cSkaTransBLEND_alloc_void(v), n, 0);
        *std_vector_deleter_cSkaTransBLEND_cap_void(v) = n;
        p = std_vector_imp_cSkaTransBLEND_begin_void(v);
        while (first != last) {
            cAllocator_cSkaTransBLEND_construct(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p, first);
            first++;
            p++;
            v->count++;
        }
    }
}
#pragma pop

