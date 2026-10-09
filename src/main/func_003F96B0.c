/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Archive* Archive_Open(int, int, int, int);

/* Opens an archive and sets the byte at +0x168 on the returned handle. */
L4Archive* func_003F96B0(int a0, int a1, int a2) {
    L4Archive* ar = Archive_Open(a0, a1, a2, 0);

    ar->unk168 = 1;
    return ar;
}
