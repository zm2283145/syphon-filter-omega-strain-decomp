/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern Word* func_001F3C20(Word*, int);
extern Word* func_001F3C60(Word*);

Word* func_001F3BF0(Word* self, int value) {
    func_001F3C20(self, value);
    return self;
}

Word* func_001F3C20(Word* self, int value) {
    func_001F3C60(self);
    self->value = value;
    return self;
}
