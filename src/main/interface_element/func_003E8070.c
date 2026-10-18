#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M4_E070;
typedef struct { char pad[0x30]; M4_E070 m; } Elem_E070;
extern "C" {
float Math_CosThunk(float);
float Math_SinThunk(float);
void Mtx44_SetRotation(M4_E070* m, float, float, float, float, float, float, float, float, float);
void IeElement_SetRotation(Elem_E070* e, float* r);
}
static inline void GQR(void* d0, void* s0) { void* d = d0; __int128 qa; __int128 qb; void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
void IeElement_SetRotation(Elem_E070* e, float* r)
{
    M4_E070 m;
    float y = r[1];
    float z = r[2];
    float x = r[0];
    float cy = Math_CosThunk(y);
    float sy = Math_SinThunk(y);
    float cz = Math_CosThunk(z);
    float sz = Math_SinThunk(z);
    float cx = Math_CosThunk(x);
    float sx = Math_SinThunk(x);
    Mtx44_SetRotation(&m, cy * cz, -sz, sy * cz, sz * (cx * cy) + sx * sy, cx * cz, sz * (cx * sy) - sx * cy, cy * (sx * sz) - cx * sy, sx * cz, sz * (sx * sy) + cx * cy);
    GQR(&e->m, &m);
}
