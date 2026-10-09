/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

/* Reads a float and then a 3-float vector from a stream cursor.
 * (Local declaration order matters for register allocation.) */
FloatVec3* func_003F3DF0(FloatVec3* dst, float** cursor) {
    float* p;
    float x, z, y;

    x = *(*cursor)++;
    dst->f = x;
    p = *cursor;
    *cursor = p + 3;
    y = p[1];
    z = p[2];
    x = p[0];
    dst->v[0] = x;
    dst->v[1] = y;
    dst->v[2] = z;
    return dst;
}

/* Reads a float and then a 3-float vector from a stream cursor.
 * (Local declaration order matters for register allocation.) */
FloatVec3* func_003F3E30(FloatVec3* dst, float** cursor) {
    float* p;
    float x, z, y;

    x = *(*cursor)++;
    dst->f = x;
    p = *cursor;
    *cursor = p + 3;
    y = p[1];
    z = p[2];
    x = p[0];
    dst->v[0] = x;
    dst->v[1] = y;
    dst->v[2] = z;
    return dst;
}
