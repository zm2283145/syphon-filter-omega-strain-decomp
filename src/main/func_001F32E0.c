/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int Motion_Lookup(int, int);
extern int cPointer_cSkaNode_ctor_cSkaNodeP(Unk1F32E0*, int);
extern void cSkaInitListOfPointers_cSkaTransBLEND_CopyPointerContentsToArray(int, ObjVec*);
extern ObjVec* cArray_cSkaTransBLEND_ctor_void(ObjVec*);

Unk1F32E0* cSkaSwitchItem_ctor_cString16NR_cSkaAnimationSetR_cSkaInitListOfPointersR(Unk1F32E0* self, int a1, int a2, int a3) {
    cPointer_cSkaNode_ctor_cSkaNodeP(self, Motion_Lookup(a2, a1));
    cArray_cSkaTransBLEND_ctor_void(&self->list);
    cSkaInitListOfPointers_cSkaTransBLEND_CopyPointerContentsToArray(a3, &self->list);
    return self;
}
