/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "texman_types.h"

extern TexListIter* func_00164940(TexListIter* result, void* list, TexListIter* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
TexListIter* func_00380170(void* list, int* value) {
    TexListIter end;
    TexListIter result;

    end.node = (TexListNode*)((char*)list + 4);
    return func_00164940(&result, list, &end, value);
}
