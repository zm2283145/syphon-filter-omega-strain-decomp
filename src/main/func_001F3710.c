/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_001F3030(void);
extern ObjVec* func_001F3760(ObjVec*);
extern ObjVec* func_001F3790(ObjVec*);
extern ObjVec* func_001F37C0(ObjVec*);
extern int func_0020B3F0(int, int);

int func_001F3710(int a0, int a1) {
    return func_0020B3F0(a0, a1);
}

int func_001F3720(void) {
    return func_001F3030();
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* func_001F3730(ObjVec* self) {
    func_001F3760(self);
    self->owned = 1;
    return self;
}

ObjVec* func_001F3760(ObjVec* self) {
    func_001F3790(self);
    return self;
}

ObjVec* func_001F3790(ObjVec* self) {
    func_001F37C0(self);
    return self;
}
