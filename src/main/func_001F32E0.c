/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int Motion_Lookup(int, int);
extern int func_001ADFE0(Unk1F32E0*, int);
extern void func_001F3340(int, ObjVec*);
extern ObjVec* func_001F3730(ObjVec*);

Unk1F32E0* func_001F32E0(Unk1F32E0* self, int a1, int a2, int a3) {
    func_001ADFE0(self, Motion_Lookup(a2, a1));
    func_001F3730(&self->list);
    func_001F3340(a3, &self->list);
    return self;
}
