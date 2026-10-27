/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_deleter_voidPtr_ctor_void(ScalarCollection*);

ScalarCollection* std_list_imp_voidPtr_ctor(ScalarCollection* self) {
    std_list_deleter_voidPtr_ctor_void(self);
    return self;
}
