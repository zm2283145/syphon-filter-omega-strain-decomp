/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* func_001F3B20(ObjVec*);
extern ObjVec* func_001F3B50(ObjVec*);
extern ObjVec* func_001F3B80(ObjVec*);
extern ObjVec* func_001F3BB0(ObjVec*);

MotionEntry24* MotionEntry_Ctor(MotionEntry24* self, int a1, int a2, float f) {
    func_001F3B20(&self->list);
    self->unk10 = f;
    self->unk14 = f;
    self->unk18 = -1;
    self->unk1C = a1;
    self->unk1D = a2;
    self->unk20 = -1;
    return self;
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* func_001F3B20(ObjVec* self) {
    func_001F3B50(self);
    self->owned = 1;
    return self;
}

ObjVec* func_001F3B50(ObjVec* self) {
    func_001F3B80(self);
    return self;
}

ObjVec* func_001F3B80(ObjVec* self) {
    func_001F3BB0(self);
    return self;
}
