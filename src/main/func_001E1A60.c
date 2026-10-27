#include "types.h"
typedef struct { char pad0[0xC]; char* c; char pad1[0x990 - 0x10]; float f990; float f994; float f998; char b99C; char b99D; } B4Obj2;
extern void* RootCollection_FindByKey(void*, void*);
extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
extern float* cQuatVec_Translation(void*);
extern char D_004A03D8[];
extern float D_004A0410;
void cHumanCollisionRoutine_DetermineIfHasReachedBottomOfLadder(B4Obj2* p) {
    float* pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(p->c + 0xB0, D_004A03D8)));
    p->b99C = (p->f998 + D_004A0410) - pos[2] > -0.5f;
}