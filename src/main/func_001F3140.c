/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* func_001F3170(Word*, int);
extern Word* func_001F31B0(Word*);

Word* func_001F3140(Word* self, int value) {
    func_001F3170(self, value);
    return self;
}

Word* func_001F3170(Word* self, int value) {
    func_001F31B0(self);
    self->value = value;
    return self;
}
