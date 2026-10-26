// nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP: transform box by inverse node/transform matrices, union results.
// GQ = lq/sq 128-bit copy idiom (asm only to pin register choice).
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
#pragma opt_common_subs off
#pragma opt_propagation off

struct V4 { float x, y, z, w; V4() {} } __attribute__((aligned(16)));
struct Box { V4 mn, mx; };
struct M44 { float f[16]; } __attribute__((aligned(16)));
struct Xf {
    void** vt; char pad4[0xC];
    M44 m10;
    unsigned char b50;
};
struct XfV {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
};
static inline M44* XfMtx(Xf* t)
{
    if (t->b50) ((XfV*)t)->Update();
    return &t->m10;
}
struct PNode { unsigned char b0; char pad1[0xF]; M44 m10; };
struct Owner { char pad0[0x54]; PNode* p54; };

extern "C" {
void Mtx_InvertRigid_13ECA0(M44* out, M44* in);
void Transform_GetInverseMatrix(M44* out, Xf* t);
V4* Vec4_Assign(V4* d, const V4* s);
void Vec_SetPositionW1(V4* v);
void Mtx_Multiply4b(Box* b);
V4 Mtx_MulVec4(V4* v, M44* m);
V4* Mtx_Multiply4(V4* v, M44* m);
V4* Vec4_Set(V4* o, float x, float y, float z, float w);
void Box_ExtendXYZ(Box* b, V4* v);
}

static inline void TB(Box* b, M44* m)
{
    V4 mn; Vec4_Assign(&mn, &b->mn); Vec_SetPositionW1(&mn);
    V4 mx; Vec4_Assign(&mx, &b->mx); Vec_SetPositionW1(&mx);
    Mtx_Multiply4b(b);
    { V4 t = Mtx_MulVec4(&mn, m); Box_ExtendXYZ(b, &t); }
    { V4 t; Box_ExtendXYZ(b, Mtx_Multiply4(Vec4_Set(&t, mn.x, mn.y, mx.z, 1.0f), m)); }
    { V4 t; Box_ExtendXYZ(b, Mtx_Multiply4(Vec4_Set(&t, mn.x, mx.y, mn.z, 1.0f), m)); }
    { V4 t; Box_ExtendXYZ(b, Mtx_Multiply4(Vec4_Set(&t, mn.x, mx.y, mx.z, 1.0f), m)); }
    { V4 t; Box_ExtendXYZ(b, Mtx_Multiply4(Vec4_Set(&t, mx.x, mn.y, mn.z, 1.0f), m)); }
    { V4 t; Box_ExtendXYZ(b, Mtx_Multiply4(Vec4_Set(&t, mx.x, mn.y, mx.z, 1.0f), m)); }
    { V4 t; Box_ExtendXYZ(b, Mtx_Multiply4(Vec4_Set(&t, mx.x, mx.y, mn.z, 1.0f), m)); }
    { V4 t = Mtx_MulVec4(&mx, m); Box_ExtendXYZ(b, &t); }
}

static inline void Ext(Box* b, V4* v_)
{
    V4* pv0 = &b->mx;
    V4* v = v_;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(pv0)
        lqc2 vf3, 0x0(v)
        vmini.xyz vf1, vf1, vf3
        vmax.xyz vf2, vf2, vf3
        sqc2 vf1, 0x0(b)
        sqc2 vf2, 0x0(pv0)
    }
}

static inline void GQ(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %1, 0x0(%2); sq %1, 0x0(%0)" : "=r"(d), "=r"(q) : "r"(s), "0"(d) : "memory"); }
static inline void CopyBox(Box* out, Box* in)
{
    __int128* d = (__int128*)out; __int128* s = (__int128*)in; __int128 qa = s[0]; __int128 qb = s[1]; d[0] = qa; d[1] = qb;
}

static inline void BoxUnion(Box* out, Box* b)
{
    if (b->mn.x <= b->mx.x) {
        Ext(out, &b->mn);
        Ext(out, &b->mx);
    }
}

extern "C" void nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cBoxR_cBoxR_cGOBJP_cXformP(Box* out, Box* in, Owner* o, Xf* xf)
{
    Box tmp;
    M44 m1, m2, m3;
    PNode* n = o->p54;
    if (n && n->b0) {
        M44* nm = &n->m10;
        M44* xm = XfMtx(xf);
        GQ(&tmp.mn, &in->mn); GQ(&tmp.mx, &in->mx);
        Mtx_InvertRigid_13ECA0(&m1, nm);
        TB(&tmp, &m1);
        CopyBox(out, in);
        Mtx_InvertRigid_13ECA0(&m2, xm);
        TB(out, &m2);
        BoxUnion(out, &tmp);
    } else {
        CopyBox(out, in);
        Transform_GetInverseMatrix(&m3, xf);
        TB(out, &m3);
    }
}
