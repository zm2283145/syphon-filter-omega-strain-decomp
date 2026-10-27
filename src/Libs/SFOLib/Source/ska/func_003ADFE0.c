/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

float cSkaPlaybackGroup_cPlaybackPosWithHistory_Curr(char* self) {
    return *(float*)(self + 4);
}
