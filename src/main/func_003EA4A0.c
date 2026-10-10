#include "types.h"
#pragma cplusplus on
class B4Obj4 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsForced();
    char pad[0x1C];
    float f20;
    float f24;
};
extern "C" int Random_Next(void);
extern "C" float D_00493988;
extern "C" bool func_003EA4A0(B4Obj4* p) {
    float chance;
    if (!p->IsForced() && p->f20 < D_00493988) return 0;
    chance = p->f20 * p->f24;
    return (float)Random_Next() / 2147483648.0f < chance;
}