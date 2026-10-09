/*
 * Matched functions (byte-identical with the retail executable).
 * cTimerExpiredMsg serializer.
 */

#include "types.h"
#include "gameGobjController_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;

/* Serialize: writes the timer id as one byte. */
void cTimerExpiredMsg_v04(int msg) {
    /* reusing the parameter for the value keeps the original full-word load */
    msg = ((cTimerExpiredMsg*)msg)->timerId;
    *D_005061D0 = msg;
    D_005061D0 = D_005061D0 + 1;
}
