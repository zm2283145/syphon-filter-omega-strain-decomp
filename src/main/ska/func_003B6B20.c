#include "types.h"

typedef struct Body {
    char part0[0xD0];
    float fD0;
    char padD4[0xC];
    char partE0[0x10];
    char partF0[0x10];
    float f100;
    char pad104[0xC];
    char part110[0x40];
    char part150[0x10];
    int i160;
    int i164;
} Body;

typedef struct Obj178 {
    int id;
    char pad[0xC];
    Body body;
} Obj178;

extern void cSkaAnimAnchor_TreeNode_ctor_cSkaAnimAnchorTreeNodeR(void*, void*);
extern void cQuaternion_ctor_cQuaternionR(void*, void*);
extern void cVector_ctor_cVectorR(void*, void*);
extern void cArray_FixedSize_cVector_4_ctor_cArrayFixedSizeR(void*, void*);

/* Assignment operator: copies each member. */
Obj178* cSkaAnimAnchorListEntry_ctor(Obj178* self, Obj178* other) {
    Body* d;
    self->id = other->id;
    d = &self->body;
    cSkaAnimAnchor_TreeNode_ctor_cSkaAnimAnchorTreeNodeR(d->part0, other->body.part0);
    d->fD0 = other->body.fD0;
    cQuaternion_ctor_cQuaternionR(d->partE0, other->body.partE0);
    cVector_ctor_cVectorR(d->partF0, other->body.partF0);
    d->f100 = other->body.f100;
    cArray_FixedSize_cVector_4_ctor_cArrayFixedSizeR(d->part110, other->body.part110);
    cQuaternion_ctor_cQuaternionR(d->part150, other->body.part150);
    d->i160 = other->body.i160;
    d->i164 = other->body.i164;
    return self;
}
