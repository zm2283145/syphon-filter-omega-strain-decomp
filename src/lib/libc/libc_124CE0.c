#include "types.h"

extern char D_00489738[];
extern int Newlib_FindenvR(int, int, int);

int Newlib_Findenv(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return Newlib_FindenvR(tmp0, a0, a1);
}
