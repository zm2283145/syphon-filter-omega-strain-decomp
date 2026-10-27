/*
 * SFOGame/Source/gameCameraCollision: 3 files, 0020C9F0-0020CAE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020C9F0 */
#pragma push /* merge_units */
#include "types.h"
#pragma optimization_level 1

#if 0 /* merge_units */
extern void opDelete_cSkaSwitchItemP_int_bool_charP_etc(void*, int, int, void*, int);
#endif /* merge_units */
void opDelete_cSkaSwitchItemP_int_bool_charP_etc(); /* merge_units */


/* Calls opDelete_cSkaSwitchItemP_int_bool_charP_etc(obj, 0, 0, ((int*)"allocator.hh"), 100) when obj is set. */
void cAllocator_cSkaSwitchItem_deallocate(void* self, void* obj) {
    if (obj != 0) opDelete_cSkaSwitchItemP_int_bool_charP_etc(obj, 0, 0, ((int*)"allocator.hh"), 100);
}
static inline void merge_flush_func_0020C9F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020C9F0 */

/* merge_units: begin func_0020CA30 */
#pragma push /* merge_units */
extern void cTimerDisable_ctor(void* g);
extern void cTimerDisable_dtor(void* g, int flags);
extern void cSkaSwitchItem_dtor(void* p, int flags);
extern void cMemMan_Deallocate(void* a, void* b, void* c, int d);
#pragma optimization_level 1
void opDelete_cSkaSwitchItemP_int_bool_charP_etc(void* p, void* pool, int destroy, void* file, int line)
{
    int g[1];
    cTimerDisable_ctor(g);
    if (destroy)
        cSkaSwitchItem_dtor(p, -1);
    cMemMan_Deallocate(pool, p, file, line);
    cTimerDisable_dtor(g, -1);
}
#pragma optimization_level reset
static inline void merge_flush_func_0020CA30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020CA30 */

/* merge_units: begin func_0020CAE0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0020CAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020CAE0 */
