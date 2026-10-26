#include "types.h"

typedef struct ObjC0 {
    char pad[0xC];
    signed char flag;
} ObjC0;

extern void std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(ObjC0*);
extern void PtrVec_Reserve(ObjC0*, int);

/* Constructor: base init, then PtrVec_Reserve(self, *src) and flag byte at +0xC. */
ObjC0* func_00363F10(ObjC0* o, int* src, int flag) {
    std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(o);
    PtrVec_Reserve(o, *src);
    o->flag = flag;
    return o;
}
