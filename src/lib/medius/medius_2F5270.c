/*
 * lib/medius: 3 files, 002F5270-002F5348
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F5270 */
extern int func_0010D050(void);
extern void func_0010CEE0(unsigned short, void *, int);
extern void SleepThread(void);
extern void func_002F5258(void);
void func_002F5270(int a)
{
    int s = func_0010D050();
    func_0010CEE0(a, func_002F5258, s);
    SleepThread();
}
/* merge_units: end func_002F5270 */

/* merge_units: begin func_002F52A8 */
extern void *memset(void *, int, unsigned int);
extern int Net_AllocZeroed(int *, unsigned long);
int func_002F52A8(int *s, unsigned int n, int x)
{
    int r;
    if (s == 0) return 2;
    if (n == 0) return 2;
    memset(s, 0, 0x18);
    r = Net_AllocZeroed(s + 4, n);
    if (r) return 3;
    if (s[4] == 0) return 3;
    s[5] = x;
    s[2] = n;
    s[1] = 0;
    s[3] = 0;
    s[0] = 0;
    return r;
}
/* merge_units: end func_002F52A8 */

/* merge_units: begin func_002F5348 */
extern int func_002FB3C0(int *);
int func_002F5348(int *p)
{
    if (p == 0) return 2;
    if (p[4]) func_002FB3C0(p + 4);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    return 0;
}
/* merge_units: end func_002F5348 */
