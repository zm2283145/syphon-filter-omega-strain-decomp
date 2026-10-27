/*
 * SFOGame/Source/NetGenerator: 1 file, 002C7BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin gameFrontEnd_2C7BA0 */
#pragma push /* merge_units */
#include "types.h"

extern char D_0051EE88[];
extern char D_005723C8[];
extern int NetGetObject(int, int);

int tNetGenerator_NetGeneratorCreationCallback(void) {
    int loc[2];
    int a0, a1, v0, v1;
    int cond;

    v0 = *(unsigned char*)(char*)D_005723C8;
    cond = v0 != 0;
    v0 = 0 + 1;
    if (cond) goto L002C7BC0;
    *(char*)(char*)D_005723C8 = v0;
L002C7BC0:;
    a0 = (int)loc;
    v0 = NetGetObject(a0, a1);
    cond = v0 != 0;
    if (cond) goto L002C7BE0;
    v1 = *(int*)(char*)loc;
    v1 = *(int*)((char*)v1 + 28);
    *(int*)(char*)D_0051EE88 = v1;
L002C7BE0:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_gameFrontEnd_2C7BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end gameFrontEnd_2C7BA0 */
