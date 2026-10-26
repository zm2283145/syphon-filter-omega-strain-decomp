#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Mtx_Multiply4(char * , int);                       
int Sphere_FromCenter(char *, char * , char * );           
int Transform_GetUpdated(int);                      
int Vec4_Copy(char * , int);                           
int Vec4_Scale(float, char *, char *);                        
int Vec4_Cross(char *, char *, char *);                     
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
void FloorContact_ReadTriFlags(char * arg0, char * arg1, int arg2, int arg3, char * arg4) {
    int spB0[4];
    int spA0[4];
    int sp90[4];
    int sp80[4];
    int temp_s1;
    float temp_f20;
    int temp_v0;
    int temp_v0_2;

    temp_s1 = (int)(arg4);
    Vec4_Copy(arg0, cCollisionModel_GetVertex(temp_s1, F_(arg1, 0x4, unsigned short)));
    Vec4_Copy(arg0 + 0x10, cCollisionModel_GetVertex(temp_s1, F_(arg1, 0x6, unsigned short)));
    Vec4_Copy(arg0 + 0x20, cCollisionModel_GetVertex(temp_s1, F_(arg1, 0x8, unsigned short)));
    temp_f20 = F_(arg1, 0x0, float);
    *cVector_W(arg0 + 0x30) = temp_f20;
    temp_v0 = cCollisionModel_GetXform(temp_s1);
    if (temp_v0 != 0) {
        temp_v0_2 = Transform_GetUpdated(temp_v0);
        Mtx_Multiply4(arg0, temp_v0_2);
        Mtx_Multiply4(arg0 + 0x10, temp_v0_2);
        Mtx_Multiply4(arg0 + 0x20, temp_v0_2);
    }
    cCollisionModel_FaceProperties_opAssign(arg0 + 0x40, arg3);
    F_(arg0, 0x50, signed char) = cCollisionModel_Face_IsCamPassThru(arg1);
    F_(arg0, 0x51, signed char) = cCollisionModel_Face_IsReceiveShadow(arg1);
    F_(arg0, 0x52, signed char) = cCollisionModel_Face_IsReceiveReflection(arg1);
    cCollisionModel_FaceLocator_Set(arg0 + 0x60, arg2, temp_s1);
    Sphere_FromCenter(spB0, arg0 + 0x10, arg0);
    Sphere_FromCenter(spA0, arg0 + 0x20, arg0);
    Vec4_Cross(sp80, spB0, spA0);
    Vec4_Scale(cCollisionFace_NormalScale(arg0), sp90, sp80);
    cCollisionFace_SetUnitNormal(arg0, sp90);
}
