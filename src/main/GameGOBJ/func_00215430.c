#include "types.h"
#pragma cplusplus on
#pragma opt_strength_reduction off
class C4It215 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Fn(int a);
};
struct C4Obj215 { char pad[0x11C]; int count; C4It215** items; };
extern "C" void func_00215430(C4Obj215* o) {
    int i;
    for (i = 0; i < o->count; i++) {
        o->items[i]->Fn(-1);
    }
}
