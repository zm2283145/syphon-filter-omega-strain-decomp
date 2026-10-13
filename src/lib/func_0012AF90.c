#include "types.h"

extern char D_00489738[];
extern int _strtol_r(int, int, int, int);

int strtol(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return _strtol_r(tmp0, a0, a1, a2);
}
