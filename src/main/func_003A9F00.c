/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (just before skeleton.cc);
 * functions are named by address until real names are known.
 */

#include "loose03_types.h"

extern int SkelNodes_Construct(SkelNodes*);
extern void func_003A9450(SkelNodes*);

void func_003A9F00(SkelNodes* self) {
    self->unk14 = 0;
    func_003A9450(self);
}

/* Sets unk14 then constructs the node set. */
int func_003A9F10(SkelNodes* self) {
    self->unk14 = 1;
    return SkelNodes_Construct(self);
}
