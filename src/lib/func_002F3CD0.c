typedef struct N2F3CD0 { struct N2F3CD0 *next; struct N2F3CD0 *prev; int a; int val; } N2F3CD0;
typedef struct { int owner; int max; char pad8[0x10]; int used; int nfree; int pad20; N2F3CD0 *used_l; N2F3CD0 *free_l; } P2F3CD0;
extern int Net_AllocZeroed(void *, int);
extern int func_002DBD58(int, int, int);
extern void func_002DC1F0(int);
extern int func_002DC230(int);
extern int func_002DC288(int);
extern void func_002FB3C0(void *);
int func_002F3CD0(P2F3CD0 *q, int key)
{
    N2F3CD0 *n;
    int r = 0;
    n = q->free_l;
    while (n) {
        if (func_002DC288(n->val) == key)
            break;
        n = n->prev;
        if (n == q->free_l)
            n = 0;
    }
    if (n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        if (--q->nfree <= 0)
            q->free_l = 0;
        else if (q->free_l == n)
            q->free_l = n->prev;
    } else {
        while (q->nfree > 0 && q->used + q->nfree >= q->max) {
            N2F3CD0 *e = q->free_l->next;
            q->nfree--;
            e->next->prev = e->prev;
            e->prev->next = e->next;
            if (q->nfree <= 0)
                q->free_l = 0;
            func_002DC1F0(e->val);
            func_002FB3C0(&e);
        }
        if (q->used < q->max) {
            Net_AllocZeroed(&n, 0x10);
            if (n != 0) {
                n->val = func_002DBD58(q->owner, key, 2);
                if (n->val == 0)
                    func_002FB3C0(&n);
            }
        }
    }
    if (n != 0) {
        if (q->used_l == 0) {
            n->next = n->prev = n;
            q->used_l = n;
        } else {
            n->prev = q->used_l;
            n->next = q->used_l->next;
            n->prev->next = n;
            n->next->prev = n;
        }
        r = n->val;
        q->used++;
        func_002DC230(r);
    }
    return r;
}
