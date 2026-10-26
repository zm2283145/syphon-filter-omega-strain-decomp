/*
 * main/GuiMissionStatList: 2 files, 003517B0-00351810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003517B0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char unused; } Alloc;
typedef struct { char data[0x14]; } Elem;
typedef struct { int unk0; int count; Elem* data; unsigned char flag; } Vec;
extern void std_vector_imp_StatsRequirement_do_assign(Vec* self, Elem* first, Elem* last, Alloc alloc);

/* Copy-assigns a vector of 20-byte elements and its flag byte. */
Vec* cArray_StatsRequirement_opAssign(Vec* self, Vec* other)
{
    Alloc alloc;
    if (self != other) {
        std_vector_imp_StatsRequirement_do_assign(self, other->data, other->data + other->count, alloc);
    }
    self->flag = other->flag;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003517B0 */

/* merge_units: begin func_00351810 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

extern "C" { char D_004BABD0[] = "vector::insert length error\n"; }
DEFINE_VECTOR_INSERT_FILL_OBJ(std_vector_imp_MissionStats_insert, 0x5C, 0x10B216, 0x8590B, D_004BABD0, D_004BAC98, 0x5C, Mem_PlacementNew, MissionStats_ctor, std_copy_backward_MissionStats_copy_backward, std_fill_n_MissionStats_int_fill_n, std_swap_vectordeleterR_vectordeleterR_37, std_vector_deleter_MissionStats_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00351810 */
