#include "types.h"

typedef struct { char b[64]; } S2C30;
extern S2C30 D_00492BF0;

int func_00352C30(S2C30* p)
{
    if (p) {
        *p = D_00492BF0;
    } else {
        return -1;
    }
    return 0;
}
