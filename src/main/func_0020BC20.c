/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* func_0020BC50(Word*, int, int);
extern Word* func_0020BC90(Word*);

Word* func_0020BC20(Word* self, int unused, int value) {
    func_0020BC50(self, unused, value);
    return self;
}

Word* func_0020BC50(Word* self, int unused, int value) {
    func_0020BC90(self);
    self->value = value;
    return self;
}
