/*
 * main/GuiKeyboard: 2 files, 0032D950-0032DA80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032D950 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004B8D10[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(func_0032D950, D_004B8D10)
#pragma pop /* merge_units */
/* merge_units: end func_0032D950 */

/* merge_units: begin func_0032DA80 */
#pragma push /* merge_units */
#include "word_vector_erase.h"

/* Erase a range from a vector of 4-byte elements. */
DEFINE_WORD_VECTOR_ERASE(func_0032DA80)
#pragma pop /* merge_units */
/* merge_units: end func_0032DA80 */
