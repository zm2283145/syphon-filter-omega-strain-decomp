/*
 * lib/libkernl: 2 files, 00117938-00117988
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00117938 */
extern int DIntr(void);
extern int EIntr(void);
extern int iGetTimerBaseTime(int);
int GetTimerBaseTime(int a)
{
    int s = DIntr();
    int r = iGetTimerBaseTime(a);
    if (s) EIntr();
    return r;
}
/* merge_units: end func_00117938 */

/* merge_units: begin func_00117988 */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void UnlinkAlarm(Alarm *);
extern long long iGetTimerSystemTime(void);
extern void SetNextComp(long long);
#if 0 /* merge_units */
extern void EIntr(void);
#endif /* merge_units */
#define EIntr() ((void)EIntr()) /* merge_units */

long long iGetTimerCount(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    long long r;
    if (id < 0 || (id & 0x3FF) != a->id) return -1;
    r = a->x18;
    if (a->flags & 1) r += iGetTimerSystemTime() - a->x10;
    return r;
}
#undef EIntr /* merge_units */
/* merge_units: end func_00117988 */
