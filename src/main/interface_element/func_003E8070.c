#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M4_E070;
typedef struct { char pad[0x30]; M4_E070 m; } Elem_E070;
extern "C" {
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(M4_E070* m, float, float, float, float, float, float, float, float, float);
void cInterfaceElement_SetRotation(Elem_E070* e, float* r);
}
static inline void GQR(void* d0, void* s0) { void* d = d0; __int128 qa; __int128 qb; void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
void cInterfaceElement_SetRotation(Elem_E070* e, float* r)
{
    M4_E070 m;
    float y = r[1];
    float z = r[2];
    float x = r[0];
    float cy = COS(y);
    float sy = SIN(y);
    float cz = COS(z);
    float sz = SIN(z);
    float cx = COS(x);
    float sx = SIN(x);
    cMatrix_Set_ColumnMajorForm(&m, cy * cz, -sz, sy * cz, sz * (cx * cy) + sx * sy, cx * cz, sz * (cx * sy) - sx * cy, cy * (sx * sz) - cx * sy, sx * cz, sz * (sx * sy) + cx * cy);
    GQR(&e->m, &m);
}
