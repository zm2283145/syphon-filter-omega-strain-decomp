#include "types.h"
typedef struct { int w; } G_1AF7A0;
extern void* D_004EE9D0;
extern void* D_004EE9D8;
extern char D_0049D8D0[];
extern void cTimerDisable_ctor(G_1AF7A0* g);
extern void cTimerDisable_dtor(G_1AF7A0* g, int f);
extern void cArray_cSkeletonCenterOfMassContributionPtr_dtor(void* p, int f);
extern void cArray_cSkeletonBBoxContributionPtr_dtor(void* p, int f);
extern void Mem_Free(int pool, void* p, char* file, int line);
extern void cHumanIkRoutine_UnInitStatics(void);
extern void HumanCol_Shutdown(void);
extern void cCollisionSystem_cBox_UnInitStatics(void);
extern void nCollision_UnInitStatics(void);
void cHuman_UnInitStatics(void)
{
    G_1AF7A0 g1;
    G_1AF7A0 g2;
    void* p = D_004EE9D0;
    if (p) {
        cTimerDisable_ctor(&g1);
        cArray_cSkeletonCenterOfMassContributionPtr_dtor(p, -1);
        Mem_Free(0, p, D_0049D8D0, 0xB2A);
        cTimerDisable_dtor(&g1, -1);
        D_004EE9D0 = 0;
    }
    p = D_004EE9D8;
    if (p) {
        cTimerDisable_ctor(&g2);
        cArray_cSkeletonBBoxContributionPtr_dtor(p, -1);
        Mem_Free(0, p, D_0049D8D0, 0xB30);
        cTimerDisable_dtor(&g2, -1);
        D_004EE9D8 = 0;
    }
    cHumanIkRoutine_UnInitStatics();
    HumanCol_Shutdown();
    cCollisionSystem_cBox_UnInitStatics();
    nCollision_UnInitStatics();
}