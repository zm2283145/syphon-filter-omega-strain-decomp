/*
 * Matched functions (byte-identical with the retail executable).
 * cGroup script native: shuffle the member order.
 */

#include "types.h"
#include "group_types.h"

extern cGroup* Group_FromHandle(void* handle);   /* script handle -> cGroup (identity) */
extern float Group_Shuffle(cGroup* group);    /* shuffles the members */

/* Randomize(group) */
int Script_cGroup_Randomize(GroupScriptArg* args) {
    Group_Shuffle(Group_FromHandle(args[0].p));
    return 0;
}
