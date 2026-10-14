/*
 * lib/libkernl: 4 files, 0010DC40-0010DD78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DC40 */
extern int func_001161A0(void);
extern int func_001161F8(void);
extern int func_0010CEB0(int);
int Alloc_Lock(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) func_001161A0();
    r = func_0010CEB0(a);
    __asm__ volatile("sync");
    if (s) func_001161F8();
    return r;
}
/* merge_units: end func_0010DC40 */

/* merge_units: begin func_0010DCA8 */
extern int func_0010CEA0(int);
int Alloc_Unlock(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) func_001161A0();
    r = func_0010CEA0(a);
    __asm__ volatile("sync");
    if (s) func_001161F8();
    return r;
}
/* merge_units: end func_0010DCA8 */

/* merge_units: begin func_0010DD10 */
extern int func_0010CED0(int);
int func_0010DD10(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) func_001161A0();
    r = func_0010CED0(a);
    __asm__ volatile("sync");
    if (s) func_001161F8();
    return r;
}
/* merge_units: end func_0010DD10 */

/* merge_units: begin func_0010DD78 */
extern int func_0010CEC0(int);
int func_0010DD78(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) func_001161A0();
    r = func_0010CEC0(a);
    __asm__ volatile("sync");
    if (s) func_001161F8();
    return r;
}
/* merge_units: end func_0010DD78 */
