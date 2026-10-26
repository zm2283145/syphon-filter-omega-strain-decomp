typedef struct L2F33E0 { struct L2F33E0 *prev; struct L2F33E0 *next; } L2F33E0;
typedef struct { int count; L2F33E0 *head; } List2F33E0;
extern L2F33E0 *GetRefFromSet(List2F33E0 *, int);
extern void DestroyPlayerRef(L2F33E0 *);
void RemoveRefFromSet(List2F33E0 *l, int key)
{
    L2F33E0 *n = GetRefFromSet(l, key);
    L2F33E0 *nx;
    if (n == 0) return;
    if (n == l->head) {
        nx = n->next;
        if (n == nx) nx = 0;
        l->head = nx;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    DestroyPlayerRef(n);
    l->count--;
}
