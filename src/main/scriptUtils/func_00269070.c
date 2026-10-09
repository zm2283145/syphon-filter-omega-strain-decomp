/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern int func_00269090(int value);
extern void* func_002690C0(void* obj);

void func_00269070(void) {
}

int func_00269080(int value) {
    return func_00269090(value);
}

/* Identity. volatile mirrors the original stack temporary. */
int func_00269090(int value) {
    volatile int v = value;
    return v;
}

void* func_002690B0(void* obj) {
    return func_002690C0(obj);
}
