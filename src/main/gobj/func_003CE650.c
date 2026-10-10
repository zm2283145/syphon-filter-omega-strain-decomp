#include "types.h"
#pragma cplusplus on
class D2_Logic {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void Update();
};
typedef struct { int a; int b; } D2_WeakRef;
typedef struct { char pad[0x30]; int id; char pad2[0x24]; D2_Logic* logic; } D2_ActorBase;
extern "C" D2_WeakRef* WeakRef_Capture(D2_WeakRef* r, void* obj);
extern "C" void func_003CE6C0(void* mgr, int* id, D2_WeakRef* r);
extern "C" void* D_00571CD0;
extern "C" void Actor_BaseLogicUpdate(D2_ActorBase* a) {
    if (a->logic != 0) {
        a->logic->Update();
    }
    if (a->id >= 0) {
        D2_WeakRef ref;
        int id[1];
        id[0] = a->id;
        func_003CE6C0(D_00571CD0, id, WeakRef_Capture(&ref, a));
    }
}
#pragma cplusplus reset