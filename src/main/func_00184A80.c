#include "types.h"

typedef struct Mtx40 {
    float m[16];
} __attribute__((aligned(16))) Mtx40;

typedef struct RootP {
    char pad0000[0x3290];
    void* root; /* 0x3290 */
} RootP;

extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* root);
extern void* cQuatVec_Rotation(void* placement);
extern void* cMatrix_ctor_cQuaternionR(Mtx40* out, void* quat);
extern void* cQuatVec_Translation(void* placement);
extern void cMatrix_Set_cMatrixR_cVectorR(void* out, void* basis, void* pos);

/* Builds the world matrix of obj's root placement into out. */
void cHuman_GetTransform_ForTeleporting(void* out, RootP* obj) {
    Mtx40 rot;
    void* placement = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(obj->root);
    void* basis = cMatrix_ctor_cQuaternionR(&rot, cQuatVec_Rotation(placement));
    cMatrix_Set_cMatrixR_cVectorR(out, basis, cQuatVec_Translation(placement));
}
