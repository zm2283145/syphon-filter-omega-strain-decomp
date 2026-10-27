#include "types.h"
typedef struct { int w[4]; } V4_1842;
typedef struct { V4_1842 v[4]; int f40[4]; unsigned char b50; unsigned char b51; unsigned char b52; char pad[13]; int f60[4]; } E_1842;
extern void cVector_opAssign(V4_1842* d, V4_1842* s);
extern void cCollisionModel_FaceProperties_opAssign(int* d, int* s);
extern void cCollisionModel_FaceLocator_opAssign(int* d, int* s);
static inline void Assign_1842(E_1842* d, E_1842* s)
{
    cVector_opAssign(&d->v[0], &s->v[0]);
    cVector_opAssign(&d->v[1], &s->v[1]);
    cVector_opAssign(&d->v[2], &s->v[2]);
    cVector_opAssign(&d->v[3], &s->v[3]);
    d->b50 = s->b50;
    cCollisionModel_FaceProperties_opAssign(d->f40, s->f40);
    cCollisionModel_FaceLocator_opAssign(d->f60, s->f60);
    d->b51 = s->b51;
    d->b52 = s->b52;
}void std_fill_n_cCollisionFace_int_fill_n(E_1842* dest, int n, E_1842* src)
{
    for (; n != 0; n--) {
        Assign_1842(dest, src);
        dest++;
    }
}