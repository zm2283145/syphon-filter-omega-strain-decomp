/*
 * lib/medius: 3 files, 002F5270-002F5348
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F5270 */
extern int GetThreadId(void);
extern void SetAlarm(unsigned short, void *, int);
extern void SleepThread(void);
extern void delay_wakeup(void);
void WaitTimeMs(int a)
{
    int s = GetThreadId();
    SetAlarm(a, delay_wakeup, s);
    SleepThread();
}
/* merge_units: end func_002F5270 */

/* merge_units: begin func_002F52A8 */
extern void *memset(void *, int, unsigned int);
extern int rt_memory_allocate_init_zero(int *, unsigned long);
int rt_circ_buf_create(int *s, unsigned int n, int x)
{
    int r;
    if (s == 0) return 2;
    if (n == 0) return 2;
    memset(s, 0, 0x18);
    r = rt_memory_allocate_init_zero(s + 4, n);
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
extern int rt_memory_free(int *);
int rt_circ_buf_destroy(int *p)
{
    if (p == 0) return 2;
    if (p[4]) rt_memory_free(p + 4);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    return 0;
}
/* merge_units: end func_002F5348 */
