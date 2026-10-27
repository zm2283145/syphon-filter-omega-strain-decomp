/*
 * main/GuiMissionStatList: 2 files, 00351230-00351320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351230 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "owned_buffer8_dtor_deep.h"

extern "C" { char D_004BACB8[] = "allocator.hh"; }
DEFINE_OWNED_BUFFER8_DTOR_MID(std_vector_imp_StatType_1_dtor, D_004BACB8)
#pragma pop /* merge_units */
/* merge_units: end func_00351230 */

/* merge_units: begin func_00351320 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy all elements (0x5C bytes each, last first) and clear the count. */
struct E351320 { int words[0x5C / 4]; };
struct V351320 { int capacity; unsigned int count; E351320* data; };
extern "C" {
void* MissionStats_dtor(void* self, short deleteFlag);
void std_vector_deleter_MissionStats_clear(V351320* v);
}
void std_vector_deleter_MissionStats_clear(V351320* v)
{
    E351320* first = v->data;
    E351320* last = first + v->count;
    while (first < last) {
        --last;
        MissionStats_dtor(last, -1);
    }
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00351320 */
