#include "types.h"
#include "vu0_ops.h"
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx;
Mtx* func_00131C40(Mtx* m) {
    VU0_UnitMatrix(m);
    return m;
}