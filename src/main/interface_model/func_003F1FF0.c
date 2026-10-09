/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

/* Reads two floats from a stream cursor. */
Vec2f* func_003F1FF0(Vec2f* dst, float** cursor) {
    dst->x = *(*cursor)++;
    dst->y = *(*cursor)++;
    return dst;
}
