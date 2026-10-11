typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern long long func_001172E0(void);
extern void func_00116DF0(long long);
extern int func_001161A0(void);
extern void func_001161F8(void);
int func_00117708(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    long long t;
    unsigned int f;
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (!(a->flags & 1)) return 0;
    t = func_001172E0();
    f = a->flags;
    a->x18 += t - a->x10;
    a->flags = f & ~1;
    if (f & 2) {
        func_00117008(a);
        func_00116DF0(t);
    }
    return 1;
}