typedef struct L2F3308 { struct L2F3308 *prev; struct L2F3308 *next; } L2F3308;
typedef struct { int count; L2F3308 *head; } List2F3308;
extern int GetRefFromSet(List2F3308 *, int);
extern L2F3308 *CreatePlayerRef(char *);
void AddRefToSet(List2F3308 *l, char *item)
{
    L2F3308 *n, *h;
    if (GetRefFromSet(l, *(int *)(item + 0x34))) return;
    n = CreatePlayerRef(item);
    h = l->head;
    if (h == 0) {
        l->head = n;
        h = n;
    }
    n->next = h;
    l->count++;
    n->prev = l->head->prev;
    h->prev = n;
    n->prev->next = n;
}
