#include "types.h"
typedef struct { char pad[0xB0]; int coll; } B5aOwner;
typedef struct { char pad[0xC]; B5aOwner* owner; char pad2[0xE4 - 0x10]; float z; } B5aObj;
extern float g_NegFltMax;
extern int D_004A03C8;
extern void* RootCollection_FindByKey(void* coll, void* key);
extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
extern float* cQuatVec_Translation(void* p);
float cHumanCollisionRoutine_GetWaterDepth(B5aObj* o) {
    float r;
    if (o->z != g_NegFltMax) {
        float* p = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(&o->owner->coll, &D_004A03C8)));
        r = o->z - p[2];
    } else {
        r = 0.0f;
    }
    return r;
}