#include "types.h"

extern int func_003D9C80(void);

/* Script native: returns whether func_003D9C80 result is not -1. */
int Script_IsGroupMember(void) {
    return func_003D9C80() != -1;
}
