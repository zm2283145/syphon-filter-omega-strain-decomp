/*
 * lib/medius: 2 files, 00306030-00306078
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306030 */
typedef struct { int sec; int usec; } ScfTime;
extern int rt_time_get_base_diff(ScfTime *tv);
#define SCF_TIME_GET(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *out) { ScfTime tv; int ret = 2; if (out == 0) return ret; ret = rt_time_get_base_diff(&tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_GET(rt_time_get_msecs, rt_time_timestamp_to_msecs)
/* merge_units: end func_00306030 */

/* merge_units: begin func_00306078 */
SCF_TIME_GET(rt_time_get_secs, TimeVal_ToSeconds)
/* merge_units: end func_00306078 */
