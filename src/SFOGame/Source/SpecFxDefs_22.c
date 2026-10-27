/*
 * SFOGame/Source/SpecFxDefs: 1 file, 00234BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00234BB0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00234BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00234BB0 */
