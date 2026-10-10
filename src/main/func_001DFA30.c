#include "types.h"
typedef struct { char pad[0x40]; } Part;
typedef struct { char pad[0x30]; char tail[0x20]; } Part2;
typedef struct { char pad[0x40]; Part a; Part2 b; Vec4 v0; Vec4 v1; char m[0x10]; } S;
extern void func_001DFAD0(void*);
extern void func_001DFAC0(void*);
extern void Quat_SetIdentity(Vec4*);
extern void func_00132800(Vec4*, Vec4*);
extern void* Vec4_GetZero(void);
extern void Vec4_Assign(void*, void*);
/* Constructor: initialises the two parts, two vectors and the matrix member. */
S* func_001DFA30(S* s)
{
    Vec4 t1;
    Vec4 t0;
    Part2* b;
    func_001DFAD0(&s->a);
    b = &s->b;
    func_001DFAD0(b);
    func_001DFAC0(b->tail);
    Quat_SetIdentity(&t0);
    func_00132800(&s->v0, &t0);
    Quat_SetIdentity(&t1);
    func_00132800(&s->v1, &t1);
    Vec4_Assign(s->m, Vec4_GetZero());
    return s;
}
