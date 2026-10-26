/*
 * Matched functions (byte-identical with the retail executable).
 * Global special-effect list registration.
 */

#include "types.h"
#include "specfx_types.h"

extern char D_0055C0A8[];   /* global effect list */
extern SpecFxListPos* List_InsertBefore(SpecFxListPos* result, void* list, SpecFxListPos* pos, int* value);
extern SpecFxListPos* std_list_cSfxSchedulerPtr_push_back(void* list, int* value);

/* Appends fx to the global effect list. */
void SpecFx_Register(SpecFx* fx) {
    int value[1];

    value[0] = (int)fx;
    std_list_cSfxSchedulerPtr_push_back(D_0055C0A8, value);
}

/* push_back on a list whose sentinel node is at +4. */
SpecFxListPos* std_list_cSfxSchedulerPtr_push_back(void* list, int* value) {
    SpecFxListPos end;
    SpecFxListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
