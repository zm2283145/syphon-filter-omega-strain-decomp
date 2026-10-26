#include "types.h"

/* This wrapper keeps a stack frame and a real call (no tail call): built at a lower optimization level. */
#pragma optimization_level 2

extern void std_list_imp_voidPtr_push_back(void* self);

/* Forwards to std_list_imp_voidPtr_push_back. */
void std_list_cSkaTransBLENDPtr_push_back(void* self)
{
    std_list_imp_voidPtr_push_back(self);
}
