/*
 * SFOGame/Source/hud: 1 file, 00244A80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00244A80 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cAnimator_AnimateTo(float, int);                          
int viBufGetTs(float, int);                          

#pragma opt_common_subs off
void cHud_ChangeGadgetState(int arg0, int arg1, int arg2) {
    int temp_a0;
    int temp_s1;

    temp_a0 = F_(arg0, 0x74, int);
    if (temp_a0 != 0) {
        temp_s1 = ((arg1 & 0xFF) * 0x1E) + 0xD2;
        if (arg2 == 0) {
            viBufGetTs((float) (temp_s1 + 0xA), temp_a0);
            cAnimator_AnimateTo((float) temp_s1, F_(arg0, 0x74, int));
            return;
        }
        viBufGetTs((float) temp_s1, temp_a0);
        cAnimator_AnimateTo((float) (temp_s1 + 0xA), F_(arg0, 0x74, int));
    }
}
static inline void merge_flush_func_00244A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00244A80 */
