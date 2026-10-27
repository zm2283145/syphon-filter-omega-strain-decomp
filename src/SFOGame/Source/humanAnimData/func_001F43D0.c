#include "types.h"
#pragma optimization_level 1

extern void std_list_imp_voidPtr_push_back(void);

/* Forwards to std_list_imp_voidPtr_push_back. */
void std_list_cSkaBlendSequenceItemPtr_push_back(void) {
    std_list_imp_voidPtr_push_back();
}
