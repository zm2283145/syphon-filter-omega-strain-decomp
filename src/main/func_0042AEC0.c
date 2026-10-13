/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_005724B0;
extern int func_002EAD30(void* callback);
extern int func_002EC4F8(void);
extern int DME_AddGameAddress(int, int);

/* Sets D_005724B0 to 3 and installs DME_AddGameAddress via func_002EAD30; falls back to func_002EC4F8 on failure. */
int func_0042AEC0(void) {
    int ret;

    D_005724B0 = 3;
    ret = func_002EAD30(DME_AddGameAddress);
    if (ret == 0) {
        ret = func_002EC4F8();
    }
    return ret;
}
