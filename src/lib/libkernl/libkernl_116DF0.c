/*
 * lib/libkernl: 2 files, 00116DF0-00116F80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00116DF0 */
/* 00116DF0 libkernel alarm: re-arm timer 1 for the next alarm group (gcc29). */
typedef struct Alarm { struct Alarm *next; struct Alarm *prev; int pad8; int padC; unsigned long long x10; unsigned long long x18; unsigned long long x20; } Alarm;
typedef struct { unsigned long long a; int id; int pad; int cnt; void *buf; Alarm *head; int x1C; } TimCtl;
extern TimCtl D_00487848;
extern void SetT2_MODE(unsigned int);
extern void SetT2_COMP(unsigned int);

void SetNextComp(unsigned long long now)
{
    Alarm *p;
    unsigned int mode;
    unsigned long long t, u;
    int pre;

    p = D_00487848.head;
    if (D_00487848.x1C >= 0) return;
    mode = *(volatile unsigned int *)0x10001010;
    if (p == 0) {
        SetT2_COMP(0);
        SetT2_MODE(mode & ~0x800);
        return;
    }
    t = p->x20 + p->x10 - p->x18;
    for (p = p->next; p; p = p->next) {
        u = p->x20 + p->x10 - p->x18;
        if (u < t + 0x7333) t = u; else break;
    }
    pre = mode & 3;
    if ((long long)(t - now) < 0x7333) {
        SetT2_COMP(*(volatile unsigned int *)0x10001000 + (int)(0x7333ULL >> (pre * 4)));
        SetT2_MODE(mode & ~0x800);
        return;
    }
    SetT2_MODE(mode & ~0x800);
    SetT2_COMP((int)(t >> (pre * 4)));
    return;
}
/* merge_units: end func_00116DF0 */

/* merge_units: begin func_00116F80 */
void InsertAlarm(Alarm *a)
{
    Alarm *prev = 0;
    Alarm *p = D_00487848.head;
    unsigned long long t = a->x20 + a->x10 - a->x18;
    while (p) {
        if (t < p->x20 + p->x10 - p->x18) break;
        prev = p;
        p = p->next;
    }
    a->prev = prev;
    a->next = p;
    if (p) p->prev = a;
    if (prev) prev->next = a;
    else D_00487848.head = a;
}
/* merge_units: end func_00116F80 */
