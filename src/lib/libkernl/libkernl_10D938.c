/*
 * lib/libkernl: 2 files, 0010D938-0010D960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010D938 */
#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern void Newlib_SysExit(int arg);

/* Handles command 1 by forwarding its argument to Newlib_SysExit; always returns 0. */
int Newlib_SysKill(int cmd, int arg)
{
    if (cmd == 1)
        Newlib_SysExit(arg);
    return 0;
}
/* merge_units: end func_0010D938 */

/* merge_units: begin func_0010D960 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int Newlib_Errno(void);

int func_0010D960(void) {
    int tmp0;

    tmp0 = Newlib_Errno();
    *(int*)((char*)tmp0) = 5;
    return -1;
}

int func_0010D988(void) {
    int tmp0;

    tmp0 = Newlib_Errno();
    *(int*)((char*)tmp0) = 5;
    return -1;
}
/* merge_units: end func_0010D960 */
