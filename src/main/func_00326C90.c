/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Network stream cursor shared by message serializers. */
extern unsigned char* D_005061D0;

/* Serialize: write the payload byte. */
void cEnableSuperJumpMsg_v04(EnableSuperJumpMsg* msg) {
    *D_005061D0 = msg->enable;
    D_005061D0 = D_005061D0 + 1;
}
