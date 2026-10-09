/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);
extern int func_0015C100(void* obj);
extern cNodeList* func_00269810(void* obj);
extern void* func_003D9990(ScriptGroup* group, int index);

/* push_back on a list whose sentinel node is at +4. */
ListPos* func_00269530(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

/* Script native: cNodeList.Get(index = args[1]); returns the element's script handle.
 * volatile mirrors the original stack temporary. */
int Script_cNodeList_Get(ScriptArg* args) {
    volatile int arg1 = args[1].i;
    int index = arg1;

    return func_0015C100(func_003D9990(func_00269810(args[0].p)->group, index));
}

/* Script native: cNodeList.GetSize(). volatile mirrors the original stack temporary. */
int Script_cNodeList_GetSize(ScriptArg* args) {
    volatile int count = func_00269810(args[0].p)->group->count;
    return count;
}
