/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_004EEEA0;

/* Serialize: write the second byte, then the first. */
void cNetSetFlagMsg_v04(ByteMsg* msg) {
    *D_005061D0 = msg->b1;
    D_005061D0 = D_005061D0 + 1;
    *D_005061D0 = msg->b0;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetSetFlagMsg_v05(void) {
    return D_004EEEA0;
}
