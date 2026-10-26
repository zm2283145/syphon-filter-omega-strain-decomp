/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00504080[];
extern char D_005040C0[];
extern int sceNetcnfifInit(void);
extern int sce_call_rpc(int, int, int);

int sceNetcnfifGetAddr(void) {
    int tmp2;

    sceNetcnfifInit();
    tmp2 = sce_call_rpc((int)D_00504080, (int)D_005040C0, 100);
    return tmp2;
}
