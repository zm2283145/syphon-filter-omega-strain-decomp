/*
 * main/GuiMissionStatistics: 5 files, 0034F720-0034F8A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034F720 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor: nested member at 0x4C, then the base destructor. */
extern "C" {
void operator_delete(void* allocation);
void* func_00351070(void* self, short deleteFlag);
void* String_Dtor(void* self, short deleteFlag);
void* func_0034F720(void* self, short deleteFlag);
}
void* func_0034F720(void* self, short deleteFlag)
{
    if (self) {
        char* m = (char*)self + 0x4C;
        if (m) {
            if (m) {
                if (m)
                    func_00351070(m, 0);
            }
        }
        if (self)
            String_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034F720 */

/* merge_units: begin func_0034F7A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member_dtor_chain.h"

DEFINE_MEMBER_DTOR_CHAIN(func_0034F7A0, func_00351070)
#pragma pop /* merge_units */
/* merge_units: end func_0034F7A0 */

/* merge_units: begin func_0034F810 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int func_0034F900(FlaggedRel*);

/* FlaggedRel constructor. */
FlaggedRel* func_0034F810(FlaggedRel* self) {
    func_0034F900(self);
    self->unk0C = 1;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034F810 */

/* merge_units: begin func_0034F840 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(func_0034F840, func_00351070)
#pragma pop /* merge_units */
/* merge_units: end func_0034F840 */

/* merge_units: begin func_0034F8A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

DEFINE_DIRECT_BASE_DTOR(func_0034F8A0, func_00351070)
#pragma pop /* merge_units */
/* merge_units: end func_0034F8A0 */
