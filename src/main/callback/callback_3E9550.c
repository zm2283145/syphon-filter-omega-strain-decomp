#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_9550;
struct M4_9550 { V4_9550 r[4]; M4_9550() {} };
class Obj_9550 {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual M4_9550 GetMatrix();
};
typedef struct { char pad[0x60]; int target; char pad64[4]; int id; } S_9550;
extern "C" {
Obj_9550* Object_LookupById(int* id);
float Vec4_GetX(V4_9550* v);
float Vec4_GetY(V4_9550* v);
float Vec4_GetZ(V4_9550* v);
void Mtx_MakeAxisRotation(M4_9550* m, float x, float y, float z, float a);
void func_003E8040(int t, M4_9550* m);
extern float D_00493980;
}
static inline void Mul_9550(M4_9550* t, M4_9550* b) {
    asm {
        lqc2 vf4, 0x0(t)
        lqc2 vf5, 0x10(t)
        lqc2 vf6, 0x20(t)
        lqc2 vf7, 0x30(t)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(t)
        sqc2 vf13, 0x10(t)
        sqc2 vf14, 0x20(t)
        sqc2 vf15, 0x30(t)
    }
}
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void func_003E9550(S_9550* self)
{
    Obj_9550* o = Object_LookupById(&self->id);
    if (o != 0) {
        M4_9550 m = o->GetMatrix();
        M4_9550 rot;
        V4_9550 axis;
        float k;
        axis.x = 1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
        axis.w = 0.0f;
        Mtx_MakeAxisRotation(&rot, Vec4_GetX(&axis), Vec4_GetY(&axis), Vec4_GetZ(&axis), -1.5707964f);
        { M4_9550* t = &m; M4_9550* b = &rot; Mul_9550(t, b); }
        k = D_00493980;
        m.r[0].x *= k;
        m.r[0].y *= k;
        m.r[0].z *= k;
        m.r[1].x *= k;
        m.r[1].y *= k;
        m.r[1].z *= k;
        m.r[2].x *= k;
        m.r[2].y *= k;
        m.r[2].z *= k;
        func_003E8040(self->target, &m);
    }
}


