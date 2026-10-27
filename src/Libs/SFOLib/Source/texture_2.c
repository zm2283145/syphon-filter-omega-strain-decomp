/*
 * Libs/SFOLib/Source/texture: 1 file, 003BB010
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin ska_3BB010 */
#pragma push /* merge_units */
#include "types.h"

extern char g_TextureMgr[];
extern int cTexMan_UnlockVram(int, int);

void cUserFrameEnv_Deactivate(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    cond = a1 != 0;
    s0 = a0;
    if (cond) goto L003BB050;
    a0 = *(int*)(char*)g_TextureMgr;
    a1 = *(int*)(char*)s0;
    v0 = cTexMan_UnlockVram(a0, a1);
    a1 = *(int*)((char*)s0 + 4);
    v1 = 0 + -1;
    cond = a1 == v1;
    if (cond) goto L003BB050;
    a0 = *(int*)(char*)g_TextureMgr;
    v0 = cTexMan_UnlockVram(a0, a1);
L003BB050:;
    goto ret;
ret:;
}
static inline void merge_flush_ska_3BB010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end ska_3BB010 */
