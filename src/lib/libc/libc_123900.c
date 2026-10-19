#include "types.h"

extern int fflush(int);
extern int Newlib_Fwalk(int, int);

int func_00123900(int a0) {
    return Newlib_Fwalk(a0, (int)fflush);
}
