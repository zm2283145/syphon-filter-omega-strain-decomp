/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_004EF038;

/* Serialize: write the one-byte payload. */
void cNetForceHolsterMsg_v04(FlagMsg* msg) {
    *D_005061D0 = msg->value;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetForceHolsterMsg_v05(void) {
    return D_004EF038;
}
