#pragma cplusplus on
#include "types.h"
struct E8Mtx { float m[12]; float px, py, pz, pw; E8Mtx() {} float* Pos() { return &px; } float Z() { return pz; } };
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct E8Obj {
    V4(v00) V4(v04) V4(v08) V4(v0C) V4(v10) V4(v14) V4(v18) V4(v1C)
    V4(v20) V4(v24) V4(v28) V4(v2C) V4(v30) V4(v34)
    virtual void v38(); virtual void v39(); virtual void v3A();
    virtual E8Mtx GetMatrix(); /* 0xF4 */
};
struct E8Nav {
    char pad00[8];
    float y08;          /* 0x08 */
    char pad0C[0x28 - 0x0C];
    float y28;          /* 0x28 */
    char pad2C[0x54 - 0x2C];
    int node;           /* 0x54 */
    char pad58[4];
    int target;         /* 0x5C */
    char pad60[0x70 - 0x60];
    E8Obj* obj;         /* 0x70 */
};
extern "C" void func_00160C40(E8Nav* self, int n);
extern "C" int func_0015D510(int n, float* pos, int flags, int ex);
extern "C" void func_0015FDD0(E8Nav* self, int n)
{
    func_00160C40(self, -1);
    if (n >= 0 && n != self->target) {
        self->target = n;
        int r = func_0015D510(n, self->obj->GetMatrix().Pos(), 0x80, -1);
        if (r >= 0) self->node = r;
    }
    float z = self->obj->GetMatrix().Z();
    self->y08 = z;
    self->y28 = z;
}
