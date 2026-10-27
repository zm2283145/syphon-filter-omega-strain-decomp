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

extern void cGOBJ_NetDeactivate(cGOBJ* obj);
extern void cGOBJ_NetActivate(cGOBJ* obj);

void cHotbox_Init(void) {
}

void cHotbox_Load(void) {
}

void* cHotbox_GetBBox(char* self) {
    return self + 112;
}

/* Set the object's +0x2C flag. */
void cHotbox_NetEnable(cGOBJ* obj) {
    obj->unk2C = 1;
}

/* Clear the object's +0x2C flag. */
void cHotbox_NetDisable(cGOBJ* obj) {
    obj->unk2C = 0;
}

void cHotbox_NetActivate(cGOBJ* obj) {
    obj->unk2C = 1;
    cGOBJ_NetActivate(obj);
}

void cHotbox_NetDeactivate(cGOBJ* obj) {
    obj->unk2C = 0;
    cGOBJ_NetDeactivate(obj);
}

int cHotbox_IsNetworked(void) {
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00173640 */

/* merge_units: begin func_001736C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cHotboxPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001736C0 */

/* merge_units: begin func_001737B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_cHotboxPtr_dtor, std_vector_imp_cHotboxPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001737B0 */
