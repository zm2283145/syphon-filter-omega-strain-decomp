/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern int D_004F8488;  /* script array type key */
extern int* func_002690E0(void);

/* Cast from script object to array (identity). */
void* func_002690C0(void* self) {
    return self;
}

int* func_002690D0(void) {
    return func_002690E0();
}

int* func_002690E0(void) {
    return &D_004F8488;
}
