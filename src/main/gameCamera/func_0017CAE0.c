#include "types.h"
#pragma cplusplus on
#pragma peephole off
#pragma opt_propagation off
typedef Vec4 V4c;
class CamCAE0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V4c GetTangent();
    char pad04[0x1C];
    V4c p20;
    V4c p30;
    V4c p40;
    char pad50[0x10];
    char sp60[0x40];
    float fA0;
};
extern "C" void func_0017CC60(void*, int);
extern "C" void* func_00139BC0(int, void*);
extern "C" void Curve_SetTangents(void*, V4c*, V4c*, V4c*, V4c*, float);
extern "C" void func_0017CAE0(CamCAE0* c, V4c* a, V4c* b)
{
    V4c t;
    void* n;
    /* empty asm: emits nothing, only a scheduling barrier keeping the lq after addiu d */
    { V4c* d = &c->p20; asm { .set noreorder; .set reorder } *d = *a; }
    c->p30 = *b;
    t = c->GetTangent();
    func_0017CC60(c->sp60, -1);
    n = func_00139BC0(0x50, c->sp60);
    if (n) Curve_SetTangents(n, &c->p20, &c->p30, &c->p40, &t, c->fA0);
}




