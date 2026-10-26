#include "types.h"
#pragma optimization_level 1

extern void opDelete_cSkaSwitchItemP_int_bool_charP_etc(void*, int, int, void*, int);

/* Calls opDelete_cSkaSwitchItemP_int_bool_charP_etc(obj, 0, 0, ((int*)"allocator.hh"), 100) when obj is set. */
void cAllocator_cSkaSwitchItem_deallocate(void* self, void* obj) {
    if (obj != 0) opDelete_cSkaSwitchItemP_int_bool_charP_etc(obj, 0, 0, ((int*)"allocator.hh"), 100);
}
