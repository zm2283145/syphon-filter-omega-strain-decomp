/*
 * lib/libkernl: 2 files, 00117938-00117988
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00117938 */
extern int func_001161A0(void);
extern int func_001161F8(void);
extern int func_001178F0(int);
int func_00117938(int a)
{
    int s = func_001161A0();
    int r = func_001178F0(a);
    if (s) func_001161F8();
    return r;
}
/* merge_units: end func_00117938 */

/* merge_units: begin func_00117988 */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern long long func_001172E0(void);
extern void func_00116DF0(long long);
#if 0 /* merge_units */
extern void func_001161F8(void);
#endif /* merge_units */
#define func_001161F8() ((void)func_001161F8()) /* merge_units */

long long func_00117988(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    long long r;
    if (id < 0 || (id & 0x3FF) != a->id) return -1;
    r = a->x18;
    if (a->flags & 1) r += func_001172E0() - a->x10;
    return r;
}
#undef func_001161F8 /* merge_units */
/* merge_units: end func_00117988 */
