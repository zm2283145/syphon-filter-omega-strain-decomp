/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern char D_004DFD80[]; /* cMessage vtable */

/* Copy constructor: sets the vtable and copies the payload fields from src. */
cMessage* cMessage_ctor(cMessage* self, cMessage* src) {
    self->vtable = D_004DFD80;
    self->args[0] = src->args[0];
    self->args[1] = src->args[1];
    self->args[2] = src->args[2];
    self->args[3] = src->args[3];
    self->args[4] = src->args[4];
    self->args[5] = src->args[5];
    self->args[6] = src->args[6];
    self->flag = src->flag;
    return self;
}
