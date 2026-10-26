#include "types.h"

extern int fflush(int);
extern int Newlib_Fwalk(int, int);

int Newlib_CleanupR(int a0) {
    return Newlib_Fwalk(a0, (int)fflush);
}
