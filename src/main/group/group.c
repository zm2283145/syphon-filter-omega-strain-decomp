/*
 * main/group: 7 files, 003D96D0-003D9870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 *
 * cGroup script natives. Each takes the script argument array; args[0] is the
 * group handle and args[1] (when present) an object or index.
 */

#include "types.h"
#include "group_types.h"

extern int Script_ObjToValue(int obj);                    /* object -> script value (identity) */
extern int Script_ValueToObj(void* value);                /* script value -> object (identity) */
extern cGroup* Group_FromHandle(void* handle);        /* script handle -> cGroup (identity) */
extern int Group_GetAt(cGroup* group, int index);     /* bounds-checked member lookup */
extern unsigned char Script_IsGroupMember(cGroup* group, int obj);
extern int Group_FindByObject(cGroup* group, int obj);
extern void Group_Print(cGroup* group);             /* debug print (empty in retail) */
extern float Group_Shuffle(cGroup* group);            /* shuffles the members */
extern void Group_RemoveAll(cGroup* group);             /* removes every member */
extern void Group_AddObject(cGroup* group, int obj);  /* appends if not already present */
extern int Group_RemoveObject(cGroup* group, int obj);
extern int Group_AddObjectDup(cGroup* group, int obj); /* appends even if already present */

/* merge_units: begin func_003D96D0 */
#pragma push /* merge_units */

/* Get(group, index): returns the member at index (0 when out of range). */
int Script_cGroup_Get(GroupScriptArg* args) {
    volatile int index = args[1].i; /* stack temporary in the original */

    return Script_ObjToValue(Group_GetAt(Group_FromHandle(args[0].p), index));
}

/* GetSize(group): number of members. */
int Script_cGroup_GetSize(GroupScriptArg* args) {
    volatile int size; /* the original goes through a stack temporary */

    size = Group_FromHandle(args[0].p)->count;
    return size;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D96D0 */

/* merge_units: begin func_003D9740 */
#pragma push /* merge_units */
/* Contains(group, obj): nonzero when obj is a member. */
int Script_cGroup_Contains(GroupScriptArg* args)
{
    cGroup* group = Group_FromHandle(args[0].p);
    return Script_IsGroupMember(group, Script_ValueToObj(args[1].p));
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9740 */

/* merge_units: begin func_003D9790 */
#pragma push /* merge_units */
/* Find(group, obj): looks obj up in the group. */
int Script_cGroup_Find(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    volatile int found = Group_FindByObject(group, Script_ValueToObj(args[1].p));
    return found;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9790 */

/* merge_units: begin func_003D97E0 */
#pragma push /* merge_units */
/* Print(group) */
int Script_cGroup_Print(GroupScriptArg* args)
{
    Group_Print(Group_FromHandle(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D97E0 */

/* merge_units: begin func_003D9810 */
#pragma push /* merge_units */
/* Randomize(group) */
int Script_cGroup_Randomize(GroupScriptArg* args) {
    Group_Shuffle(Group_FromHandle(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9810 */

/* merge_units: begin func_003D9840 */
#pragma push /* merge_units */
/* RemoveAll(group) */
int Script_cGroup_RemoveAll(GroupScriptArg* args) {
    Group_RemoveAll(Group_FromHandle(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9840 */

/* merge_units: begin func_003D9870 */
#pragma push /* merge_units */
/* Remove(group, obj) */
int Script_cGroup_Remove(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    Group_RemoveObject(group, Script_ValueToObj(args[1].p));
    return 0;
}

/* AddDup(group, obj): appends without the duplicate check. */
int Script_cGroup_AddDup(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    Group_AddObjectDup(group, Script_ValueToObj(args[1].p));
    return 0;
}

/* Add(group, obj) */
int Script_cGroup_Add(GroupScriptArg* args) {
    cGroup* group = Group_FromHandle(args[0].p);
    Group_AddObject(group, Script_ValueToObj(args[1].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9870 */