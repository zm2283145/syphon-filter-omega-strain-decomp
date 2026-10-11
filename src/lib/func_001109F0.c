typedef struct N09F0 { char pad[0x3C]; struct N09F0 *next; } N09F0;
typedef struct { int x0; int busy; int x8; N09F0 *head; } Q09F0;
extern int func_001161A0(void);
extern int func_001161F8(void);

N09F0 *func_001109F0(Q09F0 *q)
{
    N09F0 *n;
    func_001161A0();
    n = q->head;
    if (n == 0) {
        q->busy = 0;
    } else {
        q->busy = 1;
        q->head = n->next;
    }
    func_001161F8();
    return n;
}