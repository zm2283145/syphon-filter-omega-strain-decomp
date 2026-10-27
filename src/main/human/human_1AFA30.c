/*
 * main/human: range (2 files, 001AFA30-001AFB20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_001AFA30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cSkeletonCenterOfMassContributionPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001AFA30 */

/* merge_units: begin func_001AFB20 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */
                                    
#if 0 /* merge_units */
int EnableIntc(int);
#endif /* merge_units */
#define EnableIntc(a0) (EnableIntc((a0))) /* merge_units */
                                  
int nCollision_InitStatics(int, int, int, int);                      
int cHumanCollisionRoutine_InitStatics();                                  
char * cMemMan_Allocate(int, int, char *, int);                      
int cCollisionSystem_cBox_InitStatics(int);                                 
int cArrayCapacity_Int(int *);                           
int std_vector_cSkeletonBBoxContributionPtr_reserve(char * , int);                       
int std_vector_cSkeletonBBoxContributionPtr_ctor(char * );                            
int std_vector_cSkeletonCenterOfMassContributionPtr_reserve(char * , int);                       
int std_vector_cSkeletonCenterOfMassContributionPtr_ctor(char * );                            
int InitStatics_BBox(char * );                            
int InitStatics_CenterOfMass(char * );                            
int cHumanIkRoutine_InitStatics();                                  
extern char D_0049D8D0;
extern char * D_004EE9D0;
extern char * D_004EE9D8;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cHuman_InitStatics(void) {
    int sp2C;
    char * temp_s0;
    char * temp_s0_2;

    nCollision_InitStatics(0, 0, 0, 0);
    cCollisionSystem_cBox_InitStatics(0x320);
    cHumanCollisionRoutine_InitStatics();
    cHumanIkRoutine_InitStatics();
    sp2C = 0x15;
    if (D_004EE9D0 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0 = cMemMan_Allocate(0, 0x10, &D_0049D8D0, 0xB1A);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0 != NULL) {
            std_vector_cSkeletonCenterOfMassContributionPtr_ctor(temp_s0);
            std_vector_cSkeletonCenterOfMassContributionPtr_reserve(temp_s0, cArrayCapacity_Int(&sp2C));
            F_(temp_s0, 0xC, signed char) = 1;
        }
        D_004EE9D0 = temp_s0;
        InitStatics_CenterOfMass(temp_s0);
    }
    if (D_004EE9D8 == NULL) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        temp_s0_2 = cMemMan_Allocate(0, 0x10, &D_0049D8D0, 0xB20);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        if (temp_s0_2 != NULL) {
            std_vector_cSkeletonBBoxContributionPtr_ctor(temp_s0_2);
            std_vector_cSkeletonBBoxContributionPtr_reserve(temp_s0_2, cArrayCapacity_Int(&sp2C));
            F_(temp_s0_2, 0xC, signed char) = 1;
        }
        D_004EE9D8 = temp_s0_2;
        InitStatics_BBox(temp_s0_2);
    }
}
#undef Alloc_Lock /* merge_units */
#undef EnableIntc /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AFB20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AFB20 */
