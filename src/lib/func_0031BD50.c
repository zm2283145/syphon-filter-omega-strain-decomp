#include "types.h"

extern float func_00319DC0(int, int);
extern int func_0031A1E0(int, int, int, int);
extern int func_0031DE38(float);

float func_0031BD50(int a0, int a1, int a2, int a3, float f12) {
    int tmp0;
    int tmp4;

    tmp0 = func_0031DE38(f12);
    *(int*)((char*)a2) = tmp0;
    func_0031A1E0(a0, a3, tmp0, a1);
    tmp4 = *(int*)(char*)a2;
    return func_00319DC0(a1, tmp4);
}
