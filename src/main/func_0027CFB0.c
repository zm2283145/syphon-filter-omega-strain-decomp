/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00504080[];
extern char D_005040C0[];
extern int sceNetcnfifInit(void);
extern int sce_call_rpc(void*, void*, int);

int sceNetcnfifFreeWorkarea(void) {
    sceNetcnfifInit();
    return sce_call_rpc(D_00504080, D_005040C0, 102);
}
