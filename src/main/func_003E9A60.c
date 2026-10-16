#pragma cplusplus on
#include "types.h"
#pragma opt_rebuildconditionals off
typedef struct { float m[4][4]; } __attribute__((aligned(16))) M9A60;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V9A60;
struct O9A60 { char pad[0xC]; int serial; };
struct H9A60 { O9A60* p; int serial; };
extern "C" {
extern H9A60 D_00583878;
void* Camera_GetNode(O9A60* o);
void Transform_GetInverseMatrix(M9A60* out, void* t);
}

static inline bool Valid9A60(H9A60* h)
{
    O9A60* t = h->p;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if ((t->serial == h->serial) == false)
            ok = false;
    return ok != false;
}
static inline O9A60* Get9A60(H9A60* h)
{
    return Valid9A60(h) ? (O9A60*)*(O9A60* volatile*)&h->p : (O9A60*)0;
}
extern "C" void func_003E9A60(V9A60* v)
{
    O9A60* o = Get9A60(&D_00583878);
    if (o) {
        M9A60 m;
        M9A60* pm;
        Transform_GetInverseMatrix(&m, Camera_GetNode(o));
        pm = &m;
        asm {
            lqc2 vf8, 0x0(v)
            lqc2 vf4, 0x0(pm)
            lqc2 vf5, 0x10(pm)
            lqc2 vf6, 0x20(pm)
            lqc2 vf7, 0x30(pm)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(v)
        }
    }
}



