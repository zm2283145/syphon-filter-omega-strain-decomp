/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* func_00201E30(Word*, int, int);
extern Word* func_00201E70(Word*);

Word* func_00201E00(Word* self, int unused, int value) {
    func_00201E30(self, unused, value);
    return self;
}

Word* func_00201E30(Word* self, int unused, int value) {
    func_00201E70(self);
    self->value = value;
    return self;
}
