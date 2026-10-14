/*
 * lib/medius: 2 files, 00306030-00306078
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306030 */
typedef struct { int sec; int usec; } ScfTime;
extern int func_00306488(ScfTime *tv);
#define SCF_TIME_GET(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *out) { ScfTime tv; int ret = 2; if (out == 0) return ret; ret = func_00306488(&tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_GET(func_00306030, func_003063D0)
/* merge_units: end func_00306030 */

/* merge_units: begin func_00306078 */
SCF_TIME_GET(func_00306078, TimeVal_ToSeconds)
/* merge_units: end func_00306078 */
