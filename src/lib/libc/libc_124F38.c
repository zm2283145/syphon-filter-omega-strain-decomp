#include "types.h"

extern char D_00489738[];
extern int Newlib_SetlocaleR(int, int, int);

int Libc_Setlocale(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return Newlib_SetlocaleR(tmp0, a0, a1);
}
