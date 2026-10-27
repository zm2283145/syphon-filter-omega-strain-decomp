/*
 * SFOGame/Source/weapon: 3 files, 00147A00-00147A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147A00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00147A00(void) {
}

void func_00147A10(void) {
}
static inline void merge_flush_func_00147A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147A00 */

/* merge_units: begin func_00147A20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004D92A0[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAISoundSystemMessage_Clone_void_2, 0x30, "ai.hh", 0x14C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004D92A0;
    F(char, 0x24) = S(char, 0x24);
    F(char, 0x25) = S(char, 0x25);
    F(float, 0x28) = S(float, 0x28);
    F(float, 0x2C) = S(float, 0x2C);
MSG_CLONE_END
static inline void merge_flush_func_00147A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147A20 */

/* merge_units: begin func_00147B40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAISoundSystemMessage_dtor, D_004D92A0, cMessage_dtor)
static inline void merge_flush_func_00147B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147B40 */
