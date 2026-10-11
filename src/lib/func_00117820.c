typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern long long func_001172E0(void);
extern void func_00116DF0(long long);
extern int func_001161A0(void);
extern void func_001161F8(void);
long long func_00117820(int id, long long val)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    int s = func_001161A0();
    long long old, t;
    if (id < 0 || (id & 0x3FF) != a->id || D_00487848.cur == id) {
        if (s) func_001161F8();
        return -1;
    }
    old = a->x18;
    if (a->flags & 1) {
        long long d;
        t = func_001172E0();
        d = t - a->x10;
        a->x10 = t;
        a->x18 = val;
        old += d;
    } else {
        a->x18 = val;
    }
    if (s) func_001161F8();
    return old;
}