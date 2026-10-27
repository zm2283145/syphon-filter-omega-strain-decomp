/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int std_list_deleter_voidPtr_insert(HotboxListIter* out, Tree* list, HotboxListIter* pos, int* value);

/* Inserts value with end() as the position hint; the result iterator is discarded. */
int cLList_cHotboxPtr_PushBackActual(Tree* list, int* value) {
    HotboxListIter end;
    HotboxListIter result;

    end.node = (HotboxListNode*)&list->header;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
