#include "types.h"
#pragma cplusplus on
class D6XObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual D6XObj* getNode();
    virtual void attach(void* parent, int flags);
};
extern "C" void Xform_AddChild(void* self, D6XObj* child, int flags)
{
    D6XObj* n = child ? child->getNode() : 0;
    if (n) {
        n->attach(self, flags);
    }
}