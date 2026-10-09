/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "inventory_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_00587FC8;      /* cNetInventoryMsg message type id */

/* Serialize: 16-bit value (low byte first), then two bytes. */
void cNetInventoryMsg_v04(cNetInventoryMsg* msg) {
    short v = msg->unk24;

    *D_005061D0 = v;
    D_005061D0 = D_005061D0 + 1;
    *D_005061D0 = v >> 8;
    D_005061D0 = D_005061D0 + 1;
    *D_005061D0 = msg->unk26;
    D_005061D0 = D_005061D0 + 1;
    *D_005061D0 = msg->unk27;
    D_005061D0 = D_005061D0 + 1;
}

int cNetInventoryMsg_v05(void) {
    return D_00587FC8;
}
