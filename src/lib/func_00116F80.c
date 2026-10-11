typedef struct Alarm { struct Alarm *next; struct Alarm *prev; int pad8; int padC; unsigned long long x10; unsigned long long x18; unsigned long long x20; } Alarm;
typedef struct { unsigned long long a; int id; int pad; int cnt; void *buf; Alarm *head; int x1C; } TimCtl;
extern TimCtl D_00487848;
void func_00116F80(Alarm *a)
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