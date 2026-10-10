#include "types.h"
typedef struct { char pad0[0x50]; unsigned char dirty; char pad1[0x4F]; void* parent; } XfNode;
extern void Xform_EvalAncestors(void* p);
extern void Xform_ComputeWorld(XfNode* x);
void Xform_RefreshDirty(XfNode* x)
{
    if (x->dirty) {
        if (x->parent) {
            Xform_EvalAncestors(x->parent);
        }
        Xform_ComputeWorld(x);
        x->dirty = 0;
    }
}