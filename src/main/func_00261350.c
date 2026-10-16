/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004F82A0;

void HudRadar_SetPlayerId(Word* src) {
    D_004F82A0 = src->value;
}
