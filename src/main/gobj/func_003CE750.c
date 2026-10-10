#include "types.h"
#pragma cplusplus on
class C4C3CE {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void PreLogic();
};
struct C4Act3CE { char pad[0x58]; C4C3CE* ctl; };
extern "C" void Actor_BasePreLogic(C4Act3CE* a) {
    if (a->ctl) a->ctl->PreLogic();
}