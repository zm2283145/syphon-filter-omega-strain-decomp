/*
 * SFOGame/Source/GuiNetAgencyCell: 1 file, 002AEF10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiChatWindow_2AEF10 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
char D_004ABC70[] = "GuiChatWindow"; /* "GuiChatWindow" */

/* GuiChatWindow type check: true when name equals the class name "GuiChatWindow". */
int GuiChatWindow_IsClass(void* self, const char* name) {
    return strcmp(D_004ABC70, name) == 0;
}
static inline void merge_flush_GuiChatWindow_2AEF10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiChatWindow_2AEF10 */
