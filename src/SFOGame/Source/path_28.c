/*
 * SFOGame/Source/path: 2 files, 00163820-00163890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00163820 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void cPriorityQueueItem_cNodeIndex_dtor();
extern void * const D_004D9700[];
extern void * const D_004D9710[];
extern "C" char D_004D9720[];
extern "C" VtableChainObject* cNodeIndex_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9710);
        if (self) {
            self->vtable = ((char*)D_004D9700);
            if (self)
                self->vtable = D_004D9720;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9700[4] = { (void*)0x0, (void*)0x0, (void*)cPriorityQueueItem_cNodeIndex_dtor, (void*)0x0 };
void * const D_004D9710[4] = { (void*)0x0, (void*)0x0, (void*)cNodeIndex_dtor, (void*)0x0 };
static inline void merge_flush_func_00163820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00163820 */

/* merge_units: begin func_00163890 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Constructor that only installs vtables (base to derived).
 */

#include "path_types.h"

#if 0 /* merge_units */
extern char D_004D9700[];
#endif /* merge_units */
#define D_004D9700 ((char*)&D_004D9700) /* merge_units */

#if 0 /* merge_units */
extern char D_004D9710[];
#endif /* merge_units */
#define D_004D9710 ((char*)&D_004D9710) /* merge_units */

#if 0 /* merge_units */
extern char D_004D9720[];
#endif /* merge_units */
#define D_004D9720 ((char*)&D_004D9720) /* merge_units */


typedef struct PathPolyObj {
    void* vtable;
} PathPolyObj;

PathPolyObj* cNodeIndex_ctor(PathPolyObj* self) {
    self->vtable = D_004D9720;
    self->vtable = D_004D9700;
    self->vtable = D_004D9710;
    return self;
}
#undef D_004D9700 /* merge_units */
#undef D_004D9710 /* merge_units */
#undef D_004D9720 /* merge_units */
static inline void merge_flush_func_00163890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00163890 */
