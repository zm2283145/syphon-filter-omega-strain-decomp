/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"
#include "Loader_types.h"

extern int func_0013BCB0(LoaderObj* obj, int a1);

/* Initialise via func_0013BCB0, then store a2 in unk0C. */
int func_001C0500(LoaderObj* obj, int a1, int a2) {
    int result;

    result = func_0013BCB0(obj, a1);
    obj->unk0C = a2;
    return result;
}
