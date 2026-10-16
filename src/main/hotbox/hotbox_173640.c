/*
 * main/hotbox: 3 files, 00173640-001737B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00173640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern void func_003CE7D0(cGOBJ* obj);
extern void func_003CE810(cGOBJ* obj);

void func_00173640(void) {
}

void func_00173650(void) {
}

void* Hotbox_GetBounds(char* self) {
    return self + 112;
}

/* Set the object's +0x2C flag. */
void Hotbox_Enable_173670(cGOBJ* obj) {
    obj->unk2C = 1;
}

/* Clear the object's +0x2C flag. */
void func_00173680(cGOBJ* obj) {
    obj->unk2C = 0;
}

void func_00173690(cGOBJ* obj) {
    obj->unk2C = 1;
    func_003CE810(obj);
}

void func_001736A0(cGOBJ* obj) {
    obj->unk2C = 0;
    func_003CE7D0(obj);
}

int func_001736B0(void) {
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00173640 */

/* merge_units: begin func_001736C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_001736C0)
#pragma pop /* merge_units */
/* merge_units: end func_001736C0 */

/* merge_units: begin func_001737B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_001737B0, func_00173810)
#pragma pop /* merge_units */
/* merge_units: end func_001737B0 */
