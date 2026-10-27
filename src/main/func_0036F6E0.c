#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
static inline void QC(void* s, void* d) {
    __int128 qa, qb;
    asm {
        .set noreorder
        .set reorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(d)
        lq qa, 0x20(s)
        sq qb, 0x10(d)
        lq qb, 0x30(s)
        sq qa, 0x20(d)
        sq qb, 0x30(d)
    }
}
typedef struct { float m[4][4]; } __attribute__((aligned(16))) M6F6E0;
typedef struct { int p; } It6F6E0;
class X6F6E0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0xC];
    M6F6E0 world;
    unsigned char dirty;
    char pad51[0xF];
    float r[3][4];
    char pad90[0x10];
    X6F6E0* parent;
    int list[3];
};
extern "C" {
void cArray_cXformNodePtr_Begin(It6F6E0* it, void* c);
void cArray_cXformNodePtr_End(It6F6E0* it, void* c);
int cArray_cXformNodePtr_ConstIterator_opNe(It6F6E0* a, It6F6E0* b);
void** cArray_cXformNodePtr_ConstIterator_opMul(It6F6E0* it);
void cXformNode_SetNeedsUpdate(void* p);
void cArray_cXformNodePtr_ConstIterator_opInc(It6F6E0* it);
}
static inline void MulRot(M6F6E0* out, M6F6E0* m, M6F6E0* rot)
{
    asm {
        lqc2 vf8, 0x0(rot)
        lqc2 vf9, 0x10(rot)
        lqc2 vf10, 0x20(rot)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddz.xyzw vf12, vf6, vf8z
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddz.xyzw vf13, vf6, vf9z
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddz.xyzw vf14, vf6, vf10z
        vmove.xyzw vf15, vf7
        sqc2 vf12, 0x0(out)
        sqc2 vf13, 0x10(out)
        sqc2 vf14, 0x20(out)
        sqc2 vf15, 0x30(out)
    }
}
static inline void Transpose(M6F6E0* m)
{
    float t;
    t = m->m[0][1]; m->m[0][1] = m->m[1][0]; m->m[1][0] = t;
    t = m->m[0][2]; m->m[0][2] = m->m[2][0]; m->m[2][0] = t;
    t = m->m[1][2]; m->m[1][2] = m->m[2][1]; m->m[2][1] = t;
}
static inline void Set(X6F6E0* x, M6F6E0* s)
{
    x->r[0][0] = s->m[0][0]; x->r[0][1] = s->m[0][1]; x->r[0][2] = s->m[0][2];
    x->r[1][0] = s->m[1][0]; x->r[1][1] = s->m[1][1]; x->r[1][2] = s->m[1][2];
    x->r[2][0] = s->m[2][0]; x->r[2][1] = s->m[2][1]; x->r[2][2] = s->m[2][2];
    x->r[0][3] = s->m[0][3]; x->r[1][3] = s->m[1][3]; x->r[2][3] = s->m[2][3];
}
#pragma opt_common_subs off
#pragma opt_rotateloops off
extern "C" void cXformNode_SetRotationMatrix(X6F6E0* self, M6F6E0* rot)
{
    X6F6E0* p = self->parent;
    if (p) {
        M6F6E0 m;
        if (p->dirty) p->Update();
        QC(&p->world, &m);
        { float t, u, v;
        t = m.m[0][1]; m.m[0][1] = m.m[1][0]; m.m[1][0] = t;
        u = m.m[0][2]; m.m[0][2] = m.m[2][0]; m.m[2][0] = u;
        v = m.m[1][2]; m.m[1][2] = m.m[2][1]; m.m[2][1] = v; }
        MulRot(&m, &m, rot);
        Set(self, &m);
    } else {
        Set(self, rot);
    }
    if (!self->dirty) {
        It6F6E0 b;
        It6F6E0 e;
        It6F6E0* pe;
        self->dirty = 1;
        cArray_cXformNodePtr_Begin(&b, self->list);
        cArray_cXformNodePtr_End(&e, self->list);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}






