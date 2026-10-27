/*
 * Libs/SFOLib/Source/message: 1 file, 003C9B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_3C9B20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

Word* func_003C9B20(Word* self, int value) {
    self->value = value;
    return self;
}

void* func_003C9B30(char* self) {
    return self + 4;
}

void* func_003C9B40(void* self) {
    return self;
}
static inline void merge_flush_message_3C9B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_3C9B20 */
