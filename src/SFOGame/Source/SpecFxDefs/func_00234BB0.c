#include "types.h"
typedef struct LNode00234BB0 { struct LNode00234BB0* prev; struct LNode00234BB0* next; char data[1]; } LNode00234BB0;
typedef struct { int pad; LNode00234BB0* head; } LHdr00234BB0;
typedef struct { LNode00234BB0* node; } LIt00234BB0;
extern LHdr00234BB0* std_list_deleter_voidPtr_tail(void* self);
extern void std_list_deleter_voidPtr_generic_iterator_ctor_nodeP(LIt00234BB0* it, LNode00234BB0* n);
void* cLList_cParticleDefinitionPtr_opIndex(void* self, int n)
{
    LIt00234BB0 it;
    LNode00234BB0* p;
    std_list_deleter_voidPtr_generic_iterator_ctor_nodeP(&it, std_list_deleter_voidPtr_tail(self)->head);
    p = it.node;
    if (n >= 0) {
        while (n > 0) {
            p = p->next;
            n--;
        }
    } else {
        while (n < 0) {
            p = p->prev;
            n++;
        }
    }
    return p->data;
}