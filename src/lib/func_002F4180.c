typedef struct Node_002F4180 {
    struct Node_002F4180 *prev;
    struct Node_002F4180 *next;
    int unk8;
    int key;
} Node_002F4180;

typedef struct {
    int unk0;
    int unk4;
    int count;
    int freeCount;
    Node_002F4180 *head;
    Node_002F4180 *freeList;
} List_002F4180;

void func_002F4180(List_002F4180 *l, int key)
{
    Node_002F4180 *n;
    Node_002F4180 *f;
    n = l->head;
    if (key == 0 || n == 0) return;
    if (n->key != key) {
        Node_002F4180 *first = n;
        do {
            n = n->next;
            n = (n == first) ? 0 : n;
            if (n == 0) return;
        } while (n->key != key);
    }
    if (n == 0) return;
    n->next->prev = n->prev;
    n->prev->next = n->next;
    if (n == l->head)
        l->head = (n == n->next) ? 0 : n->next;
    l->count--;
    f = l->freeList; if (f == 0) {
        n->next = n;
        n->prev = n;
        l->freeList = n;
    } else {
        n->next = f; n->prev = l->freeList->prev; f->prev = n;
        n->prev->next = n;
    }
    l->freeCount++;
}





