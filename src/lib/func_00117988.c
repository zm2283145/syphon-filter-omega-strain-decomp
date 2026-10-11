typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern long long func_001172E0(void);
extern void func_00116DF0(long long);
extern int func_001161A0(void);
extern void func_001161F8(void);
long long func_00117988(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    long long r;
    if (id < 0 || (id & 0x3FF) != a->id) return -1;
    r = a->x18;
    if (a->flags & 1) r += func_001172E0() - a->x10;
    return r;
}