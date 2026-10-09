/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_004EEEF0;
extern void func_00282020(int);

/* Serialize: write the word argument, then one byte. */
void cNetMeleeAttackMsg_v04(ArgMsg* msg) {
    func_00282020(msg->arg0);
    *D_005061D0 = msg->arg1;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetMeleeAttackMsg_v05(void) {
    return D_004EEEF0;
}
