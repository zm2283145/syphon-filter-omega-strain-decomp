/*
 * lib/medius: 3 files, 003060D8-00306108
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003060D8 */
#include "types.h"

extern int func_003065D8(int);

int func_003060D8(int a0) {
    return func_003065D8(a0);
}
/* merge_units: end func_003060D8 */

/* merge_units: begin func_003060F0 */
extern int func_00306158(int, int);

int func_003060F0(int a0, int a1) {
    return func_00306158(a0, a1);
}
/* merge_units: end func_003060F0 */

/* merge_units: begin func_00306108 */
typedef struct { int sec; int usec; } ScfTime;
extern int func_003064E0(void *in, ScfTime *tv);
#define SCF_TIME_CONV(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *in, void *out) { ScfTime tv; int ret = 2; if (in == 0) return ret; if (out == 0) return ret; ret = func_003064E0(in, &tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_CONV(func_00306108, TimeVal_ToSeconds)
/* merge_units: end func_00306108 */
