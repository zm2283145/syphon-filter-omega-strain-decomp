#include "types.h"
typedef struct H1Phys { char pad000[0x980]; Vec4 ladderRef; } H1Phys;
typedef struct H1Actor {
    char pad0000[0x3298];
    void* laddRoot;
    char pad329C[0x3310 - 0x329C];
    H1Phys* phys;
} H1Actor;
extern void* Root_GetWorldPlacement(void* root);
extern Vec4* Placement_GetPosition(void* placement);
static inline void h1_cp(Vec4* d, const Vec4* s) { *d = *s; }
#pragma peephole off
#pragma opt_propagation off
float func_00476230(H1Actor* self) {
    H1Actor* s = self;
    if (self->phys != 0) {
        float z = Placement_GetPosition(Root_GetWorldPlacement(s->laddRoot))->z;
        Vec4 ref;
        h1_cp(&ref, &s->phys->ladderRef);
        return z - ref.z;
    }
    return 0.0f;
}
#pragma opt_propagation reset
#pragma peephole reset
