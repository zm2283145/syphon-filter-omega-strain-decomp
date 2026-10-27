#include "types.h"

extern void std_list_imp_voidPtr_push_back(void);

/* Calls std_list_imp_voidPtr_push_back. */
#pragma optimization_level 1
void std_list_cSkaSwitchItemPtr_push_back(void)
{
    std_list_imp_voidPtr_push_back();
}
#pragma optimization_level reset
