/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Reads unk3C into out (0 when obj is null); returns 1 for a null out, 2 for a null obj. */
int rt_udp_get_aggregation_interval(RtObj3C* obj, int* out) {
    int result = 1;

    if (out != 0) {
        *out = 0;
        result = 2;
        if (obj != 0) {
            result = 0;
            *out = obj->unk3C;
        }
    }
    return result;
}
