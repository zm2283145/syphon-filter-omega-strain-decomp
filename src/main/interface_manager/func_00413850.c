/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "types.h"
#include "interface_manager_types.h"

/* Address of record `index`. */
IfRec12* func_00413850(IfRecVec* v, int index) {
    return v->data + index;
}

/* Number of records. */
int func_00413870(IfRecVec* v) {
    return v->count;
}
