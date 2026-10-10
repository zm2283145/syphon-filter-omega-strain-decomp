#include "types.h"
#pragma cplusplus on
class C6Obj_179B70 {
public:
    int m0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
};
struct C6Own_179B70 { char pad[0x60]; C6Obj_179B70* obj; };
extern "C" void func_003CE790(C6Own_179B70*);
extern "C" void func_00179B70(C6Own_179B70* self) {
    func_003CE790(self);
    self->obj->v10();
}