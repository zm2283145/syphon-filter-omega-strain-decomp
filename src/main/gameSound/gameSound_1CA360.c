/*
 * main/gameSound: range (2 files, 001CA360-001CA470)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop
#include "net_write_two_words.h"

/* merge_units: begin func_001CA360 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
char D_0049F708[] = "gameSound.cc";
}
DEFINE_NET_MSG_CLONE(cStopAllQuipsMsg_v01, 0x24, D_0049F708, 0x6D0, D_004DAC50, (void)0)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001CA360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001CA360 */

/* merge_units: begin func_001CA470 */
#pragma push /* merge_units */
/* Serialize the two 32-bit message fields. */
DEFINE_NET_WRITE_TWO_WORDS(cPlayQuipMsg_v04)
#pragma pop /* merge_units */
/* merge_units: end func_001CA470 */
