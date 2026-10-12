/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Read a scalar (used for the physical mass at actor +0x2E0, research
 * ACTOR_RESPONSE_PROBES.md). */
float Physical_GetMass(float* value) {
    return value[0];
}
