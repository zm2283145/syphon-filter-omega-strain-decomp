#include "types.h"
#pragma opt_propagation off
#pragma peephole off
#pragma opt_common_subs off
typedef struct {
    int a;
    unsigned char zero;
    char pad05[3];
    float f;
    char pad0c[4];
    Vec4 v;
} Obj2909C0;
Obj2909C0* func_002909C0(Obj2909C0* o, int a, Vec4* v, float f) {
    int k, fl; unsigned char r;
    o->a = a;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    o->zero = r;
    o->f = f;
    {
        /* inlined copy-as-point (w = 1) into tmp, then tmp -> o->v */
        Vec4 tmp; Vec4* ps; Vec4* dst; Vec4 t; Vec4* p;
        p = &t; t = *v; p->w = 1.0f;
        { Vec4* pt = &tmp; *pt = *p; }
        dst = &o->v; ps = &tmp; *dst = *ps;
    }
    return o;
}


