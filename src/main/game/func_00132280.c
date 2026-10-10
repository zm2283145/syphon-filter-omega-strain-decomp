#include "types.h"

typedef struct Mtx40 {
    float m[16];
} __attribute__((aligned(16))) Mtx40;

typedef struct RootP {
    char pad0000[0x3290];
    void* root; /* 0x3290 */
} RootP;

extern void* Root_GetWorldPlacement(void* root);
extern void* Placement_GetQuat(void* placement);
extern void* Quat_ToMatrix(Mtx40* out, void* quat);
extern void* Placement_GetPosition(void* placement);
extern void Mtx_FromBasisAndPosition(void* out, void* basis, void* pos);

/* Builds the world matrix of obj's root placement into out. */
void func_00132280(void* out, RootP* obj) {
    Mtx40 rot;
    void* placement = Root_GetWorldPlacement(obj->root);
    void* basis = Quat_ToMatrix(&rot, Placement_GetQuat(placement));
    Mtx_FromBasisAndPosition(out, basis, Placement_GetPosition(placement));
}
