#pragma cplusplus on
#include "types.h"
#pragma always_inline on
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { V4* pd = this; const V4* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
    V4& operator=(const V4& o) { V4* pd = this; const V4* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
typedef struct { int w[1]; } It;
struct R { char pad[0x50]; V4 q; char pad60[0x40]; unsigned char bA0; char padA1[0xF]; void* parent; };
extern "C" {
void* Root_GetParent(R*);
void* Root_GetWorldPlacement(void*);
V4* Placement_GetQuat(void*);
V4* Quat_Assign(V4*, V4*);
V4* func_0019D4E0(V4*);
int func_001913E0(R* n);
void* func_001913D0(R* n);
void func_001913C0(It* out, void* vec);
void func_001913A0(It* out, void* vec);
bool func_001912A0(It* a, It* b);
R** func_00191390(It* it);
void func_001912E0(R* n);
void func_001912C0(It* it);
}
static inline V4 QMul(const V4& a, const V4& b)
{
    V4 r;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%1)" : : "r"(&a), "r"(&r), "r"(&b) : "memory");
    return r;
}
#pragma peephole off
#pragma opt_propagation off
extern "C" void Root_SetWorldOrientation(R* self, V4* q)
{
    V4 t;
    self->q = *q;
    if (self->parent) {
        Quat_Assign(&t, Placement_GetQuat(Root_GetWorldPlacement(Root_GetParent(self))));
        func_0019D4E0(&t);
        { V4* pt = &t; V4* pq = &self->q; *pq = QMul(*pt, *pq); }
    }
    self->bA0 = 1;
    if (func_001913E0(self)) {
        It it, end;
        func_001913C0(&it, func_001913D0(self));
        func_001913A0(&end, func_001913D0(self));
        for (; func_001912A0(&it, &end); func_001912C0(&it))
            func_001912E0(*func_00191390(&it));
    }
}
