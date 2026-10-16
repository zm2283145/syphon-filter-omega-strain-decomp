/*
 * main/gameSound: range (2 files, 001C93F0-001C9400)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001C93F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void SoundMgr_OnBankUserData(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C93F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C93F0 */

/* merge_units: begin func_001C9400 */
#pragma push /* merge_units */
typedef struct State44 {
    char pad000[0x44];
    unsigned char state; /* 0x44 */
    char pad045[0x133];
    unsigned char ready; /* 0x178 */
} State44;

/* Advances state 3 to 4 once the ready flag is set. */
void SoundMgr_OnLpdLoaded(void* unused, State44* obj) {
    if (obj->state == 3 && obj->ready) {
        obj->state = 4;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9400 */
