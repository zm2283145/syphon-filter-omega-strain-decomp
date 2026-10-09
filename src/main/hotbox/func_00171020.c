/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int List_InsertBefore(HotboxListIter* out, Tree* list, HotboxListIter* pos, int* value);

/* Inserts value with end() as the position hint; the result iterator is discarded. */
int func_00171020(Tree* list, int* value) {
    HotboxListIter end;
    HotboxListIter result;

    end.node = (HotboxListNode*)&list->header;
    return List_InsertBefore(&result, list, &end, value);
}
