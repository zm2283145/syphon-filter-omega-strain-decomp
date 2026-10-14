/*
 * lib/libkernl: 2 files, 0010F350-0010F388
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010F350 */
extern int func_0010ED58(const char* fmt, char* ap);
int func_0010F350(const char* fmt, ...)
{
    char* ap;
    ap = (char*)__builtin_next_arg(fmt) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0);
    return func_0010ED58(fmt, ap);
}
/* merge_units: end func_0010F350 */

/* merge_units: begin func_0010F388 */
extern void func_0010EA70(void);
extern void *D_004861A4;
int scePrintf(const char *fmt, ...)
{
    char *ap;
    void *old;
    int r;
    old = D_004861A4;
    D_004861A4 = func_0010EA70;
    ap = (char *)__builtin_next_arg(fmt) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0);
    r = func_0010ED58(fmt, ap);
    D_004861A4 = old;
    return r;
}
/* merge_units: end func_0010F388 */
