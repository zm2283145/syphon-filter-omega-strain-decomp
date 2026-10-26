/*
 * lib/libkernl: 7 files, 001175A8-001178F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001175A8 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int DIntr();                                
int EIntr();                                  
int iGetTimerUsedUnusedCounters(int, int);                          

int GetTimerUsedUnusedCounters(int arg0, int arg1) {
    int temp_s0;
    int temp_s2;

    temp_s2 = DIntr();
    temp_s0 = iGetTimerUsedUnusedCounters(arg0, arg1);
    if (temp_s2 != 0) {
        EIntr();
    }
    return temp_s0;
}
/* merge_units: end func_001175A8 */

/* merge_units: begin func_00117608 */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; int flags; unsigned long long x10; unsigned long long x18; unsigned long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void UnlinkAlarm(Alarm *);
extern unsigned long long iGetTimerSystemTime(void);
extern void InsertAlarm(Alarm *);
extern void SetNextComp(unsigned long long);
int iStartTimerCounter(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    unsigned long long t;
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (a->flags & 1) return 1;
    t = iGetTimerSystemTime();
    a->x10 = t;
    a->flags |= 1;
    if (a->flags & 2) {
        InsertAlarm(a);
        SetNextComp(t);
    }
    return 0;
}
/* merge_units: end func_00117608 */

/* merge_units: begin func_001176B8 */
#if 0 /* merge_units */
extern int DIntr(void);
#endif /* merge_units */
#define DIntr() (DIntr()) /* merge_units */

#if 0 /* merge_units */
extern int EIntr(void);
#endif /* merge_units */
#define EIntr() (EIntr()) /* merge_units */

#if 0 /* merge_units */
extern int iStartTimerCounter(int);
#endif /* merge_units */
#define iStartTimerCounter(a0) (iStartTimerCounter((a0))) /* merge_units */

int StartTimerCounter(int a)
{
    int s = DIntr();
    int r = iStartTimerCounter(a);
    if (s) EIntr();
    return r;
}
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
#undef iStartTimerCounter /* merge_units */
/* merge_units: end func_001176B8 */

/* merge_units: begin func_00117708 */
typedef struct Alarm_00117708 { struct Alarm_00117708 *next; struct Alarm_00117708 *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm_00117708;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm_00117708 *free; Alarm_00117708 *head; volatile int cur; } TimCtl_00117708;
#if 0 /* merge_units */
extern TimCtl_00117708 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_00117708*)&D_00487848) /* merge_units */

#if 0 /* merge_units */
extern void UnlinkAlarm(Alarm_00117708 *);
#endif /* merge_units */
#define UnlinkAlarm(a0) (UnlinkAlarm((Alarm *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern long long iGetTimerSystemTime(void);
#endif /* merge_units */
#define iGetTimerSystemTime() ((long long)iGetTimerSystemTime()) /* merge_units */

#if 0 /* merge_units */
extern void SetNextComp(long long);
#endif /* merge_units */
#define SetNextComp(a0) (SetNextComp((unsigned long long)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int DIntr(void);
#endif /* merge_units */
#define DIntr() (DIntr()) /* merge_units */

#if 0 /* merge_units */
extern void EIntr(void);
#endif /* merge_units */
#define EIntr() ((void)EIntr()) /* merge_units */

int iStopTimerCounter(int id)
{
    Alarm_00117708 *a = (Alarm_00117708 *)(((unsigned int)id >> 10) << 6);
    long long t;
    unsigned int f;
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (!(a->flags & 1)) return 0;
    t = iGetTimerSystemTime();
    f = a->flags;
    a->x18 += t - a->x10;
    a->flags = f & ~1;
    if (f & 2) {
        UnlinkAlarm(a);
        SetNextComp(t);
    }
    return 1;
}
#undef D_00487848 /* merge_units */
#undef UnlinkAlarm /* merge_units */
#undef iGetTimerSystemTime /* merge_units */
#undef SetNextComp /* merge_units */
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
/* merge_units: end func_00117708 */

/* merge_units: begin func_001177D0 */
#if 0 /* merge_units */
extern int DIntr(void);
#endif /* merge_units */
#define DIntr() (DIntr()) /* merge_units */

#if 0 /* merge_units */
extern int EIntr(void);
#endif /* merge_units */
#define EIntr() (EIntr()) /* merge_units */

#if 0 /* merge_units */
extern int iStopTimerCounter(int);
#endif /* merge_units */
#define iStopTimerCounter(a0) (iStopTimerCounter((a0))) /* merge_units */

int StopTimerCounter(int a)
{
    int s = DIntr();
    int r = iStopTimerCounter(a);
    if (s) EIntr();
    return r;
}
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
#undef iStopTimerCounter /* merge_units */
/* merge_units: end func_001177D0 */

/* merge_units: begin func_00117820 */
typedef struct Alarm_00117820 { struct Alarm_00117820 *next; struct Alarm_00117820 *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm_00117820;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm_00117820 *free; Alarm_00117820 *head; volatile int cur; } TimCtl_00117820;
#if 0 /* merge_units */
extern TimCtl_00117820 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_00117820*)&D_00487848) /* merge_units */

#if 0 /* merge_units */
extern void UnlinkAlarm(Alarm_00117820 *);
#endif /* merge_units */
#define UnlinkAlarm(a0) (UnlinkAlarm((Alarm *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern long long iGetTimerSystemTime(void);
#endif /* merge_units */
#define iGetTimerSystemTime() ((long long)iGetTimerSystemTime()) /* merge_units */

#if 0 /* merge_units */
extern void SetNextComp(long long);
#endif /* merge_units */
#define SetNextComp(a0) (SetNextComp((unsigned long long)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int DIntr(void);
#endif /* merge_units */
#define DIntr() (DIntr()) /* merge_units */

#if 0 /* merge_units */
extern void EIntr(void);
#endif /* merge_units */
#define EIntr() ((void)EIntr()) /* merge_units */

long long SetTimerCount(int id, long long val)
{
    Alarm_00117820 *a = (Alarm_00117820 *)(((unsigned int)id >> 10) << 6);
    int s = DIntr();
    long long old, t;
    if (id < 0 || (id & 0x3FF) != a->id || D_00487848.cur == id) {
        if (s) EIntr();
        return -1;
    }
    old = a->x18;
    if (a->flags & 1) {
        long long d;
        t = iGetTimerSystemTime();
        d = t - a->x10;
        a->x10 = t;
        a->x18 = val;
        old += d;
    } else {
        a->x18 = val;
    }
    if (s) EIntr();
    return old;
}
#undef D_00487848 /* merge_units */
#undef UnlinkAlarm /* merge_units */
#undef iGetTimerSystemTime /* merge_units */
#undef SetNextComp /* merge_units */
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
/* merge_units: end func_00117820 */

/* merge_units: begin func_001178F0 */
typedef struct Alarm_001178F0 { struct Alarm_001178F0 *next; struct Alarm_001178F0 *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm_001178F0;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm_001178F0 *free; Alarm_001178F0 *head; volatile int cur; } TimCtl_001178F0;
#if 0 /* merge_units */
extern TimCtl_001178F0 D_00487848;
#endif /* merge_units */
#define D_00487848 (*(TimCtl_001178F0*)&D_00487848) /* merge_units */

#if 0 /* merge_units */
extern void UnlinkAlarm(Alarm_001178F0 *);
#endif /* merge_units */
#define UnlinkAlarm(a0) (UnlinkAlarm((Alarm *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern long long iGetTimerSystemTime(void);
#endif /* merge_units */
#define iGetTimerSystemTime() ((long long)iGetTimerSystemTime()) /* merge_units */

#if 0 /* merge_units */
extern void SetNextComp(long long);
#endif /* merge_units */
#define SetNextComp(a0) (SetNextComp((unsigned long long)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int DIntr(void);
#endif /* merge_units */
#define DIntr() (DIntr()) /* merge_units */

#if 0 /* merge_units */
extern void EIntr(void);
#endif /* merge_units */
#define EIntr() ((void)EIntr()) /* merge_units */

long long iGetTimerBaseTime(int id)
{
    Alarm_001178F0 *a = (Alarm_001178F0 *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != a->id) return -1;
    if (a->flags & 1) return a->x10 - a->x18;
    return 0;
}
#undef D_00487848 /* merge_units */
#undef UnlinkAlarm /* merge_units */
#undef iGetTimerSystemTime /* merge_units */
#undef SetNextComp /* merge_units */
#undef DIntr /* merge_units */
#undef EIntr /* merge_units */
/* merge_units: end func_001178F0 */
