/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* func_001F30A0(ObjVec*);
extern ObjVec* func_001F30D0(ObjVec*);
extern ObjVec* func_001F3100(ObjVec*);

void* func_001F3060(void* self) {
    return self;
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* func_001F3070(ObjVec* self) {
    func_001F30A0(self);
    self->owned = 1;
    return self;
}

ObjVec* func_001F30A0(ObjVec* self) {
    func_001F30D0(self);
    return self;
}

ObjVec* func_001F30D0(ObjVec* self) {
    func_001F3100(self);
    return self;
}
