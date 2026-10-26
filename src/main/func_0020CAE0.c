#include "types.h"
typedef struct { int w[9]; } ECAE0;
typedef struct { int x0; unsigned int count; } VCAE0;
extern int std_distance_cSkaTransBLENDP_cSkaTransBLENDP(ECAE0* first, ECAE0* last);
extern unsigned int std_vector_imp_cSkaTransBLEND_max_size(VCAE0* v);
extern void std_msl_error(const char* msg);
extern char D_004A3E70[];
extern void* std_vector_deleter_cSkaTransBLEND_alloc_void(VCAE0* v);
extern ECAE0* cAllocator_cSkaTransBLEND_allocate(void* alloc, int n, int hint);
extern ECAE0** std_vector_deleter_cSkaTransBLEND_data_void(VCAE0* v);
extern int* std_vector_deleter_cSkaTransBLEND_cap_void(VCAE0* v);
extern ECAE0* std_vector_imp_cSkaTransBLEND_begin_void(VCAE0* v);
extern void cAllocator_cSkaTransBLEND_construct(void* alloc, ECAE0* p, ECAE0* src);
#pragma optimization_level 1
void std_vector_imp_cSkaTransBLEND_init(VCAE0* v, ECAE0* first, ECAE0* last)
{
    int x; int* px = &x; /* unused address-taken local: reproduces the retail 16-byte frame slot */
    int n = std_distance_cSkaTransBLENDP_cSkaTransBLENDP(first, last);
    if (v->count > std_vector_imp_cSkaTransBLEND_max_size(v))
        std_msl_error(D_004A3E70);
    if (n != 0) {
        ECAE0* p;
        *std_vector_deleter_cSkaTransBLEND_data_void(v) = cAllocator_cSkaTransBLEND_allocate(std_vector_deleter_cSkaTransBLEND_alloc_void(v), n, 0);
        *std_vector_deleter_cSkaTransBLEND_cap_void(v) = n;
        for (p = std_vector_imp_cSkaTransBLEND_begin_void(v); first != last; first++) {
            cAllocator_cSkaTransBLEND_construct(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p, first);
            p++;
            v->count++;
        }
    }
}
#pragma optimization_level reset


