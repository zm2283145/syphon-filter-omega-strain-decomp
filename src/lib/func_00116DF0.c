/* 00116DF0 libkernel alarm: re-arm timer 1 for the next alarm group (gcc29). */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; int pad8; int padC; unsigned long long x10; unsigned long long x18; unsigned long long x20; } Alarm;
typedef struct { unsigned long long a; int id; int pad; int cnt; void *buf; Alarm *head; int x1C; } TimCtl;
extern TimCtl D_00487848;
extern void func_00116A80(unsigned int);
extern void func_00116A90(unsigned int);

void func_00116DF0(unsigned long long now)
{
    Alarm *p;
    unsigned int mode;
    unsigned long long t, u;
    int pre;

    p = D_00487848.head;
    if (D_00487848.x1C >= 0) return;
    mode = *(volatile unsigned int *)0x10001010;
    if (p == 0) {
        func_00116A90(0);
        func_00116A80(mode & ~0x800);
        return;
    }
    t = p->x20 + p->x10 - p->x18;
    for (p = p->next; p; p = p->next) {
        u = p->x20 + p->x10 - p->x18;
        if (u < t + 0x7333) t = u; else break;
    }
    pre = mode & 3;
    if ((long long)(t - now) < 0x7333) {
        func_00116A90(*(volatile unsigned int *)0x10001000 + (int)(0x7333ULL >> (pre * 4)));
        func_00116A80(mode & ~0x800);
        return;
    }
    func_00116A80(mode & ~0x800);
    func_00116A90((int)(t >> (pre * 4)));
    return;
}
