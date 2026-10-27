#include "types.h"
extern void nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(int a0, int a1, int a2, int a3, int t0);
extern void nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_charP_etc(int a0, int a1, int a2, signed char* a3, int t0);
void nCAS_PerformAction_cSystemP_eAction_charP_float_etc(int a0, int a1, signed char* flag, int obj) {
    int cond;
    cond = *flag != 0;
    if (cond) goto L1;
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(a0, a1, 0, obj, obj);
    goto L2;
L1:;
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_charP_etc(a0, 0x25, 0, flag, obj);
L2:;
}