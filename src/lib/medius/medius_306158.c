/*
 * lib/medius: 3 files, 00306158-003061F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306158 */
typedef struct { int sec; int usec; } ScfTime;
extern int func_003064E0(void *in, ScfTime *tv);
#define SCF_TIME_CONV(name, conv) extern int conv(ScfTime *tv, void *out); int name(void *in, void *out) { ScfTime tv; int ret = 2; if (in == 0) return ret; if (out == 0) return ret; ret = func_003064E0(in, &tv); if (ret != 0) return ret; return conv(&tv, out); }
SCF_TIME_CONV(func_00306158, func_003063D0)
/* merge_units: end func_00306158 */

/* merge_units: begin func_003061A8 */
SCF_TIME_CONV(func_003061A8, func_00306440)
/* merge_units: end func_003061A8 */

/* merge_units: begin func_003061F8 */
extern int func_003060C0(ScfTime *tv);
extern int func_003060F0(ScfTime *tv, unsigned int *elapsed);
int func_003061F8(unsigned int ms)
{
    ScfTime tv;
    unsigned int el = 0;
    int r;
    r = func_003060C0(&tv);
    if (r != 0) return r;
    while (el < ms) {
        r = func_003060F0(&tv, &el);
        if (r != 0) return r;
    }
    return 0;
}
/* merge_units: end func_003061F8 */
