#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void std_list_cSkaTransBLENDPtr_ctor(void* obj);

/* Runs std_list_cSkaTransBLENDPtr_ctor on obj and returns obj. */
void* cLList_cSkaTransBLENDPtr_ctor(void* obj) {
    std_list_cSkaTransBLENDPtr_ctor(obj);
    return obj;
}

#pragma pop
