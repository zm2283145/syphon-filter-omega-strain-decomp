/*
 * Libs/SFOLib/Source/guiTextEditWidget: 1 file, 0041AE20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiManager_41AE20 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_r8;
static inline void Set(V4_r8* o, float x, float y, float z, float w) { o->x = x; o->y = y; o->z = z; o->w = w; }
void InterpolateColor_tRGBAR_tRGBAR_float_2(V4_r8* out, V4_r8* a, V4_r8* b, float t)
{
    Set(out, a->x + t * (b->x - a->x), a->y + t * (b->y - a->y), a->z + t * (b->z - a->z), a->w + t * (b->w - a->w));
}
static inline void merge_flush_guiManager_41AE20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiManager_41AE20 */
