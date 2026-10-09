/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GenInfoObject_types.h"

extern GioListPos* List_InsertBefore(GioListPos* result, void* list, GioListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
GioListPos* func_00439C40(void* list, int value) {
    GioListPos end;
    GioListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
