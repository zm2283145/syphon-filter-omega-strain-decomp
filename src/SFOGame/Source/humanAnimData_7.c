/*
 * SFOGame/Source/humanAnimData: 4 files, 001F2870-001F2990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F2870 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "member0_dtor.h"
DEFINE_MEMBER0_DTOR(cArray_cSkaTransBLEND_dtor, std_vector_cSkaTransBLEND_dtor)
static inline void merge_flush_func_001F2870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2870 */

/* merge_units: begin func_001F28D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"
DEFINE_DIRECT_BASE_DTOR(std_vector_cSkaTransBLEND_dtor, std_vector_imp_cSkaTransBLEND_dtor)
static inline void merge_flush_func_001F28D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F28D0 */

/* merge_units: begin func_001F2930 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_cSkaTransBLEND_dtor, std_vector_deleter_cSkaTransBLEND_dtor)
static inline void merge_flush_func_001F2930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2930 */

/* merge_units: begin func_001F2990 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern "C" void cSkaSwitch_UpdateNodes();
extern "C" void cSkaNode_PlaybackGroupId();
extern void * const D_004DFBB0[];
void* cArray_cSkaSwitchItem_dtor(void* self, short deleteFlag);
void* cSkaNode_dtor(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O1F2990 { void* vtable; char pad[0x20]; char member[4]; };
extern "C" O1F2990* cSkaSwitch_dtor(O1F2990* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFBB0);
        cArray_cSkaSwitchItem_dtor(self->member, -1);
        cSkaNode_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFBB0[8] = { (void*)0x0, (void*)0x0, (void*)cSkaSwitch_dtor, (void*)cSkaSwitch_UpdateNodes, (void*)cSkaNode_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_001F2990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F2990 */
