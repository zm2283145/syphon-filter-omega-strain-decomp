/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_001F4170(void);

/* Address of the data pointer. */
char** func_001F4150(ObjVec* v) {
    return &v->data;
}

void func_001F4160(void) {
    func_001F4170();
}
