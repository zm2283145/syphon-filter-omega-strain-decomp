/*
 * main/MoviePlayer: 2 files, 003F9520-003F9530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_003F9520(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F9520 */

/* merge_units: begin func_003F9530 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int String_CompareNoCase(int, int);
int Hog_Unload(int);
#if 0 /* merge_units */
int func_003F9520(int);
#endif /* merge_units */
#define func_003F9520(a0) ((int)func_003F9520((void *)(a0))) /* merge_units */

int func_003F95E0(int *, int);
int func_003F95F0(int);

void ArchiveList_CloseNamed(int arg0, int arg1) {
    int sp4C;
    int var_s0;

    var_s0 = F_(func_003F9520(arg0 + 4), 0x4, int);
    func_003F95E0(&sp4C, func_003F95F0(arg0));
    if (var_s0 != sp4C) {
        do {
            if (String_CompareNoCase(var_s0 + 8, arg1) == 0) {
                Hog_Unload(var_s0 + 8);
            }
            var_s0 = F_(var_s0, 0x4, int);
            func_003F95E0(&sp4C, func_003F95F0(arg0));
        } while (var_s0 != sp4C);
    }
}
#undef func_003F9520 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9530 */
