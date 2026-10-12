#include "types.h"

extern int NpcPerception_SensedRecord(int, int);

float NpcPerception_IsEnemy(void) {
    int a0, a1, v0;
    float f0, f20;
    int cond;

    f20 = 0.0f;
    v0 = NpcPerception_SensedRecord(a0, a1);
    cond = v0 == 0;
    if (cond) goto L0016C758;
    f20 = *(float*)((char*)v0 + 48);
L0016C758:;
    f0 = f20;
    goto ret;
ret:
    return f0;
}
