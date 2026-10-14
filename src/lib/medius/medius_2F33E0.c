typedef struct L2F33E0 { struct L2F33E0 *prev; struct L2F33E0 *next; } L2F33E0;
typedef struct { int count; L2F33E0 *head; } List2F33E0;
extern L2F33E0 *func_002F3388(List2F33E0 *, int);
extern void func_002F2F08(L2F33E0 *);
void func_002F33E0(List2F33E0 *l, int key)
{
    L2F33E0 *n = func_002F3388(l, key);
    L2F33E0 *nx;
    if (n == 0) return;
    if (n == l->head) {
        nx = n->next;
        if (n == nx) nx = 0;
        l->head = nx;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    func_002F2F08(n);
    l->count--;
}
