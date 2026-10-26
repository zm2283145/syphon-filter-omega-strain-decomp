#include "types.h"

extern void NellySetEFactorSase3200(int, float);

int nciSetEFactorSase3200(int a0, float f12) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 28);
    NellySetEFactorSase3200(tmp0, f12);
    return 6503;
}
