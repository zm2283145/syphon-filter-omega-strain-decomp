/*
 * Libs/SFOLib/Source/ska: 2 files, 003ABA60-003ABAC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ABA60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(cSkaAnimEventMessage_dtor, D_004DFBD0, cMessage_dtor)
static inline void merge_flush_func_003ABA60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ABA60 */

/* merge_units: begin func_003ABAC0 */
#pragma push /* merge_units */
typedef struct { char data[0xF8]; } DequeItem;
typedef struct { unsigned int mapSize; int unk4; unsigned int start; DequeItem** map; unsigned int first; unsigned int count; } Deque;

/* Returns a pointer to the last element of a block-based deque (8 items per block). */
DequeItem* std_deque_deleter_common_cSkaSystem_Request_back_void(Deque* self)
{
    unsigned int index = self->first + self->count - 1;
    return &self->map[(self->start + (index >> 3)) % self->mapSize][index & 7];
}
static inline void merge_flush_func_003ABAC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ABAC0 */
