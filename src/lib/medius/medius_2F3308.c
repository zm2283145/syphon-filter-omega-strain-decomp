typedef struct L2F3308 { struct L2F3308 *prev; struct L2F3308 *next; } L2F3308;
typedef struct { int count; L2F3308 *head; } List2F3308;
extern int func_002F3388(List2F3308 *, int);
extern L2F3308 *func_002F2E90(char *);
void func_002F3308(List2F3308 *l, char *item)
{
    L2F3308 *n, *h;
    if (func_002F3388(l, *(int *)(item + 0x34))) return;
    n = func_002F2E90(item);
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
