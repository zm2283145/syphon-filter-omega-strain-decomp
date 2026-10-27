/*
 * Libs/SFOLib/Source/gameobj: 2 files, 00393DD0-00393EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00393DD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_0049AF00[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}
typedef struct { int a; int b; int c; void* buffer; } BufHolder393DD0;
extern "C" BufHolder393DD0* _cdeque_imp_cSkaSystem_RequestPtr_1_dtor(BufHolder393DD0* self, short deleteFlag)
{
    if (self) {
        if (self) {
            void* p = self->buffer;
            if (p) {
                if (p) {
                    AllocGuard guard;
                    cMemMan_Deallocate(0, p, D_0049AF00, 0x64);
                }
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00393DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393DD0 */

/* merge_units: begin func_00393EC0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern Quad4* _cdeque_deleter_int_1_ctor(Quad4* q);
extern RelFlag* std_vector_imp_cBone_ctor(RelFlag* r);

Quad4* cdeque_cSkaSystem_RequestPtr_ctor(Quad4* q) {
    _cdeque_deleter_int_1_ctor(q);
    return q;
}

Quad4* _cdeque_deleter_int_1_ctor(Quad4* q) {
    q->unk0 = 0;
    q->unk4 = 0;
    q->unk8 = 0.0f;
    q->unkC = 0.0f;
    return q;
}

/* Clears the first two words and sets the two floats to FLT_MAX. */
Quad4* cSkaCrossFadeDuration_ctor_void(Quad4* q) {
    q->unk0 = 0;
    q->unk4 = 0;
    q->unk8 = 3.4028234663852886e38f;
    q->unkC = 3.4028234663852886e38f;
    return q;
}

RelFlag* cArray_cBone_ctor(RelFlag* r) {
    std_vector_imp_cBone_ctor(r);
    r->flag = 1;
    return r;
}
static inline void merge_flush_func_00393EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393EC0 */
