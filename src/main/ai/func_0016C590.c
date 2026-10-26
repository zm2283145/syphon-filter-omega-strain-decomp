#include "types.h"
typedef struct { char pad[0xC]; int serial; } Tgt_C590;
typedef struct { Tgt_C590* target; int serial; char pad8[0x34]; unsigned char seen; } Rec_C590;
typedef struct Node_C590 { int pad0; struct Node_C590* next; Rec_C590* val; } Node_C590;
typedef struct { Node_C590* n; } It_C590;
typedef struct { int a; } E_C590;
typedef struct { char pad[0x30]; char map[4]; } Own_C590;
extern void std_list_cTargetAwarenessPtr_end_void(E_C590* out, void* map);
extern void std_list_cTargetAwarenessPtr_begin(E_C590* out, void* map);
extern void cLListIterator_cTargetAwarenessPtr_ctor(It_C590* out, E_C590* in);
/* Clears the "seen" flag of every record (or only of the records targeting who). */
void NpcPerception_ResendAwareness(Own_C590* self, Tgt_C590* who)
{
    It_C590 it;
    It_C590 b;
    It_C590 end;
    E_C590 t1;
    E_C590 t2;
    std_list_cTargetAwarenessPtr_begin(&t1, self->map);
    cLListIterator_cTargetAwarenessPtr_ctor(&b, &t1);
    it = b;
    while (std_list_cTargetAwarenessPtr_end_void(&t2, self->map), cLListIterator_cTargetAwarenessPtr_ctor(&end, &t2), it.n != end.n) {
        if (who) {
            unsigned char ok;
            int isNull;
            Tgt_C590* c;
            Rec_C590* h;
            h = it.n->val;
            c = h->target;
            isNull = !c;
            ok = 1;
            if (!isNull)
                if (c->serial != h->serial)
                    ok = 0;
            if ((ok ? c : 0) != who)
                goto next;
        }
        it.n->val->seen = 0;
    next:
        it.n = it.n->next;
    }
}
