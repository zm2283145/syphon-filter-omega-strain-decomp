#include "types.h"
typedef struct { int a[8]; } T1D8;
extern void cQuatVec_GetUnit(T1D8* t);
extern void cIkTarget_ctor(void* d, T1D8* s, int f);
typedef struct { int unk0; char pad[0xC]; char e[6][0x60]; } O1D8;
#pragma opt_loop_invariants off
O1D8* cArray_FixedCapacity_cIkTarget_LeftRight_6_ctor(O1D8* p)
{
    char* q;
    p->unk0 = 0;
    q = p->e[0];
    do {
        T1D8 a;
        T1D8 b;
        cQuatVec_GetUnit(&a);
        cIkTarget_ctor(q, &a, -1);
        cQuatVec_GetUnit(&b);
        cIkTarget_ctor(q + 0x30, &b, -1);
        q += 0x60;
    } while (q != (char*)p + 0x250);
    return p;
}
