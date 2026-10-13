/*
 * main/group: 7 files, 003D96D0-003D9870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin Script_cGroup_Get */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_Get */

/* merge_units: begin Script_cGroup_Contains */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* Group_FromHandle(int handle);
#endif /* merge_units */
#define Group_FromHandle(a0) ((void *)Group_FromHandle((void *)(a0))) /* merge_units */

extern int func_003CB1C0(int handle);
extern unsigned char Script_IsGroupMember(void* group, int obj);
/* Script: cGroup.Contains(obj). */
int Script_cGroup_Contains(int* args)
{
    void* group = Group_FromHandle(args[0]);
    return Script_IsGroupMember(group, func_003CB1C0(args[1]));
}
#undef Group_FromHandle /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_Contains */

/* merge_units: begin Script_cGroup_Find */
#pragma push /* merge_units */
typedef struct ScriptArgs2 {
    int group;
    int name;
} ScriptArgs2;

#if 0 /* merge_units */
extern int Group_FromHandle(int handle);
#endif /* merge_units */
#define Group_FromHandle(a0) ((int)Group_FromHandle((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_003CB1C0(int str);
#endif /* merge_units */
#define func_003CB1C0(a0) (func_003CB1C0((a0))) /* merge_units */

extern int Group_FindByObject(int group, int key);

/* Script native: cGroup.Find(name). */
int Script_cGroup_Find(ScriptArgs2* args) {
    int group = Group_FromHandle(args->group);
    volatile int found = Group_FindByObject(group, func_003CB1C0(args->name));
    return found;
}
#undef Group_FromHandle /* merge_units */
#undef func_003CB1C0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_Find */

/* merge_units: begin Script_cGroup_Print */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* Group_FromHandle(int handle);
#endif /* merge_units */
#define Group_FromHandle(a0) ((void *)Group_FromHandle((void *)(a0))) /* merge_units */

extern void func_003D99F0(void* group);
/* Script: cGroup.Print(). */
int Script_cGroup_Print(int* args)
{
    func_003D99F0(Group_FromHandle(args[0]));
    return 0;
}
#undef Group_FromHandle /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_Print */

/* merge_units: begin Script_cGroup_Randomize */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGroup script native: shuffle the member order.
 */


extern float Group_Shuffle(cGroup* group);    /* shuffles the members */

/* Randomize(group) */
int Script_cGroup_Randomize(GroupScriptArg* args) {
    Group_Shuffle(Group_FromHandle(args[0].p));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_Randomize */

/* merge_units: begin Script_cGroup_RemoveAll */
#pragma push /* merge_units */
#include "scriptUtils_types.h"

#if 0 /* merge_units */
extern void* Group_FromHandle(int handle);
#endif /* merge_units */
#define Group_FromHandle(a0) ((void *)Group_FromHandle((void *)(a0))) /* merge_units */

extern void func_003D9AC0(void* group);

/* Script native: cGroup.RemoveAll(group = args[0]). */
int Script_cGroup_RemoveAll(ScriptArg* args) {
    func_003D9AC0(Group_FromHandle(args[0].i));
    return 0;
}
#undef Group_FromHandle /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_RemoveAll */

/* merge_units: begin Script_cGroup_Remove */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGroup script natives: add / remove members.
 */


extern void Group_AddObject(cGroup* group, int obj);
extern int Group_RemoveObject(cGroup* group, int obj);
#if 0 /* merge_units */
extern int func_003CB1C0(void* value);                 /* script value -> object (identity) */
#endif /* merge_units */
#define func_003CB1C0(a0) (func_003CB1C0((int)(a0))) /* merge_units */

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
#undef func_003CB1C0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Script_cGroup_Remove */
