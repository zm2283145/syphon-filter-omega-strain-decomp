#include "types.h"
typedef struct { char pad[0x40]; } Part;
typedef struct { char pad[0x30]; char tail[0x20]; } Part2;
typedef struct { char pad[0x40]; Part a; Part2 b; Vec4 v0; Vec4 v1; char m[0x10]; } S;
extern void cBoneIk_cPose_ctor(void*);
extern void cBoneIk_cIntermediatePose_cAnimSource_ctor(void*);
extern void Quat_SetIdentity(Vec4*);
extern void cQuaternion_ctor_cQuaternionR(Vec4*, Vec4*);
extern void* Vec4_GetZero(void);
extern void Vec4_Assign(void*, void*);
/* Constructor: initialises the two parts, two vectors and the matrix member. */
S* cBoneIk_ctor(S* s)
{
    Vec4 t1;
    Vec4 t0;
    Part2* b;
    cBoneIk_cPose_ctor(&s->a);
    b = &s->b;
    cBoneIk_cPose_ctor(b);
    cBoneIk_cIntermediatePose_cAnimSource_ctor(b->tail);
    Quat_SetIdentity(&t0);
    cQuaternion_ctor_cQuaternionR(&s->v0, &t0);
    Quat_SetIdentity(&t1);
    cQuaternion_ctor_cQuaternionR(&s->v1, &t1);
    Vec4_Assign(s->m, Vec4_GetZero());
    return s;
}
