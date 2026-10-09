/*
 * Matched functions (byte-identical with the retail executable).
 * cGroup script natives: add / remove members.
 */

#include "types.h"
#include "group_types.h"

extern void Group_AddObject(cGroup* group, int obj);
extern int Group_RemoveObject(cGroup* group, int obj);
extern int func_003CB1C0(void* value);                 /* script value -> object (identity) */
extern cGroup* Group_FromHandle(void* handle);           /* script handle -> cGroup (identity) */
extern int Group_AddObjectDup(cGroup* group, int obj);     /* appends even if already present */

/* Remove(group, obj) */
int Script_cGroup_Remove(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    Group_RemoveObject(group, func_003CB1C0(args[1].p));
    return 0;
}

/* AddDup(group, obj): appends without the duplicate check. */
int Script_cGroup_AddDup(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    Group_AddObjectDup(group, func_003CB1C0(args[1].p));
    return 0;
}

/* Add(group, obj) */
int Script_cGroup_Add(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    Group_AddObject(group, func_003CB1C0(args[1].p));
    return 0;
}
