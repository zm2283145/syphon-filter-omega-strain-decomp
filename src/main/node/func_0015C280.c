/*
 * Matched functions (byte-identical with the retail executable).
 * Vec4 component getters and Node_GetTranslation.
 */

#include "types.h"
#include "node_types.h"

float func_0015C280(Vec4* v) {
    return v->w;
}

float func_0015C290(Vec4* v) {
    return v->z;
}

float func_0015C2A0(Vec4* v) {
    return v->y;
}

float func_0015C2B0(Vec4* v) {
    return v->x;
}

/* Writes the node translation as a point (w = 1). */
void Node_GetTranslation(Vec4* out, cNode* node) {
    float z = node->translation.z;
    float y = node->translation.y;
    float x = node->translation.x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}
