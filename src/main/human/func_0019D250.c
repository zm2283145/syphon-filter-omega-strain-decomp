#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D250;
typedef struct { V4_D250 r[4]; } M4_D250;
extern float Math_Atan2f(float y, float x);
static inline float GetX_D250(V4_D250* v) { return v->x; }
static inline float GetY_D250(V4_D250* v) { return v->y; }
static inline float GetZ_D250(V4_D250* v) { return v->z; }
static inline float H180_D250(V4_D250* v) { return Math_Atan2f(GetY_D250(v), GetX_D250(v)); }
static inline float H170_D250(float* v) { return Math_Atan2f(-v[0], v[1]); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
float Mtx_GetHeading(M4_D250* m)
{
    V4_D250 r0;
    V4_D250 r1;
    V4_D250* d0 = &r0;
    asm { .set reorder } /* empty barrier keeps the &r0 addiu ahead of the row loads (known trick) */
    *d0 = m->r[0];
    r1 = m->r[1];
    return GetZ_D250(&r0) < GetZ_D250(&r1) ? H180_D250(&r0) : H170_D250(&r1.x);
}
#pragma pop
