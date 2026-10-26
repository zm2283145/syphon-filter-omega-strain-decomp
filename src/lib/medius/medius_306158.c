/*
 * lib/medius: 3 files, 00306158-003061F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306158 */
typedef struct { int sec; int usec; } ScfTime;
extern int rt_time_elapsed_timestamp(void *in, ScfTime *tv);
#define SCF_TIME_CONV(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *in, void *out) { ScfTime tv; int ret = 2; if (in == 0) return ret; if (out == 0) return ret; ret = rt_time_elapsed_timestamp(in, &tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_CONV(rt_time_elapsed_msecs, rt_time_timestamp_to_msecs)
/* merge_units: end func_00306158 */

/* merge_units: begin func_003061A8 */
SCF_TIME_CONV(rt_time_elapsed_usecs, rt_time_timestamp_to_usecs)
/* merge_units: end func_003061A8 */

/* merge_units: begin func_003061F8 */
extern int rt_time_start(ScfTime *tv);
extern int rt_time_elapsed(ScfTime *tv, unsigned int *elapsed);
int rt_time_delay(unsigned int ms)
{
    ScfTime tv;
    unsigned int el = 0;
    int r;
    r = rt_time_start(&tv);
    if (r != 0) return r;
    while (el < ms) {
        r = rt_time_elapsed(&tv, &el);
        if (r != 0) return r;
    }
    return 0;
}
/* merge_units: end func_003061F8 */
