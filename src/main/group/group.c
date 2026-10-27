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

extern int cSystem_SOBJ_toInt(int obj);                    /* object -> script value (identity) */
extern int cSystem_SOBJ_convert(void* value);                /* script value -> object (identity) */
extern cGroup* cGroup_SOBJ_convert(void* handle);        /* script handle -> cGroup (identity) */
extern int cGroup_Get(cGroup* group, int index);     /* bounds-checked member lookup */
extern unsigned char cGroup_Contains(cGroup* group, int obj);
extern int cGroup_Find_cSystemP(cGroup* group, int obj);
extern void cGroup_Print(cGroup* group);             /* debug print (empty in retail) */
extern float cGroup_Randomize(cGroup* group);            /* shuffles the members */
extern void Group_RemoveAll(cGroup* group);             /* removes every member */
extern void cGroup_Add(cGroup* group, int obj);  /* appends if not already present */
extern int cGroup_Remove(cGroup* group, int obj);
extern int cGroup_AddDup(cGroup* group, int obj); /* appends even if already present */

/* merge_units: begin func_003D96D0 */
#pragma push /* merge_units */

/* Get(group, index): returns the member at index (0 when out of range). */
int Script_cGroup_Get(GroupScriptArg* args) {
    volatile int index = args[1].i; /* stack temporary in the original */

    return cSystem_SOBJ_toInt(cGroup_Get(cGroup_SOBJ_convert(args[0].p), index));
}

/* GetSize(group): number of members. */
int Script_cGroup_GetSize(GroupScriptArg* args) {
    volatile int size; /* the original goes through a stack temporary */

    size = cGroup_SOBJ_convert(args[0].p)->count;
    return size;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D96D0 */

/* merge_units: begin func_003D9740 */
#pragma push /* merge_units */
/* Contains(group, obj): nonzero when obj is a member. */
int Script_cGroup_Contains(GroupScriptArg* args)
{
    cGroup* group = cGroup_SOBJ_convert(args[0].p);
    return cGroup_Contains(group, cSystem_SOBJ_convert(args[1].p));
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9740 */

/* merge_units: begin func_003D9790 */
#pragma push /* merge_units */
/* Find(group, obj): looks obj up in the group. */
int Script_cGroup_Find(GroupScriptArg* args) {
    cGroup* group = cGroup_SOBJ_convert(args[0].p);
    volatile int found = cGroup_Find_cSystemP(group, cSystem_SOBJ_convert(args[1].p));
    return found;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9790 */

/* merge_units: begin func_003D97E0 */
#pragma push /* merge_units */
/* Print(group) */
int Script_cGroup_Print(GroupScriptArg* args)
{
    cGroup_Print(cGroup_SOBJ_convert(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D97E0 */

/* merge_units: begin func_003D9810 */
#pragma push /* merge_units */
/* Randomize(group) */
int Script_cGroup_Randomize(GroupScriptArg* args) {
    cGroup_Randomize(cGroup_SOBJ_convert(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9810 */

/* merge_units: begin func_003D9840 */
#pragma push /* merge_units */
/* RemoveAll(group) */
int Script_cGroup_RemoveAll(GroupScriptArg* args) {
    Group_RemoveAll(cGroup_SOBJ_convert(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9840 */

/* merge_units: begin func_003D9870 */
#pragma push /* merge_units */
/* Remove(group, obj) */
int Script_cGroup_Remove(GroupScriptArg* args) {
    cGroup* group = cGroup_SOBJ_convert(args[0].p);
    cGroup_Remove(group, cSystem_SOBJ_convert(args[1].p));
    return 0;
}

/* AddDup(group, obj): appends without the duplicate check. */
int Script_cGroup_AddDup(GroupScriptArg* args) {
    cGroup* group = cGroup_SOBJ_convert(args[0].p);
    cGroup_AddDup(group, cSystem_SOBJ_convert(args[1].p));
    return 0;
}

/* Add(group, obj) */
int Script_cGroup_Add(GroupScriptArg* args) {
    cGroup* group = cGroup_SOBJ_convert(args[0].p);
    cGroup_Add(group, cSystem_SOBJ_convert(args[1].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D9870 */