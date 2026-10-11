typedef struct { int a, b, c, time, e; } E2ED680;
typedef struct T2ED680 {
    struct T2ED680 *next; struct T2ED680 *prev; int a; int b; char c; char p11[0x47];
    int f58; int f5C; E2ED680 *arr; int f64; int f68; int now; int f70; int f74; int f78[3];
} T2ED680;
typedef struct { char p[0x50]; int f50; int f54; } X2ED680;
extern void Net_AllocZeroed(void *, unsigned long);
extern int func_002F5160(void);
extern void *memset(void *, int, unsigned int);
T2ED680 *func_002ED680(int a, T2ED680 *list, int b, int cap)
{
    T2ED680 *p = 0;
    int now;
    int i;
    Net_AllocZeroed(&p, 0x84);
    if (p != 0) {
    now = func_002F5160();
    p->a = a;
    p->b = b;
    p->next = 0;
    p->prev = 0;
    p->f64 = 0;
    p->f70 = 0;
    p->now = now;
    p->f74 = 0;
    p->f68 = 0;
    p->c = 0;
    p->f58 = cap;
    p->f5C = p->f58 ? p->f58 : 0x20;
    Net_AllocZeroed(&p->arr, (unsigned int)(p->f5C * sizeof(E2ED680)));
    for (i = 0; i < p->f5C; i++)
        p->arr[i].time = now;
    memset(p->f78, 0, 12);
    ((X2ED680 *)p)->f54 = 0;
    ((X2ED680 *)p)->f50 = 0;
    if (list) {
        p->prev = list;
        p->next = list->next;
        p->prev->next = p;
        p->next->prev = p;
    } else {
        p->prev = p;
        p->next = p;
    }
    }
    return p;
}