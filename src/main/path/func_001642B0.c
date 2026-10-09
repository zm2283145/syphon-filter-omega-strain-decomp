/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver list insertion (push_back on listB).
 */

#include "types.h"
#include "path_types.h"

extern int PathList_PushBack(PathList* list, int* value);

void func_001642B0(PathReceiver* self, int value) {
    volatile int tmp = value; /* original stack temporary */
    PathList_PushBack(&self->listB, (int*)&tmp);
}
