#include "types.h"

void cBone_SkeletonCenterOfMassContribution_Reset(int a0, float f12) {
    int cond;

    cond = a0 == 0;
    if (cond) goto L001AF310;
    *(float*)(char*)a0 = f12;
L001AF310:;
    goto ret;
ret:;
}
