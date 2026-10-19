#include "types.h"

extern void Newlib_SysExit(int);

void Newlib_SysExit_Thunk(int a0) {
    Newlib_SysExit(a0);
}
