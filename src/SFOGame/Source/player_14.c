/*
 * SFOGame/Source/player: 1 file, 00176EB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00176EB0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Container;

extern void std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(int* out, Container* self, int* value, int** where);

/* Calls std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter with the container's +8 value and a pointer to its +4 field. */
void cLList_cSafePtr_cGOBJ_Clear(Container* self)
{
    int* where;
    int value;
    int result;
    where = &self->unk4;
    value = self->unk8;
    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&result, self, &value, &where);
}
static inline void merge_flush_func_00176EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00176EB0 */
