#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Vec4_Assign(char *, int);                          
int SkelNodes_GetAt(char * , int);                     
int cArray_cBone_Iterator_opNe(char *, char *);                        
int cArray_cBone_Iterator_opInc(char *);                               
int cArray_cBone_Iterator_opArrow(char *);                             
int cArray_cBone_End(char *, char * );                       
int cArray_cBone_Begin(char *, char * );                       
int cArray_cSkeletonBBoxContributionPtr_ConstIterator_opNe(char *, char *);                        
int cArray_cSkeletonBBoxContributionPtr_ConstIterator_opInc(char *);                               
int BoundSphere_Set(int, int, float);                     
int cSkeletonBBoxContribution_ContributionPointOffset(int);                             
float cSkeletonBBoxContribution_ContributionPointRadius(int);                             
int cSkeletonBBoxContribution_BoneIndex(int);                             
int *cArray_cSkeletonBBoxContributionPtr_ConstIterator_opMul(char *);                            
int cArray_cSkeletonBBoxContributionPtr_End(char *, int);                          
int cArray_cSkeletonBBoxContributionPtr_Begin(char *, int);                          
int BoundSphere_Reset(int);                               
int SkelNode_GetBoundSphere(int);                             
extern int D_004EE9D8;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
void Human_ApplyBoundSpheres(char * arg0) {
    int sp5C;
    int temp_s0;
    int sp58;
    int sp54;
    char * temp_s1;
    int temp_s0_2;
    int sp40[4];
    int sp50;
    float temp_f20;

    temp_s0 = D_004EE9D8;
    temp_s1 = arg0 + 0x2E50;
    if (F_(arg0, 0x2E64, unsigned char) != 0) {
        cArray_cBone_Begin(&sp5C, temp_s1 + 0x18);
        cArray_cBone_End(&sp58, temp_s1 + 0x18);
        if (cArray_cBone_Iterator_opNe(&sp5C, &sp58) != 0) {
            do {
                BoundSphere_Reset(SkelNode_GetBoundSphere(cArray_cBone_Iterator_opArrow(&sp5C)));
                cArray_cBone_Iterator_opInc(&sp5C);
            } while (cArray_cBone_Iterator_opNe(&sp5C, &sp58) != 0);
        }
        cArray_cSkeletonBBoxContributionPtr_Begin(&sp54, temp_s0);
        cArray_cSkeletonBBoxContributionPtr_End(&sp50, temp_s0);
        if (cArray_cSkeletonBBoxContributionPtr_ConstIterator_opNe(&sp54, &sp50) != 0) {
            do {
                temp_s0_2 = SkelNode_GetBoundSphere(SkelNodes_GetAt(temp_s1 + 0x18, cSkeletonBBoxContribution_BoneIndex(*cArray_cSkeletonBBoxContributionPtr_ConstIterator_opMul(&sp54))));
                temp_f20 = cSkeletonBBoxContribution_ContributionPointRadius(*cArray_cSkeletonBBoxContributionPtr_ConstIterator_opMul(&sp54));
                BoundSphere_Set(temp_s0_2, Vec4_Assign(sp40, cSkeletonBBoxContribution_ContributionPointOffset(*cArray_cSkeletonBBoxContributionPtr_ConstIterator_opMul(&sp54))), temp_f20);
                cArray_cSkeletonBBoxContributionPtr_ConstIterator_opInc(&sp54);
            } while (cArray_cSkeletonBBoxContributionPtr_ConstIterator_opNe(&sp54, &sp50) != 0);
        }
    }
}

