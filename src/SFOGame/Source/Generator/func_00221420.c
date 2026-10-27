#include "types.h"

extern void cGenInfoObject_ctor(int*);
extern void cGenInfoObject_Deactivate(int*, void*);
extern void cGOBJ_NetDeactivate(void*);

/* vtable slot 7 of cGenerator. */
void cGenerator_NetDeactivate(char* self) {
    int tmp;
    cGenInfoObject_ctor(&tmp);
    cGenInfoObject_Deactivate(&tmp, self + 0xC);
    cGOBJ_NetDeactivate(self);
}
