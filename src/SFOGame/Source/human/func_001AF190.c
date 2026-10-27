#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(char *, char *);                        
int cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opInc(char *);                               
int cBone_SkeletonCenterOfMassContribution_Reset(int, float);                          
float cSkeletonCenterOfMassContribution_Weight(int);                             
int cArray_cBone_opIndex_int_2(char * , int);                     
int cSkeletonCenterOfMassContribution_BoneIndex(int);                             
int *cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(char *);                            
int cArray_cSkeletonCenterOfMassContributionPtr_End(char *, int);                          
int cArray_cSkeletonCenterOfMassContributionPtr_Begin(char *, int);                          
int cArray_cBone_Iterator_opNe(char *, char *);                        
int cArray_cBone_Iterator_opInc(char *);                               
int cBone_SkeletonCenterOfMassContribution_Clear(int);                               
int cBone_GetSkeletonCenterOfMassContribution(int);                             
int cArray_cBone_Iterator_opArrow(char *);                             
int cArray_cBone_End(char *, char * );                       
int cArray_cBone_Begin(char *, char * );                       
extern int D_004EE9D0;

void cHuman_SetupCenterOfMassInfo(char * arg0) {
    char * temp_s1;
    int sp3C;
    int temp_s0;
    int sp38;
    int sp34;
    int sp30;
    int temp_s0_2;

    temp_s0 = D_004EE9D0;
    temp_s1 = arg0 + 0x2E50;
    if (F_(arg0, 0x2E64, unsigned char) != 0) {
        cArray_cBone_Begin(&sp3C, temp_s1 + 0x18);
        cArray_cBone_End(&sp38, temp_s1 + 0x18);
        if (cArray_cBone_Iterator_opNe(&sp3C, &sp38) != 0) {
            do {
                cBone_SkeletonCenterOfMassContribution_Clear(cBone_GetSkeletonCenterOfMassContribution(cArray_cBone_Iterator_opArrow(&sp3C)));
                cArray_cBone_Iterator_opInc(&sp3C);
            } while (cArray_cBone_Iterator_opNe(&sp3C, &sp38) != 0);
        }
        cArray_cSkeletonCenterOfMassContributionPtr_Begin(&sp34, temp_s0);
        cArray_cSkeletonCenterOfMassContributionPtr_End(&sp30, temp_s0);
        if (cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(&sp34, &sp30) != 0) {
            do {
                temp_s0_2 = cBone_GetSkeletonCenterOfMassContribution(cArray_cBone_opIndex_int_2(temp_s1 + 0x18, cSkeletonCenterOfMassContribution_BoneIndex(*cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(&sp34))));
                { float ff = cSkeletonCenterOfMassContribution_Weight(*cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opMul(&sp34)); cBone_SkeletonCenterOfMassContribution_Reset(temp_s0_2, ff); }
                cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opInc(&sp34);
            } while (cArray_cSkeletonCenterOfMassContributionPtr_ConstIterator_opNe(&sp34, &sp30) != 0);
        }
    }
}
