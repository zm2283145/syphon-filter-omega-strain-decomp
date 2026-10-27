/*
 * lib/libkernl: 4 files, 0010DC40-0010DD78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DC40 */
extern int DIntr(void);
extern int EIntr(void);
extern int _DisableIntc(int);
int Alloc_Lock(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    r = _DisableIntc(a);
    __asm__ volatile("sync");
    if (s) EIntr();
    return r;
}
/* merge_units: end func_0010DC40 */

/* merge_units: begin func_0010DCA8 */
extern int _EnableIntc(int);
int EnableIntc(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    r = _EnableIntc(a);
    __asm__ volatile("sync");
    if (s) EIntr();
    return r;
}
/* merge_units: end func_0010DCA8 */

/* merge_units: begin func_0010DD10 */
extern int _DisableDmac(int);
int DisableDmac(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    r = _DisableDmac(a);
    __asm__ volatile("sync");
    if (s) EIntr();
    return r;
}
/* merge_units: end func_0010DD10 */

/* merge_units: begin func_0010DD78 */
extern int _EnableDmac(int);
int EnableDmac(int a)
{
    int s, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    r = _EnableDmac(a);
    __asm__ volatile("sync");
    if (s) EIntr();
    return r;
}
/* merge_units: end func_0010DD78 */
