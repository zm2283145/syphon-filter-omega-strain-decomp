/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00559FA0[];

void* cScriptInterpreter_SOBJ_convert(void* self) {
    return self;
}

int cScriptInterpreter_SOBJ_getClassId(void) {
    return (int)D_00559FA0;
}
