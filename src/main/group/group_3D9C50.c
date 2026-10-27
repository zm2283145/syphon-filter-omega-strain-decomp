#include "types.h"

extern int cGroup_Find_cSystemP(void);

/* Script native: returns whether cGroup_Find_cSystemP result is not -1. */
int cGroup_Contains(void) {
    return cGroup_Find_cSystemP() != -1;
}
