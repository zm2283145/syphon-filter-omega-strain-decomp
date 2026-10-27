#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { void* vt; char pad[0x2C]; char f30[0x10]; char f40[0x10]; int f50, f54, f58, f5c, f60; char pad2[0xC]; } M2D0;
extern "C" {
extern void* cMemMan_Allocate(int, int, char*, int);
extern void cMessage_ctor_cMessageR(M2D0*, M2D0*);
extern void cVector_ctor_cVectorR(void*, void*);
extern void cEulerAngle_T_1_2_ctor_cEulerAngleTR(void*, void*);
extern char D_004DE240[];
}
extern "C" M2D0* cNetGeneratorCreateMsg_Clone(M2D0* src) {
    M2D0* m;
    {
        AllocGuard g;
        m = (M2D0*)cMemMan_Allocate(0, 0x70, "NetGeneratorCreate.hh", 0x22);
    }
    if (m) {
        cMessage_ctor_cMessageR(m, src);
        m->vt = D_004DE240;
        cVector_ctor_cVectorR(m->f30, src->f30);
        cEulerAngle_T_1_2_ctor_cEulerAngleTR(m->f40, src->f40);
        m->f50 = src->f50;
        m->f54 = src->f54;
        m->f58 = src->f58;
        m->f5c = src->f5c;
        m->f60 = src->f60;
    }
    return m;
}
