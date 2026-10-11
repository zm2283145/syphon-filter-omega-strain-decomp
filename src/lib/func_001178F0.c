typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern long long func_001172E0(void);
extern void func_00116DF0(long long);
extern int func_001161A0(void);
extern void func_001161F8(void);
long long func_001178F0(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != a->id) return -1;
    if (a->flags & 1) return a->x10 - a->x18;
    return 0;
}