#include "types.h"
typedef struct N164 { int pad; struct N164* next; struct N164* prev; float key; } N164;
typedef struct { int pad; N164* next; N164* prev; } H164;
typedef struct { int pad[2]; N164* first; int pad2; H164 sent; int count; } L164;
static inline int Less164(N164* a, N164* b) { return a->key <= b->key; }
void func_00164B70(L164* l, N164* item) {
    N164* n;
    N164* p;
    for (n = l->first; n != (N164*)&l->sent && !Less164(item, n); n = n->next) { }
    p = n->prev;
    item->next = n;
    item->prev = p;
    p->next = item;
    n->prev = item;
    l->count++;
}