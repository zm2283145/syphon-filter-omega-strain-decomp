/*
 * lib/medius: 2 files, 00323458-003234B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00323458 */
extern void func_00322E70(int, int, int);
extern void func_00322B40(int, int, int);
void func_00323458(int a, int b, int n)
{
    int h = n / 2;
    func_00322E70(a, b, h);
    func_00322B40(a, b, h);
}
/* merge_units: end func_00323458 */

/* merge_units: begin func_003234B0 */
extern void func_00322C68(int, int, int);
void func_003234B0(int a, int b, int n)
{
    int h = n / 2;
    func_00322C68(a, b, h);
    func_00322E70(b, a, h);
}
/* merge_units: end func_003234B0 */
