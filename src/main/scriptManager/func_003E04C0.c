#include "types.h"
#pragma cplusplus on
class D2_ScriptObj {
public:
    virtual void v0();
    virtual void v1();
    virtual int* GetId();
    int f4;
    int f8;
    int fC;
};
struct D2_SObj : public D2_ScriptObj { };
extern "C" int Script_ObjectToId(D2_ScriptObj* obj) {
    int id = -1;
    if (obj != 0) {
        id = *obj->GetId();
        if (id == obj->fC) id |= 0x80000000;
    }
    return id;
}
#pragma cplusplus reset