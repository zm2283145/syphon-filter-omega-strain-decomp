#include "types.h"

extern char D_00489738[];
extern char D_00499C40[];
extern void func_00121B60(void);
extern void func_001239D0(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);

void __assert(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00489738;
    tmp1 = *(int*)((char*)tmp0 + 12);
    func_001239D0(tmp1, (int)D_00499C40, a2, a0, a1, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    func_00121B60();
}
