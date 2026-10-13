typedef struct N2F3F00 { struct N2F3F00 *next; struct N2F3F00 *prev; int a; int val; } N2F3F00;
typedef struct { int owner; int max; char pad8[0x10]; int used; int nfree; int busy; N2F3F00 *used_l; N2F3F00 *free_l; int cur; } P2F3F00;
extern int func_002DC290(int);
void func_002F3F00(P2F3F00 *q, int val)
{
    N2F3F00 *n, *head;
    if (val == 0) return;
    if (func_002DC290(val) == 1) {
        if (val == q->cur) q->busy = 0;
        return;
    }
    n = q->used_l;
    if (n && n->val != val) {
        head = n;
        do { n = n->prev; if (n == head) n = 0; } while (n && n->val != val);
    }
    if (n == 0) return;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    if (--q->used <= 0)
        q->used_l = 0;
    else if (n == q->used_l)
        q->used_l = n->prev;
    if (q->free_l == 0) {
        n->next = n->prev = n;
        q->free_l = n;
    } else {
        n->prev = q->free_l;
        n->next = q->free_l->next;
        n->prev->next = n;
        n->next->prev = n;
    }
    q->nfree++;
}


