/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef struct Mtx { float m[4][4]; } Mtx;

struct Transform {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update(); /* +0x58 */
    char pad04[0x10 - 4];
    Mtx matrix;          /* +0x10 */
    unsigned char dirty; /* +0x50 */
};

extern "C" Mtx* Mtx_Copy(Mtx* dst, Mtx* src);
extern "C" Mtx* Mtx_InvertRigid(Mtx* m);

/* Writes the inverse of the transform world matrix to out (updating it first when dirty). */
extern "C" void Transform_GetInverseMatrix(Mtx* out, Transform* xf)
{
    Mtx tmp;
    if (xf->dirty)
    xf->Update();
    Mtx_Copy(out, Mtx_InvertRigid(Mtx_Copy(&tmp, &xf->matrix)));
}
