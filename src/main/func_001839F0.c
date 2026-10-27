#include "types.h"

int cCollisionModel_FaceProperties_GetMaskedBits(int a0, int a1) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)(char*)a0;
    return ((tmp0 & (a1 & 255)) & 255);
}
