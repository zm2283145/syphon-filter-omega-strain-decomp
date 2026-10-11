typedef struct N2F4030 { struct N2F4030 *next; struct N2F4030 *prev; int a; int val; } N2F4030;
typedef struct { int a; int max; int used; int nfree; N2F4030 *used_l; N2F4030 *free_l; } P2F4030;
extern int Net_AllocZeroed(void *, int);
extern int func_003135E0(void);
extern void func_002FB3C0(void *);
extern void func_00313688(int);
int func_002F4030(P2F4030 *q)
{
    N2F4030 *n = 0;
    int r = 0;
    if (q->free_l == 0) {
        if (q->used < q->max) {
            Net_AllocZeroed(&n, 0x10);
            if (n != 0) {
                n->val = func_003135E0();
                if (n->val == 0) {
                    func_002FB3C0(&n);
                    n = 0;
                }
            }
        }
    } else {
        n = q->free_l->next;
        if (n == q->free_l) q->free_l = 0;
        else {
            q->free_l->next = n->next;
            q->free_l->next->prev = q->free_l;
        }
        q->nfree--;
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
    func_00313688(r);
    }
    return r;
}