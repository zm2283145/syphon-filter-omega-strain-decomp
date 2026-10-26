#include "types.h"
extern void std_list_cSkaTransBLENDPtr_push_back(void);
/* Wrapper around std_list_cSkaTransBLENDPtr_push_back. */
#pragma optimization_level 1
void cLList_cSkaTransBLENDPtr_PushBackActual(void) { std_list_cSkaTransBLENDPtr_push_back(); }
#pragma optimization_level reset
