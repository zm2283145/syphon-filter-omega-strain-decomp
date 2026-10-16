#include "types.h"

extern int Group_FindByObject(void);

/* Script native: returns whether Group_FindByObject result is not -1. */
int Script_IsGroupMember(void) {
    return Group_FindByObject() != -1;
}
