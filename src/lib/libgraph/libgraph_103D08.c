/*
 * lib/libgraph: 2 files, 00103D08-00103D40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00103D08 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void memclr(signed char *arg0, int arg1) {
    int var_v0;
    signed char *var_a0;

    var_a0 = arg0;
    var_v0 = arg1 - 1;
    if (arg1 != 0) {
        do {
            *var_a0 = 0;
            var_v0 -= 1;
            var_a0 += 1;
        } while (var_v0 != -1);
    }
}
/* merge_units: end func_00103D08 */

/* merge_units: begin func_00103D40 */
#include "types.h"
const unsigned int D_00485EE0[10] = { 0x10008000, 0x10009000, 0x1000A000, 0x1000B000, 0x1000B400, 0x1000C000, 0x1000C400, 0x1000C800, 0x1000D000, 0x1000D400 };

int sceDmaGetChan(unsigned int arg0)
{
    if (arg0 < 10) {
        return ((int*)D_00485EE0)[arg0];
    }
    return 0;
}
/* merge_units: end func_00103D40 */
