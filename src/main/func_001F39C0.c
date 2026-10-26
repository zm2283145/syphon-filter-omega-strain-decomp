/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void ScalarCollection_Init(ScalarCollection*);

ScalarCollection* std_list_imp_voidPtr_ctor(ScalarCollection* self) {
    ScalarCollection_Init(self);
    return self;
}
