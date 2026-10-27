/*
 * SFOGame/Source/GuiAgentCreate: 1 file, 0028CD70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028CD70 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    char pad[0x70];
    __int128 save70;
    char pad2[0x2C04 - 0x80];
    int keep;
    char pad3[0x2C10 - 0x2C08];
    signed char preset;
    char pad4[0x2DF0 - 0x2C11];
} __attribute__((aligned(16))) S28C;
extern void cMan_SetBoneSet(S28C* s, int preset);
static inline void QCopy_28C(void* d0, void* s0) { int n = 0x2DF; void* s = s0; void* d = d0;
    asm {
        .set noreorder
        nop
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
void GuiAgentCreate_CloneMan(void* unused, S28C* s, S28C* src)
{
    __int128 q = s->save70;
    int k = s->keep;
    QCopy_28C(s, src);
    s->keep = k;
    cMan_SetBoneSet(s, s->preset);
    s->save70 = q;
}
static inline void merge_flush_func_0028CD70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028CD70 */
