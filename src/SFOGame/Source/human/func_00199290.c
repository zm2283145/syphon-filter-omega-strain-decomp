/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message (de)serializers. */
extern signed char* D_005061D0;

/* Read one signed byte from the network stream and advance. */
int NetStream_ReadS8(void) {
    signed char* p;

    p = D_005061D0;
    D_005061D0 = p + 1;
    return *p;
}
