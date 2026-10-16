#include "types.h"
extern void ObjectAction_SendKind7(int a0, int a1, int a2, int a3, int t0);
extern void Global_PerformAction_WithObject(int a0, int a1, int a2, signed char* a3, int t0);
void Global_PerformAction_2(int a0, int a1, signed char* flag, int obj) {
    int cond;
    cond = *flag != 0;
    if (cond) goto L1;
    ObjectAction_SendKind7(a0, a1, 0, obj, obj);
    goto L2;
L1:;
    Global_PerformAction_WithObject(a0, 0x25, 0, flag, obj);
L2:;
}