/*
 * lib/medius: 3 files, 003060D8-00306108
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003060D8 */
#include "types.h"

extern int rt_time_platform_get_time_stamp(int);

int rt_time_get_time_stamp(int a0) {
    return rt_time_platform_get_time_stamp(a0);
}
/* merge_units: end func_003060D8 */

/* merge_units: begin func_003060F0 */
extern int rt_time_elapsed_msecs(int, int);

int rt_time_elapsed(int a0, int a1) {
    return rt_time_elapsed_msecs(a0, a1);
}
/* merge_units: end func_003060F0 */

/* merge_units: begin func_00306108 */
typedef struct { int sec; int usec; } ScfTime;
extern int rt_time_elapsed_timestamp(void *in, ScfTime *tv);
#define SCF_TIME_CONV(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *in, void *out) { ScfTime tv; int ret = 2; if (in == 0) return ret; if (out == 0) return ret; ret = rt_time_elapsed_timestamp(in, &tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_CONV(rt_time_elapsed_secs, rt_time_timestamp_to_secs)
/* merge_units: end func_00306108 */
