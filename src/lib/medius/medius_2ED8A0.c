#include "types.h"
typedef struct N2ED8A0 { int a; struct N2ED8A0* next; int b; int key; } N2ED8A0;
N2ED8A0* GridGetByChannel(N2ED8A0* head, int key)
{
    N2ED8A0* p = head;
    while (p) {
        if (p->key == key) break;
        p = p->next;
        if (p == head) { p = 0; break; }
    }
    return p;
}