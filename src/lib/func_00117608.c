typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; int flags; unsigned long long x10; unsigned long long x18; unsigned long long x20; int x28; } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;
extern void func_00117008(Alarm *);
extern unsigned long long func_001172E0(void);
extern void func_00116F80(Alarm *);
extern void func_00116DF0(unsigned long long);
int func_00117608(int id)
{
    Alarm *a = (Alarm *)(((unsigned int)id >> 10) << 6);
    unsigned long long t;
    if (id < 0 || (id & 0x3FF) != a->id) return 0x80008002;
    if (D_00487848.cur == id) return 0x80000010;
    if (a->flags & 1) return 1;
    t = func_001172E0();
    a->x10 = t;
    a->flags |= 1;
    if (a->flags & 2) {
        func_00116F80(a);
        func_00116DF0(t);
    }
    return 0;
}