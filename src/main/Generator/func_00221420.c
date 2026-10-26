#include "types.h"

extern void cGenInfoObject_ctor(int*);
extern void cGenInfoObject_Deactivate(int*, void*);
extern void cNode_v07(void*);

/* vtable slot 7 of cGenerator. */
void cGenerator_v07(char* self) {
    int tmp;
    cGenInfoObject_ctor(&tmp);
    cGenInfoObject_Deactivate(&tmp, self + 0xC);
    cNode_v07(self);
}
