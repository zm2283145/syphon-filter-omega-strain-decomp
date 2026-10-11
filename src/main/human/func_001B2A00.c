#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
struct V4_1B2A00 { __int128 q; V4_1B2A00() {} };
extern "C" {
void func_0017CC60(void* p, int f);
void* func_00139BC0(unsigned int size, void* p);
void Curve_SetTangents(void* c, V4_1B2A00* a, V4_1B2A00* b, V4_1B2A00* d, V4_1B2A00* e, float t);
}
class VC_1B2A00 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual V4_1B2A00 s3();
};
struct Obj_1B2A00 : public VC_1B2A00 {
    char p0[0x1C];
    V4_1B2A00 a;
    V4_1B2A00 b;
    V4_1B2A00 c;
    char p1[0x10];
    char curve[0x40];
    float t;
};
static inline V4_1B2A00 Get_(VC_1B2A00* v) { return v->s3(); }
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void VecCurve_Reset(Obj_1B2A00* o, const V4_1B2A00* a)
{
    V4_1B2A00* d = &o->a;
    V4Copy(d, a);
    {
        V4_1B2A00 r = Get_(o);
        func_0017CC60(o->curve, -1);
        void* cv = func_00139BC0(0x50, o->curve);
        if (cv) Curve_SetTangents(cv, &o->a, &o->b, &o->c, &r, o->t);
    }
}