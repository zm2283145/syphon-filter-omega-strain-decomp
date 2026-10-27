/*
 * Libs/SFOLib/Source/particle: 2 files, 00397DB0-00397EA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00397DB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cEffectRequestPtr_1_dtor)
static inline void merge_flush_func_00397DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00397DB0 */

/* merge_units: begin func_00397EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_vector_intPtr_dtor(void* p, int flags);
void operator_delete(void* p);
}
extern "C" void* cEffectRequest_dtor(void* self, short flag)
{
    if (self) {
        void* b = *(void**)self;
        {
            AllocGuard g;
            cMemMan_Deallocate(0, b, "particle.cc", 0x11A0);
        }
        {
            void* m = (char*)self + 4;
            if (m)
                std_vector_intPtr_dtor(m, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00397EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00397EA0 */
