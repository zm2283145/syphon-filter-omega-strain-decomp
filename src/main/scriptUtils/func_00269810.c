/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern int D_004F83F8;  /* cNodeList script type key */
extern char D_00555070[];  /* script manager */
extern int ScriptFilter_Dispatch(void* manager, void* receiver, void* event);
extern int* func_00269830(void);

/* Cast from script object to cNodeList (identity). */
void* func_00269810(void* self) {
    return self;
}

int* func_00269820(void) {
    return func_00269830();
}

int* func_00269830(void) {
    return &D_004F83F8;
}

/* Returns the cNodeList script type key. */
int cNodeList_v0B(void) {
    return *func_00269830();
}

/* Script event filter: dispatches to script handlers through the script manager. */
int cNodeList_v0C(void* self, void* event) {
    return ScriptFilter_Dispatch(D_00555070, self, event);
}
