/*
 * Matched functions (byte-identical with the retail executable).
 * cGroup script natives: indexed access and size.
 */

#include "types.h"
#include "group_types.h"

extern int func_003CB1A0(int obj);                    /* object -> script value */
extern cGroup* Group_FromHandle(void* handle);           /* script handle -> cGroup (identity) */
extern int Group_GetAt(cGroup* group, int index);   /* bounds-checked member lookup */

/* Get(group, index): returns the member at index (0 when out of range). */
int Script_cGroup_Get(GroupScriptArg* args) {
    volatile int index = args[1].i; /* stack temporary in the original */

    return func_003CB1A0(Group_GetAt(Group_FromHandle(args[0].p), index));
}

/* GetSize(group): number of members. */
int Script_cGroup_GetSize(GroupScriptArg* args) {
    volatile int size; /* the original goes through a stack temporary */

    size = Group_FromHandle(args[0].p)->count;
    return size;
}
