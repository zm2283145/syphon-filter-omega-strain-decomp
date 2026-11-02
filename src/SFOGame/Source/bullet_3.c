/*
 * SFOGame/Source/bullet: 2 files, 00278250-002782B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00278250 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* std_vector_cBulletPtr_dtor(void* self, short deleteFlag);

typedef struct { int pad0[0x78/4]; int member; } Obj_00351FC0;

extern "C" Obj_00351FC0* cBullet_dtor(Obj_00351FC0* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            std_vector_cBulletPtr_dtor(m, -1);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00278250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278250 */

/* merge_units: begin func_002782B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cBulletPtr_dtor)
static inline void merge_flush_func_002782B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002782B0 */
