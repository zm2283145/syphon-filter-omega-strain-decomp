typedef struct Alarm { struct Alarm *next; struct Alarm *prev; volatile int id; int flags; unsigned long long x10; unsigned long long x18; unsigned long long x20; unsigned long (*x28)(int); } Alarm;
typedef struct { unsigned long long a; int id; volatile int seq; volatile int cnt; Alarm *free; Alarm *head; volatile int cur; } TimCtl;
extern TimCtl D_00487848;

int func_001173B0(void)
{
    Alarm *a = D_00487848.free;
    if (!a) return 0x80008005;
    D_00487848.cnt++;
    a->x28 = 0;
    a->flags = 0;
    D_00487848.free = a->next;
    a->x18 = 0;
    D_00487848.seq++;
    a->id = ((D_00487848.seq << 1) & 0x3FE) | 1;
    return ((int)a << 4) | a->id;
}
