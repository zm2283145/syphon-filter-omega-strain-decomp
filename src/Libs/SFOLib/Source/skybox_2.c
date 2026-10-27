/*
 * Libs/SFOLib/Source/skybox: 1 file, 003BC270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BC270 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ field setter.
 */

#include "types.h"
#include "skybox_types.h"

void cSKYBOX_GOBJ_Init(cSkyboxGobj* self, int value) {
    self->unk8C = value;
}
static inline void merge_flush_func_003BC270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BC270 */
