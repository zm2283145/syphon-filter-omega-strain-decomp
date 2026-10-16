#include "types.h"
const float D_0048B0E0[2] = { 1.4013e-42f, 0.0f };
typedef struct { char pad[0x60]; int v; } T262470;
void FireLight_SetIntensity(T262470* p, float f) {
    p->v = (int)((float)(*(int*)D_0048B0E0) * f / 100.0f);
}