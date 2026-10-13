/*
 * main/guiManager: 2 files, 004191D0-00419260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004191D0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004133B0(char *, int *, signed char *);                
int func_00419110(int, int, signed char *, int);               
extern char D_00571DC0;

int func_004191D0(int arg0, signed char *arg1, int arg2) {
    int sp4C;
    int var_v0;

    if ((arg1 == NULL) || (*arg1 == 0)) {
        return 0;
    }
    if (func_004133B0(&D_00571DC0, &sp4C, arg1) != 0) {
        var_v0 = func_00419110(arg0, sp4C, arg1, arg2);
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004191D0 */

/* merge_units: begin func_00419260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiManager.cc. Functions are named by address
 * until real names are known.
 */


extern int func_00419270(void* self);

int func_00419260(void* self) {
    return func_00419270(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_00419260 */
