#include "types.h"
#pragma cplusplus on
typedef struct { float m[16]; } BwMtx_f3;
typedef struct { float v[4]; } BwVec_f3;
class BwSrc_f3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC];
    BwMtx_f3 xform;
    unsigned char dirty;
};
typedef struct {
    unsigned char changed; char pad1[0xF];
    BwMtx_f3 xform;
    BwMtx_f3 delta;
    BwVec_f3 vel;
    BwVec_f3 velRate;
} BwDst_f3;
typedef struct { char pad[0x50]; BwSrc_f3* src; BwDst_f3* dst; } BwActor_f3;
extern "C" {
extern int Mtx_Equal(BwMtx_f3* a, BwMtx_f3* b);
extern void Mtx_InvertRigid_13ECA0(BwMtx_f3* out, BwMtx_f3* in);
extern BwMtx_f3* Quat_MulInverse(BwMtx_f3* a, BwMtx_f3* b);
extern void Mtx_Copy_23E150(BwMtx_f3* d, BwMtx_f3* s);
extern BwVec_f3* func_00133EC0(BwMtx_f3* m);
extern void Sphere_FromCenter(BwVec_f3* out, BwVec_f3* a, BwVec_f3* b);
extern BwVec_f3* Vec4_ClearW(BwVec_f3* v);
extern void Vec4_Copy(BwVec_f3* d, BwVec_f3* s);
extern void Vec4_Scale(BwVec_f3* out, BwVec_f3* in, float s);
void Actor_BaseWorldUpdate(BwActor_f3* self, float dt);
}
void Actor_BaseWorldUpdate(BwActor_f3* self, float dt)
{
    BwMtx_f3 inv;
    BwVec_f3 diff;
    BwVec_f3 rate;
    BwSrc_f3* src;
    BwMtx_f3* sx;
    BwDst_f3* dst;
    if (self->dst == 0) return;
    src = self->src;
    if (src == 0) return;
    if (src->dirty) {
        src->Refresh();
    }
    dst = self->dst;
    sx = &src->xform;
    dst->changed = !Mtx_Equal(sx, &dst->xform);
    Mtx_InvertRigid_13ECA0(&inv, &dst->xform);
    Mtx_Copy_23E150(&dst->delta, Quat_MulInverse(&inv, sx));
    Sphere_FromCenter(&diff, func_00133EC0(sx), func_00133EC0(&dst->xform));
    Vec4_Copy(&dst->vel, Vec4_ClearW(&diff));
    Vec4_Scale(&rate, &dst->vel, 1.0f / dt);
    Vec4_Copy(&dst->velRate, Vec4_ClearW(&rate));
    Mtx_Copy_23E150(&dst->xform, sx);
}