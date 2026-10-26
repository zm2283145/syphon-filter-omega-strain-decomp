/*
 * lib/libkernl: 2 files, 0010F350-0010F388
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010F350 */
extern int _printf(const char* fmt, char* ap);
int kprintf(const char* fmt, ...)
{
    char* ap;
    ap = (char*)__builtin_next_arg(fmt) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0);
    return _printf(fmt, ap);
}
/* merge_units: end func_0010F350 */

/* merge_units: begin func_0010F388 */
extern void deci2Putchar(void);
extern void *D_004861A4;
int scePrintf(const char *fmt, ...)
{
    char *ap;
    void *old;
    int r;
    old = D_004861A4;
    D_004861A4 = deci2Putchar;
    ap = (char *)__builtin_next_arg(fmt) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0);
    r = _printf(fmt, ap);
    D_004861A4 = old;
    return r;
}
/* merge_units: end func_0010F388 */
