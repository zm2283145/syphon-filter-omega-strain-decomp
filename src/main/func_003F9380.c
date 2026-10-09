/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (calls into MoviePlayer.cc);
 * functions are named by address until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_0036DFB0(void*, void*, int*);
extern int func_0036E5D0(void*);
extern int func_003F8450(Unk3F9380*);
extern int func_003F8D20(Unk3F9380*);

/* Constructor: clears the object, copies *src into the second sub-object, then runs two setup passes. */
Unk3F9380* func_003F9380(Unk3F9380* self, int* src, int arg) {
    self->unk00[0] = 0;
    self->unk00[1] = 0;
    self->unk00[2] = 0;
    self->unk00[3] = 0;
    self->unk00[4] = 0;
    self->unk00[5] = 0;
    self->unk00[6] = 0;
    self->unk00[7] = 0;
    self->unk00[8] = 0;
    self->unk00[9] = 0;
    self->unk00[10] = 0;
    self->unk00[11] = 0;
    self->unk00[12] = 0;
    self->unk00[13] = 0;
    self->unk00[14] = 0;
    self->unk00[15] = 0;
    self->unk00[16] = 0;
    self->unk00[17] = 0;
    self->unk00[18] = 0;
    self->unk00[19] = 0;
    func_0036E5D0(self->unk6C);
    self->unk188 = 0;
    self->unk18C = 0;
    func_0036E5D0(self->unk190);
    self->unk22C = arg;
    self->unk230 = 0;
    self->unk231 = 0;
    self->unk232 = 0;
    self->unk233 = 0;
    self->unk234 = 0;
    self->unk235 = 0;
    self->unk236 = 1;
    func_0036DFB0(self->unk190, src + 1, src);
    func_003F8D20(self);
    func_003F8450(self);
    return self;
}
