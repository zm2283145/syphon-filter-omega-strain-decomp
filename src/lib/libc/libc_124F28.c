/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00499E10[];
extern char D_00499E18[];
static void * const dat_00499DE0[4] = { (void*)D_00499E18, (void*)D_00499E10, (void*)D_00499E10, (void*)D_00499E10 };

int Newlib_LocaleconvR(void) {
    return (int)((char*)dat_00499DE0);
}
