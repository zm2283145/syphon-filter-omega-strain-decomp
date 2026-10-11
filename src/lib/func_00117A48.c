typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; unsigned int flags; long long x10; long long x18; long long x20; void *h; int gp; void *arg; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern long long func_001172E0(void);
extern void func_00116DF0(long long);
extern void func_00116F80(Alarm *);

int func_00117A48(int id, long long t, void *h, void *arg)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (a->flags & 2) func_00117008(a);
    a->h = h;
    if (h == 0) {
        a->flags &= ~2;
    } else {
        a->flags |= 2;
        a->x20 = t;
        __asm__ volatile ("sw $gp, %0" : "=m" (a->gp) : : "memory");
        a->arg = arg;
        if (a->flags & 1) func_00116F80(a);
    }
    func_00116DF0(func_001172E0());
    return 0;
}