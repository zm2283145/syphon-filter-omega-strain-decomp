/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern char D_004D9778[];
extern char D_004D9798[];
extern char D_004D9788[];

/* Inlined constructor chain: three vtables stored in turn (base to derived). */
VObject* func_001652E0(VObject* self) {
    self->vtable = D_004D9778;
    self->vtable = D_004D9788;
    self->vtable = D_004D9798;
    return self;
}
