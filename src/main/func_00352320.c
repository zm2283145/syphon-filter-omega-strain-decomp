/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int func_003527A0(Member3527A0* dst, Member3527A0* src);

/* Rec352320 copy constructor. */
Rec352320* func_00352320(Rec352320* self, Rec352320* src) {
    Member352320* body;

    self->unk00 = src->unk00;
    body = &self->unk04;
    func_003527A0(&body->unk00, &src->unk04.unk00);
    body->unk0C = src->unk04.unk0C;
    return self;
}
