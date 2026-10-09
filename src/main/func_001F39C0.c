/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void ScalarCollection_Init(ScalarCollection*);

ScalarCollection* func_001F39C0(ScalarCollection* self) {
    ScalarCollection_Init(self);
    return self;
}
