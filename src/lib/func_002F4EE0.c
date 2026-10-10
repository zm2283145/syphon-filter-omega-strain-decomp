#include "types.h"

extern int func_002D8A28(void);
extern int func_002D8B38(int, int);

int func_002F4EE0(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = func_002D8A28();
    tmp2 = func_002D8B38(tmp0, a1);
    *(int*)((char*)a0) = tmp0;
    return tmp2;
}
