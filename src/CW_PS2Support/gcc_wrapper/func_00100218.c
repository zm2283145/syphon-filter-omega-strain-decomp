#include "types.h"

extern void Exit_2(int);

void Newlib_SysExit_Thunk(int a0) {
    Exit_2(a0);
}
