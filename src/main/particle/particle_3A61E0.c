/*
 * main/particle: 3 files, 003A61E0-003A62A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A61E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_003A61E0, func_00135D10)
#pragma pop /* merge_units */
/* merge_units: end func_003A61E0 */

/* merge_units: begin func_003A6240 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: destroy the member at +4, then delete. */
extern "C" void operator_delete(void* allocation);
extern "C" void* func_003A61E0(void* self, short deleteFlag);

typedef struct { int pad0; int member; } Obj_3A6240;

extern "C" Obj_3A6240* func_003A6240(Obj_3A6240* self, short deleteFlag)
{
    if (self) {
        void* m = &self->member;
        if (m)
            func_003A61E0(m, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6240 */

/* merge_units: begin func_003A62A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_003A62A0)
#pragma pop /* merge_units */
/* merge_units: end func_003A62A0 */
