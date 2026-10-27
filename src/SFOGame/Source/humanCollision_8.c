/*
 * SFOGame/Source/humanCollision: 6 files, 001E1990-001E1B70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E1990 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vtable_base_dtor.h"
DEFINE_VTABLE_BASE_DTOR(cFoundLedgeMsg_dtor, D_004DAD40, cMessage_dtor)
static inline void merge_flush_func_001E1990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1990 */

/* merge_units: begin func_001E19F0 */
#pragma push /* merge_units */
typedef struct { char pad[0xB0]; } B4Coll;
typedef struct { char pad0[0xC]; B4Coll* c; char pad1[0x990 - 0x10]; float f990; float f994; float f998; char b99C; char b99D; } B4Obj1;
extern void* RootCollection_FindByKey(void*, void*);
extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
extern float* cQuatVec_Translation(void*);
extern char D_004A03D8[];
void cHumanCollisionRoutine_DetermineIfHasReachedTopOfLadder(B4Obj1* p) {
    float* pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey((char*)p->c + 0xB0, D_004A03D8)));
    p->b99D = p->f990 - pos[2] < 0.5f;
}
static inline void merge_flush_func_001E19F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E19F0 */

/* merge_units: begin func_001E1A60 */
#pragma push /* merge_units */
typedef struct { char pad0[0xC]; char* c; char pad1[0x990 - 0x10]; float f990; float f994; float f998; char b99C; char b99D; } B4Obj2;
extern float D_004A0410;
void cHumanCollisionRoutine_DetermineIfHasReachedBottomOfLadder(B4Obj2* p) {
    float* pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(p->c + 0xB0, D_004A03D8)));
    p->b99C = (p->f998 + D_004A0410) - pos[2] > -0.5f;
}
static inline void merge_flush_func_001E1A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1A60 */

/* merge_units: begin func_001E1AE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern "C" void cGameEventMsg_Clone();
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern void * const D_004DAD20[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cGameEventMsg_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAD20);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAD20[8] = { (void*)0x0, (void*)0x0, (void*)cGameEventMsg_dtor, (void*)cGameEventMsg_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_001E1AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1AE0 */

/* merge_units: begin func_001E1B40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* std_vector_imp_cGOBJPtr_1_end_void_2(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}
static inline void merge_flush_func_001E1B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1B40 */

/* merge_units: begin func_001E1B70 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cVector_Transform_cMatrixR(char * , int);                       
int cVector_opSub(char *, char * , char * );           
int cXform_GetMatrix(int);                      
int cVector_opAssign(char * , int);                           
int cVector_opMul(float, char *, char *);                        
int cVector_Cross(char *, char *, char *);                     
int cCollisionModel_FaceProperties_opAssign(char * , int);                         
int cCollisionFace_SetUnitNormal(char * , char *);                       
float cCollisionFace_NormalScale(char * );                          
int cCollisionModel_FaceLocator_Set(char * , int, int);                      
signed char cCollisionModel_Face_IsReceiveReflection(char * );                           
signed char cCollisionModel_Face_IsReceiveShadow(char * );                           
signed char cCollisionModel_Face_IsCamPassThru(char * );                           
int cCollisionModel_GetXform(int);                               
float *cVector_W(char * );                         
int cCollisionModel_GetVertex(int, unsigned short);                          

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74], gap at: 0x8. */
void cCollisionFace_Set_cCollisionModelFaceR_uint_cCollisionModelFacePropertiesR_cCollisionModelR(char * arg0, char * arg1, int arg2, int arg3, char * arg4) {
    int spB0[4];
    int spA0[4];
    int sp90[4];
    int sp80[4];
    int temp_s1;
    float temp_f20;
    int temp_v0;
    int temp_v0_2;

    temp_s1 = (int)(arg4);
    cVector_opAssign(arg0, cCollisionModel_GetVertex(temp_s1, F_(arg1, 0x4, unsigned short)));
    cVector_opAssign(arg0 + 0x10, cCollisionModel_GetVertex(temp_s1, F_(arg1, 0x6, unsigned short)));
    cVector_opAssign(arg0 + 0x20, cCollisionModel_GetVertex(temp_s1, F_(arg1, 0x8, unsigned short)));
    temp_f20 = F_(arg1, 0x0, float);
    *cVector_W(arg0 + 0x30) = temp_f20;
    temp_v0 = cCollisionModel_GetXform(temp_s1);
    if (temp_v0 != 0) {
        temp_v0_2 = cXform_GetMatrix(temp_v0);
        cVector_Transform_cMatrixR(arg0, temp_v0_2);
        cVector_Transform_cMatrixR(arg0 + 0x10, temp_v0_2);
        cVector_Transform_cMatrixR(arg0 + 0x20, temp_v0_2);
    }
    cCollisionModel_FaceProperties_opAssign(arg0 + 0x40, arg3);
    F_(arg0, 0x50, signed char) = cCollisionModel_Face_IsCamPassThru(arg1);
    F_(arg0, 0x51, signed char) = cCollisionModel_Face_IsReceiveShadow(arg1);
    F_(arg0, 0x52, signed char) = cCollisionModel_Face_IsReceiveReflection(arg1);
    cCollisionModel_FaceLocator_Set(arg0 + 0x60, arg2, temp_s1);
    cVector_opSub(spB0, arg0 + 0x10, arg0);
    cVector_opSub(spA0, arg0 + 0x20, arg0);
    cVector_Cross(sp80, spB0, spA0);
    cVector_opMul(cCollisionFace_NormalScale(arg0), sp90, sp80);
    cCollisionFace_SetUnitNormal(arg0, sp90);
}
static inline void merge_flush_func_001E1B70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1B70 */
