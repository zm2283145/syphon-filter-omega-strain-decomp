#include "types.h"
typedef struct { char pad[0x814]; int handle; } H36B090;
extern H36B090 D_00533CB0[4];
extern int func_0036C880(H36B090* h, void* a, void* b);
int func_0036B090(void* a, void* b)
{
    int i;
    H36B090* h = D_00533CB0;
    for (i = 0; i < 4; i++, h++) {
        if (h->handle != -1 && func_0036C880(h, a, b)) return 1;
    }
    return 0;
}