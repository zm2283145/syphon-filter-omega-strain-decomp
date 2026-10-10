#pragma cplusplus on
#include "types.h"
typedef struct Vec3SA { float x, y, z; } Vec3SA;
struct Vec4SA { float x, y, z, w; Vec4SA() {} Vec4SA(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0; } };
typedef struct XfSA { int a, b; Vec3SA pos; } XfSA;
struct SkelSA {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void SetName(void* n);
    virtual void SetPos(Vec4SA* p);
    virtual void v0E(); virtual void v0F();
    virtual void Attach(void* parent, int f);
    char pad[0xBC];
    XfSA* xf;
};
extern "C" char D_0055C9F0[];
extern "C" void SkelNode_AttachParent(SkelSA* n, void* parent)
{
    XfSA* xf;
    if (parent) {
        n->Attach(parent, 1);
    }
    xf = n->xf;
    Vec4SA v(xf->pos.x, xf->pos.y, xf->pos.z);
    v.w = 1.0f;
    n->SetPos(&v);
    n->SetName(D_0055C9F0);
}