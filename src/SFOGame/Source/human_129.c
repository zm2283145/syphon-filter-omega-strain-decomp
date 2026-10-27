/*
 * SFOGame/Source/human: 1 file, 001B97B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B97B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_004EEE88;

/* Serialize: write the one-byte payload to the network stream. */
void cEquipGogglesMsg_Pack(ByteMsg* msg) {
    *D_005061D0 = msg->b0;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cEquipGogglesMsg_v05(void) {
    return D_004EEE88;
}
static inline void merge_flush_func_001B97B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B97B0 */
