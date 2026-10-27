/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver list insertion (push_back on listB).
 */

#include "types.h"
#include "path_types.h"

extern int std_list_cPathSystemRequestPtr_push_back(PathList* list, int* value);

void cPathSystem_FreeRequest(PathReceiver* self, int value) {
    volatile int tmp = value; /* original stack temporary */
    std_list_cPathSystemRequestPtr_push_back(&self->listB, (int*)&tmp);
}
