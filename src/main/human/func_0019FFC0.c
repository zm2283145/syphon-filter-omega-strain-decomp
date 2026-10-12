#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x70]; V4 q; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* parent; } R;
extern void* Root_GetParent(R*);
extern void* Root_GetWorldPlacement(void*);
extern V4* Placement_GetQuat(void*);
extern V4* func_001325F0(V4*, V4*);
extern V4* func_0019D4E0(V4*);
static inline void QRot_(V4* q, V4* v) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}

#pragma peephole off
#pragma opt_propagation off
/* Sets the local orientation quat; when parented, rotates it into the parent's frame. */
void func_0019FFC0(R* self, V4* q)
{
    V4 t;
    {V4* d = &self->q; asm { .set reorder } *d = *q;}
    if (self->parent) {
        func_001325F0(&t, Placement_GetQuat(Root_GetWorldPlacement(Root_GetParent(self))));
        func_0019D4E0(&t);
        QRot_(&t, &self->q);
    }
    self->dirty = 1;
}
