#include "types.h"
typedef struct LNode00234BB0 { struct LNode00234BB0* prev; struct LNode00234BB0* next; char data[1]; } LNode00234BB0;
typedef struct { int pad; LNode00234BB0* head; } LHdr00234BB0;
typedef struct { LNode00234BB0* node; } LIt00234BB0;
extern LHdr00234BB0* func_001F2690(void* self);
extern void func_001F26A0(LIt00234BB0* it, LNode00234BB0* n);
void* ParticleDefs_SlotForId(void* self, int n)
{
    LIt00234BB0 it;
    LNode00234BB0* p;
    func_001F26A0(&it, func_001F2690(self)->head);
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