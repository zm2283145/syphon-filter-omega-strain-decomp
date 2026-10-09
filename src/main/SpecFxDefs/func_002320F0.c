/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper.
 */

#include "types.h"
#include "SpecFxDefs_types.h"

extern SpecListPos* List_InsertBefore(SpecListPos* result, void* list, SpecListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
SpecListPos* func_002320F0(void* list, int* value) {
    SpecListPos end;
    SpecListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
