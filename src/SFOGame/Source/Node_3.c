/*
 * SFOGame/Source/Node: 1 file, 0015C280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015C280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Vec4 component getters and cNode_GetLoc.
 */

#include "types.h"
#include "node_types.h"

float cAxisAngle_Angle(Vec4* v) {
    return v->w;
}

float cAxisAngle_Z(Vec4* v) {
    return v->z;
}

float cAxisAngle_Y(Vec4* v) {
    return v->y;
}

float cAxisAngle_X(Vec4* v) {
    return v->x;
}

/* Writes the node translation as a point (w = 1). */
void cNode_GetLoc(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}
static inline void merge_flush_func_0015C280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015C280 */
