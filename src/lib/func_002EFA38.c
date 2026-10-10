#include "types.h"
typedef struct g2Node { int pad0; struct g2Node* next; int pad8; int ids[4]; } g2Node;
typedef struct { char pad[0x54]; g2Node* list; } g2Owner;
void func_002EFA38(g2Owner* o, int id) {
    g2Node* head = o->list;
    g2Node* n = head;
    unsigned int i;
    while (n != 0) {
        for (i = 0; i < 4; i++) {
            if (n->ids[i] == id) {
                n->ids[i] = 0xFFFF;
            }
        }
        n = n->next;
        if (n == head) {
            n = 0;
        }
    }
}