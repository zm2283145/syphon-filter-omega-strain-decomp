/*
 * main/guiTextArrayWidget: range (2 files, 004264C0-004264D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_004264C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */


int* func_004264C0(PtrVec* v, int i) {
    return v->data + i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004264C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004264C0 */

/* merge_units: begin func_004264D0 */
#pragma push /* merge_units */
extern void* GuiTextArrayWidget_GetCell(void);
extern void* String_CStr(void*);
const unsigned int D_004BF7B0[4] = { 0x0, 0x0, 0x0, 0x0 };
/* Looks up an entry and converts it, else returns the default object. */
void* func_004264D0(void) { void* p = GuiTextArrayWidget_GetCell(); if (p) return String_CStr(p); return ((char*)D_004BF7B0); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004264D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004264D0 */
