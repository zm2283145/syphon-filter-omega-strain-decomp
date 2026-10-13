#include "types.h"
typedef struct { float v[5]; } D5F5;
typedef struct { float v[4]; } D5F4;
typedef struct {
    unsigned char b0;
    unsigned char b1;
    char pad2[2];
    int i4;
    D5F5 req;
    char x1C[8];
    char ev1[0x38];
    char ev2[0x38];
    char x94[0x4C];
    float fE0;
    int iE4;
    char trans[0x10];
} D5Sel;
extern D5F5* func_003AD650(D5F5* dst, D5F5* src);
extern void MotionGroup_CopyPair(void* dst, void* src);
extern void AnimEvent_Copy(void* dst, void* src);
extern void func_0018A710(void* dst, void* src);
extern void TransitionReq_Construct(void* self, float t);
extern void AnimCtl_Install(void* c, D5Sel* r, unsigned char mode);
extern void func_00396910(void* p, int f);
extern void func_00189F40(void* p, int f);
extern void func_0018A260(void* p, int f);
#pragma opt_propagation off
void AnimCtl_InstallMotion(void* ctl, int id, unsigned char mode, D5F4* range, void* pair, void* m1, void* m2, void* x, float f0, float f1)
{
    D5Sel s;
    D5F5 t;
    D5Sel* p = &s;
    t.v[0] = range->v[0];
    t.v[1] = range->v[1];
    t.v[2] = range->v[2];
    t.v[3] = range->v[3];
    t.v[4] = 0;
    s.b0 = 0;
    s.b1 = 0;
    s.i4 = id;
    func_003AD650(&s.req, &t);
    MotionGroup_CopyPair(s.x1C, pair);
    AnimEvent_Copy(s.ev1, m1);
    AnimEvent_Copy(s.ev2, m2);
    func_0018A710(p->x94, x);
    p->fE0 = f0;
    p->iE4 = 0;
    TransitionReq_Construct(p->trans, f1);
    AnimCtl_Install(ctl, &s, mode);
    func_00396910(s.trans, -1);
    func_00189F40(s.x94, -1);
    func_0018A260(s.ev2, -1);
    func_0018A260(s.ev1, -1);
}


