/*
 * lib/libkernl: 4 files, 0010DDE0-0010DE40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DDE0 */
extern void _iEnableIntc(void);
void iEnableIntc(void)
{
    _iEnableIntc();
    __asm__ __volatile__("sync");
}
/* merge_units: end func_0010DDE0 */

/* merge_units: begin func_0010DE00 */
extern void _iDisableIntc(void);
void iDisableIntc(void)
{
    _iDisableIntc();
    __asm__ __volatile__("sync");
}
/* merge_units: end func_0010DE00 */

/* merge_units: begin func_0010DE20 */
extern void _iEnableDmac(void);
void iEnableDmac(void)
{
    _iEnableDmac();
    __asm__ __volatile__("sync");
}
/* merge_units: end func_0010DE20 */

/* merge_units: begin func_0010DE40 */
extern void _iDisableDmac(void);
void iDisableDmac(void)
{
    _iDisableDmac();
    __asm__ __volatile__("sync");
}
/* merge_units: end func_0010DE40 */
