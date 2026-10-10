#include "types.h"

typedef struct { void* vtable; char kind; char pad[11]; Vec4 rot; } MotionNode;
extern char D_004DFC50[];
extern void Quat_ComposeOffset(Vec4* out, Vec4* a, Vec4* b);
extern void func_00132800(Vec4* dst, Vec4* src);

/* Base copy-constructor: sets the vtable, copies the kind byte and the composed rotation. */
MotionNode* MotionNode_BaseCopy(MotionNode* self, MotionNode* src, Vec4* offset)
{
    Vec4 q;
    self->vtable = D_004DFC50;
    self->kind = src->kind;
    Quat_ComposeOffset(&q, &src->rot, offset);
    func_00132800(&self->rot, &q);
    return self;
}
